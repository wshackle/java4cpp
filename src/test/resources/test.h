#ifndef test_h
#define test_h

#include <jni.h>

namespace test {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    
    namespace java {
        namespace lang {

            class Object {
            protected:
                jobject jthis;
            public:
                Object();
                Object(jobject _jthis, bool copy);
                Object(const Object &ref);
                jstring toString();
                ~Object();
            };
        }
    }
    
    


    
	class ClassInDefaultPackage;
	namespace testpackage{
		class A;
	} // end namespace testpackage
	namespace testpackage{
		class MyClient;
	} // end namespace testpackage
	namespace testpackage{
		class Test;
	} // end namespace testpackage
	
	class ClassInDefaultPackage : public java::lang::Object {
		public:
	            ClassInDefaultPackage(jobject _jthis, bool copy);
	            ClassInDefaultPackage(const ClassInDefaultPackage &);
	        
		ClassInDefaultPackage(jint int_0);
		virtual ~ClassInDefaultPackage();
		static void staticTest(jint int_0);
		jint getI();
	}; // end class ClassInDefaultPackage

	namespace testpackage{
		
		class A : public java::lang::Object {
			public:
		            A(jobject _jthis, bool copy);
		            A(const A &);
		        
			A();
			virtual ~A();
			static Test getTestStatic();
			Test getTestNonStatic();
		}; // end class A
	} // end namespace testpackage

	namespace testpackage{
		
		class MyClient : public java::lang::Object {
			public:
		            MyClient(jobject _jthis, bool copy);
		            MyClient(const MyClient &);
		        
			MyClient();
			virtual ~MyClient();
		}; // end class MyClient
	} // end namespace testpackage

	namespace testpackage{
		
		class Test : public java::lang::Object {
			public:
		            Test(jobject _jthis, bool copy);
		            Test(const Test &);
		        
			Test();
			virtual ~Test();
			jint getI();
			jbyteArray getByteArrayProp();
			void setByteArrayProp(jbyteArray byteArray_0);
			jbyte getByteProp();
			void setByteProp(jbyte byte_0);
			jcharArray getCharArrayProp();
			void setCharArrayProp(jcharArray charArray_0);
			jchar getCharProp();
			jshort getShortProp();
			void setShortProp(jshort short_0);
			jshortArray getShortArrayProp();
			jint getIntProp();
			void setIntProp(jint int_0);
			jintArray getIntArrayProp();
			void setIntArrayProp(jintArray intArray_0);
			jlong getLongProp();
			void setLongProp(jlong long_0);
			jlongArray getLongArrayProp();
			void setLongArrayProp(jlongArray longArray_0);
			jfloat getFloatProp();
			void setFloatProp(jfloat float_0);
			jfloatArray getFloatArrayProp();
			void setFloatArrayProp(jfloatArray floatArray_0);
			jdouble getDoubleProp();
			static Test getTestStatic();
			void setDoubleProp(jdouble double_0);
			jdoubleArray getDoubleArrayProp();
			void setDoubleArrayProp(jdoubleArray doubleArray_0);
			void setShortArrayProp(jshortArray shortArray_0);
			void setCharProp(jchar char_0);
			jstring getStrProp();
			void setStrProp(jstring string_0);
			jstring funcReturningString();
			static void main(jobjectArray stringArray_0);
			static void main(int argc,const char **argv);
			jstring toString();
		}; // end class Test
	} // end namespace testpackage



// end namespace test
}

// end #ifndef test_h
#endif

