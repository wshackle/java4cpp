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
package crcl.ui;

import crcl.utils.PendantClientOuterStub;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.bind.JAXBException;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPathExpressionException;
import org.xml.sax.SAXException;
import rcs.posemath.PmException;
import rcs.posemath.PmPose;
import rcs.posemath.PmRpy;
import rcs.posemath.Posemath;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class CmdLineClient {

    public static boolean programSucceeded = false;

    public static void main(String[] args) {
        try {
            String poseFileName = null;
            for (int i = 0; i < args.length - 1; i++) {
                switch (args[i]) {
                    case "--waitForDoneDelay":
                        System.setProperty("PendantClient.waitForDoneDelay", args[i + 1]);
                        i++;
                        break;

                    case "--poseFileName":
                        poseFileName = args[i + 1];
                        i++;
                        break;
                }
            }
            programSucceeded = false;
            System.setProperty("crcjava.PendandClient.useReadStatusThreadSelected", "false");
            PendantClientOuterStub pendantClientOuterStub = new PendantClientOuterStub();
            PendantClientInner pendantClientInner = new PendantClientInner(pendantClientOuterStub);
            final String programPropertyString = System.getProperty("crcljava.program");
            if (null != programPropertyString) {
                pendantClientInner.openXmlProgramFile(new File(programPropertyString));
                programSucceeded = pendantClientInner.runProgram(pendantClientInner.getProgram());
                System.out.println("Program " + programPropertyString + " succeeded: " + programSucceeded);
            } else {
                System.err.println("No program specified");
                System.err.println("Use --program option to set a program to run.");
                pendantClientInner.disconnect();
                System.exit(1);
            }
            if(null != poseFileName) {
                try {
                    pendantClientInner.savePoseListToCsvFile(poseFileName);
                } catch (PmException ex) {
                    Logger.getLogger(CmdLineClient.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            pendantClientInner.disconnect();
            
        } catch (ParserConfigurationException ex) {
            Logger.getLogger(CmdLineClient.class.getName()).log(Level.SEVERE, null, ex);
        } catch (JAXBException ex) {
            Logger.getLogger(CmdLineClient.class.getName()).log(Level.SEVERE, null, ex);
        } catch (XPathExpressionException ex) {
            Logger.getLogger(CmdLineClient.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(CmdLineClient.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SAXException ex) {
            Logger.getLogger(CmdLineClient.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
