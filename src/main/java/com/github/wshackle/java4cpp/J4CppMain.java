/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wshackle.java4cpp;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Optional;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
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

    private static String getCppEasyCallArrayType(Class<?> clss) {
        if (boolean.class.isAssignableFrom(clss)) {
            return "jboolean *";
        } else if (byte.class.isAssignableFrom(clss)) {
            return "jbyte *";
        } else if (char.class.isAssignableFrom(clss)) {
            return "jchar *";
        } else if (short.class.isAssignableFrom(clss)) {
            return "jshort *";
        } else if (int.class.isAssignableFrom(clss)) {
            return "jint *";
        } else if (long.class.isAssignableFrom(clss)) {
            return "jlong *";
        } else if (float.class.isAssignableFrom(clss)) {
            return "jfloat *";
        } else if (double.class.isAssignableFrom(clss)) {
            return "jdouble *";
        } else {
            return "jobject *";
        }
//        ClassLoader.getSystemClassLoader();
    }

    public static String namespace = "JavaForCpp";

    private static String getModifiedClassName(Class cls) {
        Class enclosingClass = cls.getEnclosingClass();
        if (null != enclosingClass) {
            String en = enclosingClass.getCanonicalName();
            return en + cls.getCanonicalName().substring(en.length() + 1);
        }
        return cls.getCanonicalName();
    }

    private static String getCppRelativeName(Class<?> cls, Class<?> relClass) {
        String basepackages[] = getModifiedClassName(cls).split("\\.");
        String packages[] = relClass.getCanonicalName().split("\\.");
        int i = 0;
        int index = 0;
        boolean match = true;
        for (i = 0; i < basepackages.length - 1 && i < packages.length - 1; i++) {
            if (!packages[i].equals(basepackages[i])) {
                match = false;
                break;
            }
            index += packages[i].length() + 1;
        }
        if (match) {
            return getModifiedClassName(cls)
                    .substring(index).replace(".", "::");
        }

        return "::" + namespace + "::"
                + getModifiedClassName(cls)
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
        } else if (isString(clss)) {
            return "jstring";
        } else {
            return getCppRelativeName(clss, relClass);
        }
    }

    private static String getEasyCallCppType(Class<?> clss, Class<?> relClass) {
        if (clss.isArray()) {
            Class<?> componentType = clss.getComponentType();
            return getCppEasyCallArrayType(componentType);
        }
        if (clss.isPrimitive()) {
            return getCppPrimitiveType(clss);
        }
        if (Void.class.isAssignableFrom(clss)) {
            return "void";
        } else if (isString(clss)) {
            return "const char *";
        } else {
            return getCppRelativeName(clss, relClass);
        }
    }

    private static String getCppModifiers(int modifiers) {
        String out = "";
        if (Modifier.isStatic(modifiers)) {
            out += "static ";
        }
        return out;
    }

    private static String addConstRefIndicator(Class c, String orig) {
        if (!c.isPrimitive()
                && !isString(c)
                && !c.isArray()) {
            return "const " + orig + " &";
        }
        return orig;
    }

    private static String classToParamNameDecl(Class<?> c, int index) {
        if (c.isArray()) {
            return classToParamName(c.getComponentType()) + "Array_" + index;
        }
        return c.getSimpleName().substring(0, 1).toLowerCase() + c.getSimpleName().substring(1) + "_" + index;
    }

    private static String addCppJThis(Class c) {
        if (c.isPrimitive()
                || c.isArray()
                || isString(c)) {
            return "";
        } else {
            return ".jthis";
        }
    }

    private static String classToParamName(Class<?> c) {
        if (c.isArray()) {
            return classToParamName(c.getComponentType()) + "Array";
        }
        return c.getSimpleName().substring(0, 1).toLowerCase()
                + c.getSimpleName().substring(1);
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
            if (null != clss.getEnclosingClass()) {
                String s = classToJNISignature(clss.getEnclosingClass());
                String s1 = clss.getName();
                int dollarIndex = s1.indexOf('$');
                return s.substring(0, s.length() - 1) + s1.substring(dollarIndex) + ";";
            }
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
            String name = getParamName(clsse, i);
            sb.append(name);
            if (i < clsses.length - 1) {
                sb.append(",");
            }
        }
        return sb.toString();
    }

    private static String getCppParamNamesIn(Class<?>[] clsses) {
//        return Stream.of(clsses)
//                .map(J4CppMain::classToParamName)
//                .collect(Collectors.joining(","));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < clsses.length; i++) {
            Class<?> clsse = clsses[i];
            String name = getParamNameIn(clsse, i);
            sb.append(name);
            if (i < clsses.length - 1) {
                sb.append(",");
            }
        }
        return sb.toString();
    }

    private static String getParamName(Class<?> clsse, int i) {
        return classToParamName(clsse) + "_" + i + addCppJThis(clsse);
    }

    private static String getParamNameIn(Class<?> clsse, int i) {
        return classToParamName(clsse) + "_" + i;
    }

    private static String getCppParamDeclarations(Class<?>[] clsses, Class<?> relClass) {
        StringBuilder sb = new StringBuilder();
        sb.append("(");
        for (int i = 0; i < clsses.length; i++) {
            Class<?> clsse = clsses[i];
            String name = addConstRefIndicator(clsse, getCppType(clsse, relClass)) + " " + classToParamNameDecl(clsse, i);
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

    private static String getEasyCallCppParamDeclarations(Class<?>[] clsses, Class<?> relClass) {
        StringBuilder sb = new StringBuilder();
        sb.append("(");
        for (int i = 0; i < clsses.length; i++) {
            Class<?> clsse = clsses[i];
            String type = getEasyCallCppType(clsse, relClass);
            sb.append(type);
            sb.append(' ');
            String name = "easyArg_" + i;// classToParamNameDecl(clsse, i);
            sb.append(name);
            if (i < clsses.length - 1 || clsse.isArray()) {
                sb.append(',');
            }
            if (clsse.isArray()) {
                sb.append("jsize ");
                sb.append(name);
                sb.append("_length");
                if (i < clsses.length - 1) {
                    sb.append(',');
                }
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
                "not_eq", "or", "or_eq", "xor", "xor_eq",
                "delete", "namespace", "union", "cast"));
        return badNamesSet;
    }

    private static String fixMethodName(Method m) {
        String mname = m.getName();

        Method ma[] = m.getDeclaringClass().getMethods();
        int index = 0;
        boolean index_incremented = false;
        boolean has_match = false;
        for (int i = 0; i < ma.length; i++) {
            Method method = ma[i];
            if (method.getParameterCount() > 0
                    && m.getParameterCount() > 0
                    && m.getParameterTypes()[0].isPrimitive() != method.getParameterTypes()[0].isPrimitive()) {
                continue;
            }
            if (!method.equals(m)
                    && m.getName().equals(method.getName())
                    && m.getParameterCount() == method.getParameterCount()) {
                has_match = true;
            }
        }
        for (int i = 0; i < ma.length; i++) {
            Method method = ma[i];
            if (method.equals(m)) {
                break;
            }
            if (method.getParameterCount() != m.getParameterCount()) {
                continue;
            }
            if (method.getParameterCount() > 0
                    && m.getParameterCount() > 0
                    && m.getParameterTypes()[0].isPrimitive() != method.getParameterTypes()[0].isPrimitive()) {
                continue;
            }
            if (m.getParameterCount() >= 1) {
                if (String.class.isAssignableFrom(m.getParameterTypes()[0])
                        != String.class.isAssignableFrom(method.getParameterTypes()[0])) {
                    continue;
                }
            }
            if (method.getName().equals(m.getName())) {
                index++;
                index_incremented = true;
            }
        }
        int start_index = 0;
        while (index_incremented) {
            index_incremented = false;
            for (int i = 0; i < ma.length; i++) {
                Method method = ma[i];
                for (int j = start_index; j <= index; j++) {
                    if (method.getName().equals(m.getName() + j)
                            && m.getParameterCount() == method.getParameterCount()) {
                        index++;
                        index_incremented = true;
                    }
                }
            }
            start_index = index;
        }
        if (has_match) {
            mname = mname + index;
        }
        if (badNames.contains(mname)) {
            return mname + "Method";
        }
        return mname;
    }

    private static String getCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m.getModifiers())
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m)
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    private static String getNativeMethodCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m.getModifiers())
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m) + "Native"
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    private static String getCppFieldGetterDeclaration(Field f, Class<?> relClass) {
        return getCppModifiers(f.getModifiers())
                + getCppType(f.getType(), relClass) + " "
                + "get" + f.getName().substring(0, 1).toUpperCase() + f.getName().substring(1)
                + "();";
    }

    private static String getCppFieldSetterDeclaration(Field f, Class<?> relClass) {
        return getCppModifiers(f.getModifiers())
                + "void set" + f.getName().substring(0, 1).toUpperCase() + f.getName().substring(1)
                + "(" + addConstRefIndicator(f.getType(), getCppType(f.getType(), relClass))
                + " " + classToParamNameDecl(f.getType(), 0)
                + ");";
    }

    private static String getCppFieldGetterDefinitionStart(String tabs,
            String clssOnlyName,
            Field f,
            Class<?> relClass) {
        return tabs //+ getCppModifiers(m)
                + getCppType(f.getType(), relClass) + " "
                + clssOnlyName
                + "::"
                + "get" + f.getName().substring(0, 1).toUpperCase() + f.getName().substring(1)
                + "() {";
    }

    private static String getCppFieldSetterDefinitionStart(String tabs,
            String clssOnlyName,
            Field f,
            Class<?> relClass) {
        return tabs //+ getCppModifiers(m)
                + "void "
                + clssOnlyName
                + "::"
                + "set" + f.getName().substring(0, 1).toUpperCase() + f.getName().substring(1)
                + "(" + addConstRefIndicator(f.getType(), getCppType(f.getType(), relClass))
                + " " + classToParamNameDecl(f.getType(), 0)
                + ") {";
    }

    private static String getCppMethodDefinitionStart(String tabs,
            String clssOnlyName,
            Method m,
            Class<?> relClass) {
        return tabs //+ getCppModifiers(m)
                + getCppType(m.getReturnType(), relClass) + " "
                + clssOnlyName
                + "::"
                + fixMethodName(m)
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + " {";
    }

    private static String getEasyCallCppMethodDefinitionStart(String tabs,
            String clssOnlyName,
            Method m,
            Class<?> relClass) {
        return tabs //+ getCppModifiers(m)
                + getCppType(m.getReturnType(), relClass) + " "
                + clssOnlyName
                + "::"
                + fixMethodName(m)
                + getEasyCallCppParamDeclarations(m.getParameterTypes(), relClass)
                + " {";
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
            return "return;";
        } else if (Void.class.isAssignableFrom(returnClass)) {
            return "return;";
        } else if (isString(returnClass)) {
            return "return NULL;";
        } else if (returnClass.isArray()) {
            return "return NULL;";
        } else {
            return "static " + getCppRelativeName(returnClass, relClass) + " nullObject((jobject)NULL,false); return nullObject;";
        }
    }

    private static boolean isString(Class returnClass) {
        return String.class.isAssignableFrom(returnClass);
    }

    private static boolean isPrimitiveArray(Class clss) {
        return clss.isArray() && clss.getComponentType().isPrimitive();
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
        } else if (isString(returnClass)) {
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
        } else if (isString(returnClass)) {
            return "jstring";
        } else {
            return "jobject";
        }
    }

    public static String getMethodReturnOutVarType(Class returnClass, Class relClass) {
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
        } else if (isString(returnClass)) {
            return "jstring";
        } else {
            return getCppType(returnClass, relClass);
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
        } else if (isString(returnClass)) {
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
        } else if (isString(returnClass)) {
            return "jstring retVal=NULL;";
        } else {
            return "jobject retVal=NULL;";
        }
    }

    public static String getMethodReturnVarDeclareOut(Class returnClass, Class relClass) {
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
        } else if (isString(returnClass)) {
            return "jstring retVal=NULL;";
        } else {
            return getCppType(returnClass, relClass) + " retVal((jobject)NULL,false);";
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
//    $(VC_IncludePath)
//$(WindowsSDK_IncludePath)
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
                if (null == val) {
                    val = "";
                }
                str = str.replace(key, val);
            }
        } catch (Throwable t) {
            System.err.println("orig_str=" + orig_str);
            System.err.println("str=" + str);
            System.err.println("key=" + key);
            System.err.println("val=" + val);
            System.err.println("map=" + map);
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
        boolean ret = isString(clss)
                || clss.equals(Object.class)
                || clss.isPrimitive()
                || (clss.isArray()
                && null != componentClass
                && !componentClass.isArray()
                && checkClass(componentClass, classes))
                || classes.contains(clss);
        if (!ret) {
            if (verbose) {
                if (clss.isArray()) {
                    System.out.println("checkClass skipping " + clss + " component " + clss.getComponentType());
                } else {
                    System.out.println("checkClass skipping " + clss);
                }
            }
        }
        return ret;
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
        if (m.getDeclaringClass().getName().equals(m.getName())) {
            if (verbose) {
                System.out.println("checkMethod skipping " + m + " method same as classname.");
            }
            return false;
        }
        if (m.getDeclaringClass().getName().endsWith("." + m.getName())) {
            if (verbose) {
                System.out.println("checkMethod skipping " + m + " method same as classname.");
            }
            return false;
        }
        if (m.isSynthetic()) {
            if (verbose) {
                System.out.println("checkMethod skipping " + m + " isSynthetic.");
            }
            return false;
        }
        if (!Modifier.isPublic(m.getModifiers())) {
            if (verbose) {
                System.out.println("checkMethod skipping " + m + " not public");
            }
            return false;
        }
        if (!checkClass(m.getReturnType(), classes)) {
            if (verbose) {
                System.out.println("checkMethod skipping " + m + " return type not in classes list.");
            }
            return false;
        }
        boolean ret = checkParameters(m.getParameterTypes(), classes);
        if (!ret) {
            if (verbose) {
                System.out.println("checkMethod skipping " + m + " a parameter type is not in classes list");
            }
        }
        return ret;
    }

    public static boolean isAddableClass(Class<?> clss, Set<Class> excludedClasses) {
        if (clss.isArray()
                || clss.isSynthetic()
                || clss.isAnnotation()
                || clss.isPrimitive()) {
            return false;
        }
//        if(clss.getCanonicalName().contains("Dialog") || clss.getName().contains("ModalExlusionType")) {
//            if(verbose) System.out.println("clss = " + clss);
//        }
//        if (clss.getEnclosingClass() != null) {
//            return false;
//        }
        String canonicalName = null;
        try {
            canonicalName = clss.getCanonicalName();
        } catch (Throwable t) {
            // leaving canonicalName null is enough
        }
        if (null == canonicalName) {
            return false;
        }
        if (canonicalName.indexOf('$') >= 0) {
            return false;
        }
        String pkgNames[] = clss.getCanonicalName().split("\\.");
        for (int i = 0; i < pkgNames.length; i++) {
            String pkgName = pkgNames[i];
            if (badNames.contains(pkgName)) {
                return false;
            }
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

    private static boolean isMethodToMakeEasy(Method m) {

        return !Modifier.isStatic(m.getModifiers())
                && Arrays.stream(m.getParameterTypes())
                .anyMatch(t -> t.isArray() || isString(t))
                && Arrays.stream(m.getParameterTypes())
                .noneMatch(t -> t.isArray() && !t.getComponentType().isPrimitive());
    }

    private static boolean isConstructorToMakeEasy(Constructor c, Class relClss) {
        return Arrays.stream(c.getParameterTypes())
                .anyMatch(t -> t.isArray() || isString(t))
                && Arrays.stream(c.getParameterTypes())
                .noneMatch(t -> t.isArray() && !t.getComponentType().isPrimitive());
    }

    private static String getCppClassName(Class clss) {
        String clssName = clss.getCanonicalName();
        String pkgs[] = clssName.split("\\.");
        String clssOnlyName = pkgs[pkgs.length - 1];
        Class enclosingClass = clss.getEnclosingClass();
        if (enclosingClass != null) {
            String enclosingClassName = enclosingClass.getCanonicalName();
            String enclosingPkgs[] = enclosingClassName.split("\\.");
            String enclosingName = enclosingPkgs[enclosingPkgs.length - 1];
            clssOnlyName = enclosingName + clssOnlyName;
        }
        return clssOnlyName;
    }

    private static String getEasyCallCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m.getModifiers())
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m)
                + getEasyCallCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    public static boolean hasNoArgConstructor(Constructor[] constructors) {
        for (Constructor c : constructors) {
            if ((Modifier.isProtected(c.getModifiers()) || Modifier.isPublic(c.getModifiers()))
                    && c.getParameterCount() == 0) {
                return true;
            }
        }
        return false;
    }

    private static boolean addGetterMethod(Field f, Class clss, List<Class> classes) {
        if (!Modifier.isPublic(f.getModifiers())) {
            return false;
        }
        if (!f.getType().isPrimitive()
                && !String.class.equals(f.getType())
                && !classes.contains(f.getType())) {
            return false;
        }
        Method ma[] = clss.getMethods();
        for (int i = 0; i < ma.length; i++) {
            Method method = ma[i];
            if (method.getName().equalsIgnoreCase(f.getName())) {
                return false;
            }
            if (method.getName().equalsIgnoreCase("get" + f.getName())) {
                return false;
            }
            if (method.getName().equalsIgnoreCase("set" + f.getName())) {
                return false;
            }
        }
        return true;
    }

    private static boolean addSetterMethod(Field f, Class clss, List<Class> classes) {
        if (!Modifier.isPublic(f.getModifiers())) {
            return false;
        }
        if (!f.getType().isPrimitive()
                && !String.class.equals(f.getType())
                && !classes.contains(f.getType())) {
            return false;
        }
        if (Modifier.isFinal(f.getModifiers())) {
            return false;
        }
        Method ma[] = clss.getMethods();
        for (int i = 0; i < ma.length; i++) {
            Method method = ma[i];
            if (method.getName().equalsIgnoreCase(f.getName())) {
                return false;
            }
            if (method.getName().equalsIgnoreCase("get" + f.getName())) {
                return false;
            }
            if (method.getName().equalsIgnoreCase("set" + f.getName())) {
                return false;
            }
        }
        return true;
    }

    public static String getHomeDir() throws IOException {
        String userHomeProp = System.getProperty("user.home");
        if (verbose) {
            System.out.println("userDirProp = " + userHomeProp);
        }
        String homeDir = new File(userHomeProp).getCanonicalPath();
        if (verbose) {
            System.out.println("homeDir = " + homeDir);
        }
        return homeDir;
    }

    public static String getCurrentDir() throws IOException {
        String userDirProp = System.getProperty("user.dir");
        if (verbose) {
            System.out.println("userDirProp = " + userDirProp);
        }
        String currentDir = new File(userDirProp).getCanonicalPath();
        if (verbose) {
            System.out.println("currentDir = " + currentDir);
        }
        return currentDir.replace("\\", "\\\\");
    }

    public static boolean verbose = false;

    public static boolean main_completed = false;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        main_completed = false;

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
        options.addOption(Option.builder("c")
                .hasArgs()
                .desc("Single Java class to extract.")
                .longOpt("classes")
                .build());
        options.addOption(Option.builder("p")
                .hasArgs()
                .desc("Java Package prefix to extract")
                .longOpt("packages")
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
        options.addOption(Option.builder("l")
                .hasArg()
                .desc("Maximum limit on classes to extract from jars.[default=200]")
                .longOpt("limit")
                .build());
        options.addOption(Option.builder("v")
                .desc("enable verbose output")
                .longOpt("verbose")
                .build());
        options.addOption(Option.builder()
                .hasArg()
                .desc("Classes per output file.[default=10]")
                .longOpt(CLASSESPEROUTPUT)
                .build());
        options.addOption(Option.builder()
                .hasArgs()
                .desc("Comma seperated list of nativeclass=javaclass native where nativeclass will be generated as an extension/implementation of the java class.")
                .longOpt("natives")
                .build());
        options.addOption(Option.builder()
                .hasArg()
                .desc("library name for System.loadLibrary(...) for native extension classes")
                .longOpt("loadlibname")
                .build());
        String output = null;
        String header = null;
        String jar = null;
        Set<String> classnamesToFind = null;
        Set<String> packageprefixes = null;
        String loadlibname = null;

        Map<String, String> nativesNameMap = null;
        Map<String, Class> nativesClassMap = null;
        int limit = DEFAULT_LIMIT;
        int classes_per_file = 10;
        List<Class> classes = new ArrayList<>();

        String limitstring = Integer.toString(limit);

        try {
            // parse the command line arguments
            System.out.println("args = " + Arrays.toString(args));
            CommandLine line = new DefaultParser().parse(options, args);
            loadlibname = line.getOptionValue("loadlibname");
            verbose = line.hasOption("verbose");
            if (line.hasOption(CLASSESPEROUTPUT)) {
                String cpoStr = line.getOptionValue(CLASSESPEROUTPUT);
                try {
                    int cpoI = Integer.valueOf(cpoStr);
                    classes_per_file = cpoI;
                } catch (Exception e) {
                    System.err.println("Option for " + CLASSESPEROUTPUT + "=\"" + cpoStr + "\"");
                    printHelpAndExit(options, args);
                }
            }

            if (line.hasOption("natives")) {
                String natives[] = line.getOptionValues("natives");
                if (verbose) {
                    System.out.println("natives = " + Arrays.toString(natives));
                }
                nativesNameMap = new HashMap<>();
                nativesClassMap = new HashMap<>();
                for (int i = 0; i < natives.length; i++) {
                    int eq_index = natives[i].indexOf('=');
                    String nativeClassName = natives[i].substring(0, eq_index).trim();
                    String javaClassName = natives[i].substring(eq_index + 1).trim();
                    Class javaClass = null;
                    try {
                        javaClass = Class.forName(javaClassName);
                    } catch (ClassNotFoundException e) {
                        //e.printStackTrace();
                        System.err.println("Class for " + javaClassName + " not found. (It may be found later in jar if specified.)");
                    }
                    nativesNameMap.put(javaClassName, nativeClassName);
                    if (javaClass != null) {
                        nativesClassMap.put(nativeClassName, javaClass);
                        if (!classes.contains(javaClass)) {
                            classes.add(javaClass);
                        }
                    }
                }
            }
//            // validate that block-size has been set
//            if (line.hasOption("block-size")) {
//                // print the value of block-size
//                if(verbose) System.out.println(line.getOptionValue("block-size"));
//            }
            jar = line.getOptionValue("jar", jar);
            if (verbose) {
                System.out.println("jar = " + jar);
            }
            if (null != jar) {
                if (jar.startsWith("~/")) {
                    jar = new File(new File(getHomeDir()), jar.substring(2)).getCanonicalPath();
                }
                if (jar.startsWith("./")) {
                    jar = new File(new File(getCurrentDir()), jar.substring(2)).getCanonicalPath();
                }
                if (jar.startsWith("../")) {
                    jar = new File(new File(getCurrentDir()).getParentFile(), jar.substring(3)).getCanonicalPath();
                }
            }
            if (line.hasOption("classes")) {
                classnamesToFind = new HashSet<String>();
                String classStrings[] = line.getOptionValues("classes");
                if (verbose) {
                    System.out.println("classStrings = " + Arrays.toString(classStrings));
                }
                classnamesToFind.addAll(Arrays.asList(classStrings));
                if (verbose) {
                    System.out.println("classnamesToFind = " + classnamesToFind);
                }
            }
//                if (!line.hasOption("namespace")) {
//                    if (classname != null && classname.length() > 0) {
//                        namespace = classname.toLowerCase().replace(".", "_");
//                    } else if (jar != null && jar.length() > 0) {
//                        int lastSep = jar.lastIndexOf(File.separator);
//                        int start = Math.max(0, lastSep + 1);
//                        int period = jar.indexOf('.', start + 1);
//                        int end = Math.max(start + 1, period);
//                        namespace = jar.substring(start, end).toLowerCase();
//                        namespace = namespace.replace(" ", "_");
//                        if (namespace.indexOf("-") > 0) {
//                            namespace = namespace.substring(0, namespace.indexOf("-"));
//                        }
//                    }
//                }

            namespace = line.getOptionValue("namespace", namespace);
            if (verbose) {
                System.out.println("namespace = " + namespace);
            }
            if (null != namespace) {
                output = namespace + ".cpp";
            }
            output = line.getOptionValue("output", output);
            if (verbose) {
                System.out.println("output = " + output);
            }
            if (null != output) {
                if (output.startsWith("~/")) {
                    output = System.getProperty("user.home") + output.substring(1);
                }
                header = output.substring(0, output.lastIndexOf('.')) + ".h";
            } else {
                output = "out.cpp";
            }
            header = line.getOptionValue("header", header);
            if (verbose) {
                System.out.println("header = " + header);
            }
            if (null != header) {
                if (header.startsWith("~/")) {
                    header = System.getProperty("user.home") + header.substring(1);
                }
            } else {
                header = "out.h";
            }

            if (line.hasOption("packages")) {
                packageprefixes = new HashSet<String>();
                packageprefixes.addAll(Arrays.asList(line.getOptionValues("packages")));
            }
            if (line.hasOption("limit")) {
                limitstring = line.getOptionValue("limit", Integer.toString(DEFAULT_LIMIT));
                limit = Integer.valueOf(limitstring);
            }
            if (line.hasOption("help")) {
                printHelpAndExit(options, args);
            }
        } catch (ParseException exp) {
            if (verbose) {
                System.out.println("Unexpected exception:" + exp.getMessage());
            }
            printHelpAndExit(options, args);
        }

        Set<Class> excludedClasses = new HashSet<>();
        Set<String> foundClassNames = new HashSet<>();
        excludedClasses.add(Object.class);
        excludedClasses.add(String.class);
        excludedClasses.add(void.class);
        excludedClasses.add(Void.class);
        excludedClasses.add(Class.class);
        excludedClasses.add(Enum.class);
        Set<String> packagesSet = new TreeSet<>();
        List<URL> urlsList = new ArrayList<>();
        String cp = System.getProperty("java.class.path");
        if(verbose) {
            System.out.println("System.getProperty(\"java.class.path\") = " + cp);
        }
        if (null != cp) {
            for (String cpe : cp.split(File.pathSeparator)) {
                if(verbose) {
                    System.out.println("class path element = " + cpe);
                }
                File f = new File(cpe);
                if (f.isDirectory()) {
                    urlsList.add(new URL("file:" + f.getCanonicalPath()+File.separator));
                } else if (cpe.endsWith(".jar")) {
                    urlsList.add(new URL("jar:file:" + f.getCanonicalPath() + "!/"));
                }
            }
        }
        cp = System.getenv("CLASSPATH");
        if(verbose) {
            System.out.println("System.getenv(\"CLASSPATH\") = " + cp);
        }
        if (null != cp) {
            for (String cpe : cp.split(File.pathSeparator)) {
                if(verbose) {
                    System.out.println("class path element = " + cpe);
                }
                File f = new File(cpe);
                if (f.isDirectory()) {
                    urlsList.add(new URL("file:" + f.getCanonicalPath()+File.separator));
                } else if (cpe.endsWith(".jar")) {
                    urlsList.add(new URL("jar:file:" + f.getCanonicalPath() + "!/"));
                }
            }
        }
        if (verbose) {
            System.out.println("urlsList = " + urlsList);
        }
        if (null != jar && jar.length() > 0) {
            Path jarPath = FileSystems.getDefault().getPath(jar);
            ZipInputStream zip = new ZipInputStream(Files.newInputStream(jarPath, StandardOpenOption.READ));

            URL jarUrl = new URL("jar:file:" + jarPath.toFile().getCanonicalPath() + "!/");
            urlsList.add(jarUrl);
            URL[] urls = urlsList.toArray(new URL[urlsList.size()]);
            if (verbose) {
                System.out.println("urls = " + Arrays.toString(urls));
            }
            URLClassLoader cl = URLClassLoader.newInstance(urls);
            for (ZipEntry entry = zip.getNextEntry(); entry != null; entry = zip.getNextEntry()) {
                if (!entry.isDirectory() && entry.getName().endsWith(".class")) {
                    // This ZipEntry represents a class. Now, what class does it represent?
                    String entryName = entry.getName();
                    if (verbose) {
                        System.out.println("entryName = " + entryName);
                    }
                    if (entryName.indexOf('$') >= 0) {
                        continue;
                    }
                    String classFileName = entry.getName()
                            .replace('/', '.');
                    String className = classFileName
                            .substring(0, classFileName.length() - ".class".length());
                    if (classnamesToFind != null
                            && classnamesToFind.size() > 0
                            && !classnamesToFind.contains(className)) {
                        if (verbose) {
                            System.out.println("skipping className=" + className + " because it does not found in=" + classnamesToFind);
                        }
                        continue;
                    }
                    try {
                        Class clss = cl.loadClass(className);
                        if (null != nativesClassMap
                                && null != nativesNameMap
                                && nativesNameMap.containsKey(className)) {
                            nativesClassMap.put(nativesNameMap.get(className), clss);
                            if (!classes.contains(clss)) {
                                classes.add(clss);
                            }
                        }
                        if (packageprefixes != null
                                && packageprefixes.size() > 0) {
                            if (null == clss.getPackage()) {
                                continue;
                            }
                            final String pkgName = clss.getPackage().getName();
                            if (packageprefixes.stream().noneMatch(prefix -> pkgName.startsWith(prefix))) {
                                continue;
                            }
                        }
                        Package p = clss.getPackage();
                        if (null != p) {
                            packagesSet.add(clss.getPackage().getName());
                        }
                        if (!classes.contains(clss)
                                && isAddableClass(clss, excludedClasses)) {
                            if (null != classnamesToFind
                                    && classnamesToFind.contains(className)
                                    && !foundClassNames.contains(className)) {
                                foundClassNames.add(className);
                                if (verbose) {
                                    System.out.println("foundClassNames = " + foundClassNames);
                                }
                            }
//                        if(verbose) System.out.println("clss = " + clss);
                            classes.add(clss);
//                        Class superClass = clss.getSuperclass();
//                        while (null != superClass
//                                && !classes.contains(superClass)
//                                && isAddableClass(superClass, excludedClasses)) {
//                            classes.add(superClass);
//                            superClass = superClass.getSuperclass();
//                        }
                        }
                    } catch (ClassNotFoundException | NoClassDefFoundError ex) {
                        System.err.println("Caught " + ex.getClass().getName() + ":" + ex.getMessage() + " for className=" + className + ", entryName=" + entryName + ", jarPath=" + jarPath);
                    }
                }
            }
        }
        if (null != classnamesToFind) {
            if (verbose) {
                System.out.println("Checking classnames arguments");
            }
            for (String classname : classnamesToFind) {
                if (verbose) {
                    System.out.println("classname = " + classname);
                }
                if (foundClassNames.contains(classname)) {
                    if (verbose) {
                        System.out.println("foundClassNames.contains(" + classname + ")");
                    }
                    continue;
                }
                try {
                    if (classes.contains(Class.forName(classname))) {
                        if (verbose) {
                            System.out.println("Classes list already contains:  " + classname);
                        }
                        continue;
                    }
                } catch (Exception e) {

                }

                if (null != classname && classname.length() > 0) {
                    urlsList.add(new URL("file://" + System.getProperty("user.dir") + "/"));

                    URL[] urls = urlsList.toArray(new URL[urlsList.size()]);
                    if (verbose) {
                        System.out.println("urls = " + Arrays.toString(urls));
                    }
                    URLClassLoader cl = URLClassLoader.newInstance(urls);
                    Class c = null;
                    try {
                        c = cl.loadClass(classname);
                    } catch (ClassNotFoundException e) {
                        System.err.println("Class " + classname + " not found ");
                    }
                    if (verbose) {
                        System.out.println("c = " + c);
                    }
                    if (null == c) {
                        try {
                            c = ClassLoader.getSystemClassLoader().loadClass(classname);
                        } catch (ClassNotFoundException e) {
                            if (verbose) {
                                System.out.println("System ClassLoader failed to find " + classname);
                            }
                        }
                    }
                    if (null != c) {
                        classes.add(c);
                    } else {
                        System.err.println("Class " + classname + " not found");
                    }
                }
            }
            if (verbose) {
                System.out.println("Finished checking classnames arguments");
            }
        }
        if (classes == null || classes.size() < 1) {
            if (null == nativesClassMap || nativesClassMap.keySet().size() < 1) {
                System.err.println("No Classes specified or found.");
                System.exit(1);
            }
        }
        if (verbose) {
            System.out.println("Classes found = " + classes.size());
        }
        if (classes.size() > limit) {
            System.err.println("limit=" + limit);
            System.err.println("Too many classes please use -c or -p options to limit classes or -l to increase limit.");
            if (verbose) {
                System.out.println("packagesSet = " + packagesSet);
            }
            System.exit(1);
        }
        List<Class> newClasses = new ArrayList<Class>();
        for (Class clss : classes) {
            Class superClass = clss.getSuperclass();
            while (null != superClass
                    && !classes.contains(superClass)
                    && !newClasses.contains(superClass)
                    && isAddableClass(superClass, excludedClasses)) {
                newClasses.add(superClass);
                superClass = superClass.getSuperclass();
            }
            try {
                Field fa[] = clss.getDeclaredFields();
                for (Field f : fa) {
                    if (Modifier.isPublic(f.getModifiers())) {
                        Class fClass = f.getType();
                        if (!classes.contains(fClass)
                                && !newClasses.contains(fClass)
                                && isAddableClass(fClass, excludedClasses)) {
                            newClasses.add(fClass);
                        }
                    }
                }
            } catch (NoClassDefFoundError e) {
                e.printStackTrace();
            }
            for (Method m : clss.getDeclaredMethods()) {
                if (m.isSynthetic()) {
                    continue;
                }
                if (!Modifier.isPublic(m.getModifiers())
                        || Modifier.isAbstract(m.getModifiers())) {
                    continue;
                }
                Class retType = m.getReturnType();
                if (verbose) {
                    System.out.println("Checking dependancies for Method = " + m);
                }
                if (!classes.contains(retType)
                        && !newClasses.contains(retType)
                        && isAddableClass(retType, excludedClasses)) {
                    newClasses.add(retType);
                    superClass = retType.getSuperclass();
                    while (null != superClass
                            && !classes.contains(superClass)
                            && !newClasses.contains(superClass)
                            && isAddableClass(superClass, excludedClasses)) {
                        newClasses.add(superClass);
                        superClass = superClass.getSuperclass();
                    }
                }
                for (Class paramType : m.getParameterTypes()) {
                    if (!classes.contains(paramType)
                            && !newClasses.contains(paramType)
                            && isAddableClass(paramType, excludedClasses)) {
                        newClasses.add(paramType);
                        superClass = paramType.getSuperclass();
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
        }
        if (null != nativesClassMap) {
            for (Class clss : nativesClassMap.values()) {
                if (null != clss) {
                    Class superClass = clss.getSuperclass();
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
        if (verbose) {
            System.out.println("Dependency classes needed = " + newClasses.size());
        }
        classes.addAll(newClasses);
        List<Class> newOrderClasses = new ArrayList<>();
        for (Class clss : classes) {
            if (newOrderClasses.contains(clss)) {
                continue;
            }
            Class superClass = clss.getSuperclass();
            Stack<Class> stack = new Stack<>();
            while (null != superClass
                    && !newOrderClasses.contains(superClass)
                    && !superClass.equals(java.lang.Object.class)) {
                stack.push(superClass);
                superClass = superClass.getSuperclass();
            }
            while (!stack.empty()) {
                newOrderClasses.add(stack.pop());
            }
            newOrderClasses.add(clss);
        }
        classes = newOrderClasses;
        if (verbose) {
            System.out.println("Total number of classes = " + classes.size());
            System.out.println("classes = " + classes);
        }

        String forward_header = header.substring(0, header.lastIndexOf('.')) + "_fwd.h";
        Map<String, String> map = new HashMap<>();
        map.put(JAR, jar != null ? jar : "");
        map.put("%CLASSPATH_PREFIX%", getCurrentDir() + ((jar != null) ? (File.pathSeparator + jar) : ""));
        map.put("%FORWARD_HEADER%", forward_header);
        map.put("%HEADER%", header);
        map.put("%PATH_SEPERATOR%", File.pathSeparator);
        String tabs = "";
        String headerDefine = forward_header
                .substring(Math.max(0, forward_header.indexOf(File.separator)))
                .replace(".", "_");
        map.put(HEADER_DEFINE, headerDefine);
        map.put(NAMESPACE, namespace);
        if (null != nativesClassMap) {
            for (Entry<String, Class> e : nativesClassMap.entrySet()) {
                final Class javaClass = e.getValue();
                final String nativeClassName = e.getKey();
                try (PrintWriter pw = new PrintWriter(new FileWriter(nativeClassName + ".java"))) {
                    if (javaClass.isInterface()) {
                        pw.println("public class " + nativeClassName + " implements " + javaClass.getCanonicalName() + ", AutoCloseable{");
                    } else {
                        pw.println("public class " + nativeClassName + " extends " + javaClass.getCanonicalName() + " implements AutoCloseable{");
                    }
                    if (null != loadlibname && loadlibname.length() > 0) {
                        pw.println(TAB_STRING + "static {");
                        pw.println(TAB_STRING + TAB_STRING + "System.loadLibrary(\"" + loadlibname + "\");");
                        pw.println(TAB_STRING + "}");
                        pw.println();
                    }
                    pw.println(TAB_STRING + "public " + nativeClassName + "() {");
                    pw.println(TAB_STRING + "}");
                    pw.println();
                    pw.println(TAB_STRING + "private long nativeAddress=0;");
                    pw.println(TAB_STRING + "private boolean nativeDeleteOnClose=false;");
                    pw.println();

                    pw.println(TAB_STRING + "protected " + nativeClassName + "(final long nativeAddress) {");
                    pw.println(TAB_STRING + TAB_STRING + "this.nativeAddress = nativeAddress;");
                    pw.println(TAB_STRING + "}");

                    pw.println(TAB_STRING + "private native void nativeDelete();");
                    pw.println();
                    pw.println(TAB_STRING + "@Override");
                    pw.println(TAB_STRING + "public synchronized void  close() {");
//                        pw.println(TAB_STRING + TAB_STRING + "if(nativeAddress != 0 && nativeDeleteOnClose) {");
                    pw.println(TAB_STRING + TAB_STRING + "nativeDelete();");
//                        pw.println(TAB_STRING + TAB_STRING + "}");
//                        pw.println(TAB_STRING + TAB_STRING + "nativeAddress=0;");
//                        pw.println(TAB_STRING + TAB_STRING + "nativeDeleteOnClose=false;");
                    pw.println(TAB_STRING + "}");

                    pw.println();
                    pw.println(TAB_STRING + "protected void finalizer() {");
                    pw.println(TAB_STRING + TAB_STRING + "close();");
                    pw.println(TAB_STRING + "}");

                    pw.println();
                    Method ma[] = javaClass.getDeclaredMethods();
                    for (Method m : ma) {
                        int modifiers = m.getModifiers();
                        if (Modifier.isAbstract(modifiers)
                                && Modifier.isPublic(modifiers)
                                && !Modifier.isStatic(modifiers)
                                && !m.isDefault()
                                && !m.isSynthetic()) {
                            pw.println();
                            pw.println(TAB_STRING + "@Override");
                            pw.println(TAB_STRING + "native public " + m.getReturnType().getCanonicalName() + " " + m.getName() + "("
                                    + IntStream.range(0, m.getParameterCount())
                                    .mapToObj(i -> m.getParameterTypes()[i].getCanonicalName() + " param" + i)
                                    .collect(Collectors.joining(",")) + ");");
                        }
                    }
                    pw.println("}");
                }
            }
        }
        try (PrintWriter pw = new PrintWriter(new FileWriter(forward_header))) {
            tabs = "";
            processTemplate(pw, map, "header_fwd_template_start.h", tabs);
            Class lastClass = null;
            for (int class_index = 0; class_index < classes.size(); class_index++) {
                Class clss = classes.get(class_index);
                String clssOnlyName = getCppClassName(clss);
                tabs = openClassNamespace(clss, pw, tabs, lastClass);
                tabs += TAB_STRING;
                pw.println(tabs + "class " + clssOnlyName + ";");
                tabs = tabs.substring(0, tabs.length() - 1);
                Class nextClass = (class_index < (classes.size() - 1))
                        ? classes.get(class_index + 1) : null;
                tabs = closeClassNamespace(clss, pw, tabs, nextClass);
                lastClass = clss;
            }
            processTemplate(pw, map, "header_fwd_template_end.h", tabs);
        }
        headerDefine = header
                .substring(Math.max(0, header.indexOf(File.separator)))
                .replace(".", "_");
        map.put(HEADER_DEFINE, headerDefine);
        map.put(NAMESPACE, namespace);
        if (classes_per_file < 1) {
            classes_per_file = classes.size();
        }
        final int num_class_segments
                = (classes.size() > 1)
                        ? ((classes.size() + classes_per_file - 1) / classes_per_file)
                        : 1;
        String fmt = "%d";
        if (num_class_segments > 10) {
            fmt = "%02d";
        }
        if (num_class_segments > 100) {
            fmt = "%03d";
        }
        String header_file_base = header;
        if (header_file_base.endsWith(".h")) {
            header_file_base = header_file_base.substring(0, header_file_base.length() - 2);
        } else if (header_file_base.endsWith(".hh")) {
            header_file_base = header_file_base.substring(0, header_file_base.length() - 3);
        } else if (header_file_base.endsWith(".hpp")) {
            header_file_base = header_file_base.substring(0, header_file_base.length() - 4);
        }
        try (PrintWriter pw = new PrintWriter(new FileWriter(header))) {
            tabs = "";
            processTemplate(pw, map, HEADER_TEMPLATE_STARTH, tabs);
            for (int segment_index = 0; segment_index < num_class_segments; segment_index++) {
                String header_segment_file = header_file_base + String.format(fmt, segment_index) + ".h";
                pw.println("#include \"" + header_segment_file + "\"");
            }
            if (null != nativesClassMap) {
                tabs = TAB_STRING;
                for (Entry<String, Class> e : nativesClassMap.entrySet()) {
                    final Class javaClass = e.getValue();
                    final String nativeClassName = e.getKey();
                    pw.println();
                    pw.println(tabs + "class " + nativeClassName + "Context;");
                    pw.println();
                    map.put(CLASS_NAME, nativeClassName);
                    map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + getModifiedClassName(javaClass).replace(".", "::"));
                    map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                    processTemplate(pw, map, HEADER_CLASS_STARTH, tabs);
                    tabs += TAB_STRING;
                    pw.println(tabs + nativeClassName + "Context *context;");
                    pw.println(tabs + nativeClassName + "();");
                    pw.println(tabs + "~" + nativeClassName + "();");
                    Method methods[] = javaClass.getDeclaredMethods();
                    for (int j = 0; j < methods.length; j++) {
                        Method method = methods[j];
                        int modifiers = method.getModifiers();
                        if (!Modifier.isPublic(modifiers)) {
                            continue;
                        }
                        if (Modifier.isAbstract(modifiers)
                                && Modifier.isPublic(modifiers)
                                && !Modifier.isStatic(modifiers)
                                && !method.isDefault()
                                && !method.isSynthetic()) {
                            pw.println(tabs + getNativeMethodCppDeclaration(method, javaClass));
                        }
                    }
                    pw.println(tabs + "void initContext(" + nativeClassName + "Context *ctx,bool isref);");
                    pw.println(tabs + "void deleteContext();");
                    tabs = tabs.substring(TAB_STRING.length());
                    pw.println(tabs + "}; // end class " + nativeClassName);
                }
            }
            tabs = "";
            processTemplate(pw, map, HEADER_TEMPLATE_ENDH, tabs);
        }
        for (int segment_index = 0; segment_index < num_class_segments; segment_index++) {
            String header_segment_file = header_file_base + String.format(fmt, segment_index) + ".h";
            try (PrintWriter pw = new PrintWriter(new FileWriter(header_segment_file))) {
                tabs = "";
                //processTemplate(pw, map, HEADER_TEMPLATE_STARTH, tabs);
                pw.println("// Never include this file (" + header_segment_file + ") directly. include " + header + " instead.");
                pw.println();
                Class lastClass = null;
                final int start_segment_index = segment_index * classes_per_file;
                final int end_segment_index = Math.min(segment_index * classes_per_file + classes_per_file, classes.size());
                List<Class> classesSegList = classes.subList(start_segment_index,
                        end_segment_index);
                pw.println();
                pw.println(tabs + "// start_segment_index = " + start_segment_index);
                pw.println(tabs + "// start_segment_index = " + end_segment_index);
                pw.println(tabs + "// segment_index = " + segment_index);
                pw.println(tabs + "// classesSegList=" + classesSegList);
                pw.println();
                for (int class_index = 0; class_index < classesSegList.size(); class_index++) {
                    Class clss = classesSegList.get(class_index);
                    pw.println();
                    pw.println(tabs + "// class_index = " + class_index + " clss=" + clss);
                    pw.println();
                    String clssName = clss.getCanonicalName();
                    tabs = openClassNamespace(clss, pw, tabs, lastClass);
                    String clssOnlyName = getCppClassName(clss);
                    map.put(CLASS_NAME, clssOnlyName);
                    map.put("%BASE_CLASS_FULL_NAME%", classToCppBase(clss));
                    map.put(OBJECT_CLASS_FULL_NAME, getCppRelativeName(Object.class, clss));
                    tabs += TAB_STRING;
                    processTemplate(pw, map, HEADER_CLASS_STARTH, tabs);
                    tabs += TAB_STRING;

                    Constructor constructors[] = clss.getDeclaredConstructors();
                    if (!hasNoArgConstructor(constructors)) {
                        if (Modifier.isAbstract(clss.getModifiers())
                                || clss.isInterface()) {
                            pw.println(tabs + "private:");
                            pw.println(tabs + clssOnlyName + "() {};");
                            pw.println(tabs + "public:");
                        } else {
                            if (constructors.length > 0) {
                                pw.println(tabs + "protected:");
                            }
                            pw.println(tabs + clssOnlyName + "();");
                            if (constructors.length > 0) {
                                pw.println(tabs + "public:");
                            }
                        }
                    }
                    for (Constructor c : constructors) {
                        if (c.getParameterCount() == 0
                                && Modifier.isProtected(c.getModifiers())) {
                            pw.println(tabs + "protected:");
                            pw.println(tabs + clssOnlyName + "();");
                            pw.println(tabs + "public:");
                        }
                        if (checkConstructor(c, clss, classes)) {
                            continue;
                        }

                        if (c.getParameterCount() == 1
                                && clss.isAssignableFrom(c.getParameterTypes()[0])) {
                            continue;
                        }
                        if (!Modifier.isPublic(c.getModifiers())) {
                            continue;
                        }
                        if (c.getParameterTypes().length == 1) {
                            if (c.getParameterTypes()[0].getName().equals(clss.getName())) {
//                                    if(verbose) System.out.println("skipping constructor.");
                                continue;
                            }
                        }

                        if (!checkParameters(c.getParameterTypes(), classes)) {
                            continue;
                        }
                        pw.println(tabs + clssOnlyName + getCppParamDeclarations(c.getParameterTypes(), clss) + ";");
                        if (isConstructorToMakeEasy(c, clss)) {
                            pw.println(tabs + clssOnlyName + getEasyCallCppParamDeclarations(c.getParameterTypes(), clss) + ";");
                        }
                    }

                    pw.println(tabs + "~" + clssOnlyName + "();");
                    Field fa[] = clss.getDeclaredFields();
                    for (int findex = 0; findex < fa.length; findex++) {
                        Field field = fa[findex];
                        if (addGetterMethod(field, clss, classes)) {
                            pw.println(tabs + getCppFieldGetterDeclaration(field, clss));
                        }
                        if (addSetterMethod(field, clss, classes)) {
                            pw.println(tabs + getCppFieldSetterDeclaration(field, clss));
                        }
                    }
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
                            pw.println(tabs + getCppModifiers(method.getModifiers())
                                    + getCppType(method.getReturnType(), clss) + " "
                                    + fixMethodName(method)
                                    + "(int argc,const char **argv);");
                        }
                        if (isMethodToMakeEasy(method)) {
                            pw.println(tabs + getEasyCallCppDeclaration(method, clss));
                        }
                    }
                    tabs = tabs.substring(TAB_STRING.length());
                    pw.println(tabs + "}; // end class " + clssOnlyName);
                    tabs = tabs.substring(0, tabs.length() - 1);
                    Class nextClass = (class_index < (classesSegList.size() - 1))
                            ? classesSegList.get(class_index + 1) : null;
                    tabs = closeClassNamespace(clss, pw, tabs, nextClass);
                    pw.println();
                    lastClass = clss;
                }
                //processTemplate(pw, map, HEADER_TEMPLATE_ENDH, tabs);
            }
        }
        for (int segment_index = 0; segment_index < num_class_segments; segment_index++) {
            String output_segment_file = output;
            if (output_segment_file.endsWith(".cpp")) {
                output_segment_file = output_segment_file.substring(0, output_segment_file.length() - 4);
            } else if (output_segment_file.endsWith(".cc")) {
                output_segment_file = output_segment_file.substring(0, output_segment_file.length() - 3);
            }
            output_segment_file += "" + String.format(fmt, segment_index) + ".cpp";
            try (PrintWriter pw = new PrintWriter(new FileWriter(output_segment_file))) {
                tabs = "";
                if (segment_index < 1) {
                    processTemplate(pw, map, "cpp_template_start_first.cpp", tabs);
                } else {
                    processTemplate(pw, map, CPP_TEMPLATE_STARTCPP, tabs);
                }
                final int start_segment_index = segment_index * classes_per_file;
                final int end_segment_index = Math.min(segment_index * classes_per_file + classes_per_file, classes.size());
                List<Class> classesSegList = classes.subList(start_segment_index,
                        end_segment_index);
                pw.println();
                pw.println(tabs + "// start_segment_index = " + start_segment_index);
                pw.println(tabs + "// start_segment_index = " + end_segment_index);
                pw.println(tabs + "// segment_index = " + segment_index);
                pw.println(tabs + "// classesSegList=" + classesSegList);
                pw.println();
                Class lastClass = null;
                for (int class_index = 0; class_index < classesSegList.size(); class_index++) {
                    Class clss = classesSegList.get(class_index);
                    pw.println();
                    pw.println(tabs + "// class_index = " + class_index + " clss=" + clss);
                    pw.println();
                    String clssName = clss.getCanonicalName();
                    tabs = openClassNamespace(clss, pw, tabs, lastClass);
                    String clssOnlyName = getCppClassName(clss);
                    map.put(CLASS_NAME, clssOnlyName);
                    map.put("%BASE_CLASS_FULL_NAME%", classToCppBase(clss));

                    map.put(FULL_CLASS_NAME, clssName);
                    String fcjs = classToJNISignature(clss);
                    fcjs = fcjs.substring(1, fcjs.length() - 1);
                    map.put(FULL_CLASS_JNI_SIGNATURE, fcjs);
                    if (verbose) {
                        System.out.println("fcjs = " + fcjs);
                    }
                    map.put(OBJECT_CLASS_FULL_NAME, getCppRelativeName(Object.class, clss));
                    map.put("%INITIALIZE_CONTEXT%", "");
                    map.put("%INITIALIZE_CONTEXT_REF%", "");
                    processTemplate(pw, map, CPP_START_CLASSCPP, tabs);
                    Constructor constructors[] = clss.getDeclaredConstructors();

                    if (!hasNoArgConstructor(constructors)) {
                        if (!Modifier.isAbstract(clss.getModifiers())
                                && !clss.isInterface()) {
                            pw.println(tabs + clssOnlyName + "::" + clssOnlyName + "() : " + classToCppBase(clss) + "((jobject)NULL,false) {");
                            map.put(JNI_SIGNATURE, "()V");
                            map.put(CONSTRUCTOR_ARGS, "");
                            processTemplate(pw, map, CPP_NEWCPP, tabs);
                            pw.println(tabs + "}");
                            pw.println();
                        }

                    }
                    for (Constructor c : constructors) {
                        if (checkConstructor(c, clss, classes)) {
                            continue;
                        }
                        Class[] paramClasses = c.getParameterTypes();
                        pw.println(tabs + clssOnlyName + "::" + clssOnlyName + getCppParamDeclarations(paramClasses, clss) + " : " + classToCppBase(clss) + "((jobject)NULL,false) {");
                        tabs = tabs + TAB_STRING;
                        map.put(JNI_SIGNATURE, "(" + getJNIParamSignature(paramClasses) + ")V");
                        map.put(CONSTRUCTOR_ARGS, (paramClasses.length > 0 ? "," : "") + getCppParamNames(paramClasses));
                        processTemplate(pw, map, CPP_NEWCPP, tabs);
                        tabs = tabs.substring(0, tabs.length() - 1);
                        pw.println(tabs + "}");
                        pw.println();
                        if (isConstructorToMakeEasy(c, clss)) {
                            pw.println(tabs + clssOnlyName + "::" + clssOnlyName + getEasyCallCppParamDeclarations(c.getParameterTypes(), clss) + " : " + classToCppBase(clss) + "((jobject)NULL,false) {");
                            processTemplate(pw, map, "cpp_start_easy_constructor.cpp", tabs);
                            for (int paramIndex = 0; paramIndex < paramClasses.length; paramIndex++) {
                                Class paramClasse = paramClasses[paramIndex];
                                String parmName = getParamNameIn(paramClasse, paramIndex);
                                if (isString(paramClasse)) {
                                    pw.println(tabs + "jstring " + parmName + " = env->NewStringUTF(easyArg_" + paramIndex + ");");
                                } else if (isPrimitiveArray(paramClasse)) {
                                    String callString = getMethodCallString(paramClasse.getComponentType());
                                    pw.println(tabs + getCppArrayType(paramClasse.getComponentType()) + " " + classToParamNameDecl(paramClasse, paramIndex)
                                            + "= env->New" + callString + "Array(easyArg_" + paramIndex + "_length);");
                                    pw.println(tabs + "env->Set" + callString + "ArrayRegion(" + classToParamNameDecl(paramClasse, paramIndex) + ",0,easyArg_" + paramIndex + "_length,easyArg_" + paramIndex + ");");
                                } else {
                                    pw.println(tabs + getCppType(paramClasse, clss) + " " + classToParamNameDecl(paramClasse, paramIndex)
                                            + "= easyArg_" + paramIndex + ";");
                                }
                            }
                            processTemplate(pw, map, "cpp_new_easy_internals.cpp", tabs);
                            for (int paramIndex = 0; paramIndex < paramClasses.length; paramIndex++) {
                                Class paramClasse = paramClasses[paramIndex];
                                String parmName = getParamNameIn(paramClasse, paramIndex);
                                if (isString(paramClasse)) {
                                    pw.println(tabs + "jobjectRefType ref_" + paramIndex + " = env->GetObjectRefType(" + parmName + ");");
                                    pw.println(tabs + "if(ref_" + paramIndex + " == JNIGlobalRefType) {");
                                    pw.println(tabs + TAB_STRING + "env->DeleteGlobalRef(" + parmName + ");");
                                    pw.println(tabs + "}");
                                } else if (isPrimitiveArray(paramClasse)) {
                                    String callString = getMethodCallString(paramClasse.getComponentType());
                                    pw.println(tabs + "env->Get" + callString + "ArrayRegion(" + classToParamNameDecl(paramClasse, paramIndex) + ",0,easyArg_" + paramIndex + "_length,easyArg_" + paramIndex + ");");
                                    pw.println(tabs + "jobjectRefType ref_" + paramIndex + " = env->GetObjectRefType(" + parmName + ");");
                                    pw.println(tabs + "if(ref_" + paramIndex + " == JNIGlobalRefType) {");
                                    pw.println(tabs + TAB_STRING + "env->DeleteGlobalRef(" + parmName + ");");
                                    pw.println(tabs + "}");
                                } else {

                                }
                            }
                            processTemplate(pw, map, "cpp_end_easy_constructor.cpp", tabs);
                            pw.println(tabs + "}");
                        }
                    }

                    pw.println();
                    pw.println(tabs + "// Destructor for " + clssName);
                    pw.println(tabs + clssOnlyName + "::~" + clssOnlyName + "() {");
                    pw.println(tabs + "\t// Place-holder for later extensibility.");
                    pw.println(tabs + "}");
                    pw.println();
                    Field fa[] = clss.getDeclaredFields();
                    for (int findex = 0; findex < fa.length; findex++) {
                        Field field = fa[findex];
                        if (addGetterMethod(field, clss, classes)) {
                            pw.println();
                            pw.println(tabs + "// Field getter for " + field.getName());
                            pw.println(getCppFieldGetterDefinitionStart(tabs, clssOnlyName, field, clss));
                            map.put("%FIELD_NAME%", field.getName());
                            map.put(JNI_SIGNATURE, classToJNISignature(field.getType()));
                            Class returnClass = field.getType();
                            map.put(METHOD_ONFAIL, getOnFailString(returnClass, clss));
                            map.put(METHOD_ARGS, "");
                            map.put("%METHOD_RETURN%", isVoid(returnClass) ? "" : "return");
                            map.put("%METHOD_CALL_TYPE%", getMethodCallString(returnClass));
                            map.put("%METHOD_RETURN_TYPE%", getCppType(returnClass, clss));
                            map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclare(returnClass));
                            String retStore = isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnVarType(returnClass) + ") ";
                            map.put("%METHOD_RETURN_STORE%", retStore);
                            map.put("%METHOD_RETURN_GET%", getMethodReturnGet(tabs, returnClass, clss));

                            if (Modifier.isStatic(field.getModifiers())) {
                                processTemplate(pw, map, "cpp_static_getfield.cpp", tabs);
                            } else {
                                processTemplate(pw, map, "cpp_getfield.cpp", tabs);
                            }

                            pw.println(tabs + "}");
                        }
                        if (addSetterMethod(field, clss, classes)) {
                            pw.println();
                            pw.println(tabs + "// Field setter for " + field.getName());
                            pw.println(getCppFieldSetterDefinitionStart(tabs, clssOnlyName, field, clss));
                            map.put("%FIELD_NAME%", field.getName());
                            map.put(JNI_SIGNATURE, classToJNISignature(field.getType()));
                            Class returnClass = void.class;
                            map.put(METHOD_ONFAIL, getOnFailString(returnClass, clss));
                            Class[] paramClasses = new Class[]{field.getType()};
                            String methodArgs = getCppParamNames(paramClasses);
                            map.put(METHOD_ARGS, (paramClasses.length > 0 ? "," : "") + methodArgs);
                            map.put("%METHOD_RETURN%", isVoid(returnClass) ? "" : "return");
                            map.put("%METHOD_CALL_TYPE%", getMethodCallString(field.getType()));
                            map.put("%METHOD_RETURN_TYPE%", getCppType(returnClass, clss));
                            map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclare(returnClass));
                            String retStore = isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnVarType(returnClass) + ") ";
                            map.put("%METHOD_RETURN_STORE%", retStore);
                            map.put("%METHOD_RETURN_GET%", getMethodReturnGet(tabs, returnClass, clss));

                            if (Modifier.isStatic(field.getModifiers())) {
                                processTemplate(pw, map, "cpp_static_setfield.cpp", tabs);
                            } else {
                                processTemplate(pw, map, "cpp_setfield.cpp", tabs);
                            }

                            pw.println(tabs + "}");
                        }
                    }
                    Method methods[] = clss.getDeclaredMethods();
                    for (int j = 0; j < methods.length; j++) {
                        Method method = methods[j];

                        if (checkMethod(method, classes)) {
                            pw.println();
                            pw.println(getCppMethodDefinitionStart(tabs, clssOnlyName, method, clss));
                            map.put(METHOD_NAME, method.getName());
                            if (fixMethodName(method).contains("equals2")) {
                                if (verbose) {
                                    System.out.println("debug me");
                                }
                            }
                            map.put("%JAVA_METHOD_NAME%", method.getName());
                            Class[] paramClasses = method.getParameterTypes();
                            String methodArgs = getCppParamNames(paramClasses);
                            map.put(METHOD_ARGS, (paramClasses.length > 0 ? "," : "") + methodArgs);
                            Class returnClass = method.getReturnType();
                            map.put(JNI_SIGNATURE, "(" + getJNIParamSignature(paramClasses) + ")" + classToJNISignature(returnClass));
                            map.put(METHOD_ONFAIL, getOnFailString(returnClass, clss));
                            map.put("%METHOD_RETURN%", isVoid(returnClass) ? "" : "return");
                            map.put("%METHOD_CALL_TYPE%", getMethodCallString(returnClass));
                            map.put("%METHOD_RETURN_TYPE%", getCppType(returnClass, clss));
                            map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclare(returnClass));
                            String retStore = isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnVarType(returnClass) + ") ";
                            map.put("%METHOD_RETURN_STORE%", retStore);
                            map.put("%METHOD_RETURN_GET%", getMethodReturnGet(tabs, returnClass, clss));
                            tabs += TAB_STRING;
                            if (!Modifier.isStatic(method.getModifiers())) {
                                processTemplate(pw, map, CPP_METHODCPP, tabs);
                            } else {
                                processTemplate(pw, map, CPP_STATIC_METHODCPP, tabs);
                            }
                            tabs = tabs.substring(0, tabs.length() - TAB_STRING.length());
                            pw.println(tabs + "}");
                            if (isArrayStringMethod(method)) {
                                map.put(METHOD_RETURN_STORE, isVoid(returnClass) ? "" : getCppType(returnClass, clss) + " returnVal=");
                                map.put(METHOD_RETURN_GET, isVoid(returnClass) ? "return ;" : "return returnVal;");
                                processTemplate(pw, map, CPP_EASY_STRING_ARRAY_METHODCPP, tabs);
                            } else if (isMethodToMakeEasy(method)) {
                                pw.println();
                                pw.println(tabs + "// Easy call alternative for " + method.getName());
                                pw.println(getEasyCallCppMethodDefinitionStart(tabs, clssOnlyName, method, clss));
                                tabs += TAB_STRING;
                                map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclareOut(returnClass, clss));
                                processTemplate(pw, map, "cpp_start_easy_method.cpp", tabs);
                                for (int paramIndex = 0; paramIndex < paramClasses.length; paramIndex++) {
                                    Class paramClasse = paramClasses[paramIndex];
                                    String parmName = getParamNameIn(paramClasse, paramIndex);
                                    if (isString(paramClasse)) {
                                        pw.println(tabs + "jstring " + parmName + " = env->NewStringUTF(easyArg_" + paramIndex + ");");
                                    } else if (isPrimitiveArray(paramClasse)) {
                                        String callString = getMethodCallString(paramClasse.getComponentType());
                                        pw.println(tabs + getCppArrayType(paramClasse.getComponentType()) + " " + classToParamNameDecl(paramClasse, paramIndex)
                                                + "= env->New" + callString + "Array(easyArg_" + paramIndex + "_length);");
                                        pw.println(tabs + "env->Set" + callString + "ArrayRegion(" + classToParamNameDecl(paramClasse, paramIndex) + ",0,easyArg_" + paramIndex + "_length,easyArg_" + paramIndex + ");");
                                    } else {
                                        pw.println(tabs + getCppType(paramClasse, clss) + " " + classToParamNameDecl(paramClasse, paramIndex)
                                                + "= easyArg_" + paramIndex + ";");
                                    }
                                }
                                String methodArgsIn = getCppParamNamesIn(paramClasses);
                                String retStoreOut = isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnOutVarType(returnClass, clss) + ") ";

                                pw.println(tabs + retStoreOut + fixMethodName(method) + "(" + methodArgsIn + ");");
                                for (int paramIndex = 0; paramIndex < paramClasses.length; paramIndex++) {
                                    Class paramClasse = paramClasses[paramIndex];
                                    String parmName = getParamNameIn(paramClasse, paramIndex);
                                    if (isString(paramClasse)) {
                                        pw.println(tabs + "jobjectRefType ref_" + paramIndex + " = env->GetObjectRefType(" + parmName + ");");
                                        pw.println(tabs + "if(ref_" + paramIndex + " == JNIGlobalRefType) {");
                                        pw.println(tabs + TAB_STRING + "env->DeleteGlobalRef(" + parmName + ");");
                                        pw.println(tabs + "}");
                                    } else if (isPrimitiveArray(paramClasse)) {
                                        String callString = getMethodCallString(paramClasse.getComponentType());
                                        pw.println(tabs + "env->Get" + callString + "ArrayRegion(" + classToParamNameDecl(paramClasse, paramIndex) + ",0,easyArg_" + paramIndex + "_length,easyArg_" + paramIndex + ");");
                                        pw.println(tabs + "jobjectRefType ref_" + paramIndex + " = env->GetObjectRefType(" + parmName + ");");
                                        pw.println(tabs + "if(ref_" + paramIndex + " == JNIGlobalRefType) {");
                                        pw.println(tabs + TAB_STRING + "env->DeleteGlobalRef(" + parmName + ");");
                                        pw.println(tabs + "}");
                                    } else {

                                    }
                                }
                                processTemplate(pw, map, "cpp_end_easy_method.cpp", tabs);
                                if (!isVoid(returnClass)) {
                                    pw.println(tabs + "return retVal;");
                                }
                                tabs = tabs.substring(TAB_STRING.length());
                                pw.println(tabs + "}");
                                pw.println();
                            }
                        }
                    }
                    processTemplate(pw, map, CPP_END_CLASSCPP, tabs);
                    tabs = tabs.substring(0, tabs.length() - 1);
                    Class nextClass = (class_index < (classesSegList.size() - 1))
                            ? classesSegList.get(class_index + 1) : null;
                    tabs = closeClassNamespace(clss, pw, tabs, nextClass);
                    lastClass = clss;
                }

                if (segment_index < 1) {
                    if (null != nativesClassMap) {
                        for (Entry<String, Class> e : nativesClassMap.entrySet()) {
                            final Class javaClass = e.getValue();
                            final String nativeClassName = e.getKey();
                            map.put(CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_JNI_SIGNATURE, nativeClassName);
                            map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + getModifiedClassName(javaClass).replace(".", "::"));
                            map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                            map.put("%INITIALIZE_CONTEXT%", "context=NULL; initContext(NULL,false);");
                            map.put("%INITIALIZE_CONTEXT_REF%", "context=NULL; initContext(objref.context,true);");
                            tabs += TAB_STRING;

                            processTemplate(pw, map, CPP_START_CLASSCPP, tabs);
                            pw.println();
                            pw.println(tabs + nativeClassName + "::" + nativeClassName + "() : " + getModifiedClassName(javaClass).replace(".", "::") + "((jobject)NULL,false) {");
                            tabs += TAB_STRING;
                            pw.println(tabs + "context=NULL;");
                            pw.println(tabs + "initContext(NULL,false);");
                            map.put(JNI_SIGNATURE, "()V");
                            map.put(CONSTRUCTOR_ARGS, "");
                            processTemplate(pw, map, "cpp_new_native.cpp", tabs);
                            tabs = tabs.substring(TAB_STRING.length());
                            pw.println(tabs + "}");
                            pw.println();
                            pw.println(tabs + "// Destructor for " + nativeClassName);
                            pw.println(tabs + nativeClassName + "::~" + nativeClassName + "() {");
                            pw.println(tabs + TAB_STRING + "if(NULL != context) {");
                            pw.println(tabs + TAB_STRING + TAB_STRING + "deleteContext();");
                            pw.println(tabs + TAB_STRING + "}");
                            pw.println(tabs + TAB_STRING + "context=NULL;");
                            pw.println(tabs + "}");
                            pw.println();
//                            pw.println(tabs + "public:");
//                            pw.println(tabs + nativeClassName + "();");
//                            pw.println(tabs + "~" + nativeClassName + "();");
                            tabs = tabs.substring(TAB_STRING.length());
//                            Method methods[] = javaClass.getDeclaredMethods();
//                            for (int j = 0; j < methods.length; j++) {
//                                Method method = methods[j];
//                                int modifiers = method.getModifiers();
//                                if (!Modifier.isPublic(modifiers)) {
//                                    continue;
//                                }
//                                pw.println(tabs + getCppDeclaration(method, javaClass));
//                            }
//                            pw.println(tabs + "}; // end class " + nativeClassName);
                            processTemplate(pw, map, CPP_END_CLASSCPP, tabs);
                        }
                    }
                    processTemplate(pw, map, "cpp_template_end_first.cpp", tabs);
                    tabs = "";
                    if (null != nativesClassMap) {
                        pw.println("using namespace " + namespace + ";");
                        pw.println("#ifdef __cplusplus");
                        pw.println("extern \"C\" {");
                        pw.println("#endif");
                        int max_method_count = 0;
                        tabs = "";
                        for (Entry<String, Class> e : nativesClassMap.entrySet()) {
                            final Class javaClass = e.getValue();
                            final String nativeClassName = e.getKey();
                            map.put(CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_NAME, nativeClassName);
                            map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + getModifiedClassName(javaClass).replace(".", "::"));
                            map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                            map.put(FULL_CLASS_JNI_SIGNATURE, nativeClassName);
                            map.put(METHOD_ONFAIL, "return;");
                            Method methods[] = javaClass.getDeclaredMethods();
                            if (max_method_count < methods.length) {
                                max_method_count = methods.length;
                            }
                            for (int j = 0; j < methods.length; j++) {
                                Method method = methods[j];
                                int modifiers = method.getModifiers();
                                if (!Modifier.isPublic(modifiers)) {
                                    continue;
                                }
                                if (Modifier.isAbstract(modifiers)
                                        && Modifier.isPublic(modifiers)
                                        && !Modifier.isStatic(modifiers)
                                        && !method.isDefault()
                                        && !method.isSynthetic()) {
                                    Class[] paramClasses = method.getParameterTypes();
                                    String methodArgs = getCppParamNames(paramClasses);
                                    map.put(METHOD_ARGS, methodArgs);
                                    map.put(METHOD_NAME, method.getName());
                                    Class returnClass = method.getReturnType();
                                    String retStore = isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnVarType(returnClass) + ") ";
                                    map.put(METHOD_ONFAIL, getOnFailString(returnClass, javaClass));
                                    map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclare(returnClass));
                                    map.put("%METHOD_RETURN_STORE%", retStore);
                                    map.put("%METHOD_RETURN_GET%", getMethodReturnGet(tabs, returnClass, javaClass));
                                    pw.println();
                                    String paramDecls = getCppParamDeclarations(paramClasses, javaClass);
                                    String argsToAdd = method.getParameterCount() > 0 ? "," + paramDecls.substring(1, paramDecls.length() - 1) : "";
                                    pw.println("JNIEXPORT " + getCppType(returnClass, javaClass) + " JNICALL Java_" + nativeClassName + "_" + method.getName() + "(JNIEnv *env, jobject jthis" + argsToAdd + ") {");
                                    tabs = TAB_STRING;
                                    processTemplate(pw, map, "cpp_native_wrap.cpp", tabs);
                                    tabs = tabs.substring(TAB_STRING.length());
                                    pw.println("}");
                                    pw.println();
                                }
                            }
                            pw.println("JNIEXPORT void JNICALL Java_" + nativeClassName + "_nativeDelete(JNIEnv *env, jobject jthis) {");
                            tabs += TAB_STRING;
                            map.put(METHOD_ONFAIL, getOnFailString(void.class, javaClass));
                            processTemplate(pw, map, "cpp_native_delete.cpp", tabs);
                            tabs = tabs.substring(TAB_STRING.length());
                            pw.println(tabs + "}");
                            pw.println();
                        }
                        pw.println("#ifdef __cplusplus");
                        pw.println("} // end extern \"C\"");
                        pw.println("#endif");
                        map.put("%MAX_METHOD_COUNT%", Integer.toString(max_method_count + 1));
                        processTemplate(pw, map, "cpp_start_register_native.cpp", tabs);
                        for (Entry<String, Class> e : nativesClassMap.entrySet()) {
                            final Class javaClass = e.getValue();
                            final String nativeClassName = e.getKey();
                            map.put(CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_NAME, nativeClassName);
                            map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + getModifiedClassName(javaClass).replace(".", "::"));
                            map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                            processTemplate(pw, map, "cpp_start_register_native_class.cpp", tabs);
                            tabs += TAB_STRING;
                            Method methods[] = javaClass.getDeclaredMethods();
                            int method_number = 0;
                            for (int j = 0; j < methods.length; j++) {
                                Method method = methods[j];
                                int modifiers = method.getModifiers();
                                if (!Modifier.isPublic(modifiers)) {
                                    continue;
                                }
                                if (Modifier.isAbstract(modifiers)
                                        && Modifier.isPublic(modifiers)
                                        && !Modifier.isStatic(modifiers)
                                        && !method.isDefault()
                                        && !method.isSynthetic()) {
                                    map.put("%METHOD_NUMBER%", Integer.toString(method_number));
                                    map.put(METHOD_NAME, method.getName());

                                    map.put(JNI_SIGNATURE, "(" + getJNIParamSignature(method.getParameterTypes()) + ")" + classToJNISignature(method.getReturnType()));
                                    processTemplate(pw, map, "cpp_register_native_item.cpp", tabs);
                                    method_number++;
                                }
                            }
                            map.put("%METHOD_NUMBER%", Integer.toString(method_number));
                            map.put(METHOD_NAME, "nativeDelete");
                            map.put(JNI_SIGNATURE, "()V");
                            processTemplate(pw, map, "cpp_register_native_item.cpp", tabs);
                            map.put("%NUM_NATIVE_METHODS%", Integer.toString(method_number));
                            processTemplate(pw, map, "cpp_end_register_native_class.cpp", tabs);
                            tabs = tabs.substring(TAB_STRING.length());
                        }
                        processTemplate(pw, map, "cpp_end_register_native.cpp", tabs);
                    } else {
                        pw.println("// No Native classes : registerNativMethods not needed.");
                        pw.println("static void registerNativeMethods(JNIEnv *env) {}");
                    }

                } else {
                    processTemplate(pw, map, CPP_TEMPLATE_ENDCPP, tabs);
                }
            }
            if (null != nativesClassMap) {
                tabs = "";
                for (Entry<String, Class> e : nativesClassMap.entrySet()) {
                    String nativeClassName = e.getKey();
                    File nativeClassHeaderFile = new File(namespace.toLowerCase() + "_" + nativeClassName.toLowerCase() + ".h");
                    map.put("%NATIVE_CLASS_HEADER%", nativeClassHeaderFile.getName());
                    map.put(CLASS_NAME, nativeClassName);
                    if (nativeClassHeaderFile.exists()) {
                        if (verbose) {
                            System.out.println("skipping " + nativeClassHeaderFile.getCanonicalPath() + " since it already exists.");
                        }
                    } else {
                        try (PrintWriter pw = new PrintWriter(new FileWriter(nativeClassHeaderFile))) {
                            processTemplate(pw, map, "header_native_imp.h", tabs);
                        }
                    }
                    File nativeClassCppFile = new File(namespace.toLowerCase() + "_" + nativeClassName.toLowerCase() + ".cpp");
                    if (nativeClassCppFile.exists()) {
                        if (verbose) {
                            System.out.println("skipping " + nativeClassCppFile.getCanonicalPath() + " since it already exists.");
                        }
                    } else {
                        try (PrintWriter pw = new PrintWriter(new FileWriter(nativeClassCppFile))) {
                            processTemplate(pw, map, "cpp_native_imp_start.cpp", tabs);
                            Class javaClass = e.getValue();
                            Method methods[] = javaClass.getDeclaredMethods();
                            int method_number = 0;
                            for (int j = 0; j < methods.length; j++) {
                                Method method = methods[j];
                                int modifiers = method.getModifiers();
                                if (!Modifier.isPublic(modifiers)) {
                                    continue;
                                }
                                if (Modifier.isAbstract(modifiers)
                                        && Modifier.isPublic(modifiers)
                                        && !Modifier.isStatic(modifiers)
                                        && !method.isDefault()
                                        && !method.isSynthetic()) {
                                    Class[] paramClasses = method.getParameterTypes();
//                                    String methodArgs = getCppParamNames(paramClasses);
                                    String paramDecls = getCppParamDeclarations(paramClasses, javaClass);
                                    String methodArgs = method.getParameterCount() > 0 ? paramDecls.substring(1, paramDecls.length() - 1) : "";
                                    map.put(METHOD_ARGS, methodArgs);
                                    map.put(METHOD_NAME, method.getName());
                                    Class returnClass = method.getReturnType();
                                    String retStore = isVoid(returnClass) ? "" : "retVal= (" + getMethodReturnVarType(returnClass) + ") ";
                                    map.put(METHOD_ONFAIL, getOnFailString(returnClass, javaClass));
                                    map.put("%RETURN_TYPE%", getCppType(returnClass, javaClass));
                                    map.put("%RETURN_VAR_DECLARE%", getMethodReturnVarDeclare(returnClass));
                                    map.put("%METHOD_RETURN_STORE%", retStore);
                                    map.put("%METHOD_RETURN_GET%", getMethodReturnGet(tabs, returnClass, javaClass));
                                    processTemplate(pw, map, "cpp_native_imp_stub.cpp", tabs);
                                }
                            }
                            processTemplate(pw, map, "cpp_native_imp_end.cpp", tabs);
                        }
                    }
                }
            }
        }

        main_completed = true;
    }

    private static final String CLASSESPEROUTPUT = "classes-per-output";

    private static boolean checkConstructor(Constructor c, Class clss, List<Class> classes) {
        if (!Modifier.isPublic(c.getModifiers())) {
            if (c.getParameterCount() != 0 || !Modifier.isProtected(c.getModifiers())) {
                return true;
            }
        }
        Constructor ca[] = clss.getDeclaredConstructors();
        for (int i = 0; i < ca.length; i++) {
            Constructor constructor = ca[i];
            if (constructor.equals(c)) {
                break;
            }
            if (constructor.getParameterCount() == c.getParameterCount()) {
                if (c.getParameterCount() >= 1
                        && String.class.isAssignableFrom(c.getParameterTypes()[0])
                        != String.class.isAssignableFrom(constructor.getParameterTypes()[0])) {
                    continue;
                }
                return true;
            }
        }
        if (c.getParameterCount() == 1
                && clss.isAssignableFrom(c.getParameterTypes()[0])) {
            return true;
        }
        if (!checkParameters(c.getParameterTypes(), classes)) {
            return true;
        }
        return false;
    }
    private static final int DEFAULT_LIMIT = 200;
    private static final String TAB_STRING = "    "; // used to be "\t"
    private static final String OBJECT_CLASS_FULL_NAME = "%OBJECT_CLASS_FULL_NAME%";

    private static String getMethodReturnGet(String tabs, Class returnClass, Class relClass) {

        if (!returnClass.isArray() && !returnClass.isPrimitive()
                && !isString(returnClass)) {
            tabs += TAB_STRING;
            return tabs + "\n"
                    + tabs + "jobjectRefType ref = env->GetObjectRefType(retVal);\n"
                    + tabs + "if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,\"retVal=\",retVal);"
                    //+ tabs + "std::cout << \"ref=\" << ref << std::endl;\n"
                    //                    + tabs + "std::cout << \"retVal=\" << retVal << std::endl;\n"
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

    private static boolean pkgMatch(String pkgs1[], String pkgs2[], int level) {
        if (pkgs1.length < level + 1) {
            return false;
        }
        if (pkgs2.length < level + 1) {
            return false;
        }
        for (int i = 0; i <= level; i++) {
            String pkgFrom1 = pkgs1[i];
            String pkgFrom2 = pkgs2[i];
            if (!pkgFrom1.equals(pkgFrom2)) {
                return false;
            }
        }
        return true;
    }

    /**
     *
     * @param clss the value of clss
     * @param pw the value of pw
     * @param tabs the value of tabs
     * @param nextClass the value of nextClass
     */
    private static String closeClassNamespace(Class clss, final PrintWriter pw, String tabs, Class nextClass) {
        String pkgs[] = classToPackages(clss);
        String nextPkgs[] = classToPackages(nextClass);
        boolean line_printed = false;
        if (pkgs.length < 1) {
            return tabs;
        }
        for (int i = pkgs.length - 1; i >= 0; i--) {
            String pkg = pkgs[i];
            if (pkg.length() < 1) {
                break;
            }
            if (!pkgMatch(pkgs, nextPkgs, i)) {
                pw.println(tabs + "} // end namespace " + pkg);
                line_printed = true;
            }
            tabs = tabs.substring(0, tabs.length() - 1);
        }
        if (line_printed) {
            pw.println();
        }
        return tabs;
    }

    private static final String[] emptypkgs = {};

    private static String[] classToPackages(Class clss) {
        return Optional.ofNullable(clss)
                .map(Class::getPackage)
                .map(Package::getName)
                .map(s -> s.split("\\."))
                .orElse(emptypkgs);
    }

    /**
     *
     * @param clss the value of clss
     * @param pw the value of pw
     * @param tabs the value of tabs
     * @param lastClass the value of lastClass
     */
    private static String openClassNamespace(Class clss, final PrintWriter pw, String tabs, Class lastClass) {

        String pkgs[] = classToPackages(clss);
        String lastpkgs[] = classToPackages(lastClass);
        for (int i = 0; i < pkgs.length; i++) {
            String pkg = pkgs[i];
            if (pkgMatch(pkgs, lastpkgs, i)) {
                continue;
            }
            tabs += TAB_STRING;
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
                    .map(l -> l.replace("\t", TAB_STRING))
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

    private static void printHelpAndExit(Options options, String args[]) {
        System.out.println("args = " + Arrays.toString(args));
        new HelpFormatter().printHelp("java4cpp", options);
        System.exit(1);
    }
}
