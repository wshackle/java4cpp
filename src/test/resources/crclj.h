#ifndef crclj_h
#define crclj_h

#include <jni.h>
#include "crclj_fwd.h"

namespace crclj {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::crclj::java::lang::Object &objref);
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
    
    
    
    


    
#include "crclj00.h"
#include "crclj01.h"
#include "crclj02.h"
#include "crclj03.h"
#include "crclj04.h"
#include "crclj05.h"
#include "crclj06.h"
#include "crclj07.h"
#include "crclj08.h"
#include "crclj09.h"
#include "crclj10.h"
#include "crclj11.h"
#include "crclj12.h"
#include "crclj13.h"
#include "crclj14.h"
#include "crclj15.h"
#include "crclj16.h"
#include "crclj17.h"
#include "crclj18.h"
#include "crclj19.h"
#include "crclj20.h"
#include "crclj21.h"
#include "crclj22.h"
#include "crclj23.h"
#include "crclj24.h"
#include "crclj25.h"
#include "crclj26.h"


// end namespace crclj
}

// end #ifndef crclj_h
#endif

