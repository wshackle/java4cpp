//%%% Lines beginning with "//%%%" are template comments and removed from final output.
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
        if(jthis == NULL) {
            std::cerr << "Call of method %METHOD_NAME% of %FULL_CLASS_NAME% with jthis == NULL." << std::endl;
            %METHOD_ONFAIL%
        }
        JNIEnv *env =getEnv();
        jclass cls = env->GetObjectClass(jthis);
//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
//        std::cout << "%CLASS_NAME% ref0=" << ref0 << std::endl;
//        std::cout << "%CLASS_NAME% jthis=" << jthis << std::endl;
//        std::cout << "%CLASS_NAME% GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
//        std::cout << "%CLASS_NAME% get%CLASS_NAME%Class()=" << cls << std::endl;
//        std::cout << "%CLASS_NAME% isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
//        std::cout << "%CLASS_NAME% isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
//        std::cout << "%CLASS_NAME% isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
//    
if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," %CLASS_NAME%::%METHOD_NAME% jthis=",jthis);
%RETURN_VAR_DECLARE%
if (cls != NULL) {
    static jmethodID mid = env->GetMethodID(cls, "%METHOD_NAME%", "%JNI_SIGNATURE%");
    if (NULL == mid) {
        std::cerr << "Class %FULL_CLASS_NAME% has no method named %METHOD_NAME% with signature %JNI_SIGNATURE%." << std::endl;
        %METHOD_ONFAIL%
    } else {
        %METHOD_RETURN_STORE% env->Call%METHOD_CALL_TYPE%Method(jthis, mid %METHOD_ARGS% );
    }
}
releaseEnv(env);
%METHOD_RETURN_GET%
