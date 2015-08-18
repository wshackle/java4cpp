
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.CRCLSocketExample
   static inline jclass getCRCLSocketExampleClass();
   
   CRCLSocketExample::CRCLSocketExample(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CRCLSocketExample::CRCLSocketExample(const CRCLSocketExample &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CRCLSocketExample::CRCLSocketExample() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCRCLSocketExampleClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CRCLSocketExample has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CRCLSocketExample::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CRCLSocketExample with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLSocketExample jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.CRCLSocketExample
   CRCLSocketExample::~CRCLSocketExample() {
   	// Place-holder for later extensibility.
   }

   void CRCLSocketExample::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getCRCLSocketExampleClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.CRCLSocketExample has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLSocketExample::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLSocketExample::main(int argc, const char **argv) {
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
   static jclass getNewCRCLSocketExampleClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/CRCLSocketExample");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/CRCLSocketExample" << std::endl;
       }
       return clss;
   }
   
   static jclass CRCLSocketExampleClass = NULL;
   static inline jclass getCRCLSocketExampleClass() {
       if (CRCLSocketExampleClass != NULL) {
           return CRCLSocketExampleClass;
       }
       CRCLSocketExampleClass = getNewCRCLSocketExampleClass();
   }
   
   // get JNI handle for class crcl.utils.PendantClientInner
   static inline jclass getPendantClientInnerClass();
   
   PendantClientInner::PendantClientInner(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PendantClientInner::PendantClientInner(const PendantClientInner &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PendantClientInner::PendantClientInner() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientInnerClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class PendantClientInner has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PendantClientInner with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PendantClientInner jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   PendantClientInner::PendantClientInner(PendantClientOuter  &pendantClientOuter_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPendantClientInnerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lcrcl/utils/PendantClientOuter;)V");
        if (NULL == mid) {
            std::cerr << "Class PendantClientInner has no method constructor signature (Lcrcl/utils/PendantClientOuter;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pendantClientOuter_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::main jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PendantClientInner with signature (Lcrcl/utils/PendantClientOuter;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PendantClientInner jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.PendantClientInner
   PendantClientInner::~PendantClientInner() {
   	// Place-holder for later extensibility.
   }

   void PendantClientInner::abort() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method abort of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::abort jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "abort", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named abort with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::abort jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::disconnect() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method disconnect of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::disconnect jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "disconnect", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named disconnect with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::disconnect jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClientInner::isConnected() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isConnected of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isConnected jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isConnected", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named isConnected with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isConnected jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::crcl::base::CRCLStatusType PendantClientInner::getStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getStatus of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getStatus", "()Lcrcl/base/CRCLStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getStatus with signature ()Lcrcl/base/CRCLStatusType;." << std::endl;
           ::crclj::crcl::base::CRCLStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getStatus jthis=",t);
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
   void PendantClientInner::setProgramSchema(jobjectArray fileArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setProgramSchema of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setProgramSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setProgramSchema", "([Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setProgramSchema with signature ([Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setProgramSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::setCmdSchema(jobjectArray fileArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCmdSchema of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setCmdSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCmdSchema", "([Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setCmdSchema with signature ([Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setCmdSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::setStatSchema(jobjectArray fileArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatSchema of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setStatSchema jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatSchema", "([Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setStatSchema with signature ([Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,fileArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setStatSchema jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::util::Optional PendantClientInner::getJointStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,::crclj::java::math::BigInteger  &bigInteger_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientInnerClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getJointStatus", "(Lcrcl/base/CRCLStatusType;Ljava/math/BigInteger;)Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getJointStatus with signature (Lcrcl/base/CRCLStatusType;Ljava/math/BigInteger;)Ljava/util/Optional;." << std::endl;
           ::crclj::java::util::Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,cRCLStatusType_0.jthis,bigInteger_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJointStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::Optional retObject(retVal,false);
    return retObject;
   }
   void PendantClientInner::readStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method readStatus of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::readStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "readStatus", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named readStatus with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::readStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::math::BigDecimal PendantClientInner::getJointPosition(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointPosition of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJointPosition jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointPosition", "(Ljava/math/BigInteger;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getJointPosition with signature (Ljava/math/BigInteger;)Ljava/math/BigDecimal;." << std::endl;
           ::crclj::java::math::BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJointPosition jthis=",t);
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
   void PendantClientInner::waitForPause() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method waitForPause of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::waitForPause jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "waitForPause", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named waitForPause with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::waitForPause jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClientInner::runProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method runProgram of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::runProgram jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "runProgram", "(Lcrcl/base/CRCLProgramType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named runProgram with signature (Lcrcl/base/CRCLProgramType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,cRCLProgramType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::runProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClientInner::runTest() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method runTest of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::runTest jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "runTest", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named runTest with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::runTest jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClientInner::setCmdId(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCmdId of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setCmdId jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCmdId", "(Ljava/math/BigInteger;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setCmdId with signature (Ljava/math/BigInteger;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setCmdId jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::setJogInterval(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJogInterval of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setJogInterval jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJogInterval", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setJogInterval with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setJogInterval jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::openXmlProgramFile(::crclj::java::io::File  &file_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method openXmlProgramFile of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::openXmlProgramFile jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "openXmlProgramFile", "(Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named openXmlProgramFile with signature (Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::openXmlProgramFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::saveXmlProgramFile(::crclj::java::io::File  &file_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method saveXmlProgramFile of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::saveXmlProgramFile jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "saveXmlProgramFile", "(Ljava/io/File;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named saveXmlProgramFile with signature (Ljava/io/File;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,file_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::saveXmlProgramFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PendantClientInner::getJogIncrement() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJogIncrement of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJogIncrement jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJogIncrement", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getJogIncrement with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJogIncrement jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClientInner::setProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setProgram of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setProgram jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setProgram", "(Lcrcl/base/CRCLProgramType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setProgram with signature (Lcrcl/base/CRCLProgramType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLProgramType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClientInner::incAndSendCommand(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method incAndSendCommand of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::incAndSendCommand jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "incAndSendCommand", "(Lcrcl/base/CRCLCommandType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named incAndSendCommand with signature (Lcrcl/base/CRCLCommandType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,cRCLCommandType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::incAndSendCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   CRCLSocket PendantClientInner::getCRCLSocket() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCRCLSocket of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       CRCLSocket nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCRCLSocket jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCRCLSocket", "()Lcrcl/utils/CRCLSocket;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getCRCLSocket with signature ()Lcrcl/utils/CRCLSocket;." << std::endl;
           CRCLSocket nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCRCLSocket jthis=",t);
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
   jint PendantClientInner::getJogInterval() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJogInterval of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJogInterval jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJogInterval", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getJogInterval with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJogInterval jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble PendantClientInner::getXyzJogIncrement() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getXyzJogIncrement of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getXyzJogIncrement jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getXyzJogIncrement", "()D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getXyzJogIncrement with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getXyzJogIncrement jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   CRCLSocket PendantClientInner::getTempCRCLSocket() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTempCRCLSocket of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       CRCLSocket nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getTempCRCLSocket jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTempCRCLSocket", "()Lcrcl/utils/CRCLSocket;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getTempCRCLSocket with signature ()Lcrcl/utils/CRCLSocket;." << std::endl;
           CRCLSocket nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getTempCRCLSocket jthis=",t);
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
   jobjectArray PendantClientInner::getProgramSchemaFiles() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getProgramSchemaFiles of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getProgramSchemaFiles jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getProgramSchemaFiles", "()[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getProgramSchemaFiles with signature ()[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getProgramSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::util::function::Predicate PendantClientInner::getCheckProgramValidPredicate() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCheckProgramValidPredicate of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::java::util::function::Predicate nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCheckProgramValidPredicate jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCheckProgramValidPredicate", "()Ljava/util/function/Predicate;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getCheckProgramValidPredicate with signature ()Ljava/util/function/Predicate;." << std::endl;
           ::crclj::java::util::function::Predicate nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCheckProgramValidPredicate jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::function::Predicate retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::util::function::Predicate PendantClientInner::getCheckCommandValidPredicate() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCheckCommandValidPredicate of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::java::util::function::Predicate nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCheckCommandValidPredicate jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCheckCommandValidPredicate", "()Ljava/util/function/Predicate;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getCheckCommandValidPredicate with signature ()Ljava/util/function/Predicate;." << std::endl;
           ::crclj::java::util::function::Predicate nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCheckCommandValidPredicate jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::function::Predicate retObject(retVal,false);
    return retObject;
   }
   jint PendantClientInner::getPoll_ms() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPoll_ms of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getPoll_ms jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPoll_ms", "()I");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getPoll_ms with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getPoll_ms jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClientInner::setPoll_ms(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setPoll_ms of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setPoll_ms jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setPoll_ms", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setPoll_ms with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setPoll_ms jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::setJogIncrement(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJogIncrement of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setJogIncrement jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJogIncrement", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setJogIncrement with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setJogIncrement jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::setXyzJogIncrement(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setXyzJogIncrement of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setXyzJogIncrement jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setXyzJogIncrement", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setXyzJogIncrement with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setXyzJogIncrement jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::startRunTestThread() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method startRunTestThread of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::startRunTestThread jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "startRunTestThread", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named startRunTestThread with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::startRunTestThread jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::startRunProgramThread() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method startRunProgramThread of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::startRunProgramThread jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "startRunProgramThread", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named startRunProgramThread with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::startRunProgramThread jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClientInner::isPaused() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isPaused of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isPaused jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isPaused", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named isPaused with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isPaused jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClientInner::isRunningProgram() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isRunningProgram of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isRunningProgram jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isRunningProgram", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named isRunningProgram with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isRunningProgram jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClientInner::unpause() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method unpause of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::unpause jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "unpause", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named unpause with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::unpause jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::CRCLProgramType PendantClientInner::getProgram() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getProgram of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getProgram jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getProgram", "()Lcrcl/base/CRCLProgramType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getProgram with signature ()Lcrcl/base/CRCLProgramType;." << std::endl;
           ::crclj::crcl::base::CRCLProgramType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getProgram jthis=",t);
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
   void PendantClientInner::savePoseListToCsvFile(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method savePoseListToCsvFile of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::savePoseListToCsvFile jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "savePoseListToCsvFile", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named savePoseListToCsvFile with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::savePoseListToCsvFile jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::savePoseListToCsvFile(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method savePoseListToCsvFile of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::savePoseListToCsvFile jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    savePoseListToCsvFile(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   ::crclj::java::util::List PendantClientInner::getPoseList() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPoseList of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getPoseList jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPoseList", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getPoseList with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getPoseList jthis=",t);
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
   void PendantClientInner::startStatusReaderThread() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method startStatusReaderThread of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::startStatusReaderThread jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "startStatusReaderThread", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named startStatusReaderThread with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::startStatusReaderThread jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::stopStatusReaderThread() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stopStatusReaderThread of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::stopStatusReaderThread jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stopStatusReaderThread", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named stopStatusReaderThread with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::stopStatusReaderThread jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::closeTestProgramThread() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method closeTestProgramThread of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::closeTestProgramThread jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "closeTestProgramThread", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named closeTestProgramThread with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::closeTestProgramThread jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClientInner::requestStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method requestStatus of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::requestStatus jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "requestStatus", "()Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named requestStatus with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::requestStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClientInner::checkProgramValid(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkProgramValid of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::checkProgramValid jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkProgramValid", "(Lcrcl/base/CRCLProgramType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named checkProgramValid with signature (Lcrcl/base/CRCLProgramType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,cRCLProgramType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::checkProgramValid jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClientInner::checkCommandValid(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkCommandValid of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::checkCommandValid jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkCommandValid", "(Lcrcl/base/CRCLCommandType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named checkCommandValid with signature (Lcrcl/base/CRCLCommandType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,cRCLCommandType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::checkCommandValid jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray PendantClientInner::getCmdSchemaFiles() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCmdSchemaFiles of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCmdSchemaFiles jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCmdSchemaFiles", "()[Ljava/io/File;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getCmdSchemaFiles with signature ()[Ljava/io/File;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCmdSchemaFiles jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClientInner::sendCommand(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method sendCommand of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::sendCommand jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "sendCommand", "(Lcrcl/base/CRCLCommandType;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named sendCommand with signature (Lcrcl/base/CRCLCommandType;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,cRCLCommandType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::sendCommand jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PendantClientInner::waitForDone(::crclj::java::math::BigInteger  &bigInteger_0,jlong long_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method waitForDone of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::waitForDone jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "waitForDone", "(Ljava/math/BigInteger;J)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named waitForDone with signature (Ljava/math/BigInteger;J)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,bigInteger_0.jthis,long_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::waitForDone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong PendantClientInner::getWaitForDoneDelay() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getWaitForDoneDelay of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getWaitForDoneDelay jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getWaitForDoneDelay", "()J");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getWaitForDoneDelay with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getWaitForDoneDelay jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClientInner::setWaitForDoneDelay(jlong long_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setWaitForDoneDelay of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setWaitForDoneDelay jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setWaitForDoneDelay", "(J)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setWaitForDoneDelay with signature (J)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setWaitForDoneDelay jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::util::stream::Stream PendantClientInner::getJointValues(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,::crclj::java::util::Collection  &collection_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientInnerClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getJointValues", "(Lcrcl/base/CRCLStatusType;Ljava/util/Collection;)Ljava/util/stream/Stream;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getJointValues with signature (Lcrcl/base/CRCLStatusType;Ljava/util/Collection;)Ljava/util/stream/Stream;." << std::endl;
           ::crclj::java::util::stream::Stream nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,cRCLStatusType_0.jthis,collection_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJointValues jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::stream::Stream retObject(retVal,false);
    return retObject;
   }
   jstring PendantClientInner::getJointString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,::crclj::java::util::function::Function  &function_1,::crclj::java::util::Collection  &collection_2) {

   JNIEnv *env =getEnv();
   static jclass cls = getPendantClientInnerClass();
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getJointString", "(Lcrcl/base/CRCLStatusType;Ljava/util/function/Function;Ljava/util/Collection;)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getJointString with signature (Lcrcl/base/CRCLStatusType;Ljava/util/function/Function;Ljava/util/Collection;)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallStaticObjectMethod( cls, mid ,cRCLStatusType_0.jthis,function_1.jthis,collection_2.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getJointString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PendantClientInner::pause() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method pause of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::pause jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "pause", "()V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named pause with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::pause jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PendantClientInner::isDone(::crclj::java::math::BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isDone of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isDone jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isDone", "(Ljava/math/BigInteger;)Z");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named isDone with signature (Ljava/math/BigInteger;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::isDone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::math::BigInteger PendantClientInner::getCmdId() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCmdId of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCmdId jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCmdId", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getCmdId with signature ()Ljava/math/BigInteger;." << std::endl;
           ::crclj::java::math::BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getCmdId jthis=",t);
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
   XpathUtils PendantClientInner::getXpu() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getXpu of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       XpathUtils nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getXpu jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getXpu", "()Lcrcl/utils/XpathUtils;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getXpu with signature ()Lcrcl/utils/XpathUtils;." << std::endl;
           XpathUtils nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getXpu jthis=",t);
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
   void PendantClientInner::setStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setStatus of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setStatus", "(Lcrcl/base/CRCLStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setStatus with signature (Lcrcl/base/CRCLStatusType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,cRCLStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::PoseToleranceType PendantClientInner::getExpectedEndPoseTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getExpectedEndPoseTolerance of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getExpectedEndPoseTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getExpectedEndPoseTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getExpectedEndPoseTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getExpectedEndPoseTolerance jthis=",t);
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
   void PendantClientInner::setExpectedEndPoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExpectedEndPoseTolerance of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setExpectedEndPoseTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExpectedEndPoseTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setExpectedEndPoseTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setExpectedEndPoseTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::crcl::base::PoseToleranceType PendantClientInner::getExpectedIntermediatePoseTolerance() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getExpectedIntermediatePoseTolerance of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getExpectedIntermediatePoseTolerance jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getExpectedIntermediatePoseTolerance", "()Lcrcl/base/PoseToleranceType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named getExpectedIntermediatePoseTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
           ::crclj::crcl::base::PoseToleranceType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::getExpectedIntermediatePoseTolerance jthis=",t);
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
   void PendantClientInner::setExpectedIntermediatePoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExpectedIntermediatePoseTolerance of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setExpectedIntermediatePoseTolerance jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExpectedIntermediatePoseTolerance", "(Lcrcl/base/PoseToleranceType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named setExpectedIntermediatePoseTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseToleranceType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::setExpectedIntermediatePoseTolerance jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::connect(jstring string_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method connect of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::connect jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "connect", "(Ljava/lang/String;I)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.PendantClientInner has no method named connect with signature (Ljava/lang/String;I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::connect jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PendantClientInner::connect(const char * easyArg_0,jint easyArg_1) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method connect of crcl.utils.PendantClientInner with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PendantClientInner::connect jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    jint int_1= easyArg_1;
    connect(string_0,int_1);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   static jclass getNewPendantClientInnerClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/PendantClientInner");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/PendantClientInner" << std::endl;
       }
       return clss;
   }
   
   static jclass PendantClientInnerClass = NULL;
   static inline jclass getPendantClientInnerClass() {
       if (PendantClientInnerClass != NULL) {
           return PendantClientInnerClass;
       }
       PendantClientInnerClass = getNewPendantClientInnerClass();
   }
  } // end namespace utils
 } // end namespace crcl

  namespace java{
   namespace lang{
   
   // get JNI handle for class java.lang.Number
   static inline jclass getNumberClass();
   
   Number::Number(jobject _jthis, bool copy): Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Number::Number(const Number &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   Number::Number() : Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getNumberClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Number has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Number::connect jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Number with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Number jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.lang.Number
   Number::~Number() {
   	// Place-holder for later extensibility.
   }

   jbyte Number::byteValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method byteValue of java.lang.Number with jthis == NULL." << std::endl;
       return (jbyte) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Number::byteValue jthis=",jthis);
   jbyte retVal= (jbyte) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "byteValue", "()B");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Number has no method named byteValue with signature ()B." << std::endl;
           return (jbyte) -1;
       } else {
           retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Number::byteValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jshort Number::shortValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method shortValue of java.lang.Number with jthis == NULL." << std::endl;
       return (jshort) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Number::shortValue jthis=",jthis);
   jshort retVal=(jshort) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "shortValue", "()S");
       if (NULL == mid) {
           std::cerr << "Class java.lang.Number has no method named shortValue with signature ()S." << std::endl;
           return (jshort) -1;
       } else {
           retVal= (jshort)  env->CallShortMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Number::shortValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewNumberClass() {
       jclass clss = getEnv()->FindClass("java/lang/Number");
       if (NULL == clss) {
           std::cerr << " Can't find class java/lang/Number" << std::endl;
       }
       return clss;
   }
   
   static jclass NumberClass = NULL;
   static inline jclass getNumberClass() {
       if (NumberClass != NULL) {
           return NumberClass;
       }
       NumberClass = getNewNumberClass();
   }
  } // end namespace lang

   namespace math{
   
   // get JNI handle for class java.math.BigDecimal
   static inline jclass getBigDecimalClass();
   
   BigDecimal::BigDecimal(jobject _jthis, bool copy): ::crclj::java::lang::Number(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   BigDecimal::BigDecimal(const BigDecimal &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   BigDecimal::BigDecimal() : ::crclj::java::lang::Number((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class BigDecimal has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigDecimal with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   BigDecimal::BigDecimal(jdouble double_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(D)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature (D)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature (D)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(jcharArray charArray_0,jint int_1,jint int_2) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "([CII)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature ([CII)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,charArray_0,int_1,int_2);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature ([CII)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(jchar * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   jcharArray charArray_0= env->NewCharArray(easyArg_0_length);
   env->SetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
   jint int_1= easyArg_1;
   jint int_2= easyArg_2;
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "([CII)V");
       if (NULL == mid) {
           std::cerr << "Class BigDecimal has no method constructor signature ([CII)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,charArray_0,int_1,int_2);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigDecimal with signature ([CII)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   env->GetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(charArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(charArray_0);
   }
   
   releaseEnv(env);
   }
   BigDecimal::BigDecimal(jcharArray charArray_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "([C)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature ([C)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,charArray_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature ([C)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(jchar * easyArg_0,jsize easyArg_0_length) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   jcharArray charArray_0= env->NewCharArray(easyArg_0_length);
   env->SetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "([C)V");
       if (NULL == mid) {
           std::cerr << "Class BigDecimal has no method constructor signature ([C)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,charArray_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigDecimal with signature ([C)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   env->GetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(charArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(charArray_0);
   }
   
   releaseEnv(env);
   }
   BigDecimal::BigDecimal(jint int_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(I)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature (I)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,int_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature (I)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(jlong long_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(J)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature (J)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,long_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature (J)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(BigInteger  &bigInteger_0,jint int_1) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/math/BigInteger;I)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature (Ljava/math/BigInteger;I)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,bigInteger_0.jthis,int_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature (Ljava/math/BigInteger;I)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(BigInteger  &bigInteger_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/math/BigInteger;)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature (Ljava/math/BigInteger;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,bigInteger_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature (Ljava/math/BigInteger;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(jstring string_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigDecimalClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class BigDecimal has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigDecimal with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigDecimal::BigDecimal(const char * easyArg_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class BigDecimal has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigDecimal with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigDecimal jthis=",jthis);
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

   // Destructor for java.math.BigDecimal
   BigDecimal::~BigDecimal() {
   	// Place-holder for later extensibility.
   }

   jint BigDecimal::precision() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method precision of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::precision jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "precision", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named precision with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::precision jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigDecimal BigDecimal::divideToIntegralValue(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divideToIntegralValue of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divideToIntegralValue jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divideToIntegralValue", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named divideToIntegralValue with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divideToIntegralValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   jobjectArray BigDecimal::divideAndRemainder(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divideAndRemainder of java.math.BigDecimal with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divideAndRemainder jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divideAndRemainder", "(Ljava/math/BigDecimal;)[Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named divideAndRemainder with signature (Ljava/math/BigDecimal;)[Ljava/math/BigDecimal;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divideAndRemainder jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigDecimal BigDecimal::plus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method plus of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::plus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "plus", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named plus with signature ()Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::plus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigInteger BigDecimal::unscaledValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method unscaledValue of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::unscaledValue jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "unscaledValue", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named unscaledValue with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::unscaledValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigInteger retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::movePointLeft(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method movePointLeft of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::movePointLeft jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "movePointLeft", "(I)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named movePointLeft with signature (I)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::movePointLeft jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::movePointRight(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method movePointRight of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::movePointRight jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "movePointRight", "(I)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named movePointRight with signature (I)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::movePointRight jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::scaleByPowerOfTen(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method scaleByPowerOfTen of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::scaleByPowerOfTen jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "scaleByPowerOfTen", "(I)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named scaleByPowerOfTen with signature (I)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::scaleByPowerOfTen jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::stripTrailingZeros() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stripTrailingZeros of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::stripTrailingZeros jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stripTrailingZeros", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named stripTrailingZeros with signature ()Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::stripTrailingZeros jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   jstring BigDecimal::toEngineeringString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toEngineeringString of java.math.BigDecimal with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toEngineeringString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toEngineeringString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named toEngineeringString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toEngineeringString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring BigDecimal::toPlainString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toPlainString of java.math.BigDecimal with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toPlainString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toPlainString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named toPlainString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toPlainString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigDecimal::toBigInteger() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toBigInteger of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toBigInteger jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toBigInteger", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named toBigInteger with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toBigInteger jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigInteger retObject(retVal,false);
    return retObject;
   }
   BigInteger BigDecimal::toBigIntegerExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toBigIntegerExact of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toBigIntegerExact jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toBigIntegerExact", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named toBigIntegerExact with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toBigIntegerExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigInteger retObject(retVal,false);
    return retObject;
   }
   jlong BigDecimal::longValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method longValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::longValueExact jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "longValueExact", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named longValueExact with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::longValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigDecimal::intValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method intValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::intValueExact jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "intValueExact", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named intValueExact with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::intValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jshort BigDecimal::shortValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method shortValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jshort) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValueExact jthis=",jthis);
   jshort retVal=(jshort) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "shortValueExact", "()S");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named shortValueExact with signature ()S." << std::endl;
           return (jshort) -1;
       } else {
           retVal= (jshort)  env->CallShortMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::shortValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jbyte BigDecimal::byteValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method byteValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jbyte) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::byteValueExact jthis=",jthis);
   jbyte retVal= (jbyte) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "byteValueExact", "()B");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named byteValueExact with signature ()B." << std::endl;
           return (jbyte) -1;
       } else {
           retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::byteValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigDecimal BigDecimal::subtract(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method subtract of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::subtract jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "subtract", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named subtract with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::subtract jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::multiply(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named multiply with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::setScale(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setScale of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::setScale jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setScale", "(I)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named setScale with signature (I)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::setScale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::setScale(jint int_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setScale of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::setScale jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setScale", "(II)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named setScale with signature (II)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::setScale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::negate() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method negate of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::negate jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "negate", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named negate with signature ()Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::negate jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::add(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method add of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::add jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "add", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named add with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::add jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   jboolean BigDecimal::equals(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.math.BigDecimal with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring BigDecimal::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.math.BigDecimal with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigDecimal::hashCode() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::hashCode jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named hashCode with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::hashCode jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigDecimal BigDecimal::abs() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method abs of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::abs jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "abs", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named abs with signature ()Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::abs jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::pow(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method pow of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::pow jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "pow", "(I)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named pow with signature (I)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::pow jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::min(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method min of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::min jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "min", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named min with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::min jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::max(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method max of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::max jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "max", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named max with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::max jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   jint BigDecimal::compareTo(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method compareTo of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::compareTo jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/math/BigDecimal;)I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named compareTo with signature (Ljava/math/BigDecimal;)I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::compareTo jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigDecimal::intValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method intValue of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::intValue jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "intValue", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named intValue with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::intValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong BigDecimal::longValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method longValue of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::longValue jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "longValue", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named longValue with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::longValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jfloat BigDecimal::floatValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method floatValue of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jfloat) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::floatValue jthis=",jthis);
   jfloat retVal= (jfloat) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "floatValue", "()F");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named floatValue with signature ()F." << std::endl;
           return (jfloat) -1.0;
       } else {
           retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::floatValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble BigDecimal::doubleValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method doubleValue of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::doubleValue jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "doubleValue", "()D");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named doubleValue with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::doubleValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigDecimal BigDecimal::valueOf(jlong long_0,jint int_1) {

   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(JI)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named valueOf with signature (JI)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,long_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::valueOf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::valueOf(jlong long_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(J)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named valueOf with signature (J)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::valueOf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::valueOf(jdouble double_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getBigDecimalClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(D)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named valueOf with signature (D)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::valueOf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   jint BigDecimal::signum() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method signum of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::signum jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "signum", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named signum with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::signum jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigDecimal BigDecimal::divide(BigDecimal  &bigDecimal_0,jint int_1,jint int_2) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divide of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divide jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigDecimal;II)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named divide with signature (Ljava/math/BigDecimal;II)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis,int_1,int_2 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divide jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::divide(BigDecimal  &bigDecimal_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divide of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divide jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigDecimal;I)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named divide with signature (Ljava/math/BigDecimal;I)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divide jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::divide(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divide of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divide jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named divide with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::divide jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::remainder(BigDecimal  &bigDecimal_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method remainder of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::remainder jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "remainder", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named remainder with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigDecimal_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::remainder jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   BigDecimal BigDecimal::ulp() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method ulp of java.math.BigDecimal with jthis == NULL." << std::endl;
       BigDecimal nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::ulp jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "ulp", "()Ljava/math/BigDecimal;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named ulp with signature ()Ljava/math/BigDecimal;." << std::endl;
           BigDecimal nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::ulp jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigDecimal retObject(retVal,false);
    return retObject;
   }
   jint BigDecimal::scale() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method scale of java.math.BigDecimal with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigDecimal::scale jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "scale", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigDecimal has no method named scale with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigDecimal::scale jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewBigDecimalClass() {
       jclass clss = getEnv()->FindClass("java/math/BigDecimal");
       if (NULL == clss) {
           std::cerr << " Can't find class java/math/BigDecimal" << std::endl;
       }
       return clss;
   }
   
   static jclass BigDecimalClass = NULL;
   static inline jclass getBigDecimalClass() {
       if (BigDecimalClass != NULL) {
           return BigDecimalClass;
       }
       BigDecimalClass = getNewBigDecimalClass();
   }
  } // end namespace math

   namespace util{
   
   // get JNI handle for class java.util.List
   static inline jclass getListClass();
   
   List::List(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   List::List(const List &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   List::List() : ::crclj::java::lang::Object((jobject)NULL,false) {
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
               DebugPrintJObject(__FILE__,__LINE__," List::scale jthis=",t);
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

   void List::replaceAll(function::UnaryOperator  &unaryOperator_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method replaceAll of java.util.List with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," List::replaceAll jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "replaceAll", "(Ljava/util/function/UnaryOperator;)V");
       if (NULL == mid) {
           std::cerr << "Class java.util.List has no method named replaceAll with signature (Ljava/util/function/UnaryOperator;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,unaryOperator_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," List::replaceAll jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
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



    // end namespace crclj
}

