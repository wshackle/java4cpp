
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crcljavabase1.h"

namespace crcljavabase1 {

    JNIEnv *getEnv();
    static jclass getStringClass();
    static jstring getEmptyString();

    namespace java {
        namespace lang {

            Object::Object() {
                jthis = NULL;
            };

            Object::Object(jobject _jthis) {
                jthis = _jthis;
            };

            Object::~Object() {
                if (NULL != jthis) {
                    getEnv()->DeleteGlobalRef(jthis);
                    jthis = NULL;
                }
            };
        }
    }
 

		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.DataThingType
			static inline jclass getDataThingTypeClass();
			
			DataThingType::DataThingType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			DataThingType::DataThingType() {
				JNIEnv *env =getEnv();
				jclass cls = getDataThingTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class DataThingType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.DataThingType
			DataThingType::~DataThingType() {
				// Place-holder for later extensibility.
			}

			jstring DataThingType::getName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getName of crcl.base.DataThingType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getDataThingTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getName", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.DataThingType has no method named getName with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void DataThingType::setName(jstring string_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setName of crcl.base.DataThingType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getDataThingTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setName", "(Ljava/lang/String;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.DataThingType has no method named setName with signature (Ljava/lang/String;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,string_0 );
			            }
			        }
			        
			}
			static jclass getNewDataThingTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/DataThingType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/DataThingType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass DataThingTypeClass = NULL;
			static inline jclass getDataThingTypeClass() {
			    if (DataThingTypeClass != NULL) {
			        return DataThingTypeClass;
			    }
			    DataThingTypeClass = getNewDataThingTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CRCLCommandType
			static inline jclass getCRCLCommandTypeClass();
			
			CRCLCommandType::CRCLCommandType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			CRCLCommandType::CRCLCommandType() {
				JNIEnv *env =getEnv();
				jclass cls = getCRCLCommandTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class CRCLCommandType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.CRCLCommandType
			CRCLCommandType::~CRCLCommandType() {
				// Place-holder for later extensibility.
			}

			java::math::BigInteger CRCLCommandType::getCommandID() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getCommandID of crcl.base.CRCLCommandType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLCommandTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getCommandID", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLCommandType has no method named getCommandID with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLCommandType::setCommandID(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCommandID of crcl.base.CRCLCommandType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLCommandTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCommandID", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLCommandType has no method named setCommandID with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			static jclass getNewCRCLCommandTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CRCLCommandType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CRCLCommandType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CRCLCommandTypeClass = NULL;
			static inline jclass getCRCLCommandTypeClass() {
			    if (CRCLCommandTypeClass != NULL) {
			        return CRCLCommandTypeClass;
			    }
			    CRCLCommandTypeClass = getNewCRCLCommandTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.MiddleCommandType
			static inline jclass getMiddleCommandTypeClass();
			
			MiddleCommandType::MiddleCommandType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			MiddleCommandType::MiddleCommandType() {
				JNIEnv *env =getEnv();
				jclass cls = getMiddleCommandTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class MiddleCommandType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.MiddleCommandType
			MiddleCommandType::~MiddleCommandType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewMiddleCommandTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/MiddleCommandType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/MiddleCommandType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass MiddleCommandTypeClass = NULL;
			static inline jclass getMiddleCommandTypeClass() {
			    if (MiddleCommandTypeClass != NULL) {
			        return MiddleCommandTypeClass;
			    }
			    MiddleCommandTypeClass = getNewMiddleCommandTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace java{
			namespace lang{
			
			// get JNI handle for class java.lang.Enum
			static inline jclass getEnumClass();
			
			Enum::Enum(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for java.lang.Enum
			Enum::~Enum() {
				// Place-holder for later extensibility.
			}

			jstring Enum::name() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method name of java.lang.Enum with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getEnumClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "name", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Enum has no method named name with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jstring Enum::toString() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toString of java.lang.Enum with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getEnumClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Enum has no method named toString with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint Enum::hashCode() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method hashCode of java.lang.Enum with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getEnumClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Enum has no method named hashCode with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint Enum::compareTo(Enum enum_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method compareTo of java.lang.Enum with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getEnumClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/lang/Enum;)I");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Enum has no method named compareTo with signature (Ljava/lang/Enum;)I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid ,enum_0 );
			            }
			        }
			        return retVal;
			}
			jint Enum::ordinal() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method ordinal of java.lang.Enum with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getEnumClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "ordinal", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Enum has no method named ordinal with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewEnumClass() {
			    jclass clss = getEnv()->FindClass("java/lang/Enum");
			    if (NULL == clss) {
			        std::cerr << " Can't find class java/lang/Enum" << std::endl;
			    }
			    return clss;
			}
			
			static jclass EnumClass = NULL;
			static inline jclass getEnumClass() {
			    if (EnumClass != NULL) {
			        return EnumClass;
			    }
			    EnumClass = getNewEnumClass();
			}
		} // end namespace java
	} // end namespace lang
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.GripperStatusType
			static inline jclass getGripperStatusTypeClass();
			
			GripperStatusType::GripperStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			GripperStatusType::GripperStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getGripperStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class GripperStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.GripperStatusType
			GripperStatusType::~GripperStatusType() {
				// Place-holder for later extensibility.
			}

			jstring GripperStatusType::getGripperName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getGripperName of crcl.base.GripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getGripperStatusTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getGripperName", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.GripperStatusType has no method named getGripperName with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void GripperStatusType::setGripperName(jstring string_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setGripperName of crcl.base.GripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setGripperName", "(Ljava/lang/String;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.GripperStatusType has no method named setGripperName with signature (Ljava/lang/String;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,string_0 );
			            }
			        }
			        
			}
			static jclass getNewGripperStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/GripperStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/GripperStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass GripperStatusTypeClass = NULL;
			static inline jclass getGripperStatusTypeClass() {
			    if (GripperStatusTypeClass != NULL) {
			        return GripperStatusTypeClass;
			    }
			    GripperStatusTypeClass = getNewGripperStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RotSpeedType
			static inline jclass getRotSpeedTypeClass();
			
			RotSpeedType::RotSpeedType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RotSpeedType::RotSpeedType() {
				JNIEnv *env =getEnv();
				jclass cls = getRotSpeedTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RotSpeedType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RotSpeedType
			RotSpeedType::~RotSpeedType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewRotSpeedTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RotSpeedType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RotSpeedType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RotSpeedTypeClass = NULL;
			static inline jclass getRotSpeedTypeClass() {
			    if (RotSpeedTypeClass != NULL) {
			        return RotSpeedTypeClass;
			    }
			    RotSpeedTypeClass = getNewRotSpeedTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RotAccelType
			static inline jclass getRotAccelTypeClass();
			
			RotAccelType::RotAccelType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RotAccelType::RotAccelType() {
				JNIEnv *env =getEnv();
				jclass cls = getRotAccelTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RotAccelType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RotAccelType
			RotAccelType::~RotAccelType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewRotAccelTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RotAccelType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RotAccelType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RotAccelTypeClass = NULL;
			static inline jclass getRotAccelTypeClass() {
			    if (RotAccelTypeClass != NULL) {
			        return RotAccelTypeClass;
			    }
			    RotAccelTypeClass = getNewRotAccelTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.JointDetailsType
			static inline jclass getJointDetailsTypeClass();
			
			JointDetailsType::JointDetailsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			JointDetailsType::JointDetailsType() {
				JNIEnv *env =getEnv();
				jclass cls = getJointDetailsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class JointDetailsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.JointDetailsType
			JointDetailsType::~JointDetailsType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewJointDetailsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/JointDetailsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/JointDetailsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass JointDetailsTypeClass = NULL;
			static inline jclass getJointDetailsTypeClass() {
			    if (JointDetailsTypeClass != NULL) {
			        return JointDetailsTypeClass;
			    }
			    JointDetailsTypeClass = getNewJointDetailsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TransSpeedType
			static inline jclass getTransSpeedTypeClass();
			
			TransSpeedType::TransSpeedType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			TransSpeedType::TransSpeedType() {
				JNIEnv *env =getEnv();
				jclass cls = getTransSpeedTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class TransSpeedType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.TransSpeedType
			TransSpeedType::~TransSpeedType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewTransSpeedTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TransSpeedType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TransSpeedType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TransSpeedTypeClass = NULL;
			static inline jclass getTransSpeedTypeClass() {
			    if (TransSpeedTypeClass != NULL) {
			        return TransSpeedTypeClass;
			    }
			    TransSpeedTypeClass = getNewTransSpeedTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TransAccelType
			static inline jclass getTransAccelTypeClass();
			
			TransAccelType::TransAccelType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			TransAccelType::TransAccelType() {
				JNIEnv *env =getEnv();
				jclass cls = getTransAccelTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class TransAccelType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.TransAccelType
			TransAccelType::~TransAccelType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewTransAccelTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TransAccelType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TransAccelType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TransAccelTypeClass = NULL;
			static inline jclass getTransAccelTypeClass() {
			    if (TransAccelTypeClass != NULL) {
			        return TransAccelTypeClass;
			    }
			    TransAccelTypeClass = getNewTransAccelTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace java{
			namespace lang{
			
			// get JNI handle for class java.lang.Number
			static inline jclass getNumberClass();
			
			Number::Number(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			Number::Number() {
				JNIEnv *env =getEnv();
				jclass cls = getNumberClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class Number has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for java.lang.Number
			Number::~Number() {
				// Place-holder for later extensibility.
			}

			jbyte Number::byteValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method byteValue of java.lang.Number with jthis == NULL." << std::endl;
			            return (jbyte) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getNumberClass();
			        jbyte retVal= (jbyte) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "byteValue", "()B");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Number has no method named byteValue with signature ()B." << std::endl;
			                return (jbyte) -1;
			            } else {
			                retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jshort Number::shortValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method shortValue of java.lang.Number with jthis == NULL." << std::endl;
			            return (jshort) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getNumberClass();
			        jshort retVal=(jshort) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "shortValue", "()S");
			            if (NULL == mid) {
			                std::cerr << "Class java.lang.Number has no method named shortValue with signature ()S." << std::endl;
			                return (jshort) -1;
			            } else {
			                retVal= (jshort)  env->CallShortMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewNumberClass() {
			    jclass clss = getEnv()->FindClass("java/lang/Number");
			    if (NULL == clss) {
			        std::cerr << " Can't find class java/lang/Number" << std::endl;
			    }
			    return clss;
			}
			
			static jclass NumberClass = NULL;
			static inline jclass getNumberClass() {
			    if (NumberClass != NULL) {
			        return NumberClass;
			    }
			    NumberClass = getNewNumberClass();
			}
		} // end namespace java
	} // end namespace lang
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.PoseType
			static inline jclass getPoseTypeClass();
			
			PoseType::PoseType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			PoseType::PoseType() {
				JNIEnv *env =getEnv();
				jclass cls = getPoseTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class PoseType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.PoseType
			PoseType::~PoseType() {
				// Place-holder for later extensibility.
			}

			PointType PoseType::getPoint() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getPoint of crcl.base.PoseType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getPoint", "()Lcrcl/base/PointType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseType has no method named getPoint with signature ()Lcrcl/base/PointType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PointType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseType::setPoint(PointType pointType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setPoint of crcl.base.PoseType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setPoint", "(Lcrcl/base/PointType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseType has no method named setPoint with signature (Lcrcl/base/PointType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,pointType_0 );
			            }
			        }
			        
			}
			VectorType PoseType::getXAxis() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getXAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getXAxis", "()Lcrcl/base/VectorType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseType has no method named getXAxis with signature ()Lcrcl/base/VectorType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (VectorType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseType::setXAxis(VectorType vectorType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setXAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setXAxis", "(Lcrcl/base/VectorType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseType has no method named setXAxis with signature (Lcrcl/base/VectorType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,vectorType_0 );
			            }
			        }
			        
			}
			VectorType PoseType::getZAxis() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getZAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getZAxis", "()Lcrcl/base/VectorType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseType has no method named getZAxis with signature ()Lcrcl/base/VectorType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (VectorType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseType::setZAxis(VectorType vectorType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setZAxis of crcl.base.PoseType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setZAxis", "(Lcrcl/base/VectorType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseType has no method named setZAxis with signature (Lcrcl/base/VectorType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,vectorType_0 );
			            }
			        }
			        
			}
			static jclass getNewPoseTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/PoseType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/PoseType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass PoseTypeClass = NULL;
			static inline jclass getPoseTypeClass() {
			    if (PoseTypeClass != NULL) {
			        return PoseTypeClass;
			    }
			    PoseTypeClass = getNewPoseTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CRCLProgramType
			static inline jclass getCRCLProgramTypeClass();
			
			CRCLProgramType::CRCLProgramType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			CRCLProgramType::CRCLProgramType() {
				JNIEnv *env =getEnv();
				jclass cls = getCRCLProgramTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class CRCLProgramType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.CRCLProgramType
			CRCLProgramType::~CRCLProgramType() {
				// Place-holder for later extensibility.
			}

			InitCanonType CRCLProgramType::getInitCanon() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getInitCanon of crcl.base.CRCLProgramType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLProgramTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getInitCanon", "()Lcrcl/base/InitCanonType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLProgramType has no method named getInitCanon with signature ()Lcrcl/base/InitCanonType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (InitCanonType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLProgramType::setInitCanon(InitCanonType initCanonType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setInitCanon of crcl.base.CRCLProgramType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLProgramTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setInitCanon", "(Lcrcl/base/InitCanonType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLProgramType has no method named setInitCanon with signature (Lcrcl/base/InitCanonType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,initCanonType_0 );
			            }
			        }
			        
			}
			java::util::List CRCLProgramType::getMiddleCommand() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getMiddleCommand of crcl.base.CRCLProgramType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLProgramTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getMiddleCommand", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLProgramType has no method named getMiddleCommand with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			EndCanonType CRCLProgramType::getEndCanon() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getEndCanon of crcl.base.CRCLProgramType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLProgramTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getEndCanon", "()Lcrcl/base/EndCanonType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLProgramType has no method named getEndCanon with signature ()Lcrcl/base/EndCanonType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (EndCanonType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLProgramType::setEndCanon(EndCanonType endCanonType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setEndCanon of crcl.base.CRCLProgramType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLProgramTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setEndCanon", "(Lcrcl/base/EndCanonType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLProgramType has no method named setEndCanon with signature (Lcrcl/base/EndCanonType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,endCanonType_0 );
			            }
			        }
			        
			}
			static jclass getNewCRCLProgramTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CRCLProgramType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CRCLProgramType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CRCLProgramTypeClass = NULL;
			static inline jclass getCRCLProgramTypeClass() {
			    if (CRCLProgramTypeClass != NULL) {
			        return CRCLProgramTypeClass;
			    }
			    CRCLProgramTypeClass = getNewCRCLProgramTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ActuateJointsType
			static inline jclass getActuateJointsTypeClass();
			
			ActuateJointsType::ActuateJointsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ActuateJointsType::ActuateJointsType() {
				JNIEnv *env =getEnv();
				jclass cls = getActuateJointsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ActuateJointsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ActuateJointsType
			ActuateJointsType::~ActuateJointsType() {
				// Place-holder for later extensibility.
			}

			java::util::List ActuateJointsType::getActuateJoint() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getActuateJoint of crcl.base.ActuateJointsType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointsTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getActuateJoint", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointsType has no method named getActuateJoint with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewActuateJointsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ActuateJointsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ActuateJointsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ActuateJointsTypeClass = NULL;
			static inline jclass getActuateJointsTypeClass() {
			    if (ActuateJointsTypeClass != NULL) {
			        return ActuateJointsTypeClass;
			    }
			    ActuateJointsTypeClass = getNewActuateJointsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.JointSpeedAccelType
			static inline jclass getJointSpeedAccelTypeClass();
			
			JointSpeedAccelType::JointSpeedAccelType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			JointSpeedAccelType::JointSpeedAccelType() {
				JNIEnv *env =getEnv();
				jclass cls = getJointSpeedAccelTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class JointSpeedAccelType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.JointSpeedAccelType
			JointSpeedAccelType::~JointSpeedAccelType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal JointSpeedAccelType::getJointSpeed() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointSpeed of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointSpeedAccelTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointSpeed", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointSpeedAccelType has no method named getJointSpeed with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointSpeedAccelType::setJointSpeed(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointSpeed of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointSpeedAccelTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointSpeed", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointSpeedAccelType has no method named setJointSpeed with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal JointSpeedAccelType::getJointAccel() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointAccel of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointSpeedAccelTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointAccel", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointSpeedAccelType has no method named getJointAccel with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointSpeedAccelType::setJointAccel(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointAccel of crcl.base.JointSpeedAccelType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointSpeedAccelTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointAccel", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointSpeedAccelType has no method named setJointAccel with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewJointSpeedAccelTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/JointSpeedAccelType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/JointSpeedAccelType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass JointSpeedAccelTypeClass = NULL;
			static inline jclass getJointSpeedAccelTypeClass() {
			    if (JointSpeedAccelTypeClass != NULL) {
			        return JointSpeedAccelTypeClass;
			    }
			    JointSpeedAccelTypeClass = getNewJointSpeedAccelTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TransSpeedAbsoluteType
			static inline jclass getTransSpeedAbsoluteTypeClass();
			
			TransSpeedAbsoluteType::TransSpeedAbsoluteType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			TransSpeedAbsoluteType::TransSpeedAbsoluteType() {
				JNIEnv *env =getEnv();
				jclass cls = getTransSpeedAbsoluteTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class TransSpeedAbsoluteType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.TransSpeedAbsoluteType
			TransSpeedAbsoluteType::~TransSpeedAbsoluteType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal TransSpeedAbsoluteType::getSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSetting of crcl.base.TransSpeedAbsoluteType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransSpeedAbsoluteTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransSpeedAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void TransSpeedAbsoluteType::setSetting(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSetting of crcl.base.TransSpeedAbsoluteType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransSpeedAbsoluteTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransSpeedAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewTransSpeedAbsoluteTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TransSpeedAbsoluteType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TransSpeedAbsoluteType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TransSpeedAbsoluteTypeClass = NULL;
			static inline jclass getTransSpeedAbsoluteTypeClass() {
			    if (TransSpeedAbsoluteTypeClass != NULL) {
			        return TransSpeedAbsoluteTypeClass;
			    }
			    TransSpeedAbsoluteTypeClass = getNewTransSpeedAbsoluteTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.PoseToleranceType
			static inline jclass getPoseToleranceTypeClass();
			
			PoseToleranceType::PoseToleranceType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			PoseToleranceType::PoseToleranceType() {
				JNIEnv *env =getEnv();
				jclass cls = getPoseToleranceTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class PoseToleranceType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.PoseToleranceType
			PoseToleranceType::~PoseToleranceType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal PoseToleranceType::getXPointTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getXPointTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getXPointTolerance", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named getXPointTolerance with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseToleranceType::setXPointTolerance(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setXPointTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setXPointTolerance", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named setXPointTolerance with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal PoseToleranceType::getYPointTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getYPointTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getYPointTolerance", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named getYPointTolerance with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseToleranceType::setYPointTolerance(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setYPointTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setYPointTolerance", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named setYPointTolerance with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal PoseToleranceType::getZPointTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getZPointTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getZPointTolerance", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named getZPointTolerance with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseToleranceType::setZPointTolerance(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setZPointTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setZPointTolerance", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named setZPointTolerance with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal PoseToleranceType::getXAxisTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getXAxisTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getXAxisTolerance", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named getXAxisTolerance with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseToleranceType::setXAxisTolerance(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setXAxisTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setXAxisTolerance", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named setXAxisTolerance with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal PoseToleranceType::getZAxisTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getZAxisTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getZAxisTolerance", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named getZAxisTolerance with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseToleranceType::setZAxisTolerance(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setZAxisTolerance of crcl.base.PoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setZAxisTolerance", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseToleranceType has no method named setZAxisTolerance with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewPoseToleranceTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/PoseToleranceType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/PoseToleranceType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass PoseToleranceTypeClass = NULL;
			static inline jclass getPoseToleranceTypeClass() {
			    if (PoseToleranceTypeClass != NULL) {
			        return PoseToleranceTypeClass;
			    }
			    PoseToleranceTypeClass = getNewPoseToleranceTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.InitCanonType
			static inline jclass getInitCanonTypeClass();
			
			InitCanonType::InitCanonType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			InitCanonType::InitCanonType() {
				JNIEnv *env =getEnv();
				jclass cls = getInitCanonTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class InitCanonType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.InitCanonType
			InitCanonType::~InitCanonType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewInitCanonTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/InitCanonType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/InitCanonType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass InitCanonTypeClass = NULL;
			static inline jclass getInitCanonTypeClass() {
			    if (InitCanonTypeClass != NULL) {
			        return InitCanonTypeClass;
			    }
			    InitCanonTypeClass = getNewInitCanonTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.MessageType
			static inline jclass getMessageTypeClass();
			
			MessageType::MessageType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			MessageType::MessageType() {
				JNIEnv *env =getEnv();
				jclass cls = getMessageTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class MessageType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.MessageType
			MessageType::~MessageType() {
				// Place-holder for later extensibility.
			}

			void MessageType::setMessage(jstring string_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setMessage of crcl.base.MessageType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMessageTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setMessage", "(Ljava/lang/String;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MessageType has no method named setMessage with signature (Ljava/lang/String;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,string_0 );
			            }
			        }
			        
			}
			jstring MessageType::getMessage() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getMessage of crcl.base.MessageType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMessageTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getMessage", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MessageType has no method named getMessage with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewMessageTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/MessageType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/MessageType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass MessageTypeClass = NULL;
			static inline jclass getMessageTypeClass() {
			    if (MessageTypeClass != NULL) {
			        return MessageTypeClass;
			    }
			    MessageTypeClass = getNewMessageTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.AngleUnitEnumType
			static inline jclass getAngleUnitEnumTypeClass();
			
			AngleUnitEnumType::AngleUnitEnumType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for crcl.base.AngleUnitEnumType
			AngleUnitEnumType::~AngleUnitEnumType() {
				// Place-holder for later extensibility.
			}

			AngleUnitEnumType AngleUnitEnumType::fromValue(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getAngleUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "fromValue", "(Ljava/lang/String;)Lcrcl/base/AngleUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.AngleUnitEnumType has no method named fromValue with signature (Ljava/lang/String;)Lcrcl/base/AngleUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			jstring AngleUnitEnumType::value() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method value of crcl.base.AngleUnitEnumType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getAngleUnitEnumTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "value", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.AngleUnitEnumType has no method named value with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			AngleUnitEnumType AngleUnitEnumType::valueOf(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getAngleUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lcrcl/base/AngleUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.AngleUnitEnumType has no method named valueOf with signature (Ljava/lang/String;)Lcrcl/base/AngleUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			static jclass getNewAngleUnitEnumTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/AngleUnitEnumType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/AngleUnitEnumType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass AngleUnitEnumTypeClass = NULL;
			static inline jclass getAngleUnitEnumTypeClass() {
			    if (AngleUnitEnumTypeClass != NULL) {
			        return AngleUnitEnumTypeClass;
			    }
			    AngleUnitEnumTypeClass = getNewAngleUnitEnumTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetIntermediatePoseToleranceType
			static inline jclass getSetIntermediatePoseToleranceTypeClass();
			
			SetIntermediatePoseToleranceType::SetIntermediatePoseToleranceType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetIntermediatePoseToleranceType::SetIntermediatePoseToleranceType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetIntermediatePoseToleranceTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetIntermediatePoseToleranceType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetIntermediatePoseToleranceType
			SetIntermediatePoseToleranceType::~SetIntermediatePoseToleranceType() {
				// Place-holder for later extensibility.
			}

			PoseToleranceType SetIntermediatePoseToleranceType::getTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTolerance of crcl.base.SetIntermediatePoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetIntermediatePoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTolerance", "()Lcrcl/base/PoseToleranceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetIntermediatePoseToleranceType has no method named getTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseToleranceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetIntermediatePoseToleranceType::setTolerance(PoseToleranceType poseToleranceType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTolerance of crcl.base.SetIntermediatePoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetIntermediatePoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTolerance", "(Lcrcl/base/PoseToleranceType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetIntermediatePoseToleranceType has no method named setTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,poseToleranceType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetIntermediatePoseToleranceTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetIntermediatePoseToleranceType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetIntermediatePoseToleranceType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetIntermediatePoseToleranceTypeClass = NULL;
			static inline jclass getSetIntermediatePoseToleranceTypeClass() {
			    if (SetIntermediatePoseToleranceTypeClass != NULL) {
			        return SetIntermediatePoseToleranceTypeClass;
			    }
			    SetIntermediatePoseToleranceTypeClass = getNewSetIntermediatePoseToleranceTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TransAccelAbsoluteType
			static inline jclass getTransAccelAbsoluteTypeClass();
			
			TransAccelAbsoluteType::TransAccelAbsoluteType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			TransAccelAbsoluteType::TransAccelAbsoluteType() {
				JNIEnv *env =getEnv();
				jclass cls = getTransAccelAbsoluteTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class TransAccelAbsoluteType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.TransAccelAbsoluteType
			TransAccelAbsoluteType::~TransAccelAbsoluteType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal TransAccelAbsoluteType::getSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSetting of crcl.base.TransAccelAbsoluteType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransAccelAbsoluteTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransAccelAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void TransAccelAbsoluteType::setSetting(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSetting of crcl.base.TransAccelAbsoluteType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransAccelAbsoluteTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransAccelAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewTransAccelAbsoluteTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TransAccelAbsoluteType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TransAccelAbsoluteType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TransAccelAbsoluteTypeClass = NULL;
			static inline jclass getTransAccelAbsoluteTypeClass() {
			    if (TransAccelAbsoluteTypeClass != NULL) {
			        return TransAccelAbsoluteTypeClass;
			    }
			    TransAccelAbsoluteTypeClass = getNewTransAccelAbsoluteTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.StopMotionType
			static inline jclass getStopMotionTypeClass();
			
			StopMotionType::StopMotionType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			StopMotionType::StopMotionType() {
				JNIEnv *env =getEnv();
				jclass cls = getStopMotionTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class StopMotionType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.StopMotionType
			StopMotionType::~StopMotionType() {
				// Place-holder for later extensibility.
			}

			StopConditionEnumType StopMotionType::getStopCondition() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getStopCondition of crcl.base.StopMotionType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getStopMotionTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getStopCondition", "()Lcrcl/base/StopConditionEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.StopMotionType has no method named getStopCondition with signature ()Lcrcl/base/StopConditionEnumType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (StopConditionEnumType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void StopMotionType::setStopCondition(StopConditionEnumType stopConditionEnumType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setStopCondition of crcl.base.StopMotionType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getStopMotionTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setStopCondition", "(Lcrcl/base/StopConditionEnumType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.StopMotionType has no method named setStopCondition with signature (Lcrcl/base/StopConditionEnumType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,stopConditionEnumType_0 );
			            }
			        }
			        
			}
			static jclass getNewStopMotionTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/StopMotionType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/StopMotionType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass StopMotionTypeClass = NULL;
			static inline jclass getStopMotionTypeClass() {
			    if (StopMotionTypeClass != NULL) {
			        return StopMotionTypeClass;
			    }
			    StopMotionTypeClass = getNewStopMotionTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.VectorType
			static inline jclass getVectorTypeClass();
			
			VectorType::VectorType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			VectorType::VectorType() {
				JNIEnv *env =getEnv();
				jclass cls = getVectorTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class VectorType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.VectorType
			VectorType::~VectorType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal VectorType::getI() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getI of crcl.base.VectorType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVectorTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getI", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VectorType has no method named getI with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void VectorType::setI(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setI of crcl.base.VectorType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVectorTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setI", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VectorType has no method named setI with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal VectorType::getJ() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJ of crcl.base.VectorType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVectorTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJ", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VectorType has no method named getJ with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void VectorType::setJ(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJ of crcl.base.VectorType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVectorTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJ", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VectorType has no method named setJ with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal VectorType::getK() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getK of crcl.base.VectorType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVectorTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getK", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VectorType has no method named getK with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void VectorType::setK(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setK of crcl.base.VectorType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVectorTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setK", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VectorType has no method named setK with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewVectorTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/VectorType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/VectorType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass VectorTypeClass = NULL;
			static inline jclass getVectorTypeClass() {
			    if (VectorTypeClass != NULL) {
			        return VectorTypeClass;
			    }
			    VectorTypeClass = getNewVectorTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetEndEffectorType
			static inline jclass getSetEndEffectorTypeClass();
			
			SetEndEffectorType::SetEndEffectorType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetEndEffectorType::SetEndEffectorType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetEndEffectorTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetEndEffectorType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetEndEffectorType
			SetEndEffectorType::~SetEndEffectorType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal SetEndEffectorType::getSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSetting of crcl.base.SetEndEffectorType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetEndEffectorTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetEndEffectorType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetEndEffectorType::setSetting(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSetting of crcl.base.SetEndEffectorType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetEndEffectorTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetEndEffectorType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewSetEndEffectorTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetEndEffectorType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetEndEffectorType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetEndEffectorTypeClass = NULL;
			static inline jclass getSetEndEffectorTypeClass() {
			    if (SetEndEffectorTypeClass != NULL) {
			        return SetEndEffectorTypeClass;
			    }
			    SetEndEffectorTypeClass = getNewSetEndEffectorTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CloseToolChangerType
			static inline jclass getCloseToolChangerTypeClass();
			
			CloseToolChangerType::CloseToolChangerType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			CloseToolChangerType::CloseToolChangerType() {
				JNIEnv *env =getEnv();
				jclass cls = getCloseToolChangerTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class CloseToolChangerType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.CloseToolChangerType
			CloseToolChangerType::~CloseToolChangerType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewCloseToolChangerTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CloseToolChangerType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CloseToolChangerType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CloseToolChangerTypeClass = NULL;
			static inline jclass getCloseToolChangerTypeClass() {
			    if (CloseToolChangerTypeClass != NULL) {
			        return CloseToolChangerTypeClass;
			    }
			    CloseToolChangerTypeClass = getNewCloseToolChangerTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ForceUnitEnumType
			static inline jclass getForceUnitEnumTypeClass();
			
			ForceUnitEnumType::ForceUnitEnumType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for crcl.base.ForceUnitEnumType
			ForceUnitEnumType::~ForceUnitEnumType() {
				// Place-holder for later extensibility.
			}

			ForceUnitEnumType ForceUnitEnumType::fromValue(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getForceUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "fromValue", "(Ljava/lang/String;)Lcrcl/base/ForceUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ForceUnitEnumType has no method named fromValue with signature (Ljava/lang/String;)Lcrcl/base/ForceUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			jstring ForceUnitEnumType::value() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method value of crcl.base.ForceUnitEnumType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getForceUnitEnumTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "value", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ForceUnitEnumType has no method named value with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ForceUnitEnumType ForceUnitEnumType::valueOf(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getForceUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lcrcl/base/ForceUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ForceUnitEnumType has no method named valueOf with signature (Ljava/lang/String;)Lcrcl/base/ForceUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			static jclass getNewForceUnitEnumTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ForceUnitEnumType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ForceUnitEnumType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ForceUnitEnumTypeClass = NULL;
			static inline jclass getForceUnitEnumTypeClass() {
			    if (ForceUnitEnumTypeClass != NULL) {
			        return ForceUnitEnumTypeClass;
			    }
			    ForceUnitEnumTypeClass = getNewForceUnitEnumTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TorqueUnitEnumType
			static inline jclass getTorqueUnitEnumTypeClass();
			
			TorqueUnitEnumType::TorqueUnitEnumType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for crcl.base.TorqueUnitEnumType
			TorqueUnitEnumType::~TorqueUnitEnumType() {
				// Place-holder for later extensibility.
			}

			TorqueUnitEnumType TorqueUnitEnumType::fromValue(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getTorqueUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "fromValue", "(Ljava/lang/String;)Lcrcl/base/TorqueUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TorqueUnitEnumType has no method named fromValue with signature (Ljava/lang/String;)Lcrcl/base/TorqueUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			jstring TorqueUnitEnumType::value() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method value of crcl.base.TorqueUnitEnumType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTorqueUnitEnumTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "value", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TorqueUnitEnumType has no method named value with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			TorqueUnitEnumType TorqueUnitEnumType::valueOf(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getTorqueUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lcrcl/base/TorqueUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TorqueUnitEnumType has no method named valueOf with signature (Ljava/lang/String;)Lcrcl/base/TorqueUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			static jclass getNewTorqueUnitEnumTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TorqueUnitEnumType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TorqueUnitEnumType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TorqueUnitEnumTypeClass = NULL;
			static inline jclass getTorqueUnitEnumTypeClass() {
			    if (TorqueUnitEnumTypeClass != NULL) {
			        return TorqueUnitEnumTypeClass;
			    }
			    TorqueUnitEnumTypeClass = getNewTorqueUnitEnumTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ConfigureJointReportsType
			static inline jclass getConfigureJointReportsTypeClass();
			
			ConfigureJointReportsType::ConfigureJointReportsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ConfigureJointReportsType::ConfigureJointReportsType() {
				JNIEnv *env =getEnv();
				jclass cls = getConfigureJointReportsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ConfigureJointReportsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ConfigureJointReportsType
			ConfigureJointReportsType::~ConfigureJointReportsType() {
				// Place-holder for later extensibility.
			}

			jboolean ConfigureJointReportsType::isResetAll() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isResetAll of crcl.base.ConfigureJointReportsType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportsTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isResetAll", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportsType has no method named isResetAll with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ConfigureJointReportsType::setResetAll(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setResetAll of crcl.base.ConfigureJointReportsType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportsTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setResetAll", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportsType has no method named setResetAll with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			java::util::List ConfigureJointReportsType::getConfigureJointReport() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getConfigureJointReport of crcl.base.ConfigureJointReportsType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportsTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getConfigureJointReport", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportsType has no method named getConfigureJointReport with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewConfigureJointReportsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ConfigureJointReportsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ConfigureJointReportsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ConfigureJointReportsTypeClass = NULL;
			static inline jclass getConfigureJointReportsTypeClass() {
			    if (ConfigureJointReportsTypeClass != NULL) {
			        return ConfigureJointReportsTypeClass;
			    }
			    ConfigureJointReportsTypeClass = getNewConfigureJointReportsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CRCLCommandInstanceType
			static inline jclass getCRCLCommandInstanceTypeClass();
			
			CRCLCommandInstanceType::CRCLCommandInstanceType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			CRCLCommandInstanceType::CRCLCommandInstanceType() {
				JNIEnv *env =getEnv();
				jclass cls = getCRCLCommandInstanceTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class CRCLCommandInstanceType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.CRCLCommandInstanceType
			CRCLCommandInstanceType::~CRCLCommandInstanceType() {
				// Place-holder for later extensibility.
			}

			CRCLCommandType CRCLCommandInstanceType::getCRCLCommand() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getCRCLCommand of crcl.base.CRCLCommandInstanceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLCommandInstanceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getCRCLCommand", "()Lcrcl/base/CRCLCommandType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLCommandInstanceType has no method named getCRCLCommand with signature ()Lcrcl/base/CRCLCommandType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CRCLCommandType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLCommandInstanceType::setCRCLCommand(CRCLCommandType cRCLCommandType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCRCLCommand of crcl.base.CRCLCommandInstanceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLCommandInstanceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCRCLCommand", "(Lcrcl/base/CRCLCommandType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLCommandInstanceType has no method named setCRCLCommand with signature (Lcrcl/base/CRCLCommandType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,cRCLCommandType_0 );
			            }
			        }
			        
			}
			static jclass getNewCRCLCommandInstanceTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CRCLCommandInstanceType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CRCLCommandInstanceType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CRCLCommandInstanceTypeClass = NULL;
			static inline jclass getCRCLCommandInstanceTypeClass() {
			    if (CRCLCommandInstanceTypeClass != NULL) {
			        return CRCLCommandInstanceTypeClass;
			    }
			    CRCLCommandInstanceTypeClass = getNewCRCLCommandInstanceTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetRotSpeedType
			static inline jclass getSetRotSpeedTypeClass();
			
			SetRotSpeedType::SetRotSpeedType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetRotSpeedType::SetRotSpeedType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetRotSpeedTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetRotSpeedType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetRotSpeedType
			SetRotSpeedType::~SetRotSpeedType() {
				// Place-holder for later extensibility.
			}

			RotSpeedType SetRotSpeedType::getRotSpeed() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getRotSpeed of crcl.base.SetRotSpeedType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetRotSpeedTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getRotSpeed", "()Lcrcl/base/RotSpeedType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetRotSpeedType has no method named getRotSpeed with signature ()Lcrcl/base/RotSpeedType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotSpeedType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetRotSpeedType::setRotSpeed(RotSpeedType rotSpeedType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setRotSpeed of crcl.base.SetRotSpeedType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetRotSpeedTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setRotSpeed", "(Lcrcl/base/RotSpeedType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetRotSpeedType has no method named setRotSpeed with signature (Lcrcl/base/RotSpeedType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,rotSpeedType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetRotSpeedTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetRotSpeedType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetRotSpeedType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetRotSpeedTypeClass = NULL;
			static inline jclass getSetRotSpeedTypeClass() {
			    if (SetRotSpeedTypeClass != NULL) {
			        return SetRotSpeedTypeClass;
			    }
			    SetRotSpeedTypeClass = getNewSetRotSpeedTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetTorqueUnitsType
			static inline jclass getSetTorqueUnitsTypeClass();
			
			SetTorqueUnitsType::SetTorqueUnitsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetTorqueUnitsType::SetTorqueUnitsType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetTorqueUnitsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetTorqueUnitsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetTorqueUnitsType
			SetTorqueUnitsType::~SetTorqueUnitsType() {
				// Place-holder for later extensibility.
			}

			TorqueUnitEnumType SetTorqueUnitsType::getUnitName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getUnitName of crcl.base.SetTorqueUnitsType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetTorqueUnitsTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getUnitName", "()Lcrcl/base/TorqueUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetTorqueUnitsType has no method named getUnitName with signature ()Lcrcl/base/TorqueUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TorqueUnitEnumType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetTorqueUnitsType::setUnitName(TorqueUnitEnumType torqueUnitEnumType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setUnitName of crcl.base.SetTorqueUnitsType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetTorqueUnitsTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setUnitName", "(Lcrcl/base/TorqueUnitEnumType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetTorqueUnitsType has no method named setUnitName with signature (Lcrcl/base/TorqueUnitEnumType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,torqueUnitEnumType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetTorqueUnitsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetTorqueUnitsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetTorqueUnitsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetTorqueUnitsTypeClass = NULL;
			static inline jclass getSetTorqueUnitsTypeClass() {
			    if (SetTorqueUnitsTypeClass != NULL) {
			        return SetTorqueUnitsTypeClass;
			    }
			    SetTorqueUnitsTypeClass = getNewSetTorqueUnitsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ConfigureJointReportType
			static inline jclass getConfigureJointReportTypeClass();
			
			ConfigureJointReportType::ConfigureJointReportType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ConfigureJointReportType::ConfigureJointReportType() {
				JNIEnv *env =getEnv();
				jclass cls = getConfigureJointReportTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ConfigureJointReportType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ConfigureJointReportType
			ConfigureJointReportType::~ConfigureJointReportType() {
				// Place-holder for later extensibility.
			}

			java::math::BigInteger ConfigureJointReportType::getJointNumber() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointNumber of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointNumber", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named getJointNumber with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ConfigureJointReportType::setJointNumber(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointNumber of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointNumber", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named setJointNumber with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			jboolean ConfigureJointReportType::isReportPosition() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isReportPosition of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isReportPosition", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named isReportPosition with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ConfigureJointReportType::setReportPosition(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setReportPosition of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setReportPosition", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named setReportPosition with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			jboolean ConfigureJointReportType::isReportTorqueOrForce() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isReportTorqueOrForce of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isReportTorqueOrForce", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named isReportTorqueOrForce with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ConfigureJointReportType::setReportTorqueOrForce(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setReportTorqueOrForce of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setReportTorqueOrForce", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named setReportTorqueOrForce with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			jboolean ConfigureJointReportType::isReportVelocity() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isReportVelocity of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isReportVelocity", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named isReportVelocity with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ConfigureJointReportType::setReportVelocity(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setReportVelocity of crcl.base.ConfigureJointReportType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getConfigureJointReportTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setReportVelocity", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ConfigureJointReportType has no method named setReportVelocity with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			static jclass getNewConfigureJointReportTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ConfigureJointReportType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ConfigureJointReportType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ConfigureJointReportTypeClass = NULL;
			static inline jclass getConfigureJointReportTypeClass() {
			    if (ConfigureJointReportTypeClass != NULL) {
			        return ConfigureJointReportTypeClass;
			    }
			    ConfigureJointReportTypeClass = getNewConfigureJointReportTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetEndPoseToleranceType
			static inline jclass getSetEndPoseToleranceTypeClass();
			
			SetEndPoseToleranceType::SetEndPoseToleranceType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetEndPoseToleranceType::SetEndPoseToleranceType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetEndPoseToleranceTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetEndPoseToleranceType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetEndPoseToleranceType
			SetEndPoseToleranceType::~SetEndPoseToleranceType() {
				// Place-holder for later extensibility.
			}

			PoseToleranceType SetEndPoseToleranceType::getTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTolerance of crcl.base.SetEndPoseToleranceType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetEndPoseToleranceTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTolerance", "()Lcrcl/base/PoseToleranceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetEndPoseToleranceType has no method named getTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseToleranceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetEndPoseToleranceType::setTolerance(PoseToleranceType poseToleranceType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTolerance of crcl.base.SetEndPoseToleranceType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetEndPoseToleranceTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTolerance", "(Lcrcl/base/PoseToleranceType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetEndPoseToleranceType has no method named setTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,poseToleranceType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetEndPoseToleranceTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetEndPoseToleranceType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetEndPoseToleranceType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetEndPoseToleranceTypeClass = NULL;
			static inline jclass getSetEndPoseToleranceTypeClass() {
			    if (SetEndPoseToleranceTypeClass != NULL) {
			        return SetEndPoseToleranceTypeClass;
			    }
			    SetEndPoseToleranceTypeClass = getNewSetEndPoseToleranceTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ParameterSettingType
			static inline jclass getParameterSettingTypeClass();
			
			ParameterSettingType::ParameterSettingType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ParameterSettingType::ParameterSettingType() {
				JNIEnv *env =getEnv();
				jclass cls = getParameterSettingTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ParameterSettingType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ParameterSettingType
			ParameterSettingType::~ParameterSettingType() {
				// Place-holder for later extensibility.
			}

			jstring ParameterSettingType::getParameterName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getParameterName of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getParameterSettingTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getParameterName", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ParameterSettingType has no method named getParameterName with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ParameterSettingType::setParameterName(jstring string_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setParameterName of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getParameterSettingTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setParameterName", "(Ljava/lang/String;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ParameterSettingType has no method named setParameterName with signature (Ljava/lang/String;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,string_0 );
			            }
			        }
			        
			}
			jstring ParameterSettingType::getParameterValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getParameterValue of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getParameterSettingTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getParameterValue", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ParameterSettingType has no method named getParameterValue with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ParameterSettingType::setParameterValue(jstring string_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setParameterValue of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getParameterSettingTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setParameterValue", "(Ljava/lang/String;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ParameterSettingType has no method named setParameterValue with signature (Ljava/lang/String;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,string_0 );
			            }
			        }
			        
			}
			static jclass getNewParameterSettingTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ParameterSettingType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ParameterSettingType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ParameterSettingTypeClass = NULL;
			static inline jclass getParameterSettingTypeClass() {
			    if (ParameterSettingTypeClass != NULL) {
			        return ParameterSettingTypeClass;
			    }
			    ParameterSettingTypeClass = getNewParameterSettingTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetTransSpeedType
			static inline jclass getSetTransSpeedTypeClass();
			
			SetTransSpeedType::SetTransSpeedType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetTransSpeedType::SetTransSpeedType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetTransSpeedTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetTransSpeedType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetTransSpeedType
			SetTransSpeedType::~SetTransSpeedType() {
				// Place-holder for later extensibility.
			}

			TransSpeedType SetTransSpeedType::getTransSpeed() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTransSpeed of crcl.base.SetTransSpeedType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetTransSpeedTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTransSpeed", "()Lcrcl/base/TransSpeedType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetTransSpeedType has no method named getTransSpeed with signature ()Lcrcl/base/TransSpeedType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransSpeedType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetTransSpeedType::setTransSpeed(TransSpeedType transSpeedType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTransSpeed of crcl.base.SetTransSpeedType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetTransSpeedTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTransSpeed", "(Lcrcl/base/TransSpeedType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetTransSpeedType has no method named setTransSpeed with signature (Lcrcl/base/TransSpeedType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,transSpeedType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetTransSpeedTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetTransSpeedType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetTransSpeedType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetTransSpeedTypeClass = NULL;
			static inline jclass getSetTransSpeedTypeClass() {
			    if (SetTransSpeedTypeClass != NULL) {
			        return SetTransSpeedTypeClass;
			    }
			    SetTransSpeedTypeClass = getNewSetTransSpeedTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.JointStatusesType
			static inline jclass getJointStatusesTypeClass();
			
			JointStatusesType::JointStatusesType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			JointStatusesType::JointStatusesType() {
				JNIEnv *env =getEnv();
				jclass cls = getJointStatusesTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class JointStatusesType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.JointStatusesType
			JointStatusesType::~JointStatusesType() {
				// Place-holder for later extensibility.
			}

			java::util::List JointStatusesType::getJointStatus() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointStatus of crcl.base.JointStatusesType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusesTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointStatus", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusesType has no method named getJointStatus with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewJointStatusesTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/JointStatusesType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/JointStatusesType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass JointStatusesTypeClass = NULL;
			static inline jclass getJointStatusesTypeClass() {
			    if (JointStatusesTypeClass != NULL) {
			        return JointStatusesTypeClass;
			    }
			    JointStatusesTypeClass = getNewJointStatusesTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ParallelGripperStatusType
			static inline jclass getParallelGripperStatusTypeClass();
			
			ParallelGripperStatusType::ParallelGripperStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ParallelGripperStatusType::ParallelGripperStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getParallelGripperStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ParallelGripperStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ParallelGripperStatusType
			ParallelGripperStatusType::~ParallelGripperStatusType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal ParallelGripperStatusType::getSeparation() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSeparation of crcl.base.ParallelGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getParallelGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSeparation", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ParallelGripperStatusType has no method named getSeparation with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ParallelGripperStatusType::setSeparation(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSeparation of crcl.base.ParallelGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getParallelGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSeparation", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ParallelGripperStatusType has no method named setSeparation with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewParallelGripperStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ParallelGripperStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ParallelGripperStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ParallelGripperStatusTypeClass = NULL;
			static inline jclass getParallelGripperStatusTypeClass() {
			    if (ParallelGripperStatusTypeClass != NULL) {
			        return ParallelGripperStatusTypeClass;
			    }
			    ParallelGripperStatusTypeClass = getNewParallelGripperStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.LengthUnitEnumType
			static inline jclass getLengthUnitEnumTypeClass();
			
			LengthUnitEnumType::LengthUnitEnumType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for crcl.base.LengthUnitEnumType
			LengthUnitEnumType::~LengthUnitEnumType() {
				// Place-holder for later extensibility.
			}

			LengthUnitEnumType LengthUnitEnumType::fromValue(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getLengthUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "fromValue", "(Ljava/lang/String;)Lcrcl/base/LengthUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.LengthUnitEnumType has no method named fromValue with signature (Ljava/lang/String;)Lcrcl/base/LengthUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			jstring LengthUnitEnumType::value() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method value of crcl.base.LengthUnitEnumType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getLengthUnitEnumTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "value", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.LengthUnitEnumType has no method named value with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			LengthUnitEnumType LengthUnitEnumType::valueOf(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getLengthUnitEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lcrcl/base/LengthUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.LengthUnitEnumType has no method named valueOf with signature (Ljava/lang/String;)Lcrcl/base/LengthUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			static jclass getNewLengthUnitEnumTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/LengthUnitEnumType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/LengthUnitEnumType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass LengthUnitEnumTypeClass = NULL;
			static inline jclass getLengthUnitEnumTypeClass() {
			    if (LengthUnitEnumTypeClass != NULL) {
			        return LengthUnitEnumTypeClass;
			    }
			    LengthUnitEnumTypeClass = getNewLengthUnitEnumTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetRotAccelType
			static inline jclass getSetRotAccelTypeClass();
			
			SetRotAccelType::SetRotAccelType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetRotAccelType::SetRotAccelType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetRotAccelTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetRotAccelType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetRotAccelType
			SetRotAccelType::~SetRotAccelType() {
				// Place-holder for later extensibility.
			}

			RotAccelType SetRotAccelType::getRotAccel() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getRotAccel of crcl.base.SetRotAccelType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetRotAccelTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getRotAccel", "()Lcrcl/base/RotAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetRotAccelType has no method named getRotAccel with signature ()Lcrcl/base/RotAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetRotAccelType::setRotAccel(RotAccelType rotAccelType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setRotAccel of crcl.base.SetRotAccelType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetRotAccelTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setRotAccel", "(Lcrcl/base/RotAccelType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetRotAccelType has no method named setRotAccel with signature (Lcrcl/base/RotAccelType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,rotAccelType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetRotAccelTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetRotAccelType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetRotAccelType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetRotAccelTypeClass = NULL;
			static inline jclass getSetRotAccelTypeClass() {
			    if (SetRotAccelTypeClass != NULL) {
			        return SetRotAccelTypeClass;
			    }
			    SetRotAccelTypeClass = getNewSetRotAccelTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetAngleUnitsType
			static inline jclass getSetAngleUnitsTypeClass();
			
			SetAngleUnitsType::SetAngleUnitsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetAngleUnitsType::SetAngleUnitsType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetAngleUnitsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetAngleUnitsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetAngleUnitsType
			SetAngleUnitsType::~SetAngleUnitsType() {
				// Place-holder for later extensibility.
			}

			AngleUnitEnumType SetAngleUnitsType::getUnitName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getUnitName of crcl.base.SetAngleUnitsType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetAngleUnitsTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getUnitName", "()Lcrcl/base/AngleUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetAngleUnitsType has no method named getUnitName with signature ()Lcrcl/base/AngleUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (AngleUnitEnumType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetAngleUnitsType::setUnitName(AngleUnitEnumType angleUnitEnumType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setUnitName of crcl.base.SetAngleUnitsType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetAngleUnitsTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setUnitName", "(Lcrcl/base/AngleUnitEnumType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetAngleUnitsType has no method named setUnitName with signature (Lcrcl/base/AngleUnitEnumType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,angleUnitEnumType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetAngleUnitsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetAngleUnitsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetAngleUnitsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetAngleUnitsTypeClass = NULL;
			static inline jclass getSetAngleUnitsTypeClass() {
			    if (SetAngleUnitsTypeClass != NULL) {
			        return SetAngleUnitsTypeClass;
			    }
			    SetAngleUnitsTypeClass = getNewSetAngleUnitsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CommandStatusType
			static inline jclass getCommandStatusTypeClass();
			
			CommandStatusType::CommandStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			CommandStatusType::CommandStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getCommandStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class CommandStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.CommandStatusType
			CommandStatusType::~CommandStatusType() {
				// Place-holder for later extensibility.
			}

			java::math::BigInteger CommandStatusType::getCommandID() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getCommandID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getCommandID", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStatusType has no method named getCommandID with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CommandStatusType::setCommandID(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCommandID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCommandID", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStatusType has no method named setCommandID with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			java::math::BigInteger CommandStatusType::getStatusID() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getStatusID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getStatusID", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStatusType has no method named getStatusID with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CommandStatusType::setStatusID(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setStatusID of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setStatusID", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStatusType has no method named setStatusID with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			CommandStateEnumType CommandStatusType::getCommandState() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getCommandState of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getCommandState", "()Lcrcl/base/CommandStateEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStatusType has no method named getCommandState with signature ()Lcrcl/base/CommandStateEnumType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CommandStateEnumType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CommandStatusType::setCommandState(CommandStateEnumType commandStateEnumType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCommandState of crcl.base.CommandStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCommandState", "(Lcrcl/base/CommandStateEnumType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStatusType has no method named setCommandState with signature (Lcrcl/base/CommandStateEnumType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,commandStateEnumType_0 );
			            }
			        }
			        
			}
			static jclass getNewCommandStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CommandStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CommandStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CommandStatusTypeClass = NULL;
			static inline jclass getCommandStatusTypeClass() {
			    if (CommandStatusTypeClass != NULL) {
			        return CommandStatusTypeClass;
			    }
			    CommandStatusTypeClass = getNewCommandStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TransSpeedRelativeType
			static inline jclass getTransSpeedRelativeTypeClass();
			
			TransSpeedRelativeType::TransSpeedRelativeType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			TransSpeedRelativeType::TransSpeedRelativeType() {
				JNIEnv *env =getEnv();
				jclass cls = getTransSpeedRelativeTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class TransSpeedRelativeType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.TransSpeedRelativeType
			TransSpeedRelativeType::~TransSpeedRelativeType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal TransSpeedRelativeType::getFraction() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFraction of crcl.base.TransSpeedRelativeType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransSpeedRelativeTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransSpeedRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void TransSpeedRelativeType::setFraction(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFraction of crcl.base.TransSpeedRelativeType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransSpeedRelativeTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransSpeedRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewTransSpeedRelativeTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TransSpeedRelativeType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TransSpeedRelativeType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TransSpeedRelativeTypeClass = NULL;
			static inline jclass getTransSpeedRelativeTypeClass() {
			    if (TransSpeedRelativeTypeClass != NULL) {
			        return TransSpeedRelativeTypeClass;
			    }
			    TransSpeedRelativeTypeClass = getNewTransSpeedRelativeTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetForceUnitsType
			static inline jclass getSetForceUnitsTypeClass();
			
			SetForceUnitsType::SetForceUnitsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetForceUnitsType::SetForceUnitsType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetForceUnitsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetForceUnitsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetForceUnitsType
			SetForceUnitsType::~SetForceUnitsType() {
				// Place-holder for later extensibility.
			}

			ForceUnitEnumType SetForceUnitsType::getUnitName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getUnitName of crcl.base.SetForceUnitsType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetForceUnitsTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getUnitName", "()Lcrcl/base/ForceUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetForceUnitsType has no method named getUnitName with signature ()Lcrcl/base/ForceUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ForceUnitEnumType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetForceUnitsType::setUnitName(ForceUnitEnumType forceUnitEnumType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setUnitName of crcl.base.SetForceUnitsType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetForceUnitsTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setUnitName", "(Lcrcl/base/ForceUnitEnumType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetForceUnitsType has no method named setUnitName with signature (Lcrcl/base/ForceUnitEnumType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,forceUnitEnumType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetForceUnitsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetForceUnitsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetForceUnitsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetForceUnitsTypeClass = NULL;
			static inline jclass getSetForceUnitsTypeClass() {
			    if (SetForceUnitsTypeClass != NULL) {
			        return SetForceUnitsTypeClass;
			    }
			    SetForceUnitsTypeClass = getNewSetForceUnitsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.JointStatusType
			static inline jclass getJointStatusTypeClass();
			
			JointStatusType::JointStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			JointStatusType::JointStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getJointStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class JointStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.JointStatusType
			JointStatusType::~JointStatusType() {
				// Place-holder for later extensibility.
			}

			java::math::BigInteger JointStatusType::getJointNumber() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointNumber of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointNumber", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named getJointNumber with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointStatusType::setJointNumber(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointNumber of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointNumber", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named setJointNumber with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal JointStatusType::getJointPosition() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointPosition of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointPosition", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named getJointPosition with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointStatusType::setJointPosition(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointPosition of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointPosition", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named setJointPosition with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal JointStatusType::getJointTorqueOrForce() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointTorqueOrForce of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointTorqueOrForce", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named getJointTorqueOrForce with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointStatusType::setJointTorqueOrForce(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointTorqueOrForce of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointTorqueOrForce", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named setJointTorqueOrForce with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal JointStatusType::getJointVelocity() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointVelocity of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointVelocity", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named getJointVelocity with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointStatusType::setJointVelocity(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointVelocity of crcl.base.JointStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointVelocity", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointStatusType has no method named setJointVelocity with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewJointStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/JointStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/JointStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass JointStatusTypeClass = NULL;
			static inline jclass getJointStatusTypeClass() {
			    if (JointStatusTypeClass != NULL) {
			        return JointStatusTypeClass;
			    }
			    JointStatusTypeClass = getNewJointStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.VacuumGripperStatusType
			static inline jclass getVacuumGripperStatusTypeClass();
			
			VacuumGripperStatusType::VacuumGripperStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			VacuumGripperStatusType::VacuumGripperStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getVacuumGripperStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class VacuumGripperStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.VacuumGripperStatusType
			VacuumGripperStatusType::~VacuumGripperStatusType() {
				// Place-holder for later extensibility.
			}

			jboolean VacuumGripperStatusType::isIsPowered() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isIsPowered of crcl.base.VacuumGripperStatusType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVacuumGripperStatusTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isIsPowered", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VacuumGripperStatusType has no method named isIsPowered with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void VacuumGripperStatusType::setIsPowered(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setIsPowered of crcl.base.VacuumGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getVacuumGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setIsPowered", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.VacuumGripperStatusType has no method named setIsPowered with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			static jclass getNewVacuumGripperStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/VacuumGripperStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/VacuumGripperStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass VacuumGripperStatusTypeClass = NULL;
			static inline jclass getVacuumGripperStatusTypeClass() {
			    if (VacuumGripperStatusTypeClass != NULL) {
			        return VacuumGripperStatusTypeClass;
			    }
			    VacuumGripperStatusTypeClass = getNewVacuumGripperStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetEndEffectorParametersType
			static inline jclass getSetEndEffectorParametersTypeClass();
			
			SetEndEffectorParametersType::SetEndEffectorParametersType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetEndEffectorParametersType::SetEndEffectorParametersType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetEndEffectorParametersTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetEndEffectorParametersType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetEndEffectorParametersType
			SetEndEffectorParametersType::~SetEndEffectorParametersType() {
				// Place-holder for later extensibility.
			}

			java::util::List SetEndEffectorParametersType::getParameterSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getParameterSetting of crcl.base.SetEndEffectorParametersType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetEndEffectorParametersTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getParameterSetting", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetEndEffectorParametersType has no method named getParameterSetting with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewSetEndEffectorParametersTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetEndEffectorParametersType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetEndEffectorParametersType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetEndEffectorParametersTypeClass = NULL;
			static inline jclass getSetEndEffectorParametersTypeClass() {
			    if (SetEndEffectorParametersTypeClass != NULL) {
			        return SetEndEffectorParametersTypeClass;
			    }
			    SetEndEffectorParametersTypeClass = getNewSetEndEffectorParametersTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.EndCanonType
			static inline jclass getEndCanonTypeClass();
			
			EndCanonType::EndCanonType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			EndCanonType::EndCanonType() {
				JNIEnv *env =getEnv();
				jclass cls = getEndCanonTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class EndCanonType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.EndCanonType
			EndCanonType::~EndCanonType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewEndCanonTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/EndCanonType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/EndCanonType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass EndCanonTypeClass = NULL;
			static inline jclass getEndCanonTypeClass() {
			    if (EndCanonTypeClass != NULL) {
			        return EndCanonTypeClass;
			    }
			    EndCanonTypeClass = getNewEndCanonTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CRCLStatusType
			static inline jclass getCRCLStatusTypeClass();
			
			CRCLStatusType::CRCLStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			CRCLStatusType::CRCLStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getCRCLStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class CRCLStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.CRCLStatusType
			CRCLStatusType::~CRCLStatusType() {
				// Place-holder for later extensibility.
			}

			CommandStatusType CRCLStatusType::getCommandStatus() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getCommandStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getCommandStatus", "()Lcrcl/base/CommandStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named getCommandStatus with signature ()Lcrcl/base/CommandStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CommandStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLStatusType::setCommandStatus(CommandStatusType commandStatusType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCommandStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCommandStatus", "(Lcrcl/base/CommandStatusType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named setCommandStatus with signature (Lcrcl/base/CommandStatusType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,commandStatusType_0 );
			            }
			        }
			        
			}
			JointStatusesType CRCLStatusType::getJointStatuses() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointStatuses of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointStatuses", "()Lcrcl/base/JointStatusesType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named getJointStatuses with signature ()Lcrcl/base/JointStatusesType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (JointStatusesType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLStatusType::setJointStatuses(JointStatusesType jointStatusesType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointStatuses of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointStatuses", "(Lcrcl/base/JointStatusesType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named setJointStatuses with signature (Lcrcl/base/JointStatusesType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,jointStatusesType_0 );
			            }
			        }
			        
			}
			PoseType CRCLStatusType::getPose() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getPose of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getPose", "()Lcrcl/base/PoseType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named getPose with signature ()Lcrcl/base/PoseType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLStatusType::setPose(PoseType poseType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setPose of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setPose", "(Lcrcl/base/PoseType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named setPose with signature (Lcrcl/base/PoseType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,poseType_0 );
			            }
			        }
			        
			}
			GripperStatusType CRCLStatusType::getGripperStatus() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getGripperStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getGripperStatus", "()Lcrcl/base/GripperStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named getGripperStatus with signature ()Lcrcl/base/GripperStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (GripperStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void CRCLStatusType::setGripperStatus(GripperStatusType gripperStatusType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setGripperStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCRCLStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setGripperStatus", "(Lcrcl/base/GripperStatusType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CRCLStatusType has no method named setGripperStatus with signature (Lcrcl/base/GripperStatusType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,gripperStatusType_0 );
			            }
			        }
			        
			}
			static jclass getNewCRCLStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CRCLStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CRCLStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CRCLStatusTypeClass = NULL;
			static inline jclass getCRCLStatusTypeClass() {
			    if (CRCLStatusTypeClass != NULL) {
			        return CRCLStatusTypeClass;
			    }
			    CRCLStatusTypeClass = getNewCRCLStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RotSpeedRelativeType
			static inline jclass getRotSpeedRelativeTypeClass();
			
			RotSpeedRelativeType::RotSpeedRelativeType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RotSpeedRelativeType::RotSpeedRelativeType() {
				JNIEnv *env =getEnv();
				jclass cls = getRotSpeedRelativeTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RotSpeedRelativeType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RotSpeedRelativeType
			RotSpeedRelativeType::~RotSpeedRelativeType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal RotSpeedRelativeType::getFraction() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFraction of crcl.base.RotSpeedRelativeType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotSpeedRelativeTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotSpeedRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void RotSpeedRelativeType::setFraction(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFraction of crcl.base.RotSpeedRelativeType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotSpeedRelativeTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotSpeedRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewRotSpeedRelativeTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RotSpeedRelativeType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RotSpeedRelativeType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RotSpeedRelativeTypeClass = NULL;
			static inline jclass getRotSpeedRelativeTypeClass() {
			    if (RotSpeedRelativeTypeClass != NULL) {
			        return RotSpeedRelativeTypeClass;
			    }
			    RotSpeedRelativeTypeClass = getNewRotSpeedRelativeTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RunProgramType
			static inline jclass getRunProgramTypeClass();
			
			RunProgramType::RunProgramType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RunProgramType::RunProgramType() {
				JNIEnv *env =getEnv();
				jclass cls = getRunProgramTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RunProgramType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RunProgramType
			RunProgramType::~RunProgramType() {
				// Place-holder for later extensibility.
			}

			jstring RunProgramType::getProgramText() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getProgramText of crcl.base.RunProgramType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRunProgramTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getProgramText", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RunProgramType has no method named getProgramText with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void RunProgramType::setProgramText(jstring string_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setProgramText of crcl.base.RunProgramType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRunProgramTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setProgramText", "(Ljava/lang/String;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RunProgramType has no method named setProgramText with signature (Ljava/lang/String;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,string_0 );
			            }
			        }
			        
			}
			static jclass getNewRunProgramTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RunProgramType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RunProgramType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RunProgramTypeClass = NULL;
			static inline jclass getRunProgramTypeClass() {
			    if (RunProgramTypeClass != NULL) {
			        return RunProgramTypeClass;
			    }
			    RunProgramTypeClass = getNewRunProgramTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RotAccelRelativeType
			static inline jclass getRotAccelRelativeTypeClass();
			
			RotAccelRelativeType::RotAccelRelativeType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RotAccelRelativeType::RotAccelRelativeType() {
				JNIEnv *env =getEnv();
				jclass cls = getRotAccelRelativeTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RotAccelRelativeType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RotAccelRelativeType
			RotAccelRelativeType::~RotAccelRelativeType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal RotAccelRelativeType::getFraction() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFraction of crcl.base.RotAccelRelativeType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotAccelRelativeTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotAccelRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void RotAccelRelativeType::setFraction(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFraction of crcl.base.RotAccelRelativeType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotAccelRelativeTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotAccelRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewRotAccelRelativeTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RotAccelRelativeType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RotAccelRelativeType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RotAccelRelativeTypeClass = NULL;
			static inline jclass getRotAccelRelativeTypeClass() {
			    if (RotAccelRelativeTypeClass != NULL) {
			        return RotAccelRelativeTypeClass;
			    }
			    RotAccelRelativeTypeClass = getNewRotAccelRelativeTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.MoveThroughToType
			static inline jclass getMoveThroughToTypeClass();
			
			MoveThroughToType::MoveThroughToType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			MoveThroughToType::MoveThroughToType() {
				JNIEnv *env =getEnv();
				jclass cls = getMoveThroughToTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class MoveThroughToType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.MoveThroughToType
			MoveThroughToType::~MoveThroughToType() {
				// Place-holder for later extensibility.
			}

			jboolean MoveThroughToType::isMoveStraight() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isMoveStraight of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveThroughToTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isMoveStraight", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveThroughToType has no method named isMoveStraight with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveThroughToType::setMoveStraight(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setMoveStraight of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveThroughToTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setMoveStraight", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveThroughToType has no method named setMoveStraight with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			java::util::List MoveThroughToType::getWaypoint() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getWaypoint of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveThroughToTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getWaypoint", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveThroughToType has no method named getWaypoint with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			java::math::BigInteger MoveThroughToType::getNumPositions() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getNumPositions of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveThroughToTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getNumPositions", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveThroughToType has no method named getNumPositions with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveThroughToType::setNumPositions(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setNumPositions of crcl.base.MoveThroughToType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveThroughToTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setNumPositions", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveThroughToType has no method named setNumPositions with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			static jclass getNewMoveThroughToTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/MoveThroughToType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/MoveThroughToType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass MoveThroughToTypeClass = NULL;
			static inline jclass getMoveThroughToTypeClass() {
			    if (MoveThroughToTypeClass != NULL) {
			        return MoveThroughToTypeClass;
			    }
			    MoveThroughToTypeClass = getNewMoveThroughToTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.GetStatusType
			static inline jclass getGetStatusTypeClass();
			
			GetStatusType::GetStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			GetStatusType::GetStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getGetStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class GetStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.GetStatusType
			GetStatusType::~GetStatusType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewGetStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/GetStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/GetStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass GetStatusTypeClass = NULL;
			static inline jclass getGetStatusTypeClass() {
			    if (GetStatusTypeClass != NULL) {
			        return GetStatusTypeClass;
			    }
			    GetStatusTypeClass = getNewGetStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.MoveScrewType
			static inline jclass getMoveScrewTypeClass();
			
			MoveScrewType::MoveScrewType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			MoveScrewType::MoveScrewType() {
				JNIEnv *env =getEnv();
				jclass cls = getMoveScrewTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class MoveScrewType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.MoveScrewType
			MoveScrewType::~MoveScrewType() {
				// Place-holder for later extensibility.
			}

			PoseType MoveScrewType::getStartPosition() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getStartPosition of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getStartPosition", "()Lcrcl/base/PoseType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named getStartPosition with signature ()Lcrcl/base/PoseType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveScrewType::setStartPosition(PoseType poseType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setStartPosition of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setStartPosition", "(Lcrcl/base/PoseType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named setStartPosition with signature (Lcrcl/base/PoseType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,poseType_0 );
			            }
			        }
			        
			}
			PointType MoveScrewType::getAxisPoint() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getAxisPoint of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getAxisPoint", "()Lcrcl/base/PointType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named getAxisPoint with signature ()Lcrcl/base/PointType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PointType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveScrewType::setAxisPoint(PointType pointType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setAxisPoint of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setAxisPoint", "(Lcrcl/base/PointType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named setAxisPoint with signature (Lcrcl/base/PointType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,pointType_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal MoveScrewType::getAxialDistanceFree() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getAxialDistanceFree of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getAxialDistanceFree", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named getAxialDistanceFree with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveScrewType::setAxialDistanceFree(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setAxialDistanceFree of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setAxialDistanceFree", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named setAxialDistanceFree with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal MoveScrewType::getAxialDistanceScrew() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getAxialDistanceScrew of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getAxialDistanceScrew", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named getAxialDistanceScrew with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveScrewType::setAxialDistanceScrew(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setAxialDistanceScrew of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setAxialDistanceScrew", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named setAxialDistanceScrew with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal MoveScrewType::getTurn() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTurn of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTurn", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named getTurn with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveScrewType::setTurn(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTurn of crcl.base.MoveScrewType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveScrewTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTurn", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveScrewType has no method named setTurn with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewMoveScrewTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/MoveScrewType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/MoveScrewType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass MoveScrewTypeClass = NULL;
			static inline jclass getMoveScrewTypeClass() {
			    if (MoveScrewTypeClass != NULL) {
			        return MoveScrewTypeClass;
			    }
			    MoveScrewTypeClass = getNewMoveScrewTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RotAccelAbsoluteType
			static inline jclass getRotAccelAbsoluteTypeClass();
			
			RotAccelAbsoluteType::RotAccelAbsoluteType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RotAccelAbsoluteType::RotAccelAbsoluteType() {
				JNIEnv *env =getEnv();
				jclass cls = getRotAccelAbsoluteTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RotAccelAbsoluteType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RotAccelAbsoluteType
			RotAccelAbsoluteType::~RotAccelAbsoluteType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal RotAccelAbsoluteType::getSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSetting of crcl.base.RotAccelAbsoluteType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotAccelAbsoluteTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotAccelAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void RotAccelAbsoluteType::setSetting(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSetting of crcl.base.RotAccelAbsoluteType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotAccelAbsoluteTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotAccelAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewRotAccelAbsoluteTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RotAccelAbsoluteType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RotAccelAbsoluteType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RotAccelAbsoluteTypeClass = NULL;
			static inline jclass getRotAccelAbsoluteTypeClass() {
			    if (RotAccelAbsoluteTypeClass != NULL) {
			        return RotAccelAbsoluteTypeClass;
			    }
			    RotAccelAbsoluteTypeClass = getNewRotAccelAbsoluteTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetMotionCoordinationType
			static inline jclass getSetMotionCoordinationTypeClass();
			
			SetMotionCoordinationType::SetMotionCoordinationType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetMotionCoordinationType::SetMotionCoordinationType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetMotionCoordinationTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetMotionCoordinationType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetMotionCoordinationType
			SetMotionCoordinationType::~SetMotionCoordinationType() {
				// Place-holder for later extensibility.
			}

			jboolean SetMotionCoordinationType::isCoordinated() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isCoordinated of crcl.base.SetMotionCoordinationType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetMotionCoordinationTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isCoordinated", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetMotionCoordinationType has no method named isCoordinated with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetMotionCoordinationType::setCoordinated(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCoordinated of crcl.base.SetMotionCoordinationType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetMotionCoordinationTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCoordinated", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetMotionCoordinationType has no method named setCoordinated with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			static jclass getNewSetMotionCoordinationTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetMotionCoordinationType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetMotionCoordinationType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetMotionCoordinationTypeClass = NULL;
			static inline jclass getSetMotionCoordinationTypeClass() {
			    if (SetMotionCoordinationTypeClass != NULL) {
			        return SetMotionCoordinationTypeClass;
			    }
			    SetMotionCoordinationTypeClass = getNewSetMotionCoordinationTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ActuateJointType
			static inline jclass getActuateJointTypeClass();
			
			ActuateJointType::ActuateJointType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ActuateJointType::ActuateJointType() {
				JNIEnv *env =getEnv();
				jclass cls = getActuateJointTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ActuateJointType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ActuateJointType
			ActuateJointType::~ActuateJointType() {
				// Place-holder for later extensibility.
			}

			java::math::BigInteger ActuateJointType::getJointNumber() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointNumber of crcl.base.ActuateJointType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointNumber", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointType has no method named getJointNumber with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ActuateJointType::setJointNumber(java::math::BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointNumber of crcl.base.ActuateJointType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointNumber", "(Ljava/math/BigInteger;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointType has no method named setJointNumber with signature (Ljava/math/BigInteger;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal ActuateJointType::getJointPosition() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointPosition of crcl.base.ActuateJointType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointPosition", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointType has no method named getJointPosition with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ActuateJointType::setJointPosition(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointPosition of crcl.base.ActuateJointType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointPosition", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointType has no method named setJointPosition with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			void ActuateJointType::setJointDetails(JointDetailsType jointDetailsType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setJointDetails of crcl.base.ActuateJointType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setJointDetails", "(Lcrcl/base/JointDetailsType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointType has no method named setJointDetails with signature (Lcrcl/base/JointDetailsType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,jointDetailsType_0 );
			            }
			        }
			        
			}
			JointDetailsType ActuateJointType::getJointDetails() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getJointDetails of crcl.base.ActuateJointType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getActuateJointTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getJointDetails", "()Lcrcl/base/JointDetailsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ActuateJointType has no method named getJointDetails with signature ()Lcrcl/base/JointDetailsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (JointDetailsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewActuateJointTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ActuateJointType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ActuateJointType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ActuateJointTypeClass = NULL;
			static inline jclass getActuateJointTypeClass() {
			    if (ActuateJointTypeClass != NULL) {
			        return ActuateJointTypeClass;
			    }
			    ActuateJointTypeClass = getNewActuateJointTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.StopConditionEnumType
			static inline jclass getStopConditionEnumTypeClass();
			
			StopConditionEnumType::StopConditionEnumType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for crcl.base.StopConditionEnumType
			StopConditionEnumType::~StopConditionEnumType() {
				// Place-holder for later extensibility.
			}

			StopConditionEnumType StopConditionEnumType::fromValue(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getStopConditionEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "fromValue", "(Ljava/lang/String;)Lcrcl/base/StopConditionEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.StopConditionEnumType has no method named fromValue with signature (Ljava/lang/String;)Lcrcl/base/StopConditionEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			jstring StopConditionEnumType::value() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method value of crcl.base.StopConditionEnumType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getStopConditionEnumTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "value", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.StopConditionEnumType has no method named value with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			StopConditionEnumType StopConditionEnumType::valueOf(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getStopConditionEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lcrcl/base/StopConditionEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.StopConditionEnumType has no method named valueOf with signature (Ljava/lang/String;)Lcrcl/base/StopConditionEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			static jclass getNewStopConditionEnumTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/StopConditionEnumType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/StopConditionEnumType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass StopConditionEnumTypeClass = NULL;
			static inline jclass getStopConditionEnumTypeClass() {
			    if (StopConditionEnumTypeClass != NULL) {
			        return StopConditionEnumTypeClass;
			    }
			    StopConditionEnumTypeClass = getNewStopConditionEnumTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.RotSpeedAbsoluteType
			static inline jclass getRotSpeedAbsoluteTypeClass();
			
			RotSpeedAbsoluteType::RotSpeedAbsoluteType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			RotSpeedAbsoluteType::RotSpeedAbsoluteType() {
				JNIEnv *env =getEnv();
				jclass cls = getRotSpeedAbsoluteTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class RotSpeedAbsoluteType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.RotSpeedAbsoluteType
			RotSpeedAbsoluteType::~RotSpeedAbsoluteType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal RotSpeedAbsoluteType::getSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSetting of crcl.base.RotSpeedAbsoluteType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotSpeedAbsoluteTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotSpeedAbsoluteType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void RotSpeedAbsoluteType::setSetting(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSetting of crcl.base.RotSpeedAbsoluteType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getRotSpeedAbsoluteTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.RotSpeedAbsoluteType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewRotSpeedAbsoluteTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/RotSpeedAbsoluteType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/RotSpeedAbsoluteType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass RotSpeedAbsoluteTypeClass = NULL;
			static inline jclass getRotSpeedAbsoluteTypeClass() {
			    if (RotSpeedAbsoluteTypeClass != NULL) {
			        return RotSpeedAbsoluteTypeClass;
			    }
			    RotSpeedAbsoluteTypeClass = getNewRotSpeedAbsoluteTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ThreeFingerGripperStatusType
			static inline jclass getThreeFingerGripperStatusTypeClass();
			
			ThreeFingerGripperStatusType::ThreeFingerGripperStatusType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ThreeFingerGripperStatusType::ThreeFingerGripperStatusType() {
				JNIEnv *env =getEnv();
				jclass cls = getThreeFingerGripperStatusTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ThreeFingerGripperStatusType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ThreeFingerGripperStatusType
			ThreeFingerGripperStatusType::~ThreeFingerGripperStatusType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal ThreeFingerGripperStatusType::getFinger1Position() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFinger1Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFinger1Position", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger1Position with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ThreeFingerGripperStatusType::setFinger1Position(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFinger1Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFinger1Position", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger1Position with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal ThreeFingerGripperStatusType::getFinger2Position() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFinger2Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFinger2Position", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger2Position with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ThreeFingerGripperStatusType::setFinger2Position(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFinger2Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFinger2Position", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger2Position with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal ThreeFingerGripperStatusType::getFinger3Position() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFinger3Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFinger3Position", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger3Position with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ThreeFingerGripperStatusType::setFinger3Position(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFinger3Position of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFinger3Position", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger3Position with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal ThreeFingerGripperStatusType::getFinger1Force() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFinger1Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFinger1Force", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger1Force with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ThreeFingerGripperStatusType::setFinger1Force(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFinger1Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFinger1Force", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger1Force with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal ThreeFingerGripperStatusType::getFinger2Force() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFinger2Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFinger2Force", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger2Force with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ThreeFingerGripperStatusType::setFinger2Force(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFinger2Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFinger2Force", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger2Force with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal ThreeFingerGripperStatusType::getFinger3Force() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFinger3Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFinger3Force", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named getFinger3Force with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void ThreeFingerGripperStatusType::setFinger3Force(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFinger3Force of crcl.base.ThreeFingerGripperStatusType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getThreeFingerGripperStatusTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFinger3Force", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ThreeFingerGripperStatusType has no method named setFinger3Force with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewThreeFingerGripperStatusTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ThreeFingerGripperStatusType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ThreeFingerGripperStatusType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ThreeFingerGripperStatusTypeClass = NULL;
			static inline jclass getThreeFingerGripperStatusTypeClass() {
			    if (ThreeFingerGripperStatusTypeClass != NULL) {
			        return ThreeFingerGripperStatusTypeClass;
			    }
			    ThreeFingerGripperStatusTypeClass = getNewThreeFingerGripperStatusTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetRobotParametersType
			static inline jclass getSetRobotParametersTypeClass();
			
			SetRobotParametersType::SetRobotParametersType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetRobotParametersType::SetRobotParametersType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetRobotParametersTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetRobotParametersType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetRobotParametersType
			SetRobotParametersType::~SetRobotParametersType() {
				// Place-holder for later extensibility.
			}

			java::util::List SetRobotParametersType::getParameterSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getParameterSetting of crcl.base.SetRobotParametersType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetRobotParametersTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getParameterSetting", "()Ljava/util/List;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetRobotParametersType has no method named getParameterSetting with signature ()Ljava/util/List;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::util::List)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewSetRobotParametersTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetRobotParametersType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetRobotParametersType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetRobotParametersTypeClass = NULL;
			static inline jclass getSetRobotParametersTypeClass() {
			    if (SetRobotParametersTypeClass != NULL) {
			        return SetRobotParametersTypeClass;
			    }
			    SetRobotParametersTypeClass = getNewSetRobotParametersTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.MoveToType
			static inline jclass getMoveToTypeClass();
			
			MoveToType::MoveToType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			MoveToType::MoveToType() {
				JNIEnv *env =getEnv();
				jclass cls = getMoveToTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class MoveToType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.MoveToType
			MoveToType::~MoveToType() {
				// Place-holder for later extensibility.
			}

			jboolean MoveToType::isMoveStraight() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isMoveStraight of crcl.base.MoveToType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveToTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isMoveStraight", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveToType has no method named isMoveStraight with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveToType::setMoveStraight(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setMoveStraight of crcl.base.MoveToType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveToTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setMoveStraight", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveToType has no method named setMoveStraight with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			PoseType MoveToType::getEndPosition() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getEndPosition of crcl.base.MoveToType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveToTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getEndPosition", "()Lcrcl/base/PoseType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveToType has no method named getEndPosition with signature ()Lcrcl/base/PoseType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void MoveToType::setEndPosition(PoseType poseType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setEndPosition of crcl.base.MoveToType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getMoveToTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setEndPosition", "(Lcrcl/base/PoseType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.MoveToType has no method named setEndPosition with signature (Lcrcl/base/PoseType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,poseType_0 );
			            }
			        }
			        
			}
			static jclass getNewMoveToTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/MoveToType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/MoveToType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass MoveToTypeClass = NULL;
			static inline jclass getMoveToTypeClass() {
			    if (MoveToTypeClass != NULL) {
			        return MoveToTypeClass;
			    }
			    MoveToTypeClass = getNewMoveToTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.ObjectFactory
			static inline jclass getObjectFactoryClass();
			
			ObjectFactory::ObjectFactory(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			ObjectFactory::ObjectFactory() {
				JNIEnv *env =getEnv();
				jclass cls = getObjectFactoryClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class ObjectFactory has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.ObjectFactory
			ObjectFactory::~ObjectFactory() {
				// Place-holder for later extensibility.
			}

			CRCLProgramType ObjectFactory::createCRCLProgramType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCRCLProgramType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCRCLProgramType", "()Lcrcl/base/CRCLProgramType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLProgramType with signature ()Lcrcl/base/CRCLProgramType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CRCLProgramType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			CRCLCommandInstanceType ObjectFactory::createCRCLCommandInstanceType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCRCLCommandInstanceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCRCLCommandInstanceType", "()Lcrcl/base/CRCLCommandInstanceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLCommandInstanceType with signature ()Lcrcl/base/CRCLCommandInstanceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CRCLCommandInstanceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			CRCLStatusType ObjectFactory::createCRCLStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCRCLStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCRCLStatusType", "()Lcrcl/base/CRCLStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLStatusType with signature ()Lcrcl/base/CRCLStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CRCLStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			PointType ObjectFactory::createPointType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createPointType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createPointType", "()Lcrcl/base/PointType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createPointType with signature ()Lcrcl/base/PointType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PointType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			PoseType ObjectFactory::createPoseType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createPoseType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createPoseType", "()Lcrcl/base/PoseType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createPoseType with signature ()Lcrcl/base/PoseType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			VectorType ObjectFactory::createVectorType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createVectorType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createVectorType", "()Lcrcl/base/VectorType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createVectorType with signature ()Lcrcl/base/VectorType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (VectorType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ActuateJointsType ObjectFactory::createActuateJointsType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createActuateJointsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createActuateJointsType", "()Lcrcl/base/ActuateJointsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createActuateJointsType with signature ()Lcrcl/base/ActuateJointsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ActuateJointsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			DwellType ObjectFactory::createDwellType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createDwellType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createDwellType", "()Lcrcl/base/DwellType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createDwellType with signature ()Lcrcl/base/DwellType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (DwellType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ActuateJointType ObjectFactory::createActuateJointType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createActuateJointType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createActuateJointType", "()Lcrcl/base/ActuateJointType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createActuateJointType with signature ()Lcrcl/base/ActuateJointType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ActuateJointType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			CloseToolChangerType ObjectFactory::createCloseToolChangerType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCloseToolChangerType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCloseToolChangerType", "()Lcrcl/base/CloseToolChangerType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCloseToolChangerType with signature ()Lcrcl/base/CloseToolChangerType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CloseToolChangerType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ConfigureJointReportsType ObjectFactory::createConfigureJointReportsType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createConfigureJointReportsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createConfigureJointReportsType", "()Lcrcl/base/ConfigureJointReportsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createConfigureJointReportsType with signature ()Lcrcl/base/ConfigureJointReportsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ConfigureJointReportsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ConfigureJointReportType ObjectFactory::createConfigureJointReportType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createConfigureJointReportType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createConfigureJointReportType", "()Lcrcl/base/ConfigureJointReportType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createConfigureJointReportType with signature ()Lcrcl/base/ConfigureJointReportType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ConfigureJointReportType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			EndCanonType ObjectFactory::createEndCanonType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createEndCanonType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createEndCanonType", "()Lcrcl/base/EndCanonType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createEndCanonType with signature ()Lcrcl/base/EndCanonType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (EndCanonType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			GetStatusType ObjectFactory::createGetStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createGetStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createGetStatusType", "()Lcrcl/base/GetStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createGetStatusType with signature ()Lcrcl/base/GetStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (GetStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			InitCanonType ObjectFactory::createInitCanonType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createInitCanonType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createInitCanonType", "()Lcrcl/base/InitCanonType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createInitCanonType with signature ()Lcrcl/base/InitCanonType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (InitCanonType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			JointForceTorqueType ObjectFactory::createJointForceTorqueType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createJointForceTorqueType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createJointForceTorqueType", "()Lcrcl/base/JointForceTorqueType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createJointForceTorqueType with signature ()Lcrcl/base/JointForceTorqueType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (JointForceTorqueType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			JointSpeedAccelType ObjectFactory::createJointSpeedAccelType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createJointSpeedAccelType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createJointSpeedAccelType", "()Lcrcl/base/JointSpeedAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createJointSpeedAccelType with signature ()Lcrcl/base/JointSpeedAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (JointSpeedAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			MessageType ObjectFactory::createMessageType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createMessageType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createMessageType", "()Lcrcl/base/MessageType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createMessageType with signature ()Lcrcl/base/MessageType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (MessageType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			MoveScrewType ObjectFactory::createMoveScrewType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createMoveScrewType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createMoveScrewType", "()Lcrcl/base/MoveScrewType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createMoveScrewType with signature ()Lcrcl/base/MoveScrewType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (MoveScrewType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			MoveThroughToType ObjectFactory::createMoveThroughToType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createMoveThroughToType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createMoveThroughToType", "()Lcrcl/base/MoveThroughToType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createMoveThroughToType with signature ()Lcrcl/base/MoveThroughToType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (MoveThroughToType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			MoveToType ObjectFactory::createMoveToType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createMoveToType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createMoveToType", "()Lcrcl/base/MoveToType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createMoveToType with signature ()Lcrcl/base/MoveToType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (MoveToType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			OpenToolChangerType ObjectFactory::createOpenToolChangerType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createOpenToolChangerType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createOpenToolChangerType", "()Lcrcl/base/OpenToolChangerType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createOpenToolChangerType with signature ()Lcrcl/base/OpenToolChangerType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (OpenToolChangerType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ParameterSettingType ObjectFactory::createParameterSettingType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createParameterSettingType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createParameterSettingType", "()Lcrcl/base/ParameterSettingType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createParameterSettingType with signature ()Lcrcl/base/ParameterSettingType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ParameterSettingType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			PoseAndSetType ObjectFactory::createPoseAndSetType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createPoseAndSetType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createPoseAndSetType", "()Lcrcl/base/PoseAndSetType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createPoseAndSetType with signature ()Lcrcl/base/PoseAndSetType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseAndSetType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			PoseToleranceType ObjectFactory::createPoseToleranceType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createPoseToleranceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createPoseToleranceType", "()Lcrcl/base/PoseToleranceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createPoseToleranceType with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseToleranceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			RotAccelAbsoluteType ObjectFactory::createRotAccelAbsoluteType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createRotAccelAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createRotAccelAbsoluteType", "()Lcrcl/base/RotAccelAbsoluteType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createRotAccelAbsoluteType with signature ()Lcrcl/base/RotAccelAbsoluteType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotAccelAbsoluteType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			RotAccelRelativeType ObjectFactory::createRotAccelRelativeType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createRotAccelRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createRotAccelRelativeType", "()Lcrcl/base/RotAccelRelativeType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createRotAccelRelativeType with signature ()Lcrcl/base/RotAccelRelativeType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotAccelRelativeType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			RotSpeedAbsoluteType ObjectFactory::createRotSpeedAbsoluteType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createRotSpeedAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createRotSpeedAbsoluteType", "()Lcrcl/base/RotSpeedAbsoluteType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createRotSpeedAbsoluteType with signature ()Lcrcl/base/RotSpeedAbsoluteType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotSpeedAbsoluteType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			RotSpeedRelativeType ObjectFactory::createRotSpeedRelativeType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createRotSpeedRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createRotSpeedRelativeType", "()Lcrcl/base/RotSpeedRelativeType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createRotSpeedRelativeType with signature ()Lcrcl/base/RotSpeedRelativeType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotSpeedRelativeType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			RunProgramType ObjectFactory::createRunProgramType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createRunProgramType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createRunProgramType", "()Lcrcl/base/RunProgramType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createRunProgramType with signature ()Lcrcl/base/RunProgramType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RunProgramType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetAngleUnitsType ObjectFactory::createSetAngleUnitsType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetAngleUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetAngleUnitsType", "()Lcrcl/base/SetAngleUnitsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetAngleUnitsType with signature ()Lcrcl/base/SetAngleUnitsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetAngleUnitsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetEndEffectorParametersType ObjectFactory::createSetEndEffectorParametersType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetEndEffectorParametersType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetEndEffectorParametersType", "()Lcrcl/base/SetEndEffectorParametersType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetEndEffectorParametersType with signature ()Lcrcl/base/SetEndEffectorParametersType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetEndEffectorParametersType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetEndEffectorType ObjectFactory::createSetEndEffectorType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetEndEffectorType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetEndEffectorType", "()Lcrcl/base/SetEndEffectorType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetEndEffectorType with signature ()Lcrcl/base/SetEndEffectorType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetEndEffectorType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetEndPoseToleranceType ObjectFactory::createSetEndPoseToleranceType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetEndPoseToleranceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetEndPoseToleranceType", "()Lcrcl/base/SetEndPoseToleranceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetEndPoseToleranceType with signature ()Lcrcl/base/SetEndPoseToleranceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetEndPoseToleranceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetForceUnitsType ObjectFactory::createSetForceUnitsType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetForceUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetForceUnitsType", "()Lcrcl/base/SetForceUnitsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetForceUnitsType with signature ()Lcrcl/base/SetForceUnitsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetForceUnitsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetIntermediatePoseToleranceType ObjectFactory::createSetIntermediatePoseToleranceType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetIntermediatePoseToleranceType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetIntermediatePoseToleranceType", "()Lcrcl/base/SetIntermediatePoseToleranceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetIntermediatePoseToleranceType with signature ()Lcrcl/base/SetIntermediatePoseToleranceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetIntermediatePoseToleranceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetLengthUnitsType ObjectFactory::createSetLengthUnitsType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetLengthUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetLengthUnitsType", "()Lcrcl/base/SetLengthUnitsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetLengthUnitsType with signature ()Lcrcl/base/SetLengthUnitsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetLengthUnitsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetMotionCoordinationType ObjectFactory::createSetMotionCoordinationType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetMotionCoordinationType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetMotionCoordinationType", "()Lcrcl/base/SetMotionCoordinationType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetMotionCoordinationType with signature ()Lcrcl/base/SetMotionCoordinationType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetMotionCoordinationType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetRobotParametersType ObjectFactory::createSetRobotParametersType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetRobotParametersType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetRobotParametersType", "()Lcrcl/base/SetRobotParametersType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetRobotParametersType with signature ()Lcrcl/base/SetRobotParametersType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetRobotParametersType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetRotAccelType ObjectFactory::createSetRotAccelType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetRotAccelType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetRotAccelType", "()Lcrcl/base/SetRotAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetRotAccelType with signature ()Lcrcl/base/SetRotAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetRotAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetRotSpeedType ObjectFactory::createSetRotSpeedType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetRotSpeedType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetRotSpeedType", "()Lcrcl/base/SetRotSpeedType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetRotSpeedType with signature ()Lcrcl/base/SetRotSpeedType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetRotSpeedType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetTorqueUnitsType ObjectFactory::createSetTorqueUnitsType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetTorqueUnitsType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetTorqueUnitsType", "()Lcrcl/base/SetTorqueUnitsType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetTorqueUnitsType with signature ()Lcrcl/base/SetTorqueUnitsType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetTorqueUnitsType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetTransAccelType ObjectFactory::createSetTransAccelType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetTransAccelType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetTransAccelType", "()Lcrcl/base/SetTransAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetTransAccelType with signature ()Lcrcl/base/SetTransAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetTransAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			SetTransSpeedType ObjectFactory::createSetTransSpeedType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createSetTransSpeedType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createSetTransSpeedType", "()Lcrcl/base/SetTransSpeedType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createSetTransSpeedType with signature ()Lcrcl/base/SetTransSpeedType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (SetTransSpeedType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			StopMotionType ObjectFactory::createStopMotionType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createStopMotionType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createStopMotionType", "()Lcrcl/base/StopMotionType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createStopMotionType with signature ()Lcrcl/base/StopMotionType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (StopMotionType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			TransAccelAbsoluteType ObjectFactory::createTransAccelAbsoluteType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createTransAccelAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createTransAccelAbsoluteType", "()Lcrcl/base/TransAccelAbsoluteType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createTransAccelAbsoluteType with signature ()Lcrcl/base/TransAccelAbsoluteType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransAccelAbsoluteType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			TransAccelRelativeType ObjectFactory::createTransAccelRelativeType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createTransAccelRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createTransAccelRelativeType", "()Lcrcl/base/TransAccelRelativeType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createTransAccelRelativeType with signature ()Lcrcl/base/TransAccelRelativeType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransAccelRelativeType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			TransSpeedAbsoluteType ObjectFactory::createTransSpeedAbsoluteType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createTransSpeedAbsoluteType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createTransSpeedAbsoluteType", "()Lcrcl/base/TransSpeedAbsoluteType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createTransSpeedAbsoluteType with signature ()Lcrcl/base/TransSpeedAbsoluteType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransSpeedAbsoluteType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			TransSpeedRelativeType ObjectFactory::createTransSpeedRelativeType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createTransSpeedRelativeType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createTransSpeedRelativeType", "()Lcrcl/base/TransSpeedRelativeType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createTransSpeedRelativeType with signature ()Lcrcl/base/TransSpeedRelativeType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransSpeedRelativeType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			CommandStatusType ObjectFactory::createCommandStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCommandStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCommandStatusType", "()Lcrcl/base/CommandStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCommandStatusType with signature ()Lcrcl/base/CommandStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (CommandStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			JointStatusesType ObjectFactory::createJointStatusesType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createJointStatusesType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createJointStatusesType", "()Lcrcl/base/JointStatusesType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createJointStatusesType with signature ()Lcrcl/base/JointStatusesType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (JointStatusesType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			JointStatusType ObjectFactory::createJointStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createJointStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createJointStatusType", "()Lcrcl/base/JointStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createJointStatusType with signature ()Lcrcl/base/JointStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (JointStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ParallelGripperStatusType ObjectFactory::createParallelGripperStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createParallelGripperStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createParallelGripperStatusType", "()Lcrcl/base/ParallelGripperStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createParallelGripperStatusType with signature ()Lcrcl/base/ParallelGripperStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ParallelGripperStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			ThreeFingerGripperStatusType ObjectFactory::createThreeFingerGripperStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createThreeFingerGripperStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createThreeFingerGripperStatusType", "()Lcrcl/base/ThreeFingerGripperStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createThreeFingerGripperStatusType with signature ()Lcrcl/base/ThreeFingerGripperStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (ThreeFingerGripperStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			VacuumGripperStatusType ObjectFactory::createVacuumGripperStatusType() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createVacuumGripperStatusType of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createVacuumGripperStatusType", "()Lcrcl/base/VacuumGripperStatusType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createVacuumGripperStatusType with signature ()Lcrcl/base/VacuumGripperStatusType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (VacuumGripperStatusType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			javax::xml::bind::JAXBElement ObjectFactory::createCRCLProgram(CRCLProgramType cRCLProgramType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCRCLProgram of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCRCLProgram", "(Lcrcl/base/CRCLProgramType;)Ljavax/xml/bind/JAXBElement;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLProgram with signature (Lcrcl/base/CRCLProgramType;)Ljavax/xml/bind/JAXBElement;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (javax::xml::bind::JAXBElement)  env->CallObjectMethod(jthis, mid ,cRCLProgramType_0 );
			            }
			        }
			        return retVal;
			}
			javax::xml::bind::JAXBElement ObjectFactory::createCRCLCommandInstance(CRCLCommandInstanceType cRCLCommandInstanceType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCRCLCommandInstance of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCRCLCommandInstance", "(Lcrcl/base/CRCLCommandInstanceType;)Ljavax/xml/bind/JAXBElement;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLCommandInstance with signature (Lcrcl/base/CRCLCommandInstanceType;)Ljavax/xml/bind/JAXBElement;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (javax::xml::bind::JAXBElement)  env->CallObjectMethod(jthis, mid ,cRCLCommandInstanceType_0 );
			            }
			        }
			        return retVal;
			}
			javax::xml::bind::JAXBElement ObjectFactory::createCRCLStatus(CRCLStatusType cRCLStatusType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method createCRCLStatus of crcl.base.ObjectFactory with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getObjectFactoryClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "createCRCLStatus", "(Lcrcl/base/CRCLStatusType;)Ljavax/xml/bind/JAXBElement;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.ObjectFactory has no method named createCRCLStatus with signature (Lcrcl/base/CRCLStatusType;)Ljavax/xml/bind/JAXBElement;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (javax::xml::bind::JAXBElement)  env->CallObjectMethod(jthis, mid ,cRCLStatusType_0 );
			            }
			        }
			        return retVal;
			}
			static jclass getNewObjectFactoryClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/ObjectFactory");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/ObjectFactory" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ObjectFactoryClass = NULL;
			static inline jclass getObjectFactoryClass() {
			    if (ObjectFactoryClass != NULL) {
			        return ObjectFactoryClass;
			    }
			    ObjectFactoryClass = getNewObjectFactoryClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.PoseAndSetType
			static inline jclass getPoseAndSetTypeClass();
			
			PoseAndSetType::PoseAndSetType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			PoseAndSetType::PoseAndSetType() {
				JNIEnv *env =getEnv();
				jclass cls = getPoseAndSetTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class PoseAndSetType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.PoseAndSetType
			PoseAndSetType::~PoseAndSetType() {
				// Place-holder for later extensibility.
			}

			PoseToleranceType PoseAndSetType::getTolerance() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTolerance of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTolerance", "()Lcrcl/base/PoseToleranceType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named getTolerance with signature ()Lcrcl/base/PoseToleranceType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (PoseToleranceType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseAndSetType::setTolerance(PoseToleranceType poseToleranceType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTolerance of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTolerance", "(Lcrcl/base/PoseToleranceType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named setTolerance with signature (Lcrcl/base/PoseToleranceType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,poseToleranceType_0 );
			            }
			        }
			        
			}
			RotSpeedType PoseAndSetType::getRotSpeed() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getRotSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getRotSpeed", "()Lcrcl/base/RotSpeedType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named getRotSpeed with signature ()Lcrcl/base/RotSpeedType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotSpeedType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseAndSetType::setRotSpeed(RotSpeedType rotSpeedType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setRotSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setRotSpeed", "(Lcrcl/base/RotSpeedType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named setRotSpeed with signature (Lcrcl/base/RotSpeedType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,rotSpeedType_0 );
			            }
			        }
			        
			}
			TransSpeedType PoseAndSetType::getTransSpeed() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTransSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTransSpeed", "()Lcrcl/base/TransSpeedType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named getTransSpeed with signature ()Lcrcl/base/TransSpeedType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransSpeedType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseAndSetType::setTransSpeed(TransSpeedType transSpeedType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTransSpeed of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTransSpeed", "(Lcrcl/base/TransSpeedType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named setTransSpeed with signature (Lcrcl/base/TransSpeedType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,transSpeedType_0 );
			            }
			        }
			        
			}
			RotAccelType PoseAndSetType::getRotAccel() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getRotAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getRotAccel", "()Lcrcl/base/RotAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named getRotAccel with signature ()Lcrcl/base/RotAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (RotAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseAndSetType::setRotAccel(RotAccelType rotAccelType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setRotAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setRotAccel", "(Lcrcl/base/RotAccelType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named setRotAccel with signature (Lcrcl/base/RotAccelType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,rotAccelType_0 );
			            }
			        }
			        
			}
			jboolean PoseAndSetType::isCoordinated() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isCoordinated of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isCoordinated", "()Z");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named isCoordinated with signature ()Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseAndSetType::setCoordinated(jboolean boolean_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setCoordinated of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setCoordinated", "(Z)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named setCoordinated with signature (Z)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,boolean_0 );
			            }
			        }
			        
			}
			TransAccelType PoseAndSetType::getTransAccel() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTransAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTransAccel", "()Lcrcl/base/TransAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named getTransAccel with signature ()Lcrcl/base/TransAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PoseAndSetType::setTransAccel(TransAccelType transAccelType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTransAccel of crcl.base.PoseAndSetType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPoseAndSetTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTransAccel", "(Lcrcl/base/TransAccelType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PoseAndSetType has no method named setTransAccel with signature (Lcrcl/base/TransAccelType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,transAccelType_0 );
			            }
			        }
			        
			}
			static jclass getNewPoseAndSetTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/PoseAndSetType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/PoseAndSetType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass PoseAndSetTypeClass = NULL;
			static inline jclass getPoseAndSetTypeClass() {
			    if (PoseAndSetTypeClass != NULL) {
			        return PoseAndSetTypeClass;
			    }
			    PoseAndSetTypeClass = getNewPoseAndSetTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.TransAccelRelativeType
			static inline jclass getTransAccelRelativeTypeClass();
			
			TransAccelRelativeType::TransAccelRelativeType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			TransAccelRelativeType::TransAccelRelativeType() {
				JNIEnv *env =getEnv();
				jclass cls = getTransAccelRelativeTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class TransAccelRelativeType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.TransAccelRelativeType
			TransAccelRelativeType::~TransAccelRelativeType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal TransAccelRelativeType::getFraction() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getFraction of crcl.base.TransAccelRelativeType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransAccelRelativeTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getFraction", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransAccelRelativeType has no method named getFraction with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void TransAccelRelativeType::setFraction(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setFraction of crcl.base.TransAccelRelativeType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getTransAccelRelativeTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setFraction", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.TransAccelRelativeType has no method named setFraction with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewTransAccelRelativeTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/TransAccelRelativeType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/TransAccelRelativeType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass TransAccelRelativeTypeClass = NULL;
			static inline jclass getTransAccelRelativeTypeClass() {
			    if (TransAccelRelativeTypeClass != NULL) {
			        return TransAccelRelativeTypeClass;
			    }
			    TransAccelRelativeTypeClass = getNewTransAccelRelativeTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.DwellType
			static inline jclass getDwellTypeClass();
			
			DwellType::DwellType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			DwellType::DwellType() {
				JNIEnv *env =getEnv();
				jclass cls = getDwellTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class DwellType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.DwellType
			DwellType::~DwellType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal DwellType::getDwellTime() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getDwellTime of crcl.base.DwellType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getDwellTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getDwellTime", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.DwellType has no method named getDwellTime with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void DwellType::setDwellTime(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setDwellTime of crcl.base.DwellType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getDwellTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setDwellTime", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.DwellType has no method named setDwellTime with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewDwellTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/DwellType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/DwellType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass DwellTypeClass = NULL;
			static inline jclass getDwellTypeClass() {
			    if (DwellTypeClass != NULL) {
			        return DwellTypeClass;
			    }
			    DwellTypeClass = getNewDwellTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetLengthUnitsType
			static inline jclass getSetLengthUnitsTypeClass();
			
			SetLengthUnitsType::SetLengthUnitsType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetLengthUnitsType::SetLengthUnitsType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetLengthUnitsTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetLengthUnitsType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetLengthUnitsType
			SetLengthUnitsType::~SetLengthUnitsType() {
				// Place-holder for later extensibility.
			}

			LengthUnitEnumType SetLengthUnitsType::getUnitName() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getUnitName of crcl.base.SetLengthUnitsType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetLengthUnitsTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getUnitName", "()Lcrcl/base/LengthUnitEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetLengthUnitsType has no method named getUnitName with signature ()Lcrcl/base/LengthUnitEnumType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (LengthUnitEnumType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetLengthUnitsType::setUnitName(LengthUnitEnumType lengthUnitEnumType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setUnitName of crcl.base.SetLengthUnitsType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetLengthUnitsTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setUnitName", "(Lcrcl/base/LengthUnitEnumType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetLengthUnitsType has no method named setUnitName with signature (Lcrcl/base/LengthUnitEnumType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,lengthUnitEnumType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetLengthUnitsTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetLengthUnitsType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetLengthUnitsType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetLengthUnitsTypeClass = NULL;
			static inline jclass getSetLengthUnitsTypeClass() {
			    if (SetLengthUnitsTypeClass != NULL) {
			        return SetLengthUnitsTypeClass;
			    }
			    SetLengthUnitsTypeClass = getNewSetLengthUnitsTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.OpenToolChangerType
			static inline jclass getOpenToolChangerTypeClass();
			
			OpenToolChangerType::OpenToolChangerType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			OpenToolChangerType::OpenToolChangerType() {
				JNIEnv *env =getEnv();
				jclass cls = getOpenToolChangerTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class OpenToolChangerType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.OpenToolChangerType
			OpenToolChangerType::~OpenToolChangerType() {
				// Place-holder for later extensibility.
			}

			static jclass getNewOpenToolChangerTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/OpenToolChangerType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/OpenToolChangerType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass OpenToolChangerTypeClass = NULL;
			static inline jclass getOpenToolChangerTypeClass() {
			    if (OpenToolChangerTypeClass != NULL) {
			        return OpenToolChangerTypeClass;
			    }
			    OpenToolChangerTypeClass = getNewOpenToolChangerTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.SetTransAccelType
			static inline jclass getSetTransAccelTypeClass();
			
			SetTransAccelType::SetTransAccelType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			SetTransAccelType::SetTransAccelType() {
				JNIEnv *env =getEnv();
				jclass cls = getSetTransAccelTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class SetTransAccelType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.SetTransAccelType
			SetTransAccelType::~SetTransAccelType() {
				// Place-holder for later extensibility.
			}

			TransAccelType SetTransAccelType::getTransAccel() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getTransAccel of crcl.base.SetTransAccelType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetTransAccelTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getTransAccel", "()Lcrcl/base/TransAccelType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetTransAccelType has no method named getTransAccel with signature ()Lcrcl/base/TransAccelType;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (TransAccelType)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void SetTransAccelType::setTransAccel(TransAccelType transAccelType_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setTransAccel of crcl.base.SetTransAccelType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getSetTransAccelTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setTransAccel", "(Lcrcl/base/TransAccelType;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.SetTransAccelType has no method named setTransAccel with signature (Lcrcl/base/TransAccelType;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,transAccelType_0 );
			            }
			        }
			        
			}
			static jclass getNewSetTransAccelTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/SetTransAccelType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/SetTransAccelType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass SetTransAccelTypeClass = NULL;
			static inline jclass getSetTransAccelTypeClass() {
			    if (SetTransAccelTypeClass != NULL) {
			        return SetTransAccelTypeClass;
			    }
			    SetTransAccelTypeClass = getNewSetTransAccelTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.JointForceTorqueType
			static inline jclass getJointForceTorqueTypeClass();
			
			JointForceTorqueType::JointForceTorqueType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			JointForceTorqueType::JointForceTorqueType() {
				JNIEnv *env =getEnv();
				jclass cls = getJointForceTorqueTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class JointForceTorqueType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.JointForceTorqueType
			JointForceTorqueType::~JointForceTorqueType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal JointForceTorqueType::getSetting() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getSetting of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointForceTorqueTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getSetting", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointForceTorqueType has no method named getSetting with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointForceTorqueType::setSetting(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setSetting of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointForceTorqueTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setSetting", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointForceTorqueType has no method named setSetting with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal JointForceTorqueType::getChangeRate() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getChangeRate of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointForceTorqueTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getChangeRate", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointForceTorqueType has no method named getChangeRate with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void JointForceTorqueType::setChangeRate(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setChangeRate of crcl.base.JointForceTorqueType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getJointForceTorqueTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setChangeRate", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.JointForceTorqueType has no method named setChangeRate with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewJointForceTorqueTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/JointForceTorqueType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/JointForceTorqueType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass JointForceTorqueTypeClass = NULL;
			static inline jclass getJointForceTorqueTypeClass() {
			    if (JointForceTorqueTypeClass != NULL) {
			        return JointForceTorqueTypeClass;
			    }
			    JointForceTorqueTypeClass = getNewJointForceTorqueTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.PointType
			static inline jclass getPointTypeClass();
			
			PointType::PointType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			PointType::PointType() {
				JNIEnv *env =getEnv();
				jclass cls = getPointTypeClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
				    if (NULL == mid) {
				        std::cerr << "Class PointType has no method constructor signature ()V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid );
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for crcl.base.PointType
			PointType::~PointType() {
				// Place-holder for later extensibility.
			}

			java::math::BigDecimal PointType::getX() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getX of crcl.base.PointType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPointTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getX", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PointType has no method named getX with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PointType::setX(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setX of crcl.base.PointType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPointTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setX", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PointType has no method named setX with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal PointType::getY() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getY of crcl.base.PointType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPointTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getY", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PointType has no method named getY with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PointType::setY(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setY of crcl.base.PointType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPointTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setY", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PointType has no method named setY with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			java::math::BigDecimal PointType::getZ() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getZ of crcl.base.PointType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPointTypeClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getZ", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PointType has no method named getZ with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (java::math::BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			void PointType::setZ(java::math::BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setZ of crcl.base.PointType with jthis == NULL." << std::endl;
			            
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getPointTypeClass();
			        
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setZ", "(Ljava/math/BigDecimal;)V");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.PointType has no method named setZ with signature (Ljava/math/BigDecimal;)V." << std::endl;
			                
			            } else {
			                 env->CallVoidMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        
			}
			static jclass getNewPointTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/PointType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/PointType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass PointTypeClass = NULL;
			static inline jclass getPointTypeClass() {
			    if (PointTypeClass != NULL) {
			        return PointTypeClass;
			    }
			    PointTypeClass = getNewPointTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace crcl{
			namespace base{
			
			// get JNI handle for class crcl.base.CommandStateEnumType
			static inline jclass getCommandStateEnumTypeClass();
			
			CommandStateEnumType::CommandStateEnumType(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}

			// Destructor for crcl.base.CommandStateEnumType
			CommandStateEnumType::~CommandStateEnumType() {
				// Place-holder for later extensibility.
			}

			CommandStateEnumType CommandStateEnumType::fromValue(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStateEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "fromValue", "(Ljava/lang/String;)Lcrcl/base/CommandStateEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStateEnumType has no method named fromValue with signature (Ljava/lang/String;)Lcrcl/base/CommandStateEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			jstring CommandStateEnumType::value() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method value of crcl.base.CommandStateEnumType with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStateEnumTypeClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "value", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStateEnumType has no method named value with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			CommandStateEnumType CommandStateEnumType::valueOf(jstring string_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getCommandStateEnumTypeClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lcrcl/base/CommandStateEnumType;");
			            if (NULL == mid) {
			                std::cerr << "Class crcl.base.CommandStateEnumType has no method named valueOf with signature (Ljava/lang/String;)Lcrcl/base/CommandStateEnumType;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,string_0 );
			            }
			        }
			}
			static jclass getNewCommandStateEnumTypeClass() {
			    jclass clss = getEnv()->FindClass("crcl/base/CommandStateEnumType");
			    if (NULL == clss) {
			        std::cerr << " Can't find class crcl/base/CommandStateEnumType" << std::endl;
			    }
			    return clss;
			}
			
			static jclass CommandStateEnumTypeClass = NULL;
			static inline jclass getCommandStateEnumTypeClass() {
			    if (CommandStateEnumTypeClass != NULL) {
			        return CommandStateEnumTypeClass;
			    }
			    CommandStateEnumTypeClass = getNewCommandStateEnumTypeClass();
			}
		} // end namespace crcl
	} // end namespace base
		namespace java{
			namespace util{
			
			// get JNI handle for class java.util.List
			static inline jclass getListClass();
			
			List::List(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			List::List() {
			JNIEnv *env =getEnv();
			jclass cls = getListClass();
			if (cls != NULL) {
			    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
			    if (NULL == mid) {
			        std::cerr << "Class List has no method constructor signature ()V" << std::endl;
			    } else {
			        jthis = env->NewObject(cls, mid );
			        jobjectRefType ref = env->GetObjectRefType(jthis);
			        if(ref != JNIGlobalRefType) {
			            jthis = env->NewGlobalRef(jthis);
			        }
			    }
			}
			}


			// Destructor for java.util.List
			List::~List() {
				// Place-holder for later extensibility.
			}

			static jclass getNewListClass() {
			    jclass clss = getEnv()->FindClass("java/util/List");
			    if (NULL == clss) {
			        std::cerr << " Can't find class java/util/List" << std::endl;
			    }
			    return clss;
			}
			
			static jclass ListClass = NULL;
			static inline jclass getListClass() {
			    if (ListClass != NULL) {
			        return ListClass;
			    }
			    ListClass = getNewListClass();
			}
		} // end namespace java
	} // end namespace util
		namespace java{
			namespace math{
			
			// get JNI handle for class java.math.BigInteger
			static inline jclass getBigIntegerClass();
			
			BigInteger::BigInteger(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			BigInteger::BigInteger(jstring string_0,jint int_1) {
				JNIEnv *env =getEnv();
				jclass cls = getBigIntegerClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigInteger has no method constructor signature (Ljava/lang/String;I)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,string_0,int_1);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}

			BigInteger::BigInteger(jstring string_0) {
				JNIEnv *env =getEnv();
				jclass cls = getBigIntegerClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigInteger has no method constructor signature (Ljava/lang/String;)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,string_0);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for java.math.BigInteger
			BigInteger::~BigInteger() {
				// Place-holder for later extensibility.
			}

			jint BigInteger::bitLength() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method bitLength of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "bitLength", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named bitLength with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::nextProbablePrime() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method nextProbablePrime of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "nextProbablePrime", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named nextProbablePrime with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::subtract(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method subtract of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "subtract", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named subtract with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::multiply(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method multiply of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "multiply", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named multiply with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::gcd(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method gcd of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "gcd", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named gcd with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::negate() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method negate of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "negate", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named negate with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::modPow(BigInteger bigInteger_0,BigInteger bigInteger_1) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method modPow of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "modPow", "(Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named modPow with signature (Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0,bigInteger_1 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::modInverse(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method modInverse of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "modInverse", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named modInverse with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::shiftRight(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method shiftRight of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "shiftRight", "(I)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named shiftRight with signature (I)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			jboolean BigInteger::testBit(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method testBit of java.math.BigInteger with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "testBit", "(I)Z");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named testBit with signature (I)Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::setBit(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setBit of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setBit", "(I)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named setBit with signature (I)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::clearBit(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method clearBit of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "clearBit", "(I)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named clearBit with signature (I)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::flipBit(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method flipBit of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "flipBit", "(I)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named flipBit with signature (I)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			jint BigInteger::getLowestSetBit() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method getLowestSetBit of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "getLowestSetBit", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named getLowestSetBit with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jboolean BigInteger::isProbablePrime(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method isProbablePrime of java.math.BigInteger with jthis == NULL." << std::endl;
			            return false;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        boolean retVal=false;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "isProbablePrime", "(I)Z");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named isProbablePrime with signature (I)Z." << std::endl;
			                return false;
			            } else {
			                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			jlong BigInteger::longValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method longValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jlong) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jlong retVal= (jlong) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "longValueExact", "()J");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named longValueExact with signature ()J." << std::endl;
			                return (jlong) -1;
			            } else {
			                retVal= (jlong)  env->CallLongMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint BigInteger::intValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method intValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "intValueExact", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named intValueExact with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jshort BigInteger::shortValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method shortValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jshort) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jshort retVal=(jshort) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "shortValueExact", "()S");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named shortValueExact with signature ()S." << std::endl;
			                return (jshort) -1;
			            } else {
			                retVal= (jshort)  env->CallShortMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jbyte BigInteger::byteValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method byteValueExact of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jbyte) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jbyte retVal= (jbyte) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "byteValueExact", "()B");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named byteValueExact with signature ()B." << std::endl;
			                return (jbyte) -1;
			            } else {
			                retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::mod(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method mod of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "mod", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named mod with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::notMethod() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method not of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "not", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named not with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::add(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method add of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "add", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named add with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			jint BigInteger::bitCount() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method bitCount of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "bitCount", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named bitCount with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jstring BigInteger::toString() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toString of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named toString with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jstring BigInteger::toString(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toString of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toString", "(I)Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named toString with signature (I)Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			jint BigInteger::hashCode() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method hashCode of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named hashCode with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::abs() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method abs of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "abs", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named abs with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::pow(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method pow of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "pow", "(I)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named pow with signature (I)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::min(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method min of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "min", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named min with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::max(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method max of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "max", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named max with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			jint BigInteger::compareTo(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method compareTo of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/math/BigInteger;)I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named compareTo with signature (Ljava/math/BigInteger;)I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			jint BigInteger::intValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method intValue of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "intValue", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named intValue with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jlong BigInteger::longValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method longValue of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jlong) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jlong retVal= (jlong) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "longValue", "()J");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named longValue with signature ()J." << std::endl;
			                return (jlong) -1;
			            } else {
			                retVal= (jlong)  env->CallLongMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jfloat BigInteger::floatValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method floatValue of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jfloat) -1.0;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jfloat retVal= (jfloat) -1.0;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "floatValue", "()F");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named floatValue with signature ()F." << std::endl;
			                return (jfloat) -1.0;
			            } else {
			                retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jdouble BigInteger::doubleValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method doubleValue of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jdouble) -1.0
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jdouble retVal= (jdouble) -1.0
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "doubleValue", "()D");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named doubleValue with signature ()D." << std::endl;
			                return (jdouble) -1.0
			            } else {
			                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::valueOf(jlong long_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(J)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named valueOf with signature (J)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,long_0 );
			            }
			        }
			}
			jint BigInteger::signum() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method signum of java.math.BigInteger with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "signum", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named signum with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::shiftLeft(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method shiftLeft of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "shiftLeft", "(I)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named shiftLeft with signature (I)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::divide(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method divide of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named divide with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::remainder(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method remainder of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "remainder", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named remainder with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::andMethod(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method and of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "and", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named and with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::orMethod(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method or of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "or", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named or with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::xorMethod(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method xor of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "xor", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named xor with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			BigInteger BigInteger::andNot(BigInteger bigInteger_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method andNot of java.math.BigInteger with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigIntegerClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "andNot", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigInteger has no method named andNot with signature (Ljava/math/BigInteger;)Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid ,bigInteger_0 );
			            }
			        }
			        return retVal;
			}
			static jclass getNewBigIntegerClass() {
			    jclass clss = getEnv()->FindClass("java/math/BigInteger");
			    if (NULL == clss) {
			        std::cerr << " Can't find class java/math/BigInteger" << std::endl;
			    }
			    return clss;
			}
			
			static jclass BigIntegerClass = NULL;
			static inline jclass getBigIntegerClass() {
			    if (BigIntegerClass != NULL) {
			        return BigIntegerClass;
			    }
			    BigIntegerClass = getNewBigIntegerClass();
			}
		} // end namespace java
	} // end namespace math
		namespace java{
			namespace math{
			
			// get JNI handle for class java.math.BigDecimal
			static inline jclass getBigDecimalClass();
			
			BigDecimal::BigDecimal(jobject _jthis): java::lang::Object(_jthis) {
			        // Place holder for future extensibility
			}
			BigDecimal::BigDecimal(jdouble double_0) {
				JNIEnv *env =getEnv();
				jclass cls = getBigDecimalClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(D)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigDecimal has no method constructor signature (D)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,double_0);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}

			BigDecimal::BigDecimal(jint int_0) {
				JNIEnv *env =getEnv();
				jclass cls = getBigDecimalClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(I)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigDecimal has no method constructor signature (I)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,int_0);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}

			BigDecimal::BigDecimal(jlong long_0) {
				JNIEnv *env =getEnv();
				jclass cls = getBigDecimalClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(J)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigDecimal has no method constructor signature (J)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,long_0);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}

			BigDecimal::BigDecimal(BigInteger bigInteger_0,jint int_1) {
				JNIEnv *env =getEnv();
				jclass cls = getBigDecimalClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/math/BigInteger;I)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigDecimal has no method constructor signature (Ljava/math/BigInteger;I)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,bigInteger_0,int_1);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}

			BigDecimal::BigDecimal(BigInteger bigInteger_0) {
				JNIEnv *env =getEnv();
				jclass cls = getBigDecimalClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/math/BigInteger;)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigDecimal has no method constructor signature (Ljava/math/BigInteger;)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,bigInteger_0);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}

			BigDecimal::BigDecimal(jstring string_0) {
				JNIEnv *env =getEnv();
				jclass cls = getBigDecimalClass();
				if (cls != NULL) {
				    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
				    if (NULL == mid) {
				        std::cerr << "Class BigDecimal has no method constructor signature (Ljava/lang/String;)V" << std::endl;
				    } else {
				        jthis = env->NewObject(cls, mid ,string_0);
				        jobjectRefType ref = env->GetObjectRefType(jthis);
				        if(ref != JNIGlobalRefType) {
				            jthis = env->NewGlobalRef(jthis);
				        }
				    }
				}
			}


			// Destructor for java.math.BigDecimal
			BigDecimal::~BigDecimal() {
				// Place-holder for later extensibility.
			}

			BigDecimal BigDecimal::subtract(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method subtract of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "subtract", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named subtract with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::multiply(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method multiply of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "multiply", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named multiply with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::negate() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method negate of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "negate", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named negate with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jlong BigDecimal::longValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method longValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jlong) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jlong retVal= (jlong) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "longValueExact", "()J");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named longValueExact with signature ()J." << std::endl;
			                return (jlong) -1;
			            } else {
			                retVal= (jlong)  env->CallLongMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint BigDecimal::intValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method intValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "intValueExact", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named intValueExact with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jshort BigDecimal::shortValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method shortValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jshort) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jshort retVal=(jshort) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "shortValueExact", "()S");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named shortValueExact with signature ()S." << std::endl;
			                return (jshort) -1;
			            } else {
			                retVal= (jshort)  env->CallShortMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jbyte BigDecimal::byteValueExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method byteValueExact of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jbyte) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jbyte retVal= (jbyte) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "byteValueExact", "()B");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named byteValueExact with signature ()B." << std::endl;
			                return (jbyte) -1;
			            } else {
			                retVal= (jbyte)  env->CallByteMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigDecimal::toBigInteger() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toBigInteger of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toBigInteger", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named toBigInteger with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint BigDecimal::precision() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method precision of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "precision", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named precision with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::divideToIntegralValue(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method divideToIntegralValue of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "divideToIntegralValue", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named divideToIntegralValue with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::plus() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method plus of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "plus", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named plus with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigDecimal::unscaledValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method unscaledValue of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "unscaledValue", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named unscaledValue with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::setScale(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setScale of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setScale", "(I)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named setScale with signature (I)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::setScale(jint int_0,jint int_1) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method setScale of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "setScale", "(II)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named setScale with signature (II)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,int_0,int_1 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::movePointLeft(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method movePointLeft of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "movePointLeft", "(I)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named movePointLeft with signature (I)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::movePointRight(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method movePointRight of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "movePointRight", "(I)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named movePointRight with signature (I)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::scaleByPowerOfTen(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method scaleByPowerOfTen of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "scaleByPowerOfTen", "(I)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named scaleByPowerOfTen with signature (I)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::stripTrailingZeros() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method stripTrailingZeros of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "stripTrailingZeros", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named stripTrailingZeros with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jstring BigDecimal::toEngineeringString() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toEngineeringString of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toEngineeringString", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named toEngineeringString with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jstring BigDecimal::toPlainString() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toPlainString of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toPlainString", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named toPlainString with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigInteger BigDecimal::toBigIntegerExact() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toBigIntegerExact of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toBigIntegerExact", "()Ljava/math/BigInteger;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named toBigIntegerExact with signature ()Ljava/math/BigInteger;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigInteger)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::add(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method add of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "add", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named add with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			jstring BigDecimal::toString() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method toString of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jstring retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named toString with signature ()Ljava/lang/String;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint BigDecimal::hashCode() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method hashCode of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named hashCode with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::abs() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method abs of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "abs", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named abs with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::pow(jint int_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method pow of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "pow", "(I)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named pow with signature (I)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,int_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::min(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method min of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "min", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named min with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::max(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method max of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "max", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named max with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			jint BigDecimal::compareTo(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method compareTo of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "compareTo", "(Ljava/math/BigDecimal;)I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named compareTo with signature (Ljava/math/BigDecimal;)I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			jint BigDecimal::intValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method intValue of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "intValue", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named intValue with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jlong BigDecimal::longValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method longValue of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jlong) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jlong retVal= (jlong) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "longValue", "()J");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named longValue with signature ()J." << std::endl;
			                return (jlong) -1;
			            } else {
			                retVal= (jlong)  env->CallLongMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jfloat BigDecimal::floatValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method floatValue of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jfloat) -1.0;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jfloat retVal= (jfloat) -1.0;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "floatValue", "()F");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named floatValue with signature ()F." << std::endl;
			                return (jfloat) -1.0;
			            } else {
			                retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jdouble BigDecimal::doubleValue() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method doubleValue of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jdouble) -1.0
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jdouble retVal= (jdouble) -1.0
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "doubleValue", "()D");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named doubleValue with signature ()D." << std::endl;
			                return (jdouble) -1.0
			            } else {
			                retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::valueOf(jlong long_0,jint int_1) {

			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(JI)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named valueOf with signature (JI)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,long_0,int_1 );
			            }
			        }
			}
			BigDecimal BigDecimal::valueOf(jlong long_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(J)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named valueOf with signature (J)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,long_0 );
			            }
			        }
			}
			BigDecimal BigDecimal::valueOf(jdouble double_0) {

			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        if (cls != NULL) {
			            jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(D)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named valueOf with signature (D)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                return env->CallStaticObjectMethod( cls, mid ,double_0 );
			            }
			        }
			}
			jint BigDecimal::signum() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method signum of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "signum", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named signum with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::divide(BigDecimal bigDecimal_0,jint int_1,jint int_2) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method divide of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigDecimal;II)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named divide with signature (Ljava/math/BigDecimal;II)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0,int_1,int_2 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::divide(BigDecimal bigDecimal_0,jint int_1) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method divide of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigDecimal;I)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named divide with signature (Ljava/math/BigDecimal;I)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0,int_1 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::divide(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method divide of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "divide", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named divide with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::remainder(BigDecimal bigDecimal_0) {

			        if(jthis == NULL) {
			            std::cerr << "Call of method remainder of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "remainder", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named remainder with signature (Ljava/math/BigDecimal;)Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid ,bigDecimal_0 );
			            }
			        }
			        return retVal;
			}
			BigDecimal BigDecimal::ulp() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method ulp of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return NULL;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jobject retVal=NULL;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "ulp", "()Ljava/math/BigDecimal;");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named ulp with signature ()Ljava/math/BigDecimal;." << std::endl;
			                return NULL;
			            } else {
			                retVal= (BigDecimal)  env->CallObjectMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			jint BigDecimal::scale() {

			        if(jthis == NULL) {
			            std::cerr << "Call of method scale of java.math.BigDecimal with jthis == NULL." << std::endl;
			            return (jint) -1;
			        }
			        JNIEnv *env =getEnv();
			        jclass cls = getBigDecimalClass();
			        jint retVal= (jint) -1;
			        if (cls != NULL) {
			            jmethodID mid = env->GetMethodID(cls, "scale", "()I");
			            if (NULL == mid) {
			                std::cerr << "Class java.math.BigDecimal has no method named scale with signature ()I." << std::endl;
			                return (jint) -1;
			            } else {
			                retVal= (jint)  env->CallIntMethod(jthis, mid  );
			            }
			        }
			        return retVal;
			}
			static jclass getNewBigDecimalClass() {
			    jclass clss = getEnv()->FindClass("java/math/BigDecimal");
			    if (NULL == clss) {
			        std::cerr << " Can't find class java/math/BigDecimal" << std::endl;
			    }
			    return clss;
			}
			
			static jclass BigDecimalClass = NULL;
			static inline jclass getBigDecimalClass() {
			    if (BigDecimalClass != NULL) {
			        return BigDecimalClass;
			    }
			    BigDecimalClass = getNewBigDecimalClass();
			}
		} // end namespace java
	} // end namespace math
		namespace javax{
			namespace xml{
				namespace bind{
				
				// get JNI handle for class javax.xml.bind.JAXBElement
				static inline jclass getJAXBElementClass();
				
				JAXBElement::JAXBElement(jobject _jthis): java::lang::Object(_jthis) {
				        // Place holder for future extensibility
				}

				// Destructor for javax.xml.bind.JAXBElement
				JAXBElement::~JAXBElement() {
					// Place-holder for later extensibility.
				}

				jboolean JAXBElement::isNil() {

				        if(jthis == NULL) {
				            std::cerr << "Call of method isNil of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
				            return false;
				        }
				        JNIEnv *env =getEnv();
				        jclass cls = getJAXBElementClass();
				        boolean retVal=false;
				        if (cls != NULL) {
				            jmethodID mid = env->GetMethodID(cls, "isNil", "()Z");
				            if (NULL == mid) {
				                std::cerr << "Class javax.xml.bind.JAXBElement has no method named isNil with signature ()Z." << std::endl;
				                return false;
				            } else {
				                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
				            }
				        }
				        return retVal;
				}
				void JAXBElement::setNil(jboolean boolean_0) {

				        if(jthis == NULL) {
				            std::cerr << "Call of method setNil of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
				            
				        }
				        JNIEnv *env =getEnv();
				        jclass cls = getJAXBElementClass();
				        
				        if (cls != NULL) {
				            jmethodID mid = env->GetMethodID(cls, "setNil", "(Z)V");
				            if (NULL == mid) {
				                std::cerr << "Class javax.xml.bind.JAXBElement has no method named setNil with signature (Z)V." << std::endl;
				                
				            } else {
				                 env->CallVoidMethod(jthis, mid ,boolean_0 );
				            }
				        }
				        
				}
				jboolean JAXBElement::isGlobalScope() {

				        if(jthis == NULL) {
				            std::cerr << "Call of method isGlobalScope of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
				            return false;
				        }
				        JNIEnv *env =getEnv();
				        jclass cls = getJAXBElementClass();
				        boolean retVal=false;
				        if (cls != NULL) {
				            jmethodID mid = env->GetMethodID(cls, "isGlobalScope", "()Z");
				            if (NULL == mid) {
				                std::cerr << "Class javax.xml.bind.JAXBElement has no method named isGlobalScope with signature ()Z." << std::endl;
				                return false;
				            } else {
				                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
				            }
				        }
				        return retVal;
				}
				jboolean JAXBElement::isTypeSubstituted() {

				        if(jthis == NULL) {
				            std::cerr << "Call of method isTypeSubstituted of javax.xml.bind.JAXBElement with jthis == NULL." << std::endl;
				            return false;
				        }
				        JNIEnv *env =getEnv();
				        jclass cls = getJAXBElementClass();
				        boolean retVal=false;
				        if (cls != NULL) {
				            jmethodID mid = env->GetMethodID(cls, "isTypeSubstituted", "()Z");
				            if (NULL == mid) {
				                std::cerr << "Class javax.xml.bind.JAXBElement has no method named isTypeSubstituted with signature ()Z." << std::endl;
				                return false;
				            } else {
				                retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
				            }
				        }
				        return retVal;
				}
				static jclass getNewJAXBElementClass() {
				    jclass clss = getEnv()->FindClass("javax/xml/bind/JAXBElement");
				    if (NULL == clss) {
				        std::cerr << " Can't find class javax/xml/bind/JAXBElement" << std::endl;
				    }
				    return clss;
				}
				
				static jclass JAXBElementClass = NULL;
				static inline jclass getJAXBElementClass() {
				    if (JAXBElementClass != NULL) {
				        return JAXBElementClass;
				    }
				    JAXBElementClass = getNewJAXBElementClass();
				}
			} // end namespace javax
		} // end namespace xml
	} // end namespace bind

        static bool debug_j4cpp = false;
        static JNIEnv *getNewEnv() {
            JavaVM *jvm; /* denotes a Java VM */
            JNIEnv *env; /* pointer to native method interface */
            JavaVM * jvmBuf[1];
            jsize nVMs;
            debug_j4cpp = (getenv("DEBUG_J4CPP") != NULL);
            char *classPathEnv = getenv("CLASSPATH");       
            char *jvmOptionsEnv = getenv("JVM_OPTIONS");
            std::string str;
            str += "/home/shackle/crac/CRCLJavaBase/target/CRCLJavaBase-1.0-SNAPSHOT.jar";
            if(classPathEnv!=NULL) {
                std::string classPathEnvStr(classPathEnv);
                if(debug_j4cpp) std::cout << "classPathEnv=" << classPathEnvStr << std::endl;
                str += ":";
                str += classPathEnvStr;
            }
            if(debug_j4cpp) std::cout << "str=" << str << std::endl;
            setenv("CLASSPATH",str.c_str(),1);
            std::string optsString;
            optsString+="-Djava.class.path=";
            optsString+=str;
            if(jvmOptionsEnv != NULL) {
                std::string jvmOptionsEnvStr(jvmOptionsEnv);
                if(debug_j4cpp) std::cout << "jvmOptionsEnvStr=" << jvmOptionsEnvStr << std::endl;
                optsString += " ";
                optsString += jvmOptionsEnvStr;
            }
            if(debug_j4cpp) std::cout << "optsString=" << optsString << std::endl;
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

// end namespace crcljavabase1
}

