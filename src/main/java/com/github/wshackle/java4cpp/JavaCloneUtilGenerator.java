/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wshackle.java4cpp;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class JavaCloneUtilGenerator {

    public void generateCloneUtil(String classname, File dir, List<Class> classes, Set<String> nocopyclassnamesSet) throws IOException {
        if (classname.endsWith(".class")) {
            classname = classname.substring(0, classname.length() - 6);
        } else if (classname.endsWith(".java")) {
            classname = classname.substring(0, classname.length() - 5);
        }
        int lastp = classname.lastIndexOf('.');
        String packagename;
        String classonlyname;
        if (lastp > 0) {
            packagename = classname.substring(0, lastp);
            classonlyname = classname.substring(lastp + 1);
        } else {
            packagename = "";
            classonlyname = classname;
        }
        if (null != dir) {
            dir = new File(System.getProperty("user.dir"));
        }
        String classsubstring = classname;
        int pindex = classsubstring.indexOf('.');
        while (pindex > 0 && pindex < classsubstring.length() - 1) {
            dir = new File(dir, classsubstring.substring(0, pindex));
            dir.mkdirs();
            classsubstring = classsubstring.substring(pindex + 1);
            pindex = classsubstring.indexOf('.');
        }
        File f = new File(dir, classonlyname + ".java");
        System.out.println("JavaCloneUtilGenerator writing to " + f.getCanonicalPath());
        Set<String> classnamesSet = new TreeSet<>();
        for (int i = 0; i < classes.size(); i++) {
            Class<?> clzzi = classes.get(i);
            if (clzzi.isSynthetic()) {
                continue;
            }
            classnamesSet.add(clzzi.getName());
        }
        try (PrintWriter pw = new PrintWriter(f)) {
            if (packagename != null && packagename.length() > 1) {
                pw.println("package " + packagename + ";");
                pw.println();
            }
            for (String name : classnamesSet) {
                if (name.startsWith("java.lang.")) {
                    continue;
                }
                name = name.replace('$', '.');
                pw.println("import " + name + ";");
            }
            pw.println("import java.util.Iterator;");
            pw.println("import org.checkerframework.checker.nullness.qual.Nullable;");
            pw.println();
            pw.println("public class " + classonlyname + " {");

            for (int i = 0; i < classes.size(); i++) {

                Class<?> clzzi = classes.get(i);
                pw.println("    // i = " + i + ",clzzi=" + clzzi);
                if (clzzi.isSynthetic()) {
                    continue;
                }
                if (clzzi.getName().startsWith("java.")) {
                    continue;
                }
                if (clzzi.isEnum()) {
                    continue;
                }
                if (clzzi.isInterface()) {
                    continue;
                }
                List<Class> assigableClasses = new ArrayList<>();
                for (int j = classes.size() - 1; j > 0; j--) {
                    Class<?> clzzj = classes.get(j);
                    if (!clzzi.isAssignableFrom(clzzj)) {
                        continue;
                    }
                    if (clzzj.isInterface() || Modifier.isAbstract(clzzj.getModifiers())) {
                        continue;
                    }
                    Constructor constructors[] = clzzj.getConstructors();
                    boolean publicNoArgConstructorFound = false;
                    for (int k = 0; k < constructors.length; k++) {
                        Constructor constructor = constructors[k];
                        if (constructor.getParameterCount() == 0 && Modifier.isPublic(constructor.getModifiers())) {
                            publicNoArgConstructorFound = true;
                            break;
                        }
                    }
                    if (publicNoArgConstructorFound) {
                        assigableClasses.add(clzzj);
                    }
                }
                if (assigableClasses.size() < 1) {
                    throw new RuntimeException("no assignable classes/constructors for " + clzzi);
                }
                pw.println();
                pw.println("    public static @Nullable");
                pw.println("    " + clzzi.getSimpleName() + " copy(@Nullable " + clzzi.getSimpleName() + " in) {");
                pw.println("        if(in != null) {");
                final String assignableZeroSimpleName = assigableClasses.get(0).getSimpleName();
                boolean createCopyTo = false;
                if (assigableClasses.size() == 1) {
                    if (assigableClasses.get(0) != clzzi) {
                        pw.println("            " + clzzi.getSimpleName() + " out = copy((" + assignableZeroSimpleName + ")in);");
                    } else {
                        pw.println("            " + clzzi.getSimpleName() + " out = new " + assignableZeroSimpleName + "();");
                        pw.println("            return copyTo(in,out);");
                        createCopyTo = true;
                    }
                } else {
                    pw.println("            " + clzzi.getSimpleName() + " out;");
                    pw.println("            if(in instanceof " + assignableZeroSimpleName + ") {");
                    if (assigableClasses.get(0) != clzzi) {
                        pw.println("                out = copy((" + assignableZeroSimpleName + ")in);");
                    } else {
                        pw.println("                out = new " + assignableZeroSimpleName + "();");
                        pw.println("                copyTo(in,out);");
                        createCopyTo = true;

                    }
                    for (int j = 1; j < assigableClasses.size(); j++) {
                        final String assignableJsimpleName = assigableClasses.get(j).getSimpleName();
                        pw.println("            } else if(in instanceof " + assignableJsimpleName + ") {");
                        if (assigableClasses.get(j) != clzzi) {
                            pw.println("                out = copy((" + assignableJsimpleName + ")in);");
                        } else {
                            pw.println("                out = new " + assignableJsimpleName + "();");
                            pw.println("                copyTo(in,out);");
                            createCopyTo = true;
                        }
                    }
                    pw.println("            } else {");
                    pw.println("                throw new RuntimeException(\"Unrecognized class for in=\"+in);");
                    pw.println("            }");
                    pw.println("            assert(out!=null):\"out==null\";");
                    pw.println("            return out;");
                }
                pw.println("        } else {");
                pw.println("            return null;");
                pw.println("        }");
                pw.println("    }");
                pw.println();
                if (createCopyTo) {
                    pw.println("    @SuppressWarnings({\"nullness\"})");
                    pw.println("    public static");
                    pw.println("    " + clzzi.getSimpleName() + " copyTo(" + clzzi.getSimpleName() + " in," + clzzi.getSimpleName() + " out) {");
                    pw.println("        assert(in.getClass()==" + clzzi.getSimpleName() + ".class): \"in.getClass()!=" + clzzi.getSimpleName() + ".class : in.getClass()=\"+in.getClass();");
                    pw.println("        assert(out.getClass()==" + clzzi.getSimpleName() + ".class): \"out.getClass()!=" + clzzi.getSimpleName() + ".class: out.getClass()=\"+out.getClass();");
                    Method methods[] = clzzi.getMethods();
                    for (int j = 0; j < methods.length; j++) {
                        Method methodJ = methods[j];
                        final Class<?> returnType = methodJ.getReturnType();
                        if (methodJ.getParameterCount() == 1
                                && methodJ.getName().startsWith("set")
                                && (returnType == void.class || returnType == Void.class)) {
                            Method getterMethod = null;
                            final Class<?> parameterType0 = methodJ.getParameterTypes()[0];
                            if (Boolean.class.isAssignableFrom(parameterType0)
                                    || boolean.class.isAssignableFrom(parameterType0)) {
                                try {
                                    final String getterName = "is" + methodJ.getName().substring(3);
                                    System.out.println("getterName = " + getterName);
                                    getterMethod = clzzi.getMethod(getterName);
                                } catch (NoSuchMethodException | SecurityException ex) {
                                    Logger.getLogger(JavaCloneUtilGenerator.class.getName()).log(Level.SEVERE, null, ex);
                                }
                            } else {
                                try {
                                    getterMethod = clzzi.getMethod("get" + methodJ.getName().substring(3));
                                } catch (NoSuchMethodException | SecurityException ex) {
                                    Logger.getLogger(JavaCloneUtilGenerator.class.getName()).log(Level.SEVERE, null, ex);
                                }
                            }
                            if (null != getterMethod) {
                                if (parameterType0.isPrimitive() || parameterType0.isEnum() || !classes.contains(parameterType0) || parameterType0.getName().startsWith("java.")
                                        || nocopyclassnamesSet.contains(parameterType0.getName())) {
                                    pw.println("        out." + methodJ.getName() + "(in." + getterMethod.getName() + "());");
                                } else {
                                    pw.println("        out." + methodJ.getName() + "(copy(in." + getterMethod.getName() + "()));");
                                }
                            }
                        } else if (methodJ.getParameterCount() == 0
                                && methodJ.getName().startsWith("get")
                                && Collection.class.isAssignableFrom(returnType)) {
                            String returnTypeName = methodJ.getGenericReturnType().getTypeName();
                            int ltIndex = returnTypeName.indexOf('<');
                            int gtIndex = returnTypeName.lastIndexOf('>');
                            if (ltIndex > 0 && gtIndex > ltIndex + 1 && gtIndex < returnTypeName.length()) {
                                returnTypeName = returnTypeName.replace('$', '.');
                                String componentTypeName = returnTypeName.substring(ltIndex + 1, gtIndex);
                                Class<?> componentClass = null;
                                for (int k = 0; k < classes.size(); k++) {
                                    Class<?> classK = classes.get(k);
                                    if (classK.getName().equals(componentTypeName)) {
                                        componentClass = classK;
                                    }
                                }
                                if (null == componentClass) {
                                    try {
                                        componentClass = Class.forName(componentTypeName);
                                        System.out.println("componentClass = " + componentClass);
                                    } catch (ClassNotFoundException ex) {
                                        Logger.getLogger(JavaCloneUtilGenerator.class.getName()).log(Level.SEVERE, null, ex);
                                    }
                                }
                                String outColName = "out" + methodJ.getName().substring(3);
                                pw.println("        " + returnTypeName + " " + outColName + " = out." + methodJ.getName() + "();");
                                pw.println("        assert(" + outColName + " !=null):\"" + outColName + "==null\";");
                                pw.println("        " + outColName + ".clear();");
                                String itname = "iterator" + methodJ.getName().substring(3);
                                pw.println("        Iterator<" + componentTypeName + "> " + itname + " = in." + methodJ.getName() + "().iterator();");
                                pw.println("        while(" + itname + ".hasNext()) {");
                                if(componentClass.isInterface() || nocopyclassnamesSet.contains(componentTypeName)) {
                                    pw.println("            " + outColName + ".add(" + itname + ".next());");
                                } else {
                                    pw.println("            " + outColName + ".add(copy(" + itname + ".next()));");
                                }
                                pw.println("        }");
                            }
                        }
                    }
                    pw.println("        return out;");
                    pw.println("    }");
                    pw.println();
                }

            }
            pw.println("}");
            pw.println();

        }
    }
}
