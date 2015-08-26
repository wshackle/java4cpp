
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "simple.h"

namespace simple {

    JNIEnv *getEnv();
    static bool debug_j4cpp = false;

    namespace java {
        namespace lang {

            Object::Object() {
                jthis = NULL;
            };

            Object::Object(const Object &objref) {
                jobject _jthis = objref.jthis;
                if (_jthis != NULL) {
                    jthis = getEnv()->NewGlobalRef(_jthis);
                }
            };

            Object::Object(jobject _jthis, bool copy) {
                //                std::cout << "_jthis = " << _jthis << std::endl;
                jthis = NULL;
                if (_jthis != NULL) {
                    JNIEnv *env = getEnv();
                    jobjectRefType ref0 = env->GetObjectRefType(jthis);
                    if (copy || ref0 != JNIGlobalRefType) {
                        jthis = env->NewGlobalRef(_jthis);
                    }
                }
            };

            Object & Object::operator =(const Object &otherobject) {
                jobject oldjthis = jthis;
                jobject _newjthis = otherobject.jthis;
                jobject newjthis= NULL;
                jthis= NULL;
                JNIEnv *env = getEnv();
                if (_newjthis != NULL) {
                    if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__,"Object::operator= called for _newjthis=",_newjthis);
                    newjthis = env->NewGlobalRef(_newjthis);
                }
                if (NULL != oldjthis) {
                    if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__,"Object::operator= called for oldjthis=",oldjthis);
                    env->DeleteGlobalRef(oldjthis);
                    oldjthis = NULL;
                }
                jthis=newjthis;
                releaseEnv(env);
                return *this;
            }
            
