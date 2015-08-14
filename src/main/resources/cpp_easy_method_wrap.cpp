//%%% Lines beginning with "//%%%" are template comments and removed from final output.
//%%% "%NAMESPACE%" will be replaced with namespace
//%%% "%HEADER%" will be replaced with header
//%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%% "%JNI_SIGNATURE% will be replaced with the JNI signature for the method.
//%%% "%METHOD_NAME% will be replaced with the actual methods arguments       
//%%% "%METHOD_ONFAIL% will be replaced with the code to execute on failure eg return -1        
//%%% "%METHOD_CALL_TYPE% will be replaced with the type of Call<Type>Method needed.  
//%%% "%METHOD_RETURN%" will be replaced with "return" or "" for void functions. 
//%%% "%METHOD_RETURN_STORE%" will be replaced with "type val =" or "" for void functions. 
//%%% "%METHOD_RETURN_GET%" will be replaced with "return val" or "" for void functions. 
//%%% "%METHOD_RETURN_TYPE%" will be replaced with return type for method. 
%METHOD_RETURN_TYPE% %CLASS_NAME%::%METHOD_NAME%(int argc, const char **argv) {
        if(argc <1 || argv==NULL) {
            %METHOD_RETURN% %METHOD_NAME%(NULL);
        } else {
            JNIEnv *env =getEnv();
            jclass strClss = getStringClass();
            jobjectArray stringArray = env->NewObjectArray(argc,strClss,getEmptyString());
            for(int i = 0; i < argc; i++) {
                jstring str = env->NewStringUTF(argv[i]);
                env->SetObjectArrayElement(stringArray,i,str);
            }
            %METHOD_RETURN_STORE% %METHOD_NAME%(stringArray);
            for(int i = 0; i < argc; i++) {
                jobject str = env->GetObjectArrayElement(stringArray,i);
                jobjectRefType ref = env->GetObjectRefType(str);
                if(ref == JNIGlobalRefType) {
                    env->DeleteGlobalRef(str);
                }
            }
            jobjectRefType ref = env->GetObjectRefType(stringArray);
            if(ref == JNIGlobalRefType) {
                env->DeleteGlobalRef(stringArray);
            }
            %METHOD_RETURN_GET%
        }
}