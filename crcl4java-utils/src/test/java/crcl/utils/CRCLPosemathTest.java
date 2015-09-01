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
import java.math.BigDecimal;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.apache.commons.math3.geometry.euclidean.threed.Rotation;
import org.apache.commons.math3.geometry.euclidean.threed.Vector3D;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;
import rcs.posemath.PmCartesian;
import rcs.posemath.PmException;
import rcs.posemath.PmPose;
import rcs.posemath.PmQuaternion;
import rcs.posemath.PmRotationMatrix;
import rcs.posemath.PmRotationVector;
import rcs.posemath.PmRpy;
import rcs.posemath.Posemath;

/**
 *
 * @author Will Shackleford<shackle@nist.gov>
 */
public class CRCLPosemathTest {

    public CRCLPosemathTest() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    private PointType pt123 = null;
    private PointType pt321 = null;
    private PmCartesian cart123 = null;
    private PmCartesian cart321 = null;
    private VectorType xvec = null;
    private VectorType yvec = null;
    private VectorType zvec = null;
    private PoseType pose123 = null;
    private PoseType pose321 = null;
    private PoseType pose321rot90 = null;

    static final private double ASSERT_TOLERANCE_DELTA = 1e-6;

    private void checkEquals(String msg, double v1, double v2) {
        assertEquals(msg, v1, v2, ASSERT_TOLERANCE_DELTA);
    }

//    private void checkEquals(String msg, BigDecimal v1,double v2) {
//        assertEquals(msg, v1.doubleValue(), v2, ASSERT_TOLERANCE_DELTA);
//    }
//    
//    private void checkEquals(String msg, double v1, BigDecimal v2) {
//        assertEquals(msg, v1, v2.doubleValue(), ASSERT_TOLERANCE_DELTA);
//    }
    private void checkEquals(String msg, BigDecimal v1, BigDecimal v2) {
        assertTrue(msg + " both are null or neither is null", (v1 == null) == (v2 == null));
        if (v1 == null) {
            return;
        }
        checkEquals(msg, v1.doubleValue(), v2.doubleValue());
    }

//    private void checkEquals(String msg, PmCartesian cart, PointType pt) {
//        checkEquals(msg+".x",cart.x, pt.getX());
//        checkEquals(msg+".y",cart.y, pt.getY());
//        checkEquals(msg+".z",cart.z, pt.getZ());
//    }
    private void checkEquals(String msg, PmCartesian cart1, PmCartesian cart2) {
        checkEquals(msg + ".x", cart1.x, cart2.x);
        checkEquals(msg + ".y", cart1.y, cart2.y);
        checkEquals(msg + ".z", cart1.z, cart2.z);
    }

    private void checkEquals(String msg, PmQuaternion quat1, PmQuaternion quat2) {
        checkEquals(msg + ".s", quat1.s, quat2.s);
        checkEquals(msg + ".x", quat1.x, quat2.x);
        checkEquals(msg + ".y", quat1.y, quat2.y);
        checkEquals(msg + ".z", quat1.z, quat2.z);
    }

    private void checkEquals(String msg, PmRotationMatrix cart1, PmRotationMatrix cart2) {
        checkEquals(msg + ".x", cart1.x, cart2.x);
        checkEquals(msg + ".y", cart1.y, cart2.y);
        checkEquals(msg + ".z", cart1.z, cart2.z);
    }

    private void checkEquals(String msg, PointType pt1, PointType pt2) {
        checkEquals(msg + ".getX()", pt1.getX(), pt2.getX());
        checkEquals(msg + ".getY()", pt1.getY(), pt2.getY());
        checkEquals(msg + ".getZ()", pt1.getZ(), pt2.getZ());
    }

    private void checkEquals(String msg, VectorType v1, VectorType v2) {
        checkEquals(msg + ".getI()", v1.getI(), v2.getI());
        checkEquals(msg + ".getJ()", v1.getJ(), v2.getJ());
        checkEquals(msg + ".getK()", v1.getK(), v2.getK());
    }

    private void checkEquals(String msg, PoseType pose1, PoseType pt2) {
        checkEquals(msg + ".getPoint()", pose1.getPoint(), pt2.getPoint());
        checkEquals(msg + ".getXAxis()", pose1.getXAxis(), pt2.getXAxis());
        checkEquals(msg + ".getZAxis()", pose1.getZAxis(), pt2.getZAxis());
    }

    private void checkEquals(String msg, Rotation rot1, Rotation rot2) {
        double m1[][] = rot1.getMatrix();
        double m2[][] = rot2.getMatrix();
        assertArrayEquals(msg + "[0]", m1[0], m2[0], ASSERT_TOLERANCE_DELTA);
        assertArrayEquals(msg + "[1]", m1[1], m2[1], ASSERT_TOLERANCE_DELTA);
        assertArrayEquals(msg + "[2]", m1[2], m2[2], ASSERT_TOLERANCE_DELTA);
    }

    @Before
    public void setUp() {
        pt123 = new PointType();
        pt123.setX(BIG_DECIMAL_1);
        pt123.setY(BIG_DECIMAL_2);
        pt123.setZ(BIG_DECIMAL_3);

        pt321 = new PointType();
        pt321.setX(BIG_DECIMAL_3);
        pt321.setY(BIG_DECIMAL_2);
        pt321.setZ(BIG_DECIMAL_1);

        xvec = new VectorType();
        xvec.setI(BigDecimal.ONE);
        xvec.setJ(BigDecimal.ZERO);
        xvec.setK(BigDecimal.ZERO);

        yvec = new VectorType();
        yvec.setI(BigDecimal.ZERO);
        yvec.setJ(BigDecimal.ONE);
        yvec.setK(BigDecimal.ZERO);

        zvec = new VectorType();
        zvec.setI(BigDecimal.ZERO);
        zvec.setJ(BigDecimal.ZERO);
        zvec.setK(BigDecimal.ONE);

        pose123 = new PoseType();
        pose123.setPoint(pt123);
        pose123.setXAxis(xvec);
        pose123.setZAxis(zvec);

        pose321 = new PoseType();
        pose321.setPoint(pt321);
        pose321.setXAxis(xvec);
        pose321.setZAxis(zvec);

        pose321rot90 = new PoseType();
        pose321rot90.setPoint(pt321);
        pose321rot90.setXAxis(yvec);
        pose321rot90.setZAxis(zvec);

        cart123 = new PmCartesian(1.0, 2.0, 3.0);
        cart321 = new PmCartesian(3.0, 2.0, 1.0);
    }

    private static final BigDecimal BIG_DECIMAL_1 = BigDecimal.ONE;
    private static final BigDecimal BIG_DECIMAL_2 = new BigDecimal("2");
    private static final BigDecimal BIG_DECIMAL_3 = new BigDecimal("3");
    private static final BigDecimal BIG_DECIMAL_4 = new BigDecimal("4");

    @After
    public void tearDown() {
    }

    /**
     * Test of pointToPmCartesian method, of class CRCLToPosemath.
     */
    @Test
    public void testPointToPmCartesian() {
        System.out.println("pointToPmCartesian");
        PointType pt = this.pt123;
        PmCartesian expResult = this.cart123;
        PmCartesian result = CRCLPosemath.pointToPmCartesian(pt);
        checkEquals("123", expResult, result);
    }

    /**
     * Test of diffPoints method, of class CRCLToPosemath.
     */
    @Test
    public void testDiffPoints() {
        System.out.println("diffPoints");
        PointType pt1 = this.pt123;
        PointType pt2 = this.pt321;

        // result should = sqrt((3-1)^2 + (2-2)^2 + (1-3)^2) = sqrt(8)
        double expResult = Math.sqrt(8);
        double result = CRCLPosemath.diffPoints(pt1, pt2);

        assertEquals(expResult, result, ASSERT_TOLERANCE_DELTA);
    }

    /**
     * Test of diffPosesTran method, of class CRCLToPosemath.
     */
    @Test
    public void testDiffPosesTran() {
        System.out.println("diffPosesTran");
        PoseType p1 = this.pose123;
        PoseType p2 = this.pose321;
        // result should = sqrt((3-1)^2 + (2-2)^2+(1-3)^2) = sqrt(8)
        double expResult = Math.sqrt(8.0);
        double result = CRCLPosemath.diffPosesTran(p1, p2);
        assertEquals(expResult, result, ASSERT_TOLERANCE_DELTA);
    }

    /**
     * Test of vectorToPmCartesian method, of class CRCLToPosemath.
     */
    @Test
    public void testVectorToPmCartesian() {
        System.out.println("vectorToPmCartesian");
        VectorType v = this.xvec;
        PmCartesian expResult = new PmCartesian(1.0, 0.0, 0.0);
        PmCartesian result = CRCLPosemath.vectorToPmCartesian(v);
        checkEquals("xvec", result, expResult);
    }

    /**
     * Test of toPoseType method, of class CRCLToPosemath.
     */
    @Test
    public void testToPoseType() throws Exception {
        System.out.println("toPoseType");
        PmCartesian tran = this.cart321;
        PmRotationVector v = new PmRotationVector(Math.PI / 2, 0.0, 0.0, 1.0);
        PoseType expResult = this.pose321rot90;
        PoseType result = CRCLPosemath.toPoseType(tran, v);
        checkEquals("pose321rot90", result, expResult);
    }

