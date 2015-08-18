
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace rcs{
   namespace posemath{
   
   // get JNI handle for class rcs.posemath.PmRpy
   static inline jclass getPmRpyClass();
   
   PmRpy::PmRpy(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PmRpy::PmRpy(const PmRpy &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PmRpy::PmRpy(jdouble double_0,jdouble double_1,jdouble double_2) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRpyClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDD)V");
        if (NULL == mid) {
            std::cerr << "Class PmRpy has no method constructor signature (DDD)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0,double_1,double_2);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRpy::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRpy with signature (DDD)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRpy jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmRpy::PmRpy() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRpyClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PmRpy has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRpy::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRpy with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRpy jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmRpy::PmRpy(PmQuaternion  &pmQuaternion_0) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRpyClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmQuaternion;)V");
        if (NULL == mid) {
            std::cerr << "Class PmRpy has no method constructor signature (Lrcs/posemath/PmQuaternion;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmQuaternion_0.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRpy::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRpy with signature (Lrcs/posemath/PmQuaternion;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRpy jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for rcs.posemath.PmRpy
   PmRpy::~PmRpy() {
   	// Place-holder for later extensibility.
   }

   jdouble PmRpy::getY() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getY of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::getY jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getY", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named getY with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::getY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmRpy::setY(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setY of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::setY jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setY", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named setY with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::setY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PmRpy::getR() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getR of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::getR jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getR", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named getR with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::getR jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmRpy::norm() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method norm of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::norm jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "norm", "()V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named norm with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::norm jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PmRpy::getP() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getP of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::getP jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getP", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named getP with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::getP jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmRpy::setR(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setR of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::setR jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setR", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named setR with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::setR jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PmRpy::setP(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setP of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::setP jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setP", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named setP with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::setP jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jstring PmRpy::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   PmRpy PmRpy::clone() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clone of rcs.posemath.PmRpy with jthis == NULL." << std::endl;
       PmRpy nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRpy::clone jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "clone", "()Lrcs/posemath/PmRpy;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRpy has no method named clone with signature ()Lrcs/posemath/PmRpy;." << std::endl;
           PmRpy nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRpy::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRpy retObject(retVal,false);
    return retObject;
   }
   static jclass getNewPmRpyClass() {
       jclass clss = getEnv()->FindClass("rcs/posemath/PmRpy");
       if (NULL == clss) {
           std::cerr << " Can't find class rcs/posemath/PmRpy" << std::endl;
       }
       return clss;
   }
   
   static jclass PmRpyClass = NULL;
   static inline jclass getPmRpyClass() {
       if (PmRpyClass != NULL) {
           return PmRpyClass;
       }
       PmRpyClass = getNewPmRpyClass();
   }
  } // end namespace posemath
 } // end namespace rcs

  namespace org{
   namespace w3c{
    namespace dom{
    
    // get JNI handle for class org.w3c.dom.Node
    static inline jclass getNodeClass();
    
    Node::Node(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Node::Node(const Node &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Node::Node() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getNodeClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class Node has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Node::clone jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new Node with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Node jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for org.w3c.dom.Node
    Node::~Node() {
    	// Place-holder for later extensibility.
    }

    static jclass getNewNodeClass() {
        jclass clss = getEnv()->FindClass("org/w3c/dom/Node");
        if (NULL == clss) {
            std::cerr << " Can't find class org/w3c/dom/Node" << std::endl;
        }
        return clss;
    }
    
    static jclass NodeClass = NULL;
    static inline jclass getNodeClass() {
        if (NodeClass != NULL) {
            return NodeClass;
        }
        NodeClass = getNewNodeClass();
    }
    
    // get JNI handle for class org.w3c.dom.NodeList
    static inline jclass getNodeListClass();
    
    NodeList::NodeList(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    NodeList::NodeList(const NodeList &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    NodeList::NodeList() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getNodeListClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class NodeList has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," NodeList::clone jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new NodeList with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new NodeList jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
    }


    // Destructor for org.w3c.dom.NodeList
    NodeList::~NodeList() {
    	// Place-holder for later extensibility.
    }

    static jclass getNewNodeListClass() {
        jclass clss = getEnv()->FindClass("org/w3c/dom/NodeList");
        if (NULL == clss) {
            std::cerr << " Can't find class org/w3c/dom/NodeList" << std::endl;
        }
        return clss;
    }
    
    static jclass NodeListClass = NULL;
    static inline jclass getNodeListClass() {
        if (NodeListClass != NULL) {
            return NodeListClass;
        }
        NodeListClass = getNewNodeListClass();
    }
   } // end namespace dom
  } // end namespace w3c
 } // end namespace org

  namespace javax{
   namespace xml{
    namespace datatype{
    
    // get JNI handle for class javax.xml.datatype.XMLGregorianCalendar
    static inline jclass getXMLGregorianCalendarClass();
    
    XMLGregorianCalendar::XMLGregorianCalendar(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    XMLGregorianCalendar::XMLGregorianCalendar(const XMLGregorianCalendar &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    XMLGregorianCalendar::XMLGregorianCalendar() : ::crclj::java::lang::Object((jobject)NULL,false) {
     JNIEnv *env =getEnv();
     static jclass cls = getXMLGregorianCalendarClass();
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
         if (NULL == mid) {
             std::cerr << "Class XMLGregorianCalendar has no method constructor signature ()V" << std::endl;
         } else {
             jthis = env->NewObject(cls, mid );
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::clone jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
             if(jthis == NULL) {
                 std::cerr << "Call to create new XMLGregorianCalendar with signature ()V returned null." << std::endl;
                 releaseEnv(env);
                 return;
             }
             jobjectRefType ref = env->GetObjectRefType(jthis);
             if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new XMLGregorianCalendar jthis=",jthis);
             if(ref != JNIGlobalRefType) {
                 jthis = env->NewGlobalRef(jthis);
             }
         }
     }
     releaseEnv(env);
    }


    // Destructor for javax.xml.datatype.XMLGregorianCalendar
    XMLGregorianCalendar::~XMLGregorianCalendar() {
    	// Place-holder for later extensibility.
    }

    void XMLGregorianCalendar::setTime(jint int_0,jint int_1,jint int_2) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTime of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::setTime jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setTime", "(III)V");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named setTime with signature (III)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,int_0,int_1,int_2 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::setTime jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    void XMLGregorianCalendar::setTime(jint int_0,jint int_1,jint int_2,::crclj::java::math::BigDecimal  &bigDecimal_3) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTime of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::setTime jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setTime", "(IIILjava/math/BigDecimal;)V");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named setTime with signature (IIILjava/math/BigDecimal;)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,int_0,int_1,int_2,bigDecimal_3.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::setTime jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    void XMLGregorianCalendar::setTime(jint int_0,jint int_1,jint int_2,jint int_3) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setTime of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::setTime jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setTime", "(IIII)V");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named setTime with signature (IIII)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,int_0,int_1,int_2,int_3 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::setTime jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    jint XMLGregorianCalendar::getMillisecond() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getMillisecond of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::getMillisecond jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "getMillisecond", "()I");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named getMillisecond with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::getMillisecond jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jboolean XMLGregorianCalendar::equals(::crclj::java::lang::Object  &object_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::equals jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::equals jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jstring XMLGregorianCalendar::toString() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::toString jthis=",jthis);
    jstring retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named toString with signature ()Ljava/lang/String;." << std::endl;
            return NULL;
        } else {
            retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jint XMLGregorianCalendar::hashCode() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of javax.xml.datatype.XMLGregorianCalendar with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::hashCode jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
        if (NULL == mid) {
            std::cerr << "Class javax.xml.datatype.XMLGregorianCalendar has no method named hashCode with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," XMLGregorianCalendar::hashCode jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    static jclass getNewXMLGregorianCalendarClass() {
        jclass clss = getEnv()->FindClass("javax/xml/datatype/XMLGregorianCalendar");
        if (NULL == clss) {
            std::cerr << " Can't find class javax/xml/datatype/XMLGregorianCalendar" << std::endl;
        }
        return clss;
    }
    
    static jclass XMLGregorianCalendarClass = NULL;
    static inline jclass getXMLGregorianCalendarClass() {
        if (XMLGregorianCalendarClass != NULL) {
            return XMLGregorianCalendarClass;
        }
        XMLGregorianCalendarClass = getNewXMLGregorianCalendarClass();
    }
   } // end namespace datatype
  } // end namespace xml
 } // end namespace javax

  namespace java{
   namespace io{
   
   // get JNI handle for class java.io.OutputStream
   static inline jclass getOutputStreamClass();
   
   OutputStream::OutputStream(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   OutputStream::OutputStream(const OutputStream &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   OutputStream::OutputStream() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getOutputStreamClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class OutputStream has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," OutputStream::hashCode jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new OutputStream with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new OutputStream jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for java.io.OutputStream
   OutputStream::~OutputStream() {
   	// Place-holder for later extensibility.
   }

   void OutputStream::write(jbyteArray byteArray_0,jint int_1,jint int_2) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.OutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OutputStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "([BII)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.OutputStream has no method named write with signature ([BII)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byteArray_0,int_1,int_2 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OutputStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void OutputStream::write(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method write of java.io.OutputStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OutputStream::write jthis=",jthis);
    
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jint int_1= easyArg_1;
    jint int_2= easyArg_2;
    write(byteArray_0,int_1,int_2);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
   }

   void OutputStream::write(jbyteArray byteArray_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method write of java.io.OutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OutputStream::write jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "write", "([B)V");
       if (NULL == mid) {
           std::cerr << "Class java.io.OutputStream has no method named write with signature ([B)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,byteArray_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OutputStream::write jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void OutputStream::write(jbyte * easyArg_0,jsize easyArg_0_length) {

    // convenience method, converts to/from JNI types to common C++ types.
    if(jthis == NULL) {
        std::cerr << "Call of method write of java.io.OutputStream with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OutputStream::write jthis=",jthis);
    
            
    jbyteArray byteArray_0= env->NewByteArray(easyArg_0_length);
    env->SetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    write(byteArray_0);
    env->GetByteArrayRegion(byteArray_0,0,easyArg_0_length,easyArg_0);
    jobjectRefType ref_0 = env->GetObjectRefType(byteArray_0);
    if(ref_0 == JNIGlobalRefType) {
     env->DeleteGlobalRef(byteArray_0);
    }
    
    releaseEnv(env);
   }

   void OutputStream::flush() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method flush of java.io.OutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OutputStream::flush jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "flush", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.OutputStream has no method named flush with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OutputStream::flush jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void OutputStream::close() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method close of java.io.OutputStream with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," OutputStream::close jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "close", "()V");
       if (NULL == mid) {
           std::cerr << "Class java.io.OutputStream has no method named close with signature ()V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," OutputStream::close jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   static jclass getNewOutputStreamClass() {
       jclass clss = getEnv()->FindClass("java/io/OutputStream");
       if (NULL == clss) {
           std::cerr << " Can't find class java/io/OutputStream" << std::endl;
       }
       return clss;
   }
   
   static jclass OutputStreamClass = NULL;
   static inline jclass getOutputStreamClass() {
       if (OutputStreamClass != NULL) {
           return OutputStreamClass;
       }
       OutputStreamClass = getNewOutputStreamClass();
   }
  } // end namespace io
 } // end namespace java



    // end namespace crclj
}

