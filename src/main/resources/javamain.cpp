/* 
 * File:   main.cpp
 * Author: Will Shackleford  {@literal <william.shackleford@nist.gov>}
 *
 * Created on July 30, 2015, 10:03 AM
 */

#include <cstdlib>
#include <iostream>
#include "javamain.h"
#include <jni.h>

using namespace std;
using namespace javamain;


static JNIEnv *getNewEnv() {
    JavaVM *jvm; /* denotes a Java VM */
    JNIEnv *env; /* pointer to native method interface */
    JavaVM * jvmBuf[1];
    jsize nVMs;
    jint v = JNI_GetCreatedJavaVMs(jvmBuf, 1, &nVMs);
    if (nVMs > 0) {
        jvmBuf[0]->GetEnv((void **) &env, JNI_VERSION_1_6);
        return env;
    }
    JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
    JavaVMOption* options = new JavaVMOption[1];
    options[0].optionString = (char *) getenv("JVM_OPTIONS");
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


static inline jclass getMainClass();
static inline JNIEnv *getEnv();

static jclass getNewMainClass() {
    jclass clss = getEnv()->FindClass("Main");
    if (NULL == clss) {
        cerr << " Can't find class Main" << endl;
    }
    return clss;
}



namespace javamain {

    void Main::staticTest(jint i) {
        JNIEnv *env =getEnv();
        jclass cls = getMainClass();
        if (cls != NULL) {
            jmethodID mid = env->GetStaticMethodID(cls, "staticTest", "(I)V");
            if (NULL == mid) {
                std::cerr << "Class Main has no method named staticTest" << std::endl;
            } else {
                env->CallStaticVoidMethod(cls, mid, i);
            }
        }
    }
    
    Main::Main(jint i) {
        JNIEnv *env =getEnv();
        jclass cls = getMainClass();
        if (cls != NULL) {
            jmethodID mid = env->GetMethodID(cls, "<init>", "(I)V");
            if (NULL == mid) {
                std::cerr << "Class Main has no method constructor with int parameter" << std::endl;
            } else {
                jthis = env->NewObject(cls, mid, i);
                jobjectRefType ref = env->GetObjectRefType(jthis);
                if(ref != JNIGlobalRefType) {
                    jthis = env->NewGlobalRef(jthis);
                }
            }
        }
    }
    jint Main::getI() {
        jclass cls = getMainClass();
        JNIEnv *env =getEnv();
        if (cls != NULL) {
            jmethodID mid = env->GetMethodID(cls, "getI", "()I");
            if (NULL == mid) {
                std::cerr << "Class Main has no method named getI" << std::endl;
                return (jint) -1;
            } else {
                return env->CallIntMethod(jthis, mid);
            }
        }
    }
    
    Main::~Main() {
        if(NULL != jthis) {
            getEnv()->DeleteGlobalRef(jthis);
            jthis=NULL;
        }
    }
}

static JNIEnv *env = NULL;
static jclass mainClass = NULL;

namespace javamain {
    void closeJVM() {
        JavaVM * jvmBuf[1];
        jsize nVMs;
        env = NULL;
        mainClass = NULL;
        jint v = JNI_GetCreatedJavaVMs(jvmBuf, 1, &nVMs);
        if (nVMs > 0) {
            jvmBuf[0]->DestroyJavaVM();
        }
    }
}



static inline jclass getMainClass() {
    if (mainClass != NULL) {
        return mainClass;
    }
    mainClass = getNewMainClass();
}

static inline JNIEnv *getEnv() {
    if (env != NULL) {
        return env;
    }
    env = getNewEnv();
    return env;
}