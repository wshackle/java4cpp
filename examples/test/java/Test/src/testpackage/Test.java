package testpackage;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class Test {

    private List<String> listOfStrings = new ArrayList<>();

    /**
     * Get the value of listOfStrings
     *
     * @return the value of listOfStrings
     */
    public List<String> getListOfStrings() {
        return listOfStrings;
    }

    /**
     * Set the value of listOfStrings
     *
     * @param listOfStrings new value of listOfStrings
     */
    public void setListOfStrings(List<String> listOfStrings) {
        this.listOfStrings = listOfStrings;
    }

    private A classObjectA;

    /**
     * Get the value of classObjectA
     *
     * @return the value of classObjectA
     */
    public A getClassObjectA() {
        return classObjectA;
    }

    /**
     * Set the value of classObjectA
     *
     * @param classObjectA new value of classObjectA
     */
    public void setClassObjectA(A classObjectA) {
        this.classObjectA = classObjectA;
    }

    public static Test getTestStatic() {
        Test t = new Test();
        t.setIntProp(77);
        System.out.println("Java Test getTestStatic() returning : t = " + t);
        return t;
    }

    int i = 4;

    private byte[] byteArrayProp;

    /**
     * Get the value of byteArrayProp
     *
     * @return the value of byteArrayProp
     */
    public byte[] getByteArrayProp() {
        return byteArrayProp;
    }

    /**
     * Set the value of byteArrayProp
     *
     * @param byteArrayProp new value of byteArrayProp
     */
    public void setByteArrayProp(byte[] byteArrayProp) {
        this.byteArrayProp = byteArrayProp;
    }

    private byte byteProp;

    /**
     * Get the value of byteProp
     *
     * @return the value of byteProp
     */
    public byte getByteProp() {
        return byteProp;
    }

    /**
     * Set the value of byteProp
     *
     * @param byteProp new value of byteProp
     */
    public void setByteProp(byte byteProp) {
        this.byteProp = byteProp;
    }

    private char[] charArrayProp;

    /**
     * Get the value of charArrayProp
     *
     * @return the value of charArrayProp
     */
    public char[] getCharArrayProp() {
        return charArrayProp;
    }

    /**
     * Set the value of charArrayProp
     *
     * @param charArrayProp new value of charArrayProp
     */
    public void setCharArrayProp(char[] charArrayProp) {
        this.charArrayProp = charArrayProp;
    }

    private char charProp;

    /**
     * Get the value of charProp
     *
     * @return the value of charProp
     */
    public char getCharProp() {
        return charProp;
    }

    private short shortProp;

    /**
     * Get the value of shortProp
     *
     * @return the value of shortProp
     */
    public short getShortProp() {
        return shortProp;
    }

    /**
     * Set the value of shortProp
     *
     * @param shortProp new value of shortProp
     */
    public void setShortProp(short shortProp) {
        this.shortProp = shortProp;
    }

    private short[] shortArrayProp;

    /**
     * Get the value of shortArrayProp
     *
     * @return the value of shortArrayProp
     */
    public short[] getShortArrayProp() {
        return shortArrayProp;
    }

    private int intProp;

    /**
     * Get the value of intProp
     *
     * @return the value of intProp
     */
    public int getIntProp() {
        return intProp;
    }

    /**
     * Set the value of intProp
     *
     * @param intProp new value of intProp
     */
    public void setIntProp(int intProp) {
        this.intProp = intProp;
    }

    private int[] intArrayProp;

    /**
     * Get the value of intArrayProp
     *
     * @return the value of intArrayProp
     */
    public int[] getIntArrayProp() {
        return intArrayProp;
    }

    /**
     * Set the value of intArrayProp
     *
     * @param intArrayProp new value of intArrayProp
     */
    public void setIntArrayProp(int[] intArrayProp) {
        this.intArrayProp = intArrayProp;
    }

    private long longProp;

    /**
     * Get the value of longProp
     *
     * @return the value of longProp
     */
    public long getLongProp() {
        return longProp;
    }

    /**
     * Set the value of longProp
     *
     * @param longProp new value of longProp
     */
    public void setLongProp(long longProp) {
        this.longProp = longProp;
    }

    private long[] longArrayProp;

    /**
     * Get the value of longArrayProp
     *
     * @return the value of longArrayProp
     */
    public long[] getLongArrayProp() {
        return longArrayProp;
    }

    /**
     * Set the value of longArrayProp
     *
     * @param longArrayProp new value of longArrayProp
     */
    public void setLongArrayProp(long[] longArrayProp) {
        this.longArrayProp = longArrayProp;
    }

    private float floatProp;

    /**
     * Get the value of floatProp
     *
     * @return the value of floatProp
     */
    public float getFloatProp() {
        return floatProp;
    }

    /**
     * Set the value of floatProp
     *
     * @param floatProp new value of floatProp
     */
    public void setFloatProp(float floatProp) {
        this.floatProp = floatProp;
    }

    private float[] floatArrayProp;

    /**
     * Get the value of floatArrayProp
     *
     * @return the value of floatArrayProp
     */
    public float[] getFloatArrayProp() {
        return floatArrayProp;
    }

    /**
     * Set the value of floatArrayProp
     *
     * @param floatArrayProp new value of floatArrayProp
     */
    public void setFloatArrayProp(float[] floatArrayProp) {
        this.floatArrayProp = floatArrayProp;
    }

    private double doubleProp;

    /**
     * Get the value of doubleProp
     *
     * @return the value of doubleProp
     */
    public double getDoubleProp() {
        return doubleProp;
    }

    /**
     * Set the value of doubleProp
     *
     * @param doubleProp new value of doubleProp
     */
    public void setDoubleProp(double doubleProp) {
        this.doubleProp = doubleProp;
    }

    private double[] doubleArrayProp;

    /**
     * Get the value of doubleArrayProp
     *
     * @return the value of doubleArrayProp
     */
    public double[] getDoubleArrayProp() {
        return doubleArrayProp;
    }

    /**
     * Set the value of doubleArrayProp
     *
     * @param doubleArrayProp new value of doubleArrayProp
     */
    public void setDoubleArrayProp(double[] doubleArrayProp) {
        this.doubleArrayProp = doubleArrayProp;
    }

    /**
     * Set the value of shortArrayProp
     *
     * @param shortArrayProp new value of shortArrayProp
     */
    public void setShortArrayProp(short[] shortArrayProp) {
        this.shortArrayProp = shortArrayProp;
    }

    /**
     * Set the value of charProp
     *
     * @param charProp new value of charProp
     */
    public void setCharProp(char charProp) {
        this.charProp = charProp;
    }

    private String strProp = "strProp1";

    /**
     * Get the value of strProp
     *
     * @return the value of strProp
     */
    public String getStrProp() {
        return strProp;
    }

    /**
     * Set the value of strProp
     *
     * @param strProp new value of strProp
     */
    public void setStrProp(String strProp) {
        System.out.println("Java Test.setStrProp("+strProp+") called.");
        this.strProp = strProp;
    }

    public void setI(int i) {
        this.i = i;

    }
    public int getI() {
        System.out.println("Java Test.getI() returning: " + i);
        return i;
    }

    public String funcReturningString() {
        String str = "c++ sucks";
        System.out.println("Java Test.funcReturningStrint() returning: " + str);
        return str;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Java Test.main() called with args=" + Arrays.toString(args));
    }

    @Override
    public String toString() {
        return "Test{" + "i=" + i + ", intProp=" + intProp + '}';
    }

}
