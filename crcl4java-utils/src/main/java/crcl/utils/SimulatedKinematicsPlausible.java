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

import crcl.base.PointType;
import crcl.base.PoseType;
import crcl.base.PoseType;
import crcl.base.VectorType;
import java.awt.geom.Point2D;
import java.math.BigDecimal;
import java.util.Arrays;

/**
 *
 * @author Will Shackleford{@literal <william.shackleford@nist.gov> }
 */
public class SimulatedKinematicsPlausible {

    public static final double DEFAULT_SEGLENGTHS[] = new double[]{60.0, 50.0, 25.0, 15.0, 20.0, 10.0};
    public static final double DEFAULT_JOINTVALS[] = new double[]{0.0, 45.0, -90.0, 90.0, 0.0, 0.0};

    public PoseType jointsToPose(double jv[]) {
        PoseType pose = new PoseType();
        return jointsToPose(jv, pose);
    }

    private double[] seglengths = DEFAULT_SEGLENGTHS;

    private double[] scaled_seglengths = Arrays.copyOf(seglengths, seglengths.length);

    private double scale = 1.0;

    /**
     * Get the value of scale
     *
     * @return the value of scale
     */
    public double getScale() {
        return scale;
    }

    /**
     * Set the value of scale
     *
     * @param scale new value of scale
     */
    public void setScale(double scale) {
        this.scale = scale;
        updateScaledSeglengths(scale);
    }

    private void updateScaledSeglengths(double scale1) {
        scaled_seglengths = new double [seglengths.length];
        for (int i = 0; i < scaled_seglengths.length; i++) {
            scaled_seglengths[i] = scale1 * seglengths[i];
        }
    }

    /**
     * Get the value of seglengths
     *
     * @return the value of seglengths
     */
    public double[] getSeglengths() {
        return seglengths;
    }

