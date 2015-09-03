//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.


static void registerNative%CLASS_NAME%(JNIEnv *env,jobject loader) {
        
    static JNINativeMethod methods[%NUM_NATIVE_METHODS%];
    jclass rn_clss = env->FindClass("%CLASS_NAME%");
    if(debug_j4cpp) std::cout << __FILE__ << ":" __LINE__ << "registerNative%CLASS_NAME%() rn_clss = " << rn_clss << std::endl;
    if(NULL != rn_clss) {


