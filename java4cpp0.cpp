
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "java4cpp.h"

namespace java4cpp {

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


 
 // get JNI handle for class ClassInDefaultPackage
 static inline jclass getClassInDefaultPackageClass();
 
 ClassInDefaultPackage::ClassInDefaultPackage(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
         // Place holder for future extensibility
 }
 
 ClassInDefaultPackage::ClassInDefaultPackage(const ClassInDefaultPackage &objref) {
     jobject _jthis = objref.jthis;
     if (_jthis != NULL) {
         jthis = getEnv()->NewGlobalRef(_jthis);
     }
 }
 ClassInDefaultPackage::ClassInDefaultPackage() : java::lang::Object((jobject)NULL,false) {
 JNIEnv *env =getEnv();
 static jclass cls = getClassInDefaultPackageClass();
 if (cls != NULL) {
     static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
     if (NULL == mid) {
         std::cerr << "Class ClassInDefaultPackage has no method constructor signature ()V" << std::endl;
     } else {
         jthis = env->NewObject(cls, mid );
         jthrowable t = env->ExceptionOccurred();
         if(t != NULL) {
             DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::%METHOD_NAME% jthis=",t);
             env->ExceptionDescribe();
             env->ExceptionClear();
             throw this;
         }
         if(jthis == NULL) {
             std::cerr << "Call to create new ClassInDefaultPackage with signature ()V returned null." << std::endl;
             releaseEnv(env);
             return;
         }
         jobjectRefType ref = env->GetObjectRefType(jthis);
         if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ClassInDefaultPackage jthis=",jthis);
         if(ref != JNIGlobalRefType) {
             jthis = env->NewGlobalRef(jthis);
         }
     }
 }
 releaseEnv(env);
 }