    /**
     * Set the value of seglengths
     *
     * @param seglengths new value of seglengths
     */
    public void setSeglengths(double[] seglengths) {
        this.seglengths = seglengths;
        updateScaledSeglengths(scale);
    }

//    public static void printRot9x9(double[][] r) {
//        for (int i = 0; i < 3; i++) {
//            for (int j = 0; j < 3; j++) {
//                //System.err.printf("%+.3g, ", r[i][j]);
//            }
//            //System.err.println("");
//        }
//    }
    public static double[][] rot9x9mult(double[][] r1, double[][] r2) {
        double[][] rout
                = {
                    {0.0, 0.0, 0.0},
                    {0.0, 0.0, 0.0},
                    {0.0, 0.0, 0.0},};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    rout[i][j] += r1[i][k] * r2[k][j];
                }
            }
        }
        return rout;
    }

    public double[] poseToJoints(double[] _jv, PoseType pose) {
        double[] jv = _jv;
        double[] sl = this.scaled_seglengths;
        if (null == jv || jv.length != NUM_JOINTS) {
            jv = new double[NUM_JOINTS];
        }
        //System.err.println("poseToJoints("+Arrays.toString(_jv)+","+pose+") called.");
        for (int i = 0; i < jv.length; i++) {
            if (Double.isNaN(jv[i])) {
                throw new IllegalArgumentException("poseToJoints: jv[" + i + "] isNaN");
            }
            if (Double.isInfinite(jv[i])) {
                throw new IllegalArgumentException("poseToJoints: jv[" + i + "] isInfinite");
            }
        }
        PointType pt = pose.getPoint();
        Point2D.Double endPtXY = new Point2D.Double(
                pt.getX().doubleValue(),
                pt.getY().doubleValue());
        double r = Math.sqrt(
                endPtXY.x * endPtXY.x
                + endPtXY.y * endPtXY.y
        );
        double z = pt.getZ().doubleValue();
        VectorType xv = pose.getXAxis();
        double xvi = xv.getI().doubleValue();
        double xvj = xv.getJ().doubleValue();
        double xvk = xv.getK().doubleValue();
        //System.err.println("xvi="+xvi+",xvj="+xvj+",xvk="+xvk);
        VectorType zv = pose.getZAxis();
        double zvi = zv.getI().doubleValue();
        double zvj = zv.getJ().doubleValue();
        double zvk = zv.getK().doubleValue();
        //System.err.println("zvi="+zvi+",zvj="+zvj+",zvk="+zvk);
        double a2 = Math.atan2(xvk,
                Math.sqrt(xvj * xvj + xvi * xvi));
        //System.err.println("r,z,angle 3 = " + r+","+z+","+Math.toDegrees(a2));
        Point2D.Double j4PointXY = new Point2D.Double(
                endPtXY.x - sl[3] * xvi,
                endPtXY.y - sl[3] * xvj);
        double j4z = pt.getZ().doubleValue() - sl[3] * xvk;
        double a1 = Math.atan2(j4PointXY.y, j4PointXY.x);
        jv[0] = Math.toDegrees(a1);
        jv[4] = Math.toDegrees(Math.atan2(xvj, xvi) - a1);
        double yvi = xvj * zvk - xvk * zvj;
        double yvj = xvi * zvk - xvk * zvi;
        double yvk = xvi * zvj - xvj * zvi;
        jv[5] = Math.toDegrees(Math.atan2(yvk, Math.sqrt(yvi * yvi + yvj * yvj)));

        r = Math.sqrt(
                j4PointXY.x * j4PointXY.x
                + j4PointXY.y * j4PointXY.y
        );
        z = j4z;
        //System.err.println("r,z,angle 2 = " + r+","+z+","+Math.toDegrees(a2));
        r -= sl[2] * Math.cos(a2);
        z -= sl[2] * Math.sin(a2);
        //System.err.println("r,z 1 = " + r+","+z);
        double mag1 = Math.sqrt(r * r + z * z);
        //System.err.println("mag1 = " + mag1);
        double s12_sum2 = sl[0] * sl[0] + sl[1] * sl[1];
        double s12_sum2_sqrt = Math.sqrt(s12_sum2);
        double sum = (sl[0] + sl[1]);
        if (mag1 >= sum) {
            throw new IllegalArgumentException(
                    "distance to Joint3 " + mag1 + " required to be greater than sum of robot segments 1 and 2" + sum);
        }
        double diff = Math.abs(sl[0] - sl[1]);
        if (mag1 <= diff) {
            throw new IllegalArgumentException(
                    "distance to Joint3 " + mag1 + " required to be less than difference of robot segments 1 and 2" + diff);
        }
        //System.err.println("s12_sum2_sqrt = " + s12_sum2_sqrt);
        double a3 = Math.acos((s12_sum2 - mag1 * mag1) / (2 * sl[0] * sl[1])) - Math.PI;
        jv[2] = Math.toDegrees(a3);
        //System.err.println("jv[2] = " + jv[2]);
        double a40 = Math.atan2(z, r);
        //System.err.println("Math.toDegrees(a40) = " + Math.toDegrees(a40));
        double a41 = Math.asin(Math.sin(a3 + Math.PI) * sl[1] / mag1);//Math.acos((sl[0]*sl[0]-sl[1]*sl[1]+mag1*mag1)/(2*sl[0]*mag1));
        //System.err.println("Math.toDegrees(a41) = " + Math.toDegrees(a41));
        double a4 = a40 + a41;
        //System.err.println("Math.toDegrees(a4) = " + Math.toDegrees(a4));
        double z2 = z + Math.cos(a4);
        double mag2 = mag1 - Math.sin(a4);
        double a5 = Math.atan2(z2, mag2);
        jv[1] = Math.toDegrees(a4);
        jv[3] = Math.toDegrees(a2) - jv[2] - jv[1];
        //System.err.println("poseToJoints("+Arrays.toString(_jv)+","+pose+") returning:"+ Arrays.toString(jv));
        return jv;
    }
    public static final int NUM_JOINTS = 6;

    public PoseType jointsToPose(double[] jv, PoseType _pose) {
        PoseType pose = _pose;
        double[] sl = this.scaled_seglengths;
        if (null == pose) {
            pose = new PoseType();
        }
        //System.err.println("jointsToPose("+Arrays.toString(jv)+","+_pose+") called.");
        for (int i = 0; i < jv.length; i++) {
            if (Double.isNaN(jv[i])) {
                throw new IllegalArgumentException("jv[" + i + "]=" + jv[i]);
            }
            if (Double.isInfinite(jv[i])) {
                throw new IllegalArgumentException("jv[" + i + "]=" + jv[i]);
            }
        }
        double angle = jv[1];
        double r = sl[0] * Math.cos(Math.toRadians(angle));
        double z = sl[0] * Math.sin(Math.toRadians(angle));
        //System.err.println("r,z,angle 0 = " + r+","+z+","+angle);
        angle += jv[2];
        r += sl[1] * Math.cos(Math.toRadians(angle));
        z += sl[1] * Math.sin(Math.toRadians(angle));
        //System.err.println("r,z,angle 1 = " + r+","+z+","+angle);
        double mag1 = Math.sqrt(r * r + z * z);
        //System.err.println("mag1 = " + mag1);
        if (mag1 > sl[0] + sl[1]) {
            throw new RuntimeException("distance to joint2 must be less than " + (sl[0] + sl[1]));
        }
        if (mag1 < Math.abs(sl[0] - sl[1])) {
            throw new RuntimeException("distance to joint2 must be atleast than " + Math.abs(sl[0] - sl[1]));
        }

        angle += jv[3];
        r += sl[2] * Math.cos(Math.toRadians(angle));
        z += sl[2] * Math.sin(Math.toRadians(angle));
        //System.err.println("r,z,angle 2 = " + r+","+z+","+angle);
        double x = r * Math.cos(Math.toRadians(jv[0])) + sl[3] * Math.cos(Math.toRadians(jv[4] + jv[0])) * Math.cos(Math.toRadians(angle));
        //System.err.println("x = " + x);
        double y = r * Math.sin(Math.toRadians(jv[0])) + sl[3] * Math.sin(Math.toRadians(jv[4] + jv[0])) * Math.cos(Math.toRadians(angle));
        //System.err.println("y = " + y);
        //System.err.println("Math.sqrt(x*x+y*y)="+Math.sqrt(x*x+y*y));
        r += sl[3] * Math.cos(Math.toRadians(angle)) * Math.cos(Math.toRadians(jv[4]));
        z += sl[3] * Math.sin(Math.toRadians(angle));
        //System.err.println("r,z,angle 3 = " + r+","+z+","+angle);
        PointType p = pose.getPoint();
        if (null == p) {
            p = new PointType();
        }
        p.setX(BigDecimal.valueOf(x));
        p.setY(BigDecimal.valueOf(y));
        p.setZ(BigDecimal.valueOf(z));
        pose.setPoint(p);
        double cz = Math.cos(Math.toRadians(jv[0] + jv[4]));
        double sz = Math.sin(Math.toRadians(jv[0] + jv[4]));
        double cy = Math.cos(Math.toRadians(angle));
        double sy = Math.sin(Math.toRadians(angle));
        double cx = Math.cos(Math.toRadians(jv[5]));
        double sx = Math.sin(Math.toRadians(jv[5]));
        //System.err.println("jv = " + Arrays.toString(jv));
        //System.err.println("angle = " + angle);
        double[][] rx
                = {
                    {1.0, 0.0, 0.0},
                    {0.0, cx, -sx},
                    {0.0, sx, cx},};
        //System.err.println("rx = " + Arrays.deepToString(rx));
        //printRot9x9(rx);
        double[][] ry
                = {
                    {cy, 0.0, sy},
                    {0.0, 1.0, 0.0},
                    {-sy, 0.0, cy},};
        //System.err.println("ry = " + Arrays.deepToString(ry));
        //printRot9x9(ry);
        double[][] rz
                = {
                    {cz, sz, 0.0},
                    {-sz, cz, 0.0},
                    {0.0, 0.0, 1.0},};
        //System.err.println("rz = " + Arrays.deepToString(rz));
        //printRot9x9(rz);
        double[][] Rxy = rot9x9mult(rx, ry);
        //System.err.println("Rxy = " + Arrays.deepToString(Rxy));
        //printRot9x9(Rxy);
        double[][] R = rot9x9mult(Rxy, rz);
        //System.err.println("R = " + Arrays.deepToString(R));
        //printRot9x9(R);
        VectorType xunitv = pose.getXAxis();
        if (null == xunitv) {
            xunitv = new VectorType();
        }
        xunitv.setI(BigDecimal.valueOf(R[0][0]));
        xunitv.setJ(BigDecimal.valueOf(R[0][1]));
        xunitv.setK(BigDecimal.valueOf(R[0][2]));
//        //System.out.println("xunitv = " + xunitv);
        //System.err.println("xunitv.getK().doubleValue() = " + xunitv.getK().doubleValue());
        pose.setXAxis(xunitv);
        VectorType zunitv = pose.getZAxis();
        if (null == zunitv) {
            zunitv = new VectorType();
        }
        zunitv.setI(BigDecimal.valueOf(R[2][0]));
        zunitv.setJ(BigDecimal.valueOf(R[2][1]));
        zunitv.setK(BigDecimal.valueOf(R[2][2]));
        pose.setZAxis(zunitv);
        //System.err.println("jointsToPose("+Arrays.toString(jv)+","+_pose+") returning : "+ pose);
        return pose;
    }
}
