/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * 
 */
package crcl.utils;

import crcl.base.PointType;
import crcl.base.PoseType;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Random;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Will Shackleford<shackle@nist.gov>
 */
public class SimulatedKinematicsPlausibleTest {

    public SimulatedKinematicsPlausibleTest() {
    }

    static SimulatedKinematicsPlausible sk = new SimulatedKinematicsPlausible();

    private static final int RANDOM_SEED = 8321;
    
    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    /**
     * Test of jointsToPose method, of class SimulatedKinematicsPlausible.
     */
    @Test
    public void testJointsToPose_doubleArr_doubleArr() {
//        double jtest[] = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS,
//                SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
//        PoseType pose = sk.jointsToPose(jtest);
//        double j2[] = sk.poseToJoints(null, pose);
//        //System.err.println("j2 = " + Arrays.toString(j2));
//        //System.err.println("jtest = " + Arrays.toString(jtest));
//        assertArrayEquals(jtest, j2, 0.05);
//
//        Random r = new Random();
//        for (int i = 0; i < 500; i++) {
//            try {
//                //System.err.println("");
//                //System.err.println("i = " + i);
//                int index = r.nextInt(jtest.length - 2);
//                //System.err.println("index = " + index);
//                //System.err.println("jtest[index] = " + jtest[index]);
//                jtest[index] += r.nextDouble() * 10.0 - 5.0;
//                if (Math.abs(90 - jtest[1] - jtest[2] - jtest[3]) < 5.0) {
//                    jtest = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
//                    continue;
//                }
//                //System.err.println("jtest[index] = " + jtest[index]);
//                pose = sk.jointsToPose(jtest);
//                j2 = sk.poseToJoints(j2, pose);
//                //System.err.println("j2 = " + Arrays.toString(j2));
//                //System.err.println("jtest = " + Arrays.toString(jtest));
//                for(int ii=  0; ii < jtest.length; ii++) {
//                    if(Math.abs(jtest[ii]-j2[ii]) > 1.0) {
//                        try {
//                            System.err.println("pose="+CRCLToPosemath.poseToString(pose));
//                        } catch (PmException ex) {
//                            Logger.getLogger(SimulatedKinematicsPlausibleTest.class.getName()).log(Level.SEVERE, null, ex);
//                        }
//                        System.err.println("j2="+Arrays.toString(j2));
//                        System.err.println("jtest="+Arrays.toString(jtest));
//                        break;
//                    }
//                }
//                assertArrayEquals(jtest, j2, 1.0);
//            } catch (IllegalArgumentException iae) {
//                // ignore
//            }
//        }
    }

    /**
     * Test of printRot9x9 method, of class SimulatedKinematicsPlausible.
     */
    @Test
    public void testPrintRot9x9() {
    }

    /**
     * Test of rot9x9mult method, of class SimulatedKinematicsPlausible.
     */
    @Test
    public void testRot9x9mult() {
    }

    /**
     * Test of poseToJoints method, of class SimulatedKinematicsPlausible.
     */
    @Test
    public void testPoseToJoints() {
        double jtest[] = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS,
                SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
        PoseType pose = sk.jointsToPose(jtest);

        Random r = new Random(RANDOM_SEED);
        for (int i = 0; i < 100; i++) {
            try {
                //System.err.println("");
                //System.err.println("i = " + i);
                int index = r.nextInt(3);
                //System.err.println("index = " + index);
                PointType pt = pose.getPoint();
                switch (index) {
                    case 0:
                        //System.err.println("pt.getX().doubleValue() = " + pt.getX().doubleValue());
                        pt.setX(pt.getX().add(BigDecimal.valueOf(r.nextDouble() * 20.0 - 10.0)));
                        //System.err.println("pt.getX().doubleValue() = " + pt.getX().doubleValue());
                        pose.setPoint(pt);
                        break;

                    case 1:
                        //System.err.println("pt.getY().doubleValue() = " + pt.getY().doubleValue());
                        pt.setY(pt.getY().add(BigDecimal.valueOf(r.nextDouble() * 20.0 - 10.0)));
                        //System.err.println("pt.getY().doubleValue() = " + pt.getY().doubleValue());
                        pose.setPoint(pt);
                        break;

                    case 2:
                        //System.err.println("pt.getZ().doubleValue() = " + pt.getZ().doubleValue());
                        pt.setZ(pt.getZ().add(BigDecimal.valueOf(r.nextDouble() * 20.0 - 10.0)));
                        //System.err.println("pt.getZ().doubleValue() = " + pt.getZ().doubleValue());
                        pose.setPoint(pt);
                        break;
                }

                jtest = sk.poseToJoints(jtest, pose);
                //System.err.println("jtest = " + Arrays.toString(jtest));
                PoseType pose2 = sk.jointsToPose(jtest);
                //System.err.println("jtest = " + Arrays.toString(jtest));
                double j2[] = sk.poseToJoints(null, pose2);
                //System.err.println("jtest = " + Arrays.toString(jtest));
                //System.err.println("j2 = " + Arrays.toString(j2));

                PointType pt1 = pose.getPoint();
                //System.err.printf("pt1 = (%+.3g,%+.3g,%+.3g)\n",
//                        pt1.getX().doubleValue(),
//                        pt1.getY().doubleValue(),
//                        pt1.getZ().doubleValue()
//                );
                PointType pt2 = pose2.getPoint();
                //System.err.printf("pt2 = (%+.3g,%+.3g,%+.3g)\n",
//                        pt2.getX().doubleValue(),
//                        pt2.getY().doubleValue(),
//                        pt2.getZ().doubleValue()
//                );
                assertArrayEquals(j2, jtest, 1.0);
                assertEquals(pt1.getX().doubleValue(), pt2.getX().doubleValue(), 5.0);
                assertEquals(pt1.getY().doubleValue(), pt2.getY().doubleValue(), 5.0);
                assertEquals(pt1.getZ().doubleValue(), pt2.getZ().doubleValue(), 5.0);
            } catch (IllegalArgumentException iae) {
                // ignore
            }
        }
    }

    /**
     * Test of jointsToPose method, of class SimulatedKinematicsPlausible.
     */
    @Test
    public void testJointsToPose_3args() {
    }

}