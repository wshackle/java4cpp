
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.VacuumGripperStatusType
   static inline jclass getVacuumGripperStatusTypeClass();
   
   VacuumGripperStatusType::VacuumGripperStatusType(jobject _jthis, bool copy): GripperStatusType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   VacuumGripperStatusType::VacuumGripperStatusType(const VacuumGripperStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   VacuumGripperStatusType::VacuumGripperStatusType() : GripperStatusType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getVacuumGripperStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class VacuumGripperStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," VacuumGripperStatusType::getPort jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new VacuumGripperStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new VacuumGripperStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.VacuumGripperStatusType
   VacuumGripperStatusType::~VacuumGripperStatusType() {
   	// Place-holder for later extensibility.
   }

   jboolean VacuumGripperStatusType::isIsPowered() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isIsPowered of crcl.base.VacuumGripperStatusType with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," VacuumGripperStatusType::isIsPowered jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isIsPowered", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.VacuumGripperStatusType has no method named isIsPowered with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," VacuumGripperStatusType::isIsPowered jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void VacuumGripperStatusType::setIsPowered(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setIsPowered of crcl.base.VacuumGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," VacuumGripperStatusType::setIsPowered jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setIsPowered", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.VacuumGripperStatusType has no method named setIsPowered with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," VacuumGripperStatusType::setIsPowered jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewVacuumGripperStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/VacuumGripperStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/VacuumGripperStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass VacuumGripperStatusTypeClass = NULL;
   static inline jclass getVacuumGripperStatusTypeClass() {
       if (VacuumGripperStatusTypeClass != NULL) {
           return VacuumGripperStatusTypeClass;
       }
       VacuumGripperStatusTypeClass = getNewVacuumGripperStatusTypeClass();
   }
   
   // get JNI handle for class crcl.base.GetStatusType
   static inline jclass getGetStatusTypeClass();
   
   GetStatusType::GetStatusType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   GetStatusType::GetStatusType(const GetStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   GetStatusType::GetStatusType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getGetStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class GetStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," GetStatusType::setIsPowered jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new GetStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new GetStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.GetStatusType
   GetStatusType::~GetStatusType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewGetStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/GetStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/GetStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass GetStatusTypeClass = NULL;
   static inline jclass getGetStatusTypeClass() {
       if (GetStatusTypeClass != NULL) {
           return GetStatusTypeClass;
       }
       GetStatusTypeClass = getNewGetStatusTypeClass();
   }
   
   // get JNI handle for class crcl.base.RotSpeedAbsoluteType
   static inline jclass getRotSpeedAbsoluteTypeClass();
   
   RotSpeedAbsoluteType::RotSpeedAbsoluteType(jobject _jthis, bool copy): RotSpeedType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RotSpeedAbsoluteType::RotSpeedAbsoluteType(const RotSpeedAbsoluteType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RotSpeedAbsoluteType::RotSpeedAbsoluteType() : RotSpeedType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRotSpeedAbsoluteTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RotSpeedAbsoluteType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RotSpeedAbsoluteType::setIsPowered jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RotSpeedAbsoluteType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RotSpeedAbsoluteType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RotSpeedAbsoluteType
   RotSpeedAbsoluteType::~RotSpeedAbsoluteType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal RotSpeedAbsoluteType::getSetting() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSetting of crcl.base.RotSpeedAbsoluteType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotSpeedAbsoluteType::getSetting jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotSpeedAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotSpeedAbsoluteType::getSetting jthis=",t);
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
   void RotSpeedAbsoluteType::setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSetting of crcl.base.RotSpeedAbsoluteType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," RotSpeedAbsoluteType::setSetting jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.RotSpeedAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," RotSpeedAbsoluteType::setSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewRotSpeedAbsoluteTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RotSpeedAbsoluteType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RotSpeedAbsoluteType" << std::endl;
       }
       return clss;
   }
   
   static jclass RotSpeedAbsoluteTypeClass = NULL;
   static inline jclass getRotSpeedAbsoluteTypeClass() {
       if (RotSpeedAbsoluteTypeClass != NULL) {
           return RotSpeedAbsoluteTypeClass;
       }
       RotSpeedAbsoluteTypeClass = getNewRotSpeedAbsoluteTypeClass();
   }
  } // end namespace base

   namespace utils{
   
   // get JNI handle for class crcl.utils.PendantClient
   static inline jclass getPendantClientClass();
   
   PendantClient::PendantClient(jobject _jthis, bool copy): ::crclj::javax::swing::JFrame(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PendantClient::PendantClient(const PendantClient &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PendantClient::PendantClient(jstring string_0) : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPendantClientClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class PendantClient has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PendantClient::setSetting jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PendantClient with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PendantClient jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PendantClient::PendantClient(const char * easyArg_0) : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class PendantClient has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::setSetting jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PendantClient with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PendantClient jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   jobjectRefType ref_0 = env->GetObjectRefType(string_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_0);
   }
   
   releaseEnv(env);
   }
   PendantClient::PendantClient() : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPendantClientClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PendantClient has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PendantClient::setSetting jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PendantClient with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PendantClient jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.PendantClient
   PendantClient::~PendantClient() {
   	// Place-holder for later extensibility.
   }

   jboolean PendantClient::isConnected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isConnected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isConnected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isConnected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isConnected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isConnected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClient::finishConnect() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method finishConnect of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishConnect jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "finishConnect", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named finishConnect with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishConnect jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::showMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showMessage of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showMessage", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named showMessage with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::showMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::showMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method showMessage of crcl.utils.PendantClient with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showMessage jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    showMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void PendantClient::showMessage(::crclj::java::lang::Throwable  &throwable_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showMessage of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showMessage", "(Ljava/lang/Throwable;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named showMessage with signature (Ljava/lang/Throwable;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,throwable_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::showMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClient::showDebugMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showDebugMessage of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showDebugMessage jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showDebugMessage", "(Ljava/lang/String;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named showDebugMessage with signature (Ljava/lang/String;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::showDebugMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClient::showDebugMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method showDebugMessage of crcl.utils.PendantClient with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showDebugMessage jthis=",jthis);
    jboolean retVal=false;
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    retVal= (jboolean) showDebugMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   jboolean PendantClient::validateXmlSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method validateXmlSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::validateXmlSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "validateXmlSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named validateXmlSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::validateXmlSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClient::replaceStateSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method replaceStateSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::replaceStateSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "replaceStateSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named replaceStateSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::replaceStateSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClient::finishDisconnect() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method finishDisconnect of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishDisconnect jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "finishDisconnect", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named finishDisconnect with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishDisconnect jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::finishSetStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method finishSetStatus of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishSetStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "finishSetStatus", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named finishSetStatus with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishSetStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::checkXmlQuery(CRCLSocket  &cRCLSocket_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkXmlQuery of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::checkXmlQuery jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkXmlQuery", "(Lcrcl/utils/CRCLSocket;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named checkXmlQuery with signature (Lcrcl/utils/CRCLSocket;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLSocket_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::checkXmlQuery jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::stopPollTimer() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stopPollTimer of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::stopPollTimer jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stopPollTimer", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named stopPollTimer with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::stopPollTimer jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::checkPollSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkPollSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::checkPollSelected jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkPollSelected", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named checkPollSelected with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::checkPollSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClient::isDebugWaitForDoneSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugWaitForDoneSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isDebugWaitForDoneSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugWaitForDoneSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isDebugWaitForDoneSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isDebugWaitForDoneSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClient::isDebugSendCommandSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugSendCommandSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isDebugSendCommandSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugSendCommandSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isDebugSendCommandSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isDebugSendCommandSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClient::isDebugReadStatusSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugReadStatusSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isDebugReadStatusSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugReadStatusSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isDebugReadStatusSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isDebugReadStatusSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClient::showCurrentProgramLine(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showCurrentProgramLine of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showCurrentProgramLine jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showCurrentProgramLine", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named showCurrentProgramLine with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::showCurrentProgramLine jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::finishOpenXmlProgramFile(::crclj::java::io::File  &file_0,::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method finishOpenXmlProgramFile of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishOpenXmlProgramFile jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "finishOpenXmlProgramFile", "(Ljava/io/File;Lcrcl/base/CRCLProgramType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named finishOpenXmlProgramFile with signature (Ljava/io/File;Lcrcl/base/CRCLProgramType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,file_0.jthis,cRCLProgramType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::finishOpenXmlProgramFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::CRCLProgramType PendantClient::editProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method editProgram of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::editProgram jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "editProgram", "(Lcrcl/base/CRCLProgramType;)Lcrcl/base/CRCLProgramType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named editProgram with signature (Lcrcl/base/CRCLProgramType;)Lcrcl/base/CRCLProgramType;." << std::endl;
           ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,cRCLProgramType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::editProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLProgramType retObject(retVal,false);
    return retObject;
   }
   void PendantClient::showLastProgramLineExecTimeMillisDists(jlong long_0,jdouble double_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showLastProgramLineExecTimeMillisDists of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showLastProgramLineExecTimeMillisDists jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showLastProgramLineExecTimeMillisDists", "(JD)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named showLastProgramLineExecTimeMillisDists with signature (JD)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0,double_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::showLastProgramLineExecTimeMillisDists jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClient::isRecordPoseSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isRecordPoseSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isRecordPoseSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isRecordPoseSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isRecordPoseSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isRecordPoseSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClient::isEXISelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEXISelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isEXISelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isEXISelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isEXISelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isEXISelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClient::isUseReadStatusThreadSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isUseReadStatusThreadSelected of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::isUseReadStatusThreadSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isUseReadStatusThreadSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named isUseReadStatusThreadSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::isUseReadStatusThreadSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClient::openXmlProgramFile(::crclj::java::io::File  &file_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method openXmlProgramFile of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::openXmlProgramFile jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "openXmlProgramFile", "(Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named openXmlProgramFile with signature (Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::openXmlProgramFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::saveXmlProgramFile(::crclj::java::io::File  &file_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method saveXmlProgramFile of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::saveXmlProgramFile jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "saveXmlProgramFile", "(Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named saveXmlProgramFile with signature (Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::saveXmlProgramFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PendantClient::getRpyJogIncrement() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getRpyJogIncrement of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::getRpyJogIncrement jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getRpyJogIncrement", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named getRpyJogIncrement with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::getRpyJogIncrement jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClient::setRpyJogIncrement(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setRpyJogIncrement of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::setRpyJogIncrement jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setRpyJogIncrement", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named setRpyJogIncrement with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::setRpyJogIncrement jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::showProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showProgram of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::showProgram jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showProgram", "(Lcrcl/base/CRCLProgramType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named showProgram with signature (Lcrcl/base/CRCLProgramType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLProgramType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::showProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::setStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatus of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::setStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatus", "(Lcrcl/base/CRCLStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named setStatus with signature (Lcrcl/base/CRCLStatusType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::setStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::main(int argc, const char **argv) {
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
   void PendantClient::connect(jstring string_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method connect of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::connect jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "connect", "(Ljava/lang/String;I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named connect with signature (Ljava/lang/String;I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::connect jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClient::connect(const char * easyArg_0,jint easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method connect of crcl.utils.PendantClient with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::connect jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jint int_1= easyArg_1;
    connect(string_0,int_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jstring PendantClient::getHost() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getHost of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::getHost jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getHost", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named getHost with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::getHost jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint PendantClient::getPort() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPort of crcl.utils.PendantClient with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClient::getPort jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPort", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClient has no method named getPort with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClient::getPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewPendantClientClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/PendantClient");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/PendantClient" << std::endl;
       }
       return clss;
   }
   
   static jclass PendantClientClass = NULL;
   static inline jclass getPendantClientClass() {
       if (PendantClientClass != NULL) {
           return PendantClientClass;
       }
       PendantClientClass = getNewPendantClientClass();
   }
   
   // get JNI handle for class crcl.utils.CmdLineClient
   static inline jclass getCmdLineClientClass();
   
   CmdLineClient::CmdLineClient(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CmdLineClient::CmdLineClient(const CmdLineClient &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CmdLineClient::CmdLineClient() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCmdLineClientClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CmdLineClient has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CmdLineClient::getPort jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CmdLineClient with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CmdLineClient jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.CmdLineClient
   CmdLineClient::~CmdLineClient() {
   	// Place-holder for later extensibility.
   }

   void CmdLineClient::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCmdLineClientClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CmdLineClient has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CmdLineClient::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CmdLineClient::main(int argc, const char **argv) {
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
   static jclass getNewCmdLineClientClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/CmdLineClient");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/CmdLineClient" << std::endl;
       }
       return clss;
   }
   
   static jclass CmdLineClientClass = NULL;
   static inline jclass getCmdLineClientClass() {
       if (CmdLineClientClass != NULL) {
           return CmdLineClientClass;
       }
       CmdLineClientClass = getNewCmdLineClientClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

