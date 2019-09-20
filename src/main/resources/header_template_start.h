//%%% Lines beginning with "//%%%" are template comments and removed from final output.
//%%% "%NAMESPACE%" will be replaced with namespace
//%%% "%HEADER%" will be replaced with header
//%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%% "%CLASS_NAME%" will be replaced with className (not including package)
#ifndef %HEADER_DEFINE%
#define %HEADER_DEFINE%

#include <jni.h>
#include "%FORWARD_HEADER%"

namespace %NAMESPACE% {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void PrintJThrowable(const char *prefix, jthrowable jobj);
    extern void PrintJBooleanArray(const char *prefix, jbooleanArray jobj);
    extern void PrintJByteArray(const char *prefix, jbyteArray jobj);
    extern void PrintJCharArray(const char *prefix, jcharArray jobj);
    extern void PrintJShortArray(const char *prefix, jshortArray jobj);
    extern void PrintJIntArray(const char *prefix, jintArray jobj);
    extern void PrintJLongArray(const char *prefix, jlongArray jobj);
    extern void PrintJFloatArray(const char *prefix, jfloatArray jobj);
    extern void PrintJDoubleArray(const char *prefix, jdoubleArray jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::%NAMESPACE%::java::lang::Object &objref);
    extern jclass getStringClass();
    extern jclass getClassClass();
    extern jstring getEmptyString();
    
    extern const char *GetStringUTFChars(jstring js, jboolean *iscopy=NULL);
    extern void ReleaseStringUTFChars(jstring js, const char *utf);
    extern jboolean *GetBooleanArrayElements(jbooleanArray  jarray,jboolean *iscopy=NULL);
    extern jbyte *GetByteArrayElements(jbyteArray  jarray,jboolean *iscopy=NULL);
    extern jchar *GetCharArrayElements(jcharArray  jarray,jboolean *iscopy=NULL);
    extern jshort *GetShortArrayElements(jshortArray  jarray,jboolean *iscopy=NULL);
    extern jint *GetIntArrayElements(jintArray  jarray,jboolean *iscopy=NULL);
    extern jlong *GetLongArrayElements(jlongArray  jarray,jboolean *iscopy=NULL);
    extern jfloat *GetFloatArrayElements(jfloatArray  jarray,jboolean *iscopy=NULL);
    extern jdouble *GetDoubleArrayElements(jdoubleArray  jarray,jboolean *iscopy=NULL);
    
    extern void ReleaseBooleanArrayElements(jbooleanArray jarray, jboolean *nativeArray, jint mode=0);
    extern void ReleaseByteArrayElements(jbyteArray jarray, jbyte *nativeArray, jint mode=0);
    extern void ReleaseCharArrayElements(jcharArray jarray, jchar *nativeArray, jint mode=0);
    extern void ReleaseShortArrayElements(jshortArray jarray, jshort *nativeArray, jint mode=0);
    extern void ReleaseIntArrayElements(jintArray jarray, jint *nativeArray, jint mode=0);
    extern void ReleaseLongArrayElements(jlongArray jarray, jlong *nativeArray, jint mode=0);
    extern void ReleaseFloatArrayElements(jfloatArray jarray, jfloat *nativeArray, jint mode=0);
    extern void ReleaseDoubleArrayElements(jdoubleArray jarray, jdouble *nativeArray, jint mode=0);
    
    namespace java {
        namespace lang {

            class Object {
            public:
                jobject jthis;
                Object();
                Object(jobject _jthis, bool copy);
                Object(const Object &ref);
                Object & operator=(const Object & o);
                jstring toString();
                ~Object();
            };
        }
    }

// end namespace %NAMESPACE%
}

    
    
    


    