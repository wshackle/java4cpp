
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace java{
   namespace lang{
   
   // get JNI handle for class java.lang.Throwable
   static inline jclass getThrowableClass();
   
   Throwable::Throwable(jobject _jthis, bool copy): Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Throwable::Throwable(const Throwable &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   Throwable::Throwable(jstring string_0,Throwable  &throwable_1) : Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getThrowableClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
        if (NULL == mid) {
            std::cerr << "Class Throwable has no method constructor signature (Ljava/lang/String;Ljava/lang/Throwable;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0,throwable_1.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Throwable::replaceAll jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Throwable with signature (Ljava/lang/String;Ljava/lang/Throwable;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Throwable jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   Throwable::Throwable(const char * easyArg_0,Throwable easyArg_1) : Object((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getThrowableClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   Throwable  &throwable_1= easyArg_1;
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
       if (NULL == mid) {
           std::cerr << "Class Throwable has no method constructor signature (Ljava/lang/String;Ljava/lang/Throwable;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0,throwable_1.jthis);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::replaceAll jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Throwable with signature (Ljava/lang/String;Ljava/lang/Throwable;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Throwable jthis=",jthis);
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
   Throwable::Throwable(jstring string_0) : Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getThrowableClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class Throwable has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Throwable::replaceAll jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Throwable with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Throwable jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   Throwable::Throwable(const char * easyArg_0) : Object((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getThrowableClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class Throwable has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::replaceAll jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Throwable with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Throwable jthis=",jthis);
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
   Throwable::Throwable() : Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getThrowableClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Throwable has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Throwable::replaceAll jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Throwable with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Throwable jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.lang.Throwable
   Throwable::~Throwable() {
   	// Place-holder for later extensibility.
   }

   void Throwable::printStackTrace() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method printStackTrace of java.lang.Throwable with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::printStackTrace jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "printStackTrace", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named printStackTrace with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::printStackTrace jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Throwable::printStackTrace(::crclj::java::io::PrintStream  &printStream_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method printStackTrace of java.lang.Throwable with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::printStackTrace jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "printStackTrace", "(Ljava/io/PrintStream;)V");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named printStackTrace with signature (Ljava/io/PrintStream;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,printStream_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::printStackTrace jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   Throwable Throwable::fillInStackTrace() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method fillInStackTrace of java.lang.Throwable with jthis == NULL." << std::endl;
       Throwable nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::fillInStackTrace jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "fillInStackTrace", "()Ljava/lang/Throwable;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named fillInStackTrace with signature ()Ljava/lang/Throwable;." << std::endl;
           Throwable nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::fillInStackTrace jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Throwable retObject(retVal,false);
    return retObject;
   }
   Throwable Throwable::getCause() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCause of java.lang.Throwable with jthis == NULL." << std::endl;
       Throwable nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::getCause jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCause", "()Ljava/lang/Throwable;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named getCause with signature ()Ljava/lang/Throwable;." << std::endl;
           Throwable nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::getCause jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Throwable retObject(retVal,false);
    return retObject;
   }
   Throwable Throwable::initCause(Throwable  &throwable_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method initCause of java.lang.Throwable with jthis == NULL." << std::endl;
       Throwable nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::initCause jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "initCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named initCause with signature (Ljava/lang/Throwable;)Ljava/lang/Throwable;." << std::endl;
           Throwable nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,throwable_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::initCause jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Throwable retObject(retVal,false);
    return retObject;
   }
   jstring Throwable::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.lang.Throwable with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring Throwable::getMessage() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getMessage of java.lang.Throwable with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::getMessage jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getMessage", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named getMessage with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::getMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring Throwable::getLocalizedMessage() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLocalizedMessage of java.lang.Throwable with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::getLocalizedMessage jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getLocalizedMessage", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named getLocalizedMessage with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::getLocalizedMessage jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Throwable::addSuppressed(Throwable  &throwable_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method addSuppressed of java.lang.Throwable with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::addSuppressed jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "addSuppressed", "(Ljava/lang/Throwable;)V");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named addSuppressed with signature (Ljava/lang/Throwable;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,throwable_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::addSuppressed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jobjectArray Throwable::getSuppressed() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSuppressed of java.lang.Throwable with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Throwable::getSuppressed jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSuppressed", "()[Ljava/lang/Throwable;");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Throwable has no method named getSuppressed with signature ()[Ljava/lang/Throwable;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Throwable::getSuppressed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewThrowableClass() {
       jclass clss = getEnv()->FindClass("java/lang/Throwable");
       if (NULL == clss) {
           std::cerr << " Can't find class java/lang/Throwable" << std::endl;
       }
       return clss;
   }
   
   static jclass ThrowableClass = NULL;
   static inline jclass getThrowableClass() {
       if (ThrowableClass != NULL) {
           return ThrowableClass;
       }
       ThrowableClass = getNewThrowableClass();
   }
  } // end namespace lang

   namespace io{
   
   // get JNI handle for class java.io.File
   static inline jclass getFileClass();
   
   File::File(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   File::File(const File &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   File::File() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class File has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new File with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   File::File(jstring string_0,jstring string_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFileClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class File has no method constructor signature (Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0,string_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new File with signature (Ljava/lang/String;Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   File::File(const char * easyArg_0,const char * easyArg_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   jstring string_1 = env->NewStringUTF(easyArg_1);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class File has no method constructor signature (Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0,string_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new File with signature (Ljava/lang/String;Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   jobjectRefType ref_0 = env->GetObjectRefType(string_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_0);
   }
   jobjectRefType ref_1 = env->GetObjectRefType(string_1);
   if(ref_1 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_1);
   }
   
   releaseEnv(env);
   }
   File::File(jstring string_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFileClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class File has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new File with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   File::File(const char * easyArg_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class File has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new File with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
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
   File::File(File  &file_0,jstring string_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFileClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class File has no method constructor signature (Ljava/io/File;Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,file_0.jthis,string_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new File with signature (Ljava/io/File;Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   File::File(File easyArg_0,const char * easyArg_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   File  &file_0= easyArg_0;
   jstring string_1 = env->NewStringUTF(easyArg_1);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class File has no method constructor signature (Ljava/io/File;Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,file_0.jthis,string_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getSuppressed jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new File with signature (Ljava/io/File;Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new File jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   jobjectRefType ref_1 = env->GetObjectRefType(string_1);
   if(ref_1 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_1);
   }
   
   releaseEnv(env);
   }

   // Destructor for java.io.File
   File::~File() {
   	// Place-holder for later extensibility.
   }

   jboolean File::equals(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring File::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint File::hashCode() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.io.File with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::hashCode jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named hashCode with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::hashCode jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint File::compareTo(File  &file_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method compareTo of java.io.File with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::compareTo jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/io/File;)I");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named compareTo with signature (Ljava/io/File;)I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::compareTo jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring File::getName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getName of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong File::length() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method length of java.io.File with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::length jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "length", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named length with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::length jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring File::getParent() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getParent of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getParent jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getParent", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getParent with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getParent jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::isAbsolute() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAbsolute of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::isAbsolute jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAbsolute", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named isAbsolute with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::isAbsolute jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring File::getCanonicalPath() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCanonicalPath of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getCanonicalPath jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCanonicalPath", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getCanonicalPath with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getCanonicalPath jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::deleteMethod() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method deleteMethod of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::deleteMethod jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "deleteMethod", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named deleteMethod with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::deleteMethod jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setReadOnly() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setReadOnly of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setReadOnly jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setReadOnly", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setReadOnly with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setReadOnly jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray File::list() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method list of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::list jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "list", "()[Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named list with signature ()[Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::list jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   File File::getParentFile() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getParentFile of java.io.File with jthis == NULL." << std::endl;
       File nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getParentFile jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getParentFile", "()Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getParentFile with signature ()Ljava/io/File;." << std::endl;
           File nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getParentFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    File retObject(retVal,false);
    return retObject;
   }
   jstring File::getPath() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPath of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getPath jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPath", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getPath with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getPath jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring File::getAbsolutePath() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAbsolutePath of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getAbsolutePath jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getAbsolutePath", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getAbsolutePath with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getAbsolutePath jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   File File::getAbsoluteFile() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAbsoluteFile of java.io.File with jthis == NULL." << std::endl;
       File nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getAbsoluteFile jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getAbsoluteFile", "()Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getAbsoluteFile with signature ()Ljava/io/File;." << std::endl;
           File nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getAbsoluteFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    File retObject(retVal,false);
    return retObject;
   }
   File File::getCanonicalFile() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCanonicalFile of java.io.File with jthis == NULL." << std::endl;
       File nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getCanonicalFile jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCanonicalFile", "()Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getCanonicalFile with signature ()Ljava/io/File;." << std::endl;
           File nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getCanonicalFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    File retObject(retVal,false);
    return retObject;
   }
   jboolean File::canRead() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method canRead of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::canRead jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "canRead", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named canRead with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::canRead jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::canWrite() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method canWrite of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::canWrite jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "canWrite", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named canWrite with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::canWrite jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::exists() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method exists of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::exists jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "exists", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named exists with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::exists jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::isDirectory() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDirectory of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::isDirectory jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDirectory", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named isDirectory with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::isDirectory jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::isFile() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isFile of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::isFile jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isFile", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named isFile with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::isFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::isHidden() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isHidden of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::isHidden jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isHidden", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named isHidden with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::isHidden jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong File::lastModified() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method lastModified of java.io.File with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::lastModified jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "lastModified", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named lastModified with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::lastModified jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::createNewFile() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createNewFile of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::createNewFile jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createNewFile", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named createNewFile with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::createNewFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void File::deleteOnExit() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method deleteOnExit of java.io.File with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::deleteOnExit jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "deleteOnExit", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named deleteOnExit with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::deleteOnExit jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jobjectArray File::listFiles() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method listFiles of java.io.File with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::listFiles jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "listFiles", "()[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named listFiles with signature ()[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::listFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::mkdir() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method mkdir of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::mkdir jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "mkdir", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named mkdir with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::mkdir jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::mkdirs() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method mkdirs of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::mkdirs jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "mkdirs", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named mkdirs with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::mkdirs jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::renameTo(File  &file_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method renameTo of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::renameTo jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "renameTo", "(Ljava/io/File;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named renameTo with signature (Ljava/io/File;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::renameTo jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setLastModified(jlong long_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLastModified of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setLastModified jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setLastModified", "(J)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setLastModified with signature (J)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setLastModified jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setWritable(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setWritable of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setWritable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setWritable", "(Z)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setWritable with signature (Z)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setWritable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setWritable(jboolean boolean_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setWritable of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setWritable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setWritable", "(ZZ)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setWritable with signature (ZZ)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,boolean_0,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setWritable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setReadable(jboolean boolean_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setReadable of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setReadable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setReadable", "(ZZ)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setReadable with signature (ZZ)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,boolean_0,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setReadable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setReadable(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setReadable of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setReadable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setReadable", "(Z)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setReadable with signature (Z)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setReadable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setExecutable(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExecutable of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setExecutable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExecutable", "(Z)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setExecutable with signature (Z)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setExecutable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::setExecutable(jboolean boolean_0,jboolean boolean_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExecutable of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::setExecutable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExecutable", "(ZZ)Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named setExecutable with signature (ZZ)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,boolean_0,boolean_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::setExecutable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean File::canExecute() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method canExecute of java.io.File with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::canExecute jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "canExecute", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named canExecute with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::canExecute jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray File::listRoots() {

   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "listRoots", "()[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named listRoots with signature ()[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::listRoots jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong File::getTotalSpace() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTotalSpace of java.io.File with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getTotalSpace jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTotalSpace", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getTotalSpace with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getTotalSpace jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong File::getFreeSpace() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFreeSpace of java.io.File with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getFreeSpace jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFreeSpace", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getFreeSpace with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getFreeSpace jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong File::getUsableSpace() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getUsableSpace of java.io.File with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," File::getUsableSpace jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getUsableSpace", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named getUsableSpace with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::getUsableSpace jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   File File::createTempFile(jstring string_0,jstring string_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "createTempFile", "(Ljava/lang/String;Ljava/lang/String;)Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named createTempFile with signature (Ljava/lang/String;Ljava/lang/String;)Ljava/io/File;." << std::endl;
           File nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0,string_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::createTempFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    File retObject(retVal,false);
    return retObject;
   }
   File File::createTempFile(jstring string_0,jstring string_1,File  &file_2) {

   JNIEnv *env =getEnv();
   static jclass cls = getFileClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "createTempFile", "(Ljava/lang/String;Ljava/lang/String;Ljava/io/File;)Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class java.io.File has no method named createTempFile with signature (Ljava/lang/String;Ljava/lang/String;Ljava/io/File;)Ljava/io/File;." << std::endl;
           File nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0,string_1,file_2.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," File::createTempFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    File retObject(retVal,false);
    return retObject;
   }
   static jclass getNewFileClass() {
       jclass clss = getEnv()->FindClass("java/io/File");
       if (NULL == clss) {
           std::cerr << " Can't find class java/io/File" << std::endl;
       }
       return clss;
   }
   
   static jclass FileClass = NULL;
   static inline jclass getFileClass() {
       if (FileClass != NULL) {
           return FileClass;
       }
       FileClass = getNewFileClass();
   }
  } // end namespace io
 } // end namespace java

  namespace javax{
   namespace xml{
    namespace bind{
    
    // get JNI handle for class javax.xml.bind.JAXBElement
    static inline jclass getJAXBElementClass();
    
    JAXBElement::JAXBElement(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    JAXBElement::JAXBElement(const JAXBElement &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    JAXBElement::JAXBElement() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJAXBElementClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JAXBElement has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::createTempFile jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JAXBElement with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JAXBElement jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for javax.xml.bind.JAXBElement
    JAXBElement::~JAXBElement() {
    	// Place-holder for later extensibility.
    }

    jboolean JAXBElement::isNil() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isNil of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JAXBElement::isNil jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "isNil", "()Z");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.bind.JAXBElement has no method named isNil with signature ()Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::isNil jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    void JAXBElement::setNil(jboolean boolean_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setNil of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JAXBElement::setNil jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setNil", "(Z)V");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.bind.JAXBElement has no method named setNil with signature (Z)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,boolean_0 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::setNil jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    jboolean JAXBElement::isGlobalScope() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isGlobalScope of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JAXBElement::isGlobalScope jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "isGlobalScope", "()Z");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.bind.JAXBElement has no method named isGlobalScope with signature ()Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::isGlobalScope jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jboolean JAXBElement::isTypeSubstituted() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isTypeSubstituted of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JAXBElement::isTypeSubstituted jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "isTypeSubstituted", "()Z");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.bind.JAXBElement has no method named isTypeSubstituted with signature ()Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::isTypeSubstituted jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    ::crclj::java::lang::Object JAXBElement::getValue() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getValue of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
        ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JAXBElement::getValue jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "getValue", "()Ljava/lang/Object;");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.bind.JAXBElement has no method named getValue with signature ()Ljava/lang/Object;." << std::endl;
            ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::getValue jthis=",t);
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
    void JAXBElement::setValue(::crclj::java::lang::Object  &object_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setValue of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JAXBElement::setValue jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setValue", "(Ljava/lang/Object;)V");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.bind.JAXBElement has no method named setValue with signature (Ljava/lang/Object;)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JAXBElement::setValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    static jclass getNewJAXBElementClass() {
        jclass clss = getEnv()->FindClass("javax/xml/bind/JAXBElement");
        if (NULL == clss) {
            std::cerr << " Can't find class javax/xml/bind/JAXBElement" << std::endl;
        }
        return clss;
    }
    
    static jclass JAXBElementClass = NULL;
    static inline jclass getJAXBElementClass() {
        if (JAXBElementClass != NULL) {
            return JAXBElementClass;
        }
        JAXBElementClass = getNewJAXBElementClass();
    }
   } // end namespace bind
  } // end namespace xml
 } // end namespace javax

  namespace org{
   namespace apache{
    namespace commons{
     namespace math3{
      namespace geometry{
       namespace euclidean{
        namespace threed{
        
        // get JNI handle for class org.apache.commons.math3.geometry.euclidean.threed.Vector3D
        static inline jclass getVector3DClass();
        
        Vector3D::Vector3D(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
                // Place holder for future extensibility
        }
        
        Vector3D::Vector3D(const Vector3D &objref) {
            jobject _jthis = objref.jthis;
            if (_jthis != NULL) {
                jthis = getEnv()->NewGlobalRef(_jthis);
            }
        }
        Vector3D::Vector3D() : ::crclj::java::lang::Object((jobject)NULL,false) {
        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
            if (NULL == mid) {
                std::cerr << "Class Vector3D has no method constructor signature ()V" << std::endl;
            } else {
                jthis = env->NewObject(cls, mid );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
                if(jthis == NULL) {
                    std::cerr << "Call to create new Vector3D with signature ()V returned null." << std::endl;
                    releaseEnv(env);
                    return;
                }
                jobjectRefType ref = env->GetObjectRefType(jthis);
                if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                if(ref != JNIGlobalRefType) {
                    jthis = env->NewGlobalRef(jthis);
                }
            }
        }
        releaseEnv(env);
        }

        Vector3D::Vector3D(jdouble double_0,Vector3D  &vector3D_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,vector3D_1.jthis);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Vector3D::Vector3D(jdouble double_0,jdouble double_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DD)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature (DD)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,double_1);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature (DD)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Vector3D::Vector3D(jdoubleArray doubleArray_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "([D)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature ([D)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,doubleArray_0);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature ([D)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Vector3D::Vector3D(jdouble * easyArg_0,jsize easyArg_0_length) : ::crclj::java::lang::Object((jobject)NULL,false) {
        // Convenience Constructor converts common C++ types to JNI types
        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
        env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
        
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "<init>", "([D)V");
            if (NULL == mid) {
                std::cerr << "Class Vector3D has no method constructor signature ([D)V" << std::endl;
            } else {
                jthis = env->NewObject(cls, mid ,doubleArray_0);
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
                if(jthis == NULL) {
                    std::cerr << "Call to create new Vector3D with signature ([D)V returned null." << std::endl;
                    releaseEnv(env);
                    return;
                }
                jobjectRefType ref = env->GetObjectRefType(jthis);
                if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                if(ref != JNIGlobalRefType) {
                    jthis = env->NewGlobalRef(jthis);
                }
            }
        }
        env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
        jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
        if(ref_0 == JNIGlobalRefType) {
         env->DeleteGlobalRef(doubleArray_0);
        }
        
        releaseEnv(env);
        }
        Vector3D::Vector3D(jdouble double_0,jdouble double_1,jdouble double_2) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDD)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature (DDD)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,double_1,double_2);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature (DDD)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Vector3D::Vector3D(jdouble double_0,Vector3D  &vector3D_1,jdouble double_2,Vector3D  &vector3D_3) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,vector3D_1.jthis,double_2,vector3D_3.jthis);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Vector3D::Vector3D(jdouble double_0,Vector3D  &vector3D_1,jdouble double_2,Vector3D  &vector3D_3,jdouble double_4,Vector3D  &vector3D_5) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,vector3D_1.jthis,double_2,vector3D_3.jthis,double_4,vector3D_5.jthis);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Vector3D::Vector3D(jdouble double_0,Vector3D  &vector3D_1,jdouble double_2,Vector3D  &vector3D_3,jdouble double_4,Vector3D  &vector3D_5,jdouble double_6,Vector3D  &vector3D_7) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getVector3DClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
             if (NULL == mid) {
                 std::cerr << "Class Vector3D has no method constructor signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,vector3D_1.jthis,double_2,vector3D_3.jthis,double_4,vector3D_5.jthis,double_6,vector3D_7.jthis);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Vector3D::setValue jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Vector3D with signature (DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;DLorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Vector3D jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }


        // Destructor for org.apache.commons.math3.geometry.euclidean.threed.Vector3D
        Vector3D::~Vector3D() {
        	// Place-holder for later extensibility.
        }

        jdouble Vector3D::distanceSq(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "distanceSq", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named distanceSq with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::distanceSq jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::distance(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "distance", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named distance with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::distance jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getAlpha() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAlpha of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getAlpha jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getAlpha", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getAlpha with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getAlpha jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getX() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getX of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getX jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getX", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getX with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getX jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getY() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getY of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getY jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getY", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getY with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getY jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getZ() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getZ of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getZ jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getZ", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getZ with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getZ jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::angle(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "angle", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named angle with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::angle jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        Vector3D Vector3D::negate() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method negate of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::negate jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "negate", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named negate with signature ()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::negate jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        Vector3D Vector3D::getZero() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getZero of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getZero jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getZero", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getZero with signature ()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getZero jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        Vector3D Vector3D::scalarMultiply(jdouble double_0) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method scalarMultiply of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::scalarMultiply jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "scalarMultiply", "(D)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named scalarMultiply with signature (D)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid ,double_0 );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::scalarMultiply jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        jdouble Vector3D::dotProduct(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "dotProduct", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named dotProduct with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::dotProduct jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::distanceInf(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "distanceInf", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named distanceInf with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::distanceInf jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::distance1(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "distance1", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named distance1 with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::distance1 jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getNorm() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getNorm of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNorm jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getNorm", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getNorm with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNorm jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getNorm1() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getNorm1 of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNorm1 jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getNorm1", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getNorm1 with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNorm1 jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getNormSq() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getNormSq of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNormSq jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getNormSq", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getNormSq with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNormSq jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getNormInf() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getNormInf of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNormInf jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getNormInf", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getNormInf with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getNormInf jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Vector3D::getDelta() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDelta of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::getDelta jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getDelta", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named getDelta with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::getDelta jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        Vector3D Vector3D::orthogonal() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method orthogonal of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::orthogonal jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "orthogonal", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named orthogonal with signature ()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::orthogonal jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        Vector3D Vector3D::crossProduct(Vector3D  &vector3D_0,Vector3D  &vector3D_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getVector3DClass();
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "crossProduct", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named crossProduct with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,vector3D_0.jthis,vector3D_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::crossProduct jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        jboolean Vector3D::equals(::crclj::java::lang::Object  &object_0) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return false;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::equals jthis=",jthis);
        jboolean retVal=false;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
                return false;
            } else {
                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::equals jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jstring Vector3D::toString() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return NULL;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::toString jthis=",jthis);
        jstring retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named toString with signature ()Ljava/lang/String;." << std::endl;
                return NULL;
            } else {
                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::toString jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jint Vector3D::hashCode() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return (jint) -1;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::hashCode jthis=",jthis);
        jint retVal= (jint) -1;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named hashCode with signature ()I." << std::endl;
                return (jint) -1;
            } else {
                retVal= (jint)  env->CallIntMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::hashCode jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdoubleArray Vector3D::toArray() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toArray of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return NULL;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::toArray jthis=",jthis);
        jdoubleArray retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "toArray", "()[D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named toArray with signature ()[D." << std::endl;
                return NULL;
            } else {
                retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::toArray jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jboolean Vector3D::isNaN() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isNaN of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return false;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::isNaN jthis=",jthis);
        jboolean retVal=false;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "isNaN", "()Z");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named isNaN with signature ()Z." << std::endl;
                return false;
            } else {
                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::isNaN jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        Vector3D Vector3D::normalize() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method normalize of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::normalize jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "normalize", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named normalize with signature ()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::normalize jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        jboolean Vector3D::isInfinite() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isInfinite of org.apache.commons.math3.geometry.euclidean.threed.Vector3D with jthis == NULL." << std::endl;
            return false;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Vector3D::isInfinite jthis=",jthis);
        jboolean retVal=false;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "isInfinite", "()Z");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Vector3D has no method named isInfinite with signature ()Z." << std::endl;
                return false;
            } else {
                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Vector3D::isInfinite jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        static jclass getNewVector3DClass() {
            jclass clss = getEnv()->FindClass("org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
            if (NULL == clss) {
                std::cerr << " Can't find class org/apache/commons/math3/geometry/euclidean/threed/Vector3D" << std::endl;
            }
            return clss;
        }
        
        static jclass Vector3DClass = NULL;
        static inline jclass getVector3DClass() {
            if (Vector3DClass != NULL) {
                return Vector3DClass;
            }
            Vector3DClass = getNewVector3DClass();
        }
        
        // get JNI handle for class org.apache.commons.math3.geometry.euclidean.threed.Rotation
        static inline jclass getRotationClass();
        
        Rotation::Rotation(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
                // Place holder for future extensibility
        }
        
        Rotation::Rotation(const Rotation &objref) {
            jobject _jthis = objref.jthis;
            if (_jthis != NULL) {
                jthis = getEnv()->NewGlobalRef(_jthis);
            }
        }
        Rotation::Rotation() : ::crclj::java::lang::Object((jobject)NULL,false) {
        JNIEnv *env =getEnv();
        static jclass cls = getRotationClass();
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
            if (NULL == mid) {
                std::cerr << "Class Rotation has no method constructor signature ()V" << std::endl;
            } else {
                jthis = env->NewObject(cls, mid );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::isInfinite jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
                if(jthis == NULL) {
                    std::cerr << "Call to create new Rotation with signature ()V returned null." << std::endl;
                    releaseEnv(env);
                    return;
                }
                jobjectRefType ref = env->GetObjectRefType(jthis);
                if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Rotation jthis=",jthis);
                if(ref != JNIGlobalRefType) {
                    jthis = env->NewGlobalRef(jthis);
                }
            }
        }
        releaseEnv(env);
        }

        Rotation::Rotation(Vector3D  &vector3D_0,jdouble double_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getRotationClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;D)V");
             if (NULL == mid) {
                 std::cerr << "Class Rotation has no method constructor signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;D)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,vector3D_0.jthis,double_1);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Rotation::isInfinite jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Rotation with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;D)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Rotation jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Rotation::Rotation(Vector3D  &vector3D_0,Vector3D  &vector3D_1,Vector3D  &vector3D_2,Vector3D  &vector3D_3) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getRotationClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
             if (NULL == mid) {
                 std::cerr << "Class Rotation has no method constructor signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,vector3D_0.jthis,vector3D_1.jthis,vector3D_2.jthis,vector3D_3.jthis);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Rotation::isInfinite jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Rotation with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Rotation jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Rotation::Rotation(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3,jboolean boolean_4) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getRotationClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDDDZ)V");
             if (NULL == mid) {
                 std::cerr << "Class Rotation has no method constructor signature (DDDDZ)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,double_0,double_1,double_2,double_3,boolean_4);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Rotation::isInfinite jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Rotation with signature (DDDDZ)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Rotation jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }

        Rotation::Rotation(Vector3D  &vector3D_0,Vector3D  &vector3D_1) : ::crclj::java::lang::Object((jobject)NULL,false) {
         JNIEnv *env =getEnv();
         static jclass cls = getRotationClass();
         if (cls != NULL) {
             static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
             if (NULL == mid) {
                 std::cerr << "Class Rotation has no method constructor signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V" << std::endl;
             } else {
                 jthis = env->NewObject(cls, mid ,vector3D_0.jthis,vector3D_1.jthis);
                 jthrowable t = env->ExceptionOccurred();
                 if(t != NULL) {
                     DebugPrintJObject(__FILE__,__LINE__," Rotation::isInfinite jthis=",t);
                     env->ExceptionDescribe();
                     env->ExceptionClear();
                     throw this;
                 }
                 if(jthis == NULL) {
                     std::cerr << "Call to create new Rotation with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V returned null." << std::endl;
                     releaseEnv(env);
                     return;
                 }
                 jobjectRefType ref = env->GetObjectRefType(jthis);
                 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Rotation jthis=",jthis);
                 if(ref != JNIGlobalRefType) {
                     jthis = env->NewGlobalRef(jthis);
                 }
             }
         }
         releaseEnv(env);
        }


        // Destructor for org.apache.commons.math3.geometry.euclidean.threed.Rotation
        Rotation::~Rotation() {
        	// Place-holder for later extensibility.
        }

        jdouble Rotation::distance(Rotation  &rotation_0,Rotation  &rotation_1) {

        JNIEnv *env =getEnv();
        static jclass cls = getRotationClass();
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetStaticMethodID(cls, "distance", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;)D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named distance with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;)D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,rotation_0.jthis,rotation_1.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::distance jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw env;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        Vector3D Rotation::getAxis() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAxis of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::getAxis jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getAxis", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named getAxis with signature ()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::getAxis jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        jdouble Rotation::getAngle() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getAngle of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::getAngle jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getAngle", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named getAngle with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::getAngle jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        Rotation Rotation::revert() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method revert of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            Rotation nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::revert jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "revert", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named revert with signature ()Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;." << std::endl;
                Rotation nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::revert jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Rotation retObject(retVal,false);
         return retObject;
        }
        jdouble Rotation::getQ0() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getQ0 of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ0 jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getQ0", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named getQ0 with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ0 jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Rotation::getQ1() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getQ1 of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ1 jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getQ1", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named getQ1 with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ1 jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Rotation::getQ2() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getQ2 of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ2 jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getQ2", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named getQ2 with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ2 jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        jdouble Rotation::getQ3() {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getQ3 of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return (jdouble) -1.0;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ3 jthis=",jthis);
        jdouble retVal= (jdouble) -1.0;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "getQ3", "()D");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named getQ3 with signature ()D." << std::endl;
                return (jdouble) -1.0;
            } else {
                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::getQ3 jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        return retVal;
        }
        void Rotation::applyTo(jdoubleArray doubleArray_0,jdoubleArray doubleArray_1) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",jthis);
        
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "applyTo", "([D[D)V");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named applyTo with signature ([D[D)V." << std::endl;
                return;
            } else {
                 env->CallVoidMethod(jthis, mid ,doubleArray_0,doubleArray_1 );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        
        }
        void Rotation::applyTo(jdouble * easyArg_0,jsize easyArg_0_length,jdouble * easyArg_1,jsize easyArg_1_length) {

         // convenience method, converts to/from JNI types to common C++ types.
         if(jthis == NULL) {
             std::cerr << "Call of method applyTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
             return;
         }
         JNIEnv *env =getEnv();
         jclass cls = env->GetObjectClass(jthis);
         if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",jthis);
         
                 
         jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
         env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
         jdoubleArray doubleArray_1= env->NewDoubleArray(easyArg_1_length);
         env->SetDoubleArrayRegion(doubleArray_1,0,easyArg_1_length,easyArg_1);
         applyTo(doubleArray_0,doubleArray_1);
         env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
         jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
         if(ref_0 == JNIGlobalRefType) {
          env->DeleteGlobalRef(doubleArray_0);
         }
         env->GetDoubleArrayRegion(doubleArray_1,0,easyArg_1_length,easyArg_1);
         jobjectRefType ref_1 = env->GetObjectRefType(doubleArray_1);
         if(ref_1 == JNIGlobalRefType) {
          env->DeleteGlobalRef(doubleArray_1);
         }
         
         releaseEnv(env);
        }

        Rotation Rotation::applyTo(Rotation  &rotation_0) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            Rotation nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "applyTo", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;)Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named applyTo with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;)Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;." << std::endl;
                Rotation nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid ,rotation_0.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Rotation retObject(retVal,false);
         return retObject;
        }
        Vector3D Rotation::applyTo(Vector3D  &vector3D_0) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "applyTo", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named applyTo with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid ,vector3D_0.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::applyTo jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        void Rotation::applyInverseTo(jdoubleArray doubleArray_0,jdoubleArray doubleArray_1) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyInverseTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            return;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",jthis);
        
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "applyInverseTo", "([D[D)V");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named applyInverseTo with signature ([D[D)V." << std::endl;
                return;
            } else {
                 env->CallVoidMethod(jthis, mid ,doubleArray_0,doubleArray_1 );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
        
        }
        void Rotation::applyInverseTo(jdouble * easyArg_0,jsize easyArg_0_length,jdouble * easyArg_1,jsize easyArg_1_length) {

         // convenience method, converts to/from JNI types to common C++ types.
         if(jthis == NULL) {
             std::cerr << "Call of method applyInverseTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
             return;
         }
         JNIEnv *env =getEnv();
         jclass cls = env->GetObjectClass(jthis);
         if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",jthis);
         
                 
         jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
         env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
         jdoubleArray doubleArray_1= env->NewDoubleArray(easyArg_1_length);
         env->SetDoubleArrayRegion(doubleArray_1,0,easyArg_1_length,easyArg_1);
         applyInverseTo(doubleArray_0,doubleArray_1);
         env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
         jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
         if(ref_0 == JNIGlobalRefType) {
          env->DeleteGlobalRef(doubleArray_0);
         }
         env->GetDoubleArrayRegion(doubleArray_1,0,easyArg_1_length,easyArg_1);
         jobjectRefType ref_1 = env->GetObjectRefType(doubleArray_1);
         if(ref_1 == JNIGlobalRefType) {
          env->DeleteGlobalRef(doubleArray_1);
         }
         
         releaseEnv(env);
        }

        Vector3D Rotation::applyInverseTo(Vector3D  &vector3D_0) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyInverseTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            Vector3D nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "applyInverseTo", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named applyInverseTo with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;." << std::endl;
                Vector3D nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid ,vector3D_0.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Vector3D retObject(retVal,false);
         return retObject;
        }
        Rotation Rotation::applyInverseTo(Rotation  &rotation_0) {

        if(jthis == NULL) {
            std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyInverseTo of org.apache.commons.math3.geometry.euclidean.threed.Rotation with jthis == NULL." << std::endl;
            Rotation nullObject((jobject)NULL,false); return nullObject;
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",jthis);
        jobject retVal=NULL;
        if (cls != NULL) {
            static jmethodID mid = env->GetMethodID(cls, "applyInverseTo", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;)Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;");
            if (NULL == mid) {
                std::cerr << "Class org.apache.commons.math3.geometry.euclidean.threed.Rotation has no method named applyInverseTo with signature (Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;)Lorg/apache/commons/math3/geometry/euclidean/threed/Rotation;." << std::endl;
                Rotation nullObject((jobject)NULL,false); return nullObject;
            } else {
                retVal= (jobject)  env->CallObjectMethod(jthis, mid ,rotation_0.jthis );
                jthrowable t = env->ExceptionOccurred();
                if(t != NULL) {
                    DebugPrintJObject(__FILE__,__LINE__," Rotation::applyInverseTo jthis=",t);
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                    throw this;
                }
            }
        }
        releaseEnv(env);
                 
         jobjectRefType ref = env->GetObjectRefType(retVal);
         Rotation retObject(retVal,false);
         return retObject;
        }
        static jclass getNewRotationClass() {
            jclass clss = getEnv()->FindClass("org/apache/commons/math3/geometry/euclidean/threed/Rotation");
            if (NULL == clss) {
                std::cerr << " Can't find class org/apache/commons/math3/geometry/euclidean/threed/Rotation" << std::endl;
            }
            return clss;
        }
        
        static jclass RotationClass = NULL;
        static inline jclass getRotationClass() {
            if (RotationClass != NULL) {
                return RotationClass;
            }
            RotationClass = getNewRotationClass();
        }
       } // end namespace threed
      } // end namespace euclidean
     } // end namespace geometry
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org



    // end namespace crclj
}

