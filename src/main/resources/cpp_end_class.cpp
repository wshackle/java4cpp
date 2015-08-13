//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
static jclass getNew%CLASS_NAME%Class() {
    jclass clss = getEnv()->FindClass("%FULL_CLASS_JNI_SIGNATURE%");
    if (NULL == clss) {
        std::cerr << " Can't find class %FULL_CLASS_JNI_SIGNATURE%" << std::endl;
    }
    return clss;
}

static jclass %CLASS_NAME%Class = NULL;
static inline jclass get%CLASS_NAME%Class() {
    if (%CLASS_NAME%Class != NULL) {
        return %CLASS_NAME%Class;
    }
    %CLASS_NAME%Class = getNew%CLASS_NAME%Class();
}
