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
%RETURN_VAR_DECLARE%
if(jthis == NULL) {
    std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method %METHOD_NAME% of %FULL_CLASS_NAME% with jthis == NULL." << std::endl;
    %METHOD_ONFAIL%
}
jclass cls = env->GetObjectClass(jthis);
if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," %CLASS_NAME%::%METHOD_NAME% jthis=",jthis);
%CLASS_NAME% *nativeAddress=0;
if (cls != NULL) {
    jfieldID fid = env->GetFieldID(cls, "nativeAddress", "J");
    if (NULL == fid) {
        std::cerr << "Class %FULL_CLASS_NAME% has no field named nativeAddress with signature J." << std::endl;
        env->ThrowNew(getRuntimeExceptionClass(),"Class %FULL_CLASS_NAME% has no field named nativeAddress with signature J.");
        %METHOD_ONFAIL%
    } else {
        
        nativeAddress =  (%CLASS_NAME% *) env->GetLongField( jthis, fid );
        jfieldID fidB = env->GetFieldID(cls, "nativeDeleteOnClose", "Z");
        if(0 == nativeAddress && NULL != fidB) {
            if(GetDebugJ4Cpp()) {
                std::cout << __FILE__ << ":" << __LINE__ << " calling new %CLASS_NAME%(jthis,false)" << std::endl;
            }
            nativeAddress = new %CLASS_NAME%(jthis,false);
            env->SetLongField(jthis,fid,(jlong)nativeAddress);
            env->SetBooleanField(jthis,fidB,JNI_TRUE);
            nativeAddress->context = NULL;
            nativeAddress->initContext(NULL,false);
        }
    }
}
if(nativeAddress == NULL) {
    std::cerr << "Class %FULL_CLASS_NAME%::%METHOD_NAME% : nativeAddress==NULL" << std::endl;
    env->ThrowNew(getRuntimeExceptionClass(),"Class %FULL_CLASS_NAME%::%METHOD_NAME% : nativeAddress==NULL");
    %METHOD_ONFAIL%
}
if(nativeAddress->jthis == NULL) {
    std::cerr << "Class %FULL_CLASS_NAME%::%METHOD_NAME% : nativeAddress->jthis==NULL" << std::endl;
    env->ThrowNew(getRuntimeExceptionClass(),"Class %FULL_CLASS_NAME%::%METHOD_NAME% : nativeAddress->jthis==NULL");
    %METHOD_ONFAIL%
}
if(nativeAddress->jthis != jthis && !env->IsSameObject(nativeAddress->jthis,jthis)) {
    DebugPrintJObject(__FILE__,__LINE__," %CLASS_NAME%::%METHOD_NAME% jthis=",jthis);
    DebugPrintJObject(__FILE__,__LINE__," %CLASS_NAME%::%METHOD_NAME% nativeAddress->jthis=",nativeAddress->jthis);
    std::cerr << "Class %FULL_CLASS_NAME% : nativeAddress->jthis not same object as jthis" << std::endl;
    env->ThrowNew(getRuntimeExceptionClass(),"Class %FULL_CLASS_NAME% : nativeAddress->jthis not same object as jthis");
    %METHOD_ONFAIL%
}

if(GetDebugJ4Cpp()) std::cout << __FILE__ << ":" << __LINE__ <<" Call of method %METHOD_NAME% of %FULL_CLASS_NAME% with nativeAddress=" << nativeAddress << std::endl;
%METHOD_RETURN_STORE% nativeAddress->%METHOD_NAME%Native(%METHOD_ARGS%);
%METHOD_RETURN_GET%