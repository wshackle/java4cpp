
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.SimServerOuterStub
   static inline jclass getSimServerOuterStubClass();
   
   SimServerOuterStub::SimServerOuterStub(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SimServerOuterStub::SimServerOuterStub(const SimServerOuterStub &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SimServerOuterStub::SimServerOuterStub() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSimServerOuterStubClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SimServerOuterStub has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::getFraction jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SimServerOuterStub with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimServerOuterStub jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   SimServerOuterStub::SimServerOuterStub(jboolean boolean_0,jboolean boolean_1,jboolean boolean_2,jboolean boolean_3,jboolean boolean_4,jboolean boolean_5,jboolean boolean_6,jboolean boolean_7,jboolean boolean_8,jboolean boolean_9) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSimServerOuterStubClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(ZZZZZZZZZZ)V");
        if (NULL == mid) {
            std::cerr << "Class SimServerOuterStub has no method constructor signature (ZZZZZZZZZZ)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,boolean_0,boolean_1,boolean_2,boolean_3,boolean_4,boolean_5,boolean_6,boolean_7,boolean_8,boolean_9);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::getFraction jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SimServerOuterStub with signature (ZZZZZZZZZZ)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimServerOuterStub jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.SimServerOuterStub
   SimServerOuterStub::~SimServerOuterStub() {
   	// Place-holder for later extensibility.
   }

   void SimServerOuterStub::showMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showMessage of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::showMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showMessage", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named showMessage with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::showMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::showMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method showMessage of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::showMessage jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    showMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void SimServerOuterStub::showDebugMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showDebugMessage of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::showDebugMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showDebugMessage", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named showDebugMessage with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::showDebugMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::showDebugMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method showDebugMessage of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::showDebugMessage jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    showDebugMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jboolean SimServerOuterStub::isEXISelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEXISelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isEXISelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isEXISelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isEXISelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isEXISelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerOuterStub::updateConnectedClients(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateConnectedClients of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateConnectedClients jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateConnectedClients", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateConnectedClients with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateConnectedClients jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServerOuterStub::isValidateXMLSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isValidateXMLSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isValidateXMLSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isValidateXMLSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isValidateXMLSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isValidateXMLSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isSendStatusWithoutRequestSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isSendStatusWithoutRequestSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isSendStatusWithoutRequestSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isSendStatusWithoutRequestSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isSendStatusWithoutRequestSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isSendStatusWithoutRequestSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isAppendZeroSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAppendZeroSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isAppendZeroSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAppendZeroSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isAppendZeroSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isAppendZeroSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isRandomPacketSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isRandomPacketSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isRandomPacketSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isRandomPacketSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isRandomPacketSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isRandomPacketSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isReplaceStateSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isReplaceStateSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isReplaceStateSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isReplaceStateSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isReplaceStateSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isReplaceStateSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isEditingStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEditingStatus of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isEditingStatus jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isEditingStatus", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isEditingStatus with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isEditingStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerOuterStub::updateCycleCount(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateCycleCount of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateCycleCount jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateCycleCount", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateCycleCount with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateCycleCount jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::updatePanels(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updatePanels of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updatePanels jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updatePanels", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updatePanels with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updatePanels jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::updateIsInitialized(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateIsInitialized of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateIsInitialized jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateIsInitialized", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateIsInitialized with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateIsInitialized jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::updateCurrentCommandType(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateCurrentCommandType of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateCurrentCommandType jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateCurrentCommandType", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateCurrentCommandType with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateCurrentCommandType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::updateCurrentCommandType(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method updateCurrentCommandType of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateCurrentCommandType jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    updateCurrentCommandType(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void SimServerOuterStub::updateEndEffector(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateEndEffector of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateEndEffector jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateEndEffector", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateEndEffector with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateEndEffector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::updateEndEffector(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method updateEndEffector of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateEndEffector jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    updateEndEffector(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void SimServerOuterStub::updateToolChangerIsOpen(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateToolChangerIsOpen of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateToolChangerIsOpen jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateToolChangerIsOpen", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateToolChangerIsOpen with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateToolChangerIsOpen jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServerOuterStub::isInitializedSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isInitializedSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isInitializedSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isInitializedSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isInitializedSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isInitializedSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerOuterStub::finishSetCurrentWaypoint(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method finishSetCurrentWaypoint of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::finishSetCurrentWaypoint jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "finishSetCurrentWaypoint", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named finishSetCurrentWaypoint with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::finishSetCurrentWaypoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerOuterStub::updateNumWaypoints(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateNumWaypoints of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateNumWaypoints jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateNumWaypoints", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named updateNumWaypoints with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::updateNumWaypoints jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServerOuterStub::isDebugMoveDoneSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugMoveDoneSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isDebugMoveDoneSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugMoveDoneSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isDebugMoveDoneSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isDebugMoveDoneSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isDebugSendStatusSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugSendStatusSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isDebugSendStatusSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugSendStatusSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isDebugSendStatusSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isDebugSendStatusSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isDebugReadCommandSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugReadCommandSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isDebugReadCommandSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugReadCommandSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isDebugReadCommandSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isDebugReadCommandSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerOuterStub::isReplaceXmlHeaderSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isReplaceXmlHeaderSelected of crcl.utils.SimServerOuterStub with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isReplaceXmlHeaderSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isReplaceXmlHeaderSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerOuterStub has no method named isReplaceXmlHeaderSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuterStub::isReplaceXmlHeaderSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewSimServerOuterStubClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SimServerOuterStub");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SimServerOuterStub" << std::endl;
       }
       return clss;
   }
   
   static jclass SimServerOuterStubClass = NULL;
   static inline jclass getSimServerOuterStubClass() {
       if (SimServerOuterStubClass != NULL) {
           return SimServerOuterStubClass;
       }
       SimServerOuterStubClass = getNewSimServerOuterStubClass();
   }
   
   // get JNI handle for class crcl.utils.SimServerOuter
   static inline jclass getSimServerOuterClass();
   
   SimServerOuter::SimServerOuter(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SimServerOuter::SimServerOuter(const SimServerOuter &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SimServerOuter::SimServerOuter() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getSimServerOuterClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class SimServerOuter has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerOuter::isReplaceXmlHeaderSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new SimServerOuter with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimServerOuter jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for crcl.utils.SimServerOuter
   SimServerOuter::~SimServerOuter() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewSimServerOuterClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SimServerOuter");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SimServerOuter" << std::endl;
       }
       return clss;
   }
   
   static jclass SimServerOuterClass = NULL;
   static inline jclass getSimServerOuterClass() {
       if (SimServerOuterClass != NULL) {
           return SimServerOuterClass;
       }
       SimServerOuterClass = getNewSimServerOuterClass();
   }
   
   // get JNI handle for class crcl.utils.SimServerInner
   static inline jclass getSimServerInnerClass();
   
   SimServerInner::SimServerInner(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SimServerInner::SimServerInner(const SimServerInner &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SimServerInner::SimServerInner() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getSimServerInnerClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class SimServerInner has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::isReplaceXmlHeaderSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new SimServerInner with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimServerInner jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   SimServerInner::SimServerInner(SimServerOuter  &simServerOuter_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSimServerInnerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lcrcl/utils/SimServerOuter;)V");
        if (NULL == mid) {
            std::cerr << "Class SimServerInner has no method constructor signature (Lcrcl/utils/SimServerOuter;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,simServerOuter_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SimServerInner::isReplaceXmlHeaderSelected jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SimServerInner with signature (Lcrcl/utils/SimServerOuter;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimServerInner jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.SimServerInner
   SimServerInner::~SimServerInner() {
   	// Place-holder for later extensibility.
   }

   ::crclj::crcl::base::CRCLStatusType SimServerInner::getStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatus of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatus", "()Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getStatus with signature ()Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLStatusType retObject(retVal,false);
    return retObject;
   }
   void SimServerInner::setCmdSchema(jobjectArray fileArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCmdSchema of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCmdSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCmdSchema", "([Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCmdSchema with signature ([Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCmdSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::setStatSchema(jobjectArray fileArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatSchema of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setStatSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatSchema", "([Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setStatSchema with signature ([Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setStatSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServerInner::isMoveStraight() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMoveStraight of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::isMoveStraight jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMoveStraight", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named isMoveStraight with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::isMoveStraight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setMoveStraight(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setMoveStraight of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setMoveStraight jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setMoveStraight", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setMoveStraight with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setMoveStraight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::setJointPosition(jdouble double_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointPosition of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setJointPosition jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointPosition", "(DI)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setJointPosition with signature (DI)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setJointPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdoubleArray SimServerInner::getSeglengths() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSeglengths of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getSeglengths jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSeglengths", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getSeglengths with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setPort(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setPort of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setPort jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setPort", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setPort with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jlong SimServerInner::getDelayMillis() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDelayMillis of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getDelayMillis jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getDelayMillis", "()J");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getDelayMillis with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getDelayMillis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setDelayMillis(jlong long_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setDelayMillis of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setDelayMillis jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setDelayMillis", "(J)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setDelayMillis with signature (J)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setDelayMillis jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::restartServer() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method restartServer of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::restartServer jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "restartServer", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named restartServer with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::restartServer jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::updateConnectedClients() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateConnectedClients of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::updateConnectedClients jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateConnectedClients", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named updateConnectedClients with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::updateConnectedClients jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   XpathUtils SimServerInner::getXpu() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getXpu of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       XpathUtils nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getXpu jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getXpu", "()Lcrcl/utils/XpathUtils;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getXpu with signature ()Lcrcl/utils/XpathUtils;." << std::endl;
           XpathUtils nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getXpu jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    XpathUtils retObject(retVal,false);
    return retObject;
   }
   void SimServerInner::simulatedTeleportToPose(::crclj::crcl::base::PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method simulatedTeleportToPose of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::simulatedTeleportToPose jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "simulatedTeleportToPose", "(Lcrcl/base/PoseType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named simulatedTeleportToPose with signature (Lcrcl/base/PoseType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::simulatedTeleportToPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::setCommandedJointPosition(jdouble double_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandedJointPosition of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedJointPosition jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandedJointPosition", "(DI)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCommandedJointPosition with signature (DI)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedJointPosition jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdoubleArray SimServerInner::getJointPositions() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointPositions of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getJointPositions jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointPositions", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getJointPositions with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getJointPositions jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setGoalPose(::crclj::crcl::base::PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setGoalPose of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setGoalPose jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setGoalPose", "(Lcrcl/base/PoseType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setGoalPose with signature (Lcrcl/base/PoseType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setGoalPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServerInner::isFinishedMove() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isFinishedMove of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::isFinishedMove jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isFinishedMove", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named isFinishedMove with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::isFinishedMove jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServerInner::checkPose(::crclj::crcl::base::PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkPose of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::checkPose jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkPose", "(Lcrcl/base/PoseType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named checkPose with signature (Lcrcl/base/PoseType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::checkPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble SimServerInner::getJointSpeedMax() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointSpeedMax of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getJointSpeedMax jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointSpeedMax", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getJointSpeedMax with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getJointSpeedMax jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setJointSpeedMax(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointSpeedMax of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setJointSpeedMax jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointSpeedMax", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setJointSpeedMax with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setJointSpeedMax jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::PoseType SimServerInner::limitSpeedAccel(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method limitSpeedAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::limitSpeedAccel jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "limitSpeedAccel", "(Lcrcl/base/PoseType;Lcrcl/base/PoseType;)Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named limitSpeedAccel with signature (Lcrcl/base/PoseType;Lcrcl/base/PoseType;)Lcrcl/base/PoseType;." << std::endl;
           ::crclj::crcl::base::PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,poseType_0.jthis,poseType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::limitSpeedAccel jthis=",t);
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
   jdoubleArray SimServerInner::getStraightMoveCommandedJointVals(::crclj::crcl::base::PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStraightMoveCommandedJointVals of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getStraightMoveCommandedJointVals jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStraightMoveCommandedJointVals", "(Lcrcl/base/PoseType;)[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getStraightMoveCommandedJointVals with signature (Lcrcl/base/PoseType;)[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getStraightMoveCommandedJointVals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatus of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatus", "(Lcrcl/base/CRCLStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setStatus with signature (Lcrcl/base/CRCLStatusType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::closeServer() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method closeServer of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::closeServer jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "closeServer", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named closeServer with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::closeServer jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::javax::xml::datatype::XMLGregorianCalendar SimServerInner::getXMLGregorianCalendarNow() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getXMLGregorianCalendarNow of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       ::crclj::javax::xml::datatype::XMLGregorianCalendar nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getXMLGregorianCalendarNow jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getXMLGregorianCalendarNow", "()Ljavax/xml/datatype/XMLGregorianCalendar;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getXMLGregorianCalendarNow with signature ()Ljavax/xml/datatype/XMLGregorianCalendar;." << std::endl;
           ::crclj::javax::xml::datatype::XMLGregorianCalendar nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getXMLGregorianCalendarNow jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::datatype::XMLGregorianCalendar retObject(retVal,false);
    return retObject;
   }
   void SimServerInner::goalPoseToCommandedPositions(::crclj::crcl::base::PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method goalPoseToCommandedPositions of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::goalPoseToCommandedPositions jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "goalPoseToCommandedPositions", "(Lcrcl/base/PoseType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named goalPoseToCommandedPositions with signature (Lcrcl/base/PoseType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::goalPoseToCommandedPositions jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jint SimServerInner::getCurrentWaypoint() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCurrentWaypoint of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurrentWaypoint jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCurrentWaypoint", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCurrentWaypoint with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurrentWaypoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCurrentWaypoint(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCurrentWaypoint of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurrentWaypoint jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCurrentWaypoint", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCurrentWaypoint with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurrentWaypoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::printClientStates(::crclj::java::io::PrintStream  &printStream_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method printClientStates of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::printClientStates jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "printClientStates", "(Ljava/io/PrintStream;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named printClientStates with signature (Ljava/io/PrintStream;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,printStream_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::printClientStates jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::printAllClientStates(::crclj::java::io::PrintStream  &printStream_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getSimServerInnerClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "printAllClientStates", "(Ljava/io/PrintStream;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named printAllClientStates with signature (Ljava/io/PrintStream;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,printStream_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::printAllClientStates jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServerInner::runAcceptClients() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method runAcceptClients of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::runAcceptClients jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "runAcceptClients", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named runAcceptClients with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::runAcceptClients jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCurTransSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCurTransSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurTransSpeed jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCurTransSpeed", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCurTransSpeed with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCurTransSpeed(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCurTransSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurTransSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCurTransSpeed", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCurTransSpeed with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCommandedTransSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandedTransSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedTransSpeed jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandedTransSpeed", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCommandedTransSpeed with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCommandedTransSpeed(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandedTransSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedTransSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandedTransSpeed", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCommandedTransSpeed with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedTransSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCurTransAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCurTransAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurTransAccel jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCurTransAccel", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCurTransAccel with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCurTransAccel(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCurTransAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurTransAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCurTransAccel", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCurTransAccel with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCommandedTransAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandedTransAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedTransAccel jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandedTransAccel", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCommandedTransAccel with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCommandedTransAccel(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandedTransAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedTransAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandedTransAccel", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCommandedTransAccel with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedTransAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCurRotSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCurRotSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurRotSpeed jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCurRotSpeed", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCurRotSpeed with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCurRotSpeed(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCurRotSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurRotSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCurRotSpeed", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCurRotSpeed with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCommandedRotSpeed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandedRotSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedRotSpeed jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandedRotSpeed", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCommandedRotSpeed with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCommandedRotSpeed(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandedRotSpeed of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedRotSpeed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandedRotSpeed", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCommandedRotSpeed with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedRotSpeed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCurRotAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCurRotAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurRotAccel jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCurRotAccel", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCurRotAccel with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCurRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCurRotAccel(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCurRotAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurRotAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCurRotAccel", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCurRotAccel with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCurRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble SimServerInner::getCommandedRotAccel() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandedRotAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedRotAccel jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandedRotAccel", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCommandedRotAccel with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCommandedRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServerInner::setCommandedRotAccel(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandedRotAccel of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedRotAccel jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandedRotAccel", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setCommandedRotAccel with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setCommandedRotAccel jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::PoseToleranceType SimServerInner::getExpectedEndPoseTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getExpectedEndPoseTolerance of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getExpectedEndPoseTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getExpectedEndPoseTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getExpectedEndPoseTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getExpectedEndPoseTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseToleranceType retObject(retVal,false);
    return retObject;
   }
   void SimServerInner::setExpectedEndPoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExpectedEndPoseTolerance of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setExpectedEndPoseTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExpectedEndPoseTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setExpectedEndPoseTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setExpectedEndPoseTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::PoseToleranceType SimServerInner::getExpectedIntermediatePoseTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getExpectedIntermediatePoseTolerance of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getExpectedIntermediatePoseTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getExpectedIntermediatePoseTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getExpectedIntermediatePoseTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getExpectedIntermediatePoseTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::PoseToleranceType retObject(retVal,false);
    return retObject;
   }
   void SimServerInner::setExpectedIntermediatePoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExpectedIntermediatePoseTolerance of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setExpectedIntermediatePoseTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExpectedIntermediatePoseTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setExpectedIntermediatePoseTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setExpectedIntermediatePoseTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::util::List SimServerInner::getWaypoints() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getWaypoints of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getWaypoints jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getWaypoints", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getWaypoints with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getWaypoints jthis=",t);
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
   void SimServerInner::setWaypoints(::crclj::java::util::List  &list_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setWaypoints of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setWaypoints jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setWaypoints", "(Ljava/util/List;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named setWaypoints with signature (Ljava/util/List;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,list_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::setWaypoints jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring SimServerInner::getStatusXmlString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatusXmlString of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getStatusXmlString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatusXmlString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getStatusXmlString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getStatusXmlString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   CRCLSocket SimServerInner::getCheckerCRCLSocket() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCheckerCRCLSocket of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       CRCLSocket nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCheckerCRCLSocket jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCheckerCRCLSocket", "()Lcrcl/utils/CRCLSocket;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getCheckerCRCLSocket with signature ()Lcrcl/utils/CRCLSocket;." << std::endl;
           CRCLSocket nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getCheckerCRCLSocket jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CRCLSocket retObject(retVal,false);
    return retObject;
   }
   void SimServerInner::reset() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method reset of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::reset jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "reset", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named reset with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::reset jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jint SimServerInner::getPort() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPort of crcl.utils.SimServerInner with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getPort jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPort", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServerInner has no method named getPort with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServerInner::getPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewSimServerInnerClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SimServerInner");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SimServerInner" << std::endl;
       }
       return clss;
   }
   
   static jclass SimServerInnerClass = NULL;
   static inline jclass getSimServerInnerClass() {
       if (SimServerInnerClass != NULL) {
           return SimServerInnerClass;
       }
       SimServerInnerClass = getNewSimServerInnerClass();
   }
   
   // get JNI handle for class crcl.utils.MultiLineStringJPanel
   static inline jclass getMultiLineStringJPanelClass();
   
   MultiLineStringJPanel::MultiLineStringJPanel(jobject _jthis, bool copy): ::crclj::javax::swing::JPanel(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   MultiLineStringJPanel::MultiLineStringJPanel(const MultiLineStringJPanel &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   MultiLineStringJPanel::MultiLineStringJPanel() : ::crclj::javax::swing::JPanel((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getMultiLineStringJPanelClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class MultiLineStringJPanel has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," MultiLineStringJPanel::getPort jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new MultiLineStringJPanel with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MultiLineStringJPanel jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.MultiLineStringJPanel
   MultiLineStringJPanel::~MultiLineStringJPanel() {
   	// Place-holder for later extensibility.
   }

   jstring MultiLineStringJPanel::editText(jstring string_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getMultiLineStringJPanelClass();
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "editText", "(Ljava/lang/String;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.MultiLineStringJPanel has no method named editText with signature (Ljava/lang/String;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallStaticObjectMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MultiLineStringJPanel::editText jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring MultiLineStringJPanel::editText(jstring string_0,::crclj::java::awt::Frame  &frame_1,jstring string_2,jboolean boolean_3) {

   JNIEnv *env =getEnv();
   static jclass cls = getMultiLineStringJPanelClass();
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "editText", "(Ljava/lang/String;Ljava/awt/Frame;Ljava/lang/String;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.MultiLineStringJPanel has no method named editText with signature (Ljava/lang/String;Ljava/awt/Frame;Ljava/lang/String;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallStaticObjectMethod( cls, mid ,string_0,frame_1.jthis,string_2,boolean_3 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MultiLineStringJPanel::editText jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean MultiLineStringJPanel::showText(jstring string_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getMultiLineStringJPanelClass();
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "showText", "(Ljava/lang/String;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.MultiLineStringJPanel has no method named showText with signature (Ljava/lang/String;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallStaticBooleanMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MultiLineStringJPanel::showText jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean MultiLineStringJPanel::showText(jstring string_0,::crclj::java::awt::Frame  &frame_1,jstring string_2,jboolean boolean_3) {

   JNIEnv *env =getEnv();
   static jclass cls = getMultiLineStringJPanelClass();
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "showText", "(Ljava/lang/String;Ljava/awt/Frame;Ljava/lang/String;Z)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.MultiLineStringJPanel has no method named showText with signature (Ljava/lang/String;Ljava/awt/Frame;Ljava/lang/String;Z)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallStaticBooleanMethod( cls, mid ,string_0,frame_1.jthis,string_2,boolean_3 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MultiLineStringJPanel::showText jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewMultiLineStringJPanelClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/MultiLineStringJPanel");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/MultiLineStringJPanel" << std::endl;
       }
       return clss;
   }
   
   static jclass MultiLineStringJPanelClass = NULL;
   static inline jclass getMultiLineStringJPanelClass() {
       if (MultiLineStringJPanelClass != NULL) {
           return MultiLineStringJPanelClass;
       }
       MultiLineStringJPanelClass = getNewMultiLineStringJPanelClass();
   }
   
   // get JNI handle for class crcl.utils.ObjTableJPanel
   static inline jclass getObjTableJPanelClass();
   
   ObjTableJPanel::ObjTableJPanel(jobject _jthis, bool copy): ::crclj::javax::swing::JPanel(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ObjTableJPanel::ObjTableJPanel(const ObjTableJPanel &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ObjTableJPanel::ObjTableJPanel() : ::crclj::javax::swing::JPanel((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getObjTableJPanelClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ObjTableJPanel has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::showText jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ObjTableJPanel with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ObjTableJPanel jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.ObjTableJPanel
   ObjTableJPanel::~ObjTableJPanel() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::lang::Object ObjTableJPanel::getObj() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getObj of crcl.utils.ObjTableJPanel with jthis == NULL." << std::endl;
       ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::getObj jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getObj", "()Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ObjTableJPanel has no method named getObj with signature ()Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::getObj jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::lang::Object retObject(retVal,false);
    return retObject;
   }
   void ObjTableJPanel::setObj(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setObj of crcl.utils.ObjTableJPanel with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::setObj jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setObj", "(Ljava/lang/Object;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ObjTableJPanel has no method named setObj with signature (Ljava/lang/Object;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::setObj jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::lang::Object ObjTableJPanel::editObject(::crclj::java::lang::Object  &object_0,XpathUtils  &xpathUtils_1,::crclj::java::util::function::Predicate  &predicate_2) {

   JNIEnv *env =getEnv();
   static jclass cls = getObjTableJPanelClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "editObject", "(Ljava/lang/Object;Lcrcl/utils/XpathUtils;Ljava/util/function/Predicate;)Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ObjTableJPanel has no method named editObject with signature (Ljava/lang/Object;Lcrcl/utils/XpathUtils;Ljava/util/function/Predicate;)Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis,xpathUtils_1.jthis,predicate_2.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::editObject jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::lang::Object retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::lang::Object ObjTableJPanel::editObject(::crclj::java::lang::Object  &object_0,::crclj::java::awt::Frame  &frame_1,jstring string_2,jboolean boolean_3,XpathUtils  &xpathUtils_4,::crclj::java::util::function::Predicate  &predicate_5) {

   JNIEnv *env =getEnv();
   static jclass cls = getObjTableJPanelClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "editObject", "(Ljava/lang/Object;Ljava/awt/Frame;Ljava/lang/String;ZLcrcl/utils/XpathUtils;Ljava/util/function/Predicate;)Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ObjTableJPanel has no method named editObject with signature (Ljava/lang/Object;Ljava/awt/Frame;Ljava/lang/String;ZLcrcl/utils/XpathUtils;Ljava/util/function/Predicate;)Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis,frame_1.jthis,string_2,boolean_3,xpathUtils_4.jthis,predicate_5.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::editObject jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::lang::Object retObject(retVal,false);
    return retObject;
   }
   void ObjTableJPanel::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getObjTableJPanelClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ObjTableJPanel has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void ObjTableJPanel::main(int argc, const char **argv) {
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
   ::crclj::java::util::List ObjTableJPanel::getClasses() {

   JNIEnv *env =getEnv();
   static jclass cls = getObjTableJPanelClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getClasses", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ObjTableJPanel has no method named getClasses with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ObjTableJPanel::getClasses jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::List retObject(retVal,false);
    return retObject;
   }
   static jclass getNewObjTableJPanelClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/ObjTableJPanel");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/ObjTableJPanel" << std::endl;
       }
       return clss;
   }
   
   static jclass ObjTableJPanelClass = NULL;
   static inline jclass getObjTableJPanelClass() {
       if (ObjTableJPanelClass != NULL) {
           return ObjTableJPanelClass;
       }
       ObjTableJPanelClass = getNewObjTableJPanelClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

