//%%% Lines beginning with "//%%%" are template comments and removed from final output.
//%%% "%NAMESPACE%" will be replaced with namespace
//%%% "%HEADER%" will be replaced with header
//%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%% "%CLASS_NAME%" will be replaced with className (not including package)
#ifndef %HEADER_DEFINE%
#define %HEADER_DEFINE%

#include <jni.h>

namespace %NAMESPACE% {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    
    namespace java {
        namespace lang {

            class Object {
            protected:
                jobject jthis;
            public:
                Object();
                Object(jobject _jthis, bool copy);
                Object(const Object &ref);
                jstring toString();
                ~Object();
            };
        }
    }
    
    


    