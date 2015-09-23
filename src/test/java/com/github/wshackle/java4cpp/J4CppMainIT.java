/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wshackle.java4cpp;

import java.io.File;
import java.io.IOException;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author shackle
 */
public class J4CppMainIT {

    public J4CppMainIT() {
    }

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
     * Test of getOnFailString method, of class J4CppMain.
     */
    @Test
    public void testGetOnFailString() {
    }

    /**
     * Test of getMethodReturnVarArrayType method, of class J4CppMain.
     */
    @Test
    public void testGetMethodReturnVarArrayType() {
    }

    /**
     * Test of getMethodReturnVarType method, of class J4CppMain.
     */
    @Test
    public void testGetMethodReturnVarType() {
    }

    /**
     * Test of getMethodReturnOutVarType method, of class J4CppMain.
     */
    @Test
    public void testGetMethodReturnOutVarType() {
    }

    /**
     * Test of getMethodReturnArrayVarDeclare method, of class J4CppMain.
     */
    @Test
    public void testGetMethodReturnArrayVarDeclare() {
    }

    /**
     * Test of getMethodReturnVarDeclare method, of class J4CppMain.
     */
    @Test
    public void testGetMethodReturnVarDeclare() {
    }

    /**
     * Test of getMethodReturnVarDeclareOut method, of class J4CppMain.
     */
    @Test
    public void testGetMethodReturnVarDeclareOut() {
    }

    /**
     * Test of getMethodCallString method, of class J4CppMain.
     */
    @Test
    public void testGetMethodCallString() {
    }

    /**
     * Test of isAddableClass method, of class J4CppMain.
     */
    @Test
    public void testIsAddableClass() {
    }

    /**
     * Test of hasNoArgConstructor method, of class J4CppMain.
     */
    @Test
    public void testHasNoArgConstructor() {
    }

    /**
     * Test of getHomeDir method, of class J4CppMain.
     */
    @Test
    public void testGetHomeDir() throws Exception {
    }

    /**
     * Test of getCurrentDir method, of class J4CppMain.
     */
    @Test
    public void testGetCurrentDir() throws Exception {
    }

    /**
     * Test of main method, of class J4CppMain.
     */
    @Test
    public void testMain() throws IOException, InterruptedException, ClassNotFoundException {
        final String orig_user_dir = System.getProperty("user.dir");
        try {
            final String testDir
                    = System.getProperty("test.dir", "src/test/resources");
            File testDirFile = new File(testDir);
            System.setProperty("user.dir", testDirFile.getAbsolutePath());
            final String testJar
                    = System.getProperty("testproject.jar", "../../../examples/test/java/test/target/test-1.0-SNAPSHOT.jar");
            System.out.println("testJar = " + testJar);
            File testJarFile = new File(testDirFile,testJar);
            if(!testJarFile.exists()) {
                final String testJarPrep = System.getProperty("testJarPrepScript");
                assertTrue(testJarPrep != null && testJarPrep.length() > 0);
                ProcessBuilder pbTestPrep = new ProcessBuilder(testJarPrep);
                pbTestPrep.inheritIO();
                int testPrepRet = pbTestPrep.start().waitFor();
                assertEquals(testPrepRet, 0);
            }
            final String args[]
                    = new String[]{"-v", "--natives", "NativeRunnable=java.lang.Runnable", "NativeDoubleOp=java.util.function.DoubleUnaryOperator","-n", "test", "-j", testJar};
            J4CppMain.main(args);
            assertTrue(J4CppMain.main_completed);
            final String testRunScript
                    = System.getProperty("test.run.script", "./run_test.sh");

            ProcessBuilder pb = new ProcessBuilder(testRunScript);
            pb.directory(testDirFile);
            pb.inheritIO();
            Process p = pb.start();
            int result = p.waitFor();
            assertEquals(result, 0);
        } finally {
            System.setProperty("user.dir", orig_user_dir);
        }
    }

}
