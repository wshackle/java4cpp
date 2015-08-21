//%%% Lines beginning with "//%%%" are template comments and removed from final output.
//%%% "%NAMESPACE%" will be replaced with namespace
//%%% "%HEADER%" will be replaced with header
//%%% "%HEADER_DEFINE%" will be replaced with defined value used to prevent multiple inclusion
//%%% "%CLASS_NAME%" will be replaced with className (not including package)
//%%% "%BASE_CLASS_FULL_NAME%" full name of this class's Base class.

class %CLASS_NAME% : public %BASE_CLASS_FULL_NAME% {
    public:
        %CLASS_NAME%(jobject _jthis, bool copy);
        %CLASS_NAME%(const %CLASS_NAME% &);
        static %CLASS_NAME% cast(const %OBJECT_CLASS_FULL_NAME% &);
        