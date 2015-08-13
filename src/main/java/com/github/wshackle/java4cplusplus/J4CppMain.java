/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wshackle.java4cplusplus;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class J4CppMain {

    private static String getCppPrimitiveType(Class<?> clss) {
        if (boolean.class.isAssignableFrom(clss)) {
            return "jboolean";
        } else if (byte.class.isAssignableFrom(clss)) {
            return "jbyte";
        } else if (char.class.isAssignableFrom(clss)) {
            return "jchar";
        } else if (short.class.isAssignableFrom(clss)) {
            return "jshort";
        } else if (int.class.isAssignableFrom(clss)) {
            return "jint";
        } else if (long.class.isAssignableFrom(clss)) {
            return "jlong";
        } else if (float.class.isAssignableFrom(clss)) {
            return "jfloat";
        } else if (double.class.isAssignableFrom(clss)) {
            return "jdouble";
        } else if (void.class.isAssignableFrom(clss)) {
            return "void";
        } else {
            throw new IllegalArgumentException("getCppPrimitiveType() Class=" + clss + " not recognized.");
        }
    }

    private static String getCppArrayType(Class<?> clss) {
        if (boolean.class.isAssignableFrom(clss)) {
            return "jbooleanArray";
        } else if (byte.class.isAssignableFrom(clss)) {
            return "jbyteArray";
        } else if (char.class.isAssignableFrom(clss)) {
            return "jcharArray";
        } else if (short.class.isAssignableFrom(clss)) {
            return "jshortArray";
        } else if (int.class.isAssignableFrom(clss)) {
            return "jintArray";
        } else if (long.class.isAssignableFrom(clss)) {
            return "jlongArray";
        } else if (float.class.isAssignableFrom(clss)) {
            return "jfloatArray";
        } else if (double.class.isAssignableFrom(clss)) {
            return "jdoubleArray";
        } else {
            return "jobjectArray";
        }
    }

    private static String getCppRelativeName(Class<?> cls, Class<?> relClass) {
        String basepackages[] = cls.getCanonicalName().split("\\.");
        String packages[] = relClass.getCanonicalName().split("\\.");
        int i = 0;
        int index = 0;
        for (i = 0; i < basepackages.length - 1 && i < packages.length - 1; i++) {
            if (!packages[i].equals(basepackages[i])) {
                break;
            }
            index += packages[i].length() + 1;
        }
        return cls
                .getCanonicalName()
                .substring(index)
                .replace(".", "::");
    }

    private static String getCppType(Class<?> clss, Class<?> relClass) {
        if (clss.isArray()) {
            Class<?> componentType = clss.getComponentType();
            return getCppArrayType(componentType);
        }
        if (clss.isPrimitive()) {
            return getCppPrimitiveType(clss);
        }
        if (Void.class.isAssignableFrom(clss)) {
            return "void";
        } else if (String.class.isAssignableFrom(clss)) {
            return "jstring";
        } else {
            return getCppRelativeName(clss, relClass);
        }
    }

    private static String getCppModifiers(Method m) {
        int mods = m.getModifiers();
        String out = "";
        if (0 != (mods & Modifier.STATIC)) {
            out += "static ";
        } else if (0 != (mods & Modifier.FINAL)) {
            out += "virtual ";
        }
        return out;
    }

    private static String classToParamNameDecl(Class<?> c, int index) {
        if (c.isArray()) {
            return classToParamName(c.getComponentType()) + "Array_" + index;
        }
        return c.getSimpleName().substring(0, 1).toLowerCase() + c.getSimpleName().substring(1) + "_" + index;
    }

    private static String classToParamName(Class<?> c) {
        if (c.isArray()) {
            return classToParamName(c.getComponentType()) + "Array";
        }
        return c.getSimpleName().substring(0, 1).toLowerCase() + c.getSimpleName().substring(1);
    }

    private static String classToJNISignature(Class<?> clss) {
        if (boolean.class.isAssignableFrom(clss)) {
            return "Z";
        } else if (byte.class.isAssignableFrom(clss)) {
            return "B";
        } else if (char.class.isAssignableFrom(clss)) {
            return "C";
        } else if (short.class.isAssignableFrom(clss)) {
            return "S";
        } else if (int.class.isAssignableFrom(clss)) {
            return "I";
        } else if (long.class.isAssignableFrom(clss)) {
            return "J";
        } else if (float.class.isAssignableFrom(clss)) {
            return "F";
        } else if (double.class.isAssignableFrom(clss)) {
            return "D";
        } else if (void.class.isAssignableFrom(clss)) {
            return "V";
        } else if (clss.isArray()) {
            return "[" + classToJNISignature(clss.getComponentType());
        } else {
            return "L" + clss.getCanonicalName().replace(".", "/") + ";";
        }
    }

    private static String getJNIParamSignature(Class<?>[] clsses) {
        return Stream.of(clsses)
                .map(J4CppMain::classToJNISignature)
                .collect(Collectors.joining(""));
    }

    private static String getCppParamNames(Class<?>[] clsses) {
//        return Stream.of(clsses)
//                .map(J4CppMain::classToParamName)
//                .collect(Collectors.joining(","));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < clsses.length; i++) {
            Class<?> clsse = clsses[i];
            String name = classToParamName(clsse) + "_" + i;
            sb.append(name);
            if (i < clsses.length - 1) {
                sb.append(",");
            }
        }
        return sb.toString();
    }

    private static String getCppParamDeclarations(Class<?>[] clsses, Class<?> relClass) {
        StringBuilder sb = new StringBuilder();
        sb.append("(");
        for (int i = 0; i < clsses.length; i++) {
            Class<?> clsse = clsses[i];
            String name = getCppType(clsse, relClass) + " " + classToParamNameDecl(clsse, i);
            sb.append(name);
            if (i < clsses.length - 1) {
                sb.append(",");
            }
        }
        sb.append(")");
        return sb.toString();
//        return "("
//                + Stream.of(clsses)
//                .map(c -> getCppType(c) + " " + classToParamNameDecl(c))
//                .collect(Collectors.joining(",")) + ")";
    }

    private static Set<String> badNames = getBadNames();

    private static Set<String> getBadNames() {
        Set<String> badNamesSet = new HashSet<>();
        badNamesSet.addAll(Arrays.asList("and", "and_eq", "bitand",
                "bitor", "compl", "not", "not_eq", "or",
                "not_eq", "or", "or_eq", "xor", "xor_eq"));
        return badNamesSet;
    }

    private static String fixMethodName(String mname) {
        if (badNames.contains(mname)) {
            return mname + "Method";
        }
        return mname;
    }

    private static String getCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m)
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m.getName())
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    private static String getCppMethodDefinitionStart(String tabs,
            String clssOnlyName,
            Method m,
            Class<?> relClass) {
        return tabs //+ getCppModifiers(m)
                + getCppType(m.getReturnType(), relClass) + " "
                + clssOnlyName
                + "::"
                + fixMethodName(m.getName())
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + " {\n";
    }

    public static String getOnFailString(Class returnClass, Class relClass) {
        if (boolean.class.isAssignableFrom(returnClass)) {
            return "return false;";
        } else if (byte.class.isAssignableFrom(returnClass)) {
            return "return (jbyte) -1;";
        } else if (char.class.isAssignableFrom(returnClass)) {
            return "return (jchar) -1;";
        } else if (short.class.isAssignableFrom(returnClass)) {
            return "return (jshort) -1;";
        } else if (int.class.isAssignableFrom(returnClass)) {
            return "return (jint) -1;";
        } else if (long.class.isAssignableFrom(returnClass)) {
            return "return (jlong) -1;";
        } else if (float.class.isAssignableFrom(returnClass)) {
            return "return (jfloat) -1.0;";
        } else if (double.class.isAssignableFrom(returnClass)) {
            return "return (jdouble) -1.0;";
        } else if (void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (Void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (String.class.isAssignableFrom(returnClass)) {
            return "return NULL;";
        } else if (returnClass.isArray()) {
            return "return NULL;";
        } else {
            return getCppRelativeName(returnClass, relClass) + " nullObject((jobject)NULL,false); return nullObject;";
        }
    }

    public static String getMethodReturnVarArrayType(Class returnClass) {
        if (boolean.class.isAssignableFrom(returnClass)) {
            return "jbooleanArray";
        } else if (byte.class.isAssignableFrom(returnClass)) {
            return "jbyteArray";
        } else if (char.class.isAssignableFrom(returnClass)) {
            return "jcharArray";
        } else if (short.class.isAssignableFrom(returnClass)) {
            return "jshortArray";
        } else if (int.class.isAssignableFrom(returnClass)) {
            return "jintArray";
        } else if (long.class.isAssignableFrom(returnClass)) {
            return "jlongArray";
        } else if (float.class.isAssignableFrom(returnClass)) {
            return "jfloatArray";
        } else if (double.class.isAssignableFrom(returnClass)) {
            return "jdoubleArray";
        } else if (void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (Void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (String.class.isAssignableFrom(returnClass)) {
            return "jobjectArray";
        } else {
            return "jobjectArray";
        }
    }

    public static String getMethodReturnVarType(Class returnClass) {
        if (returnClass.isArray()) {
            return getMethodReturnVarArrayType(returnClass.getComponentType());
        } else if (boolean.class.isAssignableFrom(returnClass)) {
            return "jboolean";
        } else if (byte.class.isAssignableFrom(returnClass)) {
            return "jbyte";
        } else if (char.class.isAssignableFrom(returnClass)) {
            return "jchar";
        } else if (short.class.isAssignableFrom(returnClass)) {
            return "jshort";
        } else if (int.class.isAssignableFrom(returnClass)) {
            return "jint";
        } else if (long.class.isAssignableFrom(returnClass)) {
            return "jlong";
        } else if (float.class.isAssignableFrom(returnClass)) {
            return "jfloat";
        } else if (double.class.isAssignableFrom(returnClass)) {
            return "jdouble";
        } else if (void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (Void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (String.class.isAssignableFrom(returnClass)) {
            return "jstring";
        } else {
            return "jobject";
        }
    }

    public static String getMethodReturnArrayVarDeclare(Class returnClass) {
        if (boolean.class.isAssignableFrom(returnClass)) {
            return "jbooleanArray retVal=NULL;";
        } else if (byte.class.isAssignableFrom(returnClass)) {
            return "jbyteArray retVal=NULL;";
        } else if (char.class.isAssignableFrom(returnClass)) {
            return "jcharArray retVal=NULL;";
        } else if (short.class.isAssignableFrom(returnClass)) {
            return "jshortArray retVal=NULL;";
        } else if (int.class.isAssignableFrom(returnClass)) {
            return "jintArray retVal=NULL;";
        } else if (long.class.isAssignableFrom(returnClass)) {
            return "jlongArray retVal=NULL;";
        } else if (float.class.isAssignableFrom(returnClass)) {
            return "jfloatArray retVal=NULL;";
        } else if (double.class.isAssignableFrom(returnClass)) {
            return "jdoubleArray retVal=NULL;";
        } else if (void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (Void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (String.class.isAssignableFrom(returnClass)) {
            return "jobjectArray retVal=NULL;";
        } else {
            return "jobjectArray retVal=NULL;";
        }
    }

    public static String getMethodReturnVarDeclare(Class returnClass) {
        if (returnClass.isArray()) {
            return getMethodReturnArrayVarDeclare(returnClass.getComponentType());
        } else if (boolean.class.isAssignableFrom(returnClass)) {
            return "jboolean retVal=false;";
        } else if (byte.class.isAssignableFrom(returnClass)) {
            return "jbyte retVal= (jbyte) -1;";
        } else if (char.class.isAssignableFrom(returnClass)) {
            return "jchar retVal= (jchar) -1;";
        } else if (short.class.isAssignableFrom(returnClass)) {
            return "jshort retVal=(jshort) -1;";
        } else if (int.class.isAssignableFrom(returnClass)) {
            return "jint retVal= (jint) -1;";
        } else if (long.class.isAssignableFrom(returnClass)) {
            return "jlong retVal= (jlong) -1;";
        } else if (float.class.isAssignableFrom(returnClass)) {
            return "jfloat retVal= (jfloat) -1.0;";
        } else if (double.class.isAssignableFrom(returnClass)) {
            return "jdouble retVal= (jdouble) -1.0;";
        } else if (void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (Void.class.isAssignableFrom(returnClass)) {
            return "";
        } else if (String.class.isAssignableFrom(returnClass)) {
            return "jstring retVal=NULL;";
        } else {
            return "jobject retVal=NULL;";
        }
    }

    public static String getMethodCallString(Class returnClass) {
        if (boolean.class.isAssignableFrom(returnClass)) {
            return "Boolean";
        } else if (byte.class.isAssignableFrom(returnClass)) {
            return "Byte";
        } else if (char.class.isAssignableFrom(returnClass)) {
            return "Char";
        } else if (short.class.isAssignableFrom(returnClass)) {
            return "Short";
        } else if (int.class.isAssignableFrom(returnClass)) {
            return "Int";
        } else if (long.class.isAssignableFrom(returnClass)) {
            return "Long";
        } else if (float.class.isAssignableFrom(returnClass)) {
            return "Float";
        } else if (double.class.isAssignableFrom(returnClass)) {
            return "Double";
        } else if (void.class.isAssignableFrom(returnClass)) {
            return "Void";
        } else {
            return "Object";
        }
    }

//    public static Optional<String> getArg(final String param, final String args[]) {
//        Arrays.stream(args)
//                .
//    }
    private static String replaceVars(Map<String, String> map, final String orig_str) {
        String key = null;
        String val = null;
        String str = orig_str;
        try {
            for (Map.Entry<String, String> e : map.entrySet()) {
                key = e.getKey();
                val = e.getValue();
                str = str.replaceAll(key, val);
            }
        } catch (Throwable t) {
            System.err.println("orig_str=" + orig_str);
            System.err.println("str=" + str);
            System.err.println("key=" + key);
            System.err.println("val=" + val);
            System.err.println("map="+map);
            t.printStackTrace();
            throw new RuntimeException(t);
        }
        return str;
    }

    private static boolean isVoid(Class<?> clss) {
        return clss.equals(Void.class) || clss.equals(void.class);
    }

    private static boolean isArrayStringMethod(Method m) {
        Class paramClasses[] = m.getParameterTypes();
        return paramClasses.length == 1
                && paramClasses[0].isArray()
                && paramClasses[0].getComponentType().equals(String.class);
    }

    private static boolean checkClass(Class<?> clss, List<Class> classes) {
        Class<?> componentClass = clss.getComponentType();
        return String.class.isAssignableFrom(clss)
                || clss.isPrimitive()
                || (clss.isArray()
                && null != componentClass
                && !componentClass.isArray()
                && checkClass(componentClass, classes))
                || classes.contains(clss);
    }

    private static boolean checkParameters(Class paramTypes[], List<Class> classes) {
        for (Class paramType : paramTypes) {
            if (!checkClass(paramType, classes)) {
                return false;
            }
        }
        return true;
    }

    private static boolean checkMethod(Method m, List<Class> classes) {
        if (m.isSynthetic()) {
            return false;
        }
        if (!Modifier.isPublic(m.getModifiers())
                || Modifier.isAbstract(m.getModifiers())) {
            return false;
        }
        if (!checkClass(m.getReturnType(), classes)) {
            return false;
        }
        return checkParameters(m.getParameterTypes(), classes);
    }

    public static boolean isAddableClass(Class<?> clss, Set<Class> excludedClasses) {
        if (clss.isArray() || clss.isSynthetic() || clss.isAnnotation() || clss.isPrimitive()) {
            return false;
        }
        String canonicalName = null;
        try {
            canonicalName = clss.getCanonicalName();
        } catch (Throwable t) {
            // leaving canonicalName null is enough
        }
        if (null == canonicalName) {
            return false;
        }
        if(canonicalName.indexOf('$') >= 0) {
            return false;
        }
        Method ma[] = null;
        try {
            ma = clss.getDeclaredMethods();
        } catch (Throwable t) {
            // leaving canonicalName null is enough
        }
        if (null == ma) {
            return false;
        }
        return !excludedClasses.contains(clss);
    }

    public static void main(String[] args) {

        try {

            Options options = new Options();
            options.addOption(Option.builder("?")
                    .desc("Print this message")
                    .longOpt("help")
                    .build());
            options.addOption(Option.builder("n")
                    .hasArg()
                    .desc("C++ namespace for newly generated classes.")
                    .longOpt("namespace")
                    .build());
            options.addOption(Option.builder("o")
                    .hasArg()
                    .desc("Output C++ source file.")
                    .longOpt("output")
                    .build());
            options.addOption(Option.builder("j")
                    .hasArg()
                    .desc("Input jar file")
                    .longOpt("jar")
                    .build());
            options.addOption(Option.builder("h")
                    .hasArg()
                    .desc("Output C++ header file.")
                    .longOpt("header")
                    .build());
            String namespace = null;
            String output = null;
            String header = null;
            String jar = null;

            try {
                // parse the command line arguments
                CommandLine line = new DefaultParser().parse(options, args);

//            // validate that block-size has been set
//            if (line.hasOption("block-size")) {
//                // print the value of block-size
//                System.out.println(line.getOptionValue("block-size"));
//            }
                jar = line.getOptionValue("jar", jar);
                System.out.println("jar = " + jar);
                if (null != jar) {
                    if (jar.startsWith("~/")) {
                        jar = System.getProperty("user.home") + jar.substring(1);
                    }
                    int lastSep = jar.lastIndexOf(File.separator);
                    int start = Math.max(0, lastSep + 1);
                    int period = jar.indexOf('.', start + 1);
                    int end = Math.max(start + 1, period);
                    namespace = jar.substring(start, end).toLowerCase().replace("-", "");
                }
                namespace = line.getOptionValue("namespace", namespace);
                System.out.println("namespace = " + namespace);
                if (null != namespace) {
                    output = namespace + ".cpp";
                }
                output = line.getOptionValue("output", output);
                System.out.println("output = " + output);
                if (null != output) {
                    if (output.startsWith("~/")) {
                        output = System.getProperty("user.home") + output.substring(1);
                    }
                    header = output.substring(0, output.lastIndexOf('.')) + ".h";
                } else {
                    output = "out.cpp";
                }
                header = line.getOptionValue("header", header);
                System.out.println("header = " + header);
                if (null != header) {
                    if (header.startsWith("~/")) {
                        header = System.getProperty("user.home") + header.substring(1);
                    }
                } else {
                    header = "out.h";
                }
                if (line.hasOption("help")) {
                    printHelpAndExit(options);
                }
            } catch (ParseException exp) {
                System.out.println("Unexpected exception:" + exp.getMessage());
                printHelpAndExit(options);
            }

            List<Class> classes = new ArrayList<>();
            Path jarPath = FileSystems.getDefault().getPath(jar);
            ZipInputStream zip = new ZipInputStream(Files.newInputStream(jarPath, StandardOpenOption.READ));
            URL[] urls = {new URL("jar:file:" + jar + "!/")};
            URLClassLoader cl = URLClassLoader.newInstance(urls);
            Set<Class> excludedClasses = new HashSet<>();
            excludedClasses.add(Object.class);
            excludedClasses.add(String.class);
            excludedClasses.add(void.class);
            excludedClasses.add(Void.class);
            excludedClasses.add(Class.class);
            for (ZipEntry entry = zip.getNextEntry(); entry != null; entry = zip.getNextEntry()) {
                if (!entry.isDirectory() && entry.getName().endsWith(".class")) {
                    // This ZipEntry represents a class. Now, what class does it represent?
                    String entryName = entry.getName();
                    if(entryName.indexOf('$') >= 0) {
                        continue;
                    }
                    String classFileName = entry.getName()
                            .replace('/', '.');
                    String className = classFileName
                            .substring(0, classFileName.length() - ".class".length());
                    Class clss = cl.loadClass(className);
                    if (!classes.contains(clss)
                            && isAddableClass(clss, excludedClasses)) {
                        System.out.println("clss = " + clss);
                        classes.add(clss);
                        Class superClass = clss.getSuperclass();
                        while (null != superClass
                                && !classes.contains(superClass)
                                && isAddableClass(superClass, excludedClasses)) {
                            classes.add(superClass);
                            superClass = superClass.getSuperclass();
                        }
                    }
                }
            }
            List<Class> newClasses = new ArrayList<Class>();
            for (Class clss : classes) {
                try {
                    for (Method m : clss.getDeclaredMethods()) {
                        if (m.isSynthetic()) {
                            continue;
                        }
                        if (!Modifier.isPublic(m.getModifiers())
                                || Modifier.isAbstract(m.getModifiers())) {
                            continue;
                        }
                        Class retType = m.getReturnType();
                        Method ma[] = null;
                        try {
                            ma = clss.getDeclaredMethods();
                        } catch (Throwable t) {
                            // leaving ma null is enough
                        }
                        if (null == ma) {
                            continue;
                        }
                        if (!classes.contains(retType)
                                && !excludedClasses.contains(retType)
                                && !newClasses.contains(retType)
                                && !retType.isArray()
                                && !retType.isPrimitive()) {
                            newClasses.add(retType);
                            Class superClass = retType.getSuperclass();
                            ma = null;
                            try {
                                ma = clss.getDeclaredMethods();
                            } catch (Throwable t) {
                                // leaving ma null is enough
                            }
                            if (null == ma) {
                                continue;
                            }
                            while (null != superClass
                                    && !classes.contains(superClass)
                                    && !newClasses.contains(superClass)
                                    && !excludedClasses.contains(superClass)) {
                                ma = null;
                                try {
                                    ma = superClass.getDeclaredMethods();
                                } catch (Throwable t) {
                                    // leaving ma null is enough
                                }
                                if (null == ma) {
                                    break;
                                }
                                newClasses.add(superClass);
                                superClass = superClass.getSuperclass();
                            }
                        }
                        for (Class paramType : m.getParameterTypes()) {
                            if (!classes.contains(paramType)
                                    && !excludedClasses.contains(paramType)
                                    && !newClasses.contains(paramType)
                                    && !paramType.isArray()
                                    && !paramType.isPrimitive()) {
                                newClasses.add(paramType);
                                Class superClass = paramType.getSuperclass();
                                while (null != superClass
                                        && !classes.contains(superClass)
                                        && !newClasses.contains(superClass)
                                        && !excludedClasses.contains(superClass)) {
                                    newClasses.add(superClass);
                                    superClass = superClass.getSuperclass();
                                }
                            }
                        }
                    }
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
            classes.addAll(newClasses);
            Map<Class, Integer> classMap = new HashMap<>();
            for (Class clss : classes) {
                classMap.put(clss, 0);
            }
            for (Class clss : classes) {
                Class superClass = clss.getSuperclass();
                while (null != superClass && classMap.containsKey(superClass)) {
                    classMap.put(superClass, classMap.get(superClass) - 1);
                    superClass = superClass.getSuperclass();
                }
            }
            Collections.sort(classes, new Comparator<Class>() {

                @Override
                public int compare(Class o1, Class o2) {
                    if (o1 == null || classMap.get(o1) == null) {
                        System.out.println("bad o1=" + o1);
                    }
                    if (o2 == null || classMap.get(o2) == null) {
                        System.out.println("bad o1=" + o1);
                    }
                    return classMap.get(o1) - classMap.get(o2);
                }
            });
            Map<String, String> map = new HashMap<>();
            map.put(JAR, jar);
            map.put(HEADER, header);
            map.put("%PATH_SEPERATOR%", File.pathSeparator);
            String headerDefine = header
                    .substring(Math.max(0, header.indexOf(File.separator)))
                    .replace(".", "_");
            map.put(HEADER_DEFINE, headerDefine);
            map.put(NAMESPACE, namespace);
            String tabs = "";
            try (PrintWriter pw = new PrintWriter(new FileWriter(header))) {
                processTemplate(pw, map, HEADER_TEMPLATE_STARTH, tabs);
                Class lastClass = null;
                for (int class_index = 0; class_index < classes.size(); class_index++) {
                    Class clss = classes.get(class_index);
                    String clssName = clss.getCanonicalName();
                    String pkgs[] = clssName.split("\\.");
                    tabs = openClassNamespace(pkgs, pw, tabs);
                    String clssOnlyName = pkgs[pkgs.length - 1];
                    tabs += "\t";
                    pw.println(tabs + "class " + clssOnlyName + ";");
                    tabs = tabs.substring(0, tabs.length() - 1);
                    tabs = closeClassNamespace(pkgs, pw, tabs);
                    lastClass = clss;
                }
                for (Class clss : classes) {
                    String clssName = clss.getCanonicalName();
                    String pkgs[] = clssName.split("\\.");
                    tabs = openClassNamespace(pkgs, pw, tabs);
                    String clssOnlyName = pkgs[pkgs.length - 1];
                    map.put(CLASS_NAME, clssOnlyName);
                    map.put("%BASE_CLASS_FULL_NAME%", classToCppBase(clss));
                    tabs += "\t";
                    processTemplate(pw, map, HEADER_CLASS_STARTH, tabs);
                    tabs += "\t";
                    Constructor constructors[] = clss.getDeclaredConstructors();
                    if (constructors.length < 1) {
                        pw.println(tabs + clssOnlyName + "();");
                    } else {
                        for (Constructor c : constructors) {
                            if (Modifier.PUBLIC != (c.getModifiers() & Modifier.PUBLIC)) {
                                continue;
                            }
                            if (!checkParameters(c.getParameterTypes(), classes)) {
                                continue;
                            }
                            pw.println(tabs + clssOnlyName + getCppParamDeclarations(c.getParameterTypes(), clss) + ";");
                        }
                    }
                    pw.println(tabs + "virtual ~" + clssOnlyName + "();");
                    Method methods[] = clss.getDeclaredMethods();
                    for (int j = 0; j < methods.length; j++) {
                        Method method = methods[j];
                        if (!checkMethod(method, classes)) {
                            continue;
                        }
                        if ((method.getModifiers() & Modifier.PUBLIC) == Modifier.PUBLIC) {
                            pw.println(tabs + getCppDeclaration(method, clss));
                        }
                        if (isArrayStringMethod(method)) {
                            pw.println(tabs + getCppModifiers(method)
                                    + getCppType(method.getReturnType(), clss) + " "
                                    + method.getName()
                                    + "(int argc,const char **argv);");
                        }
                    }
                    tabs = tabs.substring(0, tabs.length() - 1);
                    pw.println(tabs + "}; // end class " + clssOnlyName);
                    tabs = tabs.substring(0, tabs.length() - 1);
                    tabs = closeClassNamespace(pkgs, pw, tabs);
                    pw.println();
                }
                processTemplate(pw, map, HEADER_TEMPLATE_ENDH, tabs);
            } catch (Exception ex) {
                Logger.getLogger(J4CppMain.class.getName()).log(Level.SEVERE, null, ex);
            }

            try (PrintWriter pw = new PrintWriter(new FileWriter(output))) {
                processTemplate(pw, map, CPP_TEMPLATE_STARTCPP, tabs);
                for (Class clss : classes) {
                    String clssName = clss.getCanonicalName();
                    String pkgs[] = clssName.split("\\.");
                    tabs = "\t";
                    tabs = openClassNamespace(pkgs, pw, tabs);
                    String clssOnlyName = pkgs[pkgs.length - 1];
                    map.put(CLASS_NAME, clssOnlyName);
                    map.put(FULL_CLASS_NAME, clssName);
                    map.put(FULL_CLASS_JNI_SIGNATURE, clssName.replace(".", "/"));
                    map.put(OBJECT_CLASS_FULL_NAME, getCppRelativeName(Object.class, clss));
                    processTemplate(pw, map, CPP_START_CLASSCPP, tabs);
                    Constructor constructors[] = clss.getDeclaredConstructors();
                    if (constructors.length < 1) {
                        pw.println(tabs + clssOnlyName + "::" + clssOnlyName + "() {");
                        map.put(JNI_SIGNATURE, "()V");
                        map.put(CONSTRUCTOR_ARGS, "");
                        processTemplate(pw, map, CPP_NEWCPP, tabs);
                        pw.println(tabs + "}");
                        pw.println();
                    } else {
                        for (Constructor c : constructors) {
                            if (Modifier.PUBLIC != (c.getModifiers() & Modifier.PUBLIC)) {
                                continue;
                            }
                            if (!checkParameters(c.getParameterTypes(), classes)) {
                                continue;
                            }
                            Class[] paramClasses = c.getParameterTypes();
                            pw.println(tabs + clssOnlyName + "::" + clssOnlyName + getCppParamDeclarations(paramClasses, clss) + " {");
                            tabs = tabs + "\t";
                            map.put(JNI_SIGNATURE, "(" + getJNIParamSignature(paramClasses) + ")V");
                            map.put(CONSTRUCTOR_ARGS, (paramClasses.length > 0 ? "," : "") + getCppParamNames(paramClasses));
                            processTemplate(pw, map, CPP_NEWCPP, tabs);
                            tabs = tabs.substring(0, tabs.length() - 1);
                            pw.println(tabs + "}");
                            pw.println();
                        }
                    }
                    pw.println();
                    pw.println(tabs + "// Destructor for " + clssName);
                    pw.println(tabs + clssOnlyName + "::~" + clssOnlyName + "() {");
                    pw.println(tabs + "\t// Place-holder for later extensibility.");
                    pw.println(tabs + "}");
                    pw.println();
                    Method methods[] = clss.getDeclaredMethods();
                    for (int j = 0; j < methods.length; j++) {
                        Method method = methods[j];
                        if (!checkMethod(method, classes)) {
                            continue;
                        }
                        int modifiers = method.getModifiers();
                        if (Modifier.isPublic(modifiers) && !Modifier.isAbstract(modifiers)) {
                            pw.println(getCppMethodDefinitionStart(tabs, clssOnlyName, method, clss));
                            map.put(METHOD_NAME, method.getName());
                            Class[] paramClasses = method.getParameterTypes();
                            map.put(METHOD_ARGS, (paramClasses.length > 0 ? "," : "") + getCppParamNames(paramClasses));
                            Class returnClass = method.getReturnType();
                            map.put(JNI_SIGNATURE, "(" + getJNIParamSignature(paramClasses) + ")" + classToJNISignature(returnClass));
                            map.put(METHOD_ONFAIL, getOnFailString(returnClass, clss));
                            map.put("%METHOD_RETURN%", isVoid(returnClass) ? "" : "return");
                            map.put("%METHOD_CALL_TYPE%", getMethodCallString(returnClass));
                            map.put("%METHOD_RETURN_TYPE%", getCppType(returnClass, clss));
                            map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclare(returnClass));
                            map.put("%METHOD_RETURN_STORE%", isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnVarType(returnClass) + ") ");
                            map.put("%METHOD_RETURN_GET%", getMethodReturnGet(tabs, returnClass, clss));
                            if (!Modifier.isStatic(modifiers)) {
                                processTemplate(pw, map, CPP_METHODCPP, tabs);
                            } else {
                                processTemplate(pw, map, CPP_STATIC_METHODCPP, tabs);
                            }
                            pw.println(tabs + "}");
                            if (isArrayStringMethod(method)) {
                                map.put(METHOD_RETURN_STORE, isVoid(returnClass) ? "" : getCppType(returnClass, clss) + " returnVal=");
                                map.put(METHOD_RETURN_GET, isVoid(returnClass) ? "return ;" : "return returnVal;");
                                processTemplate(pw, map, CPP_EASY_STRING_ARRAY_METHODCPP, tabs);
                            }
                        }
                    }
                    processTemplate(pw, map, CPP_END_CLASSCPP, tabs);

                    tabs = tabs.substring(0, tabs.length() - 1);
                    tabs = closeClassNamespace(pkgs, pw, tabs);
                }
//                pw.println();
//                pw.println("// end namespace " + namespace);
//                pw.println("}");
//                pw.println();
                processTemplate(pw, map, CPP_TEMPLATE_ENDCPP, tabs);
            } catch (Exception ex) {
                Logger.getLogger(J4CppMain.class.getName()).log(Level.SEVERE, null, ex);
            }
//        }
//        }

        } catch (MalformedURLException ex) {
            Logger.getLogger(J4CppMain.class.getName()).log(Level.SEVERE, null, ex);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(J4CppMain.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException | ClassNotFoundException ex) {
            Logger.getLogger(J4CppMain.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
    private static final String OBJECT_CLASS_FULL_NAME = "%OBJECT_CLASS_FULL_NAME%";

    private static String getMethodReturnGet(String tabs, Class returnClass, Class relClass) {
        if (!returnClass.isArray() && !returnClass.isPrimitive()
                && !String.class.isAssignableFrom(returnClass)) {
            tabs += "\t";
            return tabs + "\n"
                    + tabs + "jobjectRefType ref = env->GetObjectRefType(retVal);\n"
                    + tabs + "std::cout << \"ref=\" << ref << std::endl;\n"
                    + tabs + "std::cout << \"retVal=\" << retVal << std::endl;\n"
                    //                    + tabs + "if(ref != JNIGlobalRefType) {\n" 
                    //                    + tabs + "\tretVal = env->NewGlobalRef(retVal);\n"
                    //                    + tabs + "}\n"
                    //                    + tabs + "\n"
                    //                    + tabs + "ref = env->GetObjectRefType(retVal);\n"
                    //                    + tabs + "std::cout << \"ref=\" << ref << std::endl;\n"
                    //                    + tabs + "std::cout << \"retVal=\" << retVal << std::endl;\n"
                    + tabs + getCppRelativeName(returnClass, relClass) + " retObject(retVal,false);\n"
                    + tabs + "return retObject;";
        }
        return isVoid(returnClass) ? "" : "return retVal;";
    }

    private static String classToCppBase(Class clss) {
        Class superClass = clss.getSuperclass();
        if (superClass == null) {
            superClass = Object.class;
        }
        return getCppRelativeName(superClass, clss);
    }

    private static final String METHOD_RETURN_GET = "%METHOD_RETURN_GET%";
    private static final String METHOD_RETURN_STORE = "%METHOD_RETURN_STORE%";
    private static final String CPP_EASY_STRING_ARRAY_METHODCPP = "cpp_easy_string_array_method.cpp";
    private static final String HEADER_CLASS_STARTH = "header_class_start.h";
    private static final String CPP_STATIC_METHODCPP = "cpp_static_method.cpp";
    private static final String JAR = "%JAR%";
    private static final String FULL_CLASS_JNI_SIGNATURE = "%FULL_CLASS_JNI_SIGNATURE%";
    private static final String METHOD_ONFAIL = "%METHOD_ONFAIL%";
    private static final String METHOD_ARGS = "%METHOD_ARGS%";
    private static final String METHOD_NAME = "%METHOD_NAME%";
    private static final String CONSTRUCTOR_ARGS = "%CONSTRUCTOR_ARGS%";
    private static final String JNI_SIGNATURE = "%JNI_SIGNATURE%";
    private static final String FULL_CLASS_NAME = "%FULL_CLASS_NAME%";
    private static final String CLASS_NAME = "%CLASS_NAME%";
    private static final String NAMESPACE = "%NAMESPACE%";
    private static final String HEADER_DEFINE = "%HEADER_DEFINE%";
    private static final String HEADER = "%HEADER%";

    private static String closeClassNamespace(String[] pkgs, final PrintWriter pw, String tabs) {
        for (int i = 0; i < pkgs.length - 1; i++) {
            String pkg = pkgs[i];
            pw.println(tabs + "} // end namespace " + pkg);
            tabs = tabs.substring(0, tabs.length() - 1);
        }
        return tabs;
    }

    private static String openClassNamespace(String[] pkgs, final PrintWriter pw, String tabs) {
        for (int i = 0; i < pkgs.length - 1; i++) {
            String pkg = pkgs[i];
            tabs += "\t";
            pw.println(tabs + "namespace " + pkg + "{");
        }
        return tabs;
    }

    /**
     *
     * @param pw the value of pw
     * @param map the value of map
     * @param resourceName the value of resourceName
     * @param tabs the value of tabs
     * @throws IOException
     */
    private static void processTemplate(final PrintWriter pw, Map<String, String> map, String resourceName, String tabs) throws IOException {
        //                String arg = args[i];

        try (BufferedReader br
                = new BufferedReader(new InputStreamReader(ClassLoader.getSystemResourceAsStream(resourceName), StandardCharsets.UTF_8))) {
            br.lines()
                    .filter(s -> !s.trim().startsWith(TEMPLATE_COMMENT_MARK))
                    .forEach(l -> pw.println(tabs + replaceVars(map, l)));
        }
    }

    private static final String TEMPLATE_COMMENT_MARK = "//%%%";
    private static final String HEADER_TEMPLATE_STARTH = "header_template_start.h";
    private static final String HEADER_TEMPLATE_ENDH = "header_template_end.h";
    private static final String CPP_TEMPLATE_STARTCPP = "cpp_template_start.cpp";
    private static final String CPP_TEMPLATE_ENDCPP = "cpp_template_end.cpp";
    private static final String CPP_START_CLASSCPP = "cpp_start_class.cpp";
    private static final String CPP_END_CLASSCPP = "cpp_end_class.cpp";
    private static final String CPP_NEWCPP = "cpp_new.cpp";
    private static final String CPP_METHODCPP = "cpp_method.cpp";

    private static void printHelpAndExit(Options options) {
        new HelpFormatter().printHelp("Java4CPlusPlus", options);
        System.exit(1);
    }
}
