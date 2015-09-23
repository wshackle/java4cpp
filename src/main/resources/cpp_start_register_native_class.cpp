//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.

    jclass rn_%CLASS_NAME%_clss = env->FindClass("%CLASS_NAME%");
    if(debug_j4cpp) std::cout << __FILE__ << ":" << __LINE__ << "registerNative%CLASS_NAME%() rn_%CLASS_NAME%_clss = " << rn_%CLASS_NAME%_clss << std::endl;
    if(NULL != rn_%CLASS_NAME%_clss) {


