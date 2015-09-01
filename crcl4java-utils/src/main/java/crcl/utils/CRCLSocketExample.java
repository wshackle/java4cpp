/* 
 * This is public domain software, however it is preferred
 * that the following disclaimers be attached.
 * 
 * Software Copywrite/Warranty Disclaimer
 * 
 * This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. This software is experimental.
 * NIST assumes no responsibility whatsoever for its use by other
 * parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic. We would appreciate
 * acknowledgment if the software is used. This software can be
 * redistributed and/or modified freely provided that any derivative works
 * bear some notice that they are derived from it, and any modified
 * versions bear some notice that they have been modified.
 * 
 */
package crcl.utils;

import crcl.base.CRCLCommandInstanceType;
import crcl.base.CRCLStatusType;
import crcl.base.CommandStatusType;
import crcl.base.GetStatusType;
import crcl.base.InitCanonType;
import crcl.base.JointStatusType;
import crcl.base.JointStatusesType;
import crcl.base.MoveToType;
import crcl.base.PointType;
import crcl.base.PoseType;
import crcl.base.VectorType;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Will Shackleford{@literal <william.shackleford@nist.gov> }
 */
public class CRCLSocketExample {
    public static void main(String[] args) {
        try {
            // Connect to the server
            CRCLSocket s = new CRCLSocket("localhost",CRCLSocket.DEFAULT_PORT);
            
            // Create an instance to wrap all commands.
            CRCLCommandInstanceType instance = new CRCLCommandInstanceType();
            
            // Create and send init command.
            InitCanonType init = new InitCanonType();
            init.setCommandID(BigInteger.valueOf(7));
            instance.setCRCLCommand(init);
            s.writeCommand(instance,false);
            
            // Create and send MoveTo command.
            MoveToType moveTo = new MoveToType();
            moveTo.setCommandID(BigInteger.valueOf(8));
            PoseType pose = new PoseType();
            PointType pt = new PointType();
            pt.setX(BigDecimal.valueOf(1.1));
            pt.setY(BigDecimal.valueOf(0.0));
            pt.setZ(BigDecimal.valueOf(0.1));
            pose.setPoint(pt);
            VectorType xAxis = new VectorType();
            xAxis.setI(BigDecimal.ONE);
            xAxis.setI(BigDecimal.ZERO);
            xAxis.setI(BigDecimal.ZERO);
            pose.setXAxis(xAxis);
            VectorType zAxis = new VectorType();
            zAxis.setI(BigDecimal.ZERO);
            zAxis.setI(BigDecimal.ZERO);
            zAxis.setI(BigDecimal.ONE);
            pose.setXAxis(zAxis);
            moveTo.setEndPosition(pose);
            moveTo.setMoveStraight(false);
            s.writeCommand(instance,false);
            
            // Create and send getStatus request.
            GetStatusType getStat = new GetStatusType();
            getStat.setCommandID(BigInteger.valueOf(9));
            instance.setCRCLCommand(getStat);
            s.writeCommand(instance,false);
            
            // Read status from server
            CRCLStatusType stat = s.readStatus(false);
            
            // Print out the status details.
            CommandStatusType cmdStat = stat.getCommandStatus();
            BigInteger IDback = cmdStat.getCommandID();
            System.out.println("Status:");
            System.out.println("CommandID = " + IDback);
            System.out.println("State = "+cmdStat.getCommandState());
            pt = stat.getPose().getPoint();
            System.out.println("pose = "+pt.getX()+","+pt.getY()+","+pt.getZ());
            JointStatusesType jst = stat.getJointStatuses();
            List<JointStatusType> l = jst.getJointStatus();
            System.out.println("Joints:");
            l.forEach(js -> System.out.println("Num="+js.getJointNumber()+" Pos="+js.getJointPosition()));
        } catch (Exception ex) {
            Logger.getLogger(CRCLSocketExample.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}
