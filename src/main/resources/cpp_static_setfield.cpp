//%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%% "%NAMESPACE%" will be replaced with namespace
//%%% "%HEADER%" will be replaced with header
//%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%% "%JNI_SIGNATURE% will be replaced with the JNI signature for the method.
//%%% "%METHOD_NAME% will be replaced with the actual methods arguments       
//%%% "%METHOD_ARGS% will be replaced with the actual methods arguments       
//%%% "%METHOD_ONFAIL% will be replaced with the code to execute on failure eg return -1        
//%%% "%METHOD_CALL_TYPE% will be replaced with the type of Call<Type>Method needed. 
//%%% "%METHOD_RETURN%" will be replaced with "return" or "" for void functions.   
JNIEnv *env =getEnv();
static jclass cls = get%CLASS_NAME%Class();
%RETURN_VAR_DECLARE%
if (cls != NULL) {
    static jfieldID fid = env->GetStaticFieldID(cls, "%FIELD_NAME%", "%JNI_SIGNATURE%");
    if (NULL == fid) {
        std::cerr << "Class %FULL_CLASS_NAME% has no field named %FIELD_NAME% with signature %JNI_SIGNATURE%." << std::endl;
        %METHOD_ONFAIL%
    } else {
        env->SetStatic%METHOD_CALL_TYPE%Field( cls, fid %METHOD_ARGS% );
    }
}
releaseEnv(env);
%METHOD_RETURN_GET%
