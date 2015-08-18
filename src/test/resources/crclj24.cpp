
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace java{
   namespace io{
   
   // get JNI handle for class java.io.FilterOutputStream
   static inline jclass getFilterOutputStreamClass();
   
   FilterOutputStream::FilterOutputStream(jobject _jthis, bool copy): OutputStream(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   FilterOutputStream::FilterOutputStream(const FilterOutputStream &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   FilterOutputStream::FilterOutputStream() : OutputStream((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getFilterOutputStreamClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class FilterOutputStream has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new FilterOutputStream with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new FilterOutputStream jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   FilterOutputStream::FilterOutputStream(OutputStream  &outputStream_0) : OutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFilterOutputStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/OutputStream;)V");
        if (NULL == mid) {
            std::cerr << "Class FilterOutputStream has no method constructor signature (Ljava/io/OutputStream;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,outputStream_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new FilterOutputStream with signature (Ljava/io/OutputStream;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new FilterOutputStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.io.FilterOutputStream
   FilterOutputStream::~FilterOutputStream() {
   	// Place-holder for later extensibility.
   }

   void FilterOutputStream::write(jbyteArray byteArray_0,jint int_1,jint int_2) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.FilterOutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "([BII)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.FilterOutputStream has no method named write with signature ([BII)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byteArray_0,int_1,int_2 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void FilterOutputStream::write(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method write of java.io.FilterOutputStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",jthis);
    
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jint int_1= easyArg_1;
    jint int_2= easyArg_2;
    write(byteArray_0,int_1,int_2);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
   }

   void FilterOutputStream::write(jbyteArray byteArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.FilterOutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "([B)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.FilterOutputStream has no method named write with signature ([B)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void FilterOutputStream::write(jbyte * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method write of java.io.FilterOutputStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",jthis);
    
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    write(byteArray_0);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
   }

   void FilterOutputStream::write(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.FilterOutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.FilterOutputStream has no method named write with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void FilterOutputStream::flush() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method flush of java.io.FilterOutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::flush jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "flush", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.FilterOutputStream has no method named flush with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::flush jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void FilterOutputStream::close() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method close of java.io.FilterOutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::close jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "close", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.FilterOutputStream has no method named close with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," FilterOutputStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewFilterOutputStreamClass() {
       jclass clss = getEnv()->FindClass("java/io/FilterOutputStream");
       if (NULL == clss) {
           std::cerr << " Can't find class java/io/FilterOutputStream" << std::endl;
       }
       return clss;
   }
   
   static jclass FilterOutputStreamClass = NULL;
   static inline jclass getFilterOutputStreamClass() {
       if (FilterOutputStreamClass != NULL) {
           return FilterOutputStreamClass;
       }
       FilterOutputStreamClass = getNewFilterOutputStreamClass();
   }
   
   // get JNI handle for class java.io.PrintStream
   static inline jclass getPrintStreamClass();
   
   PrintStream::PrintStream(jobject _jthis, bool copy): FilterOutputStream(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PrintStream::PrintStream(const PrintStream &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PrintStream::PrintStream() : FilterOutputStream((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getPrintStreamClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class PrintStream has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PrintStream with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   PrintStream::PrintStream(OutputStream  &outputStream_0) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/OutputStream;)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/OutputStream;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,outputStream_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/io/OutputStream;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PrintStream::PrintStream(OutputStream  &outputStream_0,jboolean boolean_1) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/OutputStream;Z)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/OutputStream;Z)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,outputStream_0.jthis,boolean_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/io/OutputStream;Z)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PrintStream::PrintStream(OutputStream  &outputStream_0,jboolean boolean_1,jstring string_2) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/OutputStream;ZLjava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/OutputStream;ZLjava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,outputStream_0.jthis,boolean_1,string_2);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/io/OutputStream;ZLjava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PrintStream::PrintStream(OutputStream easyArg_0,jboolean easyArg_1,const char * easyArg_2) : FilterOutputStream((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getPrintStreamClass();
   OutputStream  &outputStream_0= easyArg_0;
   jboolean boolean_1= easyArg_1;
   jstring string_2 = env->NewStringUTF(easyArg_2);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/OutputStream;ZLjava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/OutputStream;ZLjava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,outputStream_0.jthis,boolean_1,string_2);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PrintStream with signature (Ljava/io/OutputStream;ZLjava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
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
   PrintStream::PrintStream(jstring string_0) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PrintStream::PrintStream(const char * easyArg_0) : FilterOutputStream((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getPrintStreamClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class PrintStream has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PrintStream with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
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
   PrintStream::PrintStream(jstring string_0,jstring string_1) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0,string_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/lang/String;Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PrintStream::PrintStream(const char * easyArg_0,const char * easyArg_1) : FilterOutputStream((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getPrintStreamClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   jstring string_1 = env->NewStringUTF(easyArg_1);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class PrintStream has no method constructor signature (Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0,string_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PrintStream with signature (Ljava/lang/String;Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
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
   PrintStream::PrintStream(File  &file_0,jstring string_1) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/File;Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,file_0.jthis,string_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/io/File;Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PrintStream::PrintStream(File easyArg_0,const char * easyArg_1) : FilterOutputStream((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getPrintStreamClass();
   File  &file_0= easyArg_0;
   jstring string_1 = env->NewStringUTF(easyArg_1);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/File;Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,file_0.jthis,string_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new PrintStream with signature (Ljava/io/File;Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
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
   PrintStream::PrintStream(File  &file_0) : FilterOutputStream((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPrintStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/io/File;)V");
        if (NULL == mid) {
            std::cerr << "Class PrintStream has no method constructor signature (Ljava/io/File;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,file_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PrintStream with signature (Ljava/io/File;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PrintStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.io.PrintStream
   PrintStream::~PrintStream() {
   	// Place-holder for later extensibility.
   }

   void PrintStream::println(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jfloat float_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(F)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (F)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,float_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jlong long_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(J)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (J)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(Ljava/lang/Object;)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (Ljava/lang/Object;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    println(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void PrintStream::println(jcharArray charArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "([C)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature ([C)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,charArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jchar * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
    
            
    jcharArray charArray_0= env->NewCharArray(easyArg_0_length);
    env->SetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
    println(charArray_0);
    env->GetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(charArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(charArray_0);
    }
    
    releaseEnv(env);
   }

   void PrintStream::println() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jchar char_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(C)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (C)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,char_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::println(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method println of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "println", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named println with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::println jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PrintStream PrintStream::append(jchar char_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method append of java.io.PrintStream with jthis == NULL." << std::endl;
       PrintStream nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::append jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "append", "(C)Ljava/io/PrintStream;");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named append with signature (C)Ljava/io/PrintStream;." << std::endl;
           PrintStream nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,char_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::append jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PrintStream retObject(retVal,false);
    return retObject;
   }
   PrintStream PrintStream::format(jstring string_0,jobjectArray objectArray_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method format of java.io.PrintStream with jthis == NULL." << std::endl;
       PrintStream nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::format jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named format with signature (Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;." << std::endl;
           PrintStream nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,string_0,objectArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::format jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PrintStream retObject(retVal,false);
    return retObject;
   }
   void PrintStream::write(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named write with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::write(jbyteArray byteArray_0,jint int_1,jint int_2) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "([BII)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named write with signature ([BII)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byteArray_0,int_1,int_2 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::write(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method write of java.io.PrintStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::write jthis=",jthis);
    
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jint int_1= easyArg_1;
    jint int_2= easyArg_2;
    write(byteArray_0,int_1,int_2);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
   }

   void PrintStream::print(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(jlong long_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(J)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (J)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(jfloat float_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(F)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (F)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,float_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(Ljava/lang/Object;)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (Ljava/lang/Object;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    print(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void PrintStream::print(jcharArray charArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "([C)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature ([C)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,charArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(jchar * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
    
            
    jcharArray charArray_0= env->NewCharArray(easyArg_0_length);
    env->SetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
    print(charArray_0);
    env->GetCharArrayRegion(charArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(charArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(charArray_0);
    }
    
    releaseEnv(env);
   }

   void PrintStream::print(jchar char_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(C)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (C)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,char_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::print(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method print of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "print", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named print with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::print jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::flush() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method flush of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::flush jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "flush", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named flush with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::flush jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PrintStream::close() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method close of java.io.PrintStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "close", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named close with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean PrintStream::checkError() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method checkError of java.io.PrintStream with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::checkError jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "checkError", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named checkError with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::checkError jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   PrintStream PrintStream::printf(jstring string_0,jobjectArray objectArray_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method printf of java.io.PrintStream with jthis == NULL." << std::endl;
       PrintStream nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PrintStream::printf jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "printf", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
       if (NULL == mid) {
           std::cerr << "Class java.io.PrintStream has no method named printf with signature (Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;." << std::endl;
           PrintStream nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,string_0,objectArray_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PrintStream::printf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PrintStream retObject(retVal,false);
    return retObject;
   }
   static jclass getNewPrintStreamClass() {
       jclass clss = getEnv()->FindClass("java/io/PrintStream");
       if (NULL == clss) {
           std::cerr << " Can't find class java/io/PrintStream" << std::endl;
       }
       return clss;
   }
   
   static jclass PrintStreamClass = NULL;
   static inline jclass getPrintStreamClass() {
       if (PrintStreamClass != NULL) {
           return PrintStreamClass;
       }
       PrintStreamClass = getNewPrintStreamClass();
   }
  } // end namespace io

   namespace util{
    namespace function{
    
    // get JNI handle for class java.util.function.Predicate
    static inline jclass getPredicateClass();
    
    Predicate::Predicate(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Predicate::Predicate(const Predicate &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Predicate::Predicate() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPredicateClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Predicate has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Predicate::printf jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Predicate with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Predicate jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for java.util.function.Predicate
    Predicate::~Predicate() {
    	// Place-holder for later extensibility.
    }

    Predicate Predicate::isEqual(::crclj::java::lang::Object  &object_0) {

    JNIEnv *env =getEnv();
    static jclass cls = getPredicateClass();
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "isEqual", "(Ljava/lang/Object;)Ljava/util/function/Predicate;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Predicate has no method named isEqual with signature (Ljava/lang/Object;)Ljava/util/function/Predicate;." << std::endl;
            Predicate nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Predicate::isEqual jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Predicate retObject(retVal,false);
     return retObject;
    }
    Predicate Predicate::negate() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method negate of java.util.function.Predicate with jthis == NULL." << std::endl;
        Predicate nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Predicate::negate jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "negate", "()Ljava/util/function/Predicate;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Predicate has no method named negate with signature ()Ljava/util/function/Predicate;." << std::endl;
            Predicate nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Predicate::negate jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Predicate retObject(retVal,false);
     return retObject;
    }
    Predicate Predicate::andMethod(Predicate  &predicate_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method andMethod of java.util.function.Predicate with jthis == NULL." << std::endl;
        Predicate nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Predicate::andMethod jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "andMethod", "(Ljava/util/function/Predicate;)Ljava/util/function/Predicate;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Predicate has no method named andMethod with signature (Ljava/util/function/Predicate;)Ljava/util/function/Predicate;." << std::endl;
            Predicate nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,predicate_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Predicate::andMethod jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Predicate retObject(retVal,false);
     return retObject;
    }
    Predicate Predicate::orMethod(Predicate  &predicate_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method orMethod of java.util.function.Predicate with jthis == NULL." << std::endl;
        Predicate nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Predicate::orMethod jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "orMethod", "(Ljava/util/function/Predicate;)Ljava/util/function/Predicate;");
        if (NULL == mid) {
            std::cerr << "Class java.util.function.Predicate has no method named orMethod with signature (Ljava/util/function/Predicate;)Ljava/util/function/Predicate;." << std::endl;
            Predicate nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid ,predicate_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Predicate::orMethod jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
         
     jobjectRefType ref = env->GetObjectRefType(retVal);
     Predicate retObject(retVal,false);
     return retObject;
    }
    static jclass getNewPredicateClass() {
        jclass clss = getEnv()->FindClass("java/util/function/Predicate");
        if (NULL == clss) {
            std::cerr << " Can't find class java/util/function/Predicate" << std::endl;
        }
        return clss;
    }
    
    static jclass PredicateClass = NULL;
    static inline jclass getPredicateClass() {
        if (PredicateClass != NULL) {
            return PredicateClass;
        }
        PredicateClass = getNewPredicateClass();
    }
   } // end namespace function
  } // end namespace util

   namespace math{
   
   // get JNI handle for class java.math.BigInteger
   static inline jclass getBigIntegerClass();
   
   BigInteger::BigInteger(jobject _jthis, bool copy): ::crclj::java::lang::Number(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   BigInteger::BigInteger(const BigInteger &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   BigInteger::BigInteger() : ::crclj::java::lang::Number((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getBigIntegerClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class BigInteger has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigInteger with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }

   BigInteger::BigInteger(jbyteArray byteArray_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigIntegerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "([B)V");
        if (NULL == mid) {
            std::cerr << "Class BigInteger has no method constructor signature ([B)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,byteArray_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigInteger with signature ([B)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigInteger::BigInteger(jbyte * easyArg_0,jsize easyArg_0_length) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigIntegerClass();
   jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
   env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "([B)V");
       if (NULL == mid) {
           std::cerr << "Class BigInteger has no method constructor signature ([B)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,byteArray_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigInteger with signature ([B)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
   jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(byteArray_0);
   }
   
   releaseEnv(env);
   }
   BigInteger::BigInteger(jint int_0,jbyteArray byteArray_1) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigIntegerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(I[B)V");
        if (NULL == mid) {
            std::cerr << "Class BigInteger has no method constructor signature (I[B)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,int_0,byteArray_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigInteger with signature (I[B)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigInteger::BigInteger(jint easyArg_0,jbyte * easyArg_1,jsize easyArg_1_length) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigIntegerClass();
   jint int_0= easyArg_0;
   jbyteArray byteArray_1= env->NewByteArray(easyArg_1_length);
   env->SetByteArrayRegion(byteArray_1,0,easyArg_1_length,easyArg_1);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(I[B)V");
       if (NULL == mid) {
           std::cerr << "Class BigInteger has no method constructor signature (I[B)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,int_0,byteArray_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigInteger with signature (I[B)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   env->GetByteArrayRegion(byteArray_1,0,easyArg_1_length,easyArg_1);
   jobjectRefType ref_1 = env->GetObjectRefType(byteArray_1);
   if(ref_1 == JNIGlobalRefType) {
    env->DeleteGlobalRef(byteArray_1);
   }
   
   releaseEnv(env);
   }
   BigInteger::BigInteger(jstring string_0,jint int_1) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigIntegerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
        if (NULL == mid) {
            std::cerr << "Class BigInteger has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0,int_1);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigInteger with signature (Ljava/lang/String;I)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigInteger::BigInteger(const char * easyArg_0,jint easyArg_1) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigIntegerClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   jint int_1= easyArg_1;
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
       if (NULL == mid) {
           std::cerr << "Class BigInteger has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0,int_1);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigInteger with signature (Ljava/lang/String;I)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
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
   BigInteger::BigInteger(jstring string_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getBigIntegerClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class BigInteger has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new BigInteger with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   BigInteger::BigInteger(const char * easyArg_0) : ::crclj::java::lang::Number((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getBigIntegerClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class BigInteger has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new BigInteger with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new BigInteger jthis=",jthis);
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

   // Destructor for java.math.BigInteger
   BigInteger::~BigInteger() {
   	// Place-holder for later extensibility.
   }

   jobjectArray BigInteger::divideAndRemainder(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divideAndRemainder of java.math.BigInteger with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::divideAndRemainder jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divideAndRemainder", "(Ljava/math/BigInteger;)[Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named divideAndRemainder with signature (Ljava/math/BigInteger;)[Ljava/math/BigInteger;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::divideAndRemainder jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong BigInteger::longValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method longValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::longValueExact jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "longValueExact", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named longValueExact with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::longValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigInteger::intValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method intValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::intValueExact jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "intValueExact", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named intValueExact with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::intValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jshort BigInteger::shortValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method shortValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jshort) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::shortValueExact jthis=",jthis);
   jshort retVal=(jshort) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "shortValueExact", "()S");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named shortValueExact with signature ()S." << std::endl;
           return (jshort) -1;
       } else {
           retVal= (jshort)  env->CallShortMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::shortValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jbyte BigInteger::byteValueExact() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method byteValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jbyte) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::byteValueExact jthis=",jthis);
   jbyte retVal= (jbyte) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "byteValueExact", "()B");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named byteValueExact with signature ()B." << std::endl;
           return (jbyte) -1;
       } else {
           retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::byteValueExact jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigInteger::bitLength() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method bitLength of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::bitLength jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "bitLength", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named bitLength with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::bitLength jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean BigInteger::testBit(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method testBit of java.math.BigInteger with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::testBit jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "testBit", "(I)Z");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named testBit with signature (I)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::testBit jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigInteger::nextProbablePrime() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method nextProbablePrime of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::nextProbablePrime jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "nextProbablePrime", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named nextProbablePrime with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::nextProbablePrime jthis=",t);
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
   BigInteger BigInteger::modPow(BigInteger  &bigInteger_0,BigInteger  &bigInteger_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method modPow of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::modPow jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "modPow", "(Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named modPow with signature (Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis,bigInteger_1.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::modPow jthis=",t);
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
   BigInteger BigInteger::modInverse(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method modInverse of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::modInverse jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "modInverse", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named modInverse with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::modInverse jthis=",t);
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
   BigInteger BigInteger::clearBit(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clearBit of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::clearBit jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "clearBit", "(I)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named clearBit with signature (I)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::clearBit jthis=",t);
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
   jint BigInteger::getLowestSetBit() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getLowestSetBit of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::getLowestSetBit jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getLowestSetBit", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named getLowestSetBit with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::getLowestSetBit jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean BigInteger::isProbablePrime(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isProbablePrime of java.math.BigInteger with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::isProbablePrime jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isProbablePrime", "(I)Z");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named isProbablePrime with signature (I)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::isProbablePrime jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigInteger::mod(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method mod of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::mod jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "mod", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named mod with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::mod jthis=",t);
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
   BigInteger BigInteger::notMethod() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method notMethod of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::notMethod jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "notMethod", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named notMethod with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::notMethod jthis=",t);
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
   BigInteger BigInteger::subtract(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method subtract of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::subtract jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "subtract", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named subtract with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::subtract jthis=",t);
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
   BigInteger BigInteger::multiply(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named multiply with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::multiply jthis=",t);
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
   BigInteger BigInteger::negate() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method negate of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::negate jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "negate", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named negate with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::negate jthis=",t);
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
   BigInteger BigInteger::shiftRight(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method shiftRight of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::shiftRight jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "shiftRight", "(I)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named shiftRight with signature (I)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::shiftRight jthis=",t);
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
   BigInteger BigInteger::setBit(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setBit of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::setBit jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setBit", "(I)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named setBit with signature (I)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::setBit jthis=",t);
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
   BigInteger BigInteger::flipBit(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method flipBit of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::flipBit jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "flipBit", "(I)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named flipBit with signature (I)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::flipBit jthis=",t);
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
   BigInteger BigInteger::gcd(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method gcd of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::gcd jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "gcd", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named gcd with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::gcd jthis=",t);
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
   BigInteger BigInteger::add(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method add of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::add jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "add", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named add with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::add jthis=",t);
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
   jint BigInteger::bitCount() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method bitCount of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::bitCount jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "bitCount", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named bitCount with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::bitCount jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean BigInteger::equals(::crclj::java::lang::Object  &object_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.math.BigInteger with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring BigInteger::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.math.BigInteger with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring BigInteger::toString(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.math.BigInteger with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "(I)Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named toString with signature (I)Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigInteger::hashCode() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::hashCode jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named hashCode with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::hashCode jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigInteger::abs() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method abs of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::abs jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "abs", "()Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named abs with signature ()Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::abs jthis=",t);
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
   BigInteger BigInteger::pow(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method pow of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::pow jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "pow", "(I)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named pow with signature (I)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::pow jthis=",t);
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
   BigInteger BigInteger::min(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method min of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::min jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "min", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named min with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::min jthis=",t);
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
   BigInteger BigInteger::max(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method max of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::max jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "max", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named max with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::max jthis=",t);
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
   jint BigInteger::compareTo(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method compareTo of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::compareTo jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/math/BigInteger;)I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named compareTo with signature (Ljava/math/BigInteger;)I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::compareTo jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jint BigInteger::intValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method intValue of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::intValue jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "intValue", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named intValue with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::intValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jlong BigInteger::longValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method longValue of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jlong) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::longValue jthis=",jthis);
   jlong retVal= (jlong) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "longValue", "()J");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named longValue with signature ()J." << std::endl;
           return (jlong) -1;
       } else {
           retVal= (jlong)  env->CallLongMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::longValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jfloat BigInteger::floatValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method floatValue of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jfloat) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::floatValue jthis=",jthis);
   jfloat retVal= (jfloat) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "floatValue", "()F");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named floatValue with signature ()F." << std::endl;
           return (jfloat) -1.0;
       } else {
           retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::floatValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble BigInteger::doubleValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method doubleValue of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::doubleValue jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "doubleValue", "()D");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named doubleValue with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::doubleValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigInteger::valueOf(jlong long_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getBigIntegerClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(J)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named valueOf with signature (J)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,long_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::valueOf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    BigInteger retObject(retVal,false);
    return retObject;
   }
   jint BigInteger::signum() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method signum of java.math.BigInteger with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::signum jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "signum", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named signum with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::signum jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigInteger::shiftLeft(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method shiftLeft of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::shiftLeft jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "shiftLeft", "(I)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named shiftLeft with signature (I)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::shiftLeft jthis=",t);
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
   BigInteger BigInteger::divide(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method divide of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::divide jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named divide with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::divide jthis=",t);
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
   BigInteger BigInteger::remainder(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method remainder of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::remainder jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "remainder", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named remainder with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::remainder jthis=",t);
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
   jbyteArray BigInteger::toByteArray() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toByteArray of java.math.BigInteger with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::toByteArray jthis=",jthis);
   jbyteArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toByteArray", "()[B");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named toByteArray with signature ()[B." << std::endl;
           return NULL;
       } else {
           retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::toByteArray jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   BigInteger BigInteger::andMethod(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method andMethod of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::andMethod jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "andMethod", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named andMethod with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::andMethod jthis=",t);
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
   BigInteger BigInteger::orMethod(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method orMethod of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "orMethod", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named orMethod with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::orMethod jthis=",t);
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
   BigInteger BigInteger::xorMethod(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method xorMethod of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::xorMethod jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "xorMethod", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named xorMethod with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::xorMethod jthis=",t);
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
   BigInteger BigInteger::andNot(BigInteger  &bigInteger_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method andNot of java.math.BigInteger with jthis == NULL." << std::endl;
       BigInteger nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," BigInteger::andNot jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "andNot", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
       if (NULL == mid) {
           std::cerr << "Class java.math.BigInteger has no method named andNot with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
           BigInteger nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,bigInteger_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," BigInteger::andNot jthis=",t);
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
   static jclass getNewBigIntegerClass() {
       jclass clss = getEnv()->FindClass("java/math/BigInteger");
       if (NULL == clss) {
           std::cerr << " Can't find class java/math/BigInteger" << std::endl;
       }
       return clss;
   }
   
   static jclass BigIntegerClass = NULL;
   static inline jclass getBigIntegerClass() {
       if (BigIntegerClass != NULL) {
           return BigIntegerClass;
       }
       BigIntegerClass = getNewBigIntegerClass();
   }
  } // end namespace math
 } // end namespace java

  namespace rcs{
   namespace posemath{
   
   // get JNI handle for class rcs.posemath.PmQuaternion
   static inline jclass getPmQuaternionClass();
   
   PmQuaternion::PmQuaternion(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PmQuaternion::PmQuaternion(const PmQuaternion &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PmQuaternion::PmQuaternion() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmQuaternionClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PmQuaternion has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::andNot jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmQuaternion with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmQuaternion jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmQuaternion::PmQuaternion(PmRpy  &pmRpy_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmQuaternionClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmRpy;)V");
        if (NULL == mid) {
            std::cerr << "Class PmQuaternion has no method constructor signature (Lrcs/posemath/PmRpy;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmRpy_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::andNot jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmQuaternion with signature (Lrcs/posemath/PmRpy;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmQuaternion jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmQuaternion::PmQuaternion(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmQuaternionClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDDD)V");
        if (NULL == mid) {
            std::cerr << "Class PmQuaternion has no method constructor signature (DDDD)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0,double_1,double_2,double_3);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::andNot jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmQuaternion with signature (DDDD)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmQuaternion jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmQuaternion::PmQuaternion(PmRotationMatrix  &pmRotationMatrix_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmQuaternionClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmRotationMatrix;)V");
        if (NULL == mid) {
            std::cerr << "Class PmQuaternion has no method constructor signature (Lrcs/posemath/PmRotationMatrix;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmRotationMatrix_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::andNot jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmQuaternion with signature (Lrcs/posemath/PmRotationMatrix;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmQuaternion jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmQuaternion::PmQuaternion(PmRotationVector  &pmRotationVector_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmQuaternionClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmRotationVector;)V");
        if (NULL == mid) {
            std::cerr << "Class PmQuaternion has no method constructor signature (Lrcs/posemath/PmRotationVector;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmRotationVector_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::andNot jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmQuaternion with signature (Lrcs/posemath/PmRotationVector;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmQuaternion jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for rcs.posemath.PmQuaternion
   PmQuaternion::~PmQuaternion() {
   	// Place-holder for later extensibility.
   }

   jdouble PmQuaternion::getX() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getX of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getX jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getX", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named getX with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getX jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble PmQuaternion::getY() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getY of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getY jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getY", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named getY with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble PmQuaternion::getS() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getS of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getS jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getS", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named getS with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getS jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmQuaternion::setS(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setS of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setS jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setS", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named setS with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setS jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PmQuaternion::setX(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setX of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setX jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setX", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named setX with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setX jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PmQuaternion::setY(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setY of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setY jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setY", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named setY with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PmQuaternion::getZ() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getZ of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getZ jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getZ", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named getZ with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::getZ jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmQuaternion::setZ(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setZ of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setZ jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setZ", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named setZ with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::setZ jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   PmQuaternion PmQuaternion::multipy(PmQuaternion  &pmQuaternion_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multipy of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       PmQuaternion nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::multipy jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multipy", "(Lrcs/posemath/PmQuaternion;)Lrcs/posemath/PmQuaternion;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named multipy with signature (Lrcs/posemath/PmQuaternion;)Lrcs/posemath/PmQuaternion;." << std::endl;
           PmQuaternion nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,pmQuaternion_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::multipy jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmQuaternion retObject(retVal,false);
    return retObject;
   }
   jboolean PmQuaternion::equals(PmRotationVector  &pmRotationVector_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Lrcs/posemath/PmRotationVector;)Z");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named equals with signature (Lrcs/posemath/PmRotationVector;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,pmRotationVector_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PmQuaternion::equals(PmRotationMatrix  &pmRotationMatrix_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Lrcs/posemath/PmRotationMatrix;)Z");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named equals with signature (Lrcs/posemath/PmRotationMatrix;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,pmRotationMatrix_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean PmQuaternion::equals(PmQuaternion  &pmQuaternion_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Lrcs/posemath/PmQuaternion;)Z");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named equals with signature (Lrcs/posemath/PmQuaternion;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,pmQuaternion_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring PmQuaternion::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   PmQuaternion PmQuaternion::clone() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clone of rcs.posemath.PmQuaternion with jthis == NULL." << std::endl;
       PmQuaternion nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::clone jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "clone", "()Lrcs/posemath/PmQuaternion;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmQuaternion has no method named clone with signature ()Lrcs/posemath/PmQuaternion;." << std::endl;
           PmQuaternion nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmQuaternion::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmQuaternion retObject(retVal,false);
    return retObject;
   }
   static jclass getNewPmQuaternionClass() {
       jclass clss = getEnv()->FindClass("rcs/posemath/PmQuaternion");
       if (NULL == clss) {
           std::cerr << " Can't find class rcs/posemath/PmQuaternion" << std::endl;
       }
       return clss;
   }
   
   static jclass PmQuaternionClass = NULL;
   static inline jclass getPmQuaternionClass() {
       if (PmQuaternionClass != NULL) {
           return PmQuaternionClass;
       }
       PmQuaternionClass = getNewPmQuaternionClass();
   }
  } // end namespace posemath
 } // end namespace rcs



    // end namespace crclj
}

