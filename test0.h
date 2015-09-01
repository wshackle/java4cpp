// Never include this file (test0.h) directly. include test.h instead.


// start_segment_index = 0
// start_segment_index = 8
// segment_index = 0
// classesSegList=[class ClassInDefaultPackage, class testpackage.A, class testpackage.Test, class java.lang.Enum, class testpackage.ExternalPublicEnum, class testpackage.MyClient, class testpackage.Test$MyEnum, interface java.util.List]


// class_index = 0 clss=class ClassInDefaultPackage

 
 class ClassInDefaultPackage : public java::lang::Object {
     public:
         ClassInDefaultPackage(jobject _jthis, bool copy);
         ClassInDefaultPackage(const ClassInDefaultPackage &);
         static ClassInDefaultPackage cast(const java::lang::Object &);
         
  protected:
  ClassInDefaultPackage();
  public:
  ClassInDefaultPackage(jint int_0);
  ~ClassInDefaultPackage();
  static void staticTest(jint int_0);
  jint getI();
 }; // end class ClassInDefaultPackage


// class_index = 1 clss=class testpackage.A

 namespace testpackage{
  
  class A : public ::test::java::lang::Object {
      public:
          A(jobject _jthis, bool copy);
          A(const A &);
          static A cast(const ::test::java::lang::Object &);
          
   A();
   ~A();
   static Test getTestStatic();
   Test getTestNonStatic();
  }; // end class A


// class_index = 2 clss=class testpackage.Test

  
  class Test : public ::test::java::lang::Object {
      public:
          Test(jobject _jthis, bool copy);
          Test(const Test &);
          static Test cast(const ::test::java::lang::Object &);
          
   Test();
   ~Test();
   jint getNonstaticIntField();
   void setNonstaticIntField(jint int_0);
   static jint getStaticIntField();
   static void setStaticIntField(jint int_0);
   TestMyEnum getEnumABC();
   jint getI();
   static Test getTestStatic();
   ExternalPublicEnum getExternalPublicEnumProp();
   void setExternalPublicEnumProp(const ExternalPublicEnum & externalPublicEnum_0);
   void setEnumABC(const TestMyEnum & myEnum_0);
   ::test::java::util::List getListOfStrings();
   void setListOfStrings(const ::test::java::util::List & list_0);
   A getClassObjectA();
   void setClassObjectA(const A & a_0);
   jbooleanArray getBooleanArrayProp();
   void setBooleanArrayProp(jbooleanArray booleanArray_0);
   void setBooleanArrayProp(jboolean * easyArg_0,jsize easyArg_0_length);
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
   void setI(jint int_0);
   jstring funcReturningString();
   static void main(jobjectArray stringArray_0);
   static void main(int argc,const char **argv);
   jstring toString();
  }; // end class Test
 } // end namespace testpackage



// class_index = 3 clss=class java.lang.Enum

 namespace java{
  namespace lang{
   
   class Enum : public Object {
       public:
           Enum(jobject _jthis, bool copy);
           Enum(const Enum &);
           static Enum cast(const Object &);
           
    private:
    Enum() {};
    public:
    ~Enum();
    jstring name();
    jboolean equals(const Object & object_0);
    jstring toString();
    jint hashCode();
    jint compareTo1(const Enum & enum_0);
    jint ordinal();
   }; // end class Enum
  } // end namespace lang
 } // end namespace java



// class_index = 4 clss=class testpackage.ExternalPublicEnum

 namespace testpackage{
  
  class ExternalPublicEnum : public ::test::java::lang::Enum {
      public:
          ExternalPublicEnum(jobject _jthis, bool copy);
          ExternalPublicEnum(const ExternalPublicEnum &);
          static ExternalPublicEnum cast(const ::test::java::lang::Object &);
          
   protected:
   ExternalPublicEnum();
   public:
   ~ExternalPublicEnum();
   static ExternalPublicEnum getONE();
   static ExternalPublicEnum getTWO();
   static ExternalPublicEnum getTHREE();
   static jobjectArray values();
   static ExternalPublicEnum valueOf(jstring string_0);
  }; // end class ExternalPublicEnum


// class_index = 5 clss=class testpackage.MyClient

  
  class MyClient : public ::test::java::lang::Object {
      public:
          MyClient(jobject _jthis, bool copy);
          MyClient(const MyClient &);
          static MyClient cast(const ::test::java::lang::Object &);
          
   protected:
   MyClient();
   public:
   MyClient(jstring string_0,jint int_1);
   MyClient(const char * easyArg_0,jint easyArg_1);
   ~MyClient();
   jboolean equals(const ::test::java::lang::Object & object_0);
   jstring toString();
   jint hashCode();
   jstring getHost();
   jint getPort();
  }; // end class MyClient


// class_index = 6 clss=class testpackage.Test$MyEnum

  
  class TestMyEnum : public ::test::java::lang::Enum {
      public:
          TestMyEnum(jobject _jthis, bool copy);
          TestMyEnum(const TestMyEnum &);
          static TestMyEnum cast(const ::test::java::lang::Object &);
          
   protected:
   TestMyEnum();
   public:
   ~TestMyEnum();
   static TestMyEnum getA();
   static TestMyEnum getB();
   static TestMyEnum getC();
   static jobjectArray values();
   static TestMyEnum valueOf(jstring string_0);
  }; // end class TestMyEnum
 } // end namespace testpackage



// class_index = 7 clss=interface java.util.List

 namespace java{
  namespace util{
   
   class List : public ::test::java::lang::Object {
       public:
           List(jobject _jthis, bool copy);
           List(const List &);
           static List cast(const ::test::java::lang::Object &);
           
    private:
    List() {};
    public:
    ~List();
    jboolean add(const ::test::java::lang::Object & object_0);
    void add(jint int_0,const ::test::java::lang::Object & object_1);
    jboolean remove(const ::test::java::lang::Object & object_0);
    ::test::java::lang::Object remove1(jint int_0);
    ::test::java::lang::Object get(jint int_0);
    jboolean equals(const ::test::java::lang::Object & object_0);
    jint hashCode();
    jint indexOf(const ::test::java::lang::Object & object_0);
    void clear();
    jboolean isEmpty();
    jint lastIndexOf(const ::test::java::lang::Object & object_0);
    jboolean contains(const ::test::java::lang::Object & object_0);
    jint size();
    List subList(jint int_0,jint int_1);
    jobjectArray toArray();
    jobjectArray toArray(jobjectArray objectArray_0);
    ::test::java::lang::Object set(jint int_0,const ::test::java::lang::Object & object_1);
   }; // end class List
  } // end namespace util
 } // end namespace java


