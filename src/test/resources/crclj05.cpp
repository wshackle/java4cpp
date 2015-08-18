
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.TransAccelType
   static inline jclass getTransAccelTypeClass();
   
   TransAccelType::TransAccelType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   TransAccelType::TransAccelType(const TransAccelType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   TransAccelType::TransAccelType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getTransAccelTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class TransAccelType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," TransAccelType::setRotAccel jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new TransAccelType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TransAccelType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.TransAccelType
   TransAccelType::~TransAccelType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewTransAccelTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/TransAccelType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/TransAccelType" << std::endl;
       }
       return clss;
   }
   
   static jclass TransAccelTypeClass = NULL;
   static inline jclass getTransAccelTypeClass() {
       if (TransAccelTypeClass != NULL) {
           return TransAccelTypeClass;
       }
       TransAccelTypeClass = getNewTransAccelTypeClass();
   }
   
   // get JNI handle for class crcl.base.TransAccelRelativeType
   static inline jclass getTransAccelRelativeTypeClass();
   
   TransAccelRelativeType::TransAccelRelativeType(jobject _jthis, bool copy): TransAccelType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   TransAccelRelativeType::TransAccelRelativeType(const TransAccelRelativeType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   TransAccelRelativeType::TransAccelRelativeType() : TransAccelType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getTransAccelRelativeTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class TransAccelRelativeType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," TransAccelRelativeType::setRotAccel jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new TransAccelRelativeType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TransAccelRelativeType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.TransAccelRelativeType
   TransAccelRelativeType::~TransAccelRelativeType() {
   	// Place-holder for later extensibility.
   }

   void TransAccelRelativeType::setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFraction of crcl.base.TransAccelRelativeType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," TransAccelRelativeType::setFraction jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.TransAccelRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TransAccelRelativeType::setFraction jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal TransAccelRelativeType::getFraction() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFraction of crcl.base.TransAccelRelativeType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," TransAccelRelativeType::getFraction jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.TransAccelRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TransAccelRelativeType::getFraction jthis=",t);
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
   static jclass getNewTransAccelRelativeTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/TransAccelRelativeType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/TransAccelRelativeType" << std::endl;
       }
       return clss;
   }
   
   static jclass TransAccelRelativeTypeClass = NULL;
   static inline jclass getTransAccelRelativeTypeClass() {
       if (TransAccelRelativeTypeClass != NULL) {
           return TransAccelRelativeTypeClass;
       }
       TransAccelRelativeTypeClass = getNewTransAccelRelativeTypeClass();
   }
   
   // get JNI handle for class crcl.base.DwellType
   static inline jclass getDwellTypeClass();
   
   DwellType::DwellType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   DwellType::DwellType(const DwellType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   DwellType::DwellType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getDwellTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class DwellType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," DwellType::getFraction jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new DwellType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new DwellType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.DwellType
   DwellType::~DwellType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal DwellType::getDwellTime() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDwellTime of crcl.base.DwellType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," DwellType::getDwellTime jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getDwellTime", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.DwellType has no method named getDwellTime with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," DwellType::getDwellTime jthis=",t);
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
   void DwellType::setDwellTime(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setDwellTime of crcl.base.DwellType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," DwellType::setDwellTime jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setDwellTime", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.DwellType has no method named setDwellTime with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," DwellType::setDwellTime jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewDwellTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/DwellType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/DwellType" << std::endl;
       }
       return clss;
   }
   
   static jclass DwellTypeClass = NULL;
   static inline jclass getDwellTypeClass() {
       if (DwellTypeClass != NULL) {
           return DwellTypeClass;
       }
       DwellTypeClass = getNewDwellTypeClass();
   }
   
   // get JNI handle for class crcl.base.SetLengthUnitsType
   static inline jclass getSetLengthUnitsTypeClass();
   
   SetLengthUnitsType::SetLengthUnitsType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SetLengthUnitsType::SetLengthUnitsType(const SetLengthUnitsType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SetLengthUnitsType::SetLengthUnitsType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSetLengthUnitsTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SetLengthUnitsType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SetLengthUnitsType::setDwellTime jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SetLengthUnitsType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SetLengthUnitsType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.SetLengthUnitsType
   SetLengthUnitsType::~SetLengthUnitsType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewSetLengthUnitsTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/SetLengthUnitsType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/SetLengthUnitsType" << std::endl;
       }
       return clss;
   }
   
   static jclass SetLengthUnitsTypeClass = NULL;
   static inline jclass getSetLengthUnitsTypeClass() {
       if (SetLengthUnitsTypeClass != NULL) {
           return SetLengthUnitsTypeClass;
       }
       SetLengthUnitsTypeClass = getNewSetLengthUnitsTypeClass();
   }
   
   // get JNI handle for class crcl.base.OpenToolChangerType
   static inline jclass getOpenToolChangerTypeClass();
   
   OpenToolChangerType::OpenToolChangerType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   OpenToolChangerType::OpenToolChangerType(const OpenToolChangerType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   OpenToolChangerType::OpenToolChangerType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getOpenToolChangerTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class OpenToolChangerType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," OpenToolChangerType::setDwellTime jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new OpenToolChangerType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new OpenToolChangerType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.OpenToolChangerType
   OpenToolChangerType::~OpenToolChangerType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewOpenToolChangerTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/OpenToolChangerType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/OpenToolChangerType" << std::endl;
       }
       return clss;
   }
   
   static jclass OpenToolChangerTypeClass = NULL;
   static inline jclass getOpenToolChangerTypeClass() {
       if (OpenToolChangerTypeClass != NULL) {
           return OpenToolChangerTypeClass;
       }
       OpenToolChangerTypeClass = getNewOpenToolChangerTypeClass();
   }
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

