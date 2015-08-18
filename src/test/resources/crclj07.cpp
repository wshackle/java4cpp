
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.ListChooserJPanel
   static inline jclass getListChooserJPanelClass();
   
   ListChooserJPanel::ListChooserJPanel(jobject _jthis, bool copy): ::crclj::javax::swing::JPanel(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   ListChooserJPanel::ListChooserJPanel(const ListChooserJPanel &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   ListChooserJPanel::ListChooserJPanel() : ::crclj::javax::swing::JPanel((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getListChooserJPanelClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class ListChooserJPanel has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ListChooserJPanel::queryXmlString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new ListChooserJPanel with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new ListChooserJPanel jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for crcl.utils.ListChooserJPanel
   ListChooserJPanel::~ListChooserJPanel() {
   	// Place-holder for later extensibility.
   }

   ::crclj::java::lang::Object ListChooserJPanel::getSelectedChoice() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getSelectedChoice of crcl.utils.ListChooserJPanel with jthis == NULL." << std::endl;
       ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," ListChooserJPanel::getSelectedChoice jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getSelectedChoice", "()Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ListChooserJPanel has no method named getSelectedChoice with signature ()Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ListChooserJPanel::getSelectedChoice jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::lang::Object retObject(retVal,false);
    return retObject;
   }
   ::crclj::java::lang::Object ListChooserJPanel::Choose(::crclj::java::awt::Frame  &frame_0,jstring string_1,jobjectArray objectArray_2,::crclj::java::lang::Object  &object_3) {

   JNIEnv *env =getEnv();
   static jclass cls = getListChooserJPanelClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "Choose", "(Ljava/awt/Frame;Ljava/lang/String;[Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.ListChooserJPanel has no method named Choose with signature (Ljava/awt/Frame;Ljava/lang/String;[Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;." << std::endl;
           ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,frame_0.jthis,string_1,objectArray_2,object_3.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," ListChooserJPanel::Choose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::lang::Object retObject(retVal,false);
    return retObject;
   }
   static jclass getNewListChooserJPanelClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/ListChooserJPanel");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/ListChooserJPanel" << std::endl;
       }
       return clss;
   }
   
   static jclass ListChooserJPanelClass = NULL;
   static inline jclass getListChooserJPanelClass() {
       if (ListChooserJPanelClass != NULL) {
           return ListChooserJPanelClass;
       }
       ListChooserJPanelClass = getNewListChooserJPanelClass();
   }
  } // end namespace utils
 } // end namespace crcl

  namespace java{
   namespace awt{
   
   // get JNI handle for class java.awt.Window
   static inline jclass getWindowClass();
   
   Window::Window(jobject _jthis, bool copy): Container(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Window::Window(const Window &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   Window::Window() : Container((jobject)NULL,false) {
   JNIEnv *env =getEnv();
   static jclass cls = getWindowClass();
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
       if (NULL == mid) {
           std::cerr << "Class Window has no method constructor signature ()V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::Choose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Window with signature ()V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Window jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   releaseEnv(env);
   }


   // Destructor for java.awt.Window
   Window::~Window() {
   	// Place-holder for later extensibility.
   }

   void Window::addNotify() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method addNotify of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::addNotify jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "addNotify", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named addNotify with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::addNotify jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::setOpacity(jfloat float_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setOpacity of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setOpacity jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setOpacity", "(F)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setOpacity with signature (F)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,float_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setOpacity jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::removeNotify() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method removeNotify of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::removeNotify jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "removeNotify", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named removeNotify with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::removeNotify jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jfloat Window::getOpacity() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getOpacity of java.awt.Window with jthis == NULL." << std::endl;
       return (jfloat) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getOpacity jthis=",jthis);
   jfloat retVal= (jfloat) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getOpacity", "()F");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getOpacity with signature ()F." << std::endl;
           return (jfloat) -1.0;
       } else {
           retVal= (jfloat)  env->CallFloatMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getOpacity jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray Window::getWindows() {

   JNIEnv *env =getEnv();
   static jclass cls = getWindowClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getWindows", "()[Ljava/awt/Window;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getWindows with signature ()[Ljava/awt/Window;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getWindows jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::util::List Window::getIconImages() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getIconImages of java.awt.Window with jthis == NULL." << std::endl;
       ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getIconImages jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getIconImages", "()Ljava/util/List;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getIconImages with signature ()Ljava/util/List;." << std::endl;
           ::crclj::java::util::List nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getIconImages jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::util::List retObject(retVal,false);
    return retObject;
   }
   void Window::setIconImages(::crclj::java::util::List  &list_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setIconImages of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setIconImages jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setIconImages", "(Ljava/util/List;)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setIconImages with signature (Ljava/util/List;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,list_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setIconImages jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::setLocation(jint int_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLocation of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setLocation jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setLocation", "(II)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setLocation with signature (II)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setLocation jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::reshape(jint int_0,jint int_1,jint int_2,jint int_3) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method reshape of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::reshape jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "reshape", "(IIII)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named reshape with signature (IIII)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0,int_1,int_2,int_3 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::reshape jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::show() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method show of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::show jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "show", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named show with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::show jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::hide() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hide of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::hide jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "hide", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named hide with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::hide jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::toFront() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toFront of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::toFront jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toFront", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named toFront with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::toFront jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::toBack() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toBack of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::toBack jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toBack", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named toBack with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::toBack jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring Window::getWarningString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getWarningString of java.awt.Window with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getWarningString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getWarningString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getWarningString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getWarningString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray Window::getOwnedWindows() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getOwnedWindows of java.awt.Window with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getOwnedWindows jthis=",jthis);
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getOwnedWindows", "()[Ljava/awt/Window;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getOwnedWindows with signature ()[Ljava/awt/Window;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getOwnedWindows jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray Window::getOwnerlessWindows() {

   JNIEnv *env =getEnv();
   static jclass cls = getWindowClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getOwnerlessWindows", "()[Ljava/awt/Window;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getOwnerlessWindows with signature ()[Ljava/awt/Window;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getOwnerlessWindows jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Window::setAlwaysOnTop(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setAlwaysOnTop of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setAlwaysOnTop jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setAlwaysOnTop", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setAlwaysOnTop with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setAlwaysOnTop jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean Window::isAlwaysOnTopSupported() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAlwaysOnTopSupported of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isAlwaysOnTopSupported jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAlwaysOnTopSupported", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isAlwaysOnTopSupported with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isAlwaysOnTopSupported jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Window::isAlwaysOnTop() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAlwaysOnTop of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isAlwaysOnTop jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAlwaysOnTop", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isAlwaysOnTop with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isAlwaysOnTop jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   Component Window::getFocusOwner() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFocusOwner of java.awt.Window with jthis == NULL." << std::endl;
       Component nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getFocusOwner jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFocusOwner", "()Ljava/awt/Component;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getFocusOwner with signature ()Ljava/awt/Component;." << std::endl;
           Component nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getFocusOwner jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Component retObject(retVal,false);
    return retObject;
   }
   Component Window::getMostRecentFocusOwner() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getMostRecentFocusOwner of java.awt.Window with jthis == NULL." << std::endl;
       Component nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getMostRecentFocusOwner jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getMostRecentFocusOwner", "()Ljava/awt/Component;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getMostRecentFocusOwner with signature ()Ljava/awt/Component;." << std::endl;
           Component nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getMostRecentFocusOwner jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Component retObject(retVal,false);
    return retObject;
   }
   jboolean Window::isActive() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isActive of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isActive jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isActive", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isActive with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isActive jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Window::isFocused() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isFocused of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isFocused jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isFocused", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isFocused with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isFocused jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Window::setFocusCycleRoot(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFocusCycleRoot of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setFocusCycleRoot jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFocusCycleRoot", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setFocusCycleRoot with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setFocusCycleRoot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean Window::isFocusCycleRoot() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isFocusCycleRoot of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isFocusCycleRoot jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isFocusCycleRoot", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isFocusCycleRoot with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isFocusCycleRoot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   Container Window::getFocusCycleRootAncestor() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFocusCycleRootAncestor of java.awt.Window with jthis == NULL." << std::endl;
       Container nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getFocusCycleRootAncestor jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFocusCycleRootAncestor", "()Ljava/awt/Container;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getFocusCycleRootAncestor with signature ()Ljava/awt/Container;." << std::endl;
           Container nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getFocusCycleRootAncestor jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Container retObject(retVal,false);
    return retObject;
   }
   jboolean Window::isFocusableWindow() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isFocusableWindow of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isFocusableWindow jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isFocusableWindow", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isFocusableWindow with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isFocusableWindow jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Window::getFocusableWindowState() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getFocusableWindowState of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getFocusableWindowState jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getFocusableWindowState", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getFocusableWindowState with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getFocusableWindowState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Window::setFocusableWindowState(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setFocusableWindowState of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setFocusableWindowState jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setFocusableWindowState", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setFocusableWindowState with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setFocusableWindowState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::setAutoRequestFocus(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setAutoRequestFocus of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setAutoRequestFocus jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setAutoRequestFocus", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setAutoRequestFocus with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setAutoRequestFocus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean Window::isAutoRequestFocus() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isAutoRequestFocus of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isAutoRequestFocus jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isAutoRequestFocus", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isAutoRequestFocus with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isAutoRequestFocus jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Window::isValidateRoot() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isValidateRoot of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isValidateRoot jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isValidateRoot", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isValidateRoot with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isValidateRoot jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Window::isShowing() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isShowing of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isShowing jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isShowing", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isShowing with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isShowing jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Window::applyResourceBundle(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method applyResourceBundle of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::applyResourceBundle jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "applyResourceBundle", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named applyResourceBundle with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::applyResourceBundle jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::applyResourceBundle(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method applyResourceBundle of java.awt.Window with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::applyResourceBundle jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    applyResourceBundle(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   void Window::setLocationRelativeTo(Component  &component_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLocationRelativeTo of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setLocationRelativeTo jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setLocationRelativeTo", "(Ljava/awt/Component;)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setLocationRelativeTo with signature (Ljava/awt/Component;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,component_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setLocationRelativeTo jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::createBufferStrategy(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method createBufferStrategy of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::createBufferStrategy jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "createBufferStrategy", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named createBufferStrategy with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::createBufferStrategy jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::setLocationByPlatform(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLocationByPlatform of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setLocationByPlatform jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setLocationByPlatform", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setLocationByPlatform with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setLocationByPlatform jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean Window::isLocationByPlatform() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isLocationByPlatform of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isLocationByPlatform jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isLocationByPlatform", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isLocationByPlatform with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isLocationByPlatform jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Window::setBounds(jint int_0,jint int_1,jint int_2,jint int_3) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setBounds of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setBounds jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setBounds", "(IIII)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setBounds with signature (IIII)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0,int_1,int_2,int_3 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setBounds jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::dispose() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method dispose of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::dispose jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "dispose", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named dispose with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::dispose jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::pack() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method pack of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::pack jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "pack", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named pack with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::pack jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Window::setVisible(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setVisible of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setVisible jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setVisible", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setVisible with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setVisible jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean Window::isOpaque() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isOpaque of java.awt.Window with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::isOpaque jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isOpaque", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named isOpaque with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::isOpaque jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Window::setSize(jint int_0,jint int_1) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setSize of java.awt.Window with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::setSize jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setSize", "(II)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named setSize with signature (II)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0,int_1 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::setSize jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   Window Window::getOwner() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getOwner of java.awt.Window with jthis == NULL." << std::endl;
       Window nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Window::getOwner jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getOwner", "()Ljava/awt/Window;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Window has no method named getOwner with signature ()Ljava/awt/Window;." << std::endl;
           Window nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Window::getOwner jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    Window retObject(retVal,false);
    return retObject;
   }
   static jclass getNewWindowClass() {
       jclass clss = getEnv()->FindClass("java/awt/Window");
       if (NULL == clss) {
           std::cerr << " Can't find class java/awt/Window" << std::endl;
       }
       return clss;
   }
   
   static jclass WindowClass = NULL;
   static inline jclass getWindowClass() {
       if (WindowClass != NULL) {
           return WindowClass;
       }
       WindowClass = getNewWindowClass();
   }
   
   // get JNI handle for class java.awt.Frame
   static inline jclass getFrameClass();
   
   Frame::Frame(jobject _jthis, bool copy): Window(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   Frame::Frame(const Frame &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   Frame::Frame(jstring string_0) : Window((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class Frame has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Frame::getOwner jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Frame with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Frame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   Frame::Frame(const char * easyArg_0) : Window((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getFrameClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class Frame has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::getOwner jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new Frame with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Frame jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   jobjectRefType ref_0 = env->GetObjectRefType(string_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_0);
   }
   
   releaseEnv(env);
   }
   Frame::Frame() : Window((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Frame has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Frame::getOwner jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Frame with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Frame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.awt.Frame
   Frame::~Frame() {
   	// Place-holder for later extensibility.
   }

   void Frame::addNotify() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method addNotify of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::addNotify jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "addNotify", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named addNotify with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::addNotify jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring Frame::getTitle() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getTitle of java.awt.Frame with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::getTitle jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getTitle", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named getTitle with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::getTitle jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Frame::isResizable() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isResizable of java.awt.Frame with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::isResizable jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isResizable", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named isResizable with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::isResizable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Frame::setResizable(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setResizable of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setResizable jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setResizable", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setResizable with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setResizable jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Frame::setState(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setState of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setState jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setState", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setState with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Frame::setExtendedState(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setExtendedState of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setExtendedState jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setExtendedState", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setExtendedState with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setExtendedState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jint Frame::getExtendedState() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getExtendedState of java.awt.Frame with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::getExtendedState jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getExtendedState", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named getExtendedState with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::getExtendedState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jboolean Frame::isUndecorated() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method isUndecorated of java.awt.Frame with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::isUndecorated jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "isUndecorated", "()Z");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named isUndecorated with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::isUndecorated jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Frame::setOpacity(jfloat float_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setOpacity of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setOpacity jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setOpacity", "(F)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setOpacity with signature (F)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,float_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setOpacity jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Frame::removeNotify() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method removeNotify of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::removeNotify jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "removeNotify", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named removeNotify with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::removeNotify jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Frame::setCursor(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setCursor of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setCursor jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setCursor", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setCursor with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setCursor jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jint Frame::getCursorType() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getCursorType of java.awt.Frame with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::getCursorType jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getCursorType", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named getCursorType with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::getCursorType jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jobjectArray Frame::getFrames() {

   JNIEnv *env =getEnv();
   static jclass cls = getFrameClass();
   jobjectArray retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "getFrames", "()[Ljava/awt/Frame;");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named getFrames with signature ()[Ljava/awt/Frame;." << std::endl;
           return NULL;
       } else {
           retVal= (jobjectArray)  env->CallStaticObjectMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::getFrames jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void Frame::setUndecorated(jboolean boolean_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setUndecorated of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setUndecorated jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setUndecorated", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setUndecorated with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setUndecorated jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Frame::setTitle(jstring string_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTitle of java.awt.Frame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setTitle jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named setTitle with signature (Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::setTitle jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void Frame::setTitle(const char * easyArg_0) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method setTitle of java.awt.Frame with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::setTitle jthis=",jthis);
    
            
    jstring string_0 = env->NewStringUTF(easyArg_0);
    setTitle(string_0);
    jobjectRefType ref_0 = env->GetObjectRefType(string_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(string_0);
    }
    
    releaseEnv(env);
   }

   jint Frame::getState() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getState of java.awt.Frame with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Frame::getState jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getState", "()I");
       if (NULL == mid) {
           std::cerr << "Class java.awt.Frame has no method named getState with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," Frame::getState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewFrameClass() {
       jclass clss = getEnv()->FindClass("java/awt/Frame");
       if (NULL == clss) {
           std::cerr << " Can't find class java/awt/Frame" << std::endl;
       }
       return clss;
   }
   
   static jclass FrameClass = NULL;
   static inline jclass getFrameClass() {
       if (FrameClass != NULL) {
           return FrameClass;
       }
       FrameClass = getNewFrameClass();
   }
  } // end namespace awt
 } // end namespace java

  namespace javax{
   namespace swing{
   
   // get JNI handle for class javax.swing.JFrame
   static inline jclass getJFrameClass();
   
   JFrame::JFrame(jobject _jthis, bool copy): ::crclj::java::awt::Frame(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   JFrame::JFrame(const JFrame &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   JFrame::JFrame() : ::crclj::java::awt::Frame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class JFrame has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JFrame::getState jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JFrame with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JFrame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   JFrame::JFrame(jstring string_0) : ::crclj::java::awt::Frame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getJFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == mid) {
            std::cerr << "Class JFrame has no method constructor signature (Ljava/lang/String;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,string_0);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," JFrame::getState jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new JFrame with signature (Ljava/lang/String;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JFrame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   JFrame::JFrame(const char * easyArg_0) : ::crclj::java::awt::Frame((jobject)NULL,false) {
   // Convenience Constructor converts common C++ types to JNI types
   JNIEnv *env =getEnv();
   static jclass cls = getJFrameClass();
   jstring string_0 = env->NewStringUTF(easyArg_0);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class JFrame has no method constructor signature (Ljava/lang/String;)V" << std::endl;
       } else {
           jthis = env->NewObject(cls, mid ,string_0);
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::getState jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
           if(jthis == NULL) {
               std::cerr << "Call to create new JFrame with signature (Ljava/lang/String;)V returned null." << std::endl;
               releaseEnv(env);
               return;
           }
           jobjectRefType ref = env->GetObjectRefType(jthis);
           if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new JFrame jthis=",jthis);
           if(ref != JNIGlobalRefType) {
               jthis = env->NewGlobalRef(jthis);
           }
       }
   }
   jobjectRefType ref_0 = env->GetObjectRefType(string_0);
   if(ref_0 == JNIGlobalRefType) {
    env->DeleteGlobalRef(string_0);
   }
   
   releaseEnv(env);
   }

   // Destructor for javax.swing.JFrame
   JFrame::~JFrame() {
   	// Place-holder for later extensibility.
   }

   jint JFrame::getDefaultCloseOperation() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getDefaultCloseOperation of javax.swing.JFrame with jthis == NULL." << std::endl;
       return (jint) -1;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::getDefaultCloseOperation jthis=",jthis);
   jint retVal= (jint) -1;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getDefaultCloseOperation", "()I");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named getDefaultCloseOperation with signature ()I." << std::endl;
           return (jint) -1;
       } else {
           retVal= (jint)  env->CallIntMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::getDefaultCloseOperation jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void JFrame::setContentPane(::crclj::java::awt::Container  &container_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setContentPane of javax.swing.JFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::setContentPane jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setContentPane", "(Ljava/awt/Container;)V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named setContentPane with signature (Ljava/awt/Container;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,container_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::setContentPane jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   ::crclj::java::awt::Component JFrame::getGlassPane() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getGlassPane of javax.swing.JFrame with jthis == NULL." << std::endl;
       ::crclj::java::awt::Component nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::getGlassPane jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getGlassPane", "()Ljava/awt/Component;");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named getGlassPane with signature ()Ljava/awt/Component;." << std::endl;
           ::crclj::java::awt::Component nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::getGlassPane jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::awt::Component retObject(retVal,false);
    return retObject;
   }
   void JFrame::setGlassPane(::crclj::java::awt::Component  &component_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setGlassPane of javax.swing.JFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::setGlassPane jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setGlassPane", "(Ljava/awt/Component;)V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named setGlassPane with signature (Ljava/awt/Component;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,component_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::setGlassPane jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void JFrame::repaint(jlong long_0,jint int_1,jint int_2,jint int_3,jint int_4) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method repaint of javax.swing.JFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::repaint jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "repaint", "(JIIII)V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named repaint with signature (JIIII)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,long_0,int_1,int_2,int_3,int_4 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::repaint jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void JFrame::setDefaultLookAndFeelDecorated(jboolean boolean_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getJFrameClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "setDefaultLookAndFeelDecorated", "(Z)V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named setDefaultLookAndFeelDecorated with signature (Z)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,boolean_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::setDefaultLookAndFeelDecorated jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   jboolean JFrame::isDefaultLookAndFeelDecorated() {

   JNIEnv *env =getEnv();
   static jclass cls = getJFrameClass();
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "isDefaultLookAndFeelDecorated", "()Z");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named isDefaultLookAndFeelDecorated with signature ()Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallStaticBooleanMethod( cls, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::isDefaultLookAndFeelDecorated jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   ::crclj::java::awt::Container JFrame::getContentPane() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getContentPane of javax.swing.JFrame with jthis == NULL." << std::endl;
       ::crclj::java::awt::Container nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::getContentPane jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getContentPane", "()Ljava/awt/Container;");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named getContentPane with signature ()Ljava/awt/Container;." << std::endl;
           ::crclj::java::awt::Container nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::getContentPane jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    ::crclj::java::awt::Container retObject(retVal,false);
    return retObject;
   }
   void JFrame::setDefaultCloseOperation(jint int_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setDefaultCloseOperation of javax.swing.JFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::setDefaultCloseOperation jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setDefaultCloseOperation", "(I)V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named setDefaultCloseOperation with signature (I)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,int_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::setDefaultCloseOperation jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void JFrame::remove(::crclj::java::awt::Component  &component_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method remove of javax.swing.JFrame with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," JFrame::remove jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "remove", "(Ljava/awt/Component;)V");
       if (NULL == mid) {
           std::cerr << "Class javax.swing.JFrame has no method named remove with signature (Ljava/awt/Component;)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,component_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," JFrame::remove jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewJFrameClass() {
       jclass clss = getEnv()->FindClass("javax/swing/JFrame");
       if (NULL == clss) {
           std::cerr << " Can't find class javax/swing/JFrame" << std::endl;
       }
       return clss;
   }
   
   static jclass JFrameClass = NULL;
   static inline jclass getJFrameClass() {
       if (JFrameClass != NULL) {
           return JFrameClass;
       }
       JFrameClass = getNewJFrameClass();
   }
  } // end namespace swing
 } // end namespace javax

  namespace crcl{
   namespace utils{
   
   // get JNI handle for class crcl.utils.LauncherJFrame
   static inline jclass getLauncherJFrameClass();
   
   LauncherJFrame::LauncherJFrame(jobject _jthis, bool copy): ::crclj::javax::swing::JFrame(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   LauncherJFrame::LauncherJFrame(const LauncherJFrame &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   LauncherJFrame::LauncherJFrame() : ::crclj::javax::swing::JFrame((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getLauncherJFrameClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class LauncherJFrame has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," LauncherJFrame::remove jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new LauncherJFrame with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new LauncherJFrame jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for crcl.utils.LauncherJFrame
   LauncherJFrame::~LauncherJFrame() {
   	// Place-holder for later extensibility.
   }

   void LauncherJFrame::main(jobjectArray stringArray_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getLauncherJFrameClass();
   
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
       if (NULL == mid) {
           std::cerr << "Class crcl.utils.LauncherJFrame has no method named main with signature ([Ljava/lang/String;)V." << std::endl;
           return;
       } else {
            env->CallStaticVoidMethod( cls, mid ,stringArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," LauncherJFrame::main jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
   
   }
   void LauncherJFrame::main(int argc, const char **argv) {
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
   static jclass getNewLauncherJFrameClass() {
       jclass clss = getEnv()->FindClass("crcl/utils/LauncherJFrame");
       if (NULL == clss) {
           std::cerr << " Can't find class crcl/utils/LauncherJFrame" << std::endl;
       }
       return clss;
   }
   
   static jclass LauncherJFrameClass = NULL;
   static inline jclass getLauncherJFrameClass() {
       if (LauncherJFrameClass != NULL) {
           return LauncherJFrameClass;
       }
       LauncherJFrameClass = getNewLauncherJFrameClass();
   }
  } // end namespace utils
 } // end namespace crcl



    // end namespace crclj
}

