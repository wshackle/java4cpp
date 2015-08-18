
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.TransAccelAbsoluteType
   static inline jclass getTransAccelAbsoluteTypeClass();
   
   TransAccelAbsoluteType::TransAccelAbsoluteType(jobject _jthis, bool copy): TransAccelType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   TransAccelAbsoluteType::TransAccelAbsoluteType(const TransAccelAbsoluteType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   TransAccelAbsoluteType::TransAccelAbsoluteType() : TransAccelType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getTransAccelAbsoluteTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class TransAccelAbsoluteType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," TransAccelAbsoluteType::getMessage jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new TransAccelAbsoluteType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TransAccelAbsoluteType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.TransAccelAbsoluteType
   TransAccelAbsoluteType::~TransAccelAbsoluteType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal TransAccelAbsoluteType::getSetting() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSetting of crcl.base.TransAccelAbsoluteType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," TransAccelAbsoluteType::getSetting jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.TransAccelAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TransAccelAbsoluteType::getSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::math::BigDecimal retObject(retVal,false);
    return retObject;
   }
   void TransAccelAbsoluteType::setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSetting of crcl.base.TransAccelAbsoluteType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," TransAccelAbsoluteType::setSetting jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.TransAccelAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TransAccelAbsoluteType::setSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewTransAccelAbsoluteTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/TransAccelAbsoluteType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/TransAccelAbsoluteType" << std::endl;
       }
       return clss;
   }
   
   static jclass TransAccelAbsoluteTypeClass = NULL;
   static inline jclass getTransAccelAbsoluteTypeClass() {
       if (TransAccelAbsoluteTypeClass != NULL) {
           return TransAccelAbsoluteTypeClass;
       }
       TransAccelAbsoluteTypeClass = getNewTransAccelAbsoluteTypeClass();
   }
   
   // get JNI handle for class crcl.base.TransSpeedType
   static inline jclass getTransSpeedTypeClass();
   
   TransSpeedType::TransSpeedType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   TransSpeedType::TransSpeedType(const TransSpeedType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   TransSpeedType::TransSpeedType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getTransSpeedTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class TransSpeedType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," TransSpeedType::setSetting jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new TransSpeedType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TransSpeedType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.TransSpeedType
   TransSpeedType::~TransSpeedType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewTransSpeedTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/TransSpeedType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/TransSpeedType" << std::endl;
       }
       return clss;
   }
   
   static jclass TransSpeedTypeClass = NULL;
   static inline jclass getTransSpeedTypeClass() {
       if (TransSpeedTypeClass != NULL) {
           return TransSpeedTypeClass;
       }
       TransSpeedTypeClass = getNewTransSpeedTypeClass();
   }
   
   // get JNI handle for class crcl.base.TransSpeedRelativeType
   static inline jclass getTransSpeedRelativeTypeClass();
   
   TransSpeedRelativeType::TransSpeedRelativeType(jobject _jthis, bool copy): TransSpeedType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   TransSpeedRelativeType::TransSpeedRelativeType(const TransSpeedRelativeType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   TransSpeedRelativeType::TransSpeedRelativeType() : TransSpeedType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getTransSpeedRelativeTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class TransSpeedRelativeType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," TransSpeedRelativeType::setSetting jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new TransSpeedRelativeType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TransSpeedRelativeType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.TransSpeedRelativeType
   TransSpeedRelativeType::~TransSpeedRelativeType() {
   	// Place-holder for later extensibility.
   }

   void TransSpeedRelativeType::setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFraction of crcl.base.TransSpeedRelativeType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," TransSpeedRelativeType::setFraction jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.TransSpeedRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TransSpeedRelativeType::setFraction jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal TransSpeedRelativeType::getFraction() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFraction of crcl.base.TransSpeedRelativeType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," TransSpeedRelativeType::getFraction jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.TransSpeedRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TransSpeedRelativeType::getFraction jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::math::BigDecimal retObject(retVal,false);
    return retObject;
   }
   static jclass getNewTransSpeedRelativeTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/TransSpeedRelativeType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/TransSpeedRelativeType" << std::endl;
       }
       return clss;
   }
   
   static jclass TransSpeedRelativeTypeClass = NULL;
   static inline jclass getTransSpeedRelativeTypeClass() {
       if (TransSpeedRelativeTypeClass != NULL) {
           return TransSpeedRelativeTypeClass;
       }
       TransSpeedRelativeTypeClass = getNewTransSpeedRelativeTypeClass();
   }
   
   // get JNI handle for class crcl.base.RunProgramType
   static inline jclass getRunProgramTypeClass();
   
   RunProgramType::RunProgramType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RunProgramType::RunProgramType(const RunProgramType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RunProgramType::RunProgramType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRunProgramTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RunProgramType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RunProgramType::getFraction jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RunProgramType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RunProgramType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RunProgramType
   RunProgramType::~RunProgramType() {
   	// Place-holder for later extensibility.
   }

   jstring RunProgramType::getProgramText() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getProgramText of crcl.base.RunProgramType with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RunProgramType::getProgramText jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getProgramText", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RunProgramType has no method named getProgramText with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RunProgramType::getProgramText jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void RunProgramType::setProgramText(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setProgramText of crcl.base.RunProgramType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RunProgramType::setProgramText jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setProgramText", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RunProgramType has no method named setProgramText with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RunProgramType::setProgramText jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void RunProgramType::setProgramText(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setProgramText of crcl.base.RunProgramType with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RunProgramType::setProgramText jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setProgramText(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   static jclass getNewRunProgramTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RunProgramType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RunProgramType" << std::endl;
       }
       return clss;
   }
   
   static jclass RunProgramTypeClass = NULL;
   static inline jclass getRunProgramTypeClass() {
       if (RunProgramTypeClass != NULL) {
           return RunProgramTypeClass;
       }
       RunProgramTypeClass = getNewRunProgramTypeClass();
   }
  } // end namespace base

   namespace utils{
   
   // get JNI handle for class crcl.utils.PerfTest
   static inline jclass getPerfTestClass();
   
   PerfTest::PerfTest(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PerfTest::PerfTest(const PerfTest &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PerfTest::PerfTest() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPerfTestClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PerfTest has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PerfTest::setProgramText jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PerfTest with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PerfTest jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.PerfTest
   PerfTest::~PerfTest() {
   	// Place-holder for later extensibility.
   }

   void PerfTest::runPerfTest(jboolean boolean_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getPerfTestClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "runPerfTest", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PerfTest has no method named runPerfTest with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PerfTest::runPerfTest jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PerfTest::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getPerfTestClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PerfTest has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PerfTest::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PerfTest::main(int argc, const char **argv) {
           if(argc <1 || argv==NULL) {
                main(NULL);
           } else {
               JNIEnv *env =getEnv();
               jclass strClss = getStringClass();
               jobjectArray stringArray = env->NewObjectArray(argc,strClss,getEmptyString());
               for(int i = 0; i < argc; i++) {
                   jstring str = env->NewStringUTF(argv[i]);
                   env->SetObjectArrayElement(stringArray,i,str);
               }
                main(stringArray);
               for(int i = 0; i < argc; i++) {
                   jobject str = env->GetObjectArrayElement(stringArray,i);
                   jobjectRefType ref = env->GetObjectRefType(str);
                   if(ref == JNIGlobalRefType) {
                       env->DeleteGlobalRef(str);
                   }
               }
               jobjectRefType ref = env->GetObjectRefType(stringArray);
               if(ref == JNIGlobalRefType) {
                   env->DeleteGlobalRef(stringArray);
               }
               return ;
           }
   }
   static jclass getNewPerfTestClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/PerfTest");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/PerfTest" << std::endl;
       }
       return clss;
   }
   
   static jclass PerfTestClass = NULL;
   static inline jclass getPerfTestClass() {
       if (PerfTestClass != NULL) {
           return PerfTestClass;
       }
       PerfTestClass = getNewPerfTestClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

