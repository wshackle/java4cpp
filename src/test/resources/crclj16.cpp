
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace base{
   
   // get JNI handle for class crcl.base.ThreeFingerGripperStatusType
   static inline jclass getThreeFingerGripperStatusTypeClass();
   
   ThreeFingerGripperStatusType::ThreeFingerGripperStatusType(jobject _jthis, bool copy): GripperStatusType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ThreeFingerGripperStatusType::ThreeFingerGripperStatusType(const ThreeFingerGripperStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ThreeFingerGripperStatusType::ThreeFingerGripperStatusType() : GripperStatusType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getThreeFingerGripperStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ThreeFingerGripperStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getParameterSetting jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ThreeFingerGripperStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ThreeFingerGripperStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.ThreeFingerGripperStatusType
   ThreeFingerGripperStatusType::~ThreeFingerGripperStatusType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::math::BigDecimal ThreeFingerGripperStatusType::getFinger1Position() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFinger1Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger1Position jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFinger1Position", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger1Position with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger1Position jthis=",t);
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
   void ThreeFingerGripperStatusType::setFinger1Position(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFinger1Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger1Position jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFinger1Position", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger1Position with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger1Position jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal ThreeFingerGripperStatusType::getFinger2Position() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFinger2Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger2Position jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFinger2Position", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger2Position with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger2Position jthis=",t);
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
   void ThreeFingerGripperStatusType::setFinger2Position(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFinger2Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger2Position jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFinger2Position", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger2Position with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger2Position jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal ThreeFingerGripperStatusType::getFinger1Force() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFinger1Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger1Force jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFinger1Force", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger1Force with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger1Force jthis=",t);
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
   ::crclj::java::math::BigDecimal ThreeFingerGripperStatusType::getFinger3Position() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFinger3Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger3Position jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFinger3Position", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger3Position with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger3Position jthis=",t);
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
   void ThreeFingerGripperStatusType::setFinger3Position(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFinger3Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger3Position jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFinger3Position", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger3Position with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger3Position jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void ThreeFingerGripperStatusType::setFinger1Force(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFinger1Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger1Force jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFinger1Force", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger1Force with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger1Force jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal ThreeFingerGripperStatusType::getFinger2Force() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFinger2Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger2Force jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFinger2Force", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger2Force with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger2Force jthis=",t);
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
   void ThreeFingerGripperStatusType::setFinger2Force(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFinger2Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger2Force jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFinger2Force", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger2Force with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger2Force jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal ThreeFingerGripperStatusType::getFinger3Force() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFinger3Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger3Force jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFinger3Force", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger3Force with signature ()Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::getFinger3Force jthis=",t);
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
   void ThreeFingerGripperStatusType::setFinger3Force(::crclj::java::math::BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFinger3Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger3Force jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFinger3Force", "(Ljava/math/BigDecimal;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger3Force with signature (Ljava/math/BigDecimal;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ThreeFingerGripperStatusType::setFinger3Force jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewThreeFingerGripperStatusTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/ThreeFingerGripperStatusType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/ThreeFingerGripperStatusType" << std::endl;
       }
       return clss;
   }
   
   static jclass ThreeFingerGripperStatusTypeClass = NULL;
   static inline jclass getThreeFingerGripperStatusTypeClass() {
       if (ThreeFingerGripperStatusTypeClass != NULL) {
           return ThreeFingerGripperStatusTypeClass;
       }
       ThreeFingerGripperStatusTypeClass = getNewThreeFingerGripperStatusTypeClass();
   }
  } // end namespace base

   namespace utils{
   
   // get JNI handle for class crcl.utils.PendantClientOuter
   static inline jclass getPendantClientOuterClass();
   
   PendantClientOuter::PendantClientOuter(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PendantClientOuter::PendantClientOuter(const PendantClientOuter &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PendantClientOuter::PendantClientOuter() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientOuterClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class PendantClientOuter has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientOuter::setFinger3Force jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PendantClientOuter with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PendantClientOuter jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for crcl.utils.PendantClientOuter
   PendantClientOuter::~PendantClientOuter() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewPendantClientOuterClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/PendantClientOuter");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/PendantClientOuter" << std::endl;
       }
       return clss;
   }
   
   static jclass PendantClientOuterClass = NULL;
   static inline jclass getPendantClientOuterClass() {
       if (PendantClientOuterClass != NULL) {
           return PendantClientOuterClass;
       }
       PendantClientOuterClass = getNewPendantClientOuterClass();
   }
   
   // get JNI handle for class crcl.utils.SideViewJPanel
   static inline jclass getSideViewJPanelClass();
   
   SideViewJPanel::SideViewJPanel(jobject _jthis, bool copy): ::crclj::javax::swing::JPanel(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SideViewJPanel::SideViewJPanel(const SideViewJPanel &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SideViewJPanel::SideViewJPanel() : ::crclj::javax::swing::JPanel((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSideViewJPanelClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SideViewJPanel has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setFinger3Force jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SideViewJPanel with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SideViewJPanel jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.SideViewJPanel
   SideViewJPanel::~SideViewJPanel() {
   	// Place-holder for later extensibility.
   }

   jdoubleArray SideViewJPanel::getJointvals() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointvals of crcl.utils.SideViewJPanel with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::getJointvals jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointvals", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SideViewJPanel has no method named getJointvals with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::getJointvals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SideViewJPanel::setJointvals(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointvals of crcl.utils.SideViewJPanel with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setJointvals jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointvals", "([D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SideViewJPanel has no method named setJointvals with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setJointvals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SideViewJPanel::setJointvals(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setJointvals of crcl.utils.SideViewJPanel with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setJointvals jthis=",jthis);
    
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    setJointvals(doubleArray_0);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
   }

   void SideViewJPanel::setSeglengths(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSeglengths of crcl.utils.SideViewJPanel with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setSeglengths jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSeglengths", "([D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SideViewJPanel has no method named setSeglengths with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SideViewJPanel::setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setSeglengths of crcl.utils.SideViewJPanel with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::setSeglengths jthis=",jthis);
    
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    setSeglengths(doubleArray_0);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
   }

   jdoubleArray SideViewJPanel::getSeglengths() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSeglengths of crcl.utils.SideViewJPanel with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::getSeglengths jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSeglengths", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SideViewJPanel has no method named getSeglengths with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SideViewJPanel::getSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewSideViewJPanelClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SideViewJPanel");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SideViewJPanel" << std::endl;
       }
       return clss;
   }
   
   static jclass SideViewJPanelClass = NULL;
   static inline jclass getSideViewJPanelClass() {
       if (SideViewJPanelClass != NULL) {
           return SideViewJPanelClass;
       }
       SideViewJPanelClass = getNewSideViewJPanelClass();
   }
   
   // get JNI handle for class crcl.utils.SimulatedKinematicsSimple
   static inline jclass getSimulatedKinematicsSimpleClass();
   
   SimulatedKinematicsSimple::SimulatedKinematicsSimple(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SimulatedKinematicsSimple::SimulatedKinematicsSimple(const SimulatedKinematicsSimple &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SimulatedKinematicsSimple::SimulatedKinematicsSimple() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSimulatedKinematicsSimpleClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SimulatedKinematicsSimple has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::getSeglengths jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SimulatedKinematicsSimple with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimulatedKinematicsSimple jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.SimulatedKinematicsSimple
   SimulatedKinematicsSimple::~SimulatedKinematicsSimple() {
   	// Place-holder for later extensibility.
   }

   jdouble SimulatedKinematicsSimple::getScale() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getScale of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::getScale jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getScale", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named getScale with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::getScale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimulatedKinematicsSimple::setScale(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setScale of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::setScale jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setScale", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named setScale with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::setScale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimulatedKinematicsSimple::setSeglengths(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSeglengths of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::setSeglengths jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSeglengths", "([D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named setSeglengths with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::setSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimulatedKinematicsSimple::setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setSeglengths of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::setSeglengths jthis=",jthis);
    
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    setSeglengths(doubleArray_0);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
   }

   ::crclj::crcl::base::PoseType SimulatedKinematicsSimple::jointsToPose(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method jointsToPose of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::jointsToPose jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "jointsToPose", "([DLcrcl/base/PoseType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named jointsToPose with signature ([DLcrcl/base/PoseType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,doubleArray_0,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::jointsToPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType SimulatedKinematicsSimple::jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method jointsToPose of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
        ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::jointsToPose jthis=",jthis);
    ::crclj::crcl::base::PoseType retVal((jobject)NULL,false);
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    ::crclj::crcl::base::PoseType  &poseType_1= easyArg_1;
    retVal= (::crclj::crcl::base::PoseType) jointsToPose(doubleArray_0,poseType_1);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::PoseType SimulatedKinematicsSimple::jointsToPose(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method jointsToPose of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::jointsToPose jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "jointsToPose", "([D)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named jointsToPose with signature ([D)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::jointsToPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::PoseType SimulatedKinematicsSimple::jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method jointsToPose of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
        ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::jointsToPose jthis=",jthis);
    ::crclj::crcl::base::PoseType retVal((jobject)NULL,false);
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    retVal= (::crclj::crcl::base::PoseType) jointsToPose(doubleArray_0);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   jdoubleArray SimulatedKinematicsSimple::getSeglengths() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSeglengths of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::getSeglengths jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSeglengths", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named getSeglengths with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::getSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdoubleArray SimulatedKinematicsSimple::poseToJoints(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method poseToJoints of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::poseToJoints jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "poseToJoints", "([DLcrcl/base/PoseType;)[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsSimple has no method named poseToJoints with signature ([DLcrcl/base/PoseType;)[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid ,doubleArray_0,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::poseToJoints jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdoubleArray SimulatedKinematicsSimple::poseToJoints(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method poseToJoints of crcl.utils.SimulatedKinematicsSimple with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsSimple::poseToJoints jthis=",jthis);
    jdoubleArray retVal=NULL;
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    ::crclj::crcl::base::PoseType  &poseType_1= easyArg_1;
    retVal= (jdoubleArray) poseToJoints(doubleArray_0,poseType_1);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   static jclass getNewSimulatedKinematicsSimpleClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SimulatedKinematicsSimple");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SimulatedKinematicsSimple" << std::endl;
       }
       return clss;
   }
   
   static jclass SimulatedKinematicsSimpleClass = NULL;
   static inline jclass getSimulatedKinematicsSimpleClass() {
       if (SimulatedKinematicsSimpleClass != NULL) {
           return SimulatedKinematicsSimpleClass;
       }
       SimulatedKinematicsSimpleClass = getNewSimulatedKinematicsSimpleClass();
   }
   
   // get JNI handle for class crcl.utils.XpathQueryJFrame
   static inline jclass getXpathQueryJFrameClass();
   
   XpathQueryJFrame::XpathQueryJFrame(jobject _jthis, bool copy): ::crclj::javax::swing::JFrame(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   XpathQueryJFrame::XpathQueryJFrame(const XpathQueryJFrame &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   XpathQueryJFrame::XpathQueryJFrame() : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getXpathQueryJFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class XpathQueryJFrame has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::poseToJoints jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new XpathQueryJFrame with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new XpathQueryJFrame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.XpathQueryJFrame
   XpathQueryJFrame::~XpathQueryJFrame() {
   	// Place-holder for later extensibility.
   }

   void XpathQueryJFrame::setQuery(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setQuery of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::setQuery jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setQuery", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named setQuery with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::setQuery jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void XpathQueryJFrame::setQuery(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setQuery of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::setQuery jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setQuery(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jstring XpathQueryJFrame::runQuery(jstring string_0,jstring string_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method runQuery of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::runQuery jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "runQuery", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named runQuery with signature (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,string_0,string_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::runQuery jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathQueryJFrame::runQuery(const char * easyArg_0,const char * easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method runQuery of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::runQuery jthis=",jthis);
    jstring retVal=NULL;
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jstring string_1 = env->NewStringUTF(easyArg_1);
    retVal= (jstring) runQuery(string_0,string_1);
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

   void XpathQueryJFrame::setResult(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setResult of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::setResult jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setResult", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named setResult with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::setResult jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void XpathQueryJFrame::setResult(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setResult of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::setResult jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setResult(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void XpathQueryJFrame::Message(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method Message of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::Message jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "Message", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named Message with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::Message jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void XpathQueryJFrame::Message(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method Message of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::Message jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    Message(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void XpathQueryJFrame::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getXpathQueryJFrameClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void XpathQueryJFrame::main(int argc, const char **argv) {
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
   jstring XpathQueryJFrame::getQuery() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getQuery of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::getQuery jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getQuery", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named getQuery with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::getQuery jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring XpathQueryJFrame::getResult() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getResult of crcl.utils.XpathQueryJFrame with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::getResult jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getResult", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.XpathQueryJFrame has no method named getResult with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," XpathQueryJFrame::getResult jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewXpathQueryJFrameClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/XpathQueryJFrame");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/XpathQueryJFrame" << std::endl;
       }
       return clss;
   }
   
   static jclass XpathQueryJFrameClass = NULL;
   static inline jclass getXpathQueryJFrameClass() {
       if (XpathQueryJFrameClass != NULL) {
           return XpathQueryJFrameClass;
       }
       XpathQueryJFrameClass = getNewXpathQueryJFrameClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

