
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.MoveScrewType
   static inline jclass getMoveScrewTypeClass();
   
   MoveScrewType::MoveScrewType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   MoveScrewType::MoveScrewType(const MoveScrewType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   MoveScrewType::MoveScrewType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getMoveScrewTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class MoveScrewType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setGripperStatus jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new MoveScrewType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MoveScrewType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.MoveScrewType
   MoveScrewType::~MoveScrewType() {
   	// Place-holder for later extensibility.
   }

   PoseType MoveScrewType::getStartPosition() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStartPosition of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getStartPosition jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStartPosition", "()Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named getStartPosition with signature ()Lcrcl/base/PoseType;." << std::endl;
           PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getStartPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseType retObject(retVal,false);
    return retObject;
   }
   void MoveScrewType::setStartPosition(PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStartPosition of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setStartPosition jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStartPosition", "(Lcrcl/base/PoseType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named setStartPosition with signature (Lcrcl/base/PoseType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setStartPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PointType MoveScrewType::getAxisPoint() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAxisPoint of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       PointType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getAxisPoint jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getAxisPoint", "()Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named getAxisPoint with signature ()Lcrcl/base/PointType;." << std::endl;
           PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getAxisPoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PointType retObject(retVal,false);
    return retObject;
   }
   void MoveScrewType::setAxisPoint(PointType  &pointType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setAxisPoint of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setAxisPoint jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setAxisPoint", "(Lcrcl/base/PointType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named setAxisPoint with signature (Lcrcl/base/PointType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,pointType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setAxisPoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal MoveScrewType::getAxialDistanceFree() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAxialDistanceFree of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getAxialDistanceFree jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getAxialDistanceFree", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named getAxialDistanceFree with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getAxialDistanceFree jthis=",t);
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
   void MoveScrewType::setAxialDistanceFree(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setAxialDistanceFree of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setAxialDistanceFree jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setAxialDistanceFree", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named setAxialDistanceFree with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setAxialDistanceFree jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal MoveScrewType::getAxialDistanceScrew() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAxialDistanceScrew of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getAxialDistanceScrew jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getAxialDistanceScrew", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named getAxialDistanceScrew with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getAxialDistanceScrew jthis=",t);
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
   void MoveScrewType::setAxialDistanceScrew(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setAxialDistanceScrew of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setAxialDistanceScrew jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setAxialDistanceScrew", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named setAxialDistanceScrew with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setAxialDistanceScrew jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal MoveScrewType::getTurn() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTurn of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getTurn jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTurn", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named getTurn with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::getTurn jthis=",t);
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
   void MoveScrewType::setTurn(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTurn of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setTurn jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTurn", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveScrewType has no method named setTurn with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveScrewType::setTurn jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewMoveScrewTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/MoveScrewType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/MoveScrewType" << std::endl;
       }
       return clss;
   }
   
   static jclass MoveScrewTypeClass = NULL;
   static inline jclass getMoveScrewTypeClass() {
       if (MoveScrewTypeClass != NULL) {
           return MoveScrewTypeClass;
       }
       MoveScrewTypeClass = getNewMoveScrewTypeClass();
   }
   
   // get JNI handle for class crcl.base.MoveToType
   static inline jclass getMoveToTypeClass();
   
   MoveToType::MoveToType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   MoveToType::MoveToType(const MoveToType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   MoveToType::MoveToType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getMoveToTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class MoveToType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," MoveToType::setTurn jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new MoveToType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MoveToType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.MoveToType
   MoveToType::~MoveToType() {
   	// Place-holder for later extensibility.
   }

   jboolean MoveToType::isMoveStraight() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMoveStraight of crcl.base.MoveToType with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveToType::isMoveStraight jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMoveStraight", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveToType has no method named isMoveStraight with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveToType::isMoveStraight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void MoveToType::setMoveStraight(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setMoveStraight of crcl.base.MoveToType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveToType::setMoveStraight jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setMoveStraight", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveToType has no method named setMoveStraight with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveToType::setMoveStraight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PoseType MoveToType::getEndPosition() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getEndPosition of crcl.base.MoveToType with jthis == NULL." << std::endl;
       PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveToType::getEndPosition jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getEndPosition", "()Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveToType has no method named getEndPosition with signature ()Lcrcl/base/PoseType;." << std::endl;
           PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveToType::getEndPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseType retObject(retVal,false);
    return retObject;
   }
   void MoveToType::setEndPosition(PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setEndPosition of crcl.base.MoveToType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MoveToType::setEndPosition jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setEndPosition", "(Lcrcl/base/PoseType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MoveToType has no method named setEndPosition with signature (Lcrcl/base/PoseType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MoveToType::setEndPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewMoveToTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/MoveToType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/MoveToType" << std::endl;
       }
       return clss;
   }
   
   static jclass MoveToTypeClass = NULL;
   static inline jclass getMoveToTypeClass() {
       if (MoveToTypeClass != NULL) {
           return MoveToTypeClass;
       }
       MoveToTypeClass = getNewMoveToTypeClass();
   }
   
   // get JNI handle for class crcl.base.ObjectFactory
   static inline jclass getObjectFactoryClass();
   
   ObjectFactory::ObjectFactory(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ObjectFactory::ObjectFactory(const ObjectFactory &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ObjectFactory::ObjectFactory() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getObjectFactoryClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ObjectFactory has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::setEndPosition jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ObjectFactory with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ObjectFactory jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.ObjectFactory
   ObjectFactory::~ObjectFactory() {
   	// Place-holder for later extensibility.
   }

   ::crclj::javax::xml::bind::JAXBElement ObjectFactory::createCRCLStatus(CRCLStatusType  &cRCLStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCRCLStatus of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ::crclj::javax::xml::bind::JAXBElement nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCRCLStatus", "(Lcrcl/base/CRCLStatusType;)Ljavax/xml/bind/JAXBElement;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLStatus with signature (Lcrcl/base/CRCLStatusType;)Ljavax/xml/bind/JAXBElement;." << std::endl;
           ::crclj::javax::xml::bind::JAXBElement nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::bind::JAXBElement retObject(retVal,false);
    return retObject;
   }
   ::crclj::javax::xml::bind::JAXBElement ObjectFactory::createCRCLCommandInstance(CRCLCommandInstanceType  &cRCLCommandInstanceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCRCLCommandInstance of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ::crclj::javax::xml::bind::JAXBElement nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLCommandInstance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCRCLCommandInstance", "(Lcrcl/base/CRCLCommandInstanceType;)Ljavax/xml/bind/JAXBElement;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLCommandInstance with signature (Lcrcl/base/CRCLCommandInstanceType;)Ljavax/xml/bind/JAXBElement;." << std::endl;
           ::crclj::javax::xml::bind::JAXBElement nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,cRCLCommandInstanceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLCommandInstance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::bind::JAXBElement retObject(retVal,false);
    return retObject;
   }
   ::crclj::javax::xml::bind::JAXBElement ObjectFactory::createCRCLProgram(CRCLProgramType  &cRCLProgramType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCRCLProgram of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ::crclj::javax::xml::bind::JAXBElement nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLProgram jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCRCLProgram", "(Lcrcl/base/CRCLProgramType;)Ljavax/xml/bind/JAXBElement;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLProgram with signature (Lcrcl/base/CRCLProgramType;)Ljavax/xml/bind/JAXBElement;." << std::endl;
           ::crclj::javax::xml::bind::JAXBElement nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,cRCLProgramType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::bind::JAXBElement retObject(retVal,false);
    return retObject;
   }
   CRCLProgramType ObjectFactory::createCRCLProgramType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCRCLProgramType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLProgramType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCRCLProgramType", "()Lcrcl/base/CRCLProgramType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLProgramType with signature ()Lcrcl/base/CRCLProgramType;." << std::endl;
           CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLProgramType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CRCLProgramType retObject(retVal,false);
    return retObject;
   }
   CRCLCommandInstanceType ObjectFactory::createCRCLCommandInstanceType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCRCLCommandInstanceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLCommandInstanceType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCRCLCommandInstanceType", "()Lcrcl/base/CRCLCommandInstanceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLCommandInstanceType with signature ()Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
           CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLCommandInstanceType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CRCLCommandInstanceType retObject(retVal,false);
    return retObject;
   }
   CRCLStatusType ObjectFactory::createCRCLStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCRCLStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCRCLStatusType", "()Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLStatusType with signature ()Lcrcl/base/CRCLStatusType;." << std::endl;
           CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCRCLStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CRCLStatusType retObject(retVal,false);
    return retObject;
   }
   PointType ObjectFactory::createPointType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createPointType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       PointType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPointType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createPointType", "()Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createPointType with signature ()Lcrcl/base/PointType;." << std::endl;
           PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPointType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PointType retObject(retVal,false);
    return retObject;
   }
   PoseType ObjectFactory::createPoseType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createPoseType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPoseType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createPoseType", "()Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createPoseType with signature ()Lcrcl/base/PoseType;." << std::endl;
           PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPoseType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseType retObject(retVal,false);
    return retObject;
   }
   VectorType ObjectFactory::createVectorType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createVectorType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       VectorType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createVectorType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createVectorType", "()Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createVectorType with signature ()Lcrcl/base/VectorType;." << std::endl;
           VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createVectorType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    VectorType retObject(retVal,false);
    return retObject;
   }
   ActuateJointsType ObjectFactory::createActuateJointsType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createActuateJointsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ActuateJointsType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createActuateJointsType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createActuateJointsType", "()Lcrcl/base/ActuateJointsType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createActuateJointsType with signature ()Lcrcl/base/ActuateJointsType;." << std::endl;
           ActuateJointsType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createActuateJointsType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ActuateJointsType retObject(retVal,false);
    return retObject;
   }
   ActuateJointType ObjectFactory::createActuateJointType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createActuateJointType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ActuateJointType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createActuateJointType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createActuateJointType", "()Lcrcl/base/ActuateJointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createActuateJointType with signature ()Lcrcl/base/ActuateJointType;." << std::endl;
           ActuateJointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createActuateJointType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ActuateJointType retObject(retVal,false);
    return retObject;
   }
   CloseToolChangerType ObjectFactory::createCloseToolChangerType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCloseToolChangerType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       CloseToolChangerType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCloseToolChangerType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCloseToolChangerType", "()Lcrcl/base/CloseToolChangerType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCloseToolChangerType with signature ()Lcrcl/base/CloseToolChangerType;." << std::endl;
           CloseToolChangerType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCloseToolChangerType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CloseToolChangerType retObject(retVal,false);
    return retObject;
   }
   DwellType ObjectFactory::createDwellType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createDwellType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       DwellType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createDwellType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createDwellType", "()Lcrcl/base/DwellType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createDwellType with signature ()Lcrcl/base/DwellType;." << std::endl;
           DwellType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createDwellType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    DwellType retObject(retVal,false);
    return retObject;
   }
   ConfigureJointReportsType ObjectFactory::createConfigureJointReportsType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createConfigureJointReportsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ConfigureJointReportsType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createConfigureJointReportsType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createConfigureJointReportsType", "()Lcrcl/base/ConfigureJointReportsType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createConfigureJointReportsType with signature ()Lcrcl/base/ConfigureJointReportsType;." << std::endl;
           ConfigureJointReportsType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createConfigureJointReportsType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ConfigureJointReportsType retObject(retVal,false);
    return retObject;
   }
   ConfigureJointReportType ObjectFactory::createConfigureJointReportType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createConfigureJointReportType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ConfigureJointReportType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createConfigureJointReportType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createConfigureJointReportType", "()Lcrcl/base/ConfigureJointReportType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createConfigureJointReportType with signature ()Lcrcl/base/ConfigureJointReportType;." << std::endl;
           ConfigureJointReportType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createConfigureJointReportType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ConfigureJointReportType retObject(retVal,false);
    return retObject;
   }
   EndCanonType ObjectFactory::createEndCanonType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createEndCanonType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       EndCanonType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createEndCanonType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createEndCanonType", "()Lcrcl/base/EndCanonType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createEndCanonType with signature ()Lcrcl/base/EndCanonType;." << std::endl;
           EndCanonType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createEndCanonType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    EndCanonType retObject(retVal,false);
    return retObject;
   }
   GetStatusType ObjectFactory::createGetStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createGetStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       GetStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createGetStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createGetStatusType", "()Lcrcl/base/GetStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createGetStatusType with signature ()Lcrcl/base/GetStatusType;." << std::endl;
           GetStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createGetStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    GetStatusType retObject(retVal,false);
    return retObject;
   }
   InitCanonType ObjectFactory::createInitCanonType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createInitCanonType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       InitCanonType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createInitCanonType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createInitCanonType", "()Lcrcl/base/InitCanonType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createInitCanonType with signature ()Lcrcl/base/InitCanonType;." << std::endl;
           InitCanonType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createInitCanonType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    InitCanonType retObject(retVal,false);
    return retObject;
   }
   JointForceTorqueType ObjectFactory::createJointForceTorqueType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createJointForceTorqueType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       JointForceTorqueType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointForceTorqueType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createJointForceTorqueType", "()Lcrcl/base/JointForceTorqueType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createJointForceTorqueType with signature ()Lcrcl/base/JointForceTorqueType;." << std::endl;
           JointForceTorqueType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointForceTorqueType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    JointForceTorqueType retObject(retVal,false);
    return retObject;
   }
   JointSpeedAccelType ObjectFactory::createJointSpeedAccelType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createJointSpeedAccelType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       JointSpeedAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointSpeedAccelType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createJointSpeedAccelType", "()Lcrcl/base/JointSpeedAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createJointSpeedAccelType with signature ()Lcrcl/base/JointSpeedAccelType;." << std::endl;
           JointSpeedAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointSpeedAccelType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    JointSpeedAccelType retObject(retVal,false);
    return retObject;
   }
   MessageType ObjectFactory::createMessageType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createMessageType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       MessageType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMessageType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createMessageType", "()Lcrcl/base/MessageType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createMessageType with signature ()Lcrcl/base/MessageType;." << std::endl;
           MessageType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMessageType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    MessageType retObject(retVal,false);
    return retObject;
   }
   MoveScrewType ObjectFactory::createMoveScrewType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createMoveScrewType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       MoveScrewType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMoveScrewType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createMoveScrewType", "()Lcrcl/base/MoveScrewType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createMoveScrewType with signature ()Lcrcl/base/MoveScrewType;." << std::endl;
           MoveScrewType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMoveScrewType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    MoveScrewType retObject(retVal,false);
    return retObject;
   }
   MoveThroughToType ObjectFactory::createMoveThroughToType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createMoveThroughToType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       MoveThroughToType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMoveThroughToType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createMoveThroughToType", "()Lcrcl/base/MoveThroughToType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createMoveThroughToType with signature ()Lcrcl/base/MoveThroughToType;." << std::endl;
           MoveThroughToType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMoveThroughToType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    MoveThroughToType retObject(retVal,false);
    return retObject;
   }
   MoveToType ObjectFactory::createMoveToType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createMoveToType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       MoveToType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMoveToType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createMoveToType", "()Lcrcl/base/MoveToType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createMoveToType with signature ()Lcrcl/base/MoveToType;." << std::endl;
           MoveToType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createMoveToType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    MoveToType retObject(retVal,false);
    return retObject;
   }
   OpenToolChangerType ObjectFactory::createOpenToolChangerType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createOpenToolChangerType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       OpenToolChangerType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createOpenToolChangerType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createOpenToolChangerType", "()Lcrcl/base/OpenToolChangerType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createOpenToolChangerType with signature ()Lcrcl/base/OpenToolChangerType;." << std::endl;
           OpenToolChangerType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createOpenToolChangerType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    OpenToolChangerType retObject(retVal,false);
    return retObject;
   }
   ParameterSettingType ObjectFactory::createParameterSettingType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createParameterSettingType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ParameterSettingType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createParameterSettingType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createParameterSettingType", "()Lcrcl/base/ParameterSettingType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createParameterSettingType with signature ()Lcrcl/base/ParameterSettingType;." << std::endl;
           ParameterSettingType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createParameterSettingType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ParameterSettingType retObject(retVal,false);
    return retObject;
   }
   PoseAndSetType ObjectFactory::createPoseAndSetType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createPoseAndSetType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       PoseAndSetType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPoseAndSetType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createPoseAndSetType", "()Lcrcl/base/PoseAndSetType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createPoseAndSetType with signature ()Lcrcl/base/PoseAndSetType;." << std::endl;
           PoseAndSetType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPoseAndSetType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseAndSetType retObject(retVal,false);
    return retObject;
   }
   PoseToleranceType ObjectFactory::createPoseToleranceType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createPoseToleranceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPoseToleranceType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createPoseToleranceType", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createPoseToleranceType with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createPoseToleranceType jthis=",t);
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
   RotAccelAbsoluteType ObjectFactory::createRotAccelAbsoluteType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createRotAccelAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       RotAccelAbsoluteType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotAccelAbsoluteType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createRotAccelAbsoluteType", "()Lcrcl/base/RotAccelAbsoluteType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createRotAccelAbsoluteType with signature ()Lcrcl/base/RotAccelAbsoluteType;." << std::endl;
           RotAccelAbsoluteType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotAccelAbsoluteType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RotAccelAbsoluteType retObject(retVal,false);
    return retObject;
   }
   RotAccelRelativeType ObjectFactory::createRotAccelRelativeType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createRotAccelRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       RotAccelRelativeType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotAccelRelativeType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createRotAccelRelativeType", "()Lcrcl/base/RotAccelRelativeType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createRotAccelRelativeType with signature ()Lcrcl/base/RotAccelRelativeType;." << std::endl;
           RotAccelRelativeType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotAccelRelativeType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RotAccelRelativeType retObject(retVal,false);
    return retObject;
   }
   RotSpeedAbsoluteType ObjectFactory::createRotSpeedAbsoluteType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createRotSpeedAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       RotSpeedAbsoluteType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotSpeedAbsoluteType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createRotSpeedAbsoluteType", "()Lcrcl/base/RotSpeedAbsoluteType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createRotSpeedAbsoluteType with signature ()Lcrcl/base/RotSpeedAbsoluteType;." << std::endl;
           RotSpeedAbsoluteType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotSpeedAbsoluteType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RotSpeedAbsoluteType retObject(retVal,false);
    return retObject;
   }
   RotSpeedRelativeType ObjectFactory::createRotSpeedRelativeType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createRotSpeedRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       RotSpeedRelativeType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotSpeedRelativeType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createRotSpeedRelativeType", "()Lcrcl/base/RotSpeedRelativeType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createRotSpeedRelativeType with signature ()Lcrcl/base/RotSpeedRelativeType;." << std::endl;
           RotSpeedRelativeType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRotSpeedRelativeType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RotSpeedRelativeType retObject(retVal,false);
    return retObject;
   }
   RunProgramType ObjectFactory::createRunProgramType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createRunProgramType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       RunProgramType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRunProgramType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createRunProgramType", "()Lcrcl/base/RunProgramType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createRunProgramType with signature ()Lcrcl/base/RunProgramType;." << std::endl;
           RunProgramType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createRunProgramType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RunProgramType retObject(retVal,false);
    return retObject;
   }
   SetAngleUnitsType ObjectFactory::createSetAngleUnitsType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetAngleUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetAngleUnitsType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetAngleUnitsType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetAngleUnitsType", "()Lcrcl/base/SetAngleUnitsType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetAngleUnitsType with signature ()Lcrcl/base/SetAngleUnitsType;." << std::endl;
           SetAngleUnitsType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetAngleUnitsType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetAngleUnitsType retObject(retVal,false);
    return retObject;
   }
   SetEndEffectorParametersType ObjectFactory::createSetEndEffectorParametersType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetEndEffectorParametersType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetEndEffectorParametersType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetEndEffectorParametersType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetEndEffectorParametersType", "()Lcrcl/base/SetEndEffectorParametersType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetEndEffectorParametersType with signature ()Lcrcl/base/SetEndEffectorParametersType;." << std::endl;
           SetEndEffectorParametersType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetEndEffectorParametersType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetEndEffectorParametersType retObject(retVal,false);
    return retObject;
   }
   SetEndEffectorType ObjectFactory::createSetEndEffectorType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetEndEffectorType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetEndEffectorType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetEndEffectorType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetEndEffectorType", "()Lcrcl/base/SetEndEffectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetEndEffectorType with signature ()Lcrcl/base/SetEndEffectorType;." << std::endl;
           SetEndEffectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetEndEffectorType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetEndEffectorType retObject(retVal,false);
    return retObject;
   }
   SetEndPoseToleranceType ObjectFactory::createSetEndPoseToleranceType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetEndPoseToleranceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetEndPoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetEndPoseToleranceType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetEndPoseToleranceType", "()Lcrcl/base/SetEndPoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetEndPoseToleranceType with signature ()Lcrcl/base/SetEndPoseToleranceType;." << std::endl;
           SetEndPoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetEndPoseToleranceType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetEndPoseToleranceType retObject(retVal,false);
    return retObject;
   }
   SetForceUnitsType ObjectFactory::createSetForceUnitsType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetForceUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetForceUnitsType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetForceUnitsType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetForceUnitsType", "()Lcrcl/base/SetForceUnitsType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetForceUnitsType with signature ()Lcrcl/base/SetForceUnitsType;." << std::endl;
           SetForceUnitsType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetForceUnitsType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetForceUnitsType retObject(retVal,false);
    return retObject;
   }
   SetIntermediatePoseToleranceType ObjectFactory::createSetIntermediatePoseToleranceType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetIntermediatePoseToleranceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetIntermediatePoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetIntermediatePoseToleranceType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetIntermediatePoseToleranceType", "()Lcrcl/base/SetIntermediatePoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetIntermediatePoseToleranceType with signature ()Lcrcl/base/SetIntermediatePoseToleranceType;." << std::endl;
           SetIntermediatePoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetIntermediatePoseToleranceType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetIntermediatePoseToleranceType retObject(retVal,false);
    return retObject;
   }
   SetLengthUnitsType ObjectFactory::createSetLengthUnitsType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetLengthUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetLengthUnitsType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetLengthUnitsType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetLengthUnitsType", "()Lcrcl/base/SetLengthUnitsType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetLengthUnitsType with signature ()Lcrcl/base/SetLengthUnitsType;." << std::endl;
           SetLengthUnitsType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetLengthUnitsType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetLengthUnitsType retObject(retVal,false);
    return retObject;
   }
   SetMotionCoordinationType ObjectFactory::createSetMotionCoordinationType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetMotionCoordinationType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetMotionCoordinationType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetMotionCoordinationType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetMotionCoordinationType", "()Lcrcl/base/SetMotionCoordinationType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetMotionCoordinationType with signature ()Lcrcl/base/SetMotionCoordinationType;." << std::endl;
           SetMotionCoordinationType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetMotionCoordinationType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetMotionCoordinationType retObject(retVal,false);
    return retObject;
   }
   SetRobotParametersType ObjectFactory::createSetRobotParametersType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetRobotParametersType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetRobotParametersType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetRobotParametersType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetRobotParametersType", "()Lcrcl/base/SetRobotParametersType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetRobotParametersType with signature ()Lcrcl/base/SetRobotParametersType;." << std::endl;
           SetRobotParametersType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetRobotParametersType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetRobotParametersType retObject(retVal,false);
    return retObject;
   }
   SetRotAccelType ObjectFactory::createSetRotAccelType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetRotAccelType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetRotAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetRotAccelType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetRotAccelType", "()Lcrcl/base/SetRotAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetRotAccelType with signature ()Lcrcl/base/SetRotAccelType;." << std::endl;
           SetRotAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetRotAccelType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetRotAccelType retObject(retVal,false);
    return retObject;
   }
   SetRotSpeedType ObjectFactory::createSetRotSpeedType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetRotSpeedType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetRotSpeedType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetRotSpeedType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetRotSpeedType", "()Lcrcl/base/SetRotSpeedType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetRotSpeedType with signature ()Lcrcl/base/SetRotSpeedType;." << std::endl;
           SetRotSpeedType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetRotSpeedType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetRotSpeedType retObject(retVal,false);
    return retObject;
   }
   SetTorqueUnitsType ObjectFactory::createSetTorqueUnitsType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetTorqueUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetTorqueUnitsType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetTorqueUnitsType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetTorqueUnitsType", "()Lcrcl/base/SetTorqueUnitsType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetTorqueUnitsType with signature ()Lcrcl/base/SetTorqueUnitsType;." << std::endl;
           SetTorqueUnitsType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetTorqueUnitsType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetTorqueUnitsType retObject(retVal,false);
    return retObject;
   }
   SetTransAccelType ObjectFactory::createSetTransAccelType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetTransAccelType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetTransAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetTransAccelType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetTransAccelType", "()Lcrcl/base/SetTransAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetTransAccelType with signature ()Lcrcl/base/SetTransAccelType;." << std::endl;
           SetTransAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetTransAccelType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetTransAccelType retObject(retVal,false);
    return retObject;
   }
   SetTransSpeedType ObjectFactory::createSetTransSpeedType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createSetTransSpeedType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       SetTransSpeedType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetTransSpeedType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createSetTransSpeedType", "()Lcrcl/base/SetTransSpeedType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createSetTransSpeedType with signature ()Lcrcl/base/SetTransSpeedType;." << std::endl;
           SetTransSpeedType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createSetTransSpeedType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    SetTransSpeedType retObject(retVal,false);
    return retObject;
   }
   StopMotionType ObjectFactory::createStopMotionType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createStopMotionType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       StopMotionType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createStopMotionType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createStopMotionType", "()Lcrcl/base/StopMotionType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createStopMotionType with signature ()Lcrcl/base/StopMotionType;." << std::endl;
           StopMotionType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createStopMotionType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    StopMotionType retObject(retVal,false);
    return retObject;
   }
   TransAccelAbsoluteType ObjectFactory::createTransAccelAbsoluteType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createTransAccelAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       TransAccelAbsoluteType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransAccelAbsoluteType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createTransAccelAbsoluteType", "()Lcrcl/base/TransAccelAbsoluteType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createTransAccelAbsoluteType with signature ()Lcrcl/base/TransAccelAbsoluteType;." << std::endl;
           TransAccelAbsoluteType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransAccelAbsoluteType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    TransAccelAbsoluteType retObject(retVal,false);
    return retObject;
   }
   TransAccelRelativeType ObjectFactory::createTransAccelRelativeType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createTransAccelRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       TransAccelRelativeType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransAccelRelativeType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createTransAccelRelativeType", "()Lcrcl/base/TransAccelRelativeType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createTransAccelRelativeType with signature ()Lcrcl/base/TransAccelRelativeType;." << std::endl;
           TransAccelRelativeType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransAccelRelativeType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    TransAccelRelativeType retObject(retVal,false);
    return retObject;
   }
   TransSpeedAbsoluteType ObjectFactory::createTransSpeedAbsoluteType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createTransSpeedAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       TransSpeedAbsoluteType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransSpeedAbsoluteType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createTransSpeedAbsoluteType", "()Lcrcl/base/TransSpeedAbsoluteType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createTransSpeedAbsoluteType with signature ()Lcrcl/base/TransSpeedAbsoluteType;." << std::endl;
           TransSpeedAbsoluteType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransSpeedAbsoluteType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    TransSpeedAbsoluteType retObject(retVal,false);
    return retObject;
   }
   TransSpeedRelativeType ObjectFactory::createTransSpeedRelativeType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createTransSpeedRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       TransSpeedRelativeType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransSpeedRelativeType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createTransSpeedRelativeType", "()Lcrcl/base/TransSpeedRelativeType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createTransSpeedRelativeType with signature ()Lcrcl/base/TransSpeedRelativeType;." << std::endl;
           TransSpeedRelativeType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createTransSpeedRelativeType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    TransSpeedRelativeType retObject(retVal,false);
    return retObject;
   }
   CommandStatusType ObjectFactory::createCommandStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createCommandStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       CommandStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCommandStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createCommandStatusType", "()Lcrcl/base/CommandStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createCommandStatusType with signature ()Lcrcl/base/CommandStatusType;." << std::endl;
           CommandStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createCommandStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CommandStatusType retObject(retVal,false);
    return retObject;
   }
   JointStatusesType ObjectFactory::createJointStatusesType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createJointStatusesType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       JointStatusesType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointStatusesType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createJointStatusesType", "()Lcrcl/base/JointStatusesType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createJointStatusesType with signature ()Lcrcl/base/JointStatusesType;." << std::endl;
           JointStatusesType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointStatusesType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    JointStatusesType retObject(retVal,false);
    return retObject;
   }
   JointStatusType ObjectFactory::createJointStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createJointStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       JointStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createJointStatusType", "()Lcrcl/base/JointStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createJointStatusType with signature ()Lcrcl/base/JointStatusType;." << std::endl;
           JointStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createJointStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    JointStatusType retObject(retVal,false);
    return retObject;
   }
   ParallelGripperStatusType ObjectFactory::createParallelGripperStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createParallelGripperStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ParallelGripperStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createParallelGripperStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createParallelGripperStatusType", "()Lcrcl/base/ParallelGripperStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createParallelGripperStatusType with signature ()Lcrcl/base/ParallelGripperStatusType;." << std::endl;
           ParallelGripperStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createParallelGripperStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ParallelGripperStatusType retObject(retVal,false);
    return retObject;
   }
   ThreeFingerGripperStatusType ObjectFactory::createThreeFingerGripperStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createThreeFingerGripperStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       ThreeFingerGripperStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createThreeFingerGripperStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createThreeFingerGripperStatusType", "()Lcrcl/base/ThreeFingerGripperStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createThreeFingerGripperStatusType with signature ()Lcrcl/base/ThreeFingerGripperStatusType;." << std::endl;
           ThreeFingerGripperStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createThreeFingerGripperStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ThreeFingerGripperStatusType retObject(retVal,false);
    return retObject;
   }
   VacuumGripperStatusType ObjectFactory::createVacuumGripperStatusType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createVacuumGripperStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
       VacuumGripperStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createVacuumGripperStatusType jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createVacuumGripperStatusType", "()Lcrcl/base/VacuumGripperStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ObjectFactory has no method named createVacuumGripperStatusType with signature ()Lcrcl/base/VacuumGripperStatusType;." << std::endl;
           VacuumGripperStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjectFactory::createVacuumGripperStatusType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    VacuumGripperStatusType retObject(retVal,false);
    return retObject;
   }
   static jclass getNewObjectFactoryClass() {
       jclass clss = getEnv()->FindClass("crcl/base/ObjectFactory");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/ObjectFactory" << std::endl;
       }
       return clss;
   }
   
   static jclass ObjectFactoryClass = NULL;
   static inline jclass getObjectFactoryClass() {
       if (ObjectFactoryClass != NULL) {
           return ObjectFactoryClass;
       }
       ObjectFactoryClass = getNewObjectFactoryClass();
   }
   
   // get JNI handle for class crcl.base.PoseType
   static inline jclass getPoseTypeClass();
   
   PoseType::PoseType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PoseType::PoseType(const PoseType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PoseType::PoseType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPoseTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PoseType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PoseType::createVacuumGripperStatusType jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PoseType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PoseType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.PoseType
   PoseType::~PoseType() {
   	// Place-holder for later extensibility.
   }

   PointType PoseType::getPoint() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPoint of crcl.base.PoseType with jthis == NULL." << std::endl;
       PointType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseType::getPoint jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPoint", "()Lcrcl/base/PointType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseType has no method named getPoint with signature ()Lcrcl/base/PointType;." << std::endl;
           PointType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseType::getPoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PointType retObject(retVal,false);
    return retObject;
   }
   VectorType PoseType::getXAxis() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getXAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
       VectorType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseType::getXAxis jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getXAxis", "()Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseType has no method named getXAxis with signature ()Lcrcl/base/VectorType;." << std::endl;
           VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseType::getXAxis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    VectorType retObject(retVal,false);
    return retObject;
   }
   VectorType PoseType::getZAxis() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getZAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
       VectorType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseType::getZAxis jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getZAxis", "()Lcrcl/base/VectorType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseType has no method named getZAxis with signature ()Lcrcl/base/VectorType;." << std::endl;
           VectorType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseType::getZAxis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    VectorType retObject(retVal,false);
    return retObject;
   }
   void PoseType::setPoint(PointType  &pointType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setPoint of crcl.base.PoseType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseType::setPoint jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setPoint", "(Lcrcl/base/PointType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseType has no method named setPoint with signature (Lcrcl/base/PointType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,pointType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseType::setPoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PoseType::setXAxis(VectorType  &vectorType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setXAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseType::setXAxis jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setXAxis", "(Lcrcl/base/VectorType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseType has no method named setXAxis with signature (Lcrcl/base/VectorType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,vectorType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseType::setXAxis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PoseType::setZAxis(VectorType  &vectorType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setZAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseType::setZAxis jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setZAxis", "(Lcrcl/base/VectorType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseType has no method named setZAxis with signature (Lcrcl/base/VectorType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,vectorType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseType::setZAxis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewPoseTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/PoseType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/PoseType" << std::endl;
       }
       return clss;
   }
   
   static jclass PoseTypeClass = NULL;
   static inline jclass getPoseTypeClass() {
       if (PoseTypeClass != NULL) {
           return PoseTypeClass;
       }
       PoseTypeClass = getNewPoseTypeClass();
   }
   
   // get JNI handle for class crcl.base.PoseAndSetType
   static inline jclass getPoseAndSetTypeClass();
   
   PoseAndSetType::PoseAndSetType(jobject _jthis, bool copy): PoseType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PoseAndSetType::PoseAndSetType(const PoseAndSetType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PoseAndSetType::PoseAndSetType() : PoseType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPoseAndSetTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PoseAndSetType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setZAxis jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PoseAndSetType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PoseAndSetType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.PoseAndSetType
   PoseAndSetType::~PoseAndSetType() {
   	// Place-holder for later extensibility.
   }

   void PoseAndSetType::setTolerance(PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTolerance of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named setTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PoseToleranceType PoseAndSetType::getTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTolerance of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named getTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getTolerance jthis=",t);
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
   jboolean PoseAndSetType::isCoordinated() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isCoordinated of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::isCoordinated jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isCoordinated", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named isCoordinated with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::isCoordinated jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PoseAndSetType::setCoordinated(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCoordinated of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setCoordinated jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCoordinated", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named setCoordinated with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setCoordinated jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   TransSpeedType PoseAndSetType::getTransSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTransSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       TransSpeedType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getTransSpeed jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTransSpeed", "()Lcrcl/base/TransSpeedType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named getTransSpeed with signature ()Lcrcl/base/TransSpeedType;." << std::endl;
           TransSpeedType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    TransSpeedType retObject(retVal,false);
    return retObject;
   }
   void PoseAndSetType::setTransSpeed(TransSpeedType  &transSpeedType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTransSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setTransSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTransSpeed", "(Lcrcl/base/TransSpeedType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named setTransSpeed with signature (Lcrcl/base/TransSpeedType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,transSpeedType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   RotSpeedType PoseAndSetType::getRotSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getRotSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       RotSpeedType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getRotSpeed jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getRotSpeed", "()Lcrcl/base/RotSpeedType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named getRotSpeed with signature ()Lcrcl/base/RotSpeedType;." << std::endl;
           RotSpeedType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getRotSpeed jthis=",t);
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
   void PoseAndSetType::setRotSpeed(RotSpeedType  &rotSpeedType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setRotSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setRotSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setRotSpeed", "(Lcrcl/base/RotSpeedType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named setRotSpeed with signature (Lcrcl/base/RotSpeedType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,rotSpeedType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   TransAccelType PoseAndSetType::getTransAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTransAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       TransAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getTransAccel jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTransAccel", "()Lcrcl/base/TransAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named getTransAccel with signature ()Lcrcl/base/TransAccelType;." << std::endl;
           TransAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getTransAccel jthis=",t);
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
   void PoseAndSetType::setTransAccel(TransAccelType  &transAccelType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTransAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setTransAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTransAccel", "(Lcrcl/base/TransAccelType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named setTransAccel with signature (Lcrcl/base/TransAccelType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,transAccelType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   RotAccelType PoseAndSetType::getRotAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getRotAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       RotAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getRotAccel jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getRotAccel", "()Lcrcl/base/RotAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named getRotAccel with signature ()Lcrcl/base/RotAccelType;." << std::endl;
           RotAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::getRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    RotAccelType retObject(retVal,false);
    return retObject;
   }
   void PoseAndSetType::setRotAccel(RotAccelType  &rotAccelType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setRotAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setRotAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setRotAccel", "(Lcrcl/base/RotAccelType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.PoseAndSetType has no method named setRotAccel with signature (Lcrcl/base/RotAccelType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,rotAccelType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PoseAndSetType::setRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewPoseAndSetTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/PoseAndSetType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/PoseAndSetType" << std::endl;
       }
       return clss;
   }
   
   static jclass PoseAndSetTypeClass = NULL;
   static inline jclass getPoseAndSetTypeClass() {
       if (PoseAndSetTypeClass != NULL) {
           return PoseAndSetTypeClass;
       }
       PoseAndSetTypeClass = getNewPoseAndSetTypeClass();
   }
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

