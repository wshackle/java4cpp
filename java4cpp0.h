// Never include this file directly. include java4cpp.h instead.
 
 class ClassInDefaultPackage : public java::lang::Object {
     public:
         ClassInDefaultPackage(jobject _jthis, bool copy);
         ClassInDefaultPackage(const ClassInDefaultPackage &);
         
  protected:
  ClassInDefaultPackage();
  public:
  ClassInDefaultPackage(jint int_0);
  ~ClassInDefaultPackage();
  jint getI();
  static void staticTest(jint int_0);
 }; // end class ClassInDefaultPackage

 namespace testpackage{
  
  class A : public ::java4cpp::java::lang::Object {
      public:
          A(jobject _jthis, bool copy);
          A(const A &);
          
   A();
   ~A();
   static Test getTestStatic();
   Test getTestNonStatic();
  }; // end class A

  
  class MyClient : public ::java4cpp::java::lang::Object {
      public:
          MyClient(jobject _jthis, bool copy);
          MyClient(const MyClient &);
          
   protected:
   MyClient();
   public:
   MyClient(jstring string_0,jint int_1);
   MyClient(const char * easyArg_0,jint easyArg_1);
   ~MyClient();
   jboolean equals(::java4cpp::java::lang::Object  &object_0);
   jstring toString();
   jint hashCode();
   jstring getHost();
   jint getPort();
  }; // end class MyClient

  
  class Test : public ::java4cpp::java::lang::Object {
      public:
          Test(jobject _jthis, bool copy);
          Test(const Test &);
          
   Test();
   ~Test();
   static Test getTestStatic();
   jint getI();
   ::java4cpp::java::util::List getListOfStrings();
   void setListOfStrings(::java4cpp::java::util::List  &list_0);
   A getClassObjectA();
   void setClassObjectA(A  &a_0);
   jbyteArray getByteArrayProp();
   void setByteArrayProp(jbyteArray byteArray_0);
   void setByteArrayProp(jbyte * easyArg_0,jsize easyArg_0_length);
   jbyte getByteProp();
   void setByteProp(jbyte byte_0);
   jcharArray getCharArrayProp();
   void setCharArrayProp(jcharArray charArray_0);
   void setCharArrayProp(jchar * easyArg_0,jsize easyArg_0_length);
   jchar getCharProp();
   jshort getShortProp();
   void setShortProp(jshort short_0);
   jshortArray getShortArrayProp();
   jint getIntProp();
   void setIntProp(jint int_0);
   jintArray getIntArrayProp();
   void setIntArrayProp(jintArray intArray_0);
   void setIntArrayProp(jint * easyArg_0,jsize easyArg_0_length);
   jlong getLongProp();
   void setLongProp(jlong long_0);
   jlongArray getLongArrayProp();
   void setLongArrayProp(jlongArray longArray_0);
   void setLongArrayProp(jlong * easyArg_0,jsize easyArg_0_length);
   jfloat getFloatProp();
   void setFloatProp(jfloat float_0);
   jfloatArray getFloatArrayProp();
   void setFloatArrayProp(jfloatArray floatArray_0);
   void setFloatArrayProp(jfloat * easyArg_0,jsize easyArg_0_length);
   jdouble getDoubleProp();
   void setDoubleProp(jdouble double_0);
   jdoubleArray getDoubleArrayProp();
   void setDoubleArrayProp(jdoubleArray doubleArray_0);
   void setDoubleArrayProp(jdouble * easyArg_0,jsize easyArg_0_length);
   void setShortArrayProp(jshortArray shortArray_0);
   void setShortArrayProp(jshort * easyArg_0,jsize easyArg_0_length);
   void setCharProp(jchar char_0);
   jstring getStrProp();
   void setStrProp(jstring string_0);
   void setStrProp(const char * easyArg_0);
   jstring funcReturningString();
   static void main(jobjectArray stringArray_0);
   static void main(int argc,const char **argv);
   jstring toString();
  }; // end class Test
 } // end namespace testpackage


 namespace java{
  namespace util{
   
   class List : public ::java4cpp::java::lang::Object {
       public:
           List(jobject _jthis, bool copy);
           List(const List &);
           
    List();
    ~List();
    jboolean add(::java4cpp::java::lang::Object  &object_0);
    void add(jint int_0,::java4cpp::java::lang::Object  &object_1);
    jboolean remove(::java4cpp::java::lang::Object  &object_0);
    ::java4cpp::java::lang::Object remove(jint int_0);
    ::java4cpp::java::lang::Object get(jint int_0);
    jboolean equals(::java4cpp::java::lang::Object  &object_0);
    jint hashCode();
    jint indexOf(::java4cpp::java::lang::Object  &object_0);
    void clear();
    jboolean isEmpty();
    jint lastIndexOf(::java4cpp::java::lang::Object  &object_0);
    jboolean contains(::java4cpp::java::lang::Object  &object_0);
    jint size();
    List subList(jint int_0,jint int_1);
    jobjectArray toArray();
    jobjectArray toArray(jobjectArray objectArray_0);
    ::java4cpp::java::lang::Object set(jint int_0,::java4cpp::java::lang::Object  &object_1);
   }; // end class List
  } // end namespace util
 } // end namespace java


