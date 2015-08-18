
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.SetIntermediatePoseToleranceType
   static inline jclass getSetIntermediatePoseToleranceTypeClass();
   
   SetIntermediatePoseToleranceType::SetIntermediatePoseToleranceType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetIntermediatePoseToleranceType::SetIntermediatePoseToleranceType(const SetIntermediatePoseToleranceType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetIntermediatePoseToleranceType::SetIntermediatePoseToleranceType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetIntermediatePoseToleranceTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetIntermediatePoseToleranceType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetIntermediatePoseToleranceType::setCommandID jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetIntermediatePoseToleranceType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetIntermediatePoseToleranceType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetIntermediatePoseToleranceType
   SetIntermediatePoseToleranceType::~SetIntermediatePoseToleranceType() {
   	// Place-holder for later extensibility.
   }

   void SetIntermediatePoseToleranceType::setTolerance(PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTolerance of crcl.base.SetIntermediatePoseToleranceType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetIntermediatePoseToleranceType::setTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetIntermediatePoseToleranceType has no method named setTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetIntermediatePoseToleranceType::setTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PoseToleranceType SetIntermediatePoseToleranceType::getTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTolerance of crcl.base.SetIntermediatePoseToleranceType with jthis == NULL." << std::endl;
       PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetIntermediatePoseToleranceType::getTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetIntermediatePoseToleranceType has no method named getTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetIntermediatePoseToleranceType::getTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseToleranceType retObject(retVal,false);
    return retObject;
   }
   static jclass getNewSetIntermediatePoseToleranceTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetIntermediatePoseToleranceType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetIntermediatePoseToleranceType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetIntermediatePoseToleranceTypeClass = NULL;
   static inline jclass getSetIntermediatePoseToleranceTypeClass() {
       if (SetIntermediatePoseToleranceTypeClass != NULL) {
           return SetIntermediatePoseToleranceTypeClass;
       }
       SetIntermediatePoseToleranceTypeClass = getNewSetIntermediatePoseToleranceTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetEndPoseToleranceType
   static inline jclass getSetEndPoseToleranceTypeClass();
   
   SetEndPoseToleranceType::SetEndPoseToleranceType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetEndPoseToleranceType::SetEndPoseToleranceType(const SetEndPoseToleranceType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetEndPoseToleranceType::SetEndPoseToleranceType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetEndPoseToleranceTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetEndPoseToleranceType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetEndPoseToleranceType::getTolerance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetEndPoseToleranceType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetEndPoseToleranceType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetEndPoseToleranceType
   SetEndPoseToleranceType::~SetEndPoseToleranceType() {
   	// Place-holder for later extensibility.
   }

   void SetEndPoseToleranceType::setTolerance(PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTolerance of crcl.base.SetEndPoseToleranceType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetEndPoseToleranceType::setTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetEndPoseToleranceType has no method named setTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetEndPoseToleranceType::setTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PoseToleranceType SetEndPoseToleranceType::getTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTolerance of crcl.base.SetEndPoseToleranceType with jthis == NULL." << std::endl;
       PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetEndPoseToleranceType::getTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetEndPoseToleranceType has no method named getTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetEndPoseToleranceType::getTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseToleranceType retObject(retVal,false);
    return retObject;
   }
   static jclass getNewSetEndPoseToleranceTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetEndPoseToleranceType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetEndPoseToleranceType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetEndPoseToleranceTypeClass = NULL;
   static inline jclass getSetEndPoseToleranceTypeClass() {
       if (SetEndPoseToleranceTypeClass != NULL) {
           return SetEndPoseToleranceTypeClass;
       }
       SetEndPoseToleranceTypeClass = getNewSetEndPoseToleranceTypeClass();
   }
   
   // get JNI handle for class crcl.base.EndCanonType
   static inline jclass getEndCanonTypeClass();
   
   EndCanonType::EndCanonType(jobject _jthis, bool copy): CRCLCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   EndCanonType::EndCanonType(const EndCanonType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   EndCanonType::EndCanonType() : CRCLCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getEndCanonTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class EndCanonType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," EndCanonType::getTolerance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new EndCanonType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new EndCanonType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.EndCanonType
   EndCanonType::~EndCanonType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewEndCanonTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/EndCanonType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/EndCanonType" << std::endl;
       }
       return clss;
   }
   
   static jclass EndCanonTypeClass = NULL;
   static inline jclass getEndCanonTypeClass() {
       if (EndCanonTypeClass != NULL) {
           return EndCanonTypeClass;
       }
       EndCanonTypeClass = getNewEndCanonTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetRobotParametersType
   static inline jclass getSetRobotParametersTypeClass();
   
   SetRobotParametersType::SetRobotParametersType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetRobotParametersType::SetRobotParametersType(const SetRobotParametersType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetRobotParametersType::SetRobotParametersType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetRobotParametersTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetRobotParametersType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetRobotParametersType::getTolerance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetRobotParametersType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetRobotParametersType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetRobotParametersType
   SetRobotParametersType::~SetRobotParametersType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::util::List SetRobotParametersType::getParameterSetting() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getParameterSetting of crcl.base.SetRobotParametersType with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetRobotParametersType::getParameterSetting jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getParameterSetting", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetRobotParametersType has no method named getParameterSetting with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetRobotParametersType::getParameterSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::List retObject(retVal,false);
    return retObject;
   }
   static jclass getNewSetRobotParametersTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetRobotParametersType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetRobotParametersType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetRobotParametersTypeClass = NULL;
   static inline jclass getSetRobotParametersTypeClass() {
       if (SetRobotParametersTypeClass != NULL) {
           return SetRobotParametersTypeClass;
       }
       SetRobotParametersTypeClass = getNewSetRobotParametersTypeClass();
   }
  } // end namespace base

   namespace utils{
   
   // get JNI handle for class crcl.utils.DefaultMain
   static inline jclass getDefaultMainClass();
   
   DefaultMain::DefaultMain(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   DefaultMain::DefaultMain(const DefaultMain &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   DefaultMain::DefaultMain() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getDefaultMainClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class DefaultMain has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," DefaultMain::getParameterSetting jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new DefaultMain with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new DefaultMain jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.DefaultMain
   DefaultMain::~DefaultMain() {
   	// Place-holder for later extensibility.
   }

   void DefaultMain::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getDefaultMainClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.DefaultMain has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," DefaultMain::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void DefaultMain::main(int argc, const char **argv) {
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
   static jclass getNewDefaultMainClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/DefaultMain");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/DefaultMain" << std::endl;
       }
       return clss;
   }
   
   static jclass DefaultMainClass = NULL;
   static inline jclass getDefaultMainClass() {
       if (DefaultMainClass != NULL) {
           return DefaultMainClass;
       }
       DefaultMainClass = getNewDefaultMainClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

