#ifndef test_h
#define test_h

#include <jni.h>
#include "test_fwd.h"

namespace test {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::test::java::lang::Object &objref);
    extern jclass getStringClass();
    extern jstring getEmptyString();
    
    namespace java {
        namespace lang {

            class Object {
            public:
                jobject jthis;
                Object();
                Object(jobject _jthis, bool copy);
                Object(const Object &ref);
                jstring toString();
                ~Object();
            };
        }
    }
    
    
    
    


    
 
 class ClassInDefaultPackage : public java::lang::Object {
     public:
         ClassInDefaultPackage(jobject _jthis, bool copy);
         ClassInDefaultPackage(const ClassInDefaultPackage &);
         
  protected:
  ClassInDefaultPackage();
  public:
  ClassInDefaultPackage(jint int_0);
  ~ClassInDefaultPackage();
  static void staticTest(jint int_0);
  jint getI();
 }; // end class ClassInDefaultPackage

 namespace testpackage{
  
  class A : public ::test::java::lang::Object {
      public:
          A(jobject _jthis, bool copy);
          A(const A &);
          
   A();
   ~A();
   static Test getTestStatic();
   Test getTestNonStatic();
  }; // end class A

  
  class MyClient : public ::test::java::lang::Object {
      public:
          MyClient(jobject _jthis, bool copy);
          MyClient(const MyClient &);
          
   protected:
   MyClient();
   public:
   MyClient(jstring string_0,jint int_1);
   MyClient(const char * easyArg_0,jint easyArg_1);
   ~MyClient();
   jboolean equals(::test::java::lang::Object  &object_0);
   jstring toString();
   jint hashCode();
   jstring getHost();
   jint getPort();
  }; // end class MyClient

  
  class Test : public ::test::java::lang::Object {
      public:
          Test(jobject _jthis, bool copy);
          Test(const Test &);
          
   Test();
   ~Test();
   static Test getTestStatic();
   jint getI();
   ::test::java::util::List getListOfStrings();
   void setListOfStrings(::test::java::util::List  &list_0);
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
   
   class List : public ::test::java::lang::Object {
       public:
           List(jobject _jthis, bool copy);
           List(const List &);
           
    List();
    ~List();
    jboolean add(::test::java::lang::Object  &object_0);
    void add(jint int_0,::test::java::lang::Object  &object_1);
    jboolean remove(::test::java::lang::Object  &object_0);
    ::test::java::lang::Object remove(jint int_0);
    ::test::java::lang::Object get(jint int_0);
    jboolean equals(::test::java::lang::Object  &object_0);
    jint hashCode();
    jint indexOf(::test::java::lang::Object  &object_0);
    void clear();
    jboolean isEmpty();
    jint lastIndexOf(::test::java::lang::Object  &object_0);
    jboolean contains(::test::java::lang::Object  &object_0);
    jint size();
    List subList(jint int_0,jint int_1);
    jobjectArray toArray();
    jobjectArray toArray(jobjectArray objectArray_0);
    ::test::java::lang::Object set(jint int_0,::test::java::lang::Object  &object_1);
   }; // end class List
  } // end namespace util
 } // end namespace java




// end namespace test
}

// end #ifndef test_h
#endif

