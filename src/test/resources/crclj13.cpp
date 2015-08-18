
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.SetRotAccelType
   static inline jclass getSetRotAccelTypeClass();
   
   SetRotAccelType::SetRotAccelType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetRotAccelType::SetRotAccelType(const SetRotAccelType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetRotAccelType::SetRotAccelType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetRotAccelTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetRotAccelType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetRotAccelType::setReportVelocity jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetRotAccelType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetRotAccelType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetRotAccelType
   SetRotAccelType::~SetRotAccelType() {
   	// Place-holder for later extensibility.
   }

   RotAccelType SetRotAccelType::getRotAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getRotAccel of crcl.base.SetRotAccelType with jthis == NULL." << std::endl;
       RotAccelType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetRotAccelType::getRotAccel jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getRotAccel", "()Lcrcl/base/RotAccelType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetRotAccelType has no method named getRotAccel with signature ()Lcrcl/base/RotAccelType;." << std::endl;
           RotAccelType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetRotAccelType::getRotAccel jthis=",t);
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
   void SetRotAccelType::setRotAccel(RotAccelType  &rotAccelType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setRotAccel of crcl.base.SetRotAccelType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SetRotAccelType::setRotAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setRotAccel", "(Lcrcl/base/RotAccelType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.SetRotAccelType has no method named setRotAccel with signature (Lcrcl/base/RotAccelType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,rotAccelType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SetRotAccelType::setRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewSetRotAccelTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetRotAccelType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetRotAccelType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetRotAccelTypeClass = NULL;
   static inline jclass getSetRotAccelTypeClass() {
       if (SetRotAccelTypeClass != NULL) {
           return SetRotAccelTypeClass;
       }
       SetRotAccelTypeClass = getNewSetRotAccelTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetAngleUnitsType
   static inline jclass getSetAngleUnitsTypeClass();
   
   SetAngleUnitsType::SetAngleUnitsType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetAngleUnitsType::SetAngleUnitsType(const SetAngleUnitsType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetAngleUnitsType::SetAngleUnitsType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetAngleUnitsTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetAngleUnitsType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetAngleUnitsType::setRotAccel jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetAngleUnitsType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetAngleUnitsType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetAngleUnitsType
   SetAngleUnitsType::~SetAngleUnitsType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewSetAngleUnitsTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetAngleUnitsType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetAngleUnitsType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetAngleUnitsTypeClass = NULL;
   static inline jclass getSetAngleUnitsTypeClass() {
       if (SetAngleUnitsTypeClass != NULL) {
           return SetAngleUnitsTypeClass;
       }
       SetAngleUnitsTypeClass = getNewSetAngleUnitsTypeClass();
   }
   
   // get JNI handle for class crcl.base.CommandStatusType
   static inline jclass getCommandStatusTypeClass();
   
   CommandStatusType::CommandStatusType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CommandStatusType::CommandStatusType(const CommandStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CommandStatusType::CommandStatusType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCommandStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CommandStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::setRotAccel jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CommandStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CommandStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.CommandStatusType
   CommandStatusType::~CommandStatusType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigInteger CommandStatusType::getCommandID() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::getCommandID jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandID", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CommandStatusType has no method named getCommandID with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::getCommandID jthis=",t);
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
   void CommandStatusType::setCommandID(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::setCommandID jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandID", "(Ljava/math/BigInteger;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CommandStatusType has no method named setCommandID with signature (Ljava/math/BigInteger;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::setCommandID jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigInteger CommandStatusType::getStatusID() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatusID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::getStatusID jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatusID", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CommandStatusType has no method named getStatusID with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::getStatusID jthis=",t);
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
   void CommandStatusType::setStatusID(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatusID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::setStatusID jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatusID", "(Ljava/math/BigInteger;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CommandStatusType has no method named setStatusID with signature (Ljava/math/BigInteger;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CommandStatusType::setStatusID jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewCommandStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/CommandStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/CommandStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass CommandStatusTypeClass = NULL;
   static inline jclass getCommandStatusTypeClass() {
       if (CommandStatusTypeClass != NULL) {
           return CommandStatusTypeClass;
       }
       CommandStatusTypeClass = getNewCommandStatusTypeClass();
   }
   
   // get JNI handle for class crcl.base.RotSpeedRelativeType
   static inline jclass getRotSpeedRelativeTypeClass();
   
   RotSpeedRelativeType::RotSpeedRelativeType(jobject _jthis, bool copy): RotSpeedType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RotSpeedRelativeType::RotSpeedRelativeType(const RotSpeedRelativeType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RotSpeedRelativeType::RotSpeedRelativeType() : RotSpeedType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRotSpeedRelativeTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RotSpeedRelativeType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RotSpeedRelativeType::setStatusID jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RotSpeedRelativeType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RotSpeedRelativeType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RotSpeedRelativeType
   RotSpeedRelativeType::~RotSpeedRelativeType() {
   	// Place-holder for later extensibility.
   }

   void RotSpeedRelativeType::setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFraction of crcl.base.RotSpeedRelativeType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotSpeedRelativeType::setFraction jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotSpeedRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotSpeedRelativeType::setFraction jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal RotSpeedRelativeType::getFraction() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFraction of crcl.base.RotSpeedRelativeType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotSpeedRelativeType::getFraction jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotSpeedRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotSpeedRelativeType::getFraction jthis=",t);
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
   static jclass getNewRotSpeedRelativeTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RotSpeedRelativeType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RotSpeedRelativeType" << std::endl;
       }
       return clss;
   }
   
   static jclass RotSpeedRelativeTypeClass = NULL;
   static inline jclass getRotSpeedRelativeTypeClass() {
       if (RotSpeedRelativeTypeClass != NULL) {
           return RotSpeedRelativeTypeClass;
       }
       RotSpeedRelativeTypeClass = getNewRotSpeedRelativeTypeClass();
   }
   
   // get JNI handle for class crcl.base.RotAccelAbsoluteType
   static inline jclass getRotAccelAbsoluteTypeClass();
   
   RotAccelAbsoluteType::RotAccelAbsoluteType(jobject _jthis, bool copy): RotAccelType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RotAccelAbsoluteType::RotAccelAbsoluteType(const RotAccelAbsoluteType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RotAccelAbsoluteType::RotAccelAbsoluteType() : RotAccelType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRotAccelAbsoluteTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RotAccelAbsoluteType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RotAccelAbsoluteType::getFraction jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RotAccelAbsoluteType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RotAccelAbsoluteType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RotAccelAbsoluteType
   RotAccelAbsoluteType::~RotAccelAbsoluteType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal RotAccelAbsoluteType::getSetting() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSetting of crcl.base.RotAccelAbsoluteType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotAccelAbsoluteType::getSetting jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotAccelAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotAccelAbsoluteType::getSetting jthis=",t);
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
   void RotAccelAbsoluteType::setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSetting of crcl.base.RotAccelAbsoluteType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotAccelAbsoluteType::setSetting jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotAccelAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotAccelAbsoluteType::setSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewRotAccelAbsoluteTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RotAccelAbsoluteType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RotAccelAbsoluteType" << std::endl;
       }
       return clss;
   }
   
   static jclass RotAccelAbsoluteTypeClass = NULL;
   static inline jclass getRotAccelAbsoluteTypeClass() {
       if (RotAccelAbsoluteTypeClass != NULL) {
           return RotAccelAbsoluteTypeClass;
       }
       RotAccelAbsoluteTypeClass = getNewRotAccelAbsoluteTypeClass();
   }
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

