//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.


    static JavaVM *jvm = NULL; /* denotes a Java VM */
    
#ifdef __cplusplus
extern "C" {
#endif
    


JNIEXPORT jint JNICALL JNI_OnLoad_L(JavaVM *vm, void *reserved) {
    std::cout << "JNI_OnLoad() called" << std::endl; 
    return JNI_OK;
}


JNIEXPORT jint JNICALL JNI_OnUnload_L(JavaVM *vm, void *reserved) {
    std::cout << "JNI_OnUnLoad_L() called" << std::endl;
    return JNI_OK;
}

/*
 * Class:     com_github_wshackle_java4cplusplus_NativeRunnable
 * Method:    run
 * Signature: ()V
 */
JNIEXPORT void JNICALL 
Java_NativeRunnable_run(JNIEnv *env, jobject jobj) {
    std::cout << "Java_com_github_wshackle_java4cplusplus_NativeRunnable_run() called" << std::endl;
    std::cout << "env=" << env << std::endl;
    std::cout << "jobj=" << jobj << std::endl;    
}

#ifdef __cplusplus
}
#endif


    static JNIEnv *getNewEnv() {
        
        JNIEnv *env; /* pointer to native method interface */
        JavaVM * jvmBuf[1];
        jsize nVMs;
        char *debugJ4CppEnv = NULL;
        char *classPathEnv = NULL;
        char *jvmOptionsEnv = NULL;
#if defined(_WIN32) || defined(_WIN64)
        errno_t errno_val;
        size_t requiredSize;
        errno_val =  getenv_s( &requiredSize, NULL, 0, "DEBUG_J4CPP");
        if(requiredSize > 0) {
            debugJ4CppEnv = (char *) malloc(requiredSize);
            errno_val =  getenv_s( &requiredSize, debugJ4CppEnv, requiredSize, "DEBUG_J4CPP");
        }
        errno_val =  getenv_s( &requiredSize, NULL, 0, "CLASSPATH");
        if(requiredSize > 0) {
            classPathEnv = (char *) malloc(requiredSize);
            errno_val =  getenv_s( &requiredSize, classPathEnv, requiredSize, "CLASSPATH");
        }
        errno_val =  getenv_s( &requiredSize, NULL, 0, "JVM_OPTIONS");
        if(requiredSize > 0) {
            jvmOptionsEnv = (char *) malloc(requiredSize);
            errno_val =  getenv_s( &requiredSize, jvmOptionsEnv, requiredSize, "JVM_OPTIONS");
        }
#else 
        debugJ4CppEnv = getenv("DEBUG_J4CPP");
        classPathEnv = getenv("CLASSPATH");
        jvmOptionsEnv = getenv("JVM_OPTIONS");
#endif
        debug_j4cpp = debug_j4cpp || (debugJ4CppEnv != NULL && debugJ4CppEnv[0] != 0);
        std::string str;
        str += "%JAR%";
        if (classPathEnv != NULL) {
            std::string classPathEnvStr(classPathEnv);
            if (debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
            str += "%PATH_SEPERATOR%";
            str += classPathEnvStr;
        }
        if (debug_j4cpp) std::cout << "str=" << str << std::endl;
#if defined(_WIN32) || defined(_WIN64)
        _putenv_s("CLASSPATH", str.c_str());
#else
        setenv("CLASSPATH", str.c_str(), 1);
#endif
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
            jvm = jvmBuf[0];
            jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
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
#if defined(_WIN32) || defined(_WIN64)
        if(debugJ4CppEnv != NULL) {
            free(debugJ4CppEnv);
            debugJ4CppEnv = NULL;
        }
        if(classPathEnv != NULL) {
            free(classPathEnv);
            classPathEnv = NULL;
        }
        if(jvmOptionsEnv != NULL) {
            free(jvmOptionsEnv);
            jvmOptionsEnv = NULL;
        }
#endif
        static JNINativeMethod methods[1];
        jclass loaderclass = env->FindClass("java/lang/ClassLoader");
        std::cout << "loaderclass = " << loaderclass << std::endl;
        jmethodID mid = env->GetStaticMethodID(loaderclass,"getSystemClassLoader","()Ljava/lang/ClassLoader;");
        std::cout << "mid = " << mid << std::endl;
        jobject loader = env->CallStaticObjectMethod(loaderclass,mid);
        std::cout << "loader = " << loader << std::endl;
        jclass rn_clss = env->FindClass("NativeRunnable");
        std::cout << "rn_clss = " << rn_clss << std::endl;
        if(NULL != rn_clss) {
            methods[0].name = (char *) "run";
            methods[0].signature = (char *) "()V";
            methods[0].fnPtr = (void *) Java_NativeRunnable_run;
            jint rn_ret = env->RegisterNatives(rn_clss,methods,1);
            std::cout << "rn_ret = " << rn_ret << std::endl;
        }
        return env;
    }

    static JNIEnv *env = NULL;

    JNIEnv *getEnv() {
        if (env != NULL && jvm != NULL) {
            JNIEnv *env2=env;
            jint attach_ret = jvm->AttachCurrentThread((void **)&env2,NULL);
            if(attach_ret != JNI_OK) {
                std::cerr << "JNI AttachCurrentThread failed returning " << attach_ret << std::endl;
                return NULL;
            }
            return env2;
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

    jclass getStringClass() {
        if (StringClass != NULL) {
            return StringClass;
        }
        StringClass = getNewStringClass();
        return StringClass;
    }

    static jclass getNewClassClass() {
        jclass clss = getEnv()->FindClass("java/lang/Class");
        if (NULL == clss) {
            std::cerr << " Can't find class java/lang/Class" << std::endl;
        }
        return clss;
    }

    static jclass ClassClass = NULL;

    jclass getClassClass() {
        if (ClassClass != NULL) {
            return ClassClass;
        }
        ClassClass = getNewClassClass();
        return ClassClass;
    }
    
    static jclass getNewArraysClass() {
        jclass clss = getEnv()->FindClass("java/util/Arrays");
        if (NULL == clss) {
            std::cerr << " Can't find class java/util/Arrays" << std::endl;
        }
        return clss;
    }

    static jclass ArraysClass = NULL;

    jclass getArraysClass() {
        if (ArraysClass != NULL) {
            return ArraysClass;
        }
        ArraysClass = getNewArraysClass();
        return ArraysClass;
    }
    
    static jstring getNewEmptyString() {
        return getEnv()->NewStringUTF("");
    }

    static jstring EmptyString = NULL;

    jstring getEmptyString() {
        if (EmptyString != NULL) {
            return EmptyString;
        }
        EmptyString = getNewEmptyString();
        return EmptyString;
    }

    void PrintJObject(const char *prefix, jobject jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJBooleanArray(const char *prefix, jbooleanArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([Z)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJByteArray(const char *prefix, jbyteArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([B)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJCharArray(const char *prefix, jcharArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([C)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJShortArray(const char *prefix, jshortArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([S)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJIntArray(const char *prefix, jintArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([I)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJLongArray(const char *prefix, jlongArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([J)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJFloatArray(const char *prefix, jfloatArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([F)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJDoubleArray(const char *prefix, jdoubleArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([D)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJThrowable(const char *prefix, jthrowable jobj) {
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cerr << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    
    void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj) {
        
        if(NULL == jobj) {
            std::cout << file << ":" << lineno << " " << prefix << "NULL" << std::endl;
            return;
        }
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
    
    const char *GetStringUTFChars(jstring js, jboolean *iscopy) {
        jboolean iscopy2;
        const char *ret = getEnv()->GetStringUTFChars(js,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    
    void ReleaseStringUTFChars(jstring js, const char *utf) {
        getEnv()->ReleaseStringUTFChars(js,utf);
    }
    
    jboolean *GetBooleanArrayElements(jbooleanArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jboolean *ret = getEnv()->GetBooleanArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
    }
    
    jbyte *GetByteArrayElements(jbyteArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jbyte *ret = getEnv()->GetByteArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    
    jchar *GetCharArrayElements(jcharArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jchar *ret = getEnv()->GetCharArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jshort *GetShortArrayElements(jshortArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jshort *ret = getEnv()->GetShortArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jint *GetIntArrayElements(jintArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jint *ret = getEnv()->GetIntArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jlong *GetLongArrayElements(jlongArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jlong *ret = getEnv()->GetLongArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jfloat *GetFloatArrayElements(jfloatArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jfloat *ret = getEnv()->GetFloatArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jdouble *GetDoubleArrayElements(jdoubleArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jdouble *ret = getEnv()->GetDoubleArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    
    void ReleaseBooleanArrayElements(jbooleanArray jarray, jboolean *nativeArray, jint mode) {
        getEnv()->ReleaseBooleanArrayElements(jarray,nativeArray,mode);
    }
    
    void ReleaseByteArrayElements(jbyteArray jarray, jbyte *nativeArray, jint mode) {
        getEnv()->ReleaseByteArrayElements(jarray,nativeArray,mode);
    }
    
    void ReleaseCharArrayElements(jcharArray jarray, jchar *nativeArray, jint mode) {
        getEnv()->ReleaseCharArrayElements(jarray,nativeArray,mode);
    }
    
    void ReleaseShortArrayElements(jshortArray jarray, jshort *nativeArray, jint mode) {
        getEnv()->ReleaseShortArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseIntArrayElements(jintArray jarray, jint *nativeArray, jint mode) {
        getEnv()->ReleaseIntArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseLongArrayElements(jlongArray jarray, jlong *nativeArray, jint mode) {
        getEnv()->ReleaseLongArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseFloatArrayElements(jfloatArray jarray, jfloat *nativeArray, jint mode) {
        getEnv()->ReleaseFloatArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseDoubleArrayElements(jdoubleArray jarray, jdouble *nativeArray, jint mode) {
        getEnv()->ReleaseDoubleArrayElements(jarray,nativeArray,mode);
    }
    
    
    void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace %NAMESPACE%
}

