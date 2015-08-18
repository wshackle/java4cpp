
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.SimServer
   static inline jclass getSimServerClass();
   
   SimServer::SimServer(jobject _jthis, bool copy): ::crclj::javax::swing::JFrame(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   SimServer::SimServer(const SimServer &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   SimServer::SimServer() : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getSimServerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class SimServer has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," SimServer::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new SimServer with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SimServer jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.SimServer
   SimServer::~SimServer() {
   	// Place-holder for later extensibility.
   }

   jboolean SimServer::checkStatusValid(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkStatusValid of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::checkStatusValid jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkStatusValid", "(Lcrcl/base/CRCLStatusType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named checkStatusValid with signature (Lcrcl/base/CRCLStatusType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::checkStatusValid jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isToolChangerOpen() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isToolChangerOpen of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isToolChangerOpen jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isToolChangerOpen", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isToolChangerOpen with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isToolChangerOpen jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServer::setToolChangerOpen(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setToolChangerOpen of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::setToolChangerOpen jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setToolChangerOpen", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named setToolChangerOpen with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::setToolChangerOpen jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::showMessage(::crclj::java::lang::Throwable  &throwable_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showMessage of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::showMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showMessage", "(Ljava/lang/Throwable;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named showMessage with signature (Ljava/lang/Throwable;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,throwable_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::showMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::showMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showMessage of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::showMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showMessage", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named showMessage with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::showMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::showMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method showMessage of crcl.utils.SimServer with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::showMessage jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    showMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void SimServer::showDebugMessage(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method showDebugMessage of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::showDebugMessage jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "showDebugMessage", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named showDebugMessage with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::showDebugMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::showDebugMessage(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method showDebugMessage of crcl.utils.SimServer with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::showDebugMessage jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    showDebugMessage(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jboolean SimServer::isEXISelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEXISelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isEXISelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isEXISelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isEXISelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isEXISelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServer::updateConnectedClients(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateConnectedClients of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateConnectedClients jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateConnectedClients", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateConnectedClients with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateConnectedClients jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServer::isValidateXMLSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isValidateXMLSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isValidateXMLSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isValidateXMLSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isValidateXMLSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isValidateXMLSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isSendStatusWithoutRequestSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isSendStatusWithoutRequestSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isSendStatusWithoutRequestSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isSendStatusWithoutRequestSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isSendStatusWithoutRequestSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isSendStatusWithoutRequestSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isAppendZeroSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAppendZeroSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isAppendZeroSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAppendZeroSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isAppendZeroSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isAppendZeroSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isRandomPacketSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isRandomPacketSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isRandomPacketSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isRandomPacketSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isRandomPacketSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isRandomPacketSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isReplaceStateSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isReplaceStateSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isReplaceStateSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isReplaceStateSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isReplaceStateSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isReplaceStateSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isEditingStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEditingStatus of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isEditingStatus jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isEditingStatus", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isEditingStatus with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isEditingStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServer::updateCycleCount(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateCycleCount of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateCycleCount jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateCycleCount", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateCycleCount with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateCycleCount jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::updatePanels(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updatePanels of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updatePanels jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updatePanels", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updatePanels with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updatePanels jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::updateIsInitialized(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateIsInitialized of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateIsInitialized jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateIsInitialized", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateIsInitialized with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateIsInitialized jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::updateCurrentCommandType(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateCurrentCommandType of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateCurrentCommandType jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateCurrentCommandType", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateCurrentCommandType with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateCurrentCommandType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::updateCurrentCommandType(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method updateCurrentCommandType of crcl.utils.SimServer with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateCurrentCommandType jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    updateCurrentCommandType(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void SimServer::updateEndEffector(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateEndEffector of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateEndEffector jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateEndEffector", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateEndEffector with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateEndEffector jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::updateEndEffector(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method updateEndEffector of crcl.utils.SimServer with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateEndEffector jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    updateEndEffector(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void SimServer::updateToolChangerIsOpen(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateToolChangerIsOpen of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateToolChangerIsOpen jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateToolChangerIsOpen", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateToolChangerIsOpen with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateToolChangerIsOpen jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServer::isInitializedSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isInitializedSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isInitializedSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isInitializedSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isInitializedSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isInitializedSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServer::finishSetCurrentWaypoint(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method finishSetCurrentWaypoint of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::finishSetCurrentWaypoint jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "finishSetCurrentWaypoint", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named finishSetCurrentWaypoint with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::finishSetCurrentWaypoint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServer::checkPose(::crclj::crcl::base::PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkPose of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::checkPose jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkPose", "(Lcrcl/base/PoseType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named checkPose with signature (Lcrcl/base/PoseType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::checkPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServer::updateNumWaypoints(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateNumWaypoints of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::updateNumWaypoints jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateNumWaypoints", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named updateNumWaypoints with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::updateNumWaypoints jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean SimServer::isDebugMoveDoneSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugMoveDoneSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isDebugMoveDoneSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugMoveDoneSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isDebugMoveDoneSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isDebugMoveDoneSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isDebugSendStatusSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugSendStatusSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isDebugSendStatusSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugSendStatusSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isDebugSendStatusSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isDebugSendStatusSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isDebugReadCommandSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDebugReadCommandSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isDebugReadCommandSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDebugReadCommandSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isDebugReadCommandSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isDebugReadCommandSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean SimServer::isReplaceXmlHeaderSelected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isReplaceXmlHeaderSelected of crcl.utils.SimServer with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SimServer::isReplaceXmlHeaderSelected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isReplaceXmlHeaderSelected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named isReplaceXmlHeaderSelected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::isReplaceXmlHeaderSelected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void SimServer::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getSimServerClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.SimServer has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," SimServer::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void SimServer::main(int argc, const char **argv) {
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
   static jclass getNewSimServerClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/SimServer");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/SimServer" << std::endl;
       }
       return clss;
   }
   
   static jclass SimServerClass = NULL;
   static inline jclass getSimServerClass() {
       if (SimServerClass != NULL) {
           return SimServerClass;
       }
       SimServerClass = getNewSimServerClass();
   }
   
   // get JNI handle for class crcl.utils.CmdLineSimServer
   static inline jclass getCmdLineSimServerClass();
   
   CmdLineSimServer::CmdLineSimServer(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CmdLineSimServer::CmdLineSimServer(const CmdLineSimServer &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CmdLineSimServer::CmdLineSimServer() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCmdLineSimServerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CmdLineSimServer has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CmdLineSimServer::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CmdLineSimServer with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CmdLineSimServer jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.CmdLineSimServer
   CmdLineSimServer::~CmdLineSimServer() {
   	// Place-holder for later extensibility.
   }

   void CmdLineSimServer::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCmdLineSimServerClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CmdLineSimServer has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CmdLineSimServer::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CmdLineSimServer::main(int argc, const char **argv) {
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
   static jclass getNewCmdLineSimServerClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/CmdLineSimServer");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/CmdLineSimServer" << std::endl;
       }
       return clss;
   }
   
   static jclass CmdLineSimServerClass = NULL;
   static inline jclass getCmdLineSimServerClass() {
       if (CmdLineSimServerClass != NULL) {
           return CmdLineSimServerClass;
       }
       CmdLineSimServerClass = getNewCmdLineSimServerClass();
   }
  } // end namespace utils
 } // end namespace crcl

  namespace rcs{
   namespace posemath{
   
   // get JNI handle for class rcs.posemath.PmPose
   static inline jclass getPmPoseClass();
   
   PmPose::PmPose(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PmPose::PmPose(const PmPose &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PmPose::PmPose(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3,jdouble double_4,jdouble double_5,jdouble double_6) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmPoseClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDDDDDD)V");
        if (NULL == mid) {
            std::cerr << "Class PmPose has no method constructor signature (DDDDDDD)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0,double_1,double_2,double_3,double_4,double_5,double_6);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmPose::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmPose with signature (DDDDDDD)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmPose jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmPose::PmPose() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmPoseClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PmPose has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmPose::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmPose with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmPose jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmPose::PmPose(PmCartesian  &pmCartesian_0,PmQuaternion  &pmQuaternion_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmPoseClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;)V");
        if (NULL == mid) {
            std::cerr << "Class PmPose has no method constructor signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmCartesian_0.jthis,pmQuaternion_1.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmPose::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmPose with signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmPose jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmPose::PmPose(PmCartesian  &pmCartesian_0,PmRpy  &pmRpy_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmPoseClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRpy;)V");
        if (NULL == mid) {
            std::cerr << "Class PmPose has no method constructor signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRpy;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmCartesian_0.jthis,pmRpy_1.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmPose::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmPose with signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmRpy;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmPose jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for rcs.posemath.PmPose
   PmPose::~PmPose() {
   	// Place-holder for later extensibility.
   }

   jfloatArray PmPose::toMatFloatArrayTranspose() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toMatFloatArrayTranspose of rcs.posemath.PmPose with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmPose::toMatFloatArrayTranspose jthis=",jthis);
   jfloatArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toMatFloatArrayTranspose", "()[F");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmPose has no method named toMatFloatArrayTranspose with signature ()[F." << std::endl;
           return NULL;
       } else {
           retVal= (jfloatArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmPose::toMatFloatArrayTranspose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PmPose::equals(PmPose  &pmPose_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of rcs.posemath.PmPose with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmPose::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Lrcs/posemath/PmPose;)Z");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmPose has no method named equals with signature (Lrcs/posemath/PmPose;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,pmPose_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmPose::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring PmPose::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of rcs.posemath.PmPose with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmPose::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmPose has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmPose::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   PmPose PmPose::clone() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clone of rcs.posemath.PmPose with jthis == NULL." << std::endl;
       PmPose nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmPose::clone jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "clone", "()Lrcs/posemath/PmPose;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmPose has no method named clone with signature ()Lrcs/posemath/PmPose;." << std::endl;
           PmPose nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmPose::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmPose retObject(retVal,false);
    return retObject;
   }
   static jclass getNewPmPoseClass() {
       jclass clss = getEnv()->FindClass("rcs/posemath/PmPose");
       if (NULL == clss) {
           std::cerr << " Can't find class rcs/posemath/PmPose" << std::endl;
       }
       return clss;
   }
   
   static jclass PmPoseClass = NULL;
   static inline jclass getPmPoseClass() {
       if (PmPoseClass != NULL) {
           return PmPoseClass;
       }
       PmPoseClass = getNewPmPoseClass();
   }
  } // end namespace posemath
 } // end namespace rcs

  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.AnnotatedPose
   static inline jclass getAnnotatedPoseClass();
   
   AnnotatedPose::AnnotatedPose(jobject _jthis, bool copy): ::crclj::rcs::posemath::PmPose(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   AnnotatedPose::AnnotatedPose(const AnnotatedPose &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   AnnotatedPose::AnnotatedPose() : ::crclj::rcs::posemath::PmPose((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getAnnotatedPoseClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class AnnotatedPose has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new AnnotatedPose with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new AnnotatedPose jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   AnnotatedPose::AnnotatedPose(jlong long_0,::crclj::java::math::BigInteger  &bigInteger_1,jstring string_2,::crclj::rcs::posemath::PmCartesian  &pmCartesian_3,::crclj::rcs::posemath::PmQuaternion  &pmQuaternion_4,::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_5) : ::crclj::rcs::posemath::PmPose((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getAnnotatedPoseClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(JLjava/math/BigInteger;Ljava/lang/String;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;Lcrcl/base/CRCLStatusType;)V");
        if (NULL == mid) {
            std::cerr << "Class AnnotatedPose has no method constructor signature (JLjava/math/BigInteger;Ljava/lang/String;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;Lcrcl/base/CRCLStatusType;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,long_0,bigInteger_1.jthis,string_2,pmCartesian_3.jthis,pmQuaternion_4.jthis,cRCLStatusType_5.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::clone jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new AnnotatedPose with signature (JLjava/math/BigInteger;Ljava/lang/String;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;Lcrcl/base/CRCLStatusType;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new AnnotatedPose jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   AnnotatedPose::AnnotatedPose(jlong easyArg_0,::crclj::java::math::BigInteger easyArg_1,const char * easyArg_2,::crclj::rcs::posemath::PmCartesian easyArg_3,::crclj::rcs::posemath::PmQuaternion easyArg_4,::crclj::crcl::base::CRCLStatusType easyArg_5) : ::crclj::rcs::posemath::PmPose((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getAnnotatedPoseClass();
   jlong long_0= easyArg_0;
   ::crclj::java::math::BigInteger  &bigInteger_1= easyArg_1;
   jstring string_2 = env->NewStringUTF(easyArg_2);
   ::crclj::rcs::posemath::PmCartesian  &pmCartesian_3= easyArg_3;
   ::crclj::rcs::posemath::PmQuaternion  &pmQuaternion_4= easyArg_4;
   ::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_5= easyArg_5;
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(JLjava/math/BigInteger;Ljava/lang/String;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;Lcrcl/base/CRCLStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class AnnotatedPose has no method constructor signature (JLjava/math/BigInteger;Ljava/lang/String;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;Lcrcl/base/CRCLStatusType;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,long_0,bigInteger_1.jthis,string_2,pmCartesian_3.jthis,pmQuaternion_4.jthis,cRCLStatusType_5.jthis);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new AnnotatedPose with signature (JLjava/math/BigInteger;Ljava/lang/String;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmQuaternion;Lcrcl/base/CRCLStatusType;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new AnnotatedPose jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   jobjectRefType ref_2 = env->GetObjectRefType(string_2);
   if(ref_2 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_2);
   }
   
   releaseEnv(env);
   }

   // Destructor for crcl.utils.AnnotatedPose
   AnnotatedPose::~AnnotatedPose() {
   	// Place-holder for later extensibility.
   }

   jlong AnnotatedPose::getTime() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTime of crcl.utils.AnnotatedPose with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getTime jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTime", "()J");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.AnnotatedPose has no method named getTime with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getTime jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::crcl::base::CRCLStatusType AnnotatedPose::getStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatus of crcl.utils.AnnotatedPose with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatus", "()Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.AnnotatedPose has no method named getStatus with signature ()Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getStatus jthis=",t);
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
   ::crclj::java::math::BigInteger AnnotatedPose::getCmdId() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCmdId of crcl.utils.AnnotatedPose with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getCmdId jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCmdId", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.AnnotatedPose has no method named getCmdId with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getCmdId jthis=",t);
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
   jstring AnnotatedPose::getCommandName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandName of crcl.utils.AnnotatedPose with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getCommandName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.AnnotatedPose has no method named getCommandName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getCommandName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::rcs::posemath::PmCartesian AnnotatedPose::getTran() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTran of crcl.utils.AnnotatedPose with jthis == NULL." << std::endl;
       ::crclj::rcs::posemath::PmCartesian nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getTran jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTran", "()Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.AnnotatedPose has no method named getTran with signature ()Lrcs/posemath/PmCartesian;." << std::endl;
           ::crclj::rcs::posemath::PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getTran jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmCartesian retObject(retVal,false);
    return retObject;
   }
   ::crclj::rcs::posemath::PmQuaternion AnnotatedPose::getRot() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getRot of crcl.utils.AnnotatedPose with jthis == NULL." << std::endl;
       ::crclj::rcs::posemath::PmQuaternion nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getRot jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getRot", "()Lrcs/posemath/PmQuaternion;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.AnnotatedPose has no method named getRot with signature ()Lrcs/posemath/PmQuaternion;." << std::endl;
           ::crclj::rcs::posemath::PmQuaternion nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," AnnotatedPose::getRot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::rcs::posemath::PmQuaternion retObject(retVal,false);
    return retObject;
   }
   static jclass getNewAnnotatedPoseClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/AnnotatedPose");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/AnnotatedPose" << std::endl;
       }
       return clss;
   }
   
   static jclass AnnotatedPoseClass = NULL;
   static inline jclass getAnnotatedPoseClass() {
       if (AnnotatedPoseClass != NULL) {
           return AnnotatedPoseClass;
       }
       AnnotatedPoseClass = getNewAnnotatedPoseClass();
   }
   
   // get JNI handle for class crcl.utils.CRCLSocket
   static inline jclass getCRCLSocketClass();
   
   CRCLSocket::CRCLSocket(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CRCLSocket::CRCLSocket(const CRCLSocket &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CRCLSocket::CRCLSocket() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class CRCLSocket has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getRot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new CRCLSocket with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLSocket jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   CRCLSocket::CRCLSocket(jstring string_0,jint int_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCRCLSocketClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
        if (NULL == mid) {
            std::cerr << "Class CRCLSocket has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0,int_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getRot jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CRCLSocket with signature (Ljava/lang/String;I)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLSocket jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   CRCLSocket::CRCLSocket(const char * easyArg_0,jint easyArg_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   jint int_1= easyArg_1;
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
       if (NULL == mid) {
           std::cerr << "Class CRCLSocket has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0,int_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getRot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new CRCLSocket with signature (Ljava/lang/String;I)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLSocket jthis=",jthis);
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

   // Destructor for crcl.utils.CRCLSocket
   CRCLSocket::~CRCLSocket() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::net::InetAddress CRCLSocket::getInetAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getInetAddress of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::java::net::InetAddress nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getInetAddress jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getInetAddress", "()Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getInetAddress with signature ()Ljava/net/InetAddress;." << std::endl;
           ::crclj::java::net::InetAddress nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getInetAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::net::InetAddress retObject(retVal,false);
    return retObject;
   }
   jboolean CRCLSocket::isConnected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isConnected of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isConnected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isConnected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named isConnected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isConnected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint CRCLSocket::getLocalPort() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLocalPort of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getLocalPort jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getLocalPort", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getLocalPort with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getLocalPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::util::function::UnaryOperator CRCLSocket::getStatusStringInputFilter() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatusStringInputFilter of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::java::util::function::UnaryOperator nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getStatusStringInputFilter jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatusStringInputFilter", "()Ljava/util/function/UnaryOperator;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getStatusStringInputFilter with signature ()Ljava/util/function/UnaryOperator;." << std::endl;
           ::crclj::java::util::function::UnaryOperator nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getStatusStringInputFilter jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::function::UnaryOperator retObject(retVal,false);
    return retObject;
   }
   void CRCLSocket::setStatusStringInputFilter(::crclj::java::util::function::UnaryOperator  &unaryOperator_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatusStringInputFilter of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setStatusStringInputFilter jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatusStringInputFilter", "(Ljava/util/function/UnaryOperator;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setStatusStringInputFilter with signature (Ljava/util/function/UnaryOperator;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,unaryOperator_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setStatusStringInputFilter jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::util::function::UnaryOperator CRCLSocket::getStatusStringOutputFilter() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatusStringOutputFilter of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::java::util::function::UnaryOperator nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getStatusStringOutputFilter jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatusStringOutputFilter", "()Ljava/util/function/UnaryOperator;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getStatusStringOutputFilter with signature ()Ljava/util/function/UnaryOperator;." << std::endl;
           ::crclj::java::util::function::UnaryOperator nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getStatusStringOutputFilter jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::function::UnaryOperator retObject(retVal,false);
    return retObject;
   }
   void CRCLSocket::setStatusStringOutputFilter(::crclj::java::util::function::UnaryOperator  &unaryOperator_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatusStringOutputFilter of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setStatusStringOutputFilter jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatusStringOutputFilter", "(Ljava/util/function/UnaryOperator;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setStatusStringOutputFilter with signature (Ljava/util/function/UnaryOperator;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,unaryOperator_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setStatusStringOutputFilter jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean CRCLSocket::isJaxbFragment() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isJaxbFragment of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isJaxbFragment jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isJaxbFragment", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named isJaxbFragment with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isJaxbFragment jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::setJaxbFragment(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJaxbFragment of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setJaxbFragment jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJaxbFragment", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setJaxbFragment with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setJaxbFragment jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring CRCLSocket::getLastStatusString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLastStatusString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getLastStatusString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getLastStatusString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getLastStatusString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getLastStatusString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::getLastCommandString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLastCommandString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getLastCommandString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getLastCommandString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getLastCommandString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getLastCommandString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::javax::xml::validation::Schema CRCLSocket::getProgramSchema() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getProgramSchema of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getProgramSchema jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getProgramSchema", "()Ljavax/xml/validation/Schema;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getProgramSchema with signature ()Ljavax/xml/validation/Schema;." << std::endl;
           ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getProgramSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::validation::Schema retObject(retVal,false);
    return retObject;
   }
   void CRCLSocket::setProgramSchema(::crclj::javax::xml::validation::Schema  &schema_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setProgramSchema of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setProgramSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setProgramSchema", "(Ljavax/xml/validation/Schema;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setProgramSchema with signature (Ljavax/xml/validation/Schema;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,schema_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setProgramSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::javax::xml::validation::Schema CRCLSocket::getCmdSchema() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCmdSchema of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getCmdSchema jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCmdSchema", "()Ljavax/xml/validation/Schema;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getCmdSchema with signature ()Ljavax/xml/validation/Schema;." << std::endl;
           ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getCmdSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::validation::Schema retObject(retVal,false);
    return retObject;
   }
   void CRCLSocket::setCmdSchema(::crclj::javax::xml::validation::Schema  &schema_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCmdSchema of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setCmdSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCmdSchema", "(Ljavax/xml/validation/Schema;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setCmdSchema with signature (Ljavax/xml/validation/Schema;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,schema_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setCmdSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::javax::xml::validation::Schema CRCLSocket::getStatSchema() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatSchema of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getStatSchema jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatSchema", "()Ljavax/xml/validation/Schema;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getStatSchema with signature ()Ljavax/xml/validation/Schema;." << std::endl;
           ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getStatSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::validation::Schema retObject(retVal,false);
    return retObject;
   }
   void CRCLSocket::setStatSchema(::crclj::javax::xml::validation::Schema  &schema_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatSchema of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setStatSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatSchema", "(Ljavax/xml/validation/Schema;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setStatSchema with signature (Ljavax/xml/validation/Schema;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,schema_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setStatSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring CRCLSocket::getReadInProgressString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getReadInProgressString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getReadInProgressString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getReadInProgressString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getReadInProgressString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getReadInProgressString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::readUntilEndTag(jstring string_0,::crclj::java::io::InputStream  &inputStream_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readUntilEndTag of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readUntilEndTag jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readUntilEndTag", "(Ljava/lang/String;Ljava/io/InputStream;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readUntilEndTag with signature (Ljava/lang/String;Ljava/io/InputStream;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,string_0,inputStream_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readUntilEndTag jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::readUntilEndTag(const char * easyArg_0,::crclj::java::io::InputStream easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method readUntilEndTag of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readUntilEndTag jthis=",jthis);
    jstring retVal=NULL;
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    ::crclj::java::io::InputStream  &inputStream_1= easyArg_1;
    retVal= (jstring) readUntilEndTag(string_0,inputStream_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::stringToCommand(jstring string_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stringToCommand of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToCommand jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stringToCommand", "(Ljava/lang/String;Z)Lcrcl/base/CRCLCommandInstanceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named stringToCommand with signature (Ljava/lang/String;Z)Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
           ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,string_0,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLCommandInstanceType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::stringToCommand(const char * easyArg_0,jboolean easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method stringToCommand of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToCommand jthis=",jthis);
    ::crclj::crcl::base::CRCLCommandInstanceType retVal((jobject)NULL,false);
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jboolean boolean_1= easyArg_1;
    retVal= (::crclj::crcl::base::CRCLCommandInstanceType) stringToCommand(string_0,boolean_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::readCommandFromStream(::crclj::java::io::InputStream  &inputStream_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readCommandFromStream of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCommandFromStream jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readCommandFromStream", "(Ljava/io/InputStream;Z)Lcrcl/base/CRCLCommandInstanceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readCommandFromStream with signature (Ljava/io/InputStream;Z)Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
           ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,inputStream_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCommandFromStream jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLCommandInstanceType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::CRCLProgramType CRCLSocket::stringToProgram(jstring string_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stringToProgram of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToProgram jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stringToProgram", "(Ljava/lang/String;Z)Lcrcl/base/CRCLProgramType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named stringToProgram with signature (Ljava/lang/String;Z)Lcrcl/base/CRCLProgramType;." << std::endl;
           ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,string_0,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToProgram jthis=",t);
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
   ::crclj::crcl::base::CRCLProgramType CRCLSocket::stringToProgram(const char * easyArg_0,jboolean easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method stringToProgram of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToProgram jthis=",jthis);
    ::crclj::crcl::base::CRCLProgramType retVal((jobject)NULL,false);
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jboolean boolean_1= easyArg_1;
    retVal= (::crclj::crcl::base::CRCLProgramType) stringToProgram(string_0,boolean_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::readCommand(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readCommand of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCommand jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readCommand", "(Z)Lcrcl/base/CRCLCommandInstanceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readCommand with signature (Z)Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
           ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLCommandInstanceType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::CRCLStatusType CRCLSocket::stringToStatus(jstring string_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stringToStatus of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stringToStatus", "(Ljava/lang/String;Z)Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named stringToStatus with signature (Ljava/lang/String;Z)Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,string_0,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToStatus jthis=",t);
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
   ::crclj::crcl::base::CRCLStatusType CRCLSocket::stringToStatus(const char * easyArg_0,jboolean easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method stringToStatus of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::stringToStatus jthis=",jthis);
    ::crclj::crcl::base::CRCLStatusType retVal((jobject)NULL,false);
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jboolean boolean_1= easyArg_1;
    retVal= (::crclj::crcl::base::CRCLStatusType) stringToStatus(string_0,boolean_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::CRCLStatusType CRCLSocket::readStatusFromStream(::crclj::java::io::InputStream  &inputStream_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readStatusFromStream of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatusFromStream jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readStatusFromStream", "(Ljava/io/InputStream;Z)Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readStatusFromStream with signature (Ljava/io/InputStream;Z)Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,inputStream_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatusFromStream jthis=",t);
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
   jboolean CRCLSocket::isEXIEnabled() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEXIEnabled of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isEXIEnabled jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isEXIEnabled", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named isEXIEnabled with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isEXIEnabled jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean CRCLSocket::isPrefixEXISizeEnabled() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isPrefixEXISizeEnabled of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isPrefixEXISizeEnabled jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isPrefixEXISizeEnabled", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named isPrefixEXISizeEnabled with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isPrefixEXISizeEnabled jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::setPrefixEXISizeEnabled(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setPrefixEXISizeEnabled of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setPrefixEXISizeEnabled jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setPrefixEXISizeEnabled", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setPrefixEXISizeEnabled with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setPrefixEXISizeEnabled jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::setEXIEnabled(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setEXIEnabled of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setEXIEnabled jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setEXIEnabled", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setEXIEnabled with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setEXIEnabled jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jbyteArray CRCLSocket::statusToEXI(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method statusToEXI of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statusToEXI jthis=",jthis);
   jbyteArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "statusToEXI", "(Lcrcl/base/CRCLStatusType;)[B");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named statusToEXI with signature (Lcrcl/base/CRCLStatusType;)[B." << std::endl;
           return NULL;
       } else {
           retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statusToEXI jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jbyteArray CRCLSocket::commandToEXI(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method commandToEXI of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToEXI jthis=",jthis);
   jbyteArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "commandToEXI", "(Lcrcl/base/CRCLCommandInstanceType;)[B");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named commandToEXI with signature (Lcrcl/base/CRCLCommandInstanceType;)[B." << std::endl;
           return NULL;
       } else {
           retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid ,cRCLCommandInstanceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToEXI jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::statToDebugString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "statToDebugString", "(Lcrcl/base/CRCLStatusType;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named statToDebugString with signature (Lcrcl/base/CRCLStatusType;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallStaticObjectMethod( cls, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statToDebugString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::writeEXIStatusToStream(::crclj::java::io::OutputStream  &outputStream_0,::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method writeEXIStatusToStream of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeEXIStatusToStream jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "writeEXIStatusToStream", "(Ljava/io/OutputStream;Lcrcl/base/CRCLStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named writeEXIStatusToStream with signature (Ljava/io/OutputStream;Lcrcl/base/CRCLStatusType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,outputStream_0.jthis,cRCLStatusType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeEXIStatusToStream jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::writeEXICommandToStream(::crclj::java::io::OutputStream  &outputStream_0,::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method writeEXICommandToStream of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeEXICommandToStream jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "writeEXICommandToStream", "(Ljava/io/OutputStream;Lcrcl/base/CRCLCommandInstanceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named writeEXICommandToStream with signature (Ljava/io/OutputStream;Lcrcl/base/CRCLCommandInstanceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,outputStream_0.jthis,cRCLCommandInstanceType_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeEXICommandToStream jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::CRCLStatusType CRCLSocket::exiToStatus(jbyteArray byteArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method exiToStatus of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::exiToStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "exiToStatus", "([B)Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named exiToStatus with signature ([B)Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::exiToStatus jthis=",t);
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
   ::crclj::crcl::base::CRCLStatusType CRCLSocket::exiToStatus(jbyte * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method exiToStatus of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::exiToStatus jthis=",jthis);
    ::crclj::crcl::base::CRCLStatusType retVal((jobject)NULL,false);
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    retVal= (::crclj::crcl::base::CRCLStatusType) exiToStatus(byteArray_0);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::exiToCommand(jbyteArray byteArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method exiToCommand of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::exiToCommand jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "exiToCommand", "([B)Lcrcl/base/CRCLCommandInstanceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named exiToCommand with signature ([B)Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
           ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::exiToCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLCommandInstanceType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::exiToCommand(jbyte * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method exiToCommand of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::exiToCommand jthis=",jthis);
    ::crclj::crcl::base::CRCLCommandInstanceType retVal((jobject)NULL,false);
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    retVal= (::crclj::crcl::base::CRCLCommandInstanceType) exiToCommand(byteArray_0);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   ::crclj::crcl::base::CRCLStatusType CRCLSocket::readStatusFromEXIStream(::crclj::java::io::InputStream  &inputStream_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readStatusFromEXIStream of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatusFromEXIStream jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readStatusFromEXIStream", "(Ljava/io/InputStream;)Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readStatusFromEXIStream with signature (Ljava/io/InputStream;)Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,inputStream_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatusFromEXIStream jthis=",t);
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
   ::crclj::crcl::base::CRCLStatusType CRCLSocket::readStatusFromSaxSource(::crclj::javax::xml::transform::sax::SAXSource  &sAXSource_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readStatusFromSaxSource of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatusFromSaxSource jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readStatusFromSaxSource", "(Ljavax/xml/transform/sax/SAXSource;)Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readStatusFromSaxSource with signature (Ljavax/xml/transform/sax/SAXSource;)Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,sAXSource_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatusFromSaxSource jthis=",t);
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
   ::crclj::crcl::base::CRCLCommandInstanceType CRCLSocket::readCommandFromEXIStream(::crclj::java::io::InputStream  &inputStream_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readCommandFromEXIStream of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCommandFromEXIStream jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readCommandFromEXIStream", "(Ljava/io/InputStream;)Lcrcl/base/CRCLCommandInstanceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readCommandFromEXIStream with signature (Ljava/io/InputStream;)Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
           ::crclj::crcl::base::CRCLCommandInstanceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,inputStream_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCommandFromEXIStream jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::crcl::base::CRCLCommandInstanceType retObject(retVal,false);
    return retObject;
   }
   ::crclj::crcl::base::CRCLStatusType CRCLSocket::readStatus(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readStatus of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readStatus", "(Z)Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readStatus with signature (Z)Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatus jthis=",t);
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
   jstring CRCLSocket::commandToString(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method commandToString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "commandToString", "(Lcrcl/base/CRCLCommandType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named commandToString with signature (Lcrcl/base/CRCLCommandType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLCommandType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::commandToString(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method commandToString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "commandToString", "(Lcrcl/base/CRCLCommandInstanceType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named commandToString with signature (Lcrcl/base/CRCLCommandInstanceType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLCommandInstanceType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::programToString(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method programToString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::programToString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "programToString", "(Lcrcl/base/CRCLProgramType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named programToString with signature (Lcrcl/base/CRCLProgramType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLProgramType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::programToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::commandToPrettyString(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method commandToPrettyString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToPrettyString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "commandToPrettyString", "(Lcrcl/base/CRCLCommandInstanceType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named commandToPrettyString with signature (Lcrcl/base/CRCLCommandInstanceType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLCommandInstanceType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToPrettyString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::commandToPrettyDocString(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method commandToPrettyDocString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToPrettyDocString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "commandToPrettyDocString", "(Lcrcl/base/CRCLCommandInstanceType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named commandToPrettyDocString with signature (Lcrcl/base/CRCLCommandInstanceType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLCommandInstanceType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::commandToPrettyDocString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::programToPrettyString(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method programToPrettyString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::programToPrettyString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "programToPrettyString", "(Lcrcl/base/CRCLProgramType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named programToPrettyString with signature (Lcrcl/base/CRCLProgramType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLProgramType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::programToPrettyString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::programToPrettyDocString(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method programToPrettyDocString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::programToPrettyDocString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "programToPrettyDocString", "(Lcrcl/base/CRCLProgramType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named programToPrettyDocString with signature (Lcrcl/base/CRCLProgramType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLProgramType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::programToPrettyDocString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::writeCommand(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method writeCommand of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeCommand jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "writeCommand", "(Lcrcl/base/CRCLCommandInstanceType;Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named writeCommand with signature (Lcrcl/base/CRCLCommandInstanceType;Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLCommandInstanceType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::writeWithFill(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method writeWithFill of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeWithFill jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "writeWithFill", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named writeWithFill with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeWithFill jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::writeWithFill(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method writeWithFill of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeWithFill jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    writeWithFill(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void CRCLSocket::writeProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method writeProgram of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeProgram jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "writeProgram", "(Lcrcl/base/CRCLProgramType;Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named writeProgram with signature (Lcrcl/base/CRCLProgramType;Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLProgramType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean CRCLSocket::isReplaceHeader() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isReplaceHeader of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isReplaceHeader jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isReplaceHeader", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named isReplaceHeader with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::isReplaceHeader jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::setReplaceHeader(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setReplaceHeader of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setReplaceHeader jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setReplaceHeader", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named setReplaceHeader with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::setReplaceHeader jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring CRCLSocket::statusToString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method statusToString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statusToString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "statusToString", "(Lcrcl/base/CRCLStatusType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named statusToString with signature (Lcrcl/base/CRCLStatusType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLStatusType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statusToString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring CRCLSocket::statusToPrettyString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method statusToPrettyString of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statusToPrettyString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "statusToPrettyString", "(Lcrcl/base/CRCLStatusType;Z)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named statusToPrettyString with signature (Lcrcl/base/CRCLStatusType;Z)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,cRCLStatusType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::statusToPrettyString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray CRCLSocket::findSchemaFiles() {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "findSchemaFiles", "()[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named findSchemaFiles with signature ()[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::findSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray CRCLSocket::reorderStatSchemaFiles(jobjectArray fileArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "reorderStatSchemaFiles", "([Ljava/io/File;)[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named reorderStatSchemaFiles with signature ([Ljava/io/File;)[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::reorderStatSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::util::List CRCLSocket::reorderStatSchemaFiles(::crclj::java::util::List  &list_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "reorderStatSchemaFiles", "(Ljava/util/List;)Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named reorderStatSchemaFiles with signature (Ljava/util/List;)Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,list_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::reorderStatSchemaFiles jthis=",t);
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
   ::crclj::javax::xml::validation::Schema CRCLSocket::filesToSchema(jobjectArray fileArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "filesToSchema", "([Ljava/io/File;)Ljavax/xml/validation/Schema;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named filesToSchema with signature ([Ljava/io/File;)Ljavax/xml/validation/Schema;." << std::endl;
           ::crclj::javax::xml::validation::Schema nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::filesToSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::javax::xml::validation::Schema retObject(retVal,false);
    return retObject;
   }
   jobjectArray CRCLSocket::readStatSchemaFiles(::crclj::java::io::File  &file_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "readStatSchemaFiles", "(Ljava/io/File;)[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readStatSchemaFiles with signature (Ljava/io/File;)[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readStatSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::saveProgramSchemaFiles(::crclj::java::io::File  &file_0,jobjectArray fileArray_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "saveProgramSchemaFiles", "(Ljava/io/File;[Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named saveProgramSchemaFiles with signature (Ljava/io/File;[Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,file_0.jthis,fileArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::saveProgramSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::saveStatSchemaFiles(::crclj::java::io::File  &file_0,jobjectArray fileArray_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "saveStatSchemaFiles", "(Ljava/io/File;[Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named saveStatSchemaFiles with signature (Ljava/io/File;[Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,file_0.jthis,fileArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::saveStatSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   jobjectArray CRCLSocket::reorderCommandSchemaFiles(jobjectArray fileArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "reorderCommandSchemaFiles", "([Ljava/io/File;)[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named reorderCommandSchemaFiles with signature ([Ljava/io/File;)[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::reorderCommandSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::util::List CRCLSocket::reorderCommandSchemaFiles(::crclj::java::util::List  &list_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "reorderCommandSchemaFiles", "(Ljava/util/List;)Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named reorderCommandSchemaFiles with signature (Ljava/util/List;)Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,list_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::reorderCommandSchemaFiles jthis=",t);
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
   ::crclj::java::util::List CRCLSocket::reorderProgramSchemaFiles(::crclj::java::util::List  &list_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "reorderProgramSchemaFiles", "(Ljava/util/List;)Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named reorderProgramSchemaFiles with signature (Ljava/util/List;)Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,list_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::reorderProgramSchemaFiles jthis=",t);
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
   jobjectArray CRCLSocket::reorderProgramSchemaFiles(jobjectArray fileArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "reorderProgramSchemaFiles", "([Ljava/io/File;)[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named reorderProgramSchemaFiles with signature ([Ljava/io/File;)[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::reorderProgramSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray CRCLSocket::readCmdSchemaFiles(::crclj::java::io::File  &file_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "readCmdSchemaFiles", "(Ljava/io/File;)[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readCmdSchemaFiles with signature (Ljava/io/File;)[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readCmdSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray CRCLSocket::readProgramSchemaFiles(::crclj::java::io::File  &file_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "readProgramSchemaFiles", "(Ljava/io/File;)[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named readProgramSchemaFiles with signature (Ljava/io/File;)[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::readProgramSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void CRCLSocket::saveCmdSchemaFiles(::crclj::java::io::File  &file_0,jobjectArray fileArray_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "saveCmdSchemaFiles", "(Ljava/io/File;[Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named saveCmdSchemaFiles with signature (Ljava/io/File;[Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,file_0.jthis,fileArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::saveCmdSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::writeStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method writeStatus of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "writeStatus", "(Lcrcl/base/CRCLStatusType;Z)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named writeStatus with signature (Lcrcl/base/CRCLStatusType;Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLStatusType_0.jthis,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::writeStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocket::close() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method close of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::close jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "close", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named close with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jint CRCLSocket::available() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method available of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::available jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "available", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named available with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::available jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint CRCLSocket::getPort() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPort of crcl.utils.CRCLSocket with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getPort jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPort", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocket has no method named getPort with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocket::getPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewCRCLSocketClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/CRCLSocket");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/CRCLSocket" << std::endl;
       }
       return clss;
   }
   
   static jclass CRCLSocketClass = NULL;
   static inline jclass getCRCLSocketClass() {
       if (CRCLSocketClass != NULL) {
           return CRCLSocketClass;
       }
       CRCLSocketClass = getNewCRCLSocketClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

