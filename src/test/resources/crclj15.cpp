
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.ConfigureJointReportsType
   static inline jclass getConfigureJointReportsTypeClass();
   
   ConfigureJointReportsType::ConfigureJointReportsType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ConfigureJointReportsType::ConfigureJointReportsType(const ConfigureJointReportsType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ConfigureJointReportsType::ConfigureJointReportsType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getConfigureJointReportsTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ConfigureJointReportsType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::setZAxisTolerance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ConfigureJointReportsType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ConfigureJointReportsType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.ConfigureJointReportsType
   ConfigureJointReportsType::~ConfigureJointReportsType() {
   	// Place-holder for later extensibility.
   }

   jboolean ConfigureJointReportsType::isResetAll() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isResetAll of crcl.base.ConfigureJointReportsType with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::isResetAll jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isResetAll", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ConfigureJointReportsType has no method named isResetAll with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::isResetAll jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void ConfigureJointReportsType::setResetAll(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setResetAll of crcl.base.ConfigureJointReportsType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::setResetAll jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setResetAll", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ConfigureJointReportsType has no method named setResetAll with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::setResetAll jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::util::List ConfigureJointReportsType::getConfigureJointReport() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getConfigureJointReport of crcl.base.ConfigureJointReportsType with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::getConfigureJointReport jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getConfigureJointReport", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ConfigureJointReportsType has no method named getConfigureJointReport with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ConfigureJointReportsType::getConfigureJointReport jthis=",t);
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
   static jclass getNewConfigureJointReportsTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/ConfigureJointReportsType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/ConfigureJointReportsType" << std::endl;
       }
       return clss;
   }
   
   static jclass ConfigureJointReportsTypeClass = NULL;
   static inline jclass getConfigureJointReportsTypeClass() {
       if (ConfigureJointReportsTypeClass != NULL) {
           return ConfigureJointReportsTypeClass;
       }
       ConfigureJointReportsTypeClass = getNewConfigureJointReportsTypeClass();
   }
   
   // get JNI handle for class crcl.base.CRCLCommandInstanceType
   static inline jclass getCRCLCommandInstanceTypeClass();
   
   CRCLCommandInstanceType::CRCLCommandInstanceType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CRCLCommandInstanceType::CRCLCommandInstanceType(const CRCLCommandInstanceType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CRCLCommandInstanceType::CRCLCommandInstanceType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCRCLCommandInstanceTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CRCLCommandInstanceType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CRCLCommandInstanceType::getConfigureJointReport jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CRCLCommandInstanceType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLCommandInstanceType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.CRCLCommandInstanceType
   CRCLCommandInstanceType::~CRCLCommandInstanceType() {
   	// Place-holder for later extensibility.
   }

   void CRCLCommandInstanceType::setCRCLCommand(CRCLCommandType  &cRCLCommandType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCRCLCommand of crcl.base.CRCLCommandInstanceType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLCommandInstanceType::setCRCLCommand jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCRCLCommand", "(Lcrcl/base/CRCLCommandType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLCommandInstanceType has no method named setCRCLCommand with signature (Lcrcl/base/CRCLCommandType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLCommandType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLCommandInstanceType::setCRCLCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   CRCLCommandType CRCLCommandInstanceType::getCRCLCommand() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCRCLCommand of crcl.base.CRCLCommandInstanceType with jthis == NULL." << std::endl;
       CRCLCommandType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLCommandInstanceType::getCRCLCommand jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCRCLCommand", "()Lcrcl/base/CRCLCommandType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLCommandInstanceType has no method named getCRCLCommand with signature ()Lcrcl/base/CRCLCommandType;." << std::endl;
           CRCLCommandType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLCommandInstanceType::getCRCLCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CRCLCommandType retObject(retVal,false);
    return retObject;
   }
   static jclass getNewCRCLCommandInstanceTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/CRCLCommandInstanceType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/CRCLCommandInstanceType" << std::endl;
       }
       return clss;
   }
   
   static jclass CRCLCommandInstanceTypeClass = NULL;
   static inline jclass getCRCLCommandInstanceTypeClass() {
       if (CRCLCommandInstanceTypeClass != NULL) {
           return CRCLCommandInstanceTypeClass;
       }
       CRCLCommandInstanceTypeClass = getNewCRCLCommandInstanceTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetRotSpeedType
   static inline jclass getSetRotSpeedTypeClass();
   
   SetRotSpeedType::SetRotSpeedType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetRotSpeedType::SetRotSpeedType(const SetRotSpeedType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetRotSpeedType::SetRotSpeedType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetRotSpeedTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetRotSpeedType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetRotSpeedType::getCRCLCommand jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetRotSpeedType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetRotSpeedType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetRotSpeedType
   SetRotSpeedType::~SetRotSpeedType() {
   	// Place-holder for later extensibility.
   }

   RotSpeedType SetRotSpeedType::getRotSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getRotSpeed of crcl.base.SetRotSpeedType with jthis == NULL." << std::endl;
       RotSpeedType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetRotSpeedType::getRotSpeed jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getRotSpeed", "()Lcrcl/base/RotSpeedType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetRotSpeedType has no method named getRotSpeed with signature ()Lcrcl/base/RotSpeedType;." << std::endl;
           RotSpeedType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetRotSpeedType::getRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RotSpeedType retObject(retVal,false);
    return retObject;
   }
   void SetRotSpeedType::setRotSpeed(RotSpeedType  &rotSpeedType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setRotSpeed of crcl.base.SetRotSpeedType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetRotSpeedType::setRotSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setRotSpeed", "(Lcrcl/base/RotSpeedType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetRotSpeedType has no method named setRotSpeed with signature (Lcrcl/base/RotSpeedType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,rotSpeedType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetRotSpeedType::setRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewSetRotSpeedTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetRotSpeedType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetRotSpeedType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetRotSpeedTypeClass = NULL;
   static inline jclass getSetRotSpeedTypeClass() {
       if (SetRotSpeedTypeClass != NULL) {
           return SetRotSpeedTypeClass;
       }
       SetRotSpeedTypeClass = getNewSetRotSpeedTypeClass();
   }
   
   // get JNI handle for class crcl.base.ParallelGripperStatusType
   static inline jclass getParallelGripperStatusTypeClass();
   
   ParallelGripperStatusType::ParallelGripperStatusType(jobject _jthis, bool copy): GripperStatusType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ParallelGripperStatusType::ParallelGripperStatusType(const ParallelGripperStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ParallelGripperStatusType::ParallelGripperStatusType() : GripperStatusType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getParallelGripperStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ParallelGripperStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ParallelGripperStatusType::setRotSpeed jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ParallelGripperStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ParallelGripperStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.ParallelGripperStatusType
   ParallelGripperStatusType::~ParallelGripperStatusType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal ParallelGripperStatusType::getSeparation() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSeparation of crcl.base.ParallelGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParallelGripperStatusType::getSeparation jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSeparation", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ParallelGripperStatusType has no method named getSeparation with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ParallelGripperStatusType::getSeparation jthis=",t);
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
   void ParallelGripperStatusType::setSeparation(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSeparation of crcl.base.ParallelGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParallelGripperStatusType::setSeparation jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSeparation", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ParallelGripperStatusType has no method named setSeparation with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ParallelGripperStatusType::setSeparation jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewParallelGripperStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/ParallelGripperStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/ParallelGripperStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass ParallelGripperStatusTypeClass = NULL;
   static inline jclass getParallelGripperStatusTypeClass() {
       if (ParallelGripperStatusTypeClass != NULL) {
           return ParallelGripperStatusTypeClass;
       }
       ParallelGripperStatusTypeClass = getNewParallelGripperStatusTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetEndEffectorParametersType
   static inline jclass getSetEndEffectorParametersTypeClass();
   
   SetEndEffectorParametersType::SetEndEffectorParametersType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetEndEffectorParametersType::SetEndEffectorParametersType(const SetEndEffectorParametersType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetEndEffectorParametersType::SetEndEffectorParametersType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetEndEffectorParametersTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetEndEffectorParametersType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetEndEffectorParametersType::setSeparation jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetEndEffectorParametersType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetEndEffectorParametersType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetEndEffectorParametersType
   SetEndEffectorParametersType::~SetEndEffectorParametersType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::util::List SetEndEffectorParametersType::getParameterSetting() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getParameterSetting of crcl.base.SetEndEffectorParametersType with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetEndEffectorParametersType::getParameterSetting jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getParameterSetting", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetEndEffectorParametersType has no method named getParameterSetting with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetEndEffectorParametersType::getParameterSetting jthis=",t);
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
   static jclass getNewSetEndEffectorParametersTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetEndEffectorParametersType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetEndEffectorParametersType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetEndEffectorParametersTypeClass = NULL;
   static inline jclass getSetEndEffectorParametersTypeClass() {
       if (SetEndEffectorParametersTypeClass != NULL) {
           return SetEndEffectorParametersTypeClass;
       }
       SetEndEffectorParametersTypeClass = getNewSetEndEffectorParametersTypeClass();
   }
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