    /**
     * Test of toPmRotationMatrix method, of class CRCLToPosemath.
     */
    @Test
    public void testToPmRotationMatrix() throws Exception {
        System.out.println("toPmRotationMatrix");
        PoseType p = this.pose123;
        PmRotationMatrix expResult = new PmRotationMatrix(
                1.0, 0.0, 0.0,
                0.0, 1.0, 0.0,
                0.0, 0.0, 1.0
        );
        PmRotationMatrix result = CRCLPosemath.toPmRotationMatrix(p);
        checkEquals("RotMat", expResult, result);

        Random r = new Random(RANDOM_SEED);
        for (int i = 0; i < 300; i++) {
            PmRpy rpy1 = new PmRpy(r.nextDouble()*2.0*Math.PI-Math.PI, 
                    r.nextDouble()*Math.PI - Math.PI/2.0,
                    r.nextDouble() * 2.0 * Math.PI - Math.PI);
            expResult = Posemath.toMat(rpy1);
            p = CRCLPosemath.toPoseType(cart123, Posemath.toRot(rpy1));
            result = CRCLPosemath.toPmRotationMatrix(p);
            checkEquals("randRotMat", expResult, result);
        }
    }

    /**
     * Test of toPmRotationVector method, of class CRCLToPosemath.
     */
    @Test
    public void testToPmRotationVector() throws Exception {
        System.out.println("toPmRotationVector");
        PoseType p = this.pose321rot90;
        PmRotationVector expResult = new PmRotationVector(Math.PI / 2, 0.0, 0.0, 1.0);
        PmRotationVector result = CRCLPosemath.toPmRotationVector(p);

        assertEquals("s", expResult.s, result.s, ASSERT_TOLERANCE_DELTA);
        assertEquals("x", expResult.x, result.x, ASSERT_TOLERANCE_DELTA);
        assertEquals("y", expResult.y, result.y, ASSERT_TOLERANCE_DELTA);
        assertEquals("z", expResult.z, result.z, ASSERT_TOLERANCE_DELTA);
    }

    /**
     * Test of maxDiffDoubleArray method, of class CRCLToPosemath.
     */
    @Test
    public void testMaxDiffDoubleArray() {
        System.out.println("maxDiffDoubleArray");
        double[] da = new double[]{0, 0, 0.2, 0};
        double[] da2 = new double[]{0, 0, -0.2, 0};
        double expResult = 0.4;
        double result = CRCLPosemath.maxDiffDoubleArray(da, da2);
        assertEquals(expResult, result, ASSERT_TOLERANCE_DELTA);
        try {
            CRCLPosemath.maxDiffDoubleArray(da, new double[1]);
            fail("Expected IllegalArgumentException since array lengths don't match");
        } catch (IllegalArgumentException expectedException) {
        }
    }

    /**
     * Test of diffPosesRot method, of class CRCLToPosemath.
     */
    @Test
    public void testDiffPosesRot() throws Exception {
        System.out.println("diffPosesRot");
        PoseType pose1 = this.pose321;
        PoseType pose2 = this.pose321rot90;
        double expResult = Math.PI / 2;
        double result = CRCLPosemath.diffPosesRot(pose1, pose2);
        assertEquals(expResult, result, ASSERT_TOLERANCE_DELTA);
    }

    /**
     * Test of toPointType method, of class CRCLToPosemath.
     */
    @Test
    public void testToPointType() {
        System.out.println("toPointType");
        PmCartesian c = this.cart123;
        PointType expResult = this.pt123;
        PointType result = CRCLPosemath.toPointType(c);
        checkEquals("123", result, expResult);
    }

//    /**
//     * Test of toPoseType method, of class CRCLToPosemath.
//     */
//    @Test
//    public void testToPoseType() throws Exception {
//        System.out.println("toPoseType");
//        PmCartesian tran = this.cart123;
//        PmRotationVector v = new PmRotationVector(Math.toRadians(30), 0.0, 0.0, 1.0);
//        PoseType expResult = new PoseType();
//        VectorType xvector = new VectorType();
//        xvector.setI(BigDecimal.valueOf(Math.cos(Math.toRadians(30.0))));
//        xvector.setJ(BigDecimal.valueOf(Math.sin(Math.toRadians(30.0))));
//        xvector.setK(BigDecimal.ZERO);
//        VectorType zvector = new VectorType();
//        zvector.setI(BigDecimal.ZERO);
//        zvector.setJ(BigDecimal.ZERO);
//        zvector.setK(BigDecimal.ONE);
//        PointType pt = new PointType();
//        pt.setX(BigDecimal.ONE);
//        pt.setY(BIG_DECIMAL_2);
//        pt.setZ(BIG_DECIMAL_3);
//        expResult.setPoint(pt);
//        expResult.setXAxis(xvector);
//        expResult.setZAxis(zvector);
//        PoseType result = CRCLPosemath.toPoseType(tran, v);
//        checkEquals("123", result, expResult);
//    }

