//%%%% Lines beginning with "//%%%%" are template comments and removed from final output.
//%%%% "%NAMESPACE%" will be replaced with namespace
//%%%% "%HEADER%" will be replaced with header
//%%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%%% "%JAR%" will be replaced with name of Jar this was created from.
    methods[%METHOD_NUMBER%].name = (char *) "%METHOD_NAME%";
    methods[%METHOD_NUMBER%].signature = (char *) "%JNI_SIGNATURE%";
    methods[%METHOD_NUMBER%].fnPtr = (void *) Java_%CLASS_NAME%_%METHOD_NAME%;       