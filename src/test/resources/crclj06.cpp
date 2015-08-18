
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.SetTransAccelType
   static inline jclass getSetTransAccelTypeClass();
   
   SetTransAccelType::SetTransAccelType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetTransAccelType::SetTransAccelType(const SetTransAccelType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetTransAccelType::SetTransAccelType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetTransAccelTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetTransAccelType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetTransAccelType::setDwellTime jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetTransAccelType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetTransAccelType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetTransAccelType
   SetTransAccelType::~SetTransAccelType() {
   	// Place-holder for later extensibility.
   }

   TransAccelType SetTransAccelType::getTransAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTransAccel of crcl.base.SetTransAccelType with jthis == NULL." << std::endl;
       TransAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetTransAccelType::getTransAccel jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTransAccel", "()Lcrcl/base/TransAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetTransAccelType has no method named getTransAccel with signature ()Lcrcl/base/TransAccelType;." << std::endl;
           TransAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetTransAccelType::getTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    TransAccelType retObject(retVal,false);
    return retObject;
   }
   void SetTransAccelType::setTransAccel(TransAccelType  &transAccelType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTransAccel of crcl.base.SetTransAccelType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetTransAccelType::setTransAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTransAccel", "(Lcrcl/base/TransAccelType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetTransAccelType has no method named setTransAccel with signature (Lcrcl/base/TransAccelType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,transAccelType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetTransAccelType::setTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewSetTransAccelTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetTransAccelType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetTransAccelType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetTransAccelTypeClass = NULL;
   static inline jclass getSetTransAccelTypeClass() {
       if (SetTransAccelTypeClass != NULL) {
           return SetTransAccelTypeClass;
       }
       SetTransAccelTypeClass = getNewSetTransAccelTypeClass();
   }
   
   // get JNI handle for class crcl.base.JointForceTorqueType
   static inline jclass getJointForceTorqueTypeClass();
   
   JointForceTorqueType::JointForceTorqueType(jobject _jthis, bool copy): JointDetailsType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JointForceTorqueType::JointForceTorqueType(const JointForceTorqueType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JointForceTorqueType::JointForceTorqueType() : JointDetailsType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJointForceTorqueTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JointForceTorqueType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::setTransAccel jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JointForceTorqueType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JointForceTorqueType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.JointForceTorqueType
   JointForceTorqueType::~JointForceTorqueType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal JointForceTorqueType::getSetting() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSetting of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::getSetting jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointForceTorqueType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::getSetting jthis=",t);
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
   void JointForceTorqueType::setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSetting of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::setSetting jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointForceTorqueType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::setSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal JointForceTorqueType::getChangeRate() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getChangeRate of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::getChangeRate jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getChangeRate", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointForceTorqueType has no method named getChangeRate with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::getChangeRate jthis=",t);
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
   void JointForceTorqueType::setChangeRate(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setChangeRate of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::setChangeRate jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setChangeRate", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointForceTorqueType has no method named setChangeRate with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointForceTorqueType::setChangeRate jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewJointForceTorqueTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/JointForceTorqueType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/JointForceTorqueType" << std::endl;
       }
       return clss;
   }
   
   static jclass JointForceTorqueTypeClass = NULL;
   static inline jclass getJointForceTorqueTypeClass() {
       if (JointForceTorqueTypeClass != NULL) {
           return JointForceTorqueTypeClass;
       }
       JointForceTorqueTypeClass = getNewJointForceTorqueTypeClass();
   }
   
   // get JNI handle for class crcl.base.PointType
   static inline jclass getPointTypeClass();
   
   PointType::PointType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PointType::PointType(const PointType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PointType::PointType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPointTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PointType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PointType::setChangeRate jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PointType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PointType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.PointType
   PointType::~PointType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal PointType::getX() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getX of crcl.base.PointType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PointType::getX jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getX", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PointType has no method named getX with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PointType::getX jthis=",t);
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
   ::crclj::java::math::BigDecimal PointType::getY() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getY of crcl.base.PointType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PointType::getY jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getY", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PointType has no method named getY with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PointType::getY jthis=",t);
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
   void PointType::setX(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setX of crcl.base.PointType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PointType::setX jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setX", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PointType has no method named setX with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PointType::setX jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PointType::setY(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setY of crcl.base.PointType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PointType::setY jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setY", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PointType has no method named setY with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PointType::setY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal PointType::getZ() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getZ of crcl.base.PointType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PointType::getZ jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getZ", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PointType has no method named getZ with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PointType::getZ jthis=",t);
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
   void PointType::setZ(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setZ of crcl.base.PointType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PointType::setZ jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setZ", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PointType has no method named setZ with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PointType::setZ jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewPointTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/PointType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/PointType" << std::endl;
       }
       return clss;
   }
   
   static jclass PointTypeClass = NULL;
   static inline jclass getPointTypeClass() {
       if (PointTypeClass != NULL) {
           return PointTypeClass;
       }
       PointTypeClass = getNewPointTypeClass();
   }
  } // end namespace base

   namespace utils{
   
   // get JNI handle for class crcl.utils.CRCLPosemath
   static inline jclass getCRCLPosemathClass();
   
   CRCLPosemath::CRCLPosemath(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CRCLPosemath::CRCLPosemath(const CRCLPosemath &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CRCLPosemath::CRCLPosemath() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class CRCLPosemath has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::setZ jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new CRCLPosemath with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLPosemath jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for crcl.utils.CRCLPosemath
   CRCLPosemath::~CRCLPosemath() {
   	// Place-holder for later extensibility.
   }

   ::crclj::crcl::base::PointType CRCLPosemath::subtract(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "subtract", "(Lcrcl/base/PointType;Lcrcl/base/PointType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named subtract with signature (Lcrcl/base/PointType;Lcrcl/base/PointType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pointType_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::subtract jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::multiply(::crclj::java::math::BigDecimal  &bigDecimal_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "multiply", "(Ljava/math/BigDecimal;Lcrcl/base/PointType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named multiply with signature (Ljava/math/BigDecimal;Lcrcl/base/PointType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,bigDecimal_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::multiply(::crclj::java::math::BigDecimal  &bigDecimal_0,::crclj::crcl::base::VectorType  &vectorType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "multiply", "(Ljava/math/BigDecimal;Lcrcl/base/VectorType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named multiply with signature (Ljava/math/BigDecimal;Lcrcl/base/VectorType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,bigDecimal_0.jthis,vectorType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::multiply(jdouble double_0,::crclj::crcl::base::VectorType  &vectorType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "multiply", "(DLcrcl/base/VectorType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named multiply with signature (DLcrcl/base/VectorType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,double_0,vectorType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::multiply(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "multiply", "(Lcrcl/base/PoseType;Lcrcl/base/PoseType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named multiply with signature (Lcrcl/base/PoseType;Lcrcl/base/PoseType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::multiply(jdouble double_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "multiply", "(DLcrcl/base/PointType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named multiply with signature (DLcrcl/base/PointType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,double_0,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::math::BigDecimal CRCLPosemath::dot(::crclj::crcl::base::VectorType  &vectorType_0,::crclj::crcl::base::VectorType  &vectorType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "dot", "(Lcrcl/base/VectorType;Lcrcl/base/VectorType;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named dot with signature (Lcrcl/base/VectorType;Lcrcl/base/VectorType;)Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vectorType_0.jthis,vectorType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::dot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::math::BigDecimal retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::math::BigDecimal CRCLPosemath::dot(::crclj::crcl::base::VectorType  &vectorType_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "dot", "(Lcrcl/base/VectorType;Lcrcl/base/PointType;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named dot with signature (Lcrcl/base/VectorType;Lcrcl/base/PointType;)Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vectorType_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::dot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::math::BigDecimal retObject(retVal,false);
    return retObject;
   }
   jdouble CRCLPosemath::norm(::crclj::crcl::base::VectorType  &vectorType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "norm", "(Lcrcl/base/VectorType;)D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named norm with signature (Lcrcl/base/VectorType;)D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vectorType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::norm jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::invert(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "invert", "(Lcrcl/base/PoseType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named invert with signature (Lcrcl/base/PoseType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::invert jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D CRCLPosemath::toCommonsVector3D(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCommonsVector3D", "(Lcrcl/base/PoseType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCommonsVector3D with signature (Lcrcl/base/PoseType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
           ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCommonsVector3D jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D retObject(retVal,false);
    return retObject;
   }
   ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D CRCLPosemath::toCommonsVector3D(::crclj::crcl::base::PointType  &pointType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCommonsVector3D", "(Lcrcl/base/PointType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCommonsVector3D with signature (Lcrcl/base/PointType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
           ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pointType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCommonsVector3D jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D retObject(retVal,false);
    return retObject;
   }
   ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D CRCLPosemath::toCommonsVector3D(::crclj::crcl::base::VectorType  &vectorType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCommonsVector3D", "(Lcrcl/base/VectorType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCommonsVector3D with signature (Lcrcl/base/VectorType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
           ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vectorType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCommonsVector3D jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::VectorType CRCLPosemath::toCRCLUnitVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0,::crclj::crcl::base::VectorType  &vectorType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCRCLUnitVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lcrcl/base/VectorType;)Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCRCLUnitVector with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lcrcl/base/VectorType;)Lcrcl/base/VectorType;." << std::endl;
           ::crclj::crcl::base::VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis,vectorType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCRCLUnitVector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::VectorType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::VectorType CRCLPosemath::toCRCLUnitVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCRCLUnitVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCRCLUnitVector with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lcrcl/base/VectorType;." << std::endl;
           ::crclj::crcl::base::VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCRCLUnitVector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::VectorType retObject(retVal,false);
    return retObject;
   }
   ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Rotation CRCLPosemath::toCommonsRotation(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCommonsRotation", "(Lcrcl/base/PoseType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCommonsRotation with signature (Lcrcl/base/PoseType;)Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;." << std::endl;
           ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Rotation nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCommonsRotation jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Rotation retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::toCRCLPoint(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCRCLPoint", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCRCLPoint with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCRCLPoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::toCRCLPoint(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCRCLPoint", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lcrcl/base/PointType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCRCLPoint with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lcrcl/base/PointType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCRCLPoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::rcs::posemath::PmCartesian CRCLPosemath::pointToPmCartesian(::crclj::crcl::base::PointType  &pointType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "pointToPmCartesian", "(Lcrcl/base/PointType;)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named pointToPmCartesian with signature (Lcrcl/base/PointType;)Lrcs/posemath/PmCartesian;." << std::endl;
           ::crclj::rcs::posemath::PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pointType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::pointToPmCartesian jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmCartesian retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::identityPose() {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "identityPose", "()Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named identityPose with signature ()Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::identityPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   jstring CRCLPosemath::poseToString(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "poseToString", "(Lcrcl/base/PoseType;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named poseToString with signature (Lcrcl/base/PoseType;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::poseToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::rcs::posemath::PmPose CRCLPosemath::toPmPose(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPmPose", "(Lcrcl/base/PoseType;)Lrcs/posemath/PmPose;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPmPose with signature (Lcrcl/base/PoseType;)Lrcs/posemath/PmPose;." << std::endl;
           ::crclj::rcs::posemath::PmPose nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPmPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmPose retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::VectorType CRCLPosemath::cross(::crclj::crcl::base::VectorType  &vectorType_0,::crclj::crcl::base::VectorType  &vectorType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "cross", "(Lcrcl/base/VectorType;Lcrcl/base/VectorType;)Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named cross with signature (Lcrcl/base/VectorType;Lcrcl/base/VectorType;)Lcrcl/base/VectorType;." << std::endl;
           ::crclj::crcl::base::VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vectorType_0.jthis,vectorType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::cross jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::VectorType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::pointXAxisZAxisToPose(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::VectorType  &vectorType_1,::crclj::crcl::base::VectorType  &vectorType_2) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "pointXAxisZAxisToPose", "(Lcrcl/base/PointType;Lcrcl/base/VectorType;Lcrcl/base/VectorType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named pointXAxisZAxisToPose with signature (Lcrcl/base/PointType;Lcrcl/base/VectorType;Lcrcl/base/VectorType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pointType_0.jthis,vectorType_1.jthis,vectorType_2.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::pointXAxisZAxisToPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   jdouble CRCLPosemath::diffPoints(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "diffPoints", "(Lcrcl/base/PointType;Lcrcl/base/PointType;)D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named diffPoints with signature (Lcrcl/base/PointType;Lcrcl/base/PointType;)D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,pointType_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::diffPoints jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble CRCLPosemath::diffPosesTran(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "diffPosesTran", "(Lcrcl/base/PoseType;Lcrcl/base/PoseType;)D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named diffPosesTran with signature (Lcrcl/base/PoseType;Lcrcl/base/PoseType;)D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,poseType_0.jthis,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::diffPosesTran jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::rcs::posemath::PmCartesian CRCLPosemath::vectorToPmCartesian(::crclj::crcl::base::VectorType  &vectorType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "vectorToPmCartesian", "(Lcrcl/base/VectorType;)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named vectorToPmCartesian with signature (Lcrcl/base/VectorType;)Lrcs/posemath/PmCartesian;." << std::endl;
           ::crclj::rcs::posemath::PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vectorType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::vectorToPmCartesian jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmCartesian retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::toPoseType(::crclj::rcs::posemath::PmCartesian  &pmCartesian_0,::crclj::rcs::posemath::PmRotationVector  &pmRotationVector_1,::crclj::crcl::base::PoseType  &poseType_2) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPoseType", "(Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRotationVector;Lcrcl/base/PoseType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPoseType with signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRotationVector;Lcrcl/base/PoseType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pmCartesian_0.jthis,pmRotationVector_1.jthis,poseType_2.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPoseType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::toPoseType(::crclj::rcs::posemath::PmCartesian  &pmCartesian_0,::crclj::rcs::posemath::PmRotationVector  &pmRotationVector_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPoseType", "(Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRotationVector;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPoseType with signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRotationVector;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pmCartesian_0.jthis,pmRotationVector_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPoseType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   ::crclj::rcs::posemath::PmRotationMatrix CRCLPosemath::toPmRotationMatrix(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPmRotationMatrix", "(Lcrcl/base/PoseType;)Lrcs/posemath/PmRotationMatrix;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPmRotationMatrix with signature (Lcrcl/base/PoseType;)Lrcs/posemath/PmRotationMatrix;." << std::endl;
           ::crclj::rcs::posemath::PmRotationMatrix nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPmRotationMatrix jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmRotationMatrix retObject(retVal,false);
    return retObject;
   }
   ::crclj::rcs::posemath::PmRotationVector CRCLPosemath::toPmRotationVector(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPmRotationVector", "(Lcrcl/base/PoseType;)Lrcs/posemath/PmRotationVector;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPmRotationVector with signature (Lcrcl/base/PoseType;)Lrcs/posemath/PmRotationVector;." << std::endl;
           ::crclj::rcs::posemath::PmRotationVector nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPmRotationVector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmRotationVector retObject(retVal,false);
    return retObject;
   }
   ::crclj::rcs::posemath::PmRpy CRCLPosemath::toPmRpy(::crclj::crcl::base::PoseType  &poseType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPmRpy", "(Lcrcl/base/PoseType;)Lrcs/posemath/PmRpy;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPmRpy with signature (Lcrcl/base/PoseType;)Lrcs/posemath/PmRpy;." << std::endl;
           ::crclj::rcs::posemath::PmRpy nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPmRpy jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmRpy retObject(retVal,false);
    return retObject;
   }
   jdouble CRCLPosemath::maxDiffDoubleArray(jdoubleArray doubleArray_0,jdoubleArray doubleArray_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "maxDiffDoubleArray", "([D[D)D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named maxDiffDoubleArray with signature ([D[D)D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,doubleArray_0,doubleArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::maxDiffDoubleArray jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble CRCLPosemath::diffPosesRot(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "diffPosesRot", "(Lcrcl/base/PoseType;Lcrcl/base/PoseType;)D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named diffPosesRot with signature (Lcrcl/base/PoseType;Lcrcl/base/PoseType;)D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,poseType_0.jthis,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::diffPosesRot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::toPointType(::crclj::rcs::posemath::PmCartesian  &pmCartesian_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toPointType", "(Lrcs/posemath/PmCartesian;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toPointType with signature (Lrcs/posemath/PmCartesian;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pmCartesian_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toPointType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::VectorType CRCLPosemath::toCRCLVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCRCLVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCRCLVector with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lcrcl/base/VectorType;." << std::endl;
           ::crclj::crcl::base::VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCRCLVector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::VectorType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::VectorType CRCLPosemath::toCRCLVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0,::crclj::crcl::base::VectorType  &vectorType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "toCRCLVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lcrcl/base/VectorType;)Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named toCRCLVector with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lcrcl/base/VectorType;)Lcrcl/base/VectorType;." << std::endl;
           ::crclj::crcl::base::VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis,vectorType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::toCRCLVector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::VectorType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PointType CRCLPosemath::add(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "add", "(Lcrcl/base/PointType;Lcrcl/base/PointType;)Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named add with signature (Lcrcl/base/PointType;Lcrcl/base/PointType;)Lcrcl/base/PointType;." << std::endl;
           ::crclj::crcl::base::PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,pointType_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::add jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PointType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::VectorType CRCLPosemath::normalize(::crclj::crcl::base::VectorType  &vectorType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "normalize", "(Lcrcl/base/VectorType;)Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named normalize with signature (Lcrcl/base/VectorType;)Lcrcl/base/VectorType;." << std::endl;
           ::crclj::crcl::base::VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vectorType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::normalize jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::VectorType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType CRCLPosemath::shift(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PointType  &pointType_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLPosemathClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "shift", "(Lcrcl/base/PoseType;Lcrcl/base/PointType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLPosemath has no method named shift with signature (Lcrcl/base/PoseType;Lcrcl/base/PointType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,poseType_0.jthis,pointType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLPosemath::shift jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   static jclass getNewCRCLPosemathClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/CRCLPosemath");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/CRCLPosemath" << std::endl;
       }
       return clss;
   }
   
   static jclass CRCLPosemathClass = NULL;
   static inline jclass getCRCLPosemathClass() {
       if (CRCLPosemathClass != NULL) {
           return CRCLPosemathClass;
       }
       CRCLPosemathClass = getNewCRCLPosemathClass();
   }
   
   // get JNI handle for class crcl.utils.XpathUtils
   static inline jclass getXpathUtilsClass();
   
   XpathUtils::XpathUtils(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   XpathUtils::XpathUtils(const XpathUtils &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   XpathUtils::XpathUtils() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getXpathUtilsClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class XpathUtils has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::shift jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new XpathUtils with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new XpathUtils jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for crcl.utils.XpathUtils
   XpathUtils::~XpathUtils() {
   	// Place-holder for later extensibility.
   }

   jobjectArray XpathUtils::getSchemaFiles() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSchemaFiles of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::getSchemaFiles jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSchemaFiles", "()[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named getSchemaFiles with signature ()[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::getSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void XpathUtils::setSchemaFiles(jobjectArray fileArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSchemaFiles of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::setSchemaFiles jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSchemaFiles", "([Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named setSchemaFiles with signature ([Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::setSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring XpathUtils::getDocumentation(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDocumentation of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::getDocumentation jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getDocumentation", "(Ljava/lang/String;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named getDocumentation with signature (Ljava/lang/String;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::getDocumentation jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathUtils::getDocumentation(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method getDocumentation of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::getDocumentation jthis=",jthis);
    jstring retVal=NULL;
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    retVal= (jstring) getDocumentation(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   jstring XpathUtils::nodeToString(::crclj::org::w3c::dom::Node  &node_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method nodeToString of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::nodeToString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "nodeToString", "(Lorg/w3c/dom/Node;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named nodeToString with signature (Lorg/w3c/dom/Node;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,node_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::nodeToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathUtils::queryXml(::crclj::java::io::File  &file_0,jstring string_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method queryXml of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXml jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "queryXml", "(Ljava/io/File;Ljava/lang/String;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named queryXml with signature (Ljava/io/File;Ljava/lang/String;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,file_0.jthis,string_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXml jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathUtils::queryXml(::crclj::java::io::File easyArg_0,const char * easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method queryXml of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXml jthis=",jthis);
    jstring retVal=NULL;
            
    ::crclj::java::io::File  &file_0= easyArg_0;
    jstring string_1 = env->NewStringUTF(easyArg_1);
    retVal= (jstring) queryXml(file_0,string_1);
    jobjectRefType ref_1 = env->GetObjectRefType(string_1);
    if(ref_1 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_1);
    }
    
    releaseEnv(env);
    return retVal;
   }

   jstring XpathUtils::queryXml(jobjectArray fileArray_0,jstring string_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method queryXml of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXml jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "queryXml", "([Ljava/io/File;Ljava/lang/String;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named queryXml with signature ([Ljava/io/File;Ljava/lang/String;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,fileArray_0,string_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXml jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathUtils::nodeListToString(::crclj::org::w3c::dom::NodeList  &nodeList_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method nodeListToString of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::nodeListToString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "nodeListToString", "(Lorg/w3c/dom/NodeList;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named nodeListToString with signature (Lorg/w3c/dom/NodeList;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,nodeList_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::nodeListToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathUtils::queryXmlString(jstring string_0,jstring string_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method queryXmlString of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXmlString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "queryXmlString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathUtils has no method named queryXmlString with signature (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,string_0,string_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXmlString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathUtils::queryXmlString(const char * easyArg_0,const char * easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method queryXmlString of crcl.utils.XpathUtils with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathUtils::queryXmlString jthis=",jthis);
    jstring retVal=NULL;
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jstring string_1 = env->NewStringUTF(easyArg_1);
    retVal= (jstring) queryXmlString(string_0,string_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    jobjectRefType ref_1 = env->GetObjectRefType(string_1);
    if(ref_1 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_1);
    }
    
    releaseEnv(env);
    return retVal;
   }

   static jclass getNewXpathUtilsClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/XpathUtils");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/XpathUtils" << std::endl;
       }
       return clss;
   }
   
   static jclass XpathUtilsClass = NULL;
   static inline jclass getXpathUtilsClass() {
       if (XpathUtilsClass != NULL) {
           return XpathUtilsClass;
       }
       XpathUtilsClass = getNewXpathUtilsClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

