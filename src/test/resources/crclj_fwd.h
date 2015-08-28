#ifndef crclj_fwd_h
#define crclj_fwd_h


namespace crclj {
    
    namespace java {
            namespace lang {
                class Object;
            } // end namespace lang;
    }// end namespace java 
    
   

    
 namespace crcl{
  namespace base{
   class DataThingType;
   class JointDetailsType;
   class JointSpeedAccelType;
   class CRCLCommandType;
   class MiddleCommandType;
   class SetIntermediatePoseToleranceType;
   class SetEndPoseToleranceType;
   class EndCanonType;
   class SetRobotParametersType;
  } // end namespace base

  namespace utils{
   class DefaultMain;
   class PoseToleranceChecker;
  } // end namespace utils
 } // end namespace crcl

 namespace java{
  namespace lang{
   class Enum;
  } // end namespace lang
 } // end namespace java

 namespace crcl{
  namespace utils{
   class SimRobotEnum;
   class PendantClientOuterStub;
  } // end namespace utils
 } // end namespace crcl

 namespace java{
  namespace awt{
   class Component;
   class Container;
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   class JComponent;
   class JPanel;
  } // end namespace swing
 } // end namespace javax

 namespace crcl{
  namespace utils{
   class OverHeadJPanel;
  } // end namespace utils

  namespace base{
   class CloseToolChangerType;
   class ForceUnitEnumType;
   class ParameterSettingType;
   class CRCLStatusType;
   class MoveScrewType;
   class MoveToType;
   class ObjectFactory;
   class PoseType;
   class PoseAndSetType;
   class TransAccelType;
   class TransAccelRelativeType;
   class DwellType;
   class SetLengthUnitsType;
   class OpenToolChangerType;
   class SetTransAccelType;
   class JointForceTorqueType;
   class PointType;
   class CommandStateEnumType;
  } // end namespace base

  namespace utils{
   class CRCLPosemath;
   class XpathUtils;
   class ListChooserJPanel;
  } // end namespace utils
 } // end namespace crcl

 namespace java{
  namespace awt{
   class Window;
   class Frame;
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   class JFrame;
  } // end namespace swing
 } // end namespace javax

 namespace crcl{
  namespace utils{
   class LauncherJFrame;
   class SimulatedKinematicsPlausible;
   class GripperJFrame;
  } // end namespace utils

  namespace base{
   class RotAccelType;
   class ActuateJointsType;
   class MessageType;
   class AngleUnitEnumType;
   class TransAccelAbsoluteType;
   class TorqueUnitEnumType;
   class TransSpeedType;
   class TransSpeedRelativeType;
   class RunProgramType;
  } // end namespace base

  namespace utils{
   class PerfTest;
  } // end namespace utils

  namespace base{
   class RotSpeedType;
   class GripperStatusType;
   class SetTransSpeedType;
   class SetForceUnitsType;
   class RotAccelRelativeType;
  } // end namespace base

  namespace utils{
   class SimServerOuterStub;
   class SimServerOuter;
   class SimServerInner;
   class MultiLineStringJPanel;
   class ObjTableJPanel;
  } // end namespace utils

  namespace base{
   class CRCLProgramType;
   class VectorType;
   class SetEndEffectorType;
   class SetTorqueUnitsType;
   class ConfigureJointReportType;
   class SetRotAccelType;
   class SetAngleUnitsType;
   class CommandStatusType;
   class RotSpeedRelativeType;
   class RotAccelAbsoluteType;
   class SetMotionCoordinationType;
   class ActuateJointType;
   class TransSpeedAbsoluteType;
   class PoseToleranceType;
   class StopMotionType;
   class ConfigureJointReportsType;
   class CRCLCommandInstanceType;
   class SetRotSpeedType;
   class ParallelGripperStatusType;
   class LengthUnitEnumType;
   class SetEndEffectorParametersType;
   class ThreeFingerGripperStatusType;
  } // end namespace base

