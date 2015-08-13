
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "test.h"

namespace test {

    JNIEnv *getEnv();
    static jclass getStringClass();
    static jstring getEmptyString();
    static bool debug_j4cpp = false;

    namespace java {
        namespace lang {

            Object::Object() {
                jthis = NULL;
            };

            Object::Object(const Object &objref) {
                jobject _jthis = objref.jthis;
                if (_jthis != NULL) {
                    jthis = getEnv()->NewGlobalRef(_jthis);
                }
            };

            Object::Object(jobject _jthis, bool copy) {
                //                std::cout << "_jthis = " << _jthis << std::endl;
                jthis = NULL;
                if (_jthis != NULL) {
                    JNIEnv *env = getEnv();
                    jobjectRefType ref0 = env->GetObjectRefType(jthis);
                    if (copy || ref0 != JNIGlobalRefType) {
                        jthis = env->NewGlobalRef(_jthis);
                    }
                }
            };

            Object::~Object() {
                if (NULL != jthis) {
                    getEnv()->DeleteGlobalRef(jthis);
                    jthis = NULL;
                }
            };

            jstring Object::toString() {

                if (jthis == NULL) {
                    std::cerr << "Call of method toString of java.lang.Object with jthis == NULL." << std::endl;
                    return NULL;
                }
                JNIEnv *env = getEnv();
                jobjectRefType ref0 = env->GetObjectRefType(jthis);
                if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Object::toString() jthis=",jthis);
                jclass cls = env->GetObjectClass(jthis);
                jstring retVal = NULL;
                if (cls != NULL) {
                    jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
                    if (NULL == mid) {
                        std::cerr << "Class ava.lang.Object has no method named toString with signature ()Ljava/lang/String;." << std::endl;
                        return NULL;
                    } else {
                        retVal = (jstring) env->CallObjectMethod(jthis, mid);
                    }
                }
                return retVal;
            }
        }
    }


	
	// get JNI handle for class ClassInDefaultPackage
	static inline jclass getClassInDefaultPackageClass();
	
	ClassInDefaultPackage::ClassInDefaultPackage(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
	        // Place holder for future extensibility
	}
	
