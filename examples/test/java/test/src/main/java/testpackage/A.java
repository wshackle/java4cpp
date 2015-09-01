/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testpackage;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class A {
    
    public static Test getTestStatic() {
        Test t =  new Test();
        System.out.println("Java A getTestStatic() returning : t = " + t);
        return t;
    }
    
    public Test getTestNonStatic() {
        Test t =  new Test();
        System.out.println("Java A getTestNonStatic() returning : t = " + t);
        return t;
    }
    
}
