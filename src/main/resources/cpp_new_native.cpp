//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JNI_SIGNATURE% will be replaced with the JNI signature for the constructor.
//%%%% "%CONSTRUCTOR_ARGS% will be replaced with the actual Constructors arguments
JNIEnv *env =getEnv();
static jclass cls = get%CLASS_NAME%Class();
if(GetDebugJ4Cpp()) {
    DebugPrintJObject(__FILE__,__LINE__,"Native Constructor for %CLASS_NAME% cls=",cls);
    std::cout << __FILE__ << ":" << __LINE__ << " Native Constructor for %CLASS_NAME% this=" << this << std::endl;
}
if (cls != NULL) {
    static jmethodID mid = env->GetMethodID(cls, "<init>", "(J)V");
    if (NULL == mid) {
        std::cerr << "Class %CLASS_NAME% has no method constructor signature %JNI_SIGNATURE%" << std::endl;
    } else {
        jthis = env->NewObject(cls, mid , ((jlong)this));
        jthrowable t = env->ExceptionOccurred();
        if(t != NULL) {
            if(GetDebugJ4Cpp()) {
                DebugPrintJObject(__FILE__,__LINE__," %CLASS_NAME%::%METHOD_NAME% jthis=",t);
                env->ExceptionDescribe();
            }
            throw t;
        }
        if(jthis == NULL) {
            std::cerr << "Call to create new %CLASS_NAME% with signature %JNI_SIGNATURE% returned null." << std::endl;
            releaseEnv(env);
            return;
        }
        jobjectRefType ref = env->GetObjectRefType(jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new %CLASS_NAME% jthis=",jthis);
        if(ref != JNIGlobalRefType) {
            jthis = env->NewGlobalRef(jthis);
        }
    }
}
releaseEnv(env);