
#include <jni.h>
#include <cstdlib>
#include <iostream>
#include "crclj.h"

namespace crclj {

    


  namespace java{
   namespace awt{
    namespace geom{
    
    // get JNI handle for class java.awt.geom.Point2D
    static inline jclass getPoint2DClass();
    
    Point2D::Point2D(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Point2D::Point2D(const Point2D &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Point2D::Point2D() : ::crclj::java::lang::Object((jobject)NULL,false) {
     JNIEnv *env =getEnv();
     static jclass cls = getPoint2DClass();
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
         if (NULL == mid) {
             std::cerr << "Class Point2D has no method constructor signature ()V" << std::endl;
         } else {
             jthis = env->NewObject(cls, mid );
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," Point2D::applyInverseTo jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
             if(jthis == NULL) {
                 std::cerr << "Call to create new Point2D with signature ()V returned null." << std::endl;
                 releaseEnv(env);
                 return;
             }
             jobjectRefType ref = env->GetObjectRefType(jthis);
             if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Point2D jthis=",jthis);
             if(ref != JNIGlobalRefType) {
                 jthis = env->NewGlobalRef(jthis);
             }
         }
     }
     releaseEnv(env);
    }


    // Destructor for java.awt.geom.Point2D
    Point2D::~Point2D() {
    	// Place-holder for later extensibility.
    }

    jdouble Point2D::distanceSq(Point2D  &point2D_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method distanceSq of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return (jdouble) -1.0;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::distanceSq jthis=",jthis);
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "distanceSq", "(Ljava/awt/geom/Point2D;)D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named distanceSq with signature (Ljava/awt/geom/Point2D;)D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallDoubleMethod(jthis, mid ,point2D_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::distanceSq jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jdouble Point2D::distanceSq(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3) {

    JNIEnv *env =getEnv();
    static jclass cls = getPoint2DClass();
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "distanceSq", "(DDDD)D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named distanceSq with signature (DDDD)D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,double_0,double_1,double_2,double_3 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::distanceSq jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jdouble Point2D::distanceSq(jdouble double_0,jdouble double_1) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method distanceSq of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return (jdouble) -1.0;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::distanceSq jthis=",jthis);
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "distanceSq", "(DD)D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named distanceSq with signature (DD)D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallDoubleMethod(jthis, mid ,double_0,double_1 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::distanceSq jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jdouble Point2D::distance(Point2D  &point2D_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method distance of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return (jdouble) -1.0;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::distance jthis=",jthis);
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "distance", "(Ljava/awt/geom/Point2D;)D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named distance with signature (Ljava/awt/geom/Point2D;)D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallDoubleMethod(jthis, mid ,point2D_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::distance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jdouble Point2D::distance(jdouble double_0,jdouble double_1) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method distance of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return (jdouble) -1.0;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::distance jthis=",jthis);
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "distance", "(DD)D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named distance with signature (DD)D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallDoubleMethod(jthis, mid ,double_0,double_1 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::distance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jdouble Point2D::distance(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3) {

    JNIEnv *env =getEnv();
    static jclass cls = getPoint2DClass();
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetStaticMethodID(cls, "distance", "(DDDD)D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named distance with signature (DDDD)D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallStaticDoubleMethod( cls, mid ,double_0,double_1,double_2,double_3 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::distance jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw env;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    void Point2D::setLocation(Point2D  &point2D_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLocation of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::setLocation jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setLocation", "(Ljava/awt/geom/Point2D;)V");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named setLocation with signature (Ljava/awt/geom/Point2D;)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,point2D_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::setLocation jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    jboolean Point2D::equals(::crclj::java::lang::Object  &object_0) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return false;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::equals jthis=",jthis);
    jboolean retVal=false;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named equals with signature (Ljava/lang/Object;)Z." << std::endl;
            return false;
        } else {
            retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,object_0.jthis );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::equals jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jint Point2D::hashCode() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method hashCode of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        return (jint) -1;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::hashCode jthis=",jthis);
    jint retVal= (jint) -1;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "hashCode", "()I");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named hashCode with signature ()I." << std::endl;
            return (jint) -1;
        } else {
            retVal= (jint)  env->CallIntMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::hashCode jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    ::crclj::java::lang::Object Point2D::clone() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clone of java.awt.geom.Point2D with jthis == NULL." << std::endl;
        ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2D::clone jthis=",jthis);
    jobject retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "clone", "()Ljava/lang/Object;");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D has no method named clone with signature ()Ljava/lang/Object;." << std::endl;
            ::crclj::java::lang::Object nullObject((jobject)NULL,false); return nullObject;
        } else {
            retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2D::clone jthis=",t);
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
    static jclass getNewPoint2DClass() {
        jclass clss = getEnv()->FindClass("java/awt/geom/Point2D");
        if (NULL == clss) {
            std::cerr << " Can't find class java/awt/geom/Point2D" << std::endl;
        }
        return clss;
    }
    
    static jclass Point2DClass = NULL;
    static inline jclass getPoint2DClass() {
        if (Point2DClass != NULL) {
            return Point2DClass;
        }
        Point2DClass = getNewPoint2DClass();
    }
    
    // get JNI handle for class java.awt.geom.Point2D.Double
    static inline jclass getPoint2DDoubleClass();
    
    Point2DDouble::Point2DDouble(jobject _jthis, bool copy): Point2D(_jthis,copy) {
            // Place holder for future extensibility
    }
    
    Point2DDouble::Point2DDouble(const Point2DDouble &objref) {
        jobject _jthis = objref.jthis;
        if (_jthis != NULL) {
            jthis = getEnv()->NewGlobalRef(_jthis);
        }
    }
    Point2DDouble::Point2DDouble() : Point2D((jobject)NULL,false) {
     JNIEnv *env =getEnv();
     static jclass cls = getPoint2DDoubleClass();
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
         if (NULL == mid) {
             std::cerr << "Class Point2DDouble has no method constructor signature ()V" << std::endl;
         } else {
             jthis = env->NewObject(cls, mid );
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::clone jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
             if(jthis == NULL) {
                 std::cerr << "Call to create new Point2DDouble with signature ()V returned null." << std::endl;
                 releaseEnv(env);
                 return;
             }
             jobjectRefType ref = env->GetObjectRefType(jthis);
             if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Point2DDouble jthis=",jthis);
             if(ref != JNIGlobalRefType) {
                 jthis = env->NewGlobalRef(jthis);
             }
         }
     }
     releaseEnv(env);
    }

    Point2DDouble::Point2DDouble(jdouble double_0,jdouble double_1) : Point2D((jobject)NULL,false) {
     JNIEnv *env =getEnv();
     static jclass cls = getPoint2DDoubleClass();
     if (cls != NULL) {
         static jmethodID mid = env->GetMethodID(cls, "<init>", "(DD)V");
         if (NULL == mid) {
             std::cerr << "Class Point2DDouble has no method constructor signature (DD)V" << std::endl;
         } else {
             jthis = env->NewObject(cls, mid ,double_0,double_1);
             jthrowable t = env->ExceptionOccurred();
             if(t != NULL) {
                 DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::clone jthis=",t);
                 env->ExceptionDescribe();
                 env->ExceptionClear();
                 throw this;
             }
             if(jthis == NULL) {
                 std::cerr << "Call to create new Point2DDouble with signature (DD)V returned null." << std::endl;
                 releaseEnv(env);
                 return;
             }
             jobjectRefType ref = env->GetObjectRefType(jthis);
             if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new Point2DDouble jthis=",jthis);
             if(ref != JNIGlobalRefType) {
                 jthis = env->NewGlobalRef(jthis);
             }
         }
     }
     releaseEnv(env);
    }


    // Destructor for java.awt.geom.Point2D.Double
    Point2DDouble::~Point2DDouble() {
    	// Place-holder for later extensibility.
    }

    void Point2DDouble::setLocation(jdouble double_0,jdouble double_1) {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setLocation of java.awt.geom.Point2D.Double with jthis == NULL." << std::endl;
        return;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::setLocation jthis=",jthis);
    
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "setLocation", "(DD)V");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D.Double has no method named setLocation with signature (DD)V." << std::endl;
            return;
        } else {
             env->CallVoidMethod(jthis, mid ,double_0,double_1 );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::setLocation jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    
    }
    jdouble Point2DDouble::getX() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getX of java.awt.geom.Point2D.Double with jthis == NULL." << std::endl;
        return (jdouble) -1.0;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::getX jthis=",jthis);
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "getX", "()D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D.Double has no method named getX with signature ()D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::getX jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jdouble Point2DDouble::getY() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getY of java.awt.geom.Point2D.Double with jthis == NULL." << std::endl;
        return (jdouble) -1.0;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::getY jthis=",jthis);
    jdouble retVal= (jdouble) -1.0;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "getY", "()D");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D.Double has no method named getY with signature ()D." << std::endl;
            return (jdouble) -1.0;
        } else {
            retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::getY jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    jstring Point2DDouble::toString() {

    if(jthis == NULL) {
        std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of java.awt.geom.Point2D.Double with jthis == NULL." << std::endl;
        return NULL;
    }
    JNIEnv *env =getEnv();
    jclass cls = env->GetObjectClass(jthis);
    if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::toString jthis=",jthis);
    jstring retVal=NULL;
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
        if (NULL == mid) {
            std::cerr << "Class java.awt.geom.Point2D.Double has no method named toString with signature ()Ljava/lang/String;." << std::endl;
            return NULL;
        } else {
            retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," Point2DDouble::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
        }
    }
    releaseEnv(env);
    return retVal;
    }
    static jclass getNewPoint2DDoubleClass() {
        jclass clss = getEnv()->FindClass("java/awt/geom/Point2D/Double");
        if (NULL == clss) {
            std::cerr << " Can't find class java/awt/geom/Point2D/Double" << std::endl;
        }
        return clss;
    }
    
    static jclass Point2DDoubleClass = NULL;
    static inline jclass getPoint2DDoubleClass() {
        if (Point2DDoubleClass != NULL) {
            return Point2DDoubleClass;
        }
        Point2DDoubleClass = getNewPoint2DDoubleClass();
    }
   } // end namespace geom
  } // end namespace awt
 } // end namespace java

  namespace rcs{
   namespace posemath{
   
   // get JNI handle for class rcs.posemath.PmCartesian
   static inline jclass getPmCartesianClass();
   
   PmCartesian::PmCartesian(jobject _jthis, bool copy): ::crclj::java::awt::geom::Point2DDouble(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PmCartesian::PmCartesian(const PmCartesian &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PmCartesian::PmCartesian() : ::crclj::java::awt::geom::Point2DDouble((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmCartesianClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PmCartesian has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmCartesian::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmCartesian with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmCartesian jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmCartesian::PmCartesian(jdouble double_0,jdouble double_1,jdouble double_2) : ::crclj::java::awt::geom::Point2DDouble((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmCartesianClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDD)V");
        if (NULL == mid) {
            std::cerr << "Class PmCartesian has no method constructor signature (DDD)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0,double_1,double_2);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmCartesian::toString jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmCartesian with signature (DDD)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmCartesian jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for rcs.posemath.PmCartesian
   PmCartesian::~PmCartesian() {
   	// Place-holder for later extensibility.
   }

   jdouble PmCartesian::getX() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getX of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::getX jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getX", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named getX with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::getX jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble PmCartesian::getY() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getY of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::getY jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getY", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named getY with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::getY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmCartesian::setX(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setX of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::setX jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setX", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named setX with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::setX jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   void PmCartesian::setY(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setY of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::setY jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setY", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named setY with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::setY jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PmCartesian::getZ() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method getZ of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::getZ jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "getZ", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named getZ with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::getZ jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   void PmCartesian::setZ(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method setZ of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::setZ jthis=",jthis);
   
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "setZ", "(D)V");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named setZ with signature (D)V." << std::endl;
           return;
       } else {
            env->CallVoidMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::setZ jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   
   }
   jdouble PmCartesian::mag() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method mag of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::mag jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "mag", "()D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named mag with signature ()D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::mag jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jdouble PmCartesian::distFrom(PmCartesian  &pmCartesian_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method distFrom of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return (jdouble) -1.0;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::distFrom jthis=",jthis);
   jdouble retVal= (jdouble) -1.0;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "distFrom", "(Lrcs/posemath/PmCartesian;)D");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named distFrom with signature (Lrcs/posemath/PmCartesian;)D." << std::endl;
           return (jdouble) -1.0;
       } else {
           retVal= (jdouble)  env->CallDoubleMethod(jthis, mid ,pmCartesian_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::distFrom jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   PmCartesian PmCartesian::subtract(PmCartesian  &pmCartesian_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method subtract of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       PmCartesian nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::subtract jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "subtract", "(Lrcs/posemath/PmCartesian;)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named subtract with signature (Lrcs/posemath/PmCartesian;)Lrcs/posemath/PmCartesian;." << std::endl;
           PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,pmCartesian_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::subtract jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmCartesian retObject(retVal,false);
    return retObject;
   }
   PmCartesian PmCartesian::multiply(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       PmCartesian nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(D)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named multiply with signature (D)Lrcs/posemath/PmCartesian;." << std::endl;
           PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmCartesian retObject(retVal,false);
    return retObject;
   }
   PmCartesian PmCartesian::add(PmCartesian  &pmCartesian_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method add of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       PmCartesian nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::add jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "add", "(Lrcs/posemath/PmCartesian;)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named add with signature (Lrcs/posemath/PmCartesian;)Lrcs/posemath/PmCartesian;." << std::endl;
           PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,pmCartesian_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::add jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmCartesian retObject(retVal,false);
    return retObject;
   }
   jboolean PmCartesian::equals(PmCartesian  &pmCartesian_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method equals of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return false;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::equals jthis=",jthis);
   jboolean retVal=false;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "equals", "(Lrcs/posemath/PmCartesian;)Z");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named equals with signature (Lrcs/posemath/PmCartesian;)Z." << std::endl;
           return false;
       } else {
           retVal= (jboolean)  env->CallBooleanMethod(jthis, mid ,pmCartesian_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::equals jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   jstring PmCartesian::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   PmCartesian PmCartesian::clone() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clone of rcs.posemath.PmCartesian with jthis == NULL." << std::endl;
       PmCartesian nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmCartesian::clone jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "clone", "()Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named clone with signature ()Lrcs/posemath/PmCartesian;." << std::endl;
           PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmCartesian retObject(retVal,false);
    return retObject;
   }
   PmCartesian PmCartesian::valueOf(jstring string_0) {

   JNIEnv *env =getEnv();
   static jclass cls = getPmCartesianClass();
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmCartesian has no method named valueOf with signature (Ljava/lang/String;)Lrcs/posemath/PmCartesian;." << std::endl;
           PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallStaticObjectMethod( cls, mid ,string_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmCartesian::valueOf jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw env;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmCartesian retObject(retVal,false);
    return retObject;
   }
   static jclass getNewPmCartesianClass() {
       jclass clss = getEnv()->FindClass("rcs/posemath/PmCartesian");
       if (NULL == clss) {
           std::cerr << " Can't find class rcs/posemath/PmCartesian" << std::endl;
       }
       return clss;
   }
   
   static jclass PmCartesianClass = NULL;
   static inline jclass getPmCartesianClass() {
       if (PmCartesianClass != NULL) {
           return PmCartesianClass;
       }
       PmCartesianClass = getNewPmCartesianClass();
   }
   
   // get JNI handle for class rcs.posemath.PmRotationVector
   static inline jclass getPmRotationVectorClass();
   
   PmRotationVector::PmRotationVector(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PmRotationVector::PmRotationVector(const PmRotationVector &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PmRotationVector::PmRotationVector(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRotationVectorClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDDD)V");
        if (NULL == mid) {
            std::cerr << "Class PmRotationVector has no method constructor signature (DDDD)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0,double_1,double_2,double_3);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::valueOf jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRotationVector with signature (DDDD)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRotationVector jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmRotationVector::PmRotationVector() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRotationVectorClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PmRotationVector has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::valueOf jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRotationVector with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRotationVector jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for rcs.posemath.PmRotationVector
   PmRotationVector::~PmRotationVector() {
   	// Place-holder for later extensibility.
   }

   PmRotationVector PmRotationVector::inv() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method inv of rcs.posemath.PmRotationVector with jthis == NULL." << std::endl;
       PmRotationVector nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::inv jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "inv", "()Lrcs/posemath/PmRotationVector;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationVector has no method named inv with signature ()Lrcs/posemath/PmRotationVector;." << std::endl;
           PmRotationVector nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::inv jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRotationVector retObject(retVal,false);
    return retObject;
   }
   PmRotationVector PmRotationVector::multiply(PmRotationVector  &pmRotationVector_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of rcs.posemath.PmRotationVector with jthis == NULL." << std::endl;
       PmRotationVector nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(Lrcs/posemath/PmRotationVector;)Lrcs/posemath/PmRotationVector;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationVector has no method named multiply with signature (Lrcs/posemath/PmRotationVector;)Lrcs/posemath/PmRotationVector;." << std::endl;
           PmRotationVector nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,pmRotationVector_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRotationVector retObject(retVal,false);
    return retObject;
   }
   PmRotationVector PmRotationVector::multiply(jdouble double_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of rcs.posemath.PmRotationVector with jthis == NULL." << std::endl;
       PmRotationVector nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(D)Lrcs/posemath/PmRotationVector;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationVector has no method named multiply with signature (D)Lrcs/posemath/PmRotationVector;." << std::endl;
           PmRotationVector nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,double_0 );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRotationVector retObject(retVal,false);
    return retObject;
   }
   PmRotationVector PmRotationVector::clone() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method clone of rcs.posemath.PmRotationVector with jthis == NULL." << std::endl;
       PmRotationVector nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::clone jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "clone", "()Lrcs/posemath/PmRotationVector;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationVector has no method named clone with signature ()Lrcs/posemath/PmRotationVector;." << std::endl;
           PmRotationVector nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationVector::clone jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRotationVector retObject(retVal,false);
    return retObject;
   }
   static jclass getNewPmRotationVectorClass() {
       jclass clss = getEnv()->FindClass("rcs/posemath/PmRotationVector");
       if (NULL == clss) {
           std::cerr << " Can't find class rcs/posemath/PmRotationVector" << std::endl;
       }
       return clss;
   }
   
   static jclass PmRotationVectorClass = NULL;
   static inline jclass getPmRotationVectorClass() {
       if (PmRotationVectorClass != NULL) {
           return PmRotationVectorClass;
       }
       PmRotationVectorClass = getNewPmRotationVectorClass();
   }
   
   // get JNI handle for class rcs.posemath.PmRotationMatrix
   static inline jclass getPmRotationMatrixClass();
   
   PmRotationMatrix::PmRotationMatrix(jobject _jthis, bool copy): ::crclj::java::lang::Object(_jthis,copy) {
           // Place holder for future extensibility
   }
   
   PmRotationMatrix::PmRotationMatrix(const PmRotationMatrix &objref) {
       jobject _jthis = objref.jthis;
       if (_jthis != NULL) {
           jthis = getEnv()->NewGlobalRef(_jthis);
       }
   }
   PmRotationMatrix::PmRotationMatrix() : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRotationMatrixClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "()V");
        if (NULL == mid) {
            std::cerr << "Class PmRotationMatrix has no method constructor signature ()V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid );
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::clone jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRotationMatrix with signature ()V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRotationMatrix jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmRotationMatrix::PmRotationMatrix(PmCartesian  &pmCartesian_0,PmCartesian  &pmCartesian_1,PmCartesian  &pmCartesian_2) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRotationMatrixClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(Lrcs/posemath/PmCartesian;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmCartesian;)V");
        if (NULL == mid) {
            std::cerr << "Class PmRotationMatrix has no method constructor signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmCartesian;)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,pmCartesian_0.jthis,pmCartesian_1.jthis,pmCartesian_2.jthis);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::clone jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRotationMatrix with signature (Lrcs/posemath/PmCartesian;Lrcs/posemath/PmCartesian;Lrcs/posemath/PmCartesian;)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRotationMatrix jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }

   PmRotationMatrix::PmRotationMatrix(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3,jdouble double_4,jdouble double_5,jdouble double_6,jdouble double_7,jdouble double_8) : ::crclj::java::lang::Object((jobject)NULL,false) {
    JNIEnv *env =getEnv();
    static jclass cls = getPmRotationMatrixClass();
    if (cls != NULL) {
        static jmethodID mid = env->GetMethodID(cls, "<init>", "(DDDDDDDDD)V");
        if (NULL == mid) {
            std::cerr << "Class PmRotationMatrix has no method constructor signature (DDDDDDDDD)V" << std::endl;
        } else {
            jthis = env->NewObject(cls, mid ,double_0,double_1,double_2,double_3,double_4,double_5,double_6,double_7,double_8);
            jthrowable t = env->ExceptionOccurred();
            if(t != NULL) {
                DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::clone jthis=",t);
                env->ExceptionDescribe();
                env->ExceptionClear();
                throw this;
            }
            if(jthis == NULL) {
                std::cerr << "Call to create new PmRotationMatrix with signature (DDDDDDDDD)V returned null." << std::endl;
                releaseEnv(env);
                return;
            }
            jobjectRefType ref = env->GetObjectRefType(jthis);
            if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," new PmRotationMatrix jthis=",jthis);
            if(ref != JNIGlobalRefType) {
                jthis = env->NewGlobalRef(jthis);
            }
        }
    }
    releaseEnv(env);
   }


   // Destructor for rcs.posemath.PmRotationMatrix
   PmRotationMatrix::~PmRotationMatrix() {
   	// Place-holder for later extensibility.
   }

   PmRotationMatrix PmRotationMatrix::inv() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method inv of rcs.posemath.PmRotationMatrix with jthis == NULL." << std::endl;
       PmRotationMatrix nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::inv jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "inv", "()Lrcs/posemath/PmRotationMatrix;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationMatrix has no method named inv with signature ()Lrcs/posemath/PmRotationMatrix;." << std::endl;
           PmRotationMatrix nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::inv jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRotationMatrix retObject(retVal,false);
    return retObject;
   }
   PmRotationMatrix PmRotationMatrix::multiply(PmRotationMatrix  &pmRotationMatrix_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of rcs.posemath.PmRotationMatrix with jthis == NULL." << std::endl;
       PmRotationMatrix nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(Lrcs/posemath/PmRotationMatrix;)Lrcs/posemath/PmRotationMatrix;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationMatrix has no method named multiply with signature (Lrcs/posemath/PmRotationMatrix;)Lrcs/posemath/PmRotationMatrix;." << std::endl;
           PmRotationMatrix nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,pmRotationMatrix_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmRotationMatrix retObject(retVal,false);
    return retObject;
   }
   PmCartesian PmRotationMatrix::multiply(PmCartesian  &pmCartesian_0) {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method multiply of rcs.posemath.PmRotationMatrix with jthis == NULL." << std::endl;
       PmCartesian nullObject((jobject)NULL,false); return nullObject;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::multiply jthis=",jthis);
   jobject retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "multiply", "(Lrcs/posemath/PmCartesian;)Lrcs/posemath/PmCartesian;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationMatrix has no method named multiply with signature (Lrcs/posemath/PmCartesian;)Lrcs/posemath/PmCartesian;." << std::endl;
           PmCartesian nullObject((jobject)NULL,false); return nullObject;
       } else {
           retVal= (jobject)  env->CallObjectMethod(jthis, mid ,pmCartesian_0.jthis );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::multiply jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
       
    jobjectRefType ref = env->GetObjectRefType(retVal);
    PmCartesian retObject(retVal,false);
    return retObject;
   }
   jstring PmRotationMatrix::toString() {

   if(jthis == NULL) {
       std::cerr << __FILE__ << ":" << __LINE__ <<" Call of method toString of rcs.posemath.PmRotationMatrix with jthis == NULL." << std::endl;
       return NULL;
   }
   JNIEnv *env =getEnv();
   jclass cls = env->GetObjectClass(jthis);
   if(GetDebugJ4Cpp()) DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::toString jthis=",jthis);
   jstring retVal=NULL;
   if (cls != NULL) {
       static jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
       if (NULL == mid) {
           std::cerr << "Class rcs.posemath.PmRotationMatrix has no method named toString with signature ()Ljava/lang/String;." << std::endl;
           return NULL;
       } else {
           retVal= (jstring)  env->CallObjectMethod(jthis, mid  );
           jthrowable t = env->ExceptionOccurred();
           if(t != NULL) {
               DebugPrintJObject(__FILE__,__LINE__," PmRotationMatrix::toString jthis=",t);
               env->ExceptionDescribe();
               env->ExceptionClear();
               throw this;
           }
       }
   }
   releaseEnv(env);
   return retVal;
   }
   static jclass getNewPmRotationMatrixClass() {
       jclass clss = getEnv()->FindClass("rcs/posemath/PmRotationMatrix");
       if (NULL == clss) {
           std::cerr << " Can't find class rcs/posemath/PmRotationMatrix" << std::endl;
       }
       return clss;
   }
   
   static jclass PmRotationMatrixClass = NULL;
   static inline jclass getPmRotationMatrixClass() {
       if (PmRotationMatrixClass != NULL) {
           return PmRotationMatrixClass;
       }
       PmRotationMatrixClass = getNewPmRotationMatrixClass();
   }
  } // end namespace posemath
 } // end namespace rcs



    // end namespace crclj
}

