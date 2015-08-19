#ifndef java4cpp_h
#define java4cpp_h

#include <jni.h>
#include "java4cpp_fwd.h"

namespace java4cpp {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::java4cpp::java::lang::Object &objref);
    extern jclass getStringClass();
    extern jstring getEmptyString();
    
    namespace java {
        namespace lang {

            class Object {
            public:
                jobject jthis;
                Object();
                Object(jobject _jthis, bool copy);
                Object(const Object &ref);
                jstring toString();
                ~Object();
            };
        }
    }
    
    
    
    


    
#incude "java4cpp0.h"
#incude "java4cpp1.h"


// end namespace java4cpp
}

// end #ifndef java4cpp_h
#endif

