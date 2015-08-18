
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.InitCanonType
   static inline jclass getInitCanonTypeClass();
   
   InitCanonType::InitCanonType(jobject _jthis, bool copy): CRCLCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   InitCanonType::InitCanonType(const InitCanonType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   InitCanonType::InitCanonType() : CRCLCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getInitCanonTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class InitCanonType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," InitCanonType::getResult jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new InitCanonType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new InitCanonType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.InitCanonType
   InitCanonType::~InitCanonType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewInitCanonTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/InitCanonType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/InitCanonType" << std::endl;
       }
       return clss;
   }
   
   static jclass InitCanonTypeClass = NULL;
   static inline jclass getInitCanonTypeClass() {
       if (InitCanonTypeClass != NULL) {
           return InitCanonTypeClass;
       }
       InitCanonTypeClass = getNewInitCanonTypeClass();
   }
   
   // get JNI handle for class crcl.base.JointStatusesType
   static inline jclass getJointStatusesTypeClass();
   
   JointStatusesType::JointStatusesType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JointStatusesType::JointStatusesType(const JointStatusesType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JointStatusesType::JointStatusesType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJointStatusesTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JointStatusesType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JointStatusesType::getResult jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JointStatusesType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JointStatusesType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.JointStatusesType
   JointStatusesType::~JointStatusesType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::util::List JointStatusesType::getJointStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointStatus of crcl.base.JointStatusesType with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusesType::getJointStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointStatus", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusesType has no method named getJointStatus with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusesType::getJointStatus jthis=",t);
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
   static jclass getNewJointStatusesTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/JointStatusesType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/JointStatusesType" << std::endl;
       }
       return clss;
   }
   
   static jclass JointStatusesTypeClass = NULL;
   static inline jclass getJointStatusesTypeClass() {
       if (JointStatusesTypeClass != NULL) {
           return JointStatusesTypeClass;
       }
       JointStatusesTypeClass = getNewJointStatusesTypeClass();
   }
   
   // get JNI handle for class crcl.base.JointStatusType
   static inline jclass getJointStatusTypeClass();
   
   JointStatusType::JointStatusType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JointStatusType::JointStatusType(const JointStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JointStatusType::JointStatusType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJointStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JointStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointStatus jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JointStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JointStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.JointStatusType
   JointStatusType::~JointStatusType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigInteger JointStatusType::getJointNumber() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointNumber of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointNumber jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointNumber", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named getJointNumber with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointNumber jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::math::BigInteger retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::math::BigDecimal JointStatusType::getJointPosition() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointPosition of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointPosition jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointPosition", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named getJointPosition with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointPosition jthis=",t);
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
   ::crclj::java::math::BigDecimal JointStatusType::getJointVelocity() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointVelocity of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointVelocity jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointVelocity", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named getJointVelocity with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointVelocity jthis=",t);
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
   ::crclj::java::math::BigDecimal JointStatusType::getJointTorqueOrForce() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointTorqueOrForce of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointTorqueOrForce jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointTorqueOrForce", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named getJointTorqueOrForce with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::getJointTorqueOrForce jthis=",t);
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
   void JointStatusType::setJointNumber(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointNumber of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointNumber jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointNumber", "(Ljava/math/BigInteger;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named setJointNumber with signature (Ljava/math/BigInteger;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointNumber jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void JointStatusType::setJointPosition(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointPosition of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointPosition jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointPosition", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named setJointPosition with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void JointStatusType::setJointVelocity(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointVelocity of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointVelocity jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointVelocity", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named setJointVelocity with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointVelocity jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void JointStatusType::setJointTorqueOrForce(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointTorqueOrForce of crcl.base.JointStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointTorqueOrForce jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointTorqueOrForce", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointStatusType has no method named setJointTorqueOrForce with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointStatusType::setJointTorqueOrForce jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewJointStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/JointStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/JointStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass JointStatusTypeClass = NULL;
   static inline jclass getJointStatusTypeClass() {
       if (JointStatusTypeClass != NULL) {
           return JointStatusTypeClass;
       }
       JointStatusTypeClass = getNewJointStatusTypeClass();
   }
   
   // get JNI handle for class crcl.base.MoveThroughToType
   static inline jclass getMoveThroughToTypeClass();
   
   MoveThroughToType::MoveThroughToType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   MoveThroughToType::MoveThroughToType(const MoveThroughToType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   MoveThroughToType::MoveThroughToType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getMoveThroughToTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class MoveThroughToType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::setJointTorqueOrForce jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new MoveThroughToType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MoveThroughToType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.MoveThroughToType
   MoveThroughToType::~MoveThroughToType() {
   	// Place-holder for later extensibility.
   }

   jboolean MoveThroughToType::isMoveStraight() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMoveStraight of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::isMoveStraight jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMoveStraight", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveThroughToType has no method named isMoveStraight with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::isMoveStraight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void MoveThroughToType::setMoveStraight(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setMoveStraight of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::setMoveStraight jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setMoveStraight", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveThroughToType has no method named setMoveStraight with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::setMoveStraight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::util::List MoveThroughToType::getWaypoint() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getWaypoint of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::getWaypoint jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getWaypoint", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveThroughToType has no method named getWaypoint with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::getWaypoint jthis=",t);
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
   ::crclj::java::math::BigInteger MoveThroughToType::getNumPositions() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getNumPositions of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::getNumPositions jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getNumPositions", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveThroughToType has no method named getNumPositions with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::getNumPositions jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::math::BigInteger retObject(retVal,false);
    return retObject;
   }
   void MoveThroughToType::setNumPositions(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setNumPositions of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::setNumPositions jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setNumPositions", "(Ljava/math/BigInteger;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveThroughToType has no method named setNumPositions with signature (Ljava/math/BigInteger;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveThroughToType::setNumPositions jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewMoveThroughToTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/MoveThroughToType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/MoveThroughToType" << std::endl;
       }
       return clss;
   }
   
   static jclass MoveThroughToTypeClass = NULL;
   static inline jclass getMoveThroughToTypeClass() {
       if (MoveThroughToTypeClass != NULL) {
           return MoveThroughToTypeClass;
       }
       MoveThroughToTypeClass = getNewMoveThroughToTypeClass();
   }
  } // end namespace base

   namespace utils{
   
   // get JNI handle for class crcl.utils.TestInstance
   static inline jclass getTestInstanceClass();
   
   TestInstance::TestInstance(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   TestInstance::TestInstance(const TestInstance &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   TestInstance::TestInstance() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getTestInstanceClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class TestInstance has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," TestInstance::setNumPositions jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new TestInstance with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TestInstance jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.TestInstance
   TestInstance::~TestInstance() {
   	// Place-holder for later extensibility.
   }

   void TestInstance::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getTestInstanceClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.TestInstance has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TestInstance::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void TestInstance::main(int argc, const char **argv) {
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
   static jclass getNewTestInstanceClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/TestInstance");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/TestInstance" << std::endl;
       }
       return clss;
   }
   
   static jclass TestInstanceClass = NULL;
   static inline jclass getTestInstanceClass() {
       if (TestInstanceClass != NULL) {
           return TestInstanceClass;
       }
       TestInstanceClass = getNewTestInstanceClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

