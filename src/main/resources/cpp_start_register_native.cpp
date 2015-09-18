//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.
    
using namespace %NAMESPACE%;

#ifdef __cplusplus
extern "C" {
#endif
    
static void registerNativeMethods(JNIEnv *env) {
    
        static JNINativeMethod methods[%MAX_METHOD_COUNT%];
        jclass loaderclass = env->FindClass("java/lang/ClassLoader");
        if(debug_j4cpp) std::cout << __FILE__ << ":" <<  __LINE__ << "registerNativeMethods() loaderclass = " << loaderclass << std::endl;
        jmethodID mid = env->GetStaticMethodID(loaderclass,"getSystemClassLoader","()Ljava/lang/ClassLoader;");
        if(debug_j4cpp) std::cout << __FILE__ << ":" << __LINE__ << "registerNativeMethods() mid = " << mid << std::endl;
        jobject loader = env->CallStaticObjectMethod(loaderclass,mid);
        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__, "registerNativeMethods() loader = " ,loader );

        