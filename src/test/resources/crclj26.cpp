
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace java{
   namespace util{
   
   // get JNI handle for class java.util.Optional
   static inline jclass getOptionalClass();
   
   Optional::Optional(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Optional::Optional(const Optional &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   Optional::Optional() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getOptionalClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class Optional has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::setSystemId jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Optional with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Optional jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for java.util.Optional
   Optional::~Optional() {
   	// Place-holder for later extensibility.
   }

   jboolean Optional::isPresent() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isPresent of java.util.Optional with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::isPresent jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isPresent", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named isPresent with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::isPresent jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   Optional Optional::ofNullable(::crclj::java::lang::Object  &object_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getOptionalClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "ofNullable", "(Ljava/lang/Object;)Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named ofNullable with signature (Ljava/lang/Object;)Ljava/util/Optional;." << std::endl;
           Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::ofNullable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Optional retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::lang::Object Optional::orElse(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method orElse of java.util.Optional with jthis == NULL." << std::endl;
       ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::orElse jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "orElse", "(Ljava/lang/Object;)Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named orElse with signature (Ljava/lang/Object;)Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::orElse jthis=",t);
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
   Optional Optional::flatMap(function::Function  &function_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method flatMap of java.util.Optional with jthis == NULL." << std::endl;
       Optional nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::flatMap jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "flatMap", "(Ljava/util/function/Function;)Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named flatMap with signature (Ljava/util/function/Function;)Ljava/util/Optional;." << std::endl;
           Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,function_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::flatMap jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Optional retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::lang::Object Optional::get() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method get of java.util.Optional with jthis == NULL." << std::endl;
       ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::get jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "get", "()Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named get with signature ()Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::get jthis=",t);
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
   jboolean Optional::equals(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.util.Optional with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring Optional::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.util.Optional with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint Optional::hashCode() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.util.Optional with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::hashCode jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named hashCode with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::hashCode jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   Optional Optional::of(::crclj::java::lang::Object  &object_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getOptionalClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "of", "(Ljava/lang/Object;)Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named of with signature (Ljava/lang/Object;)Ljava/util/Optional;." << std::endl;
           Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::of jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Optional retObject(retVal,false);
    return retObject;
   }
   Optional Optional::empty() {

   JNIEnv *env =getEnv();
   static jclass cls = getOptionalClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "empty", "()Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named empty with signature ()Ljava/util/Optional;." << std::endl;
           Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::empty jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Optional retObject(retVal,false);
    return retObject;
   }
   Optional Optional::filter(function::Predicate  &predicate_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method filter of java.util.Optional with jthis == NULL." << std::endl;
       Optional nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::filter jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "filter", "(Ljava/util/function/Predicate;)Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named filter with signature (Ljava/util/function/Predicate;)Ljava/util/Optional;." << std::endl;
           Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,predicate_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::filter jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Optional retObject(retVal,false);
    return retObject;
   }
   Optional Optional::map(function::Function  &function_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method map of java.util.Optional with jthis == NULL." << std::endl;
       Optional nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Optional::map jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "map", "(Ljava/util/function/Function;)Ljava/util/Optional;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Optional has no method named map with signature (Ljava/util/function/Function;)Ljava/util/Optional;." << std::endl;
           Optional nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,function_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Optional::map jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Optional retObject(retVal,false);
    return retObject;
   }
   static jclass getNewOptionalClass() {
       jclass clss = getEnv()->FindClass("java/util/Optional");
       if (NULL == clss) {
           std::cerr << " Can't find class java/util/Optional" << std::endl;
       }
       return clss;
   }
   
   static jclass OptionalClass = NULL;
   static inline jclass getOptionalClass() {
       if (OptionalClass != NULL) {
           return OptionalClass;
       }
       OptionalClass = getNewOptionalClass();
   }
    namespace stream{
    
    // get JNI handle for class java.util.stream.Stream
    static inline jclass getStreamClass();
    
    Stream::Stream(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Stream::Stream(const Stream &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Stream::Stream() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Stream has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Stream::map jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Stream with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Stream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for java.util.stream.Stream
    Stream::~Stream() {
    	// Place-holder for later extensibility.
    }

    Stream Stream::iterate(::crclj::java::lang::Object  &object_0,::crclj::java::util::function::UnaryOperator  &unaryOperator_1) {

    JNIEnv *env =getEnv();
    static jclass cls = getStreamClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "iterate", "(Ljava/lang/Object;Ljava/util/function/UnaryOperator;)Ljava/util/stream/Stream;");
        if (NULL == mid) {
            std::cerr << "Class java.util.stream.Stream has no method named iterate with signature (Ljava/lang/Object;Ljava/util/function/UnaryOperator;)Ljava/util/stream/Stream;." << std::endl;
            Stream nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis,unaryOperator_1.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Stream::iterate jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Stream retObject(retVal,false);
     return retObject;
    }
    Stream Stream::concat(Stream  &stream_0,Stream  &stream_1) {

    JNIEnv *env =getEnv();
    static jclass cls = getStreamClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "concat", "(Ljava/util/stream/Stream;Ljava/util/stream/Stream;)Ljava/util/stream/Stream;");
        if (NULL == mid) {
            std::cerr << "Class java.util.stream.Stream has no method named concat with signature (Ljava/util/stream/Stream;Ljava/util/stream/Stream;)Ljava/util/stream/Stream;." << std::endl;
            Stream nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,stream_0.jthis,stream_1.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Stream::concat jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Stream retObject(retVal,false);
     return retObject;
    }
    Stream Stream::of(jobjectArray objectArray_0) {

    JNIEnv *env =getEnv();
    static jclass cls = getStreamClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "of", "([Ljava/lang/Object;)Ljava/util/stream/Stream;");
        if (NULL == mid) {
            std::cerr << "Class java.util.stream.Stream has no method named of with signature ([Ljava/lang/Object;)Ljava/util/stream/Stream;." << std::endl;
            Stream nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,objectArray_0 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Stream::of jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Stream retObject(retVal,false);
     return retObject;
    }
    Stream Stream::of(::crclj::java::lang::Object  &object_0) {

    JNIEnv *env =getEnv();
    static jclass cls = getStreamClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "of", "(Ljava/lang/Object;)Ljava/util/stream/Stream;");
        if (NULL == mid) {
            std::cerr << "Class java.util.stream.Stream has no method named of with signature (Ljava/lang/Object;)Ljava/util/stream/Stream;." << std::endl;
            Stream nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Stream::of jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Stream retObject(retVal,false);
     return retObject;
    }
    Stream Stream::empty() {

    JNIEnv *env =getEnv();
    static jclass cls = getStreamClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "empty", "()Ljava/util/stream/Stream;");
        if (NULL == mid) {
            std::cerr << "Class java.util.stream.Stream has no method named empty with signature ()Ljava/util/stream/Stream;." << std::endl;
            Stream nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Stream::empty jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Stream retObject(retVal,false);
     return retObject;
    }
    static jclass getNewStreamClass() {
        jclass clss = getEnv()->FindClass("java/util/stream/Stream");
        if (NULL == clss) {
            std::cerr << " Can't find class java/util/stream/Stream" << std::endl;
        }
        return clss;
    }
    
    static jclass StreamClass = NULL;
    static inline jclass getStreamClass() {
        if (StreamClass != NULL) {
            return StreamClass;
        }
        StreamClass = getNewStreamClass();
    }
   } // end namespace stream

   
   // get JNI handle for class java.util.Collection
   static inline jclass getCollectionClass();
   
   Collection::Collection(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Collection::Collection(const Collection &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   Collection::Collection() : ::crclj::java::lang::Object((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getCollectionClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class Collection has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Collection::empty jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Collection with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Collection jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for java.util.Collection
   Collection::~Collection() {
   	// Place-holder for later extensibility.
   }

   stream::Stream Collection::stream() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method stream of java.util.Collection with jthis == NULL." << std::endl;
       stream::Stream nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Collection::stream jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "stream", "()Ljava/util/stream/Stream;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Collection has no method named stream with signature ()Ljava/util/stream/Stream;." << std::endl;
           stream::Stream nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Collection::stream jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    stream::Stream retObject(retVal,false);
    return retObject;
   }
   jboolean Collection::removeIf(function::Predicate  &predicate_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method removeIf of java.util.Collection with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Collection::removeIf jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "removeIf", "(Ljava/util/function/Predicate;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.util.Collection has no method named removeIf with signature (Ljava/util/function/Predicate;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,predicate_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Collection::removeIf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   stream::Stream Collection::parallelStream() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method parallelStream of java.util.Collection with jthis == NULL." << std::endl;
       stream::Stream nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Collection::parallelStream jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "parallelStream", "()Ljava/util/stream/Stream;");
       if (NULL == mid) {
           std::cerr << "Class java.util.Collection has no method named parallelStream with signature ()Ljava/util/stream/Stream;." << std::endl;
           stream::Stream nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Collection::parallelStream jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    stream::Stream retObject(retVal,false);
    return retObject;
   }
   static jclass getNewCollectionClass() {
       jclass clss = getEnv()->FindClass("java/util/Collection");
       if (NULL == clss) {
           std::cerr << " Can't find class java/util/Collection" << std::endl;
       }
       return clss;
   }
   
   static jclass CollectionClass = NULL;
   static inline jclass getCollectionClass() {
       if (CollectionClass != NULL) {
           return CollectionClass;
       }
       CollectionClass = getNewCollectionClass();
   }
    namespace function{
    
    // get JNI handle for class java.util.function.Function
    static inline jclass getFunctionClass();
    
    Function::Function(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Function::Function(const Function &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Function::Function() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFunctionClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Function has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Function::parallelStream jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Function with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Function jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for java.util.function.Function
    Function::~Function() {
    	// Place-holder for later extensibility.
    }

    Function Function::compose(Function  &function_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method compose of java.util.function.Function with jthis == NULL." << std::endl;
        Function nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Function::compose jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "compose", "(Ljava/util/function/Function;)Ljava/util/function/Function;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Function has no method named compose with signature (Ljava/util/function/Function;)Ljava/util/function/Function;." << std::endl;
            Function nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,function_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Function::compose jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Function retObject(retVal,false);
     return retObject;
    }
    Function Function::andThen(Function  &function_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method andThen of java.util.function.Function with jthis == NULL." << std::endl;
        Function nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Function::andThen jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "andThen", "(Ljava/util/function/Function;)Ljava/util/function/Function;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Function has no method named andThen with signature (Ljava/util/function/Function;)Ljava/util/function/Function;." << std::endl;
            Function nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,function_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Function::andThen jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Function retObject(retVal,false);
     return retObject;
    }
    Function Function::identity() {

    JNIEnv *env =getEnv();
    static jclass cls = getFunctionClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "identity", "()Ljava/util/function/Function;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Function has no method named identity with signature ()Ljava/util/function/Function;." << std::endl;
            Function nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Function::identity jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Function retObject(retVal,false);
     return retObject;
    }
    static jclass getNewFunctionClass() {
        jclass clss = getEnv()->FindClass("java/util/function/Function");
        if (NULL == clss) {
            std::cerr << " Can't find class java/util/function/Function" << std::endl;
        }
        return clss;
    }
    
    static jclass FunctionClass = NULL;
    static inline jclass getFunctionClass() {
        if (FunctionClass != NULL) {
            return FunctionClass;
        }
        FunctionClass = getNewFunctionClass();
    }
   } // end namespace function
  } // end namespace util
 } // end namespace java



    // end namespace crclj
}

