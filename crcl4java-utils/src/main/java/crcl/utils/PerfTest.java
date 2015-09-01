/*
 * This software is public domain software, however it is preferred
 * that the following disclaimers be attached.
 * Software Copywrite/Warranty Disclaimer
 * 
 * This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. NIST Real-Time Control System software is an experimental
 * system. NIST assumes no responsibility whatsoever for its use by other
 * parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic. We would appreciate
 * acknowledgement if the software is used. This software can be
 * redistributed and/or modified freely provided that any derivative works
 * bear some notice that they are derived from it, and any modified
 * versions bear some notice that they have been modified.
 * 
 *  See http://www.copyright.gov/title17/92chap1.html#105
 * 
 */
package crcl.utils;

import com.siemens.ct.exi.exceptions.EXIException;
import crcl.base.CRCLCommandInstanceType;
import crcl.base.CRCLCommandType;
import crcl.base.CRCLStatusType;
import crcl.base.CommandStateEnumType;
import crcl.base.CommandStatusType;
import crcl.base.GetStatusType;
import crcl.base.GripperStatusType;
import crcl.base.JointStatusType;
import crcl.base.JointStatusesType;
import crcl.base.PointType;
import crcl.base.PoseType;
import crcl.base.VacuumGripperStatusType;
import crcl.base.VectorType;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.bind.JAXBException;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class PerfTest {

    private static CRCLStatusType createStatus() {
        CRCLStatusType stat = new CRCLStatusType();
        CommandStatusType cst = new CommandStatusType();
        cst.setCommandID(BigInteger.ONE);
        cst.setStatusID(BigInteger.ONE);
        cst.setCommandState(CommandStateEnumType.WORKING);
        stat.setCommandStatus(cst);
        PoseType pose = new PoseType();
        PointType pt = new PointType();
        pt.setX(BigDecimal.ZERO);
        pt.setY(BigDecimal.ONE);
        pt.setZ(BigDecimal.TEN);
        pose.setPoint(pt);
        VectorType xAxis = new VectorType();
        xAxis.setI(BigDecimal.ONE);
        xAxis.setJ(BigDecimal.ZERO);
        xAxis.setK(BigDecimal.ZERO);
        pose.setXAxis(xAxis);
        VectorType zAxis = new VectorType();
        zAxis.setI(BigDecimal.ZERO);
        zAxis.setJ(BigDecimal.ZERO);
        zAxis.setK(BigDecimal.ONE);
        pose.setZAxis(zAxis);
        stat.setPose(pose);
        GripperStatusType gst = new VacuumGripperStatusType();
        stat.setGripperStatus(gst);
        JointStatusesType jst = new JointStatusesType();
        jst.getJointStatus().add(new JointStatusType());
        stat.setJointStatuses(jst);
        return stat;
    }

    public static void main(String[] args) {
        runPerfTest(true);
        runPerfTest(false);
    }

    public static void runPerfTest(final boolean enableEXI) throws RuntimeException {
        try {
            CRCLSocket csTst = new CRCLSocket();
            csTst.setReplaceHeader(true);
            CRCLStatusType stat0 = createStatus();
            String xmlS  = csTst.statusToString(stat0, false);
            System.out.println("Starting runPerfTest("+enableEXI+") ...");
            System.out.println("enableEXI = " + enableEXI);
            System.out.println("xmlS = " + xmlS);
            System.out.println("xmlS.length() = " + xmlS.length());
            byte ba[] = csTst.statusToEXI(stat0);
            System.out.println("ba.length = " + ba.length);
            System.out.println("ba = " + Arrays.toString(ba));
            ExecutorService exServ = Executors.newWorkStealingPool();
            try (ServerSocket ss = new ServerSocket(44004)) {
                System.out.println("ss.getLocalPort() = " + ss.getLocalPort());
                exServ.execute(() -> {
                    while (!Thread.currentThread().isInterrupted() && !exServ.isShutdown()) {
                        try {
                            Socket s = ss.accept();
                            final CRCLSocket cs = new CRCLSocket(s);
                            cs.setEXIEnabled(enableEXI);
                            final CRCLStatusType status = createStatus();
                            exServ.execute(() -> {
                                try {
                                    while (!Thread.currentThread().isInterrupted() && !exServ.isShutdown()) {
                                        CRCLCommandInstanceType cmdInstance = cs.readCommand(false);
                                        CRCLCommandType cmd = cmdInstance.getCRCLCommand();
//                                        System.out.println("cmd.getCommandID() = " + cmd.getCommandID());
                                        status.getCommandStatus().setCommandID(cmd.getCommandID());
                                        status.getCommandStatus().setStatusID(status.getCommandStatus().getStatusID().add(BigInteger.ONE));
                                        cs.writeStatus(status, false);
                                    }
                                } catch (JAXBException | IOException | EXIException | InterruptedException ex) {
                                    Logger.getLogger(PerfTest.class.getName()).log(Level.SEVERE, null, ex);
                                } finally {
                                    try {
                                        cs.close();
                                    } catch (IOException ex) {
                                        Logger.getLogger(PerfTest.class.getName()).log(Level.SEVERE, null, ex);
                                    }
                                }
                            });
                        } catch (IOException | EXIException ex) {
                            if(null != ss && !ss.isClosed()) {
                                Logger.getLogger(PerfTest.class.getName()).log(Level.SEVERE, null, ex);
                            }
                        }
                    }
                });
                CRCLSocket cs = new CRCLSocket("localhost", ss.getLocalPort());
                cs.setEXIEnabled(enableEXI);
                CRCLCommandInstanceType cmdInstance = new CRCLCommandInstanceType();
                GetStatusType getStatus = new GetStatusType();
                getStatus.setCommandID(BigInteger.ONE);
                cmdInstance.setCRCLCommand(getStatus);
                long start = System.currentTimeMillis();
                final long repeats = 10000;
                long diff_max = 0;
                for (int i = 0; i < repeats; i++) {
                    long t1 = System.currentTimeMillis();
                    getStatus.setCommandID(getStatus.getCommandID().add(BigInteger.ONE));
//                    System.out.println("getStatus.getCommandID() = " + getStatus.getCommandID());
                    cs.writeCommand(cmdInstance, false);
                    CRCLStatusType stat = cs.readStatus(false);
//                    System.out.println("stat.getCommandStatus().getCommandID() = " + stat.getCommandStatus().getCommandID());
                    if(stat.getCommandStatus().getCommandID().compareTo(getStatus.getCommandID()) != 0) {
                        throw new RuntimeException("Command ID doesn't match : " 
                                +stat.getCommandStatus().getCommandID()+ " != "+ getStatus.getCommandID());
                    }
                    long t2 = System.currentTimeMillis();
                    long diff = t2 - t1;
                    if(diff > diff_max) {
                        diff_max = diff;
                    }
                }
                long end = System.currentTimeMillis();
                System.out.println("(end-start) = " + (end-start) + " ms");
                System.out.println("Average time = " + ((double)(end-start))/repeats + " ms");
                System.out.println("Max time = " + diff_max + " ms");
                exServ.shutdown();
                exServ.awaitTermination(5, TimeUnit.SECONDS);
                exServ.shutdownNow();
            }
        } catch (IOException | JAXBException | InterruptedException | EXIException ex) {
            Logger.getLogger(PerfTest.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
                System.out.println("End of runPerfTest("+enableEXI+")");
                System.out.println("");
        }
    }
}
