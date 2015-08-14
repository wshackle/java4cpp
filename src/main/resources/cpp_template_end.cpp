//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.



    static JNIEnv *getNewEnv() {
        JavaVM *jvm; /* denotes a Java VM */
        JNIEnv *env; /* pointer to native method interface */
        JavaVM * jvmBuf[1];
        jsize nVMs;
        debug_j4cpp = debug_j4cpp || (getenv("DEBUG_J4CPP") != NULL);
        char *classPathEnv = getenv("CLASSPATH");
        char *jvmOptionsEnv = getenv("JVM_OPTIONS");
        std::string str;
        str += "%JAR%";
        if (classPathEnv != NULL) {
            std::string classPathEnvStr(classPathEnv);
            if (debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
            str += "%PATH_SEPERATOR%";
            str += classPathEnvStr;
        }
        if (debug_j4cpp) std::cout << "str=" << str << std::endl;
        setenv("CLASSPATH", str.c_str(), 1);
        std::string optsString;
        optsString += "-Djava.class.path=";
        optsString += str;
        if (jvmOptionsEnv != NULL) {
            std::string jvmOptionsEnvStr(jvmOptionsEnv);
            if (debug_j4cpp) std::cout << "jvmOptionsEnvStr=" << jvmOptionsEnvStr << std::endl;
            optsString += " ";
            optsString += jvmOptionsEnvStr;
        }
        if (debug_j4cpp) std::cout << "optsString=" << optsString << std::endl;
        jint v = JNI_GetCreatedJavaVMs(jvmBuf, 1, &nVMs);
        if (nVMs > 0) {
            jvmBuf[0]->GetEnv((void **) &env, JNI_VERSION_1_6);
            return env;
        }
        JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
        JavaVMOption* options = new JavaVMOption[1];
        options[0].optionString = (char *) optsString.c_str();
        vm_args.version = JNI_VERSION_1_6;
        vm_args.nOptions = NULL != options[0].optionString ? 1 : 0;
        vm_args.options = options;
        vm_args.ignoreUnrecognized = false;
        /* load and initialize a Java VM, return a JNI interface
         * pointer in env */
        JNI_CreateJavaVM(&jvm,
                ((void **) (&env)),
                ((void *) (&vm_args)));
        delete options;
        return env;
    }

    static JNIEnv *env = NULL;

    JNIEnv *getEnv() {
        if (env != NULL) {
            return env;
        }
        env = getNewEnv();
        return env;
    }

    void releaseEnv(JNIEnv *env) {
        // Maybe implement this later, 
        // This will probably cause a memory leak.
        // Don't like leaks? Why the hell are using C++?
    }

    static jclass getNewStringClass() {
        jclass clss = getEnv()->FindClass("java/lang/String");
        if (NULL == clss) {
            std::cerr << " Can't find class java/lang/String" << std::endl;
        }
        return clss;
    }

    static jclass StringClass = NULL;

    static inline jclass getStringClass() {
        if (StringClass != NULL) {
            return StringClass;
        }
        StringClass = getNewStringClass();
        return StringClass;
    }

    static jstring getNewEmptyString() {
        return getEnv()->NewStringUTF("");
    }

    static jstring EmptyString = NULL;

    static inline jstring getEmptyString() {
        if (EmptyString != NULL) {
            return EmptyString;
        }
        EmptyString = getNewEmptyString();
        return EmptyString;
    }

    void PrintJObject(const char *prefix, jobject jobj) {
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj) {
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        bool isnull = (jobj == NULL) || (env->IsSameObject(jobj,NULL) == JNI_TRUE);
        if(isnull) {
            std::cout << file << ":" << lineno << " jobj=" << jobj << " " << prefix << "NULL" << std::endl;
            return;
        }
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << file << ":" << lineno << " jobj=" << jobj << " " << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintObject(const char *prefix, const ::%NAMESPACE%::java::lang::Object &objref) {
        PrintJObject(prefix,objref.jthis);
    }
    
    extern void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    extern bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace %NAMESPACE%
}

