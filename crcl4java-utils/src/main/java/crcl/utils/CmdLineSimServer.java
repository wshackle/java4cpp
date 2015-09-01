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
 */
package crcl.utils;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.parsers.ParserConfigurationException;
import rcs.posemath.Posemath;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class CmdLineSimServer {
    
    public static SimServerInner simServerInner = null;
    
    public static void main(String[] args) {
        try {
            double initPose[][] = null;
            for (int i = 0; i < args.length - 1; i++) {
                switch (args[i]) {
                    case "--delayMillis":
                        System.setProperty("SimServer.delayMillis", args[i + 1]);
                        i++;
                        break;
                    
                    case "--jointSpeedMax":
                        System.setProperty("SimServer.jointSpeedMax", args[i + 1]);
                        i++;
                        break;
                        
                    case "--maxTransSpeed":
                         System.setProperty("SimServer.maxTransSpeed", args[i + 1]);
                        i++;
                        break;
                        
                    case "--maxTransAccel":
                         System.setProperty("SimServer.maxTransAccel", args[i + 1]);
                        i++;
                        break;
                        
                    case "--initPose":
                        initPose = Posemath.csvToHomMats(args[i + 1], 0, 1, 2, 3, 4, 5);
                        break;
                }
            }
            SimServerOuterStub simServerOuterStub = new SimServerOuterStub();
            simServerInner = new SimServerInner(simServerOuterStub);
            if (null != initPose) {
                simServerInner.simulatedTeleportToPose(CRCLPosemath.toPose(initPose));
            }
            simServerInner.restartServer();
        } catch (ParserConfigurationException ex) {
            Logger.getLogger(CmdLineSimServer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