    /**
     * Test of toPmRpy method, of class CRCLToPosemath.
     */
    @Test
    public void testToPmRpy() throws Exception {
        System.out.println("toPmRpy");
        PoseType p = new PoseType() {
        };
        PmRpy expResult = new PmRpy(Math.toRadians(20.0), Math.toRadians(25.0), Math.toRadians(30.0));
        PmRotationMatrix mat = Posemath.toMat(expResult);
        VectorType xvector = new VectorType();
        xvector.setI(BigDecimal.valueOf(mat.x.x));
        xvector.setJ(BigDecimal.valueOf(mat.x.y));
        xvector.setK(BigDecimal.valueOf(mat.x.z));
        p.setXAxis(xvector);
        VectorType zvector = new VectorType();
        zvector.setI(BigDecimal.valueOf(mat.z.x));
        zvector.setJ(BigDecimal.valueOf(mat.z.y));
        zvector.setK(BigDecimal.valueOf(mat.z.z));
        p.setZAxis(zvector);
        PmRpy result = CRCLPosemath.toPmRpy(p);
        assertEquals(expResult.r, result.r, 1e-4);
        assertEquals(expResult.p, result.p, 1e-4);
        assertEquals(expResult.y, result.y, 1e-4);
    }

    /**
     * Test of poseToString method, of class CRCLToPosemath.
     */
    @Test
    public void testPoseToString() throws Exception {
        System.out.println("poseToString");
        PoseType pose = pose321rot90;
        String expResult = "{\n"
                + "{0.00,1.00,0.00,3.00},\n"
                + "{-1.00,0.00,0.00,2.00},\n"
                + "{0.00,0.00,1.00,1.00},\n"
                + "{0.00,0.00,0.00,1.00}\n"
                + "}";
        String result = CRCLPosemath.poseToString(pose);
        assertEquals(expResult, result);
    }

    /**
     * Test of toPoseType method, of class CRCLToPosemath.
     */
    @Test
    public void testToPoseType_3args() throws Exception {
        System.out.println("toPoseType");
        PmCartesian tran = this.cart321;
        PmRotationVector v = new PmRotationVector(Math.PI / 2, 0.0, 0.0, 1.0);
        PoseType pose_in = new PoseType();
        PoseType expResult = pose_in;
        PoseType result = CRCLPosemath.toPoseType(tran, v, pose_in);
        // result refences the same memory as expResult
        assertTrue(expResult == result);

        result = CRCLPosemath.toPoseType(tran, v, null);
        // result no longer refences the same memory but all members are approximately equal
        assertTrue(expResult != result);
        checkEquals("123rot90", result, expResult);

    }

    /**
     * Test of add method, of class CRCLPosemath.
     */
    @Test
    public void testAdd() {
        System.out.println("add");
        PointType p1 = this.pt123;
        PointType p2 = this.pt321;
        PointType expResult = new PointType();
        expResult.setX(BIG_DECIMAL_4);
        expResult.setY(BIG_DECIMAL_4);
        expResult.setZ(BIG_DECIMAL_4);
        PointType result = CRCLPosemath.add(p1, p2);
        checkEquals("444", result, expResult);
    }

    /**
     * Test of subtract method, of class CRCLPosemath.
     */
    @Test
    public void testSubtract() {
        System.out.println("subtract");
        PointType p1 = this.pt123;
        PointType p2 = this.pt321;
        PointType expResult = new PointType();
        expResult.setX(BigDecimal.valueOf(-2.0));
        expResult.setY(BigDecimal.valueOf(0.0));
        expResult.setZ(BigDecimal.valueOf(+2.0));
        PointType result = CRCLPosemath.subtract(p1, p2);
        checkEquals("-2,0,+2", result, expResult);
    }

    /**
     * Test of multiply method, of class CRCLPosemath.
     */
    @Test
    public void testMultiply_BigDecimal_VectorType() {
        System.out.println("multiply");
        BigDecimal dist = BigDecimal.valueOf(2.5);
        VectorType v = this.xvec;
        PointType expResult = new PointType();
        expResult.setX(BigDecimal.valueOf(2.5));
        expResult.setY(BigDecimal.ZERO);
        expResult.setZ(BigDecimal.ZERO);
        PointType result = CRCLPosemath.multiply(dist, v);
        checkEquals("2.5,0,0", expResult, result);
    }

    /**
     * Test of multiply method, of class CRCLPosemath.
     */
    @Test
    public void testMultiply_double_VectorType() {
        System.out.println("multiply");
        double dist = 2.5;
        VectorType v = this.zvec;
        PointType expResult = new PointType();
        expResult.setX(BigDecimal.ZERO);
        expResult.setY(BigDecimal.ZERO);
        expResult.setZ(BigDecimal.valueOf(2.5));
        PointType result = CRCLPosemath.multiply(dist, v);
        checkEquals("0,0,2.5", expResult, result);
    }

    /**
     * Test of multiply method, of class CRCLPosemath.
     */
    @Test
    public void testMultiply_BigDecimal_PointType() {
        System.out.println("multiply");
        BigDecimal dist = BigDecimal.valueOf(3.5);
        PointType p = this.pt123;
        PointType expResult = new PointType();
        expResult.setX(BigDecimal.valueOf(1.0 * 3.5));
        expResult.setY(BigDecimal.valueOf(2.0 * 3.5));
        expResult.setZ(BigDecimal.valueOf(3.0 * 3.5));
        PointType result = CRCLPosemath.multiply(dist, p);
        checkEquals("3.5*(1,2,3)", expResult, result);
    }

    /**
     * Test of multiply method, of class CRCLPosemath.
     */
    @Test
    public void testMultiply_double_PointType() {
        System.out.println("multiply");
        double dist = 0.3;
        PointType p = this.pt321;
        PointType expResult = new PointType();
        expResult.setX(BigDecimal.valueOf(3.0 * 0.3));
        expResult.setY(BigDecimal.valueOf(2.0 * 0.3));
        expResult.setZ(BigDecimal.valueOf(1.0 * 0.3));
        PointType result = CRCLPosemath.multiply(dist, p);
        checkEquals("0.3*(3,2,1)", expResult, result);
    }

    /**
     * Test of dot method, of class CRCLPosemath.
     */
    @Test
    public void testDot_VectorType_VectorType() {
        System.out.println("dot");
        VectorType v1 = this.xvec;
        VectorType v2 = this.yvec;
        BigDecimal expResult = BigDecimal.ZERO;
        BigDecimal result = CRCLPosemath.dot(v1, v2);
        checkEquals("x dot y", expResult, result);
        v1 = this.zvec;
        v2 = this.zvec;
        expResult = BigDecimal.ONE;
        result = CRCLPosemath.dot(v1, v2);
        checkEquals("z dot z", expResult, result);
    }

    /**
     * Test of dot method, of class CRCLPosemath.
     */
    @Test
    public void testDot_VectorType_PointType() {
        System.out.println("dot");
        VectorType v1 = this.zvec;
        PointType p2 = this.pt123;
        BigDecimal expResult = BIG_DECIMAL_3;
        BigDecimal result = CRCLPosemath.dot(v1, p2);
        checkEquals("z dot (1,2,3)", expResult, result);
    }

    /**
     * Test of cross method, of class CRCLPosemath.
     */
    @Test
    public void testCross() {
        System.out.println("cross");
        VectorType v1 = this.xvec;
        VectorType v2 = this.yvec;
        VectorType expResult = this.zvec;
        VectorType result = CRCLPosemath.cross(v1, v2);
        checkEquals("x cross y", expResult, result);
        v1 = this.zvec;
        v2 = this.xvec;
        expResult = this.yvec;
        result = CRCLPosemath.cross(v1, v2);
        checkEquals("z cross x", expResult, result);

        Random r = new Random(RANDOM_SEED);
        for (int i = 0; i < 100; i++) {
            try {
                PmCartesian cart1 = new PmCartesian(r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0);
                cart1 = cart1.multiply(1.0 / Posemath.mag(cart1));
                PmCartesian cart2 = new PmCartesian(r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0);
                cart2 = cart2.multiply(1.0 / Posemath.mag(cart2));
                v1 = new VectorType();
                v1.setI(BigDecimal.valueOf(cart1.x));
                v1.setJ(BigDecimal.valueOf(cart1.y));
                v1.setK(BigDecimal.valueOf(cart1.z));
                v2 = new VectorType();
                v2.setI(BigDecimal.valueOf(cart2.x));
                v2.setJ(BigDecimal.valueOf(cart2.y));
                v2.setK(BigDecimal.valueOf(cart2.z));
                PmCartesian cross = new PmCartesian();
                Posemath.pmCartCartCross(cart1, cart2, cross);
                expResult = new VectorType();
                expResult.setI(BigDecimal.valueOf(cross.x));
                expResult.setJ(BigDecimal.valueOf(cross.y));
                expResult.setK(BigDecimal.valueOf(cross.z));
                
                
                result = CRCLPosemath.cross(v1, v2);
                checkEquals("randomCross (posemath)", result, expResult);
                
                Vector3D v3Da = new Vector3D(cart1.x,cart1.y,cart1.z);
                Vector3D v3Db = new Vector3D(cart2.x,cart2.y,cart2.z);
                Vector3D cross2 = v3Da.crossProduct(v3Db);
                expResult = CRCLPosemath.toCRCLVector(cross2);
                checkEquals("randomCross2 (commons-math)", result, expResult);
                
            } catch (PmException ex) {
                Logger.getLogger(CRCLPosemathTest.class.getName()).log(Level.SEVERE, null, ex);
                fail("Exception not expected.");
            }
        }
    }

