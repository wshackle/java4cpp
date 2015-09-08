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
import crcl.base.CRCLProgramType;
import crcl.base.CRCLStatusType;
import crcl.base.CommandStatusType;
import crcl.base.GetStatusType;
import crcl.base.InitCanonType;
import crcl.base.MoveThroughToType;
import crcl.base.PointType;
import crcl.base.PoseType;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.bind.JAXBException;
import javax.xml.transform.sax.SAXSource;
import javax.xml.validation.Schema;
import org.junit.Assert;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class CRCLSocketTest {

    public CRCLSocketTest() {
    }

//    /**
//     * Test of statusToEXI method, of class CRCLSocket.
//     */
//    @Test
//    public void testMessage() throws Exception {
//        crcl.base.MessageType m = new  MessageType();
//        crcl.base.CRCLCommandInstanceType cmd = new CRCLCommandInstanceType();
//        m.setMessage("</CRCLCommandInstanceType>");
//        cmd.setCRCLCommand(m);
//        CRCLSocket s = new CRCLSocket();
//        String xmlPrettyS  = s.commandToPrettyDocString(cmd, true);
//        LOGGER.log(Level.INFO,"xmlPrettyS = " + xmlPrettyS);
//        String xmlS  = s.commandToString(cmd, true);
//        LOGGER.log(Level.INFO,"xmlS = " + xmlS);
//    }
    /**
     * Test of statusToEXI method, of class CRCLSocket.
     */
    @Test
    public void testStatusToEXI() throws Exception {
        LOGGER.log(Level.INFO, "statusToEXI");
        CRCLStatusType status = new CRCLStatusType();
        CommandStatusType cst = new CommandStatusType();
        cst.setCommandID(BigInteger.ONE);
        cst.setStatusID(BigInteger.TEN);
        status.setCommandStatus(cst);
        PoseType p = new PoseType();
        PointType pt = new PointType();
        pt.setX(BigDecimal.ONE);
        p.setPoint(pt);
        status.setPose(p);
        CRCLSocket instance = new CRCLSocket();
        byte[] expResult = null;
        byte[] result = instance.statusToEXI(status);
//        LOGGER.log(Level.INFO,"status = " + instance.statusToString(status, true));
//        LOGGER.log(Level.INFO,"result = " + Arrays.toString(result));
        CRCLStatusType statusCopy = instance.exiToStatus(result);
//        LOGGER.log(Level.INFO,"statusCopy = " + instance.statusToString(statusCopy, false));
//        LOGGER.log(Level.INFO,"status="+CRCLSocket.statToDebugString(status));
        assertEquals(status.getCommandStatus().getCommandID(),
                statusCopy.getCommandStatus().getCommandID());
        assertEquals(status.getCommandStatus().getStatusID(),
                statusCopy.getCommandStatus().getStatusID());
        assertTrue(status.getPose().getPoint().getX().subtract(
                statusCopy.getPose().getPoint().getX()).abs().compareTo(BigDecimal.valueOf(1e-6)) < 0);
    }

    private static final Logger LOGGER = Logger.getLogger(CRCLSocketTest.class.getName());

    /**
     * Test of commandToEXI method, of class CRCLSocket.
     */
    @Test
    public void testCommandToEXI() throws Exception {
        LOGGER.log(Level.INFO, "commandToEXI");
        CRCLCommandInstanceType initCmdInstance = new CRCLCommandInstanceType();
        crcl.base.InitCanonType init = new InitCanonType();
        init.setCommandID(BigInteger.valueOf(100));
        initCmdInstance.setCRCLCommand(init);
        CRCLSocket instance = new CRCLSocket();
        byte[] initBytes = instance.commandToEXI(initCmdInstance);
//        LOGGER.log(Level.INFO,"result = " + Arrays.toString(result));
        CRCLCommandInstanceType returnCmd = instance.exiToCommand(initBytes);
        assertEquals(initCmdInstance.getCRCLCommand().getCommandID(),
                returnCmd.getCRCLCommand().getCommandID());
        CRCLCommandInstanceType getStatusCmdInstance = new CRCLCommandInstanceType();
        GetStatusType getStatus = new GetStatusType();
        getStatus.setCommandID(BigInteger.valueOf(101));
        getStatusCmdInstance.setCRCLCommand(getStatus);
        byte[] getStatusBytes = instance.commandToEXI(getStatusCmdInstance);
//        LOGGER.log(Level.INFO,"result = " + Arrays.toString(result));
        returnCmd = instance.exiToCommand(getStatusBytes);
        assertEquals(getStatusCmdInstance.getCRCLCommand().getCommandID(),
                returnCmd.getCRCLCommand().getCommandID());
        byte twocmdsArray[] = new byte[initBytes.length + getStatusBytes.length + 1];
        System.arraycopy(initBytes, 0, twocmdsArray, 0, initBytes.length);
        System.arraycopy(getStatusBytes, 0, twocmdsArray, initBytes.length, getStatusBytes.length);
        LOGGER.log(Level.INFO, "initBytes = " + Arrays.toString(initBytes));
        LOGGER.log(Level.INFO, "getStatusBytes = " + Arrays.toString(getStatusBytes));
        LOGGER.log(Level.INFO, "twocmdsArray = " + Arrays.toString(twocmdsArray));
        try (final InputStream inputStream = new ByteArrayInputStream(twocmdsArray)) {
            returnCmd = instance.readCommandFromEXIStream(inputStream);
            LOGGER.log(Level.INFO, "returnCmd = " + returnCmd);
            CRCLCommandType c = returnCmd.getCRCLCommand();
            LOGGER.log(Level.INFO, "c = " + c);
            assertEquals(init.getCommandID(),
                    returnCmd.getCRCLCommand().getCommandID());
            returnCmd = instance.readCommandFromEXIStream(inputStream);
            LOGGER.log(Level.INFO, "returnCmd = " + returnCmd);
            c = returnCmd.getCRCLCommand();
            LOGGER.log(Level.INFO, "c = " + c);
            assertEquals(getStatus.getCommandID(),
                    returnCmd.getCRCLCommand().getCommandID());
        }
        LOGGER.log(Level.INFO, "");
        LOGGER.log(Level.INFO, "Start socket over TCP tests");
//        byte partarryay[] = new byte[initBytes.length + getStatusBytes.length/2];
//        System.arraycopy(twocmdsArray, 0, partarryay, 0, partarryay.length);
//        try (final InputStream inputStream = new ByteArrayInputStream(partarryay)) {
//            returnCmd = instance.readCommandFromEXIStream(inputStream);
//            LOGGER.log(Level.INFO,"returnCmd = " + returnCmd);
//            CRCLCommandType c = returnCmd.getCRCLCommand();
//            LOGGER.log(Level.INFO,"c = " + c);
//            assertEquals(init.getCommandID(),
//                returnCmd.getCRCLCommand().getCommandID());
//            returnCmd = instance.readCommandFromEXIStream(inputStream);
//            LOGGER.log(Level.INFO,"returnCmd = " + returnCmd);
//             c = returnCmd.getCRCLCommand();
//            LOGGER.log(Level.INFO,"c = " + c);
//            assertEquals(getStatus.getCommandID(),
//                returnCmd.getCRCLCommand().getCommandID());
//        }
        System.setProperty("crcl.prefixEXISizeEnabled", "false");
        final ServerSocket ss = new ServerSocket(0);
        ExecutorService serv = Executors.newCachedThreadPool();
        for (int i = 0; i < 10; i++) {
            LOGGER.log(Level.INFO, "i = " + i);
            Future<Socket> f = serv.submit(new Callable<Socket>() {

                @Override
                public Socket call() throws Exception {
                    return ss.accept();
                }
            });
            final CRCLSocket csClient = new CRCLSocket("127.0.0.1", ss.getLocalPort());
            csClient.setPrefixEXISizeEnabled(false);
            csClient.setEXIEnabled(true);
            CRCLSocket csServer = new CRCLSocket(f.get());
            csServer.setEXIEnabled(true);
            csServer.setPrefixEXISizeEnabled(false);
            final CRCLCommandInstanceType initCmdInstanceF = initCmdInstance;
            final CRCLCommandInstanceType getStatusCmdInstanceF = getStatusCmdInstance;
            final int MAX_J = 2;
            Runnable r = new Runnable() {

                @Override
                public void run() {
                    Random rand = new Random(138);
//                try { Thread.sleep(2000); } catch(Exception e) {};
                    for (int j = 0; j < MAX_J; j++) {
                        try {
                            csClient.writeCommand(initCmdInstanceF, true);
                            csClient.writeCommand(getStatusCmdInstanceF, true);
                            if (rand.nextBoolean()) {
                                try {
                                    Thread.sleep(rand.nextInt(50));
                                } catch (Exception e) {
                                };
                            }
                            LOGGER.log(Level.INFO, "j = " + j);
                        } catch (JAXBException ex) {
                            Logger.getLogger(CRCLSocketTest.class.getName()).log(Level.SEVERE, null, ex);
                        } catch (IOException ex) {
                            Logger.getLogger(CRCLSocketTest.class.getName()).log(Level.SEVERE, null, ex);
                        } catch (InterruptedException ex) {
                            Logger.getLogger(CRCLSocketTest.class.getName()).log(Level.SEVERE, null, ex);
                        } catch (EXIException ex) {
                            Logger.getLogger(CRCLSocketTest.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }
                }
            };
//            new Thread(r).start();
            r.run();
            for (int j = 0; j < MAX_J; j++) {
                LOGGER.log(Level.INFO, "i = " + i);
                LOGGER.log(Level.INFO, "j = " + j);
                csServer.setEXIEnabled(true);
                LOGGER.log(Level.INFO, "csServer.available() = " + csServer.available());
                returnCmd = csServer.readCommand(true);
                LOGGER.log(Level.INFO, "returnCmd = " + returnCmd);
                CRCLCommandType c = returnCmd.getCRCLCommand();
                LOGGER.log(Level.INFO, "c = " + c);
                assertEquals(init.getCommandID(),
                        returnCmd.getCRCLCommand().getCommandID());
                LOGGER.log(Level.INFO, "csServer.available() = " + csServer.available());
                returnCmd = csServer.readCommand(true);
                LOGGER.log(Level.INFO, "returnCmd = " + returnCmd);
                c = returnCmd.getCRCLCommand();
                LOGGER.log(Level.INFO, "c = " + c);
                assertEquals(getStatus.getCommandID(),
                        returnCmd.getCRCLCommand().getCommandID());
            }
            try {
                csServer.close();
            } catch (Exception e) {
            }
            try {
                csClient.close();
            } catch (Exception e) {
            }
        }
        try {
            ss.close();
        } catch (Exception e) {
        }
        try {
            serv.shutdownNow();
        } catch (Exception e) {
        }
        try (final ByteArrayOutputStream outputStream = new ByteArrayOutputStream()) {
            getStatusCmdInstance = new CRCLCommandInstanceType();
            getStatusCmdInstance.setCRCLCommand(init);
            instance.writeEXICommandToStream(outputStream, getStatusCmdInstance);
            getStatusCmdInstance = new CRCLCommandInstanceType();
            getStatusCmdInstance.setCRCLCommand(getStatus);
            instance.writeEXICommandToStream(outputStream, getStatusCmdInstance);
            byte ba[] = outputStream.toByteArray();
            LOGGER.log(Level.INFO,"ba = " + Arrays.toString(ba));
            Assert.assertArrayEquals(ba, Arrays.copyOf(twocmdsArray, twocmdsArray.length - 1));
        }
    }

    /**
     * Test of stringToCommand method, of class CRCLSocket.
     */
    @Test
    public void testStringToCommand() throws Exception {
        System.out.println("stringToCommand");
        String str = MOVETHROUGHTO_XML;
        boolean validate = true;
        CRCLSocket instance = new CRCLSocket();
        CRCLCommandInstanceType result = instance.stringToCommand(str, validate);
        final CRCLCommandType c = result.getCRCLCommand();
        assertTrue(c != null && c instanceof MoveThroughToType);
        final MoveThroughToType moveCommand = (MoveThroughToType) c;
        assertEquals(new BigInteger("2"), c.getCommandID());
        assertEquals(new BigInteger("2"), moveCommand.getNumPositions());
    }
    private static final String MOVETHROUGHTO_XML = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            + "<CRCLCommandInstance\n"
            + "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            + "  xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLCommandInstance.xsd\">\n"
            + "  <CRCLCommand xsi:type=\"MoveThroughToType\">\n"
            + "    <CommandID>2</CommandID>\n"
            + "    <MoveStraight>false</MoveStraight>\n"
            + "    <Waypoint>\n"
            + "      <Point>\n"
            + "        <X>2.5</X> <Y>1</Y> <Z>1</Z>\n"
            + "      </Point>\n"
            + "      <XAxis>\n"
            + "        <I>1</I> <J>0</J> <K>0</K>\n"
            + "      </XAxis>\n"
            + "      <ZAxis>\n"
            + "        <I>0</I> <J>0</J> <K>-1</K>\n"
            + "      </ZAxis>\n"
            + "    </Waypoint>\n"
            + "    <Waypoint>\n"
            + "      <Point>\n"
            + "        <X>0.5</X> <Y>0</Y> <Z>2</Z>\n"
            + "      </Point>\n"
            + "      <XAxis>\n"
            + "        <I>1</I> <J>0</J> <K>0</K>\n"
            + "      </XAxis>\n"
            + "      <ZAxis>\n"
            + "        <I>0</I> <J>0</J> <K>-1</K>\n"
            + "      </ZAxis>\n"
            + "    </Waypoint>\n"
            + "    <NumPositions>2</NumPositions>\n"
            + "  </CRCLCommand>\n"
            + "</CRCLCommandInstance>";

    /**
     * Test of readCommandFromStream method, of class CRCLSocket.
     */
    @Test
    public void testReadCommandFromStream() throws Exception {
        System.out.println("readCommandFromStream");
//        byte ba[] = new byte[MOVETHROUGHTO_XML.length()*2];
//        System.arraycopy(MOVETHROUGHTO_XML.getBytes(), 0, ba, 0, MOVETHROUGHTO_XML.length());
        //System.arraycopy(MOVETHROUGHTO_XML.getBytes(), 0, ba, MOVETHROUGHTO_XML.length(), MOVETHROUGHTO_XML.length());
        InputStream is = new ByteArrayInputStream(MOVETHROUGHTO_XML.getBytes());
        boolean validate = true;
        CRCLSocket instance = new CRCLSocket();
        CRCLCommandInstanceType expResult = null;
        CRCLCommandInstanceType result = instance.readCommandFromStream(is, validate);
        final CRCLCommandType c = result.getCRCLCommand();
        assertTrue(c != null && c instanceof MoveThroughToType);
        final MoveThroughToType moveCommand = (MoveThroughToType) c;
        assertEquals(new BigInteger("2"), c.getCommandID());
        assertEquals(new BigInteger("2"), moveCommand.getNumPositions());
    }

    /**
     * Test of stringToStatus method, of class CRCLSocket.
     */
    @Test
    public void testStringToStatus() throws Exception {
        System.out.println("stringToStatus");
        String str = STATUS_XML;
        boolean validate = true;
        CRCLSocket instance = new CRCLSocket();
        CRCLStatusType result = instance.stringToStatus(str, validate);
        assertEquals(BigInteger.ONE, result.getCommandStatus().getCommandID());
        assertEquals(BigInteger.ONE, result.getCommandStatus().getStatusID());
    }
    private static final String STATUS_XML = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            + "<CRCLStatus\n"
            + "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            + "  xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLStatus.xsd\">\n"
            + "\n"
            + "  <CommandStatus>\n"
            + "    <CommandID>1</CommandID>\n"
            + "    <StatusID>1</StatusID>\n"
            + "    <CommandState>Working</CommandState>\n"
            + "  </CommandStatus>\n"
            + "  <JointStatuses>\n"
            + "    <JointStatus>\n"
            + "      <JointNumber>1</JointNumber>\n"
            + "      <JointPosition>30.0</JointPosition>\n"
            + "      <JointTorqueOrForce>3.7</JointTorqueOrForce>\n"
            + "    </JointStatus>\n"
            + "    <JointStatus>\n"
            + "      <JointNumber>3</JointNumber>\n"
            + "      <JointPosition>90.0</JointPosition>\n"
            + "      <JointVelocity>0.87</JointVelocity>\n"
            + "    </JointStatus>\n"
            + "  </JointStatuses>\n"
            + "  <Pose>\n"
            + "    <Point>\n"
            + "      <X>1.5</X> <Y>1</Y> <Z>1</Z>\n"
            + "    </Point>\n"
            + "    <XAxis>\n"
            + "      <I>1</I> <J>0</J> <K>0</K>\n"
            + "      </XAxis>\n"
            + "    <ZAxis>\n"
            + "      <I>0</I> <J>0</J> <K>-1</K>\n"
            + "    </ZAxis>\n"
            + "  </Pose>\n"
            + "  <GripperStatus xsi:type=\"ParallelGripperStatusType\">\n"
            + "    <GripperName>jaws</GripperName>\n"
            + "    <Separation>0.44</Separation>\n"
            + "  </GripperStatus>\n"
            + "</CRCLStatus>\n"
            + "";

    /**
     * Test of readStatusFromStream method, of class CRCLSocket.
     */
    @Test
    public void testReadStatusFromStream() throws Exception {
        System.out.println("readStatusFromStream");
        InputStream is = new ByteArrayInputStream(STATUS_XML.getBytes());
        boolean validate = false;
        CRCLSocket instance = new CRCLSocket();
        CRCLStatusType result = instance.readStatusFromStream(is, validate);
        assertEquals(BigInteger.ONE, result.getCommandStatus().getCommandID());
        assertEquals(BigInteger.ONE, result.getCommandStatus().getStatusID());
    }

    /**
     * Test of readStatusFromStream method, of class CRCLSocket.
     */
    @Test
    public void testReadUntilEndTag() throws Exception {
        System.out.println("readUntilEndTag");
        InputStream is = new ByteArrayInputStream(STATUS_XML.getBytes());
        boolean validate = false;
        CRCLSocket instance = new CRCLSocket();
        String str = instance.readUntilEndTag("CRCLStatus", is);
        CRCLStatusType result = instance.stringToStatus(str, validate);
        assertEquals(BigInteger.ONE, result.getCommandStatus().getCommandID());
        assertEquals(BigInteger.ONE, result.getCommandStatus().getStatusID());
        is = new ByteArrayInputStream((STATUS_XML + STATUS_XML).getBytes());
        str = instance.readUntilEndTag("CRCLStatus", is);
        result = instance.stringToStatus(str, validate);
        assertEquals(BigInteger.ONE, result.getCommandStatus().getCommandID());
        assertEquals(BigInteger.ONE, result.getCommandStatus().getStatusID());
        str = instance.readUntilEndTag("CRCLStatus", is);
        result = instance.stringToStatus(str, validate);
        assertEquals(BigInteger.ONE, result.getCommandStatus().getCommandID());
        assertEquals(BigInteger.ONE, result.getCommandStatus().getStatusID());
        str = instance.readUntilEndTag("CRCLStatus",
                new ByteArrayInputStream("  <CRCLStatus name=\"foo\" /> ".getBytes()));
        assertEquals(str, "<CRCLStatus name=\"foo\" />");
        str = instance.readUntilEndTag("CRCLStatus",
                new ByteArrayInputStream("  <CRCLStatus name=\"foo\" >  </CRCLStatus garbage-here  >  ".getBytes()));
        assertEquals(str, "<CRCLStatus name=\"foo\" >  </CRCLStatus garbage-here  >");
    }

}
