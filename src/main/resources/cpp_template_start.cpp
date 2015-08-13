//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)

#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "%HEADER%"

namespace %NAMESPACE% {

    JNIEnv *getEnv();
    static jclass getStringClass();
    static jstring getEmptyString();
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

            Object::~Object() {
                if (NULL != jthis) {
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


