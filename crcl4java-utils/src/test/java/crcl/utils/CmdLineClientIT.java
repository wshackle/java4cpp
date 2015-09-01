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
 */
package crcl.utils;

import java.net.URL;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class CmdLineClientIT {

    public CmdLineClientIT() {
        System.setProperty("java.awt.headless", "true");
    }

    /**
     * Test of main method, of class CmdLineClient.
     */
    @Test
    public void testMain() {
        try {
            System.err.println("");
            System.err.flush();
            LOGGER.log(Level.INFO,"");
            LOGGER.log(Level.INFO,"Begin CmdLineClientIT.testMain");
            LOGGER.log(Level.INFO,"user.dir=" + System.getProperty("user.dir"));
            CmdLineClient.programSucceeded = false;
            URL programURL = getClass().getResource("/main/programAll.xml");
            Path programPath = Paths.get(programURL.toURI());
            System.setProperty("crcljava.program", programPath.toString());
            System.setProperty("crcljava.port", "0");
            URL initPoseURL = getClass().getResource("/main/initPose.csv");
            Path initPosePath = Paths.get(initPoseURL.toURI());
            System.setProperty("crcljava.program", programPath.toString());
            System.setProperty("crcljava.port", "0");

            System.setProperty("crcjava.SimServer.validateXML", "true");// validateXML
            System.setProperty("crcjava.SimServer.sendStatusWithoutRequest", "false");// sendStatusWithoutRequest
            System.setProperty("crcjava.SimServer.appendZero", "false");// appendZero
            System.setProperty("crcjava.SimServer.randomPacket", "false");// randomPacket
            System.setProperty("crcjava.SimServer.replaceState", "false");// replaceState
            System.setProperty("crcjava.SimServer.debugMoveDone", "true");// debugMoveDone
            System.setProperty("crcjava.SimServer.debugReadCommand", "true");// debugReadCommand
            System.setProperty("crcjava.SimServer.replaceXmlHeader", "true");// replaceXmlHeader
            System.setProperty("crcjava.SimServer.debugSendStatus", "true");// debugSendStatus
            System.setProperty("crcjava.SimServer.exiSelected", "false");// exiSelected

            System.setProperty("crcjava.PendandClient.validateXML", "true");// validateXML
            System.setProperty("crcjava.PendandClient.replaceState", "false");// validateXML
            System.setProperty("crcjava.PendandClient.debugWaitForDone", "false");// debugWaitForDone
            System.setProperty("crcjava.PendandClient.debugSendCommand", "true");// debugSendCommand
            System.setProperty("crcjava.PendandClient.recordPose", "false");// recordPose
            System.setProperty("crcjava.PendandClient.exiSelected", "false");// exiSelected
            System.setProperty("crcjava.PendandClient.useReadStatusThreadSelected","false");
            System.setProperty("crcl.utils.SimServerInner.enableGetStatusIDCheck", "true");
//            System.setProperty("crcl.prefixEXISizeEnabled", "true");
            CmdLineSimServer.main(new String[]{
                "--delayMillis", "10",
                "--jointSpeedMax", "1000.0",
                "--initPose", initPosePath.toString(),
                "--maxTransSpeed", "200.0",
                "--maxTransAccel", "200.0"
            });
            for (int i = 0; i < 2; i++) {
                LOGGER.log(Level.INFO,"i = " + i);
                CmdLineClient.main(new String[]{"--waitForDoneDelay", DELAY_STRING});
                if (!CmdLineClient.programSucceeded) {
                    LOGGER.log(Level.SEVERE,
                            "CmdLineSimServer.simServerInner.getStatus = "
                            + CmdLineSimServer.simServerInner.getStatusXmlString());
//                Thread.getAllStackTraces().entrySet().forEach((x) -> {
//                    System.err.println("Thread:" + x.getKey().getName());
//                    Arrays.stream(x.getValue()).forEach((xx) -> {
//                        System.err.println("\t" + xx);
//                    });
//                    System.err.println("");
//                });
                    fail("Program did NOT succeed.");
                }
            }
        } catch (Exception ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            fail("Exception thrown");
        }
        if (null != CmdLineSimServer.simServerInner) {
            CmdLineSimServer.simServerInner.closeServer();
            CmdLineSimServer.simServerInner = null;
        }
        LOGGER.log(Level.INFO,"End CmdLineClientIT.testMain");
        System.err.println("");
        System.out.flush();
        System.err.flush();
        LOGGER.log(Level.INFO,"");
    }
    private static final Logger LOGGER = Logger.getLogger(CmdLineClientIT.class.getName());

    /**
     * Test of main method, of class CmdLineClient.
     */
    @Test
    public void testMainEXI() {
        try {
            if (null != CmdLineSimServer.simServerInner) {
                CmdLineSimServer.simServerInner.closeServer();
                CmdLineSimServer.simServerInner = null;
            }
            System.err.println("");
            System.err.flush();
            LOGGER.log(Level.INFO,"");
            LOGGER.log(Level.INFO,"Begin CmdLineClientIT.testMainEXI");
            LOGGER.log(Level.INFO,"user.dir=" + System.getProperty("user.dir"));
            CmdLineClient.programSucceeded = false;
            URL programURL = getClass().getResource("/main/programAll.xml");
            Path programPath = Paths.get(programURL.toURI());
            System.setProperty("crcljava.program", programPath.toString());
            System.setProperty("crcljava.port", "0");
            URL initPoseURL = getClass().getResource("/main/initPose.csv");
            Path initPosePath = Paths.get(initPoseURL.toURI());
            System.setProperty("crcljava.program", programPath.toString());
            System.setProperty("crcljava.port", "0");

            System.setProperty("crcjava.SimServer.validateXML", "false");// validateXML
            System.setProperty("crcjava.SimServer.sendStatusWithoutRequest", "false");// sendStatusWithoutRequest
            System.setProperty("crcjava.SimServer.appendZero", "false");// appendZero
            System.setProperty("crcjava.SimServer.randomPacket", "false");// randomPacket
            System.setProperty("crcjava.SimServer.replaceState", "false");// replaceState
            System.setProperty("crcjava.SimServer.debugMoveDone", "true");// debugMoveDone
            System.setProperty("crcjava.SimServer.debugReadCommand", "true");// debugReadCommand
            System.setProperty("crcjava.SimServer.replaceXmlHeader", "false");// replaceXmlHeader
            System.setProperty("crcjava.SimServer.debugSendStatus", "true");// debugSendStatus
            System.setProperty("crcjava.SimServer.exiSelected", "true");// exiSelected

            System.setProperty("crcjava.PendandClient.validateXML", "false");// validateXML
            System.setProperty("crcjava.PendandClient.replaceState", "false");// validateXML
            System.setProperty("crcjava.PendandClient.debugWaitForDone", "false");// debugWaitForDone
            System.setProperty("crcjava.PendandClient.debugSendCommand", "true");// debugSendCommand
            System.setProperty("crcjava.PendandClient.recordPose", "false");// recordPose
            System.setProperty("crcjava.PendandClient.exiSelected", "true");// exiSelected
            System.setProperty("crcl.utils.SimServerInner.enableGetStatusIDCheck", "true");
            System.setProperty("crcl.prefixEXISizeEnabled", "false");
            System.setProperty("crcjava.PendandClient.useReadStatusThreadSelected","false");
            CmdLineSimServer.main(new String[]{
                "--delayMillis", "10",
                "--jointSpeedMax", "1000.0",
                "--initPose", initPosePath.toString(),
                "--maxTransSpeed", "200.0",
                "--maxTransAccel", "200.0"
            });
            for (int i = 0; i < 2; i++) {
                LOGGER.log(Level.INFO,"i = " + i);
                CmdLineClient.main(new String[]{"--waitForDoneDelay", DELAY_STRING});
                if (!CmdLineClient.programSucceeded) {
                    System.err.println("CmdLineSimServer.simServerInner.getStatus = "
                            + CmdLineSimServer.simServerInner.getStatusXmlString());
//                Thread.getAllStackTraces().entrySet().forEach((x) -> {
//                    System.err.println("Thread:" + x.getKey().getName());
//                    Arrays.stream(x.getValue()).forEach((xx) -> {
//                        System.err.println("\t" + xx);
//                    });
//                    System.err.println("");
//                });
                    fail("Program did NOT succeed.");
                }
            }
        } catch (Exception ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            fail("Exception thrown: " + ex);
        }
        if (null != CmdLineSimServer.simServerInner) {
            CmdLineSimServer.simServerInner.closeServer();
            CmdLineSimServer.simServerInner = null;
        }
        LOGGER.log(Level.INFO,"End CmdLineClientIT.testMainEXI");
        System.err.println("");
        System.out.flush();
        System.err.flush();
        LOGGER.log(Level.INFO,"");
    }
    private static final String DELAY_STRING = "0";

}
