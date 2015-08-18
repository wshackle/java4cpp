
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.SimulatedKinematicsPlausible
   static inline jclass getSimulatedKinematicsPlausibleClass();
   
   SimulatedKinematicsPlausible::SimulatedKinematicsPlausible(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SimulatedKinematicsPlausible::SimulatedKinematicsPlausible(const SimulatedKinematicsPlausible &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SimulatedKinematicsPlausible::SimulatedKinematicsPlausible() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSimulatedKinematicsPlausibleClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SimulatedKinematicsPlausible has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SimulatedKinematicsPlausible with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimulatedKinematicsPlausible jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.SimulatedKinematicsPlausible
   SimulatedKinematicsPlausible::~SimulatedKinematicsPlausible() {
   	// Place-holder for later extensibility.
   }

   jdouble SimulatedKinematicsPlausible::getScale() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getScale of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::getScale jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getScale", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named getScale with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::getScale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimulatedKinematicsPlausible::setScale(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setScale of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::setScale jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setScale", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named setScale with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::setScale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimulatedKinematicsPlausible::setSeglengths(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSeglengths of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::setSeglengths jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSeglengths", "([D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named setSeglengths with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::setSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimulatedKinematicsPlausible::setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setSeglengths of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::setSeglengths jthis=",jthis);
    
            
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

   ::crclj::crcl::base::PoseType SimulatedKinematicsPlausible::jointsToPose(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method jointsToPose of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::jointsToPose jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "jointsToPose", "([DLcrcl/base/PoseType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named jointsToPose with signature ([DLcrcl/base/PoseType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,doubleArray_0,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::jointsToPose jthis=",t);
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
   ::crclj::crcl::base::PoseType SimulatedKinematicsPlausible::jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method jointsToPose of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
        ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::jointsToPose jthis=",jthis);
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

   ::crclj::crcl::base::PoseType SimulatedKinematicsPlausible::jointsToPose(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method jointsToPose of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::jointsToPose jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "jointsToPose", "([D)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named jointsToPose with signature ([D)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::jointsToPose jthis=",t);
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
   ::crclj::crcl::base::PoseType SimulatedKinematicsPlausible::jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method jointsToPose of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
        ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::jointsToPose jthis=",jthis);
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

   jdoubleArray SimulatedKinematicsPlausible::getSeglengths() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSeglengths of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::getSeglengths jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSeglengths", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named getSeglengths with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::getSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdoubleArray SimulatedKinematicsPlausible::poseToJoints(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method poseToJoints of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::poseToJoints jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "poseToJoints", "([DLcrcl/base/PoseType;)[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimulatedKinematicsPlausible has no method named poseToJoints with signature ([DLcrcl/base/PoseType;)[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid ,doubleArray_0,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::poseToJoints jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdoubleArray SimulatedKinematicsPlausible::poseToJoints(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method poseToJoints of crcl.utils.SimulatedKinematicsPlausible with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimulatedKinematicsPlausible::poseToJoints jthis=",jthis);
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

   static jclass getNewSimulatedKinematicsPlausibleClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SimulatedKinematicsPlausible");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SimulatedKinematicsPlausible" << std::endl;
       }
       return clss;
   }
   
   static jclass SimulatedKinematicsPlausibleClass = NULL;
   static inline jclass getSimulatedKinematicsPlausibleClass() {
       if (SimulatedKinematicsPlausibleClass != NULL) {
           return SimulatedKinematicsPlausibleClass;
       }
       SimulatedKinematicsPlausibleClass = getNewSimulatedKinematicsPlausibleClass();
   }
   
   // get JNI handle for class crcl.utils.GripperJFrame
   static inline jclass getGripperJFrameClass();
   
   GripperJFrame::GripperJFrame(jobject _jthis, bool copy): ::crclj::javax::swing::JFrame(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   GripperJFrame::GripperJFrame(const GripperJFrame &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   GripperJFrame::GripperJFrame() : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getGripperJFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class GripperJFrame has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::poseToJoints jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new GripperJFrame with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new GripperJFrame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.GripperJFrame
   GripperJFrame::~GripperJFrame() {
   	// Place-holder for later extensibility.
   }

   void GripperJFrame::setPort(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setPort of crcl.utils.GripperJFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::setPort jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setPort", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.GripperJFrame has no method named setPort with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::setPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jint GripperJFrame::getDelayMillis() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDelayMillis of crcl.utils.GripperJFrame with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::getDelayMillis jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getDelayMillis", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.GripperJFrame has no method named getDelayMillis with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::getDelayMillis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void GripperJFrame::setDelayMillis(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setDelayMillis of crcl.utils.GripperJFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::setDelayMillis jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setDelayMillis", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.GripperJFrame has no method named setDelayMillis with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::setDelayMillis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void GripperJFrame::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getGripperJFrameClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.GripperJFrame has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void GripperJFrame::main(int argc, const char **argv) {
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
   jint GripperJFrame::getPort() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPort of crcl.utils.GripperJFrame with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::getPort jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPort", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.GripperJFrame has no method named getPort with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," GripperJFrame::getPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewGripperJFrameClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/GripperJFrame");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/GripperJFrame" << std::endl;
       }
       return clss;
   }
   
   static jclass GripperJFrameClass = NULL;
   static inline jclass getGripperJFrameClass() {
       if (GripperJFrameClass != NULL) {
           return GripperJFrameClass;
       }
       GripperJFrameClass = getNewGripperJFrameClass();
   }
  } // end namespace utils

   namespace base{
   
   // get JNI handle for class crcl.base.RotAccelType
   static inline jclass getRotAccelTypeClass();
   
   RotAccelType::RotAccelType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   RotAccelType::RotAccelType(const RotAccelType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   RotAccelType::RotAccelType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getRotAccelTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class RotAccelType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," RotAccelType::getPort jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new RotAccelType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new RotAccelType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.RotAccelType
   RotAccelType::~RotAccelType() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewRotAccelTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/RotAccelType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/RotAccelType" << std::endl;
       }
       return clss;
   }
   
   static jclass RotAccelTypeClass = NULL;
   static inline jclass getRotAccelTypeClass() {
       if (RotAccelTypeClass != NULL) {
           return RotAccelTypeClass;
       }
       RotAccelTypeClass = getNewRotAccelTypeClass();
   }
   
   // get JNI handle for class crcl.base.ActuateJointsType
   static inline jclass getActuateJointsTypeClass();
   
   ActuateJointsType::ActuateJointsType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ActuateJointsType::ActuateJointsType(const ActuateJointsType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ActuateJointsType::ActuateJointsType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getActuateJointsTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ActuateJointsType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ActuateJointsType::getPort jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ActuateJointsType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ActuateJointsType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.ActuateJointsType
   ActuateJointsType::~ActuateJointsType() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::util::List ActuateJointsType::getActuateJoint() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getActuateJoint of crcl.base.ActuateJointsType with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ActuateJointsType::getActuateJoint jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getActuateJoint", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ActuateJointsType has no method named getActuateJoint with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ActuateJointsType::getActuateJoint jthis=",t);
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
   static jclass getNewActuateJointsTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/ActuateJointsType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/ActuateJointsType" << std::endl;
       }
       return clss;
   }
   
   static jclass ActuateJointsTypeClass = NULL;
   static inline jclass getActuateJointsTypeClass() {
       if (ActuateJointsTypeClass != NULL) {
           return ActuateJointsTypeClass;
       }
       ActuateJointsTypeClass = getNewActuateJointsTypeClass();
   }
   
   // get JNI handle for class crcl.base.MessageType
   static inline jclass getMessageTypeClass();
   
   MessageType::MessageType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   MessageType::MessageType(const MessageType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   MessageType::MessageType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getMessageTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class MessageType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," MessageType::getActuateJoint jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new MessageType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MessageType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.MessageType
   MessageType::~MessageType() {
   	// Place-holder for later extensibility.
   }

   void MessageType::setMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setMessage of crcl.base.MessageType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MessageType::setMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setMessage", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MessageType has no method named setMessage with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MessageType::setMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void MessageType::setMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setMessage of crcl.base.MessageType with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MessageType::setMessage jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jstring MessageType::getMessage() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getMessage of crcl.base.MessageType with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MessageType::getMessage jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getMessage", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.MessageType has no method named getMessage with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MessageType::getMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewMessageTypeClass() {
       jclass clss = getEnv()->FindClass("crcl/base/MessageType");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/base/MessageType" << std::endl;
       }
       return clss;
   }
   
   static jclass MessageTypeClass = NULL;
   static inline jclass getMessageTypeClass() {
       if (MessageTypeClass != NULL) {
           return MessageTypeClass;
       }
       MessageTypeClass = getNewMessageTypeClass();
   }
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

