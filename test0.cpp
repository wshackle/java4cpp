
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "test.h"

namespace test {

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

            Object & Object::operator =(const Object &otherobject) {
                jobject oldjthis = jthis;
                jobject _newjthis = otherobject.jthis;
                jobject newjthis= NULL;
                jthis= NULL;
                JNIEnv *env = getEnv();
                if (_newjthis != NULL) {
                    if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__,"Object::operator= called for _newjthis=",_newjthis);
                    newjthis = env->NewGlobalRef(_newjthis);
                }
                if (NULL != oldjthis) {
                    if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__,"Object::operator= called for oldjthis=",oldjthis);
                    env->DeleteGlobalRef(oldjthis);
                    oldjthis = NULL;
                }
                jthis=newjthis;
                releaseEnv(env);
                return *this;
            }
            
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



// start_segment_index = 0
// start_segment_index = 8
// segment_index = 0
// classesSegList=[class ClassInDefaultPackage, class testpackage.A, class testpackage.Test, class java.lang.Enum, class testpackage.ExternalPublicEnum, class testpackage.MyClient, class testpackage.Test$MyEnum, interface java.util.List]


// class_index = 0 clss=class ClassInDefaultPackage

 
 // get JNI handle for class ClassInDefaultPackage
 static inline jclass getClassInDefaultPackageClass();
 
 ClassInDefaultPackage::ClassInDefaultPackage(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
         // Place holder for future extensibility
 }
 
 ClassInDefaultPackage::ClassInDefaultPackage(const ClassInDefaultPackage &objref): java::lang::Object((jobject)NULL,false) {
     jobject _jthis = objref.jthis;
     if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class ClassInDefaultPackage _jthis=",_jthis);
     if (_jthis != NULL) {
         jthis = getEnv()->NewGlobalRef(_jthis);
         if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class ClassInDefaultPackage jthis=",jthis);
     }
 }
 
 ClassInDefaultPackage ClassInDefaultPackage::cast(const java::lang::Object &objref) {
     JNIEnv *env =getEnv();
     static jclass cls = getClassInDefaultPackageClass(); 
     jclass objcls = env->GetObjectClass(objref.jthis);
     if(!env->IsAssignableFrom(objcls,cls)) {
         throw objcls;
     }
     ClassInDefaultPackage retVal(objref.jthis,true);
     return retVal;
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
             if(GetDebugJ4Cpp()) {
                 DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::%METHOD_NAME% jthis=",t);
                 env->ExceptionDescribe();
             }
             throw t;
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
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::%METHOD_NAME% jthis=",t);
                  env->ExceptionDescribe();
              }
              throw t;
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
              if(GetDebugJ4Cpp()) env->ExceptionDescribe();
  //            env->ExceptionClear();
              throw t;
          }
      }
  }
  releaseEnv(env);
  
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
          DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::getI jthis=",jthis);
          std::cerr << __FILE__ << ":" << __LINE__ <<  " Class ClassInDefaultPackage has no method named getI with signature ()I." << std::endl;
          return (jint) -1;
      } else {
          retVal= (jint)  env->CallIntMethod(jthis, mid  );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::getI jthrowable t=",t);
                  env->ExceptionDescribe();
              }
  //            env->ExceptionClear();
              throw t;
          }
      }
  }
  releaseEnv(env);
  return retVal;
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
     return ClassInDefaultPackageClass;
 }

// class_index = 1 clss=class testpackage.A

  namespace testpackage{
  
  // get JNI handle for class testpackage.A
  static inline jclass getAClass();
  
  A::A(jobject _jthis, bool copy): ::test::java::lang::Object(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  A::A(const A &objref): ::test::java::lang::Object((jobject)NULL,false) {
      jobject _jthis = objref.jthis;
      if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class A _jthis=",_jthis);
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class A jthis=",jthis);
      }
  }
  
  A A::cast(const ::test::java::lang::Object &objref) {
      JNIEnv *env =getEnv();
      static jclass cls = getAClass(); 
      jclass objcls = env->GetObjectClass(objref.jthis);
      if(!env->IsAssignableFrom(objcls,cls)) {
          throw objcls;
      }
      A retVal(objref.jthis,true);
      return retVal;
  }
  A::A() : ::test::java::lang::Object((jobject)NULL,false) {
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
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," A::getI jthis=",t);
                   env->ExceptionDescribe();
               }
               throw t;
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
           static Test nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," A::getTestStatic jthis=",t);
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   Test retObject(retVal,false);
   return retObject;
  }

  Test A::getTestNonStatic() {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTestNonStatic of testpackage.A with jthis == NULL." << std::endl;
       static Test nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," A::getTestNonStatic jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTestNonStatic", "()Ltestpackage/Test;");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," A::getTestNonStatic jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.A has no method named getTestNonStatic with signature ()Ltestpackage/Test;." << std::endl;
           static Test nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," A::getTestNonStatic jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   Test retObject(retVal,false);
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
      return AClass;
  }

// class_index = 2 clss=class testpackage.Test

  
  // get JNI handle for class testpackage.Test
  static inline jclass getTestClass();
  
  Test::Test(jobject _jthis, bool copy): ::test::java::lang::Object(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  Test::Test(const Test &objref): ::test::java::lang::Object((jobject)NULL,false) {
      jobject _jthis = objref.jthis;
      if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class Test _jthis=",_jthis);
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class Test jthis=",jthis);
      }
  }
  
  Test Test::cast(const ::test::java::lang::Object &objref) {
      JNIEnv *env =getEnv();
      static jclass cls = getTestClass(); 
      jclass objcls = env->GetObjectClass(objref.jthis);
      if(!env->IsAssignableFrom(objcls,cls)) {
          throw objcls;
      }
      Test retVal(objref.jthis,true);
      return retVal;
  }
  Test::Test() : ::test::java::lang::Object((jobject)NULL,false) {
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
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getTestNonStatic jthis=",t);
                   env->ExceptionDescribe();
               }
               throw t;
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


  // Field getter for nonstaticIntField
  jint Test::getNonstaticIntField() {
  }

  // Field setter for nonstaticIntField
  void Test::setNonstaticIntField(jint int_0) {
  }

  // Field getter for staticIntField
  jint Test::getStaticIntField() {
  JNIEnv *env =getEnv();
  static jclass cls = getTestClass();
  jint retVal= (jint) -1;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "staticIntField", "I");
      if (NULL == fid) {
          std::cerr << "Class testpackage.Test has no field named staticIntField with signature I." << std::endl;
          return (jint) -1;
      } else {
          retVal= (jint)  env->GetStaticIntField( cls, fid );
      }
  }
  releaseEnv(env);
  return retVal;
  }

  // Field setter for staticIntField
  void Test::setStaticIntField(jint int_0) {
  }

  TestMyEnum Test::getEnumABC() {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getEnumABC of testpackage.Test with jthis == NULL." << std::endl;
       static TestMyEnum nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getEnumABC jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getEnumABC", "()Ltestpackage/Test/MyEnum;");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::getEnumABC jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getEnumABC with signature ()Ltestpackage/Test/MyEnum;." << std::endl;
           static TestMyEnum nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getEnumABC jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   TestMyEnum retObject(retVal,false);
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getI jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getI with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getI jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   return retVal;
  }

  Test Test::getTestStatic() {
   JNIEnv *env =getEnv();
   static jclass cls = getTestClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getTestStatic", "()Ltestpackage/Test;");
       if (NULL == mid) {
           std::cerr << "Class testpackage.Test has no method named getTestStatic with signature ()Ltestpackage/Test;." << std::endl;
           static Test nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Test::getTestStatic jthis=",t);
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   Test retObject(retVal,false);
   return retObject;
  }

  ExternalPublicEnum Test::getExternalPublicEnumProp() {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getExternalPublicEnumProp of testpackage.Test with jthis == NULL." << std::endl;
       static ExternalPublicEnum nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getExternalPublicEnumProp jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getExternalPublicEnumProp", "()Ltestpackage/ExternalPublicEnum;");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::getExternalPublicEnumProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getExternalPublicEnumProp with signature ()Ltestpackage/ExternalPublicEnum;." << std::endl;
           static ExternalPublicEnum nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getExternalPublicEnumProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   ExternalPublicEnum retObject(retVal,false);
   return retObject;
  }

  void Test::setExternalPublicEnumProp(const ExternalPublicEnum & externalPublicEnum_0) {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExternalPublicEnumProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setExternalPublicEnumProp jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExternalPublicEnumProp", "(Ltestpackage/ExternalPublicEnum;)V");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::setExternalPublicEnumProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setExternalPublicEnumProp with signature (Ltestpackage/ExternalPublicEnum;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,externalPublicEnum_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setExternalPublicEnumProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  void Test::setEnumABC(const TestMyEnum & myEnum_0) {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setEnumABC of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setEnumABC jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setEnumABC", "(Ltestpackage/Test/MyEnum;)V");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::setEnumABC jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setEnumABC with signature (Ltestpackage/Test/MyEnum;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,myEnum_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setEnumABC jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  ::test::java::util::List Test::getListOfStrings() {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getListOfStrings of testpackage.Test with jthis == NULL." << std::endl;
       static ::test::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getListOfStrings jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getListOfStrings", "()Ljava/util/List;");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::getListOfStrings jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getListOfStrings with signature ()Ljava/util/List;." << std::endl;
           static ::test::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getListOfStrings jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   ::test::java::util::List retObject(retVal,false);
   return retObject;
  }

  void Test::setListOfStrings(const ::test::java::util::List & list_0) {
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setListOfStrings jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setListOfStrings with signature (Ljava/util/List;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,list_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setListOfStrings jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  A Test::getClassObjectA() {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getClassObjectA of testpackage.Test with jthis == NULL." << std::endl;
       static A nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getClassObjectA jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getClassObjectA", "()Ltestpackage/A;");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::getClassObjectA jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getClassObjectA with signature ()Ltestpackage/A;." << std::endl;
           static A nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getClassObjectA jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   A retObject(retVal,false);
   return retObject;
  }

  void Test::setClassObjectA(const A & a_0) {
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setClassObjectA jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setClassObjectA with signature (Ltestpackage/A;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,a_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setClassObjectA jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  jbooleanArray Test::getBooleanArrayProp() {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getBooleanArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::getBooleanArrayProp jthis=",jthis);
   jbooleanArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getBooleanArrayProp", "()[Z");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::getBooleanArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getBooleanArrayProp with signature ()[Z." << std::endl;
           return NULL;
       } else {
           retVal= (jbooleanArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getBooleanArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   return retVal;
  }

  void Test::setBooleanArrayProp(jbooleanArray booleanArray_0) {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setBooleanArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setBooleanArrayProp jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setBooleanArrayProp", "([Z)V");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::setBooleanArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setBooleanArrayProp with signature ([Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,booleanArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setBooleanArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setBooleanArrayProp
  void Test::setBooleanArrayProp(jboolean * easyArg_0,jsize easyArg_0_length) {
   // convenience method, converts to/from JNI types to common C++ types.
   if(jthis == NULL) {
       std::cerr << "Call of method setBooleanArrayProp of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setBooleanArrayProp jthis=",jthis);
   
           
   jbooleanArray booleanArray_0= env->NewBooleanArray(easyArg_0_length);
   env->SetBooleanArrayRegion(booleanArray_0,0,easyArg_0_length,easyArg_0);
   setBooleanArrayProp(booleanArray_0);
   env->GetBooleanArrayRegion(booleanArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(booleanArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(booleanArray_0);
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getByteArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getByteArrayProp with signature ()[B." << std::endl;
           return NULL;
       } else {
           retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getByteArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setByteArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setByteArrayProp with signature ([B)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setByteArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setByteArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getByteProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getByteProp with signature ()B." << std::endl;
           return (jbyte) -1;
       } else {
           retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getByteProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setByteProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setByteProp with signature (B)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byte_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setByteProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getCharArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getCharArrayProp with signature ()[C." << std::endl;
           return NULL;
       } else {
           retVal= (jcharArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getCharArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setCharArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setCharArrayProp with signature ([C)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,charArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setCharArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setCharArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getCharProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getCharProp with signature ()C." << std::endl;
           return (jchar) -1;
       } else {
           retVal= (jchar)  env->CallCharMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getCharProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getShortProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getShortProp with signature ()S." << std::endl;
           return (jshort) -1;
       } else {
           retVal= (jshort)  env->CallShortMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getShortProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setShortProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setShortProp with signature (S)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,short_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setShortProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getShortArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getShortArrayProp with signature ()[S." << std::endl;
           return NULL;
       } else {
           retVal= (jshortArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getShortArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getIntProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getIntProp with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getIntProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setIntProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setIntProp with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setIntProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getIntArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getIntArrayProp with signature ()[I." << std::endl;
           return NULL;
       } else {
           retVal= (jintArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getIntArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setIntArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setIntArrayProp with signature ([I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,intArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setIntArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setIntArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getLongProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getLongProp with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getLongProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setLongProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setLongProp with signature (J)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setLongProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getLongArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getLongArrayProp with signature ()[J." << std::endl;
           return NULL;
       } else {
           retVal= (jlongArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getLongArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setLongArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setLongArrayProp with signature ([J)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,longArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setLongArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setLongArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getFloatProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getFloatProp with signature ()F." << std::endl;
           return (jfloat) -1.0;
       } else {
           retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getFloatProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setFloatProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setFloatProp with signature (F)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,float_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setFloatProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getFloatArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getFloatArrayProp with signature ()[F." << std::endl;
           return NULL;
       } else {
           retVal= (jfloatArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getFloatArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setFloatArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setFloatArrayProp with signature ([F)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,floatArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setFloatArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setFloatArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getDoubleProp with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setDoubleProp with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getDoubleArrayProp with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setDoubleArrayProp with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setDoubleArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setShortArrayProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setShortArrayProp with signature ([S)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,shortArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setShortArrayProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setShortArrayProp
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setCharProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setCharProp with signature (C)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,char_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setCharProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::getStrProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named getStrProp with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::getStrProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::setStrProp jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setStrProp with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setStrProp jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   
  }

  // Easy call alternative for setStrProp
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


  void Test::setI(jint int_0) {
   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setI of testpackage.Test with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Test::setI jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setI", "(I)V");
       if (NULL == mid) {
           DebugPrintJObject(__FILE__,__LINE__," Test::setI jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named setI with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::setI jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
           }
       }
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
           DebugPrintJObject(__FILE__,__LINE__," Test::funcReturningString jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named funcReturningString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::funcReturningString jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," Test::toString jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.Test has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," Test::toString jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
      return TestClass;
  }
 } // end namespace testpackage


// class_index = 3 clss=class java.lang.Enum

  namespace java{
   namespace lang{
   
   // get JNI handle for class java.lang.Enum
   static inline jclass getEnumClass();
   
   Enum::Enum(jobject _jthis, bool copy): Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Enum::Enum(const Enum &objref): Object((jobject)NULL,false) {
       jobject _jthis = objref.jthis;
       if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class Enum _jthis=",_jthis);
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class Enum jthis=",jthis);
       }
   }
   
   Enum Enum::cast(const Object &objref) {
       JNIEnv *env =getEnv();
       static jclass cls = getEnumClass(); 
       jclass objcls = env->GetObjectClass(objref.jthis);
       if(!env->IsAssignableFrom(objcls,cls)) {
           throw objcls;
       }
       Enum retVal(objref.jthis,true);
       return retVal;
   }

   // Destructor for java.lang.Enum
   Enum::~Enum() {
   	// Place-holder for later extensibility.
   }


   jstring Enum::name() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method name of java.lang.Enum with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Enum::name jthis=",jthis);
    jstring retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "name", "()Ljava/lang/String;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," Enum::name jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.lang.Enum has no method named name with signature ()Ljava/lang/String;." << std::endl;
            return NULL;
        } else {
            retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," Enum::name jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jboolean Enum::equals(const Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.lang.Enum with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Enum::equals jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," Enum::equals jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.lang.Enum has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," Enum::equals jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jstring Enum::toString() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.lang.Enum with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Enum::toString jthis=",jthis);
    jstring retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," Enum::toString jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.lang.Enum has no method named toString with signature ()Ljava/lang/String;." << std::endl;
            return NULL;
        } else {
            retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," Enum::toString jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint Enum::hashCode() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.lang.Enum with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Enum::hashCode jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," Enum::hashCode jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.lang.Enum has no method named hashCode with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," Enum::hashCode jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint Enum::compareTo1(const Enum & enum_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method compareTo1 of java.lang.Enum with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Enum::compareTo1 jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/lang/Enum;)I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," Enum::compareTo1 jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.lang.Enum has no method named compareTo with signature (Ljava/lang/Enum;)I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid ,enum_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," Enum::compareTo1 jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint Enum::ordinal() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method ordinal of java.lang.Enum with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Enum::ordinal jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "ordinal", "()I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," Enum::ordinal jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.lang.Enum has no method named ordinal with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," Enum::ordinal jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }
   static jclass getNewEnumClass() {
       jclass clss = getEnv()->FindClass("java/lang/Enum");
       if (NULL == clss) {
           std::cerr << " Can't find class java/lang/Enum" << std::endl;
       }
       return clss;
   }
   
   static jclass EnumClass = NULL;
   static inline jclass getEnumClass() {
       if (EnumClass != NULL) {
           return EnumClass;
       }
       EnumClass = getNewEnumClass();
       return EnumClass;
   }
  } // end namespace lang
 } // end namespace java


// class_index = 4 clss=class testpackage.ExternalPublicEnum

  namespace testpackage{
  
  // get JNI handle for class testpackage.ExternalPublicEnum
  static inline jclass getExternalPublicEnumClass();
  
  ExternalPublicEnum::ExternalPublicEnum(jobject _jthis, bool copy): ::test::java::lang::Enum(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  ExternalPublicEnum::ExternalPublicEnum(const ExternalPublicEnum &objref): ::test::java::lang::Enum((jobject)NULL,false) {
      jobject _jthis = objref.jthis;
      if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class ExternalPublicEnum _jthis=",_jthis);
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class ExternalPublicEnum jthis=",jthis);
      }
  }
  
  ExternalPublicEnum ExternalPublicEnum::cast(const ::test::java::lang::Object &objref) {
      JNIEnv *env =getEnv();
      static jclass cls = getExternalPublicEnumClass(); 
      jclass objcls = env->GetObjectClass(objref.jthis);
      if(!env->IsAssignableFrom(objcls,cls)) {
          throw objcls;
      }
      ExternalPublicEnum retVal(objref.jthis,true);
      return retVal;
  }
  ExternalPublicEnum::ExternalPublicEnum() : ::test::java::lang::Enum((jobject)NULL,false) {
  JNIEnv *env =getEnv();
  static jclass cls = getExternalPublicEnumClass();
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
      if (NULL == mid) {
          std::cerr << "Class ExternalPublicEnum has no method constructor signature ()V" << std::endl;
      } else {
          jthis = env->NewObject(cls, mid );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," ExternalPublicEnum::ordinal jthis=",t);
                  env->ExceptionDescribe();
              }
              throw t;
          }
          if(jthis == NULL) {
              std::cerr << "Call to create new ExternalPublicEnum with signature ()V returned null." << std::endl;
              releaseEnv(env);
              return;
          }
          jobjectRefType ref = env->GetObjectRefType(jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ExternalPublicEnum jthis=",jthis);
          if(ref != JNIGlobalRefType) {
              jthis = env->NewGlobalRef(jthis);
          }
      }
  }
  releaseEnv(env);
  }


  // Destructor for testpackage.ExternalPublicEnum
  ExternalPublicEnum::~ExternalPublicEnum() {
  	// Place-holder for later extensibility.
  }


  // Field getter for ONE
  ExternalPublicEnum ExternalPublicEnum::getONE() {
  JNIEnv *env =getEnv();
  static jclass cls = getExternalPublicEnumClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "ONE", "Ltestpackage/ExternalPublicEnum;");
      if (NULL == fid) {
          std::cerr << "Class testpackage.ExternalPublicEnum has no field named ONE with signature Ltestpackage/ExternalPublicEnum;." << std::endl;
          static ExternalPublicEnum nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->GetStaticObjectField( cls, fid );
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   ExternalPublicEnum retObject(retVal,false);
   return retObject;
  }

  // Field getter for TWO
  ExternalPublicEnum ExternalPublicEnum::getTWO() {
  JNIEnv *env =getEnv();
  static jclass cls = getExternalPublicEnumClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "TWO", "Ltestpackage/ExternalPublicEnum;");
      if (NULL == fid) {
          std::cerr << "Class testpackage.ExternalPublicEnum has no field named TWO with signature Ltestpackage/ExternalPublicEnum;." << std::endl;
          static ExternalPublicEnum nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->GetStaticObjectField( cls, fid );
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   ExternalPublicEnum retObject(retVal,false);
   return retObject;
  }

  // Field getter for THREE
  ExternalPublicEnum ExternalPublicEnum::getTHREE() {
  JNIEnv *env =getEnv();
  static jclass cls = getExternalPublicEnumClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "THREE", "Ltestpackage/ExternalPublicEnum;");
      if (NULL == fid) {
          std::cerr << "Class testpackage.ExternalPublicEnum has no field named THREE with signature Ltestpackage/ExternalPublicEnum;." << std::endl;
          static ExternalPublicEnum nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->GetStaticObjectField( cls, fid );
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   ExternalPublicEnum retObject(retVal,false);
   return retObject;
  }

  jobjectArray ExternalPublicEnum::values() {
   JNIEnv *env =getEnv();
   static jclass cls = getExternalPublicEnumClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "values", "()[Ltestpackage/ExternalPublicEnum;");
       if (NULL == mid) {
           std::cerr << "Class testpackage.ExternalPublicEnum has no method named values with signature ()[Ltestpackage/ExternalPublicEnum;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ExternalPublicEnum::values jthis=",t);
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   return retVal;
  }

  ExternalPublicEnum ExternalPublicEnum::valueOf(jstring string_0) {
   JNIEnv *env =getEnv();
   static jclass cls = getExternalPublicEnumClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ltestpackage/ExternalPublicEnum;");
       if (NULL == mid) {
           std::cerr << "Class testpackage.ExternalPublicEnum has no method named valueOf with signature (Ljava/lang/String;)Ltestpackage/ExternalPublicEnum;." << std::endl;
           static ExternalPublicEnum nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ExternalPublicEnum::valueOf jthis=",t);
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   ExternalPublicEnum retObject(retVal,false);
   return retObject;
  }
  static jclass getNewExternalPublicEnumClass() {
      jclass clss = getEnv()->FindClass("testpackage/ExternalPublicEnum");
      if (NULL == clss) {
          std::cerr << " Can't find class testpackage/ExternalPublicEnum" << std::endl;
      }
      return clss;
  }
  
  static jclass ExternalPublicEnumClass = NULL;
  static inline jclass getExternalPublicEnumClass() {
      if (ExternalPublicEnumClass != NULL) {
          return ExternalPublicEnumClass;
      }
      ExternalPublicEnumClass = getNewExternalPublicEnumClass();
      return ExternalPublicEnumClass;
  }

// class_index = 5 clss=class testpackage.MyClient

  
  // get JNI handle for class testpackage.MyClient
  static inline jclass getMyClientClass();
  
  MyClient::MyClient(jobject _jthis, bool copy): ::test::java::lang::Object(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  MyClient::MyClient(const MyClient &objref): ::test::java::lang::Object((jobject)NULL,false) {
      jobject _jthis = objref.jthis;
      if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class MyClient _jthis=",_jthis);
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class MyClient jthis=",jthis);
      }
  }
  
  MyClient MyClient::cast(const ::test::java::lang::Object &objref) {
      JNIEnv *env =getEnv();
      static jclass cls = getMyClientClass(); 
      jclass objcls = env->GetObjectClass(objref.jthis);
      if(!env->IsAssignableFrom(objcls,cls)) {
          throw objcls;
      }
      MyClient retVal(objref.jthis,true);
      return retVal;
  }
  MyClient::MyClient() : ::test::java::lang::Object((jobject)NULL,false) {
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
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," MyClient::valueOf jthis=",t);
                  env->ExceptionDescribe();
              }
              throw t;
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

  MyClient::MyClient(jstring string_0,jint int_1) : ::test::java::lang::Object((jobject)NULL,false) {
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
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," MyClient::valueOf jthis=",t);
                   env->ExceptionDescribe();
               }
               throw t;
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

  MyClient::MyClient(const char * easyArg_0,jint easyArg_1) : ::test::java::lang::Object((jobject)NULL,false) {
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
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," MyClient::valueOf jthis=",t);
                  env->ExceptionDescribe();
              }
              throw t;
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


  jboolean MyClient::equals(const ::test::java::lang::Object & object_0) {
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
           DebugPrintJObject(__FILE__,__LINE__," MyClient::equals jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.MyClient has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," MyClient::equals jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," MyClient::toString jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.MyClient has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," MyClient::toString jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," MyClient::hashCode jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.MyClient has no method named hashCode with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," MyClient::hashCode jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," MyClient::getHost jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.MyClient has no method named getHost with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," MyClient::getHost jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
           DebugPrintJObject(__FILE__,__LINE__," MyClient::getPort jthis=",jthis);
           std::cerr << __FILE__ << ":" << __LINE__ <<  " Class testpackage.MyClient has no method named getPort with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               if(GetDebugJ4Cpp()) {
                   DebugPrintJObject(__FILE__,__LINE__," MyClient::getPort jthrowable t=",t);
                   env->ExceptionDescribe();
               }
   //            env->ExceptionClear();
               throw t;
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
      return MyClientClass;
  }

// class_index = 6 clss=class testpackage.Test$MyEnum

  
  // get JNI handle for class testpackage.Test.MyEnum
  static inline jclass getTestMyEnumClass();
  
  TestMyEnum::TestMyEnum(jobject _jthis, bool copy): ::test::java::lang::Enum(_jthis,copy) {
          // Place holder for future extensibility
  }
  
  TestMyEnum::TestMyEnum(const TestMyEnum &objref): ::test::java::lang::Enum((jobject)NULL,false) {
      jobject _jthis = objref.jthis;
      if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class TestMyEnum _jthis=",_jthis);
      if (_jthis != NULL) {
          jthis = getEnv()->NewGlobalRef(_jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class TestMyEnum jthis=",jthis);
      }
  }
  
  TestMyEnum TestMyEnum::cast(const ::test::java::lang::Object &objref) {
      JNIEnv *env =getEnv();
      static jclass cls = getTestMyEnumClass(); 
      jclass objcls = env->GetObjectClass(objref.jthis);
      if(!env->IsAssignableFrom(objcls,cls)) {
          throw objcls;
      }
      TestMyEnum retVal(objref.jthis,true);
      return retVal;
  }
  TestMyEnum::TestMyEnum() : ::test::java::lang::Enum((jobject)NULL,false) {
  JNIEnv *env =getEnv();
  static jclass cls = getTestMyEnumClass();
  if (cls != NULL) {
      static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
      if (NULL == mid) {
          std::cerr << "Class TestMyEnum has no method constructor signature ()V" << std::endl;
      } else {
          jthis = env->NewObject(cls, mid );
          jthrowable t = env->ExceptionOccurred();
          if(t != NULL) {
              if(GetDebugJ4Cpp()) {
                  DebugPrintJObject(__FILE__,__LINE__," TestMyEnum::getPort jthis=",t);
                  env->ExceptionDescribe();
              }
              throw t;
          }
          if(jthis == NULL) {
              std::cerr << "Call to create new TestMyEnum with signature ()V returned null." << std::endl;
              releaseEnv(env);
              return;
          }
          jobjectRefType ref = env->GetObjectRefType(jthis);
          if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new TestMyEnum jthis=",jthis);
          if(ref != JNIGlobalRefType) {
              jthis = env->NewGlobalRef(jthis);
          }
      }
  }
  releaseEnv(env);
  }


  // Destructor for testpackage.Test.MyEnum
  TestMyEnum::~TestMyEnum() {
  	// Place-holder for later extensibility.
  }


  // Field getter for A
  TestMyEnum TestMyEnum::getA() {
  JNIEnv *env =getEnv();
  static jclass cls = getTestMyEnumClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "A", "Ltestpackage/Test/MyEnum;");
      if (NULL == fid) {
          std::cerr << "Class testpackage.Test.MyEnum has no field named A with signature Ltestpackage/Test/MyEnum;." << std::endl;
          static TestMyEnum nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->GetStaticObjectField( cls, fid );
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   TestMyEnum retObject(retVal,false);
   return retObject;
  }

  // Field getter for B
  TestMyEnum TestMyEnum::getB() {
  JNIEnv *env =getEnv();
  static jclass cls = getTestMyEnumClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "B", "Ltestpackage/Test/MyEnum;");
      if (NULL == fid) {
          std::cerr << "Class testpackage.Test.MyEnum has no field named B with signature Ltestpackage/Test/MyEnum;." << std::endl;
          static TestMyEnum nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->GetStaticObjectField( cls, fid );
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   TestMyEnum retObject(retVal,false);
   return retObject;
  }

  // Field getter for C
  TestMyEnum TestMyEnum::getC() {
  JNIEnv *env =getEnv();
  static jclass cls = getTestMyEnumClass();
  jobject retVal=NULL;
  if (cls != NULL) {
      static jfieldID fid = env->GetStaticFieldID(cls, "C", "Ltestpackage/Test/MyEnum;");
      if (NULL == fid) {
          std::cerr << "Class testpackage.Test.MyEnum has no field named C with signature Ltestpackage/Test/MyEnum;." << std::endl;
          static TestMyEnum nullObject((jobject)NULL,false); return nullObject;
      } else {
          retVal= (jobject)  env->GetStaticObjectField( cls, fid );
      }
  }
  releaseEnv(env);
     
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   TestMyEnum retObject(retVal,false);
   return retObject;
  }

  jobjectArray TestMyEnum::values() {
   JNIEnv *env =getEnv();
   static jclass cls = getTestMyEnumClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "values", "()[Ltestpackage/Test/MyEnum;");
       if (NULL == mid) {
           std::cerr << "Class testpackage.Test.MyEnum has no method named values with signature ()[Ltestpackage/Test/MyEnum;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TestMyEnum::values jthis=",t);
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
   return retVal;
  }

  TestMyEnum TestMyEnum::valueOf(jstring string_0) {
   JNIEnv *env =getEnv();
   static jclass cls = getTestMyEnumClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ltestpackage/Test/MyEnum;");
       if (NULL == mid) {
           std::cerr << "Class testpackage.Test.MyEnum has no method named valueOf with signature (Ljava/lang/String;)Ltestpackage/Test/MyEnum;." << std::endl;
           static TestMyEnum nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," TestMyEnum::valueOf jthis=",t);
               if(GetDebugJ4Cpp()) env->ExceptionDescribe();
   //            env->ExceptionClear();
               throw t;
           }
       }
   }
   releaseEnv(env);
      
   jobjectRefType ref = env->GetObjectRefType(retVal);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);   TestMyEnum retObject(retVal,false);
   return retObject;
  }
  static jclass getNewTestMyEnumClass() {
      jclass clss = getEnv()->FindClass("testpackage/Test/MyEnum");
      if (NULL == clss) {
          std::cerr << " Can't find class testpackage/Test/MyEnum" << std::endl;
      }
      return clss;
  }
  
  static jclass TestMyEnumClass = NULL;
  static inline jclass getTestMyEnumClass() {
      if (TestMyEnumClass != NULL) {
          return TestMyEnumClass;
      }
      TestMyEnumClass = getNewTestMyEnumClass();
      return TestMyEnumClass;
  }
 } // end namespace testpackage


// class_index = 7 clss=interface java.util.List

  namespace java{
   namespace util{
   
   // get JNI handle for class java.util.List
   static inline jclass getListClass();
   
   List::List(jobject _jthis, bool copy): ::test::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   List::List(const List &objref): ::test::java::lang::Object((jobject)NULL,false) {
       jobject _jthis = objref.jthis;
       if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class List _jthis=",_jthis);
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class List jthis=",jthis);
       }
   }
   
   List List::cast(const ::test::java::lang::Object &objref) {
       JNIEnv *env =getEnv();
       static jclass cls = getListClass(); 
       jclass objcls = env->GetObjectClass(objref.jthis);
       if(!env->IsAssignableFrom(objcls,cls)) {
           throw objcls;
       }
       List retVal(objref.jthis,true);
       return retVal;
   }

   // Destructor for java.util.List
   List::~List() {
   	// Place-holder for later extensibility.
   }


   jboolean List::add(const ::test::java::lang::Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method add of java.util.List with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::add jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "add", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::add jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named add with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::add jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   void List::add(jint int_0,const ::test::java::lang::Object & object_1) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method add of java.util.List with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::add jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "add", "(ILjava/lang/Object;)V");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::add jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named add with signature (ILjava/lang/Object;)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,int_0,object_1.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::add jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    
   }

   jboolean List::remove(const ::test::java::lang::Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method remove of java.util.List with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::remove jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "remove", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::remove jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named remove with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::remove jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   ::test::java::lang::Object List::remove1(jint int_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method remove1 of java.util.List with jthis == NULL." << std::endl;
        static ::test::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::remove1 jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "remove", "(I)Ljava/lang/Object;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::remove1 jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named remove with signature (I)Ljava/lang/Object;." << std::endl;
            static ::test::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::remove1 jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
        
    jobjectRefType ref = env->GetObjectRefType(retVal);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);    ::test::java::lang::Object retObject(retVal,false);
    return retObject;
   }

   ::test::java::lang::Object List::get(jint int_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method get of java.util.List with jthis == NULL." << std::endl;
        static ::test::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::get jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "get", "(I)Ljava/lang/Object;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::get jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named get with signature (I)Ljava/lang/Object;." << std::endl;
            static ::test::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::get jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
        
    jobjectRefType ref = env->GetObjectRefType(retVal);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);    ::test::java::lang::Object retObject(retVal,false);
    return retObject;
   }

   jboolean List::equals(const ::test::java::lang::Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.util.List with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::equals jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::equals jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::equals jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint List::hashCode() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.util.List with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::hashCode jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::hashCode jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named hashCode with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::hashCode jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint List::indexOf(const ::test::java::lang::Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method indexOf of java.util.List with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::indexOf jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "indexOf", "(Ljava/lang/Object;)I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::indexOf jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named indexOf with signature (Ljava/lang/Object;)I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::indexOf jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   void List::clear() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clear of java.util.List with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::clear jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "clear", "()V");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::clear jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named clear with signature ()V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::clear jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    
   }

   jboolean List::isEmpty() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isEmpty of java.util.List with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::isEmpty jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "isEmpty", "()Z");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::isEmpty jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named isEmpty with signature ()Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::isEmpty jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint List::lastIndexOf(const ::test::java::lang::Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method lastIndexOf of java.util.List with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::lastIndexOf jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "lastIndexOf", "(Ljava/lang/Object;)I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::lastIndexOf jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named lastIndexOf with signature (Ljava/lang/Object;)I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::lastIndexOf jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jboolean List::contains(const ::test::java::lang::Object & object_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method contains of java.util.List with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::contains jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "contains", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::contains jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named contains with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::contains jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jint List::size() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method size of java.util.List with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::size jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "size", "()I");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::size jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named size with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::size jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   List List::subList(jint int_0,jint int_1) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method subList of java.util.List with jthis == NULL." << std::endl;
        static List nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::subList jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "subList", "(II)Ljava/util/List;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::subList jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named subList with signature (II)Ljava/util/List;." << std::endl;
            static List nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0,int_1 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::subList jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
        
    jobjectRefType ref = env->GetObjectRefType(retVal);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);    List retObject(retVal,false);
    return retObject;
   }

   jobjectArray List::toArray() {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toArray of java.util.List with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::toArray jthis=",jthis);
    jobjectArray retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "toArray", "()[Ljava/lang/Object;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::toArray jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named toArray with signature ()[Ljava/lang/Object;." << std::endl;
            return NULL;
        } else {
            retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::toArray jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   jobjectArray List::toArray(jobjectArray objectArray_0) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toArray of java.util.List with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::toArray jthis=",jthis);
    jobjectArray retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::toArray jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named toArray with signature ([Ljava/lang/Object;)[Ljava/lang/Object;." << std::endl;
            return NULL;
        } else {
            retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid ,objectArray_0 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::toArray jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
    return retVal;
   }

   ::test::java::lang::Object List::set(jint int_0,const ::test::java::lang::Object & object_1) {
    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method set of java.util.List with jthis == NULL." << std::endl;
        static ::test::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::set jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "set", "(ILjava/lang/Object;)Ljava/lang/Object;");
        if (NULL == mid) {
            DebugPrintJObject(__FILE__,__LINE__," List::set jthis=",jthis);
            std::cerr << __FILE__ << ":" << __LINE__ <<  " Class java.util.List has no method named set with signature (ILjava/lang/Object;)Ljava/lang/Object;." << std::endl;
            static ::test::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0,object_1.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                if(GetDebugJ4Cpp()) {
                    DebugPrintJObject(__FILE__,__LINE__," List::set jthrowable t=",t);
                    env->ExceptionDescribe();
                }
    //            env->ExceptionClear();
                throw t;
            }
        }
    }
    releaseEnv(env);
        
    jobjectRefType ref = env->GetObjectRefType(retVal);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"retVal=",retVal);    ::test::java::lang::Object retObject(retVal,false);
    return retObject;
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
       return ListClass;
   }
  } // end namespace util
 } // end namespace java



    static JavaVM *jvm = NULL; /* denotes a Java VM */
    
    static JNIEnv *getNewEnv() {
        
        JNIEnv *env; /* pointer to native method interface */
        JavaVM * jvmBuf[1];
        jsize nVMs;
        char *debugJ4CppEnv = NULL;
        char *classPathEnv = NULL;
        char *jvmOptionsEnv = NULL;
#if defined(_WIN32) || defined(_WIN64)
        errno_t errno_val;
        size_t requiredSize;
        errno_val =  getenv_s( &requiredSize, NULL, 0, "DEBUG_J4CPP");
        if(requiredSize > 0) {
            debugJ4CppEnv = (char *) malloc(requiredSize);
            errno_val =  getenv_s( &requiredSize, debugJ4CppEnv, requiredSize, "DEBUG_J4CPP");
        }
        errno_val =  getenv_s( &requiredSize, NULL, 0, "CLASSPATH");
        if(requiredSize > 0) {
            classPathEnv = (char *) malloc(requiredSize);
            errno_val =  getenv_s( &requiredSize, classPathEnv, requiredSize, "CLASSPATH");
        }
        errno_val =  getenv_s( &requiredSize, NULL, 0, "JVM_OPTIONS");
        if(requiredSize > 0) {
            jvmOptionsEnv = (char *) malloc(requiredSize);
            errno_val =  getenv_s( &requiredSize, jvmOptionsEnv, requiredSize, "JVM_OPTIONS");
        }
#else 
        debugJ4CppEnv = getenv("DEBUG_J4CPP");
        classPathEnv = getenv("CLASSPATH");
        jvmOptionsEnv = getenv("JVM_OPTIONS");
#endif
        debug_j4cpp = debug_j4cpp || (debugJ4CppEnv != NULL && debugJ4CppEnv[0] != 0);
        std::string str;
        str += "/home/shackle/java4cpp/examples/test/java/test/target/test-1.0-SNAPSHOT.jar";
        if (classPathEnv != NULL) {
            std::string classPathEnvStr(classPathEnv);
            if (debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
            str += ":";
            str += classPathEnvStr;
        }
        if (debug_j4cpp) std::cout << "str=" << str << std::endl;
#if defined(_WIN32) || defined(_WIN64)
        _putenv_s("CLASSPATH", str.c_str());
#else
        setenv("CLASSPATH", str.c_str(), 1);
#endif
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
            jvm = jvmBuf[0];
            jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
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
#if defined(_WIN32) || defined(_WIN64)
        if(debugJ4CppEnv != NULL) {
            free(debugJ4CppEnv);
            debugJ4CppEnv = NULL;
        }
        if(classPathEnv != NULL) {
            free(classPathEnv);
            classPathEnv = NULL;
        }
        if(jvmOptionsEnv != NULL) {
            free(jvmOptionsEnv);
            jvmOptionsEnv = NULL;
        }
#endif
        return env;
    }

    static JNIEnv *env = NULL;

    JNIEnv *getEnv() {
        if (env != NULL && jvm != NULL) {
            JNIEnv *env2=env;
            jint attach_ret = jvm->AttachCurrentThread((void **)&env2,NULL);
            if(attach_ret != JNI_OK) {
                std::cerr << "JNI AttachCurrentThread failed returning " << attach_ret << std::endl;
                return NULL;
            }
            return env2;
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

    static jclass getNewClassClass() {
        jclass clss = getEnv()->FindClass("java/lang/Class");
        if (NULL == clss) {
            std::cerr << " Can't find class java/lang/Class" << std::endl;
        }
        return clss;
    }

    static jclass ClassClass = NULL;

    jclass getClassClass() {
        if (ClassClass != NULL) {
            return ClassClass;
        }
        ClassClass = getNewClassClass();
        return ClassClass;
    }
    
    static jclass getNewArraysClass() {
        jclass clss = getEnv()->FindClass("java/util/Arrays");
        if (NULL == clss) {
            std::cerr << " Can't find class java/util/Arrays" << std::endl;
        }
        return clss;
    }

    static jclass ArraysClass = NULL;

    jclass getArraysClass() {
        if (ArraysClass != NULL) {
            return ArraysClass;
        }
        ArraysClass = getNewArraysClass();
        return ArraysClass;
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
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJBooleanArray(const char *prefix, jbooleanArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([Z)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJByteArray(const char *prefix, jbyteArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([B)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJCharArray(const char *prefix, jcharArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([C)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJShortArray(const char *prefix, jshortArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([S)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJIntArray(const char *prefix, jintArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([I)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJLongArray(const char *prefix, jlongArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([J)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJFloatArray(const char *prefix, jfloatArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([F)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJDoubleArray(const char *prefix, jdoubleArray jobj) {
        if(NULL == jobj) {
            std::cout << prefix << "NULL" << std::endl;
            return;
        }
        JNIEnv *env = getEnv();
        jclass clss = getArraysClass();
        jmethodID midToString = env->GetStaticMethodID(clss, "toString", "([D)Ljava/lang/String;");
        if(NULL == midToString) {
            std::cout << prefix << "can not find toString method" << std::endl;
            return;
        }
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        if(NULL == jobjstr) {
            std::cout << prefix << "toString() returned NULL" << std::endl;
            return;
        }
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void PrintJThrowable(const char *prefix, jthrowable jobj) {
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cerr << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
        env->ExceptionDescribe();
        env->ExceptionClear();
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
    
    void PrintObject(const char *prefix, const ::test::java::lang::Object &objref) {
        PrintJObject(prefix,objref.jthis);
    }
    
    const char *GetStringUTFChars(jstring js, jboolean *iscopy) {
        jboolean iscopy2;
        const char *ret = getEnv()->GetStringUTFChars(js,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    
    void ReleaseStringUTFChars(jstring js, const char *utf) {
        getEnv()->ReleaseStringUTFChars(js,utf);
    }
    
    jboolean *GetBooleanArrayElements(jbooleanArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jboolean *ret = getEnv()->GetBooleanArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
    }
    
    jbyte *GetByteArrayElements(jbyteArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jbyte *ret = getEnv()->GetByteArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    
    jchar *GetCharArrayElements(jcharArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jchar *ret = getEnv()->GetCharArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jshort *GetShortArrayElements(jshortArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jshort *ret = getEnv()->GetShortArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jint *GetIntArrayElements(jintArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jint *ret = getEnv()->GetIntArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jlong *GetLongArrayElements(jlongArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jlong *ret = getEnv()->GetLongArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jfloat *GetFloatArrayElements(jfloatArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jfloat *ret = getEnv()->GetFloatArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    jdouble *GetDoubleArrayElements(jdoubleArray  jarray,jboolean *iscopy) {
        jboolean iscopy2;
        jdouble *ret = getEnv()->GetDoubleArrayElements(jarray,&iscopy2);
        if(NULL != iscopy) {
            *iscopy = iscopy2;
        }
        return ret;
    }
    
    void ReleaseBooleanArrayElements(jbooleanArray jarray, jboolean *nativeArray, jint mode) {
        getEnv()->ReleaseBooleanArrayElements(jarray,nativeArray,mode);
    }
    
    void ReleaseByteArrayElements(jbyteArray jarray, jbyte *nativeArray, jint mode) {
        getEnv()->ReleaseByteArrayElements(jarray,nativeArray,mode);
    }
    
    void ReleaseCharArrayElements(jcharArray jarray, jchar *nativeArray, jint mode) {
        getEnv()->ReleaseCharArrayElements(jarray,nativeArray,mode);
    }
    
    void ReleaseShortArrayElements(jshortArray jarray, jshort *nativeArray, jint mode) {
        getEnv()->ReleaseShortArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseIntArrayElements(jintArray jarray, jint *nativeArray, jint mode) {
        getEnv()->ReleaseIntArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseLongArrayElements(jlongArray jarray, jlong *nativeArray, jint mode) {
        getEnv()->ReleaseLongArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseFloatArrayElements(jfloatArray jarray, jfloat *nativeArray, jint mode) {
        getEnv()->ReleaseFloatArrayElements(jarray,nativeArray,mode);
    }
    void ReleaseDoubleArrayElements(jdoubleArray jarray, jdouble *nativeArray, jint mode) {
        getEnv()->ReleaseDoubleArrayElements(jarray,nativeArray,mode);
    }
    
    
    void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace test
}