	ClassInDefaultPackage::ClassInDefaultPackage(const ClassInDefaultPackage &objref) {
	    jobject _jthis = objref.jthis;
	    if (_jthis != NULL) {
	        jthis = getEnv()->NewGlobalRef(_jthis);
	    }
	}
	ClassInDefaultPackage::ClassInDefaultPackage(jint int_0) {
		JNIEnv *env =getEnv();
		jclass cls = getClassInDefaultPackageClass();
		if (cls != NULL) {
		    jmethodID mid = env->GetMethodID(cls, "<init>", "(I)V");
		    if (NULL == mid) {
		        std::cerr << "Class ClassInDefaultPackage has no method constructor signature (I)V" << std::endl;
		    } else {
		        jthis = env->NewObject(cls, mid ,int_0);
		        jobjectRefType ref = env->GetObjectRefType(jthis);
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," new ClassInDefaultPackage jthis=",jthis);
		//        std::cout << "ClassInDefaultPackage ref=" << ref << std::endl;
		//        std::cout << "ClassInDefaultPackage jthis=" << jthis << std::endl;
		        if(ref != JNIGlobalRefType) {
		            jthis = env->NewGlobalRef(jthis);
		        }
		    }
		}
	}


	// Destructor for ClassInDefaultPackage
	ClassInDefaultPackage::~ClassInDefaultPackage() {
		// Place-holder for later extensibility.
	}

	void ClassInDefaultPackage::staticTest(jint int_0) {

	        JNIEnv *env =getEnv();
	        static jclass cls = getClassInDefaultPackageClass();
	        
	        if (cls != NULL) {
	            static jmethodID mid = env->GetStaticMethodID(cls, "staticTest", "(I)V");
	            if (NULL == mid) {
	                std::cerr << "Class ClassInDefaultPackage has no method named staticTest with signature (I)V." << std::endl;
	                
	            } else {
	                 env->CallStaticVoidMethod( cls, mid ,int_0 );
	            }
	        }
	        
	}
	jint ClassInDefaultPackage::getI() {

	        if(jthis == NULL) {
	            std::cerr << "Call of method getI of ClassInDefaultPackage with jthis == NULL." << std::endl;
	            return (jint) -1;
	        }
	        JNIEnv *env =getEnv();
	        jclass cls = env->GetObjectClass(jthis);
	//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
	//        std::cout << "ClassInDefaultPackage ref0=" << ref0 << std::endl;
	//        std::cout << "ClassInDefaultPackage jthis=" << jthis << std::endl;
	//        std::cout << "ClassInDefaultPackage GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
	//        std::cout << "ClassInDefaultPackage getClassInDefaultPackageClass()=" << cls << std::endl;
	//        std::cout << "ClassInDefaultPackage isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
	//        std::cout << "ClassInDefaultPackage isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
	//        std::cout << "ClassInDefaultPackage isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
	//    
	        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," ClassInDefaultPackage::getI jthis=",jthis);
	        jint retVal= (jint) -1;
	        if (cls != NULL) {
	            static jmethodID mid = env->GetMethodID(cls, "getI", "()I");
	            if (NULL == mid) {
	                std::cerr << "Class ClassInDefaultPackage has no method named getI with signature ()I." << std::endl;
	                return (jint) -1;
	            } else {
	                retVal= (jint)  env->CallIntMethod(jthis, mid  );
	            }
	        }
	        return retVal;
	}
	static jclass getNewClassInDefaultPackageClass() {
	    jclass clss = getEnv()->FindClass("ClassInDefaultPackage");
	    if (NULL == clss) {
	        std::cerr << " Can't find class ClassInDefaultPackage" << std::endl;
	    }
	    return clss;
	}
	
	static jclass ClassInDefaultPackageClass = NULL;
	static inline jclass getClassInDefaultPackageClass() {
	    if (ClassInDefaultPackageClass != NULL) {
	        return ClassInDefaultPackageClass;
	    }
	    ClassInDefaultPackageClass = getNewClassInDefaultPackageClass();
	}
		namespace testpackage{
		
		// get JNI handle for class testpackage.A
		static inline jclass getAClass();
		
		A::A(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
		        // Place holder for future extensibility
		}
		
		A::A(const A &objref) {
		    jobject _jthis = objref.jthis;
		    if (_jthis != NULL) {
		        jthis = getEnv()->NewGlobalRef(_jthis);
		    }
		}
		A::A() {
			JNIEnv *env =getEnv();
			jclass cls = getAClass();
			if (cls != NULL) {
			    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
			    if (NULL == mid) {
			        std::cerr << "Class A has no method constructor signature ()V" << std::endl;
			    } else {
			        jthis = env->NewObject(cls, mid );
			        jobjectRefType ref = env->GetObjectRefType(jthis);
			        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," new A jthis=",jthis);
			//        std::cout << "A ref=" << ref << std::endl;
			//        std::cout << "A jthis=" << jthis << std::endl;
			        if(ref != JNIGlobalRefType) {
			            jthis = env->NewGlobalRef(jthis);
			        }
			    }
			}
		}


		// Destructor for testpackage.A
		A::~A() {
			// Place-holder for later extensibility.
		}

		Test A::getTestStatic() {

		        JNIEnv *env =getEnv();
		        static jclass cls = getAClass();
		        jobject retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetStaticMethodID(cls, "getTestStatic", "()Ltestpackage/Test;");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.A has no method named getTestStatic with signature ()Ltestpackage/Test;." << std::endl;
		                Test nullObject((jobject)NULL,false); return nullObject;
		            } else {
		                retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
		            }
		        }
		        			
			jobjectRefType ref = env->GetObjectRefType(retVal);
			std::cout << "ref=" << ref << std::endl;
			std::cout << "retVal=" << retVal << std::endl;
			Test retObject(retVal,false);
			return retObject;
		}
		Test A::getTestNonStatic() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getTestNonStatic of testpackage.A with jthis == NULL." << std::endl;
		            Test nullObject((jobject)NULL,false); return nullObject;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "A ref0=" << ref0 << std::endl;
		//        std::cout << "A jthis=" << jthis << std::endl;
		//        std::cout << "A GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "A getAClass()=" << cls << std::endl;
		//        std::cout << "A isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "A isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "A isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," A::getTestNonStatic jthis=",jthis);
		        jobject retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getTestNonStatic", "()Ltestpackage/Test;");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.A has no method named getTestNonStatic with signature ()Ltestpackage/Test;." << std::endl;
		                Test nullObject((jobject)NULL,false); return nullObject;
		            } else {
		                retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        			
			jobjectRefType ref = env->GetObjectRefType(retVal);
			std::cout << "ref=" << ref << std::endl;
			std::cout << "retVal=" << retVal << std::endl;
			Test retObject(retVal,false);
			return retObject;
		}
		static jclass getNewAClass() {
		    jclass clss = getEnv()->FindClass("testpackage/A");
		    if (NULL == clss) {
		        std::cerr << " Can't find class testpackage/A" << std::endl;
		    }
		    return clss;
		}
		
		static jclass AClass = NULL;
		static inline jclass getAClass() {
		    if (AClass != NULL) {
		        return AClass;
		    }
		    AClass = getNewAClass();
		}
	} // end namespace testpackage
		namespace testpackage{
		
		// get JNI handle for class testpackage.MyClient
		static inline jclass getMyClientClass();
		
		MyClient::MyClient(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
		        // Place holder for future extensibility
		}
		
		MyClient::MyClient(const MyClient &objref) {
		    jobject _jthis = objref.jthis;
		    if (_jthis != NULL) {
		        jthis = getEnv()->NewGlobalRef(_jthis);
		    }
		}
		MyClient::MyClient() {
			JNIEnv *env =getEnv();
			jclass cls = getMyClientClass();
			if (cls != NULL) {
			    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
			    if (NULL == mid) {
			        std::cerr << "Class MyClient has no method constructor signature ()V" << std::endl;
			    } else {
			        jthis = env->NewObject(cls, mid );
			        jobjectRefType ref = env->GetObjectRefType(jthis);
			        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," new MyClient jthis=",jthis);
			//        std::cout << "MyClient ref=" << ref << std::endl;
			//        std::cout << "MyClient jthis=" << jthis << std::endl;
			        if(ref != JNIGlobalRefType) {
			            jthis = env->NewGlobalRef(jthis);
			        }
			    }
			}
		}


		// Destructor for testpackage.MyClient
		MyClient::~MyClient() {
			// Place-holder for later extensibility.
		}

		static jclass getNewMyClientClass() {
		    jclass clss = getEnv()->FindClass("testpackage/MyClient");
		    if (NULL == clss) {
		        std::cerr << " Can't find class testpackage/MyClient" << std::endl;
		    }
		    return clss;
		}
		
		static jclass MyClientClass = NULL;
		static inline jclass getMyClientClass() {
		    if (MyClientClass != NULL) {
		        return MyClientClass;
		    }
		    MyClientClass = getNewMyClientClass();
		}
	} // end namespace testpackage
		namespace testpackage{
		
		// get JNI handle for class testpackage.Test
		static inline jclass getTestClass();
		
		Test::Test(jobject _jthis, bool copy): java::lang::Object(_jthis,copy) {
		        // Place holder for future extensibility
		}
		
		Test::Test(const Test &objref) {
		    jobject _jthis = objref.jthis;
		    if (_jthis != NULL) {
		        jthis = getEnv()->NewGlobalRef(_jthis);
		    }
		}
		Test::Test() {
			JNIEnv *env =getEnv();
			jclass cls = getTestClass();
			if (cls != NULL) {
			    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
			    if (NULL == mid) {
			        std::cerr << "Class Test has no method constructor signature ()V" << std::endl;
			    } else {
			        jthis = env->NewObject(cls, mid );
			        jobjectRefType ref = env->GetObjectRefType(jthis);
			        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," new Test jthis=",jthis);
			//        std::cout << "Test ref=" << ref << std::endl;
			//        std::cout << "Test jthis=" << jthis << std::endl;
			        if(ref != JNIGlobalRefType) {
			            jthis = env->NewGlobalRef(jthis);
			        }
			    }
			}
		}


		// Destructor for testpackage.Test
		Test::~Test() {
			// Place-holder for later extensibility.
		}

		jint Test::getI() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getI of testpackage.Test with jthis == NULL." << std::endl;
		            return (jint) -1;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getI jthis=",jthis);
		        jint retVal= (jint) -1;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getI", "()I");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getI with signature ()I." << std::endl;
		                return (jint) -1;
		            } else {
		                retVal= (jint)  env->CallIntMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		jbyteArray Test::getByteArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getByteArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getByteArrayProp jthis=",jthis);
		        jbyteArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getByteArrayProp", "()[B");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getByteArrayProp with signature ()[B." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jbyteArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setByteArrayProp(jbyteArray byteArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setByteArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setByteArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setByteArrayProp", "([B)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setByteArrayProp with signature ([B)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,byteArray_0 );
		            }
		        }
		        
		}
		jbyte Test::getByteProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getByteProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jbyte) -1;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getByteProp jthis=",jthis);
		        jbyte retVal= (jbyte) -1;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getByteProp", "()B");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getByteProp with signature ()B." << std::endl;
		                return (jbyte) -1;
		            } else {
		                retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setByteProp(jbyte byte_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setByteProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setByteProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setByteProp", "(B)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setByteProp with signature (B)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,byte_0 );
		            }
		        }
		        
		}
		jcharArray Test::getCharArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getCharArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getCharArrayProp jthis=",jthis);
		        jcharArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getCharArrayProp", "()[C");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getCharArrayProp with signature ()[C." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jcharArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setCharArrayProp(jcharArray charArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setCharArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setCharArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setCharArrayProp", "([C)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setCharArrayProp with signature ([C)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,charArray_0 );
		            }
		        }
		        
		}
		jchar Test::getCharProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getCharProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jchar) -1;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getCharProp jthis=",jthis);
		        jchar retVal= (jchar) -1;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getCharProp", "()C");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getCharProp with signature ()C." << std::endl;
		                return (jchar) -1;
		            } else {
		                retVal= (jchar)  env->CallCharMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		jshort Test::getShortProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getShortProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jshort) -1;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getShortProp jthis=",jthis);
		        jshort retVal=(jshort) -1;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getShortProp", "()S");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getShortProp with signature ()S." << std::endl;
		                return (jshort) -1;
		            } else {
		                retVal= (jshort)  env->CallShortMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setShortProp(jshort short_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setShortProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setShortProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setShortProp", "(S)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setShortProp with signature (S)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,short_0 );
		            }
		        }
		        
		}
		jshortArray Test::getShortArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getShortArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getShortArrayProp jthis=",jthis);
		        jshortArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getShortArrayProp", "()[S");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getShortArrayProp with signature ()[S." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jshortArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		jint Test::getIntProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getIntProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jint) -1;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getIntProp jthis=",jthis);
		        jint retVal= (jint) -1;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getIntProp", "()I");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getIntProp with signature ()I." << std::endl;
		                return (jint) -1;
		            } else {
		                retVal= (jint)  env->CallIntMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setIntProp(jint int_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setIntProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setIntProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setIntProp", "(I)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setIntProp with signature (I)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,int_0 );
		            }
		        }
		        
		}
		jintArray Test::getIntArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getIntArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getIntArrayProp jthis=",jthis);
		        jintArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getIntArrayProp", "()[I");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getIntArrayProp with signature ()[I." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jintArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setIntArrayProp(jintArray intArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setIntArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setIntArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setIntArrayProp", "([I)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setIntArrayProp with signature ([I)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,intArray_0 );
		            }
		        }
		        
		}
		jlong Test::getLongProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getLongProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jlong) -1;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getLongProp jthis=",jthis);
		        jlong retVal= (jlong) -1;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getLongProp", "()J");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getLongProp with signature ()J." << std::endl;
		                return (jlong) -1;
		            } else {
		                retVal= (jlong)  env->CallLongMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setLongProp(jlong long_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setLongProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setLongProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setLongProp", "(J)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setLongProp with signature (J)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,long_0 );
		            }
		        }
		        
		}
		jlongArray Test::getLongArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getLongArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getLongArrayProp jthis=",jthis);
		        jlongArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getLongArrayProp", "()[J");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getLongArrayProp with signature ()[J." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jlongArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setLongArrayProp(jlongArray longArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setLongArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setLongArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setLongArrayProp", "([J)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setLongArrayProp with signature ([J)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,longArray_0 );
		            }
		        }
		        
		}
		jfloat Test::getFloatProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getFloatProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jfloat) -1.0;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getFloatProp jthis=",jthis);
		        jfloat retVal= (jfloat) -1.0;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getFloatProp", "()F");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getFloatProp with signature ()F." << std::endl;
		                return (jfloat) -1.0;
		            } else {
		                retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setFloatProp(jfloat float_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setFloatProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setFloatProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setFloatProp", "(F)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setFloatProp with signature (F)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,float_0 );
		            }
		        }
		        
		}
		jfloatArray Test::getFloatArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getFloatArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getFloatArrayProp jthis=",jthis);
		        jfloatArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getFloatArrayProp", "()[F");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getFloatArrayProp with signature ()[F." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jfloatArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setFloatArrayProp(jfloatArray floatArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setFloatArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setFloatArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setFloatArrayProp", "([F)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setFloatArrayProp with signature ([F)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,floatArray_0 );
		            }
		        }
		        
		}
		jdouble Test::getDoubleProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getDoubleProp of testpackage.Test with jthis == NULL." << std::endl;
		            return (jdouble) -1.0;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleProp jthis=",jthis);
		        jdouble retVal= (jdouble) -1.0;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getDoubleProp", "()D");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getDoubleProp with signature ()D." << std::endl;
		                return (jdouble) -1.0;
		            } else {
		                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		Test Test::getTestStatic() {

		        JNIEnv *env =getEnv();
		        static jclass cls = getTestClass();
		        jobject retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetStaticMethodID(cls, "getTestStatic", "()Ltestpackage/Test;");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getTestStatic with signature ()Ltestpackage/Test;." << std::endl;
		                Test nullObject((jobject)NULL,false); return nullObject;
		            } else {
		                retVal= (jobject)  env->CallStaticObjectMethod( cls, mid  );
		            }
		        }
		        			
			jobjectRefType ref = env->GetObjectRefType(retVal);
			std::cout << "ref=" << ref << std::endl;
			std::cout << "retVal=" << retVal << std::endl;
			Test retObject(retVal,false);
			return retObject;
		}
		void Test::setDoubleProp(jdouble double_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setDoubleProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setDoubleProp", "(D)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setDoubleProp with signature (D)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,double_0 );
		            }
		        }
		        
		}
		jdoubleArray Test::getDoubleArrayProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getDoubleArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getDoubleArrayProp jthis=",jthis);
		        jdoubleArray retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getDoubleArrayProp", "()[D");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getDoubleArrayProp with signature ()[D." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setDoubleArrayProp(jdoubleArray doubleArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setDoubleArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setDoubleArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setDoubleArrayProp", "([D)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setDoubleArrayProp with signature ([D)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,doubleArray_0 );
		            }
		        }
		        
		}
		void Test::setShortArrayProp(jshortArray shortArray_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setShortArrayProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setShortArrayProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setShortArrayProp", "([S)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setShortArrayProp with signature ([S)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,shortArray_0 );
		            }
		        }
		        
		}
		void Test::setCharProp(jchar char_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setCharProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setCharProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setCharProp", "(C)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setCharProp with signature (C)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,char_0 );
		            }
		        }
		        
		}
		jstring Test::getStrProp() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method getStrProp of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::getStrProp jthis=",jthis);
		        jstring retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "getStrProp", "()Ljava/lang/String;");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named getStrProp with signature ()Ljava/lang/String;." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::setStrProp(jstring string_0) {

		        if(jthis == NULL) {
		            std::cerr << "Call of method setStrProp of testpackage.Test with jthis == NULL." << std::endl;
		            
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::setStrProp jthis=",jthis);
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "setStrProp", "(Ljava/lang/String;)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named setStrProp with signature (Ljava/lang/String;)V." << std::endl;
		                
		            } else {
		                 env->CallVoidMethod(jthis, mid ,string_0 );
		            }
		        }
		        
		}
		jstring Test::funcReturningString() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method funcReturningString of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::funcReturningString jthis=",jthis);
		        jstring retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "funcReturningString", "()Ljava/lang/String;");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named funcReturningString with signature ()Ljava/lang/String;." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		void Test::main(jobjectArray stringArray_0) {

		        JNIEnv *env =getEnv();
		        static jclass cls = getTestClass();
		        
		        if (cls != NULL) {
		            static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
		                
		            } else {
		                 env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
		            }
		        }
		        
		}
		void Test::main(int argc, const char **argv) {
		        if(argc <1 || argv==NULL) {
		             main(NULL);
		        } else {
		            JNIEnv *env =getEnv();
		            jclass strClss = getStringClass();
		            jobjectArray stringArray = env->NewObjectArray(argc,strClss,getEmptyString());
		            for(int i = 0; i < argc; i++) {
		                jstring str = env->NewStringUTF(argv[i]);
		                env->SetObjectArrayElement(stringArray,i,str);
		            }
		             main(stringArray);
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
		            return ;
		        }
		}
		jstring Test::toString() {

		        if(jthis == NULL) {
		            std::cerr << "Call of method toString of testpackage.Test with jthis == NULL." << std::endl;
		            return NULL;
		        }
		        JNIEnv *env =getEnv();
		        jclass cls = env->GetObjectClass(jthis);
		//        jobjectRefType ref0 = env->GetObjectRefType(jthis);
		//        std::cout << "Test ref0=" << ref0 << std::endl;
		//        std::cout << "Test jthis=" << jthis << std::endl;
		//        std::cout << "Test GetObjectClass=" << env->GetObjectClass(jthis) << std::endl;
		//        std::cout << "Test getTestClass()=" << cls << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(env->GetObjectClass(jthis),cls) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isAssignable=" << (env->IsAssignableFrom(cls,env->GetObjectClass(jthis)) ==JNI_TRUE) << std::endl;
		//        std::cout << "Test isInstanceOf=" << (env->IsInstanceOf(jthis,cls) ==JNI_TRUE) << std::endl;
		//    
		        if(debug_j4cpp) DebugPrintJObject(__FILE__,__LINE__," Test::toString jthis=",jthis);
		        jstring retVal=NULL;
		        if (cls != NULL) {
		            static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
		            if (NULL == mid) {
		                std::cerr << "Class testpackage.Test has no method named toString with signature ()Ljava/lang/String;." << std::endl;
		                return NULL;
		            } else {
		                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
		            }
		        }
		        return retVal;
		}
		static jclass getNewTestClass() {
		    jclass clss = getEnv()->FindClass("testpackage/Test");
		    if (NULL == clss) {
		        std::cerr << " Can't find class testpackage/Test" << std::endl;
		    }
		    return clss;
		}
		
		static jclass TestClass = NULL;
		static inline jclass getTestClass() {
		    if (TestClass != NULL) {
		        return TestClass;
		    }
		    TestClass = getNewTestClass();
		}
	} // end namespace testpackage



    static JNIEnv *getNewEnv() {
        JavaVM *jvm; /* denotes a Java VM */
        JNIEnv *env; /* pointer to native method interface */
        JavaVM * jvmBuf[1];
        jsize nVMs;
        debug_j4cpp = debug_j4cpp || (getenv("DEBUG_J4CPP") != NULL);
        char *classPathEnv = getenv("CLASSPATH");
        char *jvmOptionsEnv = getenv("JVM_OPTIONS");
        std::string str;
        str += "/home/shackle/Test/dist/Test.jar";
        if (classPathEnv != NULL) {
            std::string classPathEnvStr(classPathEnv);
            if (debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
            str += ":";
            str += classPathEnvStr;
        }
        if (debug_j4cpp) std::cout << "str=" << str << std::endl;
        setenv("CLASSPATH", str.c_str(), 1);
        std::string optsString;
        optsString += "-Djava.class.path=";
        optsString += str;
        if (jvmOptionsEnv != NULL) {
            std::string jvmOptionsEnvStr(jvmOptionsEnv);
            if (debug_j4cpp) std::cout << "jvmOptionsEnvStr=" << jvmOptionsEnvStr << std::endl;
            optsString += " ";
            optsString += jvmOptionsEnvStr;
        }
        if (debug_j4cpp) std::cout << "optsString=" << optsString << std::endl;
        jint v = JNI_GetCreatedJavaVMs(jvmBuf, 1, &nVMs);
        if (nVMs > 0) {
            jvmBuf[0]->GetEnv((void **) &env, JNI_VERSION_1_6);
            return env;
        }
        JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
        JavaVMOption* options = new JavaVMOption[1];
        options[0].optionString = (char *) optsString.c_str();
        vm_args.version = JNI_VERSION_1_6;
        vm_args.nOptions = NULL != options[0].optionString ? 1 : 0;
        vm_args.options = options;
        vm_args.ignoreUnrecognized = false;
        /* load and initialize a Java VM, return a JNI interface
         * pointer in env */
        JNI_CreateJavaVM(&jvm,
                ((void **) (&env)),
                ((void *) (&vm_args)));
        delete options;
        return env;
    }

    static JNIEnv *env = NULL;

    JNIEnv *getEnv() {
        if (env != NULL) {
            return env;
        }
        env = getNewEnv();
        return env;
    }

    void releaseEnv(JNIEnv *env) {
        // Maybe implement this later, 
        // This will probably cause a memory leak.
        // Don't like leaks? Why the hell are using C++?
    }

    static jclass getNewStringClass() {
        jclass clss = getEnv()->FindClass("java/lang/String");
        if (NULL == clss) {
            std::cerr << " Can't find class java/lang/String" << std::endl;
        }
        return clss;
    }

    static jclass StringClass = NULL;

    static inline jclass getStringClass() {
        if (StringClass != NULL) {
            return StringClass;
        }
        StringClass = getNewStringClass();
        return StringClass;
    }

    static jstring getNewEmptyString() {
        return getEnv()->NewStringUTF("");
    }

    static jstring EmptyString = NULL;

    static inline jstring getEmptyString() {
        if (EmptyString != NULL) {
            return EmptyString;
        }
        EmptyString = getNewEmptyString();
        return EmptyString;
    }

    void PrintJObject(const char *prefix, jobject jobj) {
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj) {
        JNIEnv *env = getEnv();
        jclass clss = env->GetObjectClass(jobj);
        bool isnull = (jobj == NULL) || (env->IsSameObject(jobj,NULL) == JNI_TRUE);
        if(isnull) {
            std::cout << file << ":" << lineno << " jobj=" << jobj << " " << prefix << "NULL" << std::endl;
            return;
        }
        jmethodID midToString = env->GetMethodID(clss, "toString", "()Ljava/lang/String;");
        jstring jobjstr = (jstring) env->CallObjectMethod(jobj, midToString);
        jboolean iscopy = JNI_FALSE;
        const char *cstr = env->GetStringUTFChars(jobjstr, &iscopy);
        std::cout << file << ":" << lineno << " jobj=" << jobj << " " << prefix << cstr << std::endl;
        env->ReleaseStringUTFChars(jobjstr,cstr);
    }
    
    
    extern void SetDebugJ4Cpp(bool debug) {
        debug_j4cpp = debug;
    }
    
    extern bool GetDebugJ4Cpp() { 
        return debug_j4cpp;
    }
    // end namespace test
}

