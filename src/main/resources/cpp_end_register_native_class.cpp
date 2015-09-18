//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.

    jint rn_ret = env->RegisterNatives(rn_clss,methods,%NUM_NATIVE_METHODS%);
    if(debug_j4cpp) std::cout << __FILE__ << ":" << __LINE__ << "registerNative%CLASS_NAME%() rn_ret = " << rn_ret << std::endl;
}
