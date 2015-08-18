
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

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


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.DataThingType
   static inline jclass getDataThingTypeClass();
   
   DataThingType::DataThingType(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   DataThingType::DataThingType(const DataThingType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   DataThingType::DataThingType() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getDataThingTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class DataThingType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," DataThingType::%METHOD_NAME% jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new DataThingType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new DataThingType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.DataThingType
   DataThingType::~DataThingType() {
   	// Place-holder for later extensibility.
   }

   jstring DataThingType::getName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getName of crcl.base.DataThingType with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," DataThingType::getName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.DataThingType has no method named getName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," DataThingType::getName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void DataThingType::setName(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setName of crcl.base.DataThingType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," DataThingType::setName jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setName", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.DataThingType has no method named setName with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," DataThingType::setName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void DataThingType::setName(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setName of crcl.base.DataThingType with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," DataThingType::setName jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setName(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   static jclass getNewDataThingTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/DataThingType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/DataThingType" << std::endl;
       }
       return clss;
   }
   
   static jclass DataThingTypeClass = NULL;
   static inline jclass getDataThingTypeClass() {
       if (DataThingTypeClass != NULL) {
           return DataThingTypeClass;
       }
       DataThingTypeClass = getNewDataThingTypeClass();
   }
   
   // get JNI handle for class crcl.base.JointDetailsType
   static inline jclass getJointDetailsTypeClass();
   
   JointDetailsType::JointDetailsType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JointDetailsType::JointDetailsType(const JointDetailsType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JointDetailsType::JointDetailsType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJointDetailsTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JointDetailsType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JointDetailsType::setName jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JointDetailsType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JointDetailsType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.JointDetailsType
   JointDetailsType::~JointDetailsType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewJointDetailsTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/JointDetailsType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/JointDetailsType" << std::endl;
       }
       return clss;
   }
   
   static jclass JointDetailsTypeClass = NULL;
   static inline jclass getJointDetailsTypeClass() {
       if (JointDetailsTypeClass != NULL) {
           return JointDetailsTypeClass;
       }
       JointDetailsTypeClass = getNewJointDetailsTypeClass();
   }
   
   // get JNI handle for class crcl.base.JointSpeedAccelType
   static inline jclass getJointSpeedAccelTypeClass();
   
   JointSpeedAccelType::JointSpeedAccelType(jobject _jthis, bool copy): JointDetailsType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JointSpeedAccelType::JointSpeedAccelType(const JointSpeedAccelType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JointSpeedAccelType::JointSpeedAccelType() : JointDetailsType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJointSpeedAccelTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JointSpeedAccelType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::setName jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JointSpeedAccelType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JointSpeedAccelType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.JointSpeedAccelType
   JointSpeedAccelType::~JointSpeedAccelType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal JointSpeedAccelType::getJointSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointSpeed of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::getJointSpeed jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointSpeed", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointSpeedAccelType has no method named getJointSpeed with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::getJointSpeed jthis=",t);
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
   void JointSpeedAccelType::setJointSpeed(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointSpeed of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::setJointSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointSpeed", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointSpeedAccelType has no method named setJointSpeed with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::setJointSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal JointSpeedAccelType::getJointAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointAccel of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::getJointAccel jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointAccel", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointSpeedAccelType has no method named getJointAccel with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::getJointAccel jthis=",t);
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
   void JointSpeedAccelType::setJointAccel(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointAccel of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::setJointAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointAccel", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.JointSpeedAccelType has no method named setJointAccel with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JointSpeedAccelType::setJointAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewJointSpeedAccelTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/JointSpeedAccelType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/JointSpeedAccelType" << std::endl;
       }
       return clss;
   }
   
   static jclass JointSpeedAccelTypeClass = NULL;
   static inline jclass getJointSpeedAccelTypeClass() {
       if (JointSpeedAccelTypeClass != NULL) {
           return JointSpeedAccelTypeClass;
       }
       JointSpeedAccelTypeClass = getNewJointSpeedAccelTypeClass();
   }
   
   // get JNI handle for class crcl.base.CRCLCommandType
   static inline jclass getCRCLCommandTypeClass();
   
   CRCLCommandType::CRCLCommandType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CRCLCommandType::CRCLCommandType(const CRCLCommandType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CRCLCommandType::CRCLCommandType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCRCLCommandTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CRCLCommandType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CRCLCommandType::setJointAccel jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CRCLCommandType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLCommandType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.CRCLCommandType
   CRCLCommandType::~CRCLCommandType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigInteger CRCLCommandType::getCommandID() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandID of crcl.base.CRCLCommandType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLCommandType::getCommandID jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandID", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLCommandType has no method named getCommandID with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLCommandType::getCommandID jthis=",t);
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
   void CRCLCommandType::setCommandID(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandID of crcl.base.CRCLCommandType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLCommandType::setCommandID jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandID", "(Ljava/math/BigInteger;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLCommandType has no method named setCommandID with signature (Ljava/math/BigInteger;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLCommandType::setCommandID jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewCRCLCommandTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/CRCLCommandType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/CRCLCommandType" << std::endl;
       }
       return clss;
   }
   
   static jclass CRCLCommandTypeClass = NULL;
   static inline jclass getCRCLCommandTypeClass() {
       if (CRCLCommandTypeClass != NULL) {
           return CRCLCommandTypeClass;
       }
       CRCLCommandTypeClass = getNewCRCLCommandTypeClass();
   }
   
   // get JNI handle for class crcl.base.MiddleCommandType
   static inline jclass getMiddleCommandTypeClass();
   
   MiddleCommandType::MiddleCommandType(jobject _jthis, bool copy): CRCLCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   MiddleCommandType::MiddleCommandType(const MiddleCommandType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   MiddleCommandType::MiddleCommandType() : CRCLCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getMiddleCommandTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class MiddleCommandType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," MiddleCommandType::setCommandID jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new MiddleCommandType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MiddleCommandType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.MiddleCommandType
   MiddleCommandType::~MiddleCommandType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewMiddleCommandTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/MiddleCommandType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/MiddleCommandType" << std::endl;
       }
       return clss;
   }
   
   static jclass MiddleCommandTypeClass = NULL;
   static inline jclass getMiddleCommandTypeClass() {
       if (MiddleCommandTypeClass != NULL) {
           return MiddleCommandTypeClass;
       }
       MiddleCommandTypeClass = getNewMiddleCommandTypeClass();
   }
  } // end namespace base
 } // end namespace crcl




    static JNIEnv *getNewEnv() {
        JavaVM *jvm; /* denotes a Java VM */
        JNIEnv *env; /* pointer to native method interface */
        JavaVM * jvmBuf[1];
        jsize nVMs;
        debug_j4cpp = debug_j4cpp || (getenv("DEBUG_J4CPP") != NULL);
        char *classPathEnv = getenv("CLASSPATH");
        char *jvmOptionsEnv = getenv("JVM_OPTIONS");
        std::string str;
        str += "../crac/CRCLJava/target/CRCLJava-1.0-SNAPSHOT-jar-with-dependencies.jar";
        if (classPathEnv != NULL) {
            std::string classPathEnvStr(classPathEnv);
            if (debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
            str += ":";
            str += classPathEnvStr;
        }
        if (debug_j4cpp) std::cout << "str=" << str << std::endl;
        setenv("CLASSPATH", str.c_str(), 1);
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
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
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
    
    void PrintObject(const char *prefix, const ::crclj::java::lang::Object &objref) {
        PrintJObject(prefix,objref.jthis);
    }
    
    extern void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    extern bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace crclj
}