    private static final int RANDOM_SEED = 9321;

    /**
     * Test of multiply method, of class CRCLPosemath.
     */
    @Test
    public void testMultiply_PoseType_PoseType() {
        System.out.println("multiply");
        PoseType p1 = this.pose123;
        PoseType p2 = this.pose321;
        PoseType expResult = new PoseType();
        PointType pt444 = new PointType();
        pt444.setX(BIG_DECIMAL_4);
        pt444.setY(BIG_DECIMAL_4);
        pt444.setZ(BIG_DECIMAL_4);
        expResult.setPoint(pt444);
        expResult.setXAxis(xvec);
        expResult.setZAxis(zvec);
        PoseType result = CRCLPosemath.multiply(p1, p2);
        checkEquals("444", expResult, result);
        p1 = this.pose321rot90;
        p2 = this.pose123;
        expResult = new PoseType();
        PointType pt2 = new PointType();
        pt2.setX(BigDecimal.valueOf(3.0 - 2.0));
        pt2.setY(BigDecimal.valueOf(2.0 + 1.0));
        pt2.setZ(BigDecimal.valueOf(1.0 + 3.0));
        expResult.setPoint(pt2);
        expResult.setXAxis(yvec);
        expResult.setZAxis(zvec);
        result = CRCLPosemath.multiply(p1, p2);
        try {
            PmCartesian chkCart
                    = CRCLPosemath.toPmRotationMatrix(p1).multiply(CRCLPosemath.pointToPmCartesian(p2.getPoint()));
            System.out.println("chkCart = " + chkCart);
        } catch (PmException ex) {
            Logger.getLogger(CRCLPosemathTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        checkEquals("234", expResult, result);

        testWithRandomMults();
    }

    public void testWithRandomMults() {
        PoseType p1;
        PoseType p2;
        PoseType result;
        PoseType expResult;
        Random r = new Random(RANDOM_SEED);
        for (int i = 0; i < 100; i++) {
            try {
                PmRpy rpy1 = new PmRpy(r.nextDouble() * 2.0 * Math.PI - Math.PI,
                        r.nextDouble() * Math.PI - Math.PI / 2.0,
                        r.nextDouble() * 2.0 * Math.PI - Math.PI
                );
                PmRpy rpy2 = new PmRpy(r.nextDouble() * 2.0 * Math.PI - Math.PI,
                        r.nextDouble() * Math.PI - Math.PI / 2.0,
                        r.nextDouble() * 2.0 * Math.PI - Math.PI
                );
                PmCartesian cart1 = new PmCartesian(r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0);

                PmCartesian cart2 = new PmCartesian(r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0);

                PmPose pose1 = new PmPose(cart1, Posemath.toQuat(rpy1));
                PmPose pose2 = new PmPose(cart2, Posemath.toQuat(rpy2));
                PmPose poseProduct = new PmPose();
                Posemath.pmPosePoseMult(pose1, pose2, poseProduct);
                PmPose revPoseProduct = new PmPose();
                Posemath.pmPosePoseMult(pose2, pose1, revPoseProduct);
                p1 = CRCLPosemath.toPoseType(cart1, Posemath.toRot(rpy1));
                p2 = CRCLPosemath.toPoseType(cart2, Posemath.toRot(rpy2));
                result = CRCLPosemath.multiply(p1, p2);
                expResult = CRCLPosemath.toPoseType(poseProduct.tran, Posemath.toRot(poseProduct.rot));
                checkEquals("poseProduct", result, expResult);
            } catch (PmException ex) {
                Logger.getLogger(CRCLPosemathTest.class.getName()).log(Level.SEVERE, null, ex);
                fail("PmException thrown.");
            }

        }
    }

    /**
     * Test of shift method, of class CRCLPosemath.
     */
    @Test
    public void testShift() {
        System.out.println("shift");
        PoseType poseIn = this.pose321rot90;
        PointType pt = this.pt123;
        PoseType expResult = new PoseType();
        PointType expResultPt = CRCLPosemath.add(pose321rot90.getPoint(), pt);
        expResult.setPoint(expResultPt);
        expResult.setXAxis(poseIn.getXAxis());
        expResult.setZAxis(poseIn.getZAxis());
        PoseType result = CRCLPosemath.shift(poseIn, pt);
        checkEquals("444rot90", result, expResult);
    }

    /**
     * Test of pointXAxisZAxisToPose method, of class CRCLPosemath.
     */
    @Test
    public void testPointXAxisZAxisToPose() {
        System.out.println("pointXAxisZAxisToPose");
        PointType pt = this.pt123;
        VectorType x = this.xvec;
        VectorType z = this.zvec;
        PoseType expResult = this.pose123;
        PoseType result = CRCLPosemath.pointXAxisZAxisToPose(pt, x, z);
        checkEquals("123", expResult, result);
    }

    /**
     * Test of toPoseType method, of class CRCLPosemath.
     */
    @Test
    public void testToPoseType_PmCartesian_PmRotationVector() throws Exception {
        System.out.println("toPoseType");
        PmCartesian tran = this.cart321;
        PmRotationVector v = new PmRotationVector(Math.PI / 2.0, 0.0, 0.0, 1.0);
        PoseType expResult = this.pose321rot90;
        PoseType result = CRCLPosemath.toPoseType(tran, v);
        checkEquals("pose321rot90", result, expResult);
    }

    /**
     * Test of toPose method, of class CRCLPosemath.
     */
    @Test
    public void testToPose() {
        System.out.println("toPose");
        double[][] mat = new double[][]{
            {+0.0, +1.0, +0.0, +3.0},
            {-1.0, +0.0, +0.0, +2.0},
            {+0.0, +0.0, +1.0, +1.0},
            {+0.0, +0.0, +0.0, +1.0}
        };
        PoseType expResult = this.pose321rot90;
        PoseType result = CRCLPosemath.toPose(mat);
        checkEquals("fromMat", result, expResult);
    }

    /**
     * Test of invert method, of class CRCLPosemath.
     */
    @Test
    public void testInvert() {
        System.out.println("invert");
        PoseType p = this.pose123;
        PoseType expResult = new PoseType();
        PointType pt = new PointType();
        pt.setX(BIG_DECIMAL_1.negate());
        pt.setY(BIG_DECIMAL_2.negate());
        pt.setZ(BIG_DECIMAL_3.negate());
        expResult.setPoint(pt);
        expResult.setXAxis(xvec);
        expResult.setZAxis(zvec);
        PoseType result = CRCLPosemath.invert(p);
        checkEquals("invert", expResult, result);

        PoseType identity = CRCLPosemath.identityPose();
        PoseType identityCheck = CRCLPosemath.multiply(p, result);
        checkEquals("identity", identityCheck, identity);
        Random r = new Random(RANDOM_SEED);
        for (int i = 0; i < 100; i++) {
            try {
                PmRpy rpy1 = new PmRpy(r.nextDouble() * 2.0 * Math.PI - Math.PI,
                        r.nextDouble() * Math.PI - Math.PI / 2.0,
                        r.nextDouble() * 2.0 * Math.PI - Math.PI
                );
                PmCartesian cart1 = new PmCartesian(r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0,
                        r.nextDouble() * 2.0 - 1.0);

                p = CRCLPosemath.toPoseType(cart1, Posemath.toRot(rpy1));
                result = CRCLPosemath.invert(p);
                identityCheck = CRCLPosemath.multiply(p, result);
                checkEquals("identity", identityCheck, identity);
            } catch (PmException ex) {
                Logger.getLogger(CRCLPosemathTest.class.getName()).log(Level.SEVERE, null, ex);
                fail("PmException thrown.");
            }
        }
    }

    /**
     * Test of toCommonsVector3D method, of class CRCLPosemath.
     */
    @Test
    public void testToCommonsVector3D_VectorType() {
        System.out.println("toCommonsVector3D");
        VectorType vIn = xvec;
        Vector3D expResult = Vector3D.PLUS_I;
        Vector3D result = CRCLPosemath.toCommonsVector3D(vIn);
        assertEquals(expResult, result);
    }

    /**
     * Test of toCommonsVector3D method, of class CRCLPosemath.
     */
    @Test
    public void testToCommonsVector3D_PointType() {
        System.out.println("toCommonsVector3D");
        PointType ptIn = pt123;
        Vector3D expResult = new Vector3D(1, 2, 3);
        Vector3D result = CRCLPosemath.toCommonsVector3D(ptIn);
        assertEquals(expResult, result);
    }

    /**
     * Test of toCommonsVector3D method, of class CRCLPosemath.
     */
    @Test
    public void testToCommonsVector3D_PoseType() {
        System.out.println("toCommonsVector3D");
        PoseType poseIn = pose321rot90;
        Vector3D expResult = new Vector3D(3, 2, 1);
        Vector3D result = CRCLPosemath.toCommonsVector3D(poseIn);
        assertEquals(expResult, result);
    }

    /**
     * Test of toCRCLUnitVector method, of class CRCLPosemath.
     */
    @Test
    public void testToCRCLUnitVector_Vector3D_VectorType() {
        System.out.println("toCRCLUnitVector");
        Vector3D vIn = Vector3D.PLUS_I;
        VectorType vOut = null;
        VectorType expResult = xvec;
        VectorType result = CRCLPosemath.toCRCLUnitVector(vIn, vOut);
        checkEquals("xvec", result, expResult);
    }

    /**
     * Test of toCRCLUnitVector method, of class CRCLPosemath.
     */
    @Test
    public void testToCRCLUnitVector_Vector3D() {
        System.out.println("toCRCLUnitVector");
        Vector3D vIn = Vector3D.PLUS_I;
        VectorType expResult = xvec;
        VectorType result = CRCLPosemath.toCRCLUnitVector(vIn);
        checkEquals("xvec", result, expResult);
    }

    /**
     * Test of toCommonsRotation method, of class CRCLPosemath.
     */
    @Test
    public void testToCommonsRotation() {
        System.out.println("toCommonsRotation");
        PoseType poseIn = pose321rot90;
        // NOTICE the MINUS sign, commons-math uses opposite convention
        Rotation expResult = new Rotation(Vector3D.PLUS_K, -Math.PI / 2);
        Rotation result = CRCLPosemath.toCommonsRotation(poseIn);
        checkEquals("rot90", expResult, result);
    }

    /**
     * Test of toCRCLPoint method, of class CRCLPosemath.
     */
    @Test
    public void testToCRCLPoint_Vector3D_PointType() {
        System.out.println("toCRCLPoint");
        Vector3D vIn = new Vector3D(1, 2, 3);
        PointType ptOut = new PointType();
        PointType expResult = pt123;
        PointType result = CRCLPosemath.toCRCLPoint(vIn, null);
        checkEquals("pt123", result, expResult);
        result = CRCLPosemath.toCRCLPoint(vIn, ptOut);
        checkEquals("pt123", result, expResult);
        assertTrue(ptOut == result);
    }

    /**
     * Test of toCRCLPoint method, of class CRCLPosemath.
     */
    @Test
    public void testToCRCLPoint_Vector3D() {
        System.out.println("toCRCLPoint");
        Vector3D vIn = new Vector3D(1, 2, 3);
        PointType expResult = pt123;
        PointType result = CRCLPosemath.toCRCLPoint(vIn);
        checkEquals("pt123", result, expResult);
    }

    /**
     * Test of identityPose method, of class CRCLPosemath.
     */
    @Test
    public void testIdentityPose() {
        System.out.println("identityPose");
//        PoseType expResult = null;
        PoseType result = CRCLPosemath.identityPose();
        checkEquals("xvec", xvec, result.getXAxis());
        checkEquals("zvec", zvec, result.getZAxis());
        PointType zeroPoint = new PointType();
        zeroPoint.setX(BigDecimal.ZERO);
        zeroPoint.setY(BigDecimal.ZERO);
        zeroPoint.setZ(BigDecimal.ZERO);
        checkEquals("point", zeroPoint, result.getPoint());
    }

    /**
     * Test of toPmPose method, of class CRCLPosemath.
     */
    @Test
    public void testToPmPose() throws Exception {
        System.out.println("toPmPose");
        PoseType p = pose321rot90;
        PmPose expResult = new PmPose(cart321,
                new PmQuaternion(new PmRotationVector(Math.PI / 2, 0, 0, 1)));
        PmPose result = CRCLPosemath.toPmPose(p);
        checkEquals("tran", result.tran, expResult.tran);
        checkEquals("rot", result.rot, expResult.rot);

    }

    /**
     * Test of toHomMat method, of class CRCLPosemath.
     */
    @Test
    public void testToHomMat() {
        System.out.println("toHomMat");
        PoseType poseIn = pose321rot90;
        double[][] expResult = new double[][]{
            {+0, 1, 0, 3},
            {-1, 0, 0, 2},
            {+0, 0, 1, 1},
            {+0, 0, 0, 1}
        };
        double[][] result = CRCLPosemath.toHomMat(poseIn);
        assertArrayEquals("mat[0]", expResult[0], result[0], ASSERT_TOLERANCE_DELTA);
        assertArrayEquals("mat[1]", expResult[1], result[1], ASSERT_TOLERANCE_DELTA);
        assertArrayEquals("mat[2]", expResult[2], result[2], ASSERT_TOLERANCE_DELTA);
        assertArrayEquals("mat[3]", expResult[3], result[3], ASSERT_TOLERANCE_DELTA);
    }

}
