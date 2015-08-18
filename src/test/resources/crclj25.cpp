
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace java{
   namespace net{
   
   // get JNI handle for class java.net.InetAddress
   static inline jclass getInetAddressClass();
   
   InetAddress::InetAddress(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   InetAddress::InetAddress(const InetAddress &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   InetAddress::InetAddress() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class InetAddress has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new InetAddress with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new InetAddress jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for java.net.InetAddress
   InetAddress::~InetAddress() {
   	// Place-holder for later extensibility.
   }

   InetAddress InetAddress::getLoopbackAddress() {

   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getLoopbackAddress", "()Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getLoopbackAddress with signature ()Ljava/net/InetAddress;." << std::endl;
           InetAddress nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getLoopbackAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    InetAddress retObject(retVal,false);
    return retObject;
   }
   jboolean InetAddress::isMulticastAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMulticastAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMulticastAddress jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMulticastAddress", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isMulticastAddress with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMulticastAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isAnyLocalAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAnyLocalAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isAnyLocalAddress jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAnyLocalAddress", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isAnyLocalAddress with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isAnyLocalAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   InetAddress InetAddress::getByName(jstring string_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getByName", "(Ljava/lang/String;)Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getByName with signature (Ljava/lang/String;)Ljava/net/InetAddress;." << std::endl;
           InetAddress nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getByName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    InetAddress retObject(retVal,false);
    return retObject;
   }
   InetAddress InetAddress::getLocalHost() {

   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getLocalHost", "()Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getLocalHost with signature ()Ljava/net/InetAddress;." << std::endl;
           InetAddress nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getLocalHost jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    InetAddress retObject(retVal,false);
    return retObject;
   }
   jboolean InetAddress::isLoopbackAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isLoopbackAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isLoopbackAddress jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isLoopbackAddress", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isLoopbackAddress with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isLoopbackAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isLinkLocalAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isLinkLocalAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isLinkLocalAddress jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isLinkLocalAddress", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isLinkLocalAddress with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isLinkLocalAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isSiteLocalAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isSiteLocalAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isSiteLocalAddress jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isSiteLocalAddress", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isSiteLocalAddress with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isSiteLocalAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isMCGlobal() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMCGlobal of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCGlobal jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMCGlobal", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isMCGlobal with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCGlobal jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isMCNodeLocal() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMCNodeLocal of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCNodeLocal jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMCNodeLocal", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isMCNodeLocal with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCNodeLocal jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isMCLinkLocal() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMCLinkLocal of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCLinkLocal jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMCLinkLocal", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isMCLinkLocal with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCLinkLocal jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isMCSiteLocal() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMCSiteLocal of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCSiteLocal jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMCSiteLocal", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isMCSiteLocal with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCSiteLocal jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isMCOrgLocal() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isMCOrgLocal of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCOrgLocal jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isMCOrgLocal", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isMCOrgLocal with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isMCOrgLocal jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::isReachable(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isReachable of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::isReachable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isReachable", "(I)Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named isReachable with signature (I)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::isReachable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring InetAddress::getCanonicalHostName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCanonicalHostName of java.net.InetAddress with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::getCanonicalHostName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCanonicalHostName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getCanonicalHostName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getCanonicalHostName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   InetAddress InetAddress::getByAddress(jstring string_0,jbyteArray byteArray_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getByAddress", "(Ljava/lang/String;[B)Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getByAddress with signature (Ljava/lang/String;[B)Ljava/net/InetAddress;." << std::endl;
           InetAddress nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0,byteArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getByAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    InetAddress retObject(retVal,false);
    return retObject;
   }
   InetAddress InetAddress::getByAddress(jbyteArray byteArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getByAddress", "([B)Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getByAddress with signature ([B)Ljava/net/InetAddress;." << std::endl;
           InetAddress nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getByAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    InetAddress retObject(retVal,false);
    return retObject;
   }
   jobjectArray InetAddress::getAllByName(jstring string_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getInetAddressClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getAllByName", "(Ljava/lang/String;)[Ljava/net/InetAddress;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getAllByName with signature (Ljava/lang/String;)[Ljava/net/InetAddress;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getAllByName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InetAddress::equals(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.net.InetAddress with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring InetAddress::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.net.InetAddress with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint InetAddress::hashCode() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.net.InetAddress with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::hashCode jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named hashCode with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::hashCode jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jbyteArray InetAddress::getAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::getAddress jthis=",jthis);
   jbyteArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getAddress", "()[B");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getAddress with signature ()[B." << std::endl;
           return NULL;
       } else {
           retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring InetAddress::getHostAddress() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getHostAddress of java.net.InetAddress with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::getHostAddress jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getHostAddress", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getHostAddress with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getHostAddress jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring InetAddress::getHostName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getHostName of java.net.InetAddress with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InetAddress::getHostName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getHostName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.net.InetAddress has no method named getHostName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InetAddress::getHostName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewInetAddressClass() {
       jclass clss = getEnv()->FindClass("java/net/InetAddress");
       if (NULL == clss) {
           std::cerr << " Can't find class java/net/InetAddress" << std::endl;
       }
       return clss;
   }
   
   static jclass InetAddressClass = NULL;
   static inline jclass getInetAddressClass() {
       if (InetAddressClass != NULL) {
           return InetAddressClass;
       }
       InetAddressClass = getNewInetAddressClass();
   }
  } // end namespace net

   namespace util{
    namespace function{
    
    // get JNI handle for class java.util.function.UnaryOperator
    static inline jclass getUnaryOperatorClass();
    
    UnaryOperator::UnaryOperator(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    UnaryOperator::UnaryOperator(const UnaryOperator &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    UnaryOperator::UnaryOperator() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getUnaryOperatorClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class UnaryOperator has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," UnaryOperator::getHostName jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new UnaryOperator with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new UnaryOperator jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for java.util.function.UnaryOperator
    UnaryOperator::~UnaryOperator() {
    	// Place-holder for later extensibility.
    }

    UnaryOperator UnaryOperator::identity() {

    JNIEnv *env =getEnv();
    static jclass cls = getUnaryOperatorClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "identity", "()Ljava/util/function/UnaryOperator;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.UnaryOperator has no method named identity with signature ()Ljava/util/function/UnaryOperator;." << std::endl;
            UnaryOperator nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," UnaryOperator::identity jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     UnaryOperator retObject(retVal,false);
     return retObject;
    }
    static jclass getNewUnaryOperatorClass() {
        jclass clss = getEnv()->FindClass("java/util/function/UnaryOperator");
        if (NULL == clss) {
            std::cerr << " Can't find class java/util/function/UnaryOperator" << std::endl;
        }
        return clss;
    }
    
    static jclass UnaryOperatorClass = NULL;
    static inline jclass getUnaryOperatorClass() {
        if (UnaryOperatorClass != NULL) {
            return UnaryOperatorClass;
        }
        UnaryOperatorClass = getNewUnaryOperatorClass();
    }
   } // end namespace function
  } // end namespace util
 } // end namespace java

  namespace javax{
   namespace xml{
    namespace validation{
    
    // get JNI handle for class javax.xml.validation.Schema
    static inline jclass getSchemaClass();
    
    Schema::Schema(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Schema::Schema(const Schema &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Schema::Schema() : ::crclj::java::lang::Object((jobject)NULL,false) {
     JNIEnv *env =getEnv();
     static jclass cls = getSchemaClass();
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
         if (NULL == mid) {
             std::cerr << "Class Schema has no method constructor signature ()V" << std::endl;
         } else {
             jthis = env->NewObject(cls, mid );
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," Schema::identity jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
             if(jthis == NULL) {
                 std::cerr << "Call to create new Schema with signature ()V returned null." << std::endl;
                 releaseEnv(env);
                 return;
             }
             jobjectRefType ref = env->GetObjectRefType(jthis);
             if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Schema jthis=",jthis);
             if(ref != JNIGlobalRefType) {
                 jthis = env->NewGlobalRef(jthis);
             }
         }
     }
     releaseEnv(env);
    }


    // Destructor for javax.xml.validation.Schema
    Schema::~Schema() {
    	// Place-holder for later extensibility.
    }

    static jclass getNewSchemaClass() {
        jclass clss = getEnv()->FindClass("javax/xml/validation/Schema");
        if (NULL == clss) {
            std::cerr << " Can't find class javax/xml/validation/Schema" << std::endl;
        }
        return clss;
    }
    
    static jclass SchemaClass = NULL;
    static inline jclass getSchemaClass() {
        if (SchemaClass != NULL) {
            return SchemaClass;
        }
        SchemaClass = getNewSchemaClass();
    }
   } // end namespace validation
  } // end namespace xml
 } // end namespace javax

  namespace java{
   namespace io{
   
   // get JNI handle for class java.io.InputStream
   static inline jclass getInputStreamClass();
   
   InputStream::InputStream(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   InputStream::InputStream(const InputStream &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   InputStream::InputStream() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getInputStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class InputStream has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," InputStream::identity jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new InputStream with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new InputStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.io.InputStream
   InputStream::~InputStream() {
   	// Place-holder for later extensibility.
   }

   jint InputStream::read(jbyteArray byteArray_0,jint int_1,jint int_2) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method read of java.io.InputStream with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::read jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "read", "([BII)I");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named read with signature ([BII)I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid ,byteArray_0,int_1,int_2 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::read jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint InputStream::read(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method read of java.io.InputStream with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::read jthis=",jthis);
    jint retVal= (jint) -1;
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jint int_1= easyArg_1;
    jint int_2= easyArg_2;
    retVal= (jint) read(byteArray_0,int_1,int_2);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   jint InputStream::read(jbyteArray byteArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method read of java.io.InputStream with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::read jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "read", "([B)I");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named read with signature ([B)I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::read jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint InputStream::read(jbyte * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method read of java.io.InputStream with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::read jthis=",jthis);
    jint retVal= (jint) -1;
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    retVal= (jint) read(byteArray_0);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
    return retVal;
   }

   void InputStream::close() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method close of java.io.InputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::close jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "close", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named close with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void InputStream::mark(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method mark of java.io.InputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::mark jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "mark", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named mark with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::mark jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jlong InputStream::skip(jlong long_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method skip of java.io.InputStream with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::skip jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "skip", "(J)J");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named skip with signature (J)J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::skip jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint InputStream::available() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method available of java.io.InputStream with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::available jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "available", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named available with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::available jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean InputStream::markSupported() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method markSupported of java.io.InputStream with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::markSupported jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "markSupported", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named markSupported with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::markSupported jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void InputStream::reset() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method reset of java.io.InputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," InputStream::reset jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "reset", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.InputStream has no method named reset with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," InputStream::reset jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewInputStreamClass() {
       jclass clss = getEnv()->FindClass("java/io/InputStream");
       if (NULL == clss) {
           std::cerr << " Can't find class java/io/InputStream" << std::endl;
       }
       return clss;
   }
   
   static jclass InputStreamClass = NULL;
   static inline jclass getInputStreamClass() {
       if (InputStreamClass != NULL) {
           return InputStreamClass;
       }
       InputStreamClass = getNewInputStreamClass();
   }
  } // end namespace io
 } // end namespace java

  namespace javax{
   namespace xml{
    namespace transform{
     namespace sax{
     
     // get JNI handle for class javax.xml.transform.sax.SAXSource
     static inline jclass getSAXSourceClass();
     
     SAXSource::SAXSource(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
             // Place holder for future extensibility
     }
     
     SAXSource::SAXSource(const SAXSource &objref) {
         jobject _jthis = objref.jthis;
         if (_jthis != NULL) {
             jthis = getEnv()->NewGlobalRef(_jthis);
         }
     }
     SAXSource::SAXSource() : ::crclj::java::lang::Object((jobject)NULL,false) {
      JNIEnv *env =getEnv();
      static jclass cls = getSAXSourceClass();
      if (cls != NULL) {
          static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
          if (NULL == mid) {
              std::cerr << "Class SAXSource has no method constructor signature ()V" << std::endl;
          } else {
              jthis = env->NewObject(cls, mid );
              jthrowable t = env->ExceptionOccurred();
              if(t != NULL) {
                  DebugPrintJObject(__FILE__,__LINE__," SAXSource::reset jthis=",t);
                  env->ExceptionDescribe();
                  env->ExceptionClear();
                  throw this;
              }
              if(jthis == NULL) {
                  std::cerr << "Call to create new SAXSource with signature ()V returned null." << std::endl;
                  releaseEnv(env);
                  return;
              }
              jobjectRefType ref = env->GetObjectRefType(jthis);
              if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new SAXSource jthis=",jthis);
              if(ref != JNIGlobalRefType) {
                  jthis = env->NewGlobalRef(jthis);
              }
          }
      }
      releaseEnv(env);
     }


     // Destructor for javax.xml.transform.sax.SAXSource
     SAXSource::~SAXSource() {
     	// Place-holder for later extensibility.
     }

     jstring SAXSource::getSystemId() {

     if(jthis == NULL) {
         std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSystemId of javax.xml.transform.sax.SAXSource with jthis == NULL." << std::endl;
         return NULL;
     }
     JNIEnv *env =getEnv();
     jclass cls = env->GetObjectClass(jthis);
     if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SAXSource::getSystemId jthis=",jthis);
     jstring retVal=NULL;
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "getSystemId", "()Ljava/lang/String;");
         if (NULL == mid) {
             std::cerr << "Class javax.xml.transform.sax.SAXSource has no method named getSystemId with signature ()Ljava/lang/String;." << std::endl;
             return NULL;
         } else {
             retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," SAXSource::getSystemId jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
         }
     }
     releaseEnv(env);
     return retVal;
     }
     void SAXSource::setSystemId(jstring string_0) {

     if(jthis == NULL) {
         std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSystemId of javax.xml.transform.sax.SAXSource with jthis == NULL." << std::endl;
         return;
     }
     JNIEnv *env =getEnv();
     jclass cls = env->GetObjectClass(jthis);
     if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SAXSource::setSystemId jthis=",jthis);
     
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "setSystemId", "(Ljava/lang/String;)V");
         if (NULL == mid) {
             std::cerr << "Class javax.xml.transform.sax.SAXSource has no method named setSystemId with signature (Ljava/lang/String;)V." << std::endl;
             return;
         } else {
              env->CallVoidMethod(jthis, mid ,string_0 );
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," SAXSource::setSystemId jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
         }
     }
     releaseEnv(env);
     
     }
     void SAXSource::setSystemId(const char * easyArg_0) {

      // convenience method, converts to/from JNI types to common C++ types.
      if(jthis == NULL) {
          std::cerr << "Call of method setSystemId of javax.xml.transform.sax.SAXSource with jthis == NULL." << std::endl;
          return;
      }
      JNIEnv *env =getEnv();
      jclass cls = env->GetObjectClass(jthis);
      if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," SAXSource::setSystemId jthis=",jthis);
      
              
      jstring string_0 = env->NewStringUTF(easyArg_0);
      setSystemId(string_0);
      jobjectRefType ref_0 = env->GetObjectRefType(string_0);
      if(ref_0 == JNIGlobalRefType) {
       env->DeleteGlobalRef(string_0);
      }
      
      releaseEnv(env);
     }

     static jclass getNewSAXSourceClass() {
         jclass clss = getEnv()->FindClass("javax/xml/transform/sax/SAXSource");
         if (NULL == clss) {
             std::cerr << " Can't find class javax/xml/transform/sax/SAXSource" << std::endl;
         }
         return clss;
     }
     
     static jclass SAXSourceClass = NULL;
     static inline jclass getSAXSourceClass() {
         if (SAXSourceClass != NULL) {
             return SAXSourceClass;
         }
         SAXSourceClass = getNewSAXSourceClass();
     }
    } // end namespace sax
   } // end namespace transform
  } // end namespace xml
 } // end namespace javax



    // end namespace crclj
}

