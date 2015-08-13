#ifndef crcljavabase1_h
#define crcljavabase1_h

#include <jni.h>

namespace crcljavabase1 {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);

    namespace java {
        namespace lang {

            class Object {
            protected:
                jobject jthis;
            public:
                Object();
                Object(jobject _jthis);
                virtual ~Object();
            };
        }
    }
    
    


    
	namespace crcl{
		namespace base{
			class DataThingType;
			class CRCLCommandType;
			class MiddleCommandType;
		} // end namespace crcl
	} // end namespace base
	namespace java{
		namespace lang{
			class Enum;
		} // end namespace java
	} // end namespace lang
	namespace crcl{
		namespace base{
			class GripperStatusType;
			class RotSpeedType;
			class RotAccelType;
			class JointDetailsType;
			class TransSpeedType;
			class TransAccelType;
		} // end namespace crcl
	} // end namespace base
	namespace java{
		namespace lang{
			class Number;
		} // end namespace java
	} // end namespace lang
	namespace crcl{
		namespace base{
			class PoseType;
			class CRCLProgramType;
			class ActuateJointsType;
			class JointSpeedAccelType;
			class TransSpeedAbsoluteType;
			class PoseToleranceType;
			class InitCanonType;
			class MessageType;
			class AngleUnitEnumType;
			class SetIntermediatePoseToleranceType;
			class TransAccelAbsoluteType;
			class StopMotionType;
			class VectorType;
			class SetEndEffectorType;
			class CloseToolChangerType;
			class ForceUnitEnumType;
			class TorqueUnitEnumType;
			class ConfigureJointReportsType;
			class CRCLCommandInstanceType;
			class SetRotSpeedType;
			class SetTorqueUnitsType;
			class ConfigureJointReportType;
			class SetEndPoseToleranceType;
			class ParameterSettingType;
			class SetTransSpeedType;
			class JointStatusesType;
			class ParallelGripperStatusType;
			class LengthUnitEnumType;
			class SetRotAccelType;
			class SetAngleUnitsType;
			class CommandStatusType;
			class TransSpeedRelativeType;
			class SetForceUnitsType;
			class JointStatusType;
			class VacuumGripperStatusType;
			class SetEndEffectorParametersType;
			class EndCanonType;
			class CRCLStatusType;
			class RotSpeedRelativeType;
			class RunProgramType;
			class RotAccelRelativeType;
			class MoveThroughToType;
			class GetStatusType;
			class MoveScrewType;
			class RotAccelAbsoluteType;
			class SetMotionCoordinationType;
			class ActuateJointType;
			class StopConditionEnumType;
			class RotSpeedAbsoluteType;
			class ThreeFingerGripperStatusType;
			class SetRobotParametersType;
			class MoveToType;
			class ObjectFactory;
			class PoseAndSetType;
			class TransAccelRelativeType;
			class DwellType;
			class SetLengthUnitsType;
			class OpenToolChangerType;
			class SetTransAccelType;
			class JointForceTorqueType;
			class PointType;
			class CommandStateEnumType;
		} // end namespace crcl
	} // end namespace base
	namespace java{
		namespace util{
			class List;
		} // end namespace java
	} // end namespace util
	namespace java{
		namespace math{
			class BigInteger;
			class BigDecimal;
		} // end namespace java
	} // end namespace math
	namespace javax{
		namespace xml{
			namespace bind{
				class JAXBElement;
			} // end namespace javax
		} // end namespace xml
	} // end namespace bind
	namespace crcl{
		namespace base{
			
			class DataThingType : public java::lang::Object {
				protected:
			        DataThingType(jobject _jthis);
			        public:
				DataThingType();
				virtual ~DataThingType();
				jstring getName();
				void setName(jstring string_0);
			}; // end class DataThingType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CRCLCommandType : public DataThingType {
				protected:
			        CRCLCommandType(jobject _jthis);
			        public:
				CRCLCommandType();
				virtual ~CRCLCommandType();
				java::math::BigInteger getCommandID();
				void setCommandID(java::math::BigInteger bigInteger_0);
			}; // end class CRCLCommandType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class MiddleCommandType : public CRCLCommandType {
				protected:
			        MiddleCommandType(jobject _jthis);
			        public:
				MiddleCommandType();
				virtual ~MiddleCommandType();
			}; // end class MiddleCommandType
		} // end namespace crcl
	} // end namespace base

	namespace java{
		namespace lang{
			
			class Enum : public Object {
				protected:
			        Enum(jobject _jthis);
			        public:
				virtual ~Enum();
				virtual jstring name();
				jstring toString();
				virtual jint hashCode();
				virtual jint compareTo(Enum enum_0);
				virtual jint ordinal();
			}; // end class Enum
		} // end namespace java
	} // end namespace lang

	namespace crcl{
		namespace base{
			
			class GripperStatusType : public DataThingType {
				protected:
			        GripperStatusType(jobject _jthis);
			        public:
				GripperStatusType();
				virtual ~GripperStatusType();
				jstring getGripperName();
				void setGripperName(jstring string_0);
			}; // end class GripperStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RotSpeedType : public DataThingType {
				protected:
			        RotSpeedType(jobject _jthis);
			        public:
				RotSpeedType();
				virtual ~RotSpeedType();
			}; // end class RotSpeedType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RotAccelType : public DataThingType {
				protected:
			        RotAccelType(jobject _jthis);
			        public:
				RotAccelType();
				virtual ~RotAccelType();
			}; // end class RotAccelType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class JointDetailsType : public DataThingType {
				protected:
			        JointDetailsType(jobject _jthis);
			        public:
				JointDetailsType();
				virtual ~JointDetailsType();
			}; // end class JointDetailsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TransSpeedType : public DataThingType {
				protected:
			        TransSpeedType(jobject _jthis);
			        public:
				TransSpeedType();
				virtual ~TransSpeedType();
			}; // end class TransSpeedType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TransAccelType : public DataThingType {
				protected:
			        TransAccelType(jobject _jthis);
			        public:
				TransAccelType();
				virtual ~TransAccelType();
			}; // end class TransAccelType
		} // end namespace crcl
	} // end namespace base

	namespace java{
		namespace lang{
			
			class Number : public Object {
				protected:
			        Number(jobject _jthis);
			        public:
				Number();
				virtual ~Number();
				jbyte byteValue();
				jshort shortValue();
			}; // end class Number
		} // end namespace java
	} // end namespace lang

	namespace crcl{
		namespace base{
			
			class PoseType : public DataThingType {
				protected:
			        PoseType(jobject _jthis);
			        public:
				PoseType();
				virtual ~PoseType();
				PointType getPoint();
				void setPoint(PointType pointType_0);
				VectorType getXAxis();
				void setXAxis(VectorType vectorType_0);
				VectorType getZAxis();
				void setZAxis(VectorType vectorType_0);
			}; // end class PoseType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CRCLProgramType : public DataThingType {
				protected:
			        CRCLProgramType(jobject _jthis);
			        public:
				CRCLProgramType();
				virtual ~CRCLProgramType();
				InitCanonType getInitCanon();
				void setInitCanon(InitCanonType initCanonType_0);
				java::util::List getMiddleCommand();
				EndCanonType getEndCanon();
				void setEndCanon(EndCanonType endCanonType_0);
			}; // end class CRCLProgramType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ActuateJointsType : public MiddleCommandType {
				protected:
			        ActuateJointsType(jobject _jthis);
			        public:
				ActuateJointsType();
				virtual ~ActuateJointsType();
				java::util::List getActuateJoint();
			}; // end class ActuateJointsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class JointSpeedAccelType : public JointDetailsType {
				protected:
			        JointSpeedAccelType(jobject _jthis);
			        public:
				JointSpeedAccelType();
				virtual ~JointSpeedAccelType();
				java::math::BigDecimal getJointSpeed();
				void setJointSpeed(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getJointAccel();
				void setJointAccel(java::math::BigDecimal bigDecimal_0);
			}; // end class JointSpeedAccelType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TransSpeedAbsoluteType : public TransSpeedType {
				protected:
			        TransSpeedAbsoluteType(jobject _jthis);
			        public:
				TransSpeedAbsoluteType();
				virtual ~TransSpeedAbsoluteType();
				java::math::BigDecimal getSetting();
				void setSetting(java::math::BigDecimal bigDecimal_0);
			}; // end class TransSpeedAbsoluteType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class PoseToleranceType : public DataThingType {
				protected:
			        PoseToleranceType(jobject _jthis);
			        public:
				PoseToleranceType();
				virtual ~PoseToleranceType();
				java::math::BigDecimal getXPointTolerance();
				void setXPointTolerance(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getYPointTolerance();
				void setYPointTolerance(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getZPointTolerance();
				void setZPointTolerance(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getXAxisTolerance();
				void setXAxisTolerance(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getZAxisTolerance();
				void setZAxisTolerance(java::math::BigDecimal bigDecimal_0);
			}; // end class PoseToleranceType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class InitCanonType : public CRCLCommandType {
				protected:
			        InitCanonType(jobject _jthis);
			        public:
				InitCanonType();
				virtual ~InitCanonType();
			}; // end class InitCanonType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class MessageType : public MiddleCommandType {
				protected:
			        MessageType(jobject _jthis);
			        public:
				MessageType();
				virtual ~MessageType();
				void setMessage(jstring string_0);
				jstring getMessage();
			}; // end class MessageType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class AngleUnitEnumType : public java::lang::Enum {
				protected:
			        AngleUnitEnumType(jobject _jthis);
			        public:
				virtual ~AngleUnitEnumType();
				static AngleUnitEnumType fromValue(jstring string_0);
				jstring value();
				static AngleUnitEnumType valueOf(jstring string_0);
			}; // end class AngleUnitEnumType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetIntermediatePoseToleranceType : public MiddleCommandType {
				protected:
			        SetIntermediatePoseToleranceType(jobject _jthis);
			        public:
				SetIntermediatePoseToleranceType();
				virtual ~SetIntermediatePoseToleranceType();
				PoseToleranceType getTolerance();
				void setTolerance(PoseToleranceType poseToleranceType_0);
			}; // end class SetIntermediatePoseToleranceType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TransAccelAbsoluteType : public TransAccelType {
				protected:
			        TransAccelAbsoluteType(jobject _jthis);
			        public:
				TransAccelAbsoluteType();
				virtual ~TransAccelAbsoluteType();
				java::math::BigDecimal getSetting();
				void setSetting(java::math::BigDecimal bigDecimal_0);
			}; // end class TransAccelAbsoluteType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class StopMotionType : public MiddleCommandType {
				protected:
			        StopMotionType(jobject _jthis);
			        public:
				StopMotionType();
				virtual ~StopMotionType();
				StopConditionEnumType getStopCondition();
				void setStopCondition(StopConditionEnumType stopConditionEnumType_0);
			}; // end class StopMotionType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class VectorType : public DataThingType {
				protected:
			        VectorType(jobject _jthis);
			        public:
				VectorType();
				virtual ~VectorType();
				java::math::BigDecimal getI();
				void setI(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getJ();
				void setJ(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getK();
				void setK(java::math::BigDecimal bigDecimal_0);
			}; // end class VectorType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetEndEffectorType : public MiddleCommandType {
				protected:
			        SetEndEffectorType(jobject _jthis);
			        public:
				SetEndEffectorType();
				virtual ~SetEndEffectorType();
				java::math::BigDecimal getSetting();
				void setSetting(java::math::BigDecimal bigDecimal_0);
			}; // end class SetEndEffectorType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CloseToolChangerType : public MiddleCommandType {
				protected:
			        CloseToolChangerType(jobject _jthis);
			        public:
				CloseToolChangerType();
				virtual ~CloseToolChangerType();
			}; // end class CloseToolChangerType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ForceUnitEnumType : public java::lang::Enum {
				protected:
			        ForceUnitEnumType(jobject _jthis);
			        public:
				virtual ~ForceUnitEnumType();
				static ForceUnitEnumType fromValue(jstring string_0);
				jstring value();
				static ForceUnitEnumType valueOf(jstring string_0);
			}; // end class ForceUnitEnumType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TorqueUnitEnumType : public java::lang::Enum {
				protected:
			        TorqueUnitEnumType(jobject _jthis);
			        public:
				virtual ~TorqueUnitEnumType();
				static TorqueUnitEnumType fromValue(jstring string_0);
				jstring value();
				static TorqueUnitEnumType valueOf(jstring string_0);
			}; // end class TorqueUnitEnumType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ConfigureJointReportsType : public MiddleCommandType {
				protected:
			        ConfigureJointReportsType(jobject _jthis);
			        public:
				ConfigureJointReportsType();
				virtual ~ConfigureJointReportsType();
				jboolean isResetAll();
				void setResetAll(jboolean boolean_0);
				java::util::List getConfigureJointReport();
			}; // end class ConfigureJointReportsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CRCLCommandInstanceType : public DataThingType {
				protected:
			        CRCLCommandInstanceType(jobject _jthis);
			        public:
				CRCLCommandInstanceType();
				virtual ~CRCLCommandInstanceType();
				CRCLCommandType getCRCLCommand();
				void setCRCLCommand(CRCLCommandType cRCLCommandType_0);
			}; // end class CRCLCommandInstanceType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetRotSpeedType : public MiddleCommandType {
				protected:
			        SetRotSpeedType(jobject _jthis);
			        public:
				SetRotSpeedType();
				virtual ~SetRotSpeedType();
				RotSpeedType getRotSpeed();
				void setRotSpeed(RotSpeedType rotSpeedType_0);
			}; // end class SetRotSpeedType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetTorqueUnitsType : public MiddleCommandType {
				protected:
			        SetTorqueUnitsType(jobject _jthis);
			        public:
				SetTorqueUnitsType();
				virtual ~SetTorqueUnitsType();
				TorqueUnitEnumType getUnitName();
				void setUnitName(TorqueUnitEnumType torqueUnitEnumType_0);
			}; // end class SetTorqueUnitsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ConfigureJointReportType : public DataThingType {
				protected:
			        ConfigureJointReportType(jobject _jthis);
			        public:
				ConfigureJointReportType();
				virtual ~ConfigureJointReportType();
				java::math::BigInteger getJointNumber();
				void setJointNumber(java::math::BigInteger bigInteger_0);
				jboolean isReportPosition();
				void setReportPosition(jboolean boolean_0);
				jboolean isReportTorqueOrForce();
				void setReportTorqueOrForce(jboolean boolean_0);
				jboolean isReportVelocity();
				void setReportVelocity(jboolean boolean_0);
			}; // end class ConfigureJointReportType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetEndPoseToleranceType : public MiddleCommandType {
				protected:
			        SetEndPoseToleranceType(jobject _jthis);
			        public:
				SetEndPoseToleranceType();
				virtual ~SetEndPoseToleranceType();
				PoseToleranceType getTolerance();
				void setTolerance(PoseToleranceType poseToleranceType_0);
			}; // end class SetEndPoseToleranceType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ParameterSettingType : public DataThingType {
				protected:
			        ParameterSettingType(jobject _jthis);
			        public:
				ParameterSettingType();
				virtual ~ParameterSettingType();
				jstring getParameterName();
				void setParameterName(jstring string_0);
				jstring getParameterValue();
				void setParameterValue(jstring string_0);
			}; // end class ParameterSettingType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetTransSpeedType : public MiddleCommandType {
				protected:
			        SetTransSpeedType(jobject _jthis);
			        public:
				SetTransSpeedType();
				virtual ~SetTransSpeedType();
				TransSpeedType getTransSpeed();
				void setTransSpeed(TransSpeedType transSpeedType_0);
			}; // end class SetTransSpeedType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class JointStatusesType : public DataThingType {
				protected:
			        JointStatusesType(jobject _jthis);
			        public:
				JointStatusesType();
				virtual ~JointStatusesType();
				java::util::List getJointStatus();
			}; // end class JointStatusesType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ParallelGripperStatusType : public GripperStatusType {
				protected:
			        ParallelGripperStatusType(jobject _jthis);
			        public:
				ParallelGripperStatusType();
				virtual ~ParallelGripperStatusType();
				java::math::BigDecimal getSeparation();
				void setSeparation(java::math::BigDecimal bigDecimal_0);
			}; // end class ParallelGripperStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class LengthUnitEnumType : public java::lang::Enum {
				protected:
			        LengthUnitEnumType(jobject _jthis);
			        public:
				virtual ~LengthUnitEnumType();
				static LengthUnitEnumType fromValue(jstring string_0);
				jstring value();
				static LengthUnitEnumType valueOf(jstring string_0);
			}; // end class LengthUnitEnumType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetRotAccelType : public MiddleCommandType {
				protected:
			        SetRotAccelType(jobject _jthis);
			        public:
				SetRotAccelType();
				virtual ~SetRotAccelType();
				RotAccelType getRotAccel();
				void setRotAccel(RotAccelType rotAccelType_0);
			}; // end class SetRotAccelType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetAngleUnitsType : public MiddleCommandType {
				protected:
			        SetAngleUnitsType(jobject _jthis);
			        public:
				SetAngleUnitsType();
				virtual ~SetAngleUnitsType();
				AngleUnitEnumType getUnitName();
				void setUnitName(AngleUnitEnumType angleUnitEnumType_0);
			}; // end class SetAngleUnitsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CommandStatusType : public DataThingType {
				protected:
			        CommandStatusType(jobject _jthis);
			        public:
				CommandStatusType();
				virtual ~CommandStatusType();
				java::math::BigInteger getCommandID();
				void setCommandID(java::math::BigInteger bigInteger_0);
				java::math::BigInteger getStatusID();
				void setStatusID(java::math::BigInteger bigInteger_0);
				CommandStateEnumType getCommandState();
				void setCommandState(CommandStateEnumType commandStateEnumType_0);
			}; // end class CommandStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TransSpeedRelativeType : public TransSpeedType {
				protected:
			        TransSpeedRelativeType(jobject _jthis);
			        public:
				TransSpeedRelativeType();
				virtual ~TransSpeedRelativeType();
				java::math::BigDecimal getFraction();
				void setFraction(java::math::BigDecimal bigDecimal_0);
			}; // end class TransSpeedRelativeType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetForceUnitsType : public MiddleCommandType {
				protected:
			        SetForceUnitsType(jobject _jthis);
			        public:
				SetForceUnitsType();
				virtual ~SetForceUnitsType();
				ForceUnitEnumType getUnitName();
				void setUnitName(ForceUnitEnumType forceUnitEnumType_0);
			}; // end class SetForceUnitsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class JointStatusType : public DataThingType {
				protected:
			        JointStatusType(jobject _jthis);
			        public:
				JointStatusType();
				virtual ~JointStatusType();
				java::math::BigInteger getJointNumber();
				void setJointNumber(java::math::BigInteger bigInteger_0);
				java::math::BigDecimal getJointPosition();
				void setJointPosition(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getJointTorqueOrForce();
				void setJointTorqueOrForce(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getJointVelocity();
				void setJointVelocity(java::math::BigDecimal bigDecimal_0);
			}; // end class JointStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class VacuumGripperStatusType : public GripperStatusType {
				protected:
			        VacuumGripperStatusType(jobject _jthis);
			        public:
				VacuumGripperStatusType();
				virtual ~VacuumGripperStatusType();
				jboolean isIsPowered();
				void setIsPowered(jboolean boolean_0);
			}; // end class VacuumGripperStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetEndEffectorParametersType : public MiddleCommandType {
				protected:
			        SetEndEffectorParametersType(jobject _jthis);
			        public:
				SetEndEffectorParametersType();
				virtual ~SetEndEffectorParametersType();
				java::util::List getParameterSetting();
			}; // end class SetEndEffectorParametersType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class EndCanonType : public CRCLCommandType {
				protected:
			        EndCanonType(jobject _jthis);
			        public:
				EndCanonType();
				virtual ~EndCanonType();
			}; // end class EndCanonType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CRCLStatusType : public DataThingType {
				protected:
			        CRCLStatusType(jobject _jthis);
			        public:
				CRCLStatusType();
				virtual ~CRCLStatusType();
				CommandStatusType getCommandStatus();
				void setCommandStatus(CommandStatusType commandStatusType_0);
				JointStatusesType getJointStatuses();
				void setJointStatuses(JointStatusesType jointStatusesType_0);
				PoseType getPose();
				void setPose(PoseType poseType_0);
				GripperStatusType getGripperStatus();
				void setGripperStatus(GripperStatusType gripperStatusType_0);
			}; // end class CRCLStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RotSpeedRelativeType : public RotSpeedType {
				protected:
			        RotSpeedRelativeType(jobject _jthis);
			        public:
				RotSpeedRelativeType();
				virtual ~RotSpeedRelativeType();
				java::math::BigDecimal getFraction();
				void setFraction(java::math::BigDecimal bigDecimal_0);
			}; // end class RotSpeedRelativeType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RunProgramType : public MiddleCommandType {
				protected:
			        RunProgramType(jobject _jthis);
			        public:
				RunProgramType();
				virtual ~RunProgramType();
				jstring getProgramText();
				void setProgramText(jstring string_0);
			}; // end class RunProgramType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RotAccelRelativeType : public RotAccelType {
				protected:
			        RotAccelRelativeType(jobject _jthis);
			        public:
				RotAccelRelativeType();
				virtual ~RotAccelRelativeType();
				java::math::BigDecimal getFraction();
				void setFraction(java::math::BigDecimal bigDecimal_0);
			}; // end class RotAccelRelativeType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class MoveThroughToType : public MiddleCommandType {
				protected:
			        MoveThroughToType(jobject _jthis);
			        public:
				MoveThroughToType();
				virtual ~MoveThroughToType();
				jboolean isMoveStraight();
				void setMoveStraight(jboolean boolean_0);
				java::util::List getWaypoint();
				java::math::BigInteger getNumPositions();
				void setNumPositions(java::math::BigInteger bigInteger_0);
			}; // end class MoveThroughToType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class GetStatusType : public MiddleCommandType {
				protected:
			        GetStatusType(jobject _jthis);
			        public:
				GetStatusType();
				virtual ~GetStatusType();
			}; // end class GetStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class MoveScrewType : public MiddleCommandType {
				protected:
			        MoveScrewType(jobject _jthis);
			        public:
				MoveScrewType();
				virtual ~MoveScrewType();
				PoseType getStartPosition();
				void setStartPosition(PoseType poseType_0);
				PointType getAxisPoint();
				void setAxisPoint(PointType pointType_0);
				java::math::BigDecimal getAxialDistanceFree();
				void setAxialDistanceFree(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getAxialDistanceScrew();
				void setAxialDistanceScrew(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getTurn();
				void setTurn(java::math::BigDecimal bigDecimal_0);
			}; // end class MoveScrewType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RotAccelAbsoluteType : public RotAccelType {
				protected:
			        RotAccelAbsoluteType(jobject _jthis);
			        public:
				RotAccelAbsoluteType();
				virtual ~RotAccelAbsoluteType();
				java::math::BigDecimal getSetting();
				void setSetting(java::math::BigDecimal bigDecimal_0);
			}; // end class RotAccelAbsoluteType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetMotionCoordinationType : public MiddleCommandType {
				protected:
			        SetMotionCoordinationType(jobject _jthis);
			        public:
				SetMotionCoordinationType();
				virtual ~SetMotionCoordinationType();
				jboolean isCoordinated();
				void setCoordinated(jboolean boolean_0);
			}; // end class SetMotionCoordinationType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ActuateJointType : public DataThingType {
				protected:
			        ActuateJointType(jobject _jthis);
			        public:
				ActuateJointType();
				virtual ~ActuateJointType();
				java::math::BigInteger getJointNumber();
				void setJointNumber(java::math::BigInteger bigInteger_0);
				java::math::BigDecimal getJointPosition();
				void setJointPosition(java::math::BigDecimal bigDecimal_0);
				void setJointDetails(JointDetailsType jointDetailsType_0);
				JointDetailsType getJointDetails();
			}; // end class ActuateJointType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class StopConditionEnumType : public java::lang::Enum {
				protected:
			        StopConditionEnumType(jobject _jthis);
			        public:
				virtual ~StopConditionEnumType();
				static StopConditionEnumType fromValue(jstring string_0);
				jstring value();
				static StopConditionEnumType valueOf(jstring string_0);
			}; // end class StopConditionEnumType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class RotSpeedAbsoluteType : public RotSpeedType {
				protected:
			        RotSpeedAbsoluteType(jobject _jthis);
			        public:
				RotSpeedAbsoluteType();
				virtual ~RotSpeedAbsoluteType();
				java::math::BigDecimal getSetting();
				void setSetting(java::math::BigDecimal bigDecimal_0);
			}; // end class RotSpeedAbsoluteType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ThreeFingerGripperStatusType : public GripperStatusType {
				protected:
			        ThreeFingerGripperStatusType(jobject _jthis);
			        public:
				ThreeFingerGripperStatusType();
				virtual ~ThreeFingerGripperStatusType();
				java::math::BigDecimal getFinger1Position();
				void setFinger1Position(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getFinger2Position();
				void setFinger2Position(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getFinger3Position();
				void setFinger3Position(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getFinger1Force();
				void setFinger1Force(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getFinger2Force();
				void setFinger2Force(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getFinger3Force();
				void setFinger3Force(java::math::BigDecimal bigDecimal_0);
			}; // end class ThreeFingerGripperStatusType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetRobotParametersType : public MiddleCommandType {
				protected:
			        SetRobotParametersType(jobject _jthis);
			        public:
				SetRobotParametersType();
				virtual ~SetRobotParametersType();
				java::util::List getParameterSetting();
			}; // end class SetRobotParametersType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class MoveToType : public MiddleCommandType {
				protected:
			        MoveToType(jobject _jthis);
			        public:
				MoveToType();
				virtual ~MoveToType();
				jboolean isMoveStraight();
				void setMoveStraight(jboolean boolean_0);
				PoseType getEndPosition();
				void setEndPosition(PoseType poseType_0);
			}; // end class MoveToType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class ObjectFactory : public java::lang::Object {
				protected:
			        ObjectFactory(jobject _jthis);
			        public:
				ObjectFactory();
				virtual ~ObjectFactory();
				CRCLProgramType createCRCLProgramType();
				CRCLCommandInstanceType createCRCLCommandInstanceType();
				CRCLStatusType createCRCLStatusType();
				PointType createPointType();
				PoseType createPoseType();
				VectorType createVectorType();
				ActuateJointsType createActuateJointsType();
				DwellType createDwellType();
				ActuateJointType createActuateJointType();
				CloseToolChangerType createCloseToolChangerType();
				ConfigureJointReportsType createConfigureJointReportsType();
				ConfigureJointReportType createConfigureJointReportType();
				EndCanonType createEndCanonType();
				GetStatusType createGetStatusType();
				InitCanonType createInitCanonType();
				JointForceTorqueType createJointForceTorqueType();
				JointSpeedAccelType createJointSpeedAccelType();
				MessageType createMessageType();
				MoveScrewType createMoveScrewType();
				MoveThroughToType createMoveThroughToType();
				MoveToType createMoveToType();
				OpenToolChangerType createOpenToolChangerType();
				ParameterSettingType createParameterSettingType();
				PoseAndSetType createPoseAndSetType();
				PoseToleranceType createPoseToleranceType();
				RotAccelAbsoluteType createRotAccelAbsoluteType();
				RotAccelRelativeType createRotAccelRelativeType();
				RotSpeedAbsoluteType createRotSpeedAbsoluteType();
				RotSpeedRelativeType createRotSpeedRelativeType();
				RunProgramType createRunProgramType();
				SetAngleUnitsType createSetAngleUnitsType();
				SetEndEffectorParametersType createSetEndEffectorParametersType();
				SetEndEffectorType createSetEndEffectorType();
				SetEndPoseToleranceType createSetEndPoseToleranceType();
				SetForceUnitsType createSetForceUnitsType();
				SetIntermediatePoseToleranceType createSetIntermediatePoseToleranceType();
				SetLengthUnitsType createSetLengthUnitsType();
				SetMotionCoordinationType createSetMotionCoordinationType();
				SetRobotParametersType createSetRobotParametersType();
				SetRotAccelType createSetRotAccelType();
				SetRotSpeedType createSetRotSpeedType();
				SetTorqueUnitsType createSetTorqueUnitsType();
				SetTransAccelType createSetTransAccelType();
				SetTransSpeedType createSetTransSpeedType();
				StopMotionType createStopMotionType();
				TransAccelAbsoluteType createTransAccelAbsoluteType();
				TransAccelRelativeType createTransAccelRelativeType();
				TransSpeedAbsoluteType createTransSpeedAbsoluteType();
				TransSpeedRelativeType createTransSpeedRelativeType();
				CommandStatusType createCommandStatusType();
				JointStatusesType createJointStatusesType();
				JointStatusType createJointStatusType();
				ParallelGripperStatusType createParallelGripperStatusType();
				ThreeFingerGripperStatusType createThreeFingerGripperStatusType();
				VacuumGripperStatusType createVacuumGripperStatusType();
				javax::xml::bind::JAXBElement createCRCLProgram(CRCLProgramType cRCLProgramType_0);
				javax::xml::bind::JAXBElement createCRCLCommandInstance(CRCLCommandInstanceType cRCLCommandInstanceType_0);
				javax::xml::bind::JAXBElement createCRCLStatus(CRCLStatusType cRCLStatusType_0);
			}; // end class ObjectFactory
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class PoseAndSetType : public PoseType {
				protected:
			        PoseAndSetType(jobject _jthis);
			        public:
				PoseAndSetType();
				virtual ~PoseAndSetType();
				PoseToleranceType getTolerance();
				void setTolerance(PoseToleranceType poseToleranceType_0);
				RotSpeedType getRotSpeed();
				void setRotSpeed(RotSpeedType rotSpeedType_0);
				TransSpeedType getTransSpeed();
				void setTransSpeed(TransSpeedType transSpeedType_0);
				RotAccelType getRotAccel();
				void setRotAccel(RotAccelType rotAccelType_0);
				jboolean isCoordinated();
				void setCoordinated(jboolean boolean_0);
				TransAccelType getTransAccel();
				void setTransAccel(TransAccelType transAccelType_0);
			}; // end class PoseAndSetType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class TransAccelRelativeType : public TransAccelType {
				protected:
			        TransAccelRelativeType(jobject _jthis);
			        public:
				TransAccelRelativeType();
				virtual ~TransAccelRelativeType();
				java::math::BigDecimal getFraction();
				void setFraction(java::math::BigDecimal bigDecimal_0);
			}; // end class TransAccelRelativeType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class DwellType : public MiddleCommandType {
				protected:
			        DwellType(jobject _jthis);
			        public:
				DwellType();
				virtual ~DwellType();
				java::math::BigDecimal getDwellTime();
				void setDwellTime(java::math::BigDecimal bigDecimal_0);
			}; // end class DwellType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetLengthUnitsType : public MiddleCommandType {
				protected:
			        SetLengthUnitsType(jobject _jthis);
			        public:
				SetLengthUnitsType();
				virtual ~SetLengthUnitsType();
				LengthUnitEnumType getUnitName();
				void setUnitName(LengthUnitEnumType lengthUnitEnumType_0);
			}; // end class SetLengthUnitsType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class OpenToolChangerType : public MiddleCommandType {
				protected:
			        OpenToolChangerType(jobject _jthis);
			        public:
				OpenToolChangerType();
				virtual ~OpenToolChangerType();
			}; // end class OpenToolChangerType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class SetTransAccelType : public MiddleCommandType {
				protected:
			        SetTransAccelType(jobject _jthis);
			        public:
				SetTransAccelType();
				virtual ~SetTransAccelType();
				TransAccelType getTransAccel();
				void setTransAccel(TransAccelType transAccelType_0);
			}; // end class SetTransAccelType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class JointForceTorqueType : public JointDetailsType {
				protected:
			        JointForceTorqueType(jobject _jthis);
			        public:
				JointForceTorqueType();
				virtual ~JointForceTorqueType();
				java::math::BigDecimal getSetting();
				void setSetting(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getChangeRate();
				void setChangeRate(java::math::BigDecimal bigDecimal_0);
			}; // end class JointForceTorqueType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class PointType : public DataThingType {
				protected:
			        PointType(jobject _jthis);
			        public:
				PointType();
				virtual ~PointType();
				java::math::BigDecimal getX();
				void setX(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getY();
				void setY(java::math::BigDecimal bigDecimal_0);
				java::math::BigDecimal getZ();
				void setZ(java::math::BigDecimal bigDecimal_0);
			}; // end class PointType
		} // end namespace crcl
	} // end namespace base

	namespace crcl{
		namespace base{
			
			class CommandStateEnumType : public java::lang::Enum {
				protected:
			        CommandStateEnumType(jobject _jthis);
			        public:
				virtual ~CommandStateEnumType();
				static CommandStateEnumType fromValue(jstring string_0);
				jstring value();
				static CommandStateEnumType valueOf(jstring string_0);
			}; // end class CommandStateEnumType
		} // end namespace crcl
	} // end namespace base

	namespace java{
		namespace util{
			
			class List : public lang::Object {
				protected:
			        List(jobject _jthis);
			        public:
				List();
				virtual ~List();
			}; // end class List
		} // end namespace java
	} // end namespace util

	namespace java{
		namespace math{
			
			class BigInteger : public lang::Number {
				protected:
			        BigInteger(jobject _jthis);
			        public:
				BigInteger(jstring string_0,jint int_1);
				BigInteger(jstring string_0);
				virtual ~BigInteger();
				jint bitLength();
				BigInteger nextProbablePrime();
				BigInteger subtract(BigInteger bigInteger_0);
				BigInteger multiply(BigInteger bigInteger_0);
				BigInteger gcd(BigInteger bigInteger_0);
				BigInteger negate();
				BigInteger modPow(BigInteger bigInteger_0,BigInteger bigInteger_1);
				BigInteger modInverse(BigInteger bigInteger_0);
				BigInteger shiftRight(jint int_0);
				jboolean testBit(jint int_0);
				BigInteger setBit(jint int_0);
				BigInteger clearBit(jint int_0);
				BigInteger flipBit(jint int_0);
				jint getLowestSetBit();
				jboolean isProbablePrime(jint int_0);
				jlong longValueExact();
				jint intValueExact();
				jshort shortValueExact();
				jbyte byteValueExact();
				BigInteger mod(BigInteger bigInteger_0);
				BigInteger notMethod();
				BigInteger add(BigInteger bigInteger_0);
				jint bitCount();
				jstring toString();
				jstring toString(jint int_0);
				jint hashCode();
				BigInteger abs();
				BigInteger pow(jint int_0);
				BigInteger min(BigInteger bigInteger_0);
				BigInteger max(BigInteger bigInteger_0);
				jint compareTo(BigInteger bigInteger_0);
				jint intValue();
				jlong longValue();
				jfloat floatValue();
				jdouble doubleValue();
				static BigInteger valueOf(jlong long_0);
				jint signum();
				BigInteger shiftLeft(jint int_0);
				BigInteger divide(BigInteger bigInteger_0);
				BigInteger remainder(BigInteger bigInteger_0);
				BigInteger andMethod(BigInteger bigInteger_0);
				BigInteger orMethod(BigInteger bigInteger_0);
				BigInteger xorMethod(BigInteger bigInteger_0);
				BigInteger andNot(BigInteger bigInteger_0);
			}; // end class BigInteger
		} // end namespace java
	} // end namespace math

	namespace java{
		namespace math{
			
			class BigDecimal : public lang::Number {
				protected:
			        BigDecimal(jobject _jthis);
			        public:
				BigDecimal(jdouble double_0);
				BigDecimal(jint int_0);
				BigDecimal(jlong long_0);
				BigDecimal(BigInteger bigInteger_0,jint int_1);
				BigDecimal(BigInteger bigInteger_0);
				BigDecimal(jstring string_0);
				virtual ~BigDecimal();
				BigDecimal subtract(BigDecimal bigDecimal_0);
				BigDecimal multiply(BigDecimal bigDecimal_0);
				BigDecimal negate();
				jlong longValueExact();
				jint intValueExact();
				jshort shortValueExact();
				jbyte byteValueExact();
				BigInteger toBigInteger();
				jint precision();
				BigDecimal divideToIntegralValue(BigDecimal bigDecimal_0);
				BigDecimal plus();
				BigInteger unscaledValue();
				BigDecimal setScale(jint int_0);
				BigDecimal setScale(jint int_0,jint int_1);
				BigDecimal movePointLeft(jint int_0);
				BigDecimal movePointRight(jint int_0);
				BigDecimal scaleByPowerOfTen(jint int_0);
				BigDecimal stripTrailingZeros();
				jstring toEngineeringString();
				jstring toPlainString();
				BigInteger toBigIntegerExact();
				BigDecimal add(BigDecimal bigDecimal_0);
				jstring toString();
				jint hashCode();
				BigDecimal abs();
				BigDecimal pow(jint int_0);
				BigDecimal min(BigDecimal bigDecimal_0);
				BigDecimal max(BigDecimal bigDecimal_0);
				jint compareTo(BigDecimal bigDecimal_0);
				jint intValue();
				jlong longValue();
				jfloat floatValue();
				jdouble doubleValue();
				static BigDecimal valueOf(jlong long_0,jint int_1);
				static BigDecimal valueOf(jlong long_0);
				static BigDecimal valueOf(jdouble double_0);
				jint signum();
				BigDecimal divide(BigDecimal bigDecimal_0,jint int_1,jint int_2);
				BigDecimal divide(BigDecimal bigDecimal_0,jint int_1);
				BigDecimal divide(BigDecimal bigDecimal_0);
				BigDecimal remainder(BigDecimal bigDecimal_0);
				BigDecimal ulp();
				jint scale();
			}; // end class BigDecimal
		} // end namespace java
	} // end namespace math

	namespace javax{
		namespace xml{
			namespace bind{
				
				class JAXBElement : public java::lang::Object {
					protected:
				        JAXBElement(jobject _jthis);
				        public:
					virtual ~JAXBElement();
					jboolean isNil();
					void setNil(jboolean boolean_0);
					jboolean isGlobalScope();
					jboolean isTypeSubstituted();
				}; // end class JAXBElement
			} // end namespace javax
		} // end namespace xml
	} // end namespace bind



// end namespace crcljavabase1
}

// end #ifndef crcljavabase1_h
#endif