  namespace utils{
   class PendantClientOuter;
   class SideViewJPanel;
   class SimulatedKinematicsSimple;
   class XpathQueryJFrame;
  } // end namespace utils

  namespace base{
   class InitCanonType;
   class JointStatusesType;
   class JointStatusType;
   class MoveThroughToType;
   class StopConditionEnumType;
  } // end namespace base

  namespace utils{
   class TestInstance;
   class SimServer;
   class CmdLineSimServer;
  } // end namespace utils
 } // end namespace crcl

 namespace rcs{
  namespace posemath{
   class PmPose;
  } // end namespace posemath
 } // end namespace rcs

 namespace crcl{
  namespace utils{
   class AnnotatedPose;
   class CRCLSocket;
  } // end namespace utils

  namespace base{
   class VacuumGripperStatusType;
   class GetStatusType;
   class RotSpeedAbsoluteType;
  } // end namespace base

  namespace utils{
   class PendantClient;
   class CmdLineClient;
   class CRCLSocketExample;
   class PendantClientInner;
  } // end namespace utils
 } // end namespace crcl

 namespace java{
  namespace lang{
   class Number;
  } // end namespace lang

  namespace math{
   class BigDecimal;
  } // end namespace math

  namespace util{
   class List;
  } // end namespace util

  namespace lang{
   class Throwable;
  } // end namespace lang

  namespace io{
   class File;
  } // end namespace io
 } // end namespace java

 namespace javax{
  namespace xml{
   namespace bind{
    class JAXBElement;
   } // end namespace bind
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace geometry{
      namespace euclidean{
       namespace threed{
        class Vector3D;
        class Rotation;
       } // end namespace threed
      } // end namespace euclidean
     } // end namespace geometry
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace awt{
   namespace geom{
    class Point2D;
    class Point2DDouble;
   } // end namespace geom
  } // end namespace awt
 } // end namespace java

 namespace rcs{
  namespace posemath{
   class PmCartesian;
   class PmRotationVector;
   class PmRotationMatrix;
   class PmRpy;
  } // end namespace posemath
 } // end namespace rcs

 namespace org{
  namespace w3c{
   namespace dom{
    class Node;
    class NodeList;
   } // end namespace dom
  } // end namespace w3c
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace datatype{
    class XMLGregorianCalendar;
   } // end namespace datatype
  } // end namespace xml
 } // end namespace javax

 namespace java{
  namespace io{
   class OutputStream;
   class FilterOutputStream;
   class PrintStream;
  } // end namespace io

  namespace util{
   namespace function{
    class Predicate;
   } // end namespace function
  } // end namespace util

  namespace math{
   class BigInteger;
  } // end namespace math
 } // end namespace java

 namespace rcs{
  namespace posemath{
   class PmQuaternion;
  } // end namespace posemath
 } // end namespace rcs

 namespace java{
  namespace net{
   class InetAddress;
  } // end namespace net

  namespace util{
   namespace function{
    class UnaryOperator;
   } // end namespace function
  } // end namespace util
 } // end namespace java

 namespace javax{
  namespace xml{
   namespace validation{
    class Schema;
   } // end namespace validation
  } // end namespace xml
 } // end namespace javax

 namespace java{
  namespace io{
   class InputStream;
  } // end namespace io
 } // end namespace java

 namespace javax{
  namespace xml{
   namespace transform{
    namespace sax{
     class SAXSource;
    } // end namespace sax
   } // end namespace transform
  } // end namespace xml
 } // end namespace javax

 namespace java{
  namespace util{
   class Optional;
  } // end namespace util
 } // end namespace java

 namespace crcl{
  namespace utils{
   class PendantClientInnerTrySupplier;
  } // end namespace utils
 } // end namespace crcl

 namespace java{
  namespace util{
   namespace stream{
    class Stream;
   } // end namespace stream

   class Collection;
   namespace function{
    class Function;
   } // end namespace function
  } // end namespace util
 } // end namespace java



// end namespace crclj
}

// end #ifndef crclj_fwd_h
#endif

