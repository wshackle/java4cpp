#ifndef test_h
#define test_h

#include <jni.h>
#include "test_fwd.h"

namespace test {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void PrintJThrowable(const char *prefix, jthrowable jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::test::java::lang::Object &objref);
    extern jclass getStringClass();
    extern jclass getClassClass();
    extern jstring getEmptyString();
    
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
    
    
    
    


    
#include "test0.h"
#include "test1.h"


// end namespace test
}

// end #ifndef test_h
#endif

