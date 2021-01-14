/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wshackle.java4cpp;

import static com.github.wshackle.java4cpp.J4CppMain.getCurrentDir;
import static com.github.wshackle.java4cpp.J4CppMain.verbose;
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
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class CppGenerator {

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

    private static String getModifiedClassName(Class cls) {
        Class enclosingClass = cls.getEnclosingClass();
        if (null != enclosingClass) {
            String en = enclosingClass.getCanonicalName();
            return en + cls.getCanonicalName().substring(en.length() + 1);
        }
        return cls.getCanonicalName();
    }

    private String getCppRelativeName(Class<?> cls, Class<?> relClass) {
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

    private String getCppType(Class<?> clss, Class<?> relClass) {
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

    private String getEasyCallCppType(Class<?> clss, Class<?> relClass) {
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
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < clsses.length; i++) {
            Class<?> clsse = clsses[i];
            String sig = classToJNISignature(clsse);
            sb.append(sig);
        }
        return sb.toString();
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

    private String getCppParamDeclarations(Class<?>[] clsses, Class<?> relClass) {
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

    private String getEasyCallCppParamDeclarations(Class<?>[] clsses, Class<?> relClass) {
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

   

    private static boolean fixMultipleOverrides = Boolean.getBoolean("fixMultipleOverrides");

    private static String fixMethodName(Method m) {
        String mname = m.getName();

        if (fixMultipleOverrides) {
            Method ma[] = m.getDeclaringClass().getMethods();
            int index = 0;
            boolean index_incremented = false;
            boolean has_match = false;
            Arrays.sort(ma, new Comparator<Method>() {
                @Override
                public int compare(Method o1, Method o2) {
                    return Arrays.toString(o1.getParameterTypes()).compareTo(Arrays.toString(o2.getParameterTypes()));
                }
            });
            List<Method> matchingMethods = new ArrayList<>();
            for (int i = 0; i < ma.length; i++) {
                Method method = ma[i];
                if (method.getParameterTypes().length > 0
                        && m.getParameterTypes().length > 0
                        && m.getParameterTypes()[0].isPrimitive() != method.getParameterTypes()[0].isPrimitive()) {
                    continue;
                }
                if (!method.equals(m)
                        && m.getName().equals(method.getName())
                        && m.getParameterTypes().length == method.getParameterTypes().length) {
                    has_match = true;
                    matchingMethods.add(method);
                }
            }
            for (int i = 0; i < ma.length; i++) {
                Method method = ma[i];
                if (method.equals(m)) {
                    break;
                }
                if (method.getParameterTypes().length != m.getParameterTypes().length) {
                    continue;
                }
                if (method.getParameterTypes().length > 0
                        && m.getParameterTypes().length > 0
                        && m.getParameterTypes()[0].isPrimitive() != method.getParameterTypes()[0].isPrimitive()) {
                    continue;
                }
                if (m.getParameterTypes().length >= 1) {
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
                                && m.getParameterTypes().length == method.getParameterTypes().length) {
                            index++;
                            index_incremented = true;
                        }
                    }
                }
                start_index = index;
            }
            if (has_match) {
                StringBuilder paramstringBuilder = new StringBuilder();
                Class[] paramclasses = m.getParameterTypes();
                for (int i = 0; i < paramclasses.length; i++) {
                    String append = classToMethodAppendage(paramclasses[i]);
                    paramstringBuilder.append(append);
                }
                mname = mname + paramstringBuilder.toString();
                if (mname.contains(";")) {
                    System.out.println("paramclasses = " + Arrays.toString(paramclasses));
                }
            }
        }

        if (J4CppMain.isBadName(mname)) {
            return mname + "Method";
        }
        return mname;
    }

    private static String classToMethodAppendage(Class clzz) {
        return clzz
                .getName()
                .replace("Ljava.lang", "")
                .replace("Ljava.io", "")
                .replace("Ljava.util", "")
                .replace("Ljava.net", "")
                .replace("Ljava.math", "")
                .replace("java.lang", "")
                .replace("java.io", "")
                .replace("java.util", "")
                .replace("java.net", "")
                .replace("java.math", "")
                .replaceAll("[.\\[\\]\\$_;]+", "");
    }

    private String getCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m.getModifiers())
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m)
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    private String getNativeMethodCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m.getModifiers())
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m) + "Native"
                + getCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    private String getCppFieldGetterDeclaration(Field f, Class<?> relClass) {
        return getCppModifiers(f.getModifiers())
                + getCppType(f.getType(), relClass) + " "
                + "get" + f.getName().substring(0, 1).toUpperCase() + f.getName().substring(1)
                + "();";
    }

    private String getCppFieldSetterDeclaration(Field f, Class<?> relClass) {
        return getCppModifiers(f.getModifiers())
                + "void set" + f.getName().substring(0, 1).toUpperCase() + f.getName().substring(1)
                + "(" + addConstRefIndicator(f.getType(), getCppType(f.getType(), relClass))
                + " " + classToParamNameDecl(f.getType(), 0)
                + ");";
    }

    private String getCppFieldGetterDefinitionStart(String tabs,
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

    private String getCppFieldSetterDefinitionStart(String tabs,
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

    private String getCppMethodDefinitionStart(String tabs,
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

    private String getEasyCallCppMethodDefinitionStart(String tabs,
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

    public String getOnFailString(Class returnClass, Class relClass) {
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

    public String getMethodReturnOutVarType(Class returnClass, Class relClass) {
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

    public  String getMethodReturnVarDeclareOut(Class returnClass, Class relClass) {
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

    

    private static boolean isMethodToMakeEasy(Method m) {
        if (Modifier.isStatic(m.getModifiers())) {
            return false;
        }
        Class<?> types[] = m.getParameterTypes();
        for (int i = 0; i < types.length; i++) {
            Class<?> type = types[i];
            if (type.isArray() && !type.getComponentType().isPrimitive()) {
                return false;
            }
        }
        for (int i = 0; i < types.length; i++) {
            Class<?> type = types[i];
            if (type.isArray() || isString(type)) {
                return true;
            }
        }
        return false;
//        return !Modifier.isStatic(m.getModifiers())
//                && Arrays.stream(m.getParameterTypes())
//                .anyMatch(t -> t.isArray() || isString(t))
//                && Arrays.stream(m.getParameterTypes())
//                .noneMatch(t -> t.isArray() && !t.getComponentType().isPrimitive());
    }

    private static boolean isConstructorToMakeEasy(Constructor c, Class relClss) {
        Class<?> types[] = c.getParameterTypes();
        for (int i = 0; i < types.length; i++) {
            Class<?> type = types[i];
            if (type.isArray() && !type.getComponentType().isPrimitive()) {
                return false;
            }
        }
        for (int i = 0; i < types.length; i++) {
            Class<?> type = types[i];
            if (type.isArray() || isString(type)) {
                return true;
            }
        }
        return false;
//        return Arrays.stream(c.getParameterTypes())
//                .anyMatch(t -> t.isArray() || isString(t))
//                && Arrays.stream(c.getParameterTypes())
//                .noneMatch(t -> t.isArray() && !t.getComponentType().isPrimitive());
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

    private  String getEasyCallCppDeclaration(Method m, Class<?> relClass) {
        return getCppModifiers(m.getModifiers())
                + getCppType(m.getReturnType(), relClass) + " "
                + fixMethodName(m)
                + getEasyCallCppParamDeclarations(m.getParameterTypes(), relClass)
                + ";";
    }

    public static boolean hasNoArgConstructor(Constructor[] constructors) {
        for (Constructor c : constructors) {
            if ((Modifier.isProtected(c.getModifiers()) || Modifier.isPublic(c.getModifiers()))
                    && c.getParameterTypes().length == 0) {
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
        return J4CppMain.getHomeDir();
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

            String s = null;
            while (null != (s = br.readLine())) {
                if (!s.trim().startsWith(TEMPLATE_COMMENT_MARK)) {
                    s = s.replace("\t", TAB_STRING);
                    pw.println(tabs + replaceVars(map, s));
                }
            }
//                    .filter(s -> !s.trim().startsWith(TEMPLATE_COMMENT_MARK))
//                    .map(l -> l.replace("\t", TAB_STRING))
//                    .forEach(l -> pw.println(tabs + replaceVars(map, l)));
        }
    }

    
    private static String incTabs(String tabs) {
        tabs += TAB_STRING;
        return tabs;
    }

    private static String decTabs(String tabs) {
        if (tabs.length() >= TAB_STRING.length()) {
            tabs = tabs.substring(0, tabs.length() - TAB_STRING.length());
        } else {
            System.err.println("tabs.length()=" + tabs.length());
        }
        return tabs;
    }


    private static boolean checkConstructor(Constructor c, Class clss, List<Class> classes) {
        if (!Modifier.isPublic(c.getModifiers())) {
            if (c.getParameterTypes().length != 0 || !Modifier.isProtected(c.getModifiers())) {
                return true;
            }
        }
        Constructor ca[] = clss.getDeclaredConstructors();
        for (int i = 0; i < ca.length; i++) {
            Constructor constructor = ca[i];
            if (constructor.equals(c)) {
                break;
            }
            if (constructor.getParameterTypes().length == c.getParameterTypes().length) {
                if (c.getParameterTypes().length >= 1
                        && String.class.isAssignableFrom(c.getParameterTypes()[0])
                        != String.class.isAssignableFrom(constructor.getParameterTypes()[0])) {
                    continue;
                }
                return true;
            }
        }
        if (c.getParameterTypes().length == 1
                && clss.isAssignableFrom(c.getParameterTypes()[0])) {
            return true;
        }
        if (!checkParameters(c.getParameterTypes(), classes)) {
            return true;
        }
        return false;
    }
   
    private String getMethodReturnGet(String tabs, Class returnClass, Class relClass) {

        if (!returnClass.isArray() && !returnClass.isPrimitive()
                && !isString(returnClass)) {
            tabs = incTabs(tabs);
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

    private String classToCppBase(Class clss) {
        Class superClass = clss.getSuperclass();
        if (superClass == null) {
            superClass = Object.class;
        }
        return getCppRelativeName(superClass, clss);
    }

    

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
    private static void closeClassNamespace(Class clss, final PrintWriter pw, String tabs, Class nextClass) {
        String origTabs = tabs;
        int origTabsLength = origTabs.length();
        String pkgs[] = classToPackages(clss);
        String nextPkgs[] = classToPackages(nextClass);
        boolean line_printed = false;
        if (pkgs.length < 1) {
            return;
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
            if (tabs.length() < TAB_STRING.length()) {
                System.out.println("origTabsLength = " + origTabsLength);
                System.out.println("origTabs = \"" + origTabs + "\"");
                System.out.println("clss = " + clss);
                System.out.println("pkgs = " + Arrays.toString(pkgs));
                System.out.println("nextClass = " + nextClass);
                System.out.println("nextPkgs = " + Arrays.toString(nextPkgs));
                System.err.println("bad tabs");
                Thread.dumpStack();
                pw.close();
                System.exit(1);
            } else {
                tabs = tabs.substring(0, tabs.length() - TAB_STRING.length());
            }
        }
        if (line_printed) {
            pw.println();
        }
    }

    private static final String[] emptypkgs = {};

    private static String[] classToPackages(Class clss) {
        if (null != clss
                && null != clss.getPackage()) {
            final String clssPackageName = clss.getPackage().getName();
            if (clssPackageName == null || clssPackageName.length() < 1) {
                return emptypkgs;
            }
            if (null != clssPackageName) {
                return clssPackageName.split("\\.");
            }
        }
        return emptypkgs;
//        return Optional.ofNullable(clss)
//                .map(Class::getPackage)
//                .map(Package::getName)
//                .map(s -> s.split("\\."))
//                .orElse(emptypkgs);
    }

    /**
     *
     * @param clss the value of clss
     * @param pw the value of pw
     * @param tabs the value of tabs
     * @param lastClass the value of lastClass
     */
    private static String openClassNamespace(Class clss, final PrintWriter pw, Class lastClass) {

        String tabs = "";
        String pkgs[] = classToPackages(clss);
        String lastpkgs[] = classToPackages(lastClass);
        for (int i = 0; i < pkgs.length; i++) {
            String pkg = pkgs[i];
            tabs = incTabs(tabs);
            if (pkgMatch(pkgs, lastpkgs, i)) {
                continue;
            }
            pw.println(tabs + "namespace " + pkg + "{");
        }
        return tabs;
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
    private static final String TAB_STRING = "    "; // used to be "\t"
    private static final String OBJECT_CLASS_FULL_NAME = "%OBJECT_CLASS_FULL_NAME%";
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

    private String namespace = "javaforcpp";

    public void setNamespace(String namespace) {
        this.namespace = namespace;
    }

    public String getCurrentDir() throws IOException {
        return J4CppMain.getCurrentDir();
    }
    
    public void generatAllCpp(String header, String jar, Map<String, Class> nativesClassMap, String loadlibname, List<Class> classesList, int classes_per_file, String output) throws IOException, SecurityException {
        String forward_header = header.substring(0, header.lastIndexOf('.')) + "_fwd.h";
        Map<String, String> map = new HashMap<>();
        map.put(JAR, jar != null ? jar : "");
        map.put("%CLASSPATH_PREFIX%", getCurrentDir() + ((jar != null) ? (File.pathSeparator + ((new File(jar).getCanonicalPath()).replace("\\", "\\\\"))) : ""));
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
            for (Map.Entry<String, Class> e : nativesClassMap.entrySet()) {
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
                                //                                && !m.isDefault()
                                && !m.isSynthetic()) {
                            pw.println();
                            pw.println(TAB_STRING + "@Override");
                            StringBuilder params = new StringBuilder();
                            for (int i = 0; i < m.getParameterTypes().length; i++) {
                                String append = m.getParameterTypes()[i].getCanonicalName() + " param" + i;
                                params.append(append);
                                if (i < m.getParameterTypes().length - 1) {
                                    params.append(",");
                                }
                            }
                            pw.println(TAB_STRING + "native public "
                                    + m.getReturnType().getCanonicalName()
                                    + " " + m.getName() + "("
                                    + params.toString() + ");");
//                                    + IntStream.range(0, m.getParameterTypes().length)
//                                    .mapToObj(i -> m.getParameterTypes()[i].getCanonicalName() + " param" + i)
//                                    .collect(Collectors.joining(",")) + ");");
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
            for (int class_index = 0; class_index < classesList.size(); class_index++) {
                Class clss = classesList.get(class_index);
                String clssOnlyName = getCppClassName(clss);
                tabs = openClassNamespace(clss, pw, lastClass);
                tabs = incTabs(tabs);
                pw.println(tabs + "class " + clssOnlyName + ";");
                tabs = decTabs(tabs);
                Class nextClass = (class_index < (classesList.size() - 1))
                        ? classesList.get(class_index + 1) : null;
                closeClassNamespace(clss, pw, tabs, nextClass);
                tabs = TAB_STRING;
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
            classes_per_file = classesList.size();
        }
        final int num_class_segments
                = (classesList.size() > 1)
                ? ((classesList.size() + classes_per_file - 1) / classes_per_file)
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
                pw.println();
                pw.println("namespace " + namespace + " {");
                pw.println();
                for (Map.Entry<String, Class> e : nativesClassMap.entrySet()) {
                    final Class javaClass = e.getValue();
                    final String nativeClassName = e.getKey();
                    pw.println();
                    pw.println(tabs + "class " + nativeClassName + "Context;");
                    pw.println();
                    map.put(CLASS_NAME, nativeClassName);
                    final String baseClassRelName = getModifiedClassName(javaClass).replace(".", "::");
                    map.put("%BASE_CLASS_REL_NAME%", baseClassRelName);
                    map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + baseClassRelName);
                    map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                    map.put("%OBJECT_CLASS_REL_NAME%", "java::lang::Object");
                    processTemplate(pw, map, HEADER_CLASS_STARTH, tabs);
                    tabs = incTabs(tabs);
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
                                //                                && !method.isDefault()
                                && !method.isSynthetic()) {
                            pw.println(tabs + getNativeMethodCppDeclaration(method, javaClass));
                        }
                    }
                    pw.println(tabs + "void initContext(" + nativeClassName + "Context *ctx,bool isref);");
                    pw.println(tabs + "void deleteContext();");
                    tabs = decTabs(tabs);
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
                final int end_segment_index = Math.min(segment_index * classes_per_file + classes_per_file, classesList.size());
                List<Class> classesSegList = classesList.subList(start_segment_index,
                        end_segment_index);
                pw.println();
                pw.println(tabs + "// start_segment_index = " + start_segment_index);
                pw.println(tabs + "// start_segment_index = " + end_segment_index);
                pw.println(tabs + "// segment_index = " + segment_index);
                pw.println(tabs + "// classesSegList=" + classesSegList);
                pw.println();
                pw.println(tabs + "namespace " + namespace + " {");
                pw.println();
                for (int class_index = 0; class_index < classesSegList.size(); class_index++) {
                    Class clss = classesSegList.get(class_index);
                    pw.println();
                    pw.println(tabs + "// class_index = " + class_index + " clss=" + clss);
                    pw.println();
                    String clssName = clss.getCanonicalName();
                    tabs = openClassNamespace(clss, pw, lastClass);
                    String clssOnlyName = getCppClassName(clss);
                    map.put(CLASS_NAME, clssOnlyName);
                    map.put("%BASE_CLASS_FULL_NAME%", classToCppBase(clss));
                    map.put(OBJECT_CLASS_FULL_NAME, getCppRelativeName(Object.class, clss));
                    tabs = incTabs(tabs);
                    processTemplate(pw, map, HEADER_CLASS_STARTH, tabs);
                    tabs = incTabs(tabs);

                    Constructor constructors[] = clss.getDeclaredConstructors();
                    if (!hasNoArgConstructor(constructors)) {
                        if (Modifier.isAbstract(clss.getModifiers())
                                || clss.isInterface()) {
                            pw.println(tabs + "protected:");
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
                        if (c.getParameterTypes().length == 0
                                && Modifier.isProtected(c.getModifiers())) {
                            pw.println(tabs + "protected:");
                            pw.println(tabs + clssOnlyName + "();");
                            pw.println(tabs + "public:");
                        }
                        if (checkConstructor(c, clss, classesList)) {
                            continue;
                        }

                        if (c.getParameterTypes().length == 1
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

                        if (!checkParameters(c.getParameterTypes(), classesList)) {
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
                        if (addGetterMethod(field, clss, classesList)) {
                            pw.println(tabs + getCppFieldGetterDeclaration(field, clss));
                        }
                        if (addSetterMethod(field, clss, classesList)) {
                            pw.println(tabs + getCppFieldSetterDeclaration(field, clss));
                        }
                    }
                    Method methods[] = clss.getDeclaredMethods();
                    for (int j = 0; j < methods.length; j++) {
                        Method method = methods[j];
                        if (!checkMethod(method, classesList)) {
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
                    tabs = decTabs(tabs);
                    pw.println(tabs + "}; // end class " + clssOnlyName);
                    tabs = decTabs(tabs);
                    Class nextClass = (class_index < (classesSegList.size() - 1))
                            ? classesSegList.get(class_index + 1) : null;
                    closeClassNamespace(clss, pw, tabs, nextClass);
                    tabs = TAB_STRING;
                    pw.println();
                    lastClass = clss;
                }
                pw.println();
                pw.println("}; // end namespace " + namespace);
                pw.println();
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
                final int end_segment_index = Math.min(segment_index * classes_per_file + classes_per_file, classesList.size());
                List<Class> classesSegList = classesList.subList(start_segment_index,
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
                    tabs = openClassNamespace(clss, pw, lastClass);
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
                        if (checkConstructor(c, clss, classesList)) {
                            continue;
                        }
                        Class[] paramClasses = c.getParameterTypes();
                        pw.println(tabs + clssOnlyName + "::" + clssOnlyName + getCppParamDeclarations(paramClasses, clss) + " : " + classToCppBase(clss) + "((jobject)NULL,false) {");
                        tabs = tabs + TAB_STRING;
                        map.put(JNI_SIGNATURE, "(" + getJNIParamSignature(paramClasses) + ")V");
                        map.put(CONSTRUCTOR_ARGS, (paramClasses.length > 0 ? "," : "") + getCppParamNames(paramClasses));
                        processTemplate(pw, map, CPP_NEWCPP, tabs);
                        if (tabs.length() >= TAB_STRING.length()) {
                            tabs = tabs.substring(0, tabs.length() - TAB_STRING.length());
                        }
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
                        if (addGetterMethod(field, clss, classesList)) {
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
                        if (addSetterMethod(field, clss, classesList)) {
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

                        if (checkMethod(method, classesList)) {
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
                            tabs = incTabs(tabs);
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
                                tabs = incTabs(tabs);
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
                                tabs = decTabs(tabs);
                                pw.println(tabs + "}");
                                pw.println();
                            }
                        }
                    }
                    processTemplate(pw, map, CPP_END_CLASSCPP, tabs);
//                    tabs = decTabs(tabs);
                    Class nextClass = (class_index < (classesSegList.size() - 1))
                            ? classesSegList.get(class_index + 1) : null;
                    closeClassNamespace(clss, pw, tabs, nextClass);
                    tabs = TAB_STRING;
                    lastClass = clss;
                }

                if (segment_index < 1) {
                    if (null != nativesClassMap) {
                        for (Map.Entry<String, Class> e : nativesClassMap.entrySet()) {
                            final Class javaClass = e.getValue();
                            final String nativeClassName = e.getKey();
                            map.put(CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_JNI_SIGNATURE, nativeClassName);
                            map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + getModifiedClassName(javaClass).replace(".", "::"));
                            map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                            map.put("%INITIALIZE_CONTEXT%", "context=NULL; initContext(NULL,false);");
                            map.put("%INITIALIZE_CONTEXT_REF%", "context=NULL; initContext(objref.context,true);");
                            tabs = incTabs(tabs);

                            processTemplate(pw, map, CPP_START_CLASSCPP, tabs);
                            pw.println();
                            pw.println(tabs + nativeClassName + "::" + nativeClassName + "() : " + getModifiedClassName(javaClass).replace(".", "::") + "((jobject)NULL,false) {");
                            tabs = incTabs(tabs);
                            pw.println(tabs + "context=NULL;");
                            pw.println(tabs + "initContext(NULL,false);");
                            map.put(JNI_SIGNATURE, "()V");
                            map.put(CONSTRUCTOR_ARGS, "");
                            processTemplate(pw, map, "cpp_new_native.cpp", tabs);
                            tabs = decTabs(tabs);
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
                            tabs = decTabs(tabs);
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
                        for (Map.Entry<String, Class> e : nativesClassMap.entrySet()) {
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
                                        //                                        && !method.isDefault()
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
                                    String argsToAdd = method.getParameterTypes().length > 0 ? "," + paramDecls.substring(1, paramDecls.length() - 1) : "";
                                    pw.println("JNIEXPORT " + getCppType(returnClass, javaClass) + " JNICALL Java_" + nativeClassName + "_" + method.getName() + "(JNIEnv *env, jobject jthis" + argsToAdd + ") {");
                                    tabs = TAB_STRING;
                                    processTemplate(pw, map, "cpp_native_wrap.cpp", tabs);
                                    tabs = decTabs(tabs);
                                    pw.println("}");
                                    pw.println();
                                }
                            }
                            pw.println("JNIEXPORT void JNICALL Java_" + nativeClassName + "_nativeDelete(JNIEnv *env, jobject jthis) {");
                            tabs = incTabs(tabs);
                            map.put(METHOD_ONFAIL, getOnFailString(void.class, javaClass));
                            processTemplate(pw, map, "cpp_native_delete.cpp", tabs);
                            tabs = decTabs(tabs);
                            pw.println(tabs + "}");
                            pw.println();
                        }
                        pw.println("#ifdef __cplusplus");
                        pw.println("} // end extern \"C\"");
                        pw.println("#endif");
                        map.put("%MAX_METHOD_COUNT%", Integer.toString(max_method_count + 1));
                        processTemplate(pw, map, "cpp_start_register_native.cpp", tabs);
                        for (Map.Entry<String, Class> e : nativesClassMap.entrySet()) {
                            final Class javaClass = e.getValue();
                            final String nativeClassName = e.getKey();
                            map.put(CLASS_NAME, nativeClassName);
                            map.put(FULL_CLASS_NAME, nativeClassName);
                            map.put("%BASE_CLASS_FULL_NAME%", "::" + namespace + "::" + getModifiedClassName(javaClass).replace(".", "::"));
                            map.put(OBJECT_CLASS_FULL_NAME, "::" + namespace + "::java::lang::Object");
                            processTemplate(pw, map, "cpp_start_register_native_class.cpp", tabs);
                            tabs = incTabs(tabs);
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
                                        //                                        && !method.isDefault()
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
                            tabs = decTabs(tabs);
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
                for (Map.Entry<String, Class> e : nativesClassMap.entrySet()) {
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
                    File nativeClassCppFile = new File("stub_" + namespace.toLowerCase() + "_" + nativeClassName.toLowerCase() + ".cpp");
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
                                        //                                        && !method.isDefault()
                                        && !method.isSynthetic()) {
                                    Class[] paramClasses = method.getParameterTypes();
//                                    String methodArgs = getCppParamNames(paramClasses);
                                    String paramDecls = getCppParamDeclarations(paramClasses, javaClass);
                                    String methodArgs = method.getParameterTypes().length > 0 ? paramDecls.substring(1, paramDecls.length() - 1) : "";
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
    }
}