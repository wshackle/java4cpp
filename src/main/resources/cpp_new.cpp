//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JNI_SIGNATURE% will be replaced with the JNI signature for the constructor.
//%%%% "%CONSTRUCTOR_ARGS% will be replaced with the actual Constructors arguments
JNIEnv *env =getEnv();
static jclass cls = get%CLASS_NAME%Class();
if (cls != NULL) {
    static jmethodID mid = env->GetMethodID(cls, "<init>", "%JNI_SIGNATURE%");
    if (NULL == mid) {
        std::cerr << "Class %CLASS_NAME% has no method constructor signature %JNI_SIGNATURE%" << std::endl;
    } else {
        jthis = env->NewObject(cls, mid %CONSTRUCTOR_ARGS%);
        jobjectRefType ref = env->GetObjectRefType(jthis);
        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," new %CLASS_NAME% jthis=",jthis);
        if(ref != JNIGlobalRefType) {
            jthis = env->NewGlobalRef(jthis);
        }
    }
}
releaseEnv(env);