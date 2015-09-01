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

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Arc2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JPanel;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov> }
 */
public class OverHeadJPanel extends JPanel {

    private SimRobotEnum robotType = SimRobotEnum.SIMPLE;

    /**
     * Get the value of robotType
     *
     * @return the value of robotType
     */
    public SimRobotEnum getRobotType() {
        return robotType;
    }

    /**
     * Set the value of robotType
     *
     * @param robotType new value of robotType
     */
    public void setRobotType(SimRobotEnum robotType) {
        this.robotType = robotType;
        this.repaint();
    }

    private double[] jointvals;

    /**
     * Get the value of jointvals
     *
     * @return the value of jointvals
     */
    public double[] getJointvals() {
        return jointvals;
    }

    /**
     * Set the value of jointvals
     *
     * @param jointvals new value of jointvals
     */
    public void setJointvals(double[] jointvals) {
        this.jointvals = jointvals;
    }

    private double[] seglengths = SimulatedKinematicsPlausible.DEFAULT_SEGLENGTHS;

    /**
     * Set the value of seglengths
     *
     * @param seglengths new value of seglengths
     */
    public void setSeglengths(double[] seglengths) {
        this.seglengths = seglengths;
        if(null == seglengths || seglengths.length < 1) {
            return;
        }
        l0rect.width = seglengths[0];
        if(seglengths.length < 2) {
            return;
        }
        l1rect.width = seglengths[1];
        if(seglengths.length < 3) {
            return;
        }
        l2rect.width = seglengths[2];
        if(seglengths.length < 4) {
            return;
        }
        l3rect.width = seglengths[3];
        if(seglengths.length < 5) {
            return;
        }
        l4rect.height = seglengths[4];
        if(seglengths.length < 6) {
            return;
        }
        l5rect.width = seglengths[5];
    }

    Arc2D.Double j1circle = new Arc2D.Double(-10.0, -10.0 // x,y
            , 20, 20 // w,h
            , 0, 360, Arc2D.CHORD);

    Arc2D.Double j2circle = new Arc2D.Double(-6, -6.0 // x,y
            , 12, 12 // w,h
            , 0, 360, Arc2D.CHORD);

    Rectangle2D.Double jrect = new Rectangle2D.Double(0.0, -5.0, 10.0, 10.0);

    Rectangle2D.Double l0rect = new Rectangle2D.Double(0.0, -5.0, seglengths[0], 10.0);
    Rectangle2D.Double l1rect = new Rectangle2D.Double(0.0, -5.0, seglengths[1], 10.0);
    Rectangle2D.Double l2rect = new Rectangle2D.Double(0.0, -5.0, seglengths[2], 10.0);
    Rectangle2D.Double l3rect = new Rectangle2D.Double(0.0, -5.0, seglengths[3], 10.0);
    Rectangle2D.Double l4rect = new Rectangle2D.Double(0.0, -10.0, 5.0, seglengths[4]);
    Rectangle2D.Double l5rect = new Rectangle2D.Double(0.0, -0.5, seglengths[5], 1.0);

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        try {
            Graphics2D g2d = (Graphics2D) g;
            Dimension d = this.getSize();
            g2d.translate(d.width / 2.0, d.height / 2.0);
            switch (robotType) {
                case PLAUSIBLE:
                    if (paintPlausibleRobot(d, g2d)) {
                        return;
                    }
                    break;
                
                case SIMPLE:
                    if (paintSimpleRobot(d, g2d)) {
                        return;
                    }
                    break;
                
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private double maxSimpleJv0 = 0;

    private boolean paintSimpleRobot(Dimension d, Graphics2D g2d) {
        if(null == jointvals || jointvals.length < SimulatedKinematicsSimple.NUM_JOINTS) {
            return true;
        }
        maxSimpleJv0 = Math.max(maxSimpleJv0, jointvals[0]);
        double sfactor = Math.min(d.width / 2.0, d.height / 2.0) / (Math.abs(maxSimpleJv0) + SimulatedKinematicsSimple.DEFAULT_SEGLENGTHS[0]);
        g2d.scale(sfactor, -1.0 * sfactor);
        g2d.setColor(Color.gray);
        g2d.fill(j1circle);
        l0rect.width = Math.cos(Math.toRadians(jointvals[2])) * jointvals[0];
        g2d.rotate(Math.toRadians(jointvals[1]));
        g2d.setColor(Color.yellow);
        g2d.fill(l0rect);
        g2d.translate(l0rect.width, 0.0);
        g2d.setColor(Color.gray);
        g2d.fill(j1circle);
        l1rect.width = Math.cos(Math.toRadians(jointvals[4])) * SimulatedKinematicsSimple.DEFAULT_SEGLENGTHS[0];
        g2d.rotate(Math.toRadians(jointvals[5] - jointvals[2]));
        g2d.setColor(Color.yellow);
        g2d.fill(l1rect);
        return false;
    }

    private boolean paintPlausibleRobot(Dimension d, Graphics2D g2d) {
        double sfactor = Math.min(d.width / 2.0, d.height / 2.0) / (seglengths[0] + seglengths[1] + seglengths[2] + seglengths[3]);
        g2d.scale(sfactor, -1.0 * sfactor);
        g2d.setColor(Color.gray);
        g2d.fill(j1circle);
        if (null == jointvals) {
            return true;
        }
        g2d.rotate(Math.toRadians(jointvals[0]));
        g2d.setColor(Color.yellow);
        double angle = jointvals[1];
        l0rect.width = seglengths[0] * Math.cos(Math.toRadians(angle));
        g2d.fill(l0rect);
        g2d.translate(l0rect.width, 0.0);
        g2d.setColor(Color.yellow);
        angle += jointvals[2];
        l1rect.width = seglengths[1] * Math.cos(Math.toRadians(angle));
        if (l1rect.width <= 0) {
            return true;
        }
        g2d.fill(l1rect);
        g2d.setColor(Color.gray);
        g2d.fill(jrect);
        g2d.translate(l1rect.width, 0.0);
        angle += jointvals[3];
        l2rect.width = seglengths[2] * Math.cos(Math.toRadians(angle));
        if (l2rect.width <= 0) {
            return true;
        }
        g2d.setColor(Color.yellow);
        g2d.fill(l2rect);
        g2d.setColor(Color.gray);
        g2d.fill(jrect);
        g2d.translate(l2rect.width, 0.0);
        l3rect.width = seglengths[3] * Math.cos(Math.toRadians(angle));
        if (l3rect.width <= 0) {
            return true;
        }
        g2d.rotate(Math.toRadians(jointvals[4]));
        g2d.setColor(Color.yellow);
        g2d.fill(l3rect);
        g2d.setColor(Color.gray);
        g2d.fill(j2circle);
        g2d.translate(l3rect.width, 0.0);
        g2d.setColor(Color.BLACK);
        l4rect.height = seglengths[3] * Math.abs(Math.sin(Math.toRadians(jointvals[5])));
        l4rect.y = -0.5 * l5rect.height;
        g2d.fill(l4rect);
        g2d.translate(0.0, l5rect.height / 2.0);
        g2d.fill(l5rect);
        g2d.translate(0.0, -l5rect.height);
        g2d.fill(l5rect);
        return false;
    }

}
