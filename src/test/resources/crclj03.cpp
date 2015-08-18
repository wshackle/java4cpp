
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace javax{
   namespace swing{
   
   // get JNI handle for class javax.swing.JPanel
   static inline jclass getJPanelClass();
   
   JPanel::JPanel(jobject _jthis, bool copy): JComponent(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JPanel::JPanel(const JPanel &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JPanel::JPanel(jboolean boolean_0) : JComponent((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJPanelClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Z)V");
        if (NULL == mid) {
            std::cerr << "Class JPanel has no method constructor signature (Z)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,boolean_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JPanel::disable jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JPanel with signature (Z)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JPanel jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   JPanel::JPanel() : JComponent((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJPanelClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JPanel has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JPanel::disable jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JPanel with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JPanel jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for javax.swing.JPanel
   JPanel::~JPanel() {
   	// Place-holder for later extensibility.
   }

   void JPanel::updateUI() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method updateUI of javax.swing.JPanel with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JPanel::updateUI jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "updateUI", "()V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JPanel has no method named updateUI with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JPanel::updateUI jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring JPanel::getUIClassID() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getUIClassID of javax.swing.JPanel with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JPanel::getUIClassID jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getUIClassID", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JPanel has no method named getUIClassID with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JPanel::getUIClassID jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewJPanelClass() {
       jclass clss = getEnv()->FindClass("javax/swing/JPanel");
       if (NULL == clss) {
           std::cerr << " Can't find class javax/swing/JPanel" << std::endl;
       }
       return clss;
   }
   
   static jclass JPanelClass = NULL;
   static inline jclass getJPanelClass() {
       if (JPanelClass != NULL) {
           return JPanelClass;
       }
       JPanelClass = getNewJPanelClass();
   }
  } // end namespace swing
 } // end namespace javax

  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.OverHeadJPanel
   static inline jclass getOverHeadJPanelClass();
   
   OverHeadJPanel::OverHeadJPanel(jobject _jthis, bool copy): ::crclj::javax::swing::JPanel(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   OverHeadJPanel::OverHeadJPanel(const OverHeadJPanel &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   OverHeadJPanel::OverHeadJPanel() : ::crclj::javax::swing::JPanel((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getOverHeadJPanelClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class OverHeadJPanel has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::getUIClassID jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new OverHeadJPanel with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new OverHeadJPanel jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.OverHeadJPanel
   OverHeadJPanel::~OverHeadJPanel() {
   	// Place-holder for later extensibility.
   }

   jdoubleArray OverHeadJPanel::getJointvals() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointvals of crcl.utils.OverHeadJPanel with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::getJointvals jthis=",jthis);
   jdoubleArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointvals", "()[D");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.OverHeadJPanel has no method named getJointvals with signature ()[D." << std::endl;
           return NULL;
       } else {
           retVal= (jdoubleArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::getJointvals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void OverHeadJPanel::setJointvals(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointvals of crcl.utils.OverHeadJPanel with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::setJointvals jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointvals", "([D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.OverHeadJPanel has no method named setJointvals with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::setJointvals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void OverHeadJPanel::setJointvals(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setJointvals of crcl.utils.OverHeadJPanel with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::setJointvals jthis=",jthis);
    
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    setJointvals(doubleArray_0);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
   }

   void OverHeadJPanel::setSeglengths(jdoubleArray doubleArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSeglengths of crcl.utils.OverHeadJPanel with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::setSeglengths jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSeglengths", "([D)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.OverHeadJPanel has no method named setSeglengths with signature ([D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,doubleArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::setSeglengths jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void OverHeadJPanel::setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setSeglengths of crcl.utils.OverHeadJPanel with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OverHeadJPanel::setSeglengths jthis=",jthis);
    
            
    jdoubleArray doubleArray_0= env->NewDoubleArray(easyArg_0_length);
    env->SetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    setSeglengths(doubleArray_0);
    env->GetDoubleArrayRegion(doubleArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(doubleArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(doubleArray_0);
    }
    
    releaseEnv(env);
   }

   static jclass getNewOverHeadJPanelClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/OverHeadJPanel");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/OverHeadJPanel" << std::endl;
       }
       return clss;
   }
   
   static jclass OverHeadJPanelClass = NULL;
   static inline jclass getOverHeadJPanelClass() {
       if (OverHeadJPanelClass != NULL) {
           return OverHeadJPanelClass;
       }
       OverHeadJPanelClass = getNewOverHeadJPanelClass();
   }
  } // end namespace utils

   namespace base{
   
   // get JNI handle for class crcl.base.CloseToolChangerType
   static inline jclass getCloseToolChangerTypeClass();
   
   CloseToolChangerType::CloseToolChangerType(jobject _jthis, bool copy): MiddleCommandType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CloseToolChangerType::CloseToolChangerType(const CloseToolChangerType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CloseToolChangerType::CloseToolChangerType() : MiddleCommandType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCloseToolChangerTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CloseToolChangerType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CloseToolChangerType::setSeglengths jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CloseToolChangerType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CloseToolChangerType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
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
   
   // get JNI handle for class crcl.base.ParameterSettingType
   static inline jclass getParameterSettingTypeClass();
   
   ParameterSettingType::ParameterSettingType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ParameterSettingType::ParameterSettingType(const ParameterSettingType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ParameterSettingType::ParameterSettingType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getParameterSettingTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class ParameterSettingType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setSeglengths jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new ParameterSettingType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ParameterSettingType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.ParameterSettingType
   ParameterSettingType::~ParameterSettingType() {
   	// Place-holder for later extensibility.
   }

   jstring ParameterSettingType::getParameterName() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getParameterName of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::getParameterName jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getParameterName", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ParameterSettingType has no method named getParameterName with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::getParameterName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void ParameterSettingType::setParameterName(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setParameterName of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setParameterName jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setParameterName", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ParameterSettingType has no method named setParameterName with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setParameterName jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void ParameterSettingType::setParameterName(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setParameterName of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setParameterName jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setParameterName(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jstring ParameterSettingType::getParameterValue() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getParameterValue of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::getParameterValue jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getParameterValue", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ParameterSettingType has no method named getParameterValue with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::getParameterValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void ParameterSettingType::setParameterValue(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setParameterValue of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setParameterValue jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setParameterValue", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.ParameterSettingType has no method named setParameterValue with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setParameterValue jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void ParameterSettingType::setParameterValue(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setParameterValue of crcl.base.ParameterSettingType with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ParameterSettingType::setParameterValue jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setParameterValue(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
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
   
   // get JNI handle for class crcl.base.CRCLStatusType
   static inline jclass getCRCLStatusTypeClass();
   
   CRCLStatusType::CRCLStatusType(jobject _jthis, bool copy): DataThingType(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   CRCLStatusType::CRCLStatusType(const CRCLStatusType &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   CRCLStatusType::CRCLStatusType() : DataThingType((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getCRCLStatusTypeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class CRCLStatusType has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setParameterValue jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new CRCLStatusType with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new CRCLStatusType jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.base.CRCLStatusType
   CRCLStatusType::~CRCLStatusType() {
   	// Place-holder for later extensibility.
   }

   JointStatusesType CRCLStatusType::getJointStatuses() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getJointStatuses of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       JointStatusesType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getJointStatuses jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getJointStatuses", "()Lcrcl/base/JointStatusesType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named getJointStatuses with signature ()Lcrcl/base/JointStatusesType;." << std::endl;
           JointStatusesType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getJointStatuses jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    JointStatusesType retObject(retVal,false);
    return retObject;
   }
   CommandStatusType CRCLStatusType::getCommandStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCommandStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       CommandStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getCommandStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCommandStatus", "()Lcrcl/base/CommandStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named getCommandStatus with signature ()Lcrcl/base/CommandStatusType;." << std::endl;
           CommandStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getCommandStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    CommandStatusType retObject(retVal,false);
    return retObject;
   }
   PoseType CRCLStatusType::getPose() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getPose of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       PoseType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getPose jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getPose", "()Lcrcl/base/PoseType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named getPose with signature ()Lcrcl/base/PoseType;." << std::endl;
           PoseType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PoseType retObject(retVal,false);
    return retObject;
   }
   void CRCLStatusType::setCommandStatus(CommandStatusType  &commandStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCommandStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setCommandStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCommandStatus", "(Lcrcl/base/CommandStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named setCommandStatus with signature (Lcrcl/base/CommandStatusType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,commandStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setCommandStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLStatusType::setJointStatuses(JointStatusesType  &jointStatusesType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setJointStatuses of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setJointStatuses jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setJointStatuses", "(Lcrcl/base/JointStatusesType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named setJointStatuses with signature (Lcrcl/base/JointStatusesType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,jointStatusesType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setJointStatuses jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void CRCLStatusType::setPose(PoseType  &poseType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setPose of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setPose jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setPose", "(Lcrcl/base/PoseType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named setPose with signature (Lcrcl/base/PoseType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,poseType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setPose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   GripperStatusType CRCLStatusType::getGripperStatus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getGripperStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       GripperStatusType nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getGripperStatus jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getGripperStatus", "()Lcrcl/base/GripperStatusType;");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named getGripperStatus with signature ()Lcrcl/base/GripperStatusType;." << std::endl;
           GripperStatusType nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::getGripperStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    GripperStatusType retObject(retVal,false);
    return retObject;
   }
   void CRCLStatusType::setGripperStatus(GripperStatusType  &gripperStatusType_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setGripperStatus of crcl.base.CRCLStatusType with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setGripperStatus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setGripperStatus", "(Lcrcl/base/GripperStatusType;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.base.CRCLStatusType has no method named setGripperStatus with signature (Lcrcl/base/GripperStatusType;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,gripperStatusType_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," CRCLStatusType::setGripperStatus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
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
  } // end namespace base
 } // end namespace crcl



    // end namespace crclj
}

