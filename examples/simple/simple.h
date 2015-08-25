#ifndef simple_h
#define simple_h

#include <jni.h>
#include "simple_fwd.h"

namespace simple {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void PrintJThrowable(const char *prefix, jthrowable jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::simple::java::lang::Object &objref);
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
    
    
    
    


    
#include "simple0.h"


// end namespace simple
}

// end #ifndef simple_h
#endif