 ClassInDefaultPackage::ClassInDefaultPackage(jint int_0) : java::lang::Object((jobject)NULL,false) {
  JNIEnv *env =getEnv();
  static jclass cls = getClassInDefaultPackageClass();
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "<init>", "(I)V");
      if (NULL == mid) {
          std::cerr << "Class ClassInDefaultPackage has no method constructor signature (I)V" << std::endl;
      } else {
          jthis = env->NewObject(cls, mid ,int_0);
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::%METHOD_NAME% jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
          if(jthis == NULL) {
              std::cerr << "Call to create new ClassInDefaultPackage with signature (I)V returned null." << std::endl;
              releaseEnv(env);
              return;
          }
          jobjectRefType ref = env->GetObjectRefType(jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ClassInDefaultPackage jthis=",jthis);
          if(ref != JNIGlobalRefType) {
              jthis = env->NewGlobalRef(jthis);
          }
      }
  }
  releaseEnv(env);
 }


 // Destructor for ClassInDefaultPackage
 ClassInDefaultPackage::~ClassInDefaultPackage() {
 	// Place-holder for later extensibility.
 }

 jint ClassInDefaultPackage::getI() {

 if(jthis == NULL) {
     std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getI of ClassInDefaultPackage with jthis == NULL." << std::endl;
     return (jint) -1;
 }
 JNIEnv *env =getEnv();
 jclass cls = env->GetObjectClass(jthis);
 if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::getI jthis=",jthis);
 jint retVal= (jint) -1;
 if (cls != NULL) {
     static jmethodID mid = env->GetMethodID(cls, "getI", "()I");
     if (NULL == mid) {
         std::cerr << "Class ClassInDefaultPackage has no method named getI with signature ()I." << std::endl;
         return (jint) -1;
     } else {
         retVal= (jint)  env->CallIntMethod(jthis, mid  );
         jthrowable t = env->ExceptionOccurred();
         if(t != NULL) {
             DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::getI jthis=",t);
             env->ExceptionDescribe();
             env->ExceptionClear();
             throw this;
         }
     }
 }
 releaseEnv(env);
 return retVal;
 }
 void ClassInDefaultPackage::staticTest(jint int_0) {

 JNIEnv *env =getEnv();
 static jclass cls = getClassInDefaultPackageClass();
 
 if (cls != NULL) {
     static jmethodID mid = env->GetStaticMethodID(cls, "staticTest", "(I)V");
     if (NULL == mid) {
         std::cerr << "Class ClassInDefaultPackage has no method named staticTest with signature (I)V." << std::endl;
         return;
     } else {
          env->CallStaticVoidMethod( cls, mid ,int_0 );
         jthrowable t = env->ExceptionOccurred();
         if(t != NULL) {
             DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::staticTest jthis=",t);
             env->ExceptionDescribe();
             env->ExceptionClear();
             throw env;
         }
     }
 }
 releaseEnv(env);
 
 }
 static jclass getNewClassInDefaultPackageClass() {
     jclass clss = getEnv()->FindClass("ClassInDefaultPackage");
     if (NULL == clss) {
         std::cerr << " Can't find class ClassInDefaultPackage" << std::endl;
     }
     return clss;
 }
 
 static jclass ClassInDefaultPackageClass = NULL;
 static inline jclass getClassInDefaultPackageClass() {
     if (ClassInDefaultPackageClass != NULL) {
         return ClassInDefaultPackageClass;
     }
     ClassInDefaultPackageClass = getNewClassInDefaultPackageClass();
 }
  namespace testpackage{
  
  // get JNI handle for class testpackage.A
  static inline jclass getAClass();
  
  A::A(jobject _jthis, bool copy): ::java4cpp::java::lang::Object(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  A::A(const A &objref) {
      jobject _jthis = objref.jthis;
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
      }
  }
  A::A() : ::java4cpp::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getAClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class A has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," A::staticTest jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new A with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new A jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
  }


  // Destructor for testpackage.A
  A::~A() {
  	// Place-holder for later extensibility.
  }

  Test A::getTestStatic() {

  JNIEnv *env =getEnv();
  static jclass cls = getAClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetStaticMethodID(cls, "getTestStatic", "()Ltestpackage/Test;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.A has no method named getTestStatic with signature ()Ltestpackage/Test;." << std::endl;
          Test nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," A::getTestStatic jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw env;
          }
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   Test retObject(retVal,false);
   return retObject;
  }
  Test A::getTestNonStatic() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTestNonStatic of testpackage.A with jthis == NULL." << std::endl;
      Test nullObject((jobject)NULL,false); return nullObject;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," A::getTestNonStatic jthis=",jthis);
  jobject retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getTestNonStatic", "()Ltestpackage/Test;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.A has no method named getTestNonStatic with signature ()Ltestpackage/Test;." << std::endl;
          Test nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," A::getTestNonStatic jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   Test retObject(retVal,false);
   return retObject;
  }
  static jclass getNewAClass() {
      jclass clss = getEnv()->FindClass("testpackage/A");
      if (NULL == clss) {
          std::cerr << " Can't find class testpackage/A" << std::endl;
      }
      return clss;
  }
  
  static jclass AClass = NULL;
  static inline jclass getAClass() {
      if (AClass != NULL) {
          return AClass;
      }
      AClass = getNewAClass();
  }
  
  // get JNI handle for class testpackage.MyClient
  static inline jclass getMyClientClass();
  
  MyClient::MyClient(jobject _jthis, bool copy): ::java4cpp::java::lang::Object(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  MyClient::MyClient(const MyClient &objref) {
      jobject _jthis = objref.jthis;
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
      }
  }
  MyClient::MyClient() : ::java4cpp::java::lang::Object((jobject)NULL,false) {
  JNIEnv *env =getEnv();
  static jclass cls = getMyClientClass();
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
      if (NULL == mid) {
          std::cerr << "Class MyClient has no method constructor signature ()V" << std::endl;
      } else {
          jthis = env->NewObject(cls, mid );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::getTestNonStatic jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
          if(jthis == NULL) {
              std::cerr << "Call to create new MyClient with signature ()V returned null." << std::endl;
              releaseEnv(env);
              return;
          }
          jobjectRefType ref = env->GetObjectRefType(jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MyClient jthis=",jthis);
          if(ref != JNIGlobalRefType) {
              jthis = env->NewGlobalRef(jthis);
          }
      }
  }
  releaseEnv(env);
  }

  MyClient::MyClient(jstring string_0,jint int_1) : ::java4cpp::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getMyClientClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
       if (NULL == mid) {
           std::cerr << "Class MyClient has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0,int_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," MyClient::getTestNonStatic jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new MyClient with signature (Ljava/lang/String;I)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MyClient jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
  }

  MyClient::MyClient(const char * easyArg_0,jint easyArg_1) : ::java4cpp::java::lang::Object((jobject)NULL,false) {
  // Convenience Constructor converts common C++ types to JNI types
  JNIEnv *env =getEnv();
  static jclass cls = getMyClientClass();
  jstring string_0 = env->NewStringUTF(easyArg_0);
  jint int_1= easyArg_1;
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
      if (NULL == mid) {
          std::cerr << "Class MyClient has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
      } else {
          jthis = env->NewObject(cls, mid ,string_0,int_1);
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::getTestNonStatic jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
          if(jthis == NULL) {
              std::cerr << "Call to create new MyClient with signature (Ljava/lang/String;I)V returned null." << std::endl;
              releaseEnv(env);
              return;
          }
          jobjectRefType ref = env->GetObjectRefType(jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new MyClient jthis=",jthis);
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

  // Destructor for testpackage.MyClient
  MyClient::~MyClient() {
  	// Place-holder for later extensibility.
  }

  jboolean MyClient::equals(::java4cpp::java::lang::Object  &object_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of testpackage.MyClient with jthis == NULL." << std::endl;
      return false;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MyClient::equals jthis=",jthis);
  jboolean retVal=false;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
      if (NULL == mid) {
          std::cerr << "Class testpackage.MyClient has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
          return false;
      } else {
          retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::equals jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  jstring MyClient::toString() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of testpackage.MyClient with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MyClient::toString jthis=",jthis);
  jstring retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.MyClient has no method named toString with signature ()Ljava/lang/String;." << std::endl;
          return NULL;
      } else {
          retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::toString jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  jint MyClient::hashCode() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of testpackage.MyClient with jthis == NULL." << std::endl;
      return (jint) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MyClient::hashCode jthis=",jthis);
  jint retVal= (jint) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
      if (NULL == mid) {
          std::cerr << "Class testpackage.MyClient has no method named hashCode with signature ()I." << std::endl;
          return (jint) -1;
      } else {
          retVal= (jint)  env->CallIntMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::hashCode jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  jstring MyClient::getHost() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getHost of testpackage.MyClient with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MyClient::getHost jthis=",jthis);
  jstring retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getHost", "()Ljava/lang/String;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.MyClient has no method named getHost with signature ()Ljava/lang/String;." << std::endl;
          return NULL;
      } else {
          retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::getHost jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  jint MyClient::getPort() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPort of testpackage.MyClient with jthis == NULL." << std::endl;
      return (jint) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," MyClient::getPort jthis=",jthis);
  jint retVal= (jint) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getPort", "()I");
      if (NULL == mid) {
          std::cerr << "Class testpackage.MyClient has no method named getPort with signature ()I." << std::endl;
          return (jint) -1;
      } else {
          retVal= (jint)  env->CallIntMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," MyClient::getPort jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  static jclass getNewMyClientClass() {
      jclass clss = getEnv()->FindClass("testpackage/MyClient");
      if (NULL == clss) {
          std::cerr << " Can't find class testpackage/MyClient" << std::endl;
      }
      return clss;
  }
  
  static jclass MyClientClass = NULL;
  static inline jclass getMyClientClass() {
      if (MyClientClass != NULL) {
          return MyClientClass;
      }
      MyClientClass = getNewMyClientClass();
  }
  
  // get JNI handle for class testpackage.Test
  static inline jclass getTestClass();
  
  Test::Test(jobject _jthis, bool copy): ::java4cpp::java::lang::Object(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  Test::Test(const Test &objref) {
      jobject _jthis = objref.jthis;
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
      }
  }
  Test::Test() : ::java4cpp::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getTestClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class Test has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Test::getPort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Test with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Test jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
  }


  // Destructor for testpackage.Test
  Test::~Test() {
  	// Place-holder for later extensibility.
  }

  Test Test::getTestStatic() {

  JNIEnv *env =getEnv();
  static jclass cls = getTestClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetStaticMethodID(cls, "getTestStatic", "()Ltestpackage/Test;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getTestStatic with signature ()Ltestpackage/Test;." << std::endl;
          Test nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getTestStatic jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw env;
          }
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   Test retObject(retVal,false);
   return retObject;
  }
  jint Test::getI() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getI of testpackage.Test with jthis == NULL." << std::endl;
      return (jint) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getI jthis=",jthis);
  jint retVal= (jint) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getI", "()I");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getI with signature ()I." << std::endl;
          return (jint) -1;
      } else {
          retVal= (jint)  env->CallIntMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getI jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  ::java4cpp::java::util::List Test::getListOfStrings() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getListOfStrings of testpackage.Test with jthis == NULL." << std::endl;
      ::java4cpp::java::util::List nullObject((jobject)NULL,false); return nullObject;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getListOfStrings jthis=",jthis);
  jobject retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getListOfStrings", "()Ljava/util/List;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getListOfStrings with signature ()Ljava/util/List;." << std::endl;
          ::java4cpp::java::util::List nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getListOfStrings jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   ::java4cpp::java::util::List retObject(retVal,false);
   return retObject;
  }
  void Test::setListOfStrings(::java4cpp::java::util::List  &list_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setListOfStrings of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setListOfStrings jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setListOfStrings", "(Ljava/util/List;)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setListOfStrings with signature (Ljava/util/List;)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,list_0.jthis );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setListOfStrings jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  A Test::getClassObjectA() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getClassObjectA of testpackage.Test with jthis == NULL." << std::endl;
      A nullObject((jobject)NULL,false); return nullObject;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getClassObjectA jthis=",jthis);
  jobject retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getClassObjectA", "()Ltestpackage/A;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getClassObjectA with signature ()Ltestpackage/A;." << std::endl;
          A nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getClassObjectA jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   A retObject(retVal,false);
   return retObject;
  }
  void Test::setClassObjectA(A  &a_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setClassObjectA of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setClassObjectA jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setClassObjectA", "(Ltestpackage/A;)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setClassObjectA with signature (Ltestpackage/A;)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,a_0.jthis );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setClassObjectA jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jbyteArray Test::getByteArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getByteArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getByteArrayProp jthis=",jthis);
  jbyteArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getByteArrayProp", "()[B");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getByteArrayProp with signature ()[B." << std::endl;
          return NULL;
      } else {
          retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getByteArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setByteArrayProp(jbyteArray byteArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setByteArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setByteArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setByteArrayProp", "([B)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setByteArrayProp with signature ([B)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,byteArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setByteArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setByteArrayProp(jbyte * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setByteArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setByteArrayProp jthis=",jthis);
   
           
   jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
   env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
   setByteArrayProp(byteArray_0);
   env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(byteArray_0);
   }
   
   releaseEnv(env);
  }

  jbyte Test::getByteProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getByteProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jbyte) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getByteProp jthis=",jthis);
  jbyte retVal= (jbyte) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getByteProp", "()B");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getByteProp with signature ()B." << std::endl;
          return (jbyte) -1;
      } else {
          retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getByteProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setByteProp(jbyte byte_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setByteProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setByteProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setByteProp", "(B)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setByteProp with signature (B)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,byte_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setByteProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jcharArray Test::getCharArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCharArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getCharArrayProp jthis=",jthis);
  jcharArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getCharArrayProp", "()[C");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getCharArrayProp with signature ()[C." << std::endl;
          return NULL;
      } else {
          retVal= (jcharArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getCharArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setCharArrayProp(jcharArray charArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCharArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setCharArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setCharArrayProp", "([C)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setCharArrayProp with signature ([C)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,charArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setCharArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setCharArrayProp(jchar * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setCharArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setCharArrayProp jthis=",jthis);
   
           
   jcharArray charArray_0= env->NewCharArray(easyArg_0_length);
   env->SetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
   setCharArrayProp(charArray_0);
   env->GetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(charArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(charArray_0);
   }
   
   releaseEnv(env);
  }

  jchar Test::getCharProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCharProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jchar) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getCharProp jthis=",jthis);
  jchar retVal= (jchar) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getCharProp", "()C");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getCharProp with signature ()C." << std::endl;
          return (jchar) -1;
      } else {
          retVal= (jchar)  env->CallCharMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getCharProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  jshort Test::getShortProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getShortProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jshort) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getShortProp jthis=",jthis);
  jshort retVal=(jshort) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getShortProp", "()S");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getShortProp with signature ()S." << std::endl;
          return (jshort) -1;
      } else {
          retVal= (jshort)  env->CallShortMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getShortProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setShortProp(jshort short_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setShortProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setShortProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setShortProp", "(S)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setShortProp with signature (S)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,short_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setShortProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jshortArray Test::getShortArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getShortArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getShortArrayProp jthis=",jthis);
  jshortArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getShortArrayProp", "()[S");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getShortArrayProp with signature ()[S." << std::endl;
          return NULL;
      } else {
          retVal= (jshortArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getShortArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  jint Test::getIntProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getIntProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jint) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getIntProp jthis=",jthis);
  jint retVal= (jint) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getIntProp", "()I");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getIntProp with signature ()I." << std::endl;
          return (jint) -1;
      } else {
          retVal= (jint)  env->CallIntMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getIntProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setIntProp(jint int_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setIntProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setIntProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setIntProp", "(I)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setIntProp with signature (I)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,int_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setIntProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jintArray Test::getIntArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getIntArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getIntArrayProp jthis=",jthis);
  jintArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getIntArrayProp", "()[I");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getIntArrayProp with signature ()[I." << std::endl;
          return NULL;
      } else {
          retVal= (jintArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getIntArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setIntArrayProp(jintArray intArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setIntArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setIntArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setIntArrayProp", "([I)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setIntArrayProp with signature ([I)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,intArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setIntArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setIntArrayProp(jint * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setIntArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setIntArrayProp jthis=",jthis);
   
           
   jintArray intArray_0= env->NewIntArray(easyArg_0_length);
   env->SetIntArrayRegion(intArray_0,0,easyArg_0_length,easyArg_0);
   setIntArrayProp(intArray_0);
   env->GetIntArrayRegion(intArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(intArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(intArray_0);
   }
   
   releaseEnv(env);
  }

  jlong Test::getLongProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLongProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jlong) -1;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getLongProp jthis=",jthis);
  jlong retVal= (jlong) -1;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getLongProp", "()J");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getLongProp with signature ()J." << std::endl;
          return (jlong) -1;
      } else {
          retVal= (jlong)  env->CallLongMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getLongProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setLongProp(jlong long_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLongProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setLongProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setLongProp", "(J)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setLongProp with signature (J)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,long_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setLongProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jlongArray Test::getLongArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLongArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getLongArrayProp jthis=",jthis);
  jlongArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getLongArrayProp", "()[J");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getLongArrayProp with signature ()[J." << std::endl;
          return NULL;
      } else {
          retVal= (jlongArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getLongArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setLongArrayProp(jlongArray longArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLongArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setLongArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setLongArrayProp", "([J)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setLongArrayProp with signature ([J)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,longArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setLongArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setLongArrayProp(jlong * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setLongArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setLongArrayProp jthis=",jthis);
   
           
   jlongArray longArray_0= env->NewLongArray(easyArg_0_length);
   env->SetLongArrayRegion(longArray_0,0,easyArg_0_length,easyArg_0);
   setLongArrayProp(longArray_0);
   env->GetLongArrayRegion(longArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(longArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(longArray_0);
   }
   
   releaseEnv(env);
  }

  jfloat Test::getFloatProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFloatProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jfloat) -1.0;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getFloatProp jthis=",jthis);
  jfloat retVal= (jfloat) -1.0;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getFloatProp", "()F");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getFloatProp with signature ()F." << std::endl;
          return (jfloat) -1.0;
      } else {
          retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getFloatProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setFloatProp(jfloat float_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFloatProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setFloatProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setFloatProp", "(F)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setFloatProp with signature (F)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,float_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setFloatProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jfloatArray Test::getFloatArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFloatArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getFloatArrayProp jthis=",jthis);
  jfloatArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getFloatArrayProp", "()[F");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getFloatArrayProp with signature ()[F." << std::endl;
          return NULL;
      } else {
          retVal= (jfloatArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getFloatArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setFloatArrayProp(jfloatArray floatArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFloatArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setFloatArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setFloatArrayProp", "([F)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setFloatArrayProp with signature ([F)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,floatArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setFloatArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setFloatArrayProp(jfloat * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setFloatArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setFloatArrayProp jthis=",jthis);
   
           
   jfloatArray floatArray_0= env->NewFloatArray(easyArg_0_length);
   env->SetFloatArrayRegion(floatArray_0,0,easyArg_0_length,easyArg_0);
   setFloatArrayProp(floatArray_0);
   env->GetFloatArrayRegion(floatArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(floatArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(floatArray_0);
   }
   
   releaseEnv(env);
  }

  jdouble Test::getDoubleProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDoubleProp of testpackage.Test with jthis == NULL." << std::endl;
      return (jdouble) -1.0;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleProp jthis=",jthis);
  jdouble retVal= (jdouble) -1.0;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getDoubleProp", "()D");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getDoubleProp with signature ()D." << std::endl;
          return (jdouble) -1.0;
      } else {
          retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setDoubleProp(jdouble double_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setDoubleProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setDoubleProp", "(D)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setDoubleProp with signature (D)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,double_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jdoubleArray Test::getDoubleArrayProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDoubleArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleArrayProp jthis=",jthis);
  jdoubleArray retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getDoubleArrayProp", "()[D");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getDoubleArrayProp with signature ()[D." << std::endl;
          return NULL;
      } else {
          retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setDoubleArrayProp(jdoubleArray doubleArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setDoubleArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setDoubleArrayProp", "([D)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setDoubleArrayProp with signature ([D)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,doubleArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setDoubleArrayProp(jdouble * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setDoubleArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleArrayProp jthis=",jthis);
   
           
   jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
   env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
   setDoubleArrayProp(doubleArray_0);
   env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(doubleArray_0);
   }
   
   releaseEnv(env);
  }

  void Test::setShortArrayProp(jshortArray shortArray_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setShortArrayProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setShortArrayProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setShortArrayProp", "([S)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setShortArrayProp with signature ([S)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,shortArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setShortArrayProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setShortArrayProp(jshort * easyArg_0,jsize easyArg_0_length) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setShortArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setShortArrayProp jthis=",jthis);
   
           
   jshortArray shortArray_0= env->NewShortArray(easyArg_0_length);
   env->SetShortArrayRegion(shortArray_0,0,easyArg_0_length,easyArg_0);
   setShortArrayProp(shortArray_0);
   env->GetShortArrayRegion(shortArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(shortArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(shortArray_0);
   }
   
   releaseEnv(env);
  }

  void Test::setCharProp(jchar char_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCharProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setCharProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setCharProp", "(C)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setCharProp with signature (C)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,char_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setCharProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  jstring Test::getStrProp() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStrProp of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getStrProp jthis=",jthis);
  jstring retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "getStrProp", "()Ljava/lang/String;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named getStrProp with signature ()Ljava/lang/String;." << std::endl;
          return NULL;
      } else {
          retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::getStrProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::setStrProp(jstring string_0) {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStrProp of testpackage.Test with jthis == NULL." << std::endl;
      return;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setStrProp jthis=",jthis);
  
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "setStrProp", "(Ljava/lang/String;)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named setStrProp with signature (Ljava/lang/String;)V." << std::endl;
          return;
      } else {
           env->CallVoidMethod(jthis, mid ,string_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::setStrProp jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::setStrProp(const char * easyArg_0) {

   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setStrProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setStrProp jthis=",jthis);
   
           
   jstring string_0 = env->NewStringUTF(easyArg_0);
   setStrProp(string_0);
   jobjectRefType ref_0 = env->GetObjectRefType(string_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_0);
   }
   
   releaseEnv(env);
  }

  jstring Test::funcReturningString() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method funcReturningString of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::funcReturningString jthis=",jthis);
  jstring retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "funcReturningString", "()Ljava/lang/String;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named funcReturningString with signature ()Ljava/lang/String;." << std::endl;
          return NULL;
      } else {
          retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::funcReturningString jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  void Test::main(jobjectArray stringArray_0) {

  JNIEnv *env =getEnv();
  static jclass cls = getTestClass();
  
  if (cls != NULL) {
      static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
          return;
      } else {
           env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::main jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw env;
          }
      }
  }
  releaseEnv(env);
  
  }
  void Test::main(int argc, const char **argv) {
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
  jstring Test::toString() {

  if(jthis == NULL) {
      std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of testpackage.Test with jthis == NULL." << std::endl;
      return NULL;
  }
  JNIEnv *env =getEnv();
  jclass cls = env->GetObjectClass(jthis);
  if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::toString jthis=",jthis);
  jstring retVal=NULL;
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
      if (NULL == mid) {
          std::cerr << "Class testpackage.Test has no method named toString with signature ()Ljava/lang/String;." << std::endl;
          return NULL;
      } else {
          retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              DebugPrintJObject(__FILE__,__LINE__," Test::toString jthis=",t);
              env->ExceptionDescribe();
              env->ExceptionClear();
              throw this;
          }
      }
  }
  releaseEnv(env);
  return retVal;
  }
  static jclass getNewTestClass() {
      jclass clss = getEnv()->FindClass("testpackage/Test");
      if (NULL == clss) {
          std::cerr << " Can't find class testpackage/Test" << std::endl;
      }
      return clss;
  }
  
  static jclass TestClass = NULL;
  static inline jclass getTestClass() {
      if (TestClass != NULL) {
          return TestClass;
      }
      TestClass = getNewTestClass();
  }
 } // end namespace testpackage

  namespace java{
   namespace util{
   
   // get JNI handle for class java.util.List
   static inline jclass getListClass();
   
   List::List(jobject _jthis, bool copy): ::java4cpp::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   List::List(const List &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   List::List() : ::java4cpp::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getListClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class List has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," List::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new List with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new List jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for java.util.List
   List::~List() {
   	// Place-holder for later extensibility.
   }

   static jclass getNewListClass() {
       jclass clss = getEnv()->FindClass("java/util/List");
       if (NULL == clss) {
           std::cerr << " Can't find class java/util/List" << std::endl;
       }
       return clss;
   }
   
   static jclass ListClass = NULL;
   static inline jclass getListClass() {
       if (ListClass != NULL) {
           return ListClass;
       }
       ListClass = getNewListClass();
   }
  } // end namespace util
 } // end namespace java




    static JNIEnv *getNewEnv() {
        JavaVM *jvm; /* denotes a Java VM */
        JNIEnv *env; /* pointer to native method interface */
        JavaVM * jvmBuf[1];
        jsize nVMs;
        debug_j4cpp = debug_j4cpp || (getenv("DEBUG_J4CPP") != NULL);
        char *classPathEnv = getenv("CLASSPATH");
        char *jvmOptionsEnv = getenv("JVM_OPTIONS");
        std::string str;
        str += "src/test/resources/Test.jar";
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
    
    void PrintObject(const char *prefix, const ::java4cpp::java::lang::Object &objref) {
        PrintJObject(prefix,objref.jthis);
    }
    
    extern void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    extern bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace java4cpp
}

