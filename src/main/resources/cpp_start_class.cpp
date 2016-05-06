//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package
//%%% "%BASE_CLASS_FULL_NAME%" full name of this class's Base class.
//%%%% "%OBJECT_CLASS_FULL_NAME%" will be replaced with className (not including package

// get JNI handle for class %FULL_CLASS_NAME%
static inline jclass get%CLASS_NAME%Class();

%CLASS_NAME%::%CLASS_NAME%(jobject _jthis, bool copy): %BASE_CLASS_FULL_NAME%(_jthis,copy) {
        %INITIALIZE_CONTEXT%
}

%CLASS_NAME%::%CLASS_NAME%(const %CLASS_NAME% &objref): %BASE_CLASS_FULL_NAME%((jobject)NULL,false) {
    %INITIALIZE_CONTEXT_REF%
    jobject _jthis = objref.jthis;
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class %CLASS_NAME% _jthis=",_jthis);
    if (_jthis != NULL) {
        jthis = getEnv()->NewGlobalRef(_jthis);
        if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__,"Copy Constructor for class %CLASS_NAME% jthis=",jthis);
    }
}

%CLASS_NAME% %CLASS_NAME%::cast(const %OBJECT_CLASS_FULL_NAME% &objref) {
    JNIEnv *env =getEnv();
    static jclass cls = get%CLASS_NAME%Class(); 
    jclass objcls = env->GetObjectClass(objref.jthis);
    if(!env->IsAssignableFrom(objcls,cls)) {
        throw objcls;
    }
    %CLASS_NAME% retVal(objref.jthis,true);
    return retVal;
}

bool %CLASS_NAME%::instanceof(const %OBJECT_CLASS_FULL_NAME% &objref) {
    JNIEnv *env =getEnv();
    static jclass cls = get%CLASS_NAME%Class(); 
    jclass objcls = env->GetObjectClass(objref.jthis);
    return (JNI_TRUE == env->IsAssignableFrom(objcls,cls));
}
