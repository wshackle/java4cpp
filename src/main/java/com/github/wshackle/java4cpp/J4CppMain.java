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
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;
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

    public static boolean verbose = false;

    public static boolean main_completed = false;
    private static final int DEFAULT_LIMIT = 200;

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

    private static Set<String> badNames = getBadNames();

    private static Set<String> getBadNames() {
        Set<String> badNamesSet = new HashSet<>();
        badNamesSet.addAll(Arrays.asList("and", "and_eq", "bitand",
                "bitor", "compl", "not", "not_eq", "or",
                "not_eq", "or", "or_eq", "xor", "xor_eq",
                "delete", "namespace", "union", "cast"));
        return badNamesSet;
    }

    public static boolean isBadName(String nameToCheck) {
        return badNames.contains(nameToCheck);
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
                .longOpt("classes-per-output")
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
        options.addOption(Option.builder()
                .hasArg()
                .desc("Extra class urls.")
                .longOpt("extraclassurls")
                .build());
        options.addOption(Option.builder()
                .hasArg()
                .desc("Extra class names.")
                .longOpt("extraclassnames")
                .build());
        options.addOption(Option.builder()
                .hasArg()
                .desc("No copy class names.")
                .longOpt("nocopyclassnames")
                .build());
        options.addOption(Option.builder()
                .hasArg()
                .desc("Generate a utility java class for cloning.")
                .longOpt("javacloner")
                .build());
        String output = null;
        String header = null;
        String jar = null;
        Set<String> classnamesToFind = null;
        Set<String> packageprefixes = null;
        String loadlibname = null;
        String javacloner = null;

        Map<String, String> nativesNameMap = null;
        Map<String, Class> nativesClassMap = null;
        int limit = DEFAULT_LIMIT;
        int classes_per_file = 10;
        List<Class> classesList = new ArrayList<>();

        String limitstring = Integer.toString(limit);
        URL extraclassurls[] = new URL[0];
        String extraclassnames[] = new String[0];
        String nocopyclassnames[] = new String[0];
        Set<String> nocopyclassnamesSet = new TreeSet<>();
        String namespace = "javaforcpp";
        try {
            // parse the command line arguments
            System.out.println("args = " + Arrays.toString(args));
            CommandLine line = new DefaultParser().parse(options, args);
            loadlibname = line.getOptionValue("loadlibname");
            javacloner = line.getOptionValue("javacloner");
            verbose = line.hasOption("verbose");
            if (line.hasOption("extraclassurls")) {
                String extraclassurlstrings[] = line.getOptionValues("extraclassurls");
                System.out.println("extraclassurlstrings = " + Arrays.toString(extraclassurlstrings));
                extraclassurls = new URL[extraclassurlstrings.length];
                for (int i = 0; i < extraclassurlstrings.length; i++) {
                    String extraclassurlstring = extraclassurlstrings[i];
                    extraclassurls[i] = new URL(extraclassurlstring);
                }
                System.out.println("extraclassurls = " + Arrays.toString(extraclassurls));
            }

            if (line.hasOption("extraclassnames")) {
                extraclassnames = line.getOptionValues("extraclassnames");
                System.out.println("extraclassnames = " + Arrays.toString(extraclassnames));
            }

            if (line.hasOption("nocopyclassnames")) {
                nocopyclassnames = line.getOptionValues("nocopyclassnames");
                System.out.println("nocopyclassnames = " + Arrays.toString(nocopyclassnames));
                for (int i = 0; i < nocopyclassnames.length; i++) {
                    String nocopyclassname = nocopyclassnames[i];
                    nocopyclassnamesSet.add(nocopyclassname);
                }
            }
            if (line.hasOption("classes-per-output")) {
                String cpoStr = line.getOptionValue("classes-per-output");
                try {
                    int cpoI = Integer.parseInt(cpoStr);
                    classes_per_file = cpoI;
                } catch (Exception e) {
                    System.err.println("Option for " + "classes-per-output" + "=\"" + cpoStr + "\"");
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
                        if (!classesList.contains(javaClass)) {
                            classesList.add(javaClass);
                        }
                    }
                }
            }

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
        if (verbose) {
            System.out.println("System.getProperty(\"java.class.path\") = " + cp);
        }
        if (null != cp) {
            for (String cpe : cp.split(File.pathSeparator)) {
                if (verbose) {
                    System.out.println("class path element = " + cpe);
                }
                File f = new File(cpe);
                if (f.isDirectory()) {
                    urlsList.add(new URL("file:" + f.getCanonicalPath() + File.separator));
                } else if (cpe.endsWith(".jar")) {
                    urlsList.add(new URL("jar:file:" + f.getCanonicalPath() + "!/"));
                }
            }
        }
        cp = System.getenv("CLASSPATH");
        if (verbose) {
            System.out.println("System.getenv(\"CLASSPATH\") = " + cp);
        }
        if (null != cp) {
            for (String cpe : cp.split(File.pathSeparator)) {
                if (verbose) {
                    System.out.println("class path element = " + cpe);
                }
                File f = new File(cpe);
                if (f.isDirectory()) {
                    urlsList.add(new URL("file:" + f.getCanonicalPath() + File.separator));
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

            URL jarUrl = new URL("jar:file:" + jarPath.toFile().getCanonicalPath() + "!/");
            urlsList.add(jarUrl);
        }
        urlsList.add(new URL("file://" + System.getProperty("user.dir") + "/"));
        for (int i = 0; i < extraclassurls.length; i++) {
            urlsList.add(extraclassurls[i]);
        }
        URL[] urls = urlsList.toArray(new URL[urlsList.size()]);
        if (verbose) {
            System.out.println("urls = " + Arrays.toString(urls));
        }
        URLClassLoader cl = URLClassLoader.newInstance(urls);
        if (null != jar && jar.length() > 0) {
            Path jarPath = FileSystems.getDefault().getPath(jar);
            ZipInputStream zip = new ZipInputStream(Files.newInputStream(jarPath, StandardOpenOption.READ));
            for (ZipEntry entry = zip.getNextEntry(); entry != null; entry = zip.getNextEntry()) {
                // This ZipEntry represents a class. Now, what class does it represent?
                String entryName = entry.getName();
                if (verbose) {
                    System.out.println("entryName = " + entryName);
                }

                if (!entry.isDirectory() && entryName.endsWith(".class")) {

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
                            if (!classesList.contains(clss)) {
                                classesList.add(clss);
                            }
                        }
                        if (packageprefixes != null
                                && packageprefixes.size() > 0) {
                            if (null == clss.getPackage()) {
                                continue;
                            }
                            final String pkgName = clss.getPackage().getName();
                            boolean matchFound = false;
                            for (String prefix : packageprefixes) {
                                if (pkgName.startsWith(prefix)) {
                                    matchFound = true;
                                    break;
                                }
                            }
                            if (!matchFound) {
                                continue;
                            }
                        }
                        Package p = clss.getPackage();
                        if (null != p) {
                            packagesSet.add(clss.getPackage().getName());
                        }
                        if (!classesList.contains(clss)
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
                            classesList.add(clss);
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
                    if (classesList.contains(Class.forName(classname))) {
                        if (verbose) {
                            System.out.println("Classes list already contains:  " + classname);
                        }
                        continue;
                    }
                } catch (Exception e) {

                }

                if (null != classname && classname.length() > 0) {

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
                        if (!classesList.contains(c)) {
                            classesList.add(c);
                        }
                    } else {
                        System.err.println("Class " + classname + " not found");
                    }
                }
            }
            if (verbose) {
                System.out.println("Finished checking classnames arguments");
            }
        }
        if (classesList == null || classesList.size() < 1) {
            if (null == nativesClassMap || nativesClassMap.keySet().size() < 1) {
                System.err.println("No Classes specified or found.");
                System.exit(1);
            }
        }
        if (verbose) {
            System.out.println("Classes found = " + classesList.size());
        }
        if (classesList.size() > limit) {
            System.err.println("limit=" + limit);
            System.err.println("Too many classes please use -c or -p options to limit classes or -l to increase limit.");
            if (verbose) {
                System.out.println("packagesSet = " + packagesSet);
            }
            System.exit(1);
        }
        List<Class> newClasses = new ArrayList<Class>();
        System.out.println("Before adding extras : classesList.size() = " + classesList.size());
        if (extraclassnames.length > 0) {
            for (int i = 0; i < extraclassnames.length; i++) {
                String extraclassname = extraclassnames[i];
                Class clzz = cl.loadClass(extraclassname);
                if (!classesList.contains(clzz)) {
                    classesList.add(clzz);
                }
            }
        }
        System.out.println("Before adding supers : classesList.size() = " + classesList.size());

        for (Class clss : classesList) {
            Class superClass = clss.getSuperclass();
            while (null != superClass
                    && !classesList.contains(superClass)
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
                        if (!classesList.contains(fClass)
                                && !newClasses.contains(fClass)
                                && isAddableClass(fClass, excludedClasses)) {
                            newClasses.add(fClass);
                        }
                    }
                }
            } catch (NoClassDefFoundError e) {
                e.printStackTrace();
            }
            final Method[] classDeclaredMethods = clss.getDeclaredMethods();
//            Arrays.sort(classDeclaredMethods, Comparator.comparing((Method m) -> m.getName()));
            for (Method m : classDeclaredMethods) {
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
                if (!classesList.contains(retType)
                        && !newClasses.contains(retType)
                        && isAddableClass(retType, excludedClasses)) {
                    newClasses.add(retType);
                    if (verbose) {
                        System.out.println("Added retType = " + retType);
                    }
                    superClass = retType.getSuperclass();
                    while (null != superClass
                            && !classesList.contains(superClass)
                            && !newClasses.contains(superClass)
                            && isAddableClass(superClass, excludedClasses)) {

                        newClasses.add(superClass);
                        if (verbose) {
                            System.out.println("Added retType.getSuperclass() = " + superClass);
                        }
                        superClass = superClass.getSuperclass();
                    }
                }
                for (Class paramType : m.getParameterTypes()) {
                    if (!classesList.contains(paramType)
                            && !newClasses.contains(paramType)
                            && isAddableClass(paramType, excludedClasses)) {
                        newClasses.add(paramType);
                        if (verbose) {
                            System.out.println("Added paramType = " + superClass);
                        }
                        superClass = paramType.getSuperclass();
                        while (null != superClass
                                && !classesList.contains(superClass)
                                && !newClasses.contains(superClass)
                                && !excludedClasses.contains(superClass)) {
                            if (verbose) {
                                System.out.println("Added paramType.superClass = " + superClass);
                            }
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
                            && !classesList.contains(superClass)
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
            System.out.println("newClasses = " + newClasses);
        }
        classesList.addAll(newClasses);
        List<Class> newOrderClasses = new ArrayList<>();
        for (Class clss : classesList) {
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
                final Class poppedClass = stack.pop();
                if (!newOrderClasses.contains(poppedClass)) {
                    newOrderClasses.add(poppedClass);
                }
            }
            if (!newOrderClasses.contains(clss)) {
                newOrderClasses.add(clss);
            }
        }
        classesList = newOrderClasses;
        if (verbose) {
            System.out.println("Total number of classes = " + classesList.size());
            System.out.println("classes = " + classesList);
        }
        if (null != javacloner && javacloner.length() > 1) {
            JavaCloneUtilGenerator generator = new JavaCloneUtilGenerator();
            File dir;
            if (null != output && output.length() > 0) {
                File outFile = new File(output);
                File outFileParent = outFile.getParentFile();
                if (null != outFileParent) {
                    dir = outFileParent;
                } else {
                    dir = null;
                }
            } else {
                dir = null;
            }
            generator.generateCloneUtil(javacloner, dir, classesList,nocopyclassnamesSet);
        } else {
            CppGenerator cg = new CppGenerator();
            cg.setNamespace(namespace);
            cg.generatAllCpp(header, jar, nativesClassMap, loadlibname, classesList, classes_per_file, output);
        }
        main_completed = true;
    }

    private static void printHelpAndExit(Options options, String args[]) {
        System.out.println("args = " + Arrays.toString(args));
        new HelpFormatter().printHelp("java4cpp", options);
        System.exit(1);
    }
}