            Object::~Object() {
                if (NULL != jthis) {
                    if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__,"Destructor called for ",jthis);
                    getEnv()->DeleteGlobalRef(jthis);
                    jthis = NULL;
                }
            };

            jstring Object::toString() {

                if (jthis == NULL) {
                    std::cerr << "Call of method toString of java.lang.Object with jthis == NULL." << std::endl;
                    return NULL;
                }
                JNIEnv *env = getEnv();
                jobjectRefType ref0 = env->GetObjectRefType(jthis);
                if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Object::toString() jthis=",jthis);
                jclass cls = env->GetObjectClass(jthis);
                jstring retVal = NULL;
                if (cls != NULL) {
                    jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
                    if (NULL == mid) {
                        std::cerr << "Class ava.lang.Object has no method named toString with signature ()Ljava/lang/String;." << std::endl;
                        return NULL;
                    } else {
                        retVal = (jstring) env->CallObjectMethod(jthis, mid);
                    }
                }
                return retVal;
            }
        }
    }


 
 // get JNI handle for class Simple
 static inline jclass getSimpleClass();
 
 Simple::Simple(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
         // Place holder for future extensibility
 }
 
 Simple::Simple(const Simple &objref): java::lang::Object((jobject)NULL,false) {
     jobject _jthis = objref.jthis;
     if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class Simple _jthis=",_jthis);
     if (_jthis != NULL) {
         jthis = getEnv()->NewGlobalRef(_jthis);
         if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class Simple jthis=",jthis);
     }
 }
 
 Simple Simple::cast(const java::lang::Object &objref) {
     JNIEnv *env =getEnv();
     static jclass cls = getSimpleClass(); 
     jclass objcls = env->GetObjectClass(objref.jthis);
     if(!env->IsAssignableFrom(objcls,cls)) {
         throw objcls;
     }
     Simple retVal(objref.jthis,true);
     return retVal;
 }
 Simple::Simple() : java::lang::Object((jobject)NULL,false) {
 JNIEnv *env =getEnv();
 static jclass cls = getSimpleClass();
 if (cls != NULL) {
     static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
     if (NULL == mid) {
         std::cerr << "Class Simple has no method constructor signature ()V" << std::endl;
     } else {
         jthis = env->NewObject(cls, mid );
         jthrowable t = env->ExceptionOccurred();
         if(t != NULL) {
             if(GetDebugJ4Cpp()) {
                 DebugPrintJObject(__FILE__,__LINE__," Simple::%METHOD_NAME% jthis=",t);
                 env->ExceptionDescribe();
             }
             throw t;
         }
         if(jthis == NULL) {
             std::cerr << "Call to create new Simple with signature ()V returned null." << std::endl;
             releaseEnv(env);
             return;
         }
         jobjectRefType ref = env->GetObjectRefType(jthis);
         if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Simple jthis=",jthis);
         if(ref != JNIGlobalRefType) {
             jthis = env->NewGlobalRef(jthis);
         }
     }
 }
 releaseEnv(env);
 }

 Simple::Simple(jint int_0) : java::lang::Object((jobject)NULL,false) {
  JNIEnv *env =getEnv();
  static jclass cls = getSimpleClass();
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "<init>", "(I)V");
      if (NULL == mid) {
          std::cerr << "Class Simple has no method constructor signature (I)V" << std::endl;
      } else {
          jthis = env->NewObject(cls, mid ,int_0);
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," Simple::%METHOD_NAME% jthis=",t);
                  env->ExceptionDescribe();
              }
              throw t;
          }
          if(jthis == NULL) {
              std::cerr << "Call to create new Simple with signature (I)V returned null." << std::endl;
              releaseEnv(env);
              return;
          }
          jobjectRefType ref = env->GetObjectRefType(jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Simple jthis=",jthis);
          if(ref != JNIGlobalRefType) {
              jthis = env->NewGlobalRef(jthis);
          }
      }
  }
  releaseEnv(env);
 }


 // Destructor for Simple
 Simple::~Simple() {
 	// Place-holder for later extensibility.
 }

 jint Simple::getValue() {

 if(jthis == NULL) {
     std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getValue of Simple with jthis == NULL." << std::endl;
     return (jint) -1;
 }
 JNIEnv *env =getEnv();
 jclass cls = env->GetObjectClass(jthis);
 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Simple::getValue jthis=",jthis);
 jint retVal= (jint) -1;
 if (cls != NULL) {
     static jmethodID mid = env->GetMethodID(cls, "getValue", "()I");
     if (NULL == mid) {
         DebugPrintJObject(__FILE__,__LINE__," Simple::getValue jthis=",jthis);
         std::cerr << __FILE__ << ":" << __LINE__ <<  " Class Simple has no method named getValue with signature ()I." << std::endl;
         return (jint) -1;
     } else {
         retVal= (jint)  env->CallIntMethod(jthis, mid  );
         jthrowable t = env->ExceptionOccurred();
         if(t != NULL) {
             if(GetDebugJ4Cpp()) {
                 DebugPrintJObject(__FILE__,__LINE__," Simple::getValue jthrowable t=",t);
                 env->ExceptionDescribe();
             }
 //            env->ExceptionClear();
             throw t;
         }
     }
 }
 releaseEnv(env);
 return retVal;
 }
 static jclass getNewSimpleClass() {
     jclass clss = getEnv()->FindClass("Simple");
     if (NULL == clss) {
         std::cerr << " Can't find class Simple" << std::endl;
     }
     return clss;
 }
 
 static jclass SimpleClass = NULL;
 static inline jclass getSimpleClass() {
     if (SimpleClass != NULL) {
         return SimpleClass;
     }
     SimpleClass = getNewSimpleClass();
     return SimpleClass;
 }



    static JNIEnv *getNewEnv() {
        JavaVM *jvm; /* denotes a Java VM */
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
        str += "/home/shackle/java4cpp/examples/simple";
        if (classPathEnv != NULL) {
            std::string classPathEnvStr(classPathEnv);
            if (debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
            str += ":";
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
        ClassClass = getNewStringClass();
        return ClassClass;
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
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
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
    
    void PrintObject(const char *prefix, const ::simple::java::lang::Object &objref) {
        PrintJObject(prefix,objref.jthis);
    }
    
    extern void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    extern bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace simple
}

