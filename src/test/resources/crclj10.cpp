
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.RotSpeedType
   static inline jclass getRotSpeedTypeClass();
   
   RotSpeedType::RotSpeedType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RotSpeedType::RotSpeedType(const RotSpeedType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RotSpeedType::RotSpeedType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRotSpeedTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RotSpeedType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RotSpeedType::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RotSpeedType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RotSpeedType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RotSpeedType
   RotSpeedType::~RotSpeedType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewRotSpeedTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RotSpeedType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RotSpeedType" << std::endl;
       }
       return clss;
   }
   
   static jclass RotSpeedTypeClass = NULL;
   static inline jclass getRotSpeedTypeClass() {
       if (RotSpeedTypeClass != NULL) {
           return RotSpeedTypeClass;
       }
       RotSpeedTypeClass = getNewRotSpeedTypeClass();
   }
   
   // get JNI handle for class crcl.base.GripperStatusType
   static inline jclass getGripperStatusTypeClass();
   
   GripperStatusType::GripperStatusType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   GripperStatusType::GripperStatusType(const GripperStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   GripperStatusType::GripperStatusType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getGripperStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class GripperStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," GripperStatusType::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new GripperStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new GripperStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.GripperStatusType
   GripperStatusType::~GripperStatusType() {
   	// Place-holder for later extensibility.
   }

   jstring GripperStatusType::getGripperName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getGripperName of crcl.base.GripperStatusType with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperStatusType::getGripperName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getGripperName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.GripperStatusType has no method named getGripperName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperStatusType::getGripperName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void GripperStatusType::setGripperName(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setGripperName of crcl.base.GripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperStatusType::setGripperName jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setGripperName", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.GripperStatusType has no method named setGripperName with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperStatusType::setGripperName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void GripperStatusType::setGripperName(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setGripperName of crcl.base.GripperStatusType with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperStatusType::setGripperName jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setGripperName(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   static jclass getNewGripperStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/GripperStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/GripperStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass GripperStatusTypeClass = NULL;
   static inline jclass getGripperStatusTypeClass() {
       if (GripperStatusTypeClass != NULL) {
           return GripperStatusTypeClass;
       }
       GripperStatusTypeClass = getNewGripperStatusTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetTransSpeedType
   static inline jclass getSetTransSpeedTypeClass();
   
   SetTransSpeedType::SetTransSpeedType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetTransSpeedType::SetTransSpeedType(const SetTransSpeedType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetTransSpeedType::SetTransSpeedType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetTransSpeedTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetTransSpeedType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetTransSpeedType::setGripperName jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetTransSpeedType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetTransSpeedType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetTransSpeedType
   SetTransSpeedType::~SetTransSpeedType() {
   	// Place-holder for later extensibility.
   }

   TransSpeedType SetTransSpeedType::getTransSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTransSpeed of crcl.base.SetTransSpeedType with jthis == NULL." << std::endl;
       TransSpeedType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetTransSpeedType::getTransSpeed jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTransSpeed", "()Lcrcl/base/TransSpeedType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetTransSpeedType has no method named getTransSpeed with signature ()Lcrcl/base/TransSpeedType;." << std::endl;
           TransSpeedType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetTransSpeedType::getTransSpeed jthis=",t);
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
   void SetTransSpeedType::setTransSpeed(TransSpeedType  &transSpeedType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTransSpeed of crcl.base.SetTransSpeedType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetTransSpeedType::setTransSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTransSpeed", "(Lcrcl/base/TransSpeedType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetTransSpeedType has no method named setTransSpeed with signature (Lcrcl/base/TransSpeedType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,transSpeedType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetTransSpeedType::setTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewSetTransSpeedTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetTransSpeedType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetTransSpeedType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetTransSpeedTypeClass = NULL;
   static inline jclass getSetTransSpeedTypeClass() {
       if (SetTransSpeedTypeClass != NULL) {
           return SetTransSpeedTypeClass;
       }
       SetTransSpeedTypeClass = getNewSetTransSpeedTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetForceUnitsType
   static inline jclass getSetForceUnitsTypeClass();
   
   SetForceUnitsType::SetForceUnitsType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetForceUnitsType::SetForceUnitsType(const SetForceUnitsType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetForceUnitsType::SetForceUnitsType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetForceUnitsTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetForceUnitsType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetForceUnitsType::setTransSpeed jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetForceUnitsType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetForceUnitsType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetForceUnitsType
   SetForceUnitsType::~SetForceUnitsType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewSetForceUnitsTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetForceUnitsType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetForceUnitsType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetForceUnitsTypeClass = NULL;
   static inline jclass getSetForceUnitsTypeClass() {
       if (SetForceUnitsTypeClass != NULL) {
           return SetForceUnitsTypeClass;
       }
       SetForceUnitsTypeClass = getNewSetForceUnitsTypeClass();
   }
   
   // get JNI handle for class crcl.base.RotAccelRelativeType
   static inline jclass getRotAccelRelativeTypeClass();
   
   RotAccelRelativeType::RotAccelRelativeType(jobject _jthis, bool copy): RotAccelType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RotAccelRelativeType::RotAccelRelativeType(const RotAccelRelativeType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RotAccelRelativeType::RotAccelRelativeType() : RotAccelType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRotAccelRelativeTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RotAccelRelativeType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RotAccelRelativeType::setTransSpeed jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RotAccelRelativeType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RotAccelRelativeType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RotAccelRelativeType
   RotAccelRelativeType::~RotAccelRelativeType() {
   	// Place-holder for later extensibility.
   }

   void RotAccelRelativeType::setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFraction of crcl.base.RotAccelRelativeType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotAccelRelativeType::setFraction jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotAccelRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotAccelRelativeType::setFraction jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal RotAccelRelativeType::getFraction() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFraction of crcl.base.RotAccelRelativeType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotAccelRelativeType::getFraction jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotAccelRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotAccelRelativeType::getFraction jthis=",t);
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
   static jclass getNewRotAccelRelativeTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RotAccelRelativeType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RotAccelRelativeType" << std::endl;
       }
       return clss;
   }
   
   static jclass RotAccelRelativeTypeClass = NULL;
   static inline jclass getRotAccelRelativeTypeClass() {
       if (RotAccelRelativeTypeClass != NULL) {
           return RotAccelRelativeTypeClass;
       }
       RotAccelRelativeTypeClass = getNewRotAccelRelativeTypeClass();
   }
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

