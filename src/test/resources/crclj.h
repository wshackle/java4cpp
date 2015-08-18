#ifndef crclj_h
#define crclj_h

#include <jni.h>
#include "crclj_fwd.h"

namespace crclj {

    extern JNIEnv *getEnv();
    extern void releaseEnv(JNIEnv *);
    extern void PrintJObject(const char *prefix, jobject jobj);
    extern void DebugPrintJObject(const char *file, int lineno, const char *prefix, jobject jobj);
    extern void SetDebugJ4Cpp(bool debug);
    extern bool GetDebugJ4Cpp();
    extern void PrintObject(const char *prefix, const ::crclj::java::lang::Object &objref);
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
    
    
    
    


    
 namespace crcl{
  namespace base{
   
   class DataThingType : public ::crclj::java::lang::Object {
       public:
           DataThingType(jobject _jthis, bool copy);
           DataThingType(const DataThingType &);
           
    DataThingType();
    ~DataThingType();
    jstring getName();
    void setName(jstring string_0);
    void setName(const char * easyArg_0);
   }; // end class DataThingType

   
   class JointDetailsType : public DataThingType {
       public:
           JointDetailsType(jobject _jthis, bool copy);
           JointDetailsType(const JointDetailsType &);
           
    JointDetailsType();
    ~JointDetailsType();
   }; // end class JointDetailsType

   
   class JointSpeedAccelType : public JointDetailsType {
       public:
           JointSpeedAccelType(jobject _jthis, bool copy);
           JointSpeedAccelType(const JointSpeedAccelType &);
           
    JointSpeedAccelType();
    ~JointSpeedAccelType();
    ::crclj::java::math::BigDecimal getJointSpeed();
    void setJointSpeed(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getJointAccel();
    void setJointAccel(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class JointSpeedAccelType

   
   class CRCLCommandType : public DataThingType {
       public:
           CRCLCommandType(jobject _jthis, bool copy);
           CRCLCommandType(const CRCLCommandType &);
           
    CRCLCommandType();
    ~CRCLCommandType();
    ::crclj::java::math::BigInteger getCommandID();
    void setCommandID(::crclj::java::math::BigInteger  &bigInteger_0);
   }; // end class CRCLCommandType

   
   class MiddleCommandType : public CRCLCommandType {
       public:
           MiddleCommandType(jobject _jthis, bool copy);
           MiddleCommandType(const MiddleCommandType &);
           
    MiddleCommandType();
    ~MiddleCommandType();
   }; // end class MiddleCommandType

   
   class SetIntermediatePoseToleranceType : public MiddleCommandType {
       public:
           SetIntermediatePoseToleranceType(jobject _jthis, bool copy);
           SetIntermediatePoseToleranceType(const SetIntermediatePoseToleranceType &);
           
    SetIntermediatePoseToleranceType();
    ~SetIntermediatePoseToleranceType();
    void setTolerance(PoseToleranceType  &poseToleranceType_0);
    PoseToleranceType getTolerance();
   }; // end class SetIntermediatePoseToleranceType

   
   class SetEndPoseToleranceType : public MiddleCommandType {
       public:
           SetEndPoseToleranceType(jobject _jthis, bool copy);
           SetEndPoseToleranceType(const SetEndPoseToleranceType &);
           
    SetEndPoseToleranceType();
    ~SetEndPoseToleranceType();
    void setTolerance(PoseToleranceType  &poseToleranceType_0);
    PoseToleranceType getTolerance();
   }; // end class SetEndPoseToleranceType

   
   class EndCanonType : public CRCLCommandType {
       public:
           EndCanonType(jobject _jthis, bool copy);
           EndCanonType(const EndCanonType &);
           
    EndCanonType();
    ~EndCanonType();
   }; // end class EndCanonType

   
   class SetRobotParametersType : public MiddleCommandType {
       public:
           SetRobotParametersType(jobject _jthis, bool copy);
           SetRobotParametersType(const SetRobotParametersType &);
           
    SetRobotParametersType();
    ~SetRobotParametersType();
    ::crclj::java::util::List getParameterSetting();
   }; // end class SetRobotParametersType
  } // end namespace base


  namespace utils{
   
   class DefaultMain : public ::crclj::java::lang::Object {
       public:
           DefaultMain(jobject _jthis, bool copy);
           DefaultMain(const DefaultMain &);
           
    DefaultMain();
    ~DefaultMain();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class DefaultMain

   
   class PoseToleranceChecker : public ::crclj::java::lang::Object {
       public:
           PoseToleranceChecker(jobject _jthis, bool copy);
           PoseToleranceChecker(const PoseToleranceChecker &);
           
    protected:
    PoseToleranceChecker();
    public:
    ~PoseToleranceChecker();
    static jboolean containsNull(::crclj::crcl::base::PoseType  &poseType_0);
    static jboolean containsNull(::crclj::crcl::base::VectorType  &vectorType_0);
    static jboolean containsNull(::crclj::crcl::base::PointType  &pointType_0);
    static jboolean containsNull(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0);
    static jboolean isInTolerance(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1,::crclj::crcl::base::PoseToleranceType  &poseToleranceType_2);
    static jboolean isInTolerance(::crclj::java::math::BigDecimal  &bigDecimal_0,::crclj::java::math::BigDecimal  &bigDecimal_1,::crclj::java::math::BigDecimal  &bigDecimal_2);
   }; // end class PoseToleranceChecker

   
   class PendantClientOuterStub : public ::crclj::java::lang::Object {
       public:
           PendantClientOuterStub(jobject _jthis, bool copy);
           PendantClientOuterStub(const PendantClientOuterStub &);
           
    PendantClientOuterStub();
    PendantClientOuterStub(jboolean boolean_0,jboolean boolean_1,jstring string_2,jint int_3,jboolean boolean_4,jboolean boolean_5,jboolean boolean_6,jboolean boolean_7,jboolean boolean_8,jboolean boolean_9);
    PendantClientOuterStub(jboolean easyArg_0,jboolean easyArg_1,const char * easyArg_2,jint easyArg_3,jboolean easyArg_4,jboolean easyArg_5,jboolean easyArg_6,jboolean easyArg_7,jboolean easyArg_8,jboolean easyArg_9);
    ~PendantClientOuterStub();
    void finishConnect();
    void showMessage(jstring string_0);
    void showMessage(const char * easyArg_0);
    void showMessage(::crclj::java::lang::Throwable  &throwable_0);
    jboolean showDebugMessage(jstring string_0);
    jboolean showDebugMessage(const char * easyArg_0);
    jboolean validateXmlSelected();
    jboolean replaceStateSelected();
    void finishDisconnect();
    void finishSetStatus();
    void checkXmlQuery(CRCLSocket  &cRCLSocket_0);
    void stopPollTimer();
    void checkPollSelected();
    jboolean isDebugWaitForDoneSelected();
    jboolean isDebugSendCommandSelected();
    jboolean isDebugReadStatusSelected();
    void showCurrentProgramLine(jint int_0);
    void finishOpenXmlProgramFile(::crclj::java::io::File  &file_0,::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_1);
    ::crclj::crcl::base::CRCLProgramType editProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    void showLastProgramLineExecTimeMillisDists(jlong long_0,jdouble double_1);
    jboolean isRecordPoseSelected();
    jboolean isEXISelected();
    jboolean isUseReadStatusThreadSelected();
    jstring getHost();
    jint getPort();
   }; // end class PendantClientOuterStub
  } // end namespace utils
 } // end namespace crcl


 namespace java{
  namespace awt{
   
   class Component : public ::crclj::java::lang::Object {
       public:
           Component(jobject _jthis, bool copy);
           Component(const Component &);
           
    protected:
    Component();
    public:
    ~Component();
    void transferFocusBackward();
    void setEnabled(jboolean boolean_0);
    jboolean isDoubleBuffered();
    void enableInputMethods(jboolean boolean_0);
    jboolean isForegroundSet();
    jboolean isBackgroundSet();
    jboolean isFontSet();
    jint getBaseline(jint int_0,jint int_1);
    void revalidate();
    jboolean isCursorSet();
    void setIgnoreRepaint(jboolean boolean_0);
    jboolean getIgnoreRepaint();
    jboolean inside(jint int_0,jint int_1);
    jboolean isFocusTraversable();
    void setFocusable(jboolean boolean_0);
    void setFocusTraversalKeysEnabled(jboolean boolean_0);
    jboolean getFocusTraversalKeysEnabled();
    jboolean requestFocusInWindow();
    void nextFocus();
    void transferFocusUpCycle();
    jboolean hasFocus();
    jboolean isValid();
    void validate();
    void addNotify();
    void removeNotify();
     ::crclj::java::lang::Object getTreeLock();
    jboolean isDisplayable();
    void setLocation(jint int_0,jint int_1);
    void reshape(jint int_0,jint int_1,jint int_2,jint int_3);
    void show(jboolean boolean_0);
    void show();
    void hide();
    jboolean isFocusCycleRoot(Container  &container_0);
    Container getFocusCycleRootAncestor();
    jboolean isShowing();
    void setBounds(jint int_0,jint int_1,jint int_2,jint int_3);
    jint getX();
    jint getY();
    jboolean isMinimumSizeSet();
    jboolean isVisible();
    void requestFocus();
    jint getWidth();
    jint getHeight();
    void doLayout();
    jfloat getAlignmentX();
    jfloat getAlignmentY();
    Component getComponentAt(jint int_0,jint int_1);
    Component locate(jint int_0,jint int_1);
    jboolean areFocusTraversalKeysSet(jint int_0);
    jboolean isEnabled();
    jboolean isFocusable();
    jboolean isLightweight();
    jboolean isFocusOwner();
    void transferFocus();
    jboolean isPreferredSizeSet();
    jboolean isMaximumSizeSet();
    void invalidate();
    void repaint(jlong long_0,jint int_1,jint int_2,jint int_3,jint int_4);
    void repaint(jint int_0,jint int_1,jint int_2,jint int_3);
    void repaint(jlong long_0);
    void repaint();
    void firePropertyChange(jstring string_0,jshort short_1,jshort short_2);
    void firePropertyChange(const char * easyArg_0,jshort easyArg_1,jshort easyArg_2);
    void firePropertyChange(jstring string_0,jchar char_1,jchar char_2);
    void firePropertyChange(const char * easyArg_0,jchar easyArg_1,jchar easyArg_2);
    void firePropertyChange(jstring string_0,jbyte byte_1,jbyte byte_2);
    void firePropertyChange(const char * easyArg_0,jbyte easyArg_1,jbyte easyArg_2);
    void firePropertyChange(jstring string_0,jlong long_1,jlong long_2);
    void firePropertyChange(const char * easyArg_0,jlong easyArg_1,jlong easyArg_2);
    void firePropertyChange(jstring string_0,jfloat float_1,jfloat float_2);
    void firePropertyChange(const char * easyArg_0,jfloat easyArg_1,jfloat easyArg_2);
    void firePropertyChange(jstring string_0,jdouble double_1,jdouble double_2);
    void firePropertyChange(const char * easyArg_0,jdouble easyArg_1,jdouble easyArg_2);
    void move(jint int_0,jint int_1);
    void layout();
    void setVisible(jboolean boolean_0);
    jstring toString();
    jstring getName();
    jboolean contains(jint int_0,jint int_1);
    Container getParent();
    void setName(jstring string_0);
    void setName(const char * easyArg_0);
    void list(::crclj::java::io::PrintStream  &printStream_0,jint int_1);
    void list(::crclj::java::io::PrintStream  &printStream_0);
    void list();
    jboolean isOpaque();
    void setSize(jint int_0,jint int_1);
    void resize(jint int_0,jint int_1);
    void enable(jboolean boolean_0);
    void enable();
    void disable();
   }; // end class Component

   
   class Container : public Component {
       public:
           Container(jobject _jthis, bool copy);
           Container(const Container &);
           
    Container();
    ~Container();
    void validate();
    void addNotify();
    void removeNotify();
    void setFocusCycleRoot(jboolean boolean_0);
    jboolean isFocusCycleRoot(Container  &container_0);
    jboolean isFocusCycleRoot();
    jboolean isValidateRoot();
    jint getComponentCount();
    Component getComponent(jint int_0);
    jint countComponents();
    jobjectArray getComponents();
    void setComponentZOrder(Component  &component_0,jint int_1);
    jint getComponentZOrder(Component  &component_0);
    void doLayout();
    jfloat getAlignmentX();
    jfloat getAlignmentY();
    Component getComponentAt(jint int_0,jint int_1);
    Component locate(jint int_0,jint int_1);
    Component findComponentAt(jint int_0,jint int_1);
    jboolean isAncestorOf(Component  &component_0);
    jboolean areFocusTraversalKeysSet(jint int_0);
    jboolean isFocusTraversalPolicySet();
     void setFocusTraversalPolicyProvider(jboolean boolean_0);
     jboolean isFocusTraversalPolicyProvider();
    void transferFocusDownCycle();
    void invalidate();
    void layout();
    Component add(Component  &component_0);
    void add(Component  &component_0,::crclj::java::lang::Object  &object_1,jint int_2);
    Component add(jstring string_0,Component  &component_1);
    Component add(const char * easyArg_0,Component easyArg_1);
    Component add(Component  &component_0,jint int_1);
    void add(Component  &component_0,::crclj::java::lang::Object  &object_1);
    void remove(Component  &component_0);
    void remove(jint int_0);
    void list(::crclj::java::io::PrintStream  &printStream_0,jint int_1);
    void removeAll();
   }; // end class Container
  } // end namespace awt
 } // end namespace java


 namespace javax{
  namespace swing{
   
   class JComponent : public ::crclj::java::awt::Container {
       public:
           JComponent(jobject _jthis, bool copy);
           JComponent(const JComponent &);
           
    JComponent();
    ~JComponent();
    void setInheritsPopupMenu(jboolean boolean_0);
    jboolean getInheritsPopupMenu();
    jboolean isPaintingTile();
     jboolean isPaintingForPrint();
    jboolean isManagingFocus();
    void setNextFocusableComponent(::crclj::java::awt::Component  &component_0);
    ::crclj::java::awt::Component getNextFocusableComponent();
    void setRequestFocusEnabled(jboolean boolean_0);
    jboolean isRequestFocusEnabled();
    void grabFocus();
    void setVerifyInputWhenFocusTarget(jboolean boolean_0);
    jboolean getVerifyInputWhenFocusTarget();
    void setAlignmentY(jfloat float_0);
    void setAlignmentX(jfloat float_0);
    void setDebugGraphicsOptions(jint int_0);
    jint getDebugGraphicsOptions();
    void resetKeyboardActions();
    jboolean requestDefaultFocus();
    void setToolTipText(jstring string_0);
    void setToolTipText(const char * easyArg_0);
    jstring getToolTipText();
    void setAutoscrolls(jboolean boolean_0);
    jboolean getAutoscrolls();
     ::crclj::java::lang::Object getClientProperty(::crclj::java::lang::Object  &object_0);
     void putClientProperty(::crclj::java::lang::Object  &object_0,::crclj::java::lang::Object  &object_1);
    static jboolean isLightweightComponent(::crclj::java::awt::Component  &component_0);
    ::crclj::java::awt::Container getTopLevelAncestor();
    jboolean isOptimizedDrawingEnabled();
    void paintImmediately(jint int_0,jint int_1,jint int_2,jint int_3);
    void setEnabled(jboolean boolean_0);
    jboolean isDoubleBuffered();
    jint getBaseline(jint int_0,jint int_1);
    void revalidate();
    jboolean requestFocusInWindow();
    void updateUI();
    jstring getUIClassID();
    void setDoubleBuffered(jboolean boolean_0);
    void addNotify();
    void removeNotify();
    void reshape(jint int_0,jint int_1,jint int_2,jint int_3);
    void hide();
    jboolean isValidateRoot();
    jint getX();
    jint getY();
    jboolean requestFocus(jboolean boolean_0);
    void requestFocus();
    jint getWidth();
    jint getHeight();
    jfloat getAlignmentX();
    jfloat getAlignmentY();
    void repaint(jlong long_0,jint int_1,jint int_2,jint int_3,jint int_4);
    void setOpaque(jboolean boolean_0);
    void firePropertyChange(jstring string_0,jchar char_1,jchar char_2);
    void firePropertyChange(const char * easyArg_0,jchar easyArg_1,jchar easyArg_2);
    void firePropertyChange(jstring string_0,jboolean boolean_1,jboolean boolean_2);
    void firePropertyChange(const char * easyArg_0,jboolean easyArg_1,jboolean easyArg_2);
    void firePropertyChange(jstring string_0,jint int_1,jint int_2);
    void firePropertyChange(const char * easyArg_0,jint easyArg_1,jint easyArg_2);
    void setVisible(jboolean boolean_0);
    jboolean contains(jint int_0,jint int_1);
    jboolean isOpaque();
    void enable();
    void disable();
   }; // end class JComponent

   
   class JPanel : public JComponent {
       public:
           JPanel(jobject _jthis, bool copy);
           JPanel(const JPanel &);
           
    JPanel(jboolean boolean_0);
    JPanel();
    ~JPanel();
    void updateUI();
    jstring getUIClassID();
   }; // end class JPanel
  } // end namespace swing
 } // end namespace javax


 namespace crcl{
  namespace utils{
   
   class OverHeadJPanel : public ::crclj::javax::swing::JPanel {
       public:
           OverHeadJPanel(jobject _jthis, bool copy);
           OverHeadJPanel(const OverHeadJPanel &);
           
    OverHeadJPanel();
    ~OverHeadJPanel();
    jdoubleArray getJointvals();
    void setJointvals(jdoubleArray doubleArray_0);
    void setJointvals(jdouble * easyArg_0,jsize easyArg_0_length);
    void setSeglengths(jdoubleArray doubleArray_0);
    void setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length);
   }; // end class OverHeadJPanel
  } // end namespace utils


  namespace base{
   
   class CloseToolChangerType : public MiddleCommandType {
       public:
           CloseToolChangerType(jobject _jthis, bool copy);
           CloseToolChangerType(const CloseToolChangerType &);
           
    CloseToolChangerType();
    ~CloseToolChangerType();
   }; // end class CloseToolChangerType

   
   class ParameterSettingType : public DataThingType {
       public:
           ParameterSettingType(jobject _jthis, bool copy);
           ParameterSettingType(const ParameterSettingType &);
           
    ParameterSettingType();
    ~ParameterSettingType();
    jstring getParameterName();
    void setParameterName(jstring string_0);
    void setParameterName(const char * easyArg_0);
    jstring getParameterValue();
    void setParameterValue(jstring string_0);
    void setParameterValue(const char * easyArg_0);
   }; // end class ParameterSettingType

   
   class CRCLStatusType : public DataThingType {
       public:
           CRCLStatusType(jobject _jthis, bool copy);
           CRCLStatusType(const CRCLStatusType &);
           
    CRCLStatusType();
    ~CRCLStatusType();
    JointStatusesType getJointStatuses();
    CommandStatusType getCommandStatus();
    PoseType getPose();
    void setCommandStatus(CommandStatusType  &commandStatusType_0);
    void setJointStatuses(JointStatusesType  &jointStatusesType_0);
    void setPose(PoseType  &poseType_0);
    GripperStatusType getGripperStatus();
    void setGripperStatus(GripperStatusType  &gripperStatusType_0);
   }; // end class CRCLStatusType

   
   class MoveScrewType : public MiddleCommandType {
       public:
           MoveScrewType(jobject _jthis, bool copy);
           MoveScrewType(const MoveScrewType &);
           
    MoveScrewType();
    ~MoveScrewType();
    PoseType getStartPosition();
    void setStartPosition(PoseType  &poseType_0);
    PointType getAxisPoint();
    void setAxisPoint(PointType  &pointType_0);
    ::crclj::java::math::BigDecimal getAxialDistanceFree();
    void setAxialDistanceFree(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getAxialDistanceScrew();
    void setAxialDistanceScrew(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getTurn();
    void setTurn(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class MoveScrewType

   
   class MoveToType : public MiddleCommandType {
       public:
           MoveToType(jobject _jthis, bool copy);
           MoveToType(const MoveToType &);
           
    MoveToType();
    ~MoveToType();
    jboolean isMoveStraight();
    void setMoveStraight(jboolean boolean_0);
    PoseType getEndPosition();
    void setEndPosition(PoseType  &poseType_0);
   }; // end class MoveToType

   
   class ObjectFactory : public ::crclj::java::lang::Object {
       public:
           ObjectFactory(jobject _jthis, bool copy);
           ObjectFactory(const ObjectFactory &);
           
    ObjectFactory();
    ~ObjectFactory();
    ::crclj::javax::xml::bind::JAXBElement createCRCLStatus(CRCLStatusType  &cRCLStatusType_0);
    ::crclj::javax::xml::bind::JAXBElement createCRCLCommandInstance(CRCLCommandInstanceType  &cRCLCommandInstanceType_0);
    ::crclj::javax::xml::bind::JAXBElement createCRCLProgram(CRCLProgramType  &cRCLProgramType_0);
    CRCLProgramType createCRCLProgramType();
    CRCLCommandInstanceType createCRCLCommandInstanceType();
    CRCLStatusType createCRCLStatusType();
    PointType createPointType();
    PoseType createPoseType();
    VectorType createVectorType();
    ActuateJointsType createActuateJointsType();
    ActuateJointType createActuateJointType();
    CloseToolChangerType createCloseToolChangerType();
    DwellType createDwellType();
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
   }; // end class ObjectFactory

   
   class PoseType : public DataThingType {
       public:
           PoseType(jobject _jthis, bool copy);
           PoseType(const PoseType &);
           
    PoseType();
    ~PoseType();
    PointType getPoint();
    VectorType getXAxis();
    VectorType getZAxis();
    void setPoint(PointType  &pointType_0);
    void setXAxis(VectorType  &vectorType_0);
    void setZAxis(VectorType  &vectorType_0);
   }; // end class PoseType

   
   class PoseAndSetType : public PoseType {
       public:
           PoseAndSetType(jobject _jthis, bool copy);
           PoseAndSetType(const PoseAndSetType &);
           
    PoseAndSetType();
    ~PoseAndSetType();
    void setTolerance(PoseToleranceType  &poseToleranceType_0);
    PoseToleranceType getTolerance();
    jboolean isCoordinated();
    void setCoordinated(jboolean boolean_0);
    TransSpeedType getTransSpeed();
    void setTransSpeed(TransSpeedType  &transSpeedType_0);
    RotSpeedType getRotSpeed();
    void setRotSpeed(RotSpeedType  &rotSpeedType_0);
    TransAccelType getTransAccel();
    void setTransAccel(TransAccelType  &transAccelType_0);
    RotAccelType getRotAccel();
    void setRotAccel(RotAccelType  &rotAccelType_0);
   }; // end class PoseAndSetType

   
   class TransAccelType : public DataThingType {
       public:
           TransAccelType(jobject _jthis, bool copy);
           TransAccelType(const TransAccelType &);
           
    TransAccelType();
    ~TransAccelType();
   }; // end class TransAccelType

   
   class TransAccelRelativeType : public TransAccelType {
       public:
           TransAccelRelativeType(jobject _jthis, bool copy);
           TransAccelRelativeType(const TransAccelRelativeType &);
           
    TransAccelRelativeType();
    ~TransAccelRelativeType();
    void setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFraction();
   }; // end class TransAccelRelativeType

   
   class DwellType : public MiddleCommandType {
       public:
           DwellType(jobject _jthis, bool copy);
           DwellType(const DwellType &);
           
    DwellType();
    ~DwellType();
    ::crclj::java::math::BigDecimal getDwellTime();
    void setDwellTime(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class DwellType

   
   class SetLengthUnitsType : public MiddleCommandType {
       public:
           SetLengthUnitsType(jobject _jthis, bool copy);
           SetLengthUnitsType(const SetLengthUnitsType &);
           
    SetLengthUnitsType();
    ~SetLengthUnitsType();
   }; // end class SetLengthUnitsType

   
   class OpenToolChangerType : public MiddleCommandType {
       public:
           OpenToolChangerType(jobject _jthis, bool copy);
           OpenToolChangerType(const OpenToolChangerType &);
           
    OpenToolChangerType();
    ~OpenToolChangerType();
   }; // end class OpenToolChangerType

   
   class SetTransAccelType : public MiddleCommandType {
       public:
           SetTransAccelType(jobject _jthis, bool copy);
           SetTransAccelType(const SetTransAccelType &);
           
    SetTransAccelType();
    ~SetTransAccelType();
    TransAccelType getTransAccel();
    void setTransAccel(TransAccelType  &transAccelType_0);
   }; // end class SetTransAccelType

   
   class JointForceTorqueType : public JointDetailsType {
       public:
           JointForceTorqueType(jobject _jthis, bool copy);
           JointForceTorqueType(const JointForceTorqueType &);
           
    JointForceTorqueType();
    ~JointForceTorqueType();
    ::crclj::java::math::BigDecimal getSetting();
    void setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getChangeRate();
    void setChangeRate(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class JointForceTorqueType

   
   class PointType : public DataThingType {
       public:
           PointType(jobject _jthis, bool copy);
           PointType(const PointType &);
           
    PointType();
    ~PointType();
    ::crclj::java::math::BigDecimal getX();
    ::crclj::java::math::BigDecimal getY();
    void setX(::crclj::java::math::BigDecimal  &bigDecimal_0);
    void setY(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getZ();
    void setZ(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class PointType
  } // end namespace base


  namespace utils{
   
   class CRCLPosemath : public ::crclj::java::lang::Object {
       public:
           CRCLPosemath(jobject _jthis, bool copy);
           CRCLPosemath(const CRCLPosemath &);
           
    protected:
    CRCLPosemath();
    public:
    ~CRCLPosemath();
    static ::crclj::crcl::base::PointType subtract(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1);
    static ::crclj::crcl::base::PointType multiply(::crclj::java::math::BigDecimal  &bigDecimal_0,::crclj::crcl::base::PointType  &pointType_1);
    static ::crclj::crcl::base::PointType multiply(::crclj::java::math::BigDecimal  &bigDecimal_0,::crclj::crcl::base::VectorType  &vectorType_1);
    static ::crclj::crcl::base::PointType multiply(jdouble double_0,::crclj::crcl::base::VectorType  &vectorType_1);
    static ::crclj::crcl::base::PoseType multiply(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1);
    static ::crclj::crcl::base::PointType multiply(jdouble double_0,::crclj::crcl::base::PointType  &pointType_1);
    static ::crclj::java::math::BigDecimal dot(::crclj::crcl::base::VectorType  &vectorType_0,::crclj::crcl::base::VectorType  &vectorType_1);
    static ::crclj::java::math::BigDecimal dot(::crclj::crcl::base::VectorType  &vectorType_0,::crclj::crcl::base::PointType  &pointType_1);
    static jdouble norm(::crclj::crcl::base::VectorType  &vectorType_0);
    static ::crclj::crcl::base::PoseType invert(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D toCommonsVector3D(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D toCommonsVector3D(::crclj::crcl::base::PointType  &pointType_0);
    static ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D toCommonsVector3D(::crclj::crcl::base::VectorType  &vectorType_0);
    static ::crclj::crcl::base::VectorType toCRCLUnitVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0,::crclj::crcl::base::VectorType  &vectorType_1);
    static ::crclj::crcl::base::VectorType toCRCLUnitVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0);
    static ::crclj::org::apache::commons::math3::geometry::euclidean::threed::Rotation toCommonsRotation(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::crcl::base::PointType toCRCLPoint(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0);
    static ::crclj::crcl::base::PointType toCRCLPoint(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0,::crclj::crcl::base::PointType  &pointType_1);
    static ::crclj::rcs::posemath::PmCartesian pointToPmCartesian(::crclj::crcl::base::PointType  &pointType_0);
    static ::crclj::crcl::base::PoseType identityPose();
    static jstring poseToString(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::rcs::posemath::PmPose toPmPose(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::crcl::base::VectorType cross(::crclj::crcl::base::VectorType  &vectorType_0,::crclj::crcl::base::VectorType  &vectorType_1);
    static ::crclj::crcl::base::PoseType pointXAxisZAxisToPose(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::VectorType  &vectorType_1,::crclj::crcl::base::VectorType  &vectorType_2);
    static jdouble diffPoints(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1);
    static jdouble diffPosesTran(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1);
    static ::crclj::rcs::posemath::PmCartesian vectorToPmCartesian(::crclj::crcl::base::VectorType  &vectorType_0);
    static ::crclj::crcl::base::PoseType toPoseType(::crclj::rcs::posemath::PmCartesian  &pmCartesian_0,::crclj::rcs::posemath::PmRotationVector  &pmRotationVector_1,::crclj::crcl::base::PoseType  &poseType_2);
    static ::crclj::crcl::base::PoseType toPoseType(::crclj::rcs::posemath::PmCartesian  &pmCartesian_0,::crclj::rcs::posemath::PmRotationVector  &pmRotationVector_1);
    static ::crclj::rcs::posemath::PmRotationMatrix toPmRotationMatrix(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::rcs::posemath::PmRotationVector toPmRotationVector(::crclj::crcl::base::PoseType  &poseType_0);
    static ::crclj::rcs::posemath::PmRpy toPmRpy(::crclj::crcl::base::PoseType  &poseType_0);
    static jdouble maxDiffDoubleArray(jdoubleArray doubleArray_0,jdoubleArray doubleArray_1);
    static jdouble diffPosesRot(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1);
    static ::crclj::crcl::base::PointType toPointType(::crclj::rcs::posemath::PmCartesian  &pmCartesian_0);
    static ::crclj::crcl::base::VectorType toCRCLVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0);
    static ::crclj::crcl::base::VectorType toCRCLVector(::crclj::org::apache::commons::math3::geometry::euclidean::threed::Vector3D  &vector3D_0,::crclj::crcl::base::VectorType  &vectorType_1);
    static ::crclj::crcl::base::PointType add(::crclj::crcl::base::PointType  &pointType_0,::crclj::crcl::base::PointType  &pointType_1);
    static ::crclj::crcl::base::VectorType normalize(::crclj::crcl::base::VectorType  &vectorType_0);
    static ::crclj::crcl::base::PoseType shift(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PointType  &pointType_1);
   }; // end class CRCLPosemath

   
   class XpathUtils : public ::crclj::java::lang::Object {
       public:
           XpathUtils(jobject _jthis, bool copy);
           XpathUtils(const XpathUtils &);
           
    protected:
    XpathUtils();
    public:
    ~XpathUtils();
    jobjectArray getSchemaFiles();
    void setSchemaFiles(jobjectArray fileArray_0);
    jstring getDocumentation(jstring string_0);
    jstring getDocumentation(const char * easyArg_0);
     jstring nodeToString(::crclj::org::w3c::dom::Node  &node_0);
    jstring queryXml(::crclj::java::io::File  &file_0,jstring string_1);
    jstring queryXml(::crclj::java::io::File easyArg_0,const char * easyArg_1);
    jstring queryXml(jobjectArray fileArray_0,jstring string_1);
    jstring nodeListToString(::crclj::org::w3c::dom::NodeList  &nodeList_0);
    jstring queryXmlString(jstring string_0,jstring string_1);
    jstring queryXmlString(const char * easyArg_0,const char * easyArg_1);
   }; // end class XpathUtils

   
   class ListChooserJPanel : public ::crclj::javax::swing::JPanel {
       public:
           ListChooserJPanel(jobject _jthis, bool copy);
           ListChooserJPanel(const ListChooserJPanel &);
           
    protected:
    ListChooserJPanel();
    public:
    ~ListChooserJPanel();
    ::crclj::java::lang::Object getSelectedChoice();
    static ::crclj::java::lang::Object Choose(::crclj::java::awt::Frame  &frame_0,jstring string_1,jobjectArray objectArray_2,::crclj::java::lang::Object  &object_3);
   }; // end class ListChooserJPanel
  } // end namespace utils
 } // end namespace crcl


 namespace java{
  namespace awt{
   
   class Window : public Container {
       public:
           Window(jobject _jthis, bool copy);
           Window(const Window &);
           
    protected:
    Window();
    public:
    ~Window();
    void addNotify();
    void setOpacity(jfloat float_0);
    void removeNotify();
    jfloat getOpacity();
    static jobjectArray getWindows();
    ::crclj::java::util::List getIconImages();
    void setIconImages(::crclj::java::util::List  &list_0);
    void setLocation(jint int_0,jint int_1);
    void reshape(jint int_0,jint int_1,jint int_2,jint int_3);
    void show();
    void hide();
    void toFront();
    void toBack();
     jstring getWarningString();
    jobjectArray getOwnedWindows();
    static jobjectArray getOwnerlessWindows();
     void setAlwaysOnTop(jboolean boolean_0);
    jboolean isAlwaysOnTopSupported();
     jboolean isAlwaysOnTop();
    Component getFocusOwner();
    Component getMostRecentFocusOwner();
    jboolean isActive();
    jboolean isFocused();
     void setFocusCycleRoot(jboolean boolean_0);
     jboolean isFocusCycleRoot();
     Container getFocusCycleRootAncestor();
     jboolean isFocusableWindow();
    jboolean getFocusableWindowState();
    void setFocusableWindowState(jboolean boolean_0);
    void setAutoRequestFocus(jboolean boolean_0);
    jboolean isAutoRequestFocus();
    jboolean isValidateRoot();
    jboolean isShowing();
    void applyResourceBundle(jstring string_0);
    void applyResourceBundle(const char * easyArg_0);
    void setLocationRelativeTo(Component  &component_0);
    void createBufferStrategy(jint int_0);
    void setLocationByPlatform(jboolean boolean_0);
    jboolean isLocationByPlatform();
    void setBounds(jint int_0,jint int_1,jint int_2,jint int_3);
    void dispose();
    void pack();
    void setVisible(jboolean boolean_0);
    jboolean isOpaque();
    void setSize(jint int_0,jint int_1);
    Window getOwner();
   }; // end class Window

   
   class Frame : public Window {
       public:
           Frame(jobject _jthis, bool copy);
           Frame(const Frame &);
           
    Frame(jstring string_0);
    Frame(const char * easyArg_0);
    Frame();
    ~Frame();
    void addNotify();
    jstring getTitle();
    jboolean isResizable();
    void setResizable(jboolean boolean_0);
    void setState(jint int_0);
    void setExtendedState(jint int_0);
    jint getExtendedState();
    jboolean isUndecorated();
    void setOpacity(jfloat float_0);
    void removeNotify();
    void setCursor(jint int_0);
    jint getCursorType();
    static jobjectArray getFrames();
    void setUndecorated(jboolean boolean_0);
    void setTitle(jstring string_0);
    void setTitle(const char * easyArg_0);
    jint getState();
   }; // end class Frame
  } // end namespace awt
 } // end namespace java


 namespace javax{
  namespace swing{
   
   class JFrame : public ::crclj::java::awt::Frame {
       public:
           JFrame(jobject _jthis, bool copy);
           JFrame(const JFrame &);
           
    JFrame();
    JFrame(jstring string_0);
    JFrame(const char * easyArg_0);
    ~JFrame();
    jint getDefaultCloseOperation();
    void setContentPane(::crclj::java::awt::Container  &container_0);
    ::crclj::java::awt::Component getGlassPane();
    void setGlassPane(::crclj::java::awt::Component  &component_0);
    void repaint(jlong long_0,jint int_1,jint int_2,jint int_3,jint int_4);
    static void setDefaultLookAndFeelDecorated(jboolean boolean_0);
    static jboolean isDefaultLookAndFeelDecorated();
    ::crclj::java::awt::Container getContentPane();
    void setDefaultCloseOperation(jint int_0);
    void remove(::crclj::java::awt::Component  &component_0);
   }; // end class JFrame
  } // end namespace swing
 } // end namespace javax


 namespace crcl{
  namespace utils{
   
   class LauncherJFrame : public ::crclj::javax::swing::JFrame {
       public:
           LauncherJFrame(jobject _jthis, bool copy);
           LauncherJFrame(const LauncherJFrame &);
           
    LauncherJFrame();
    ~LauncherJFrame();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class LauncherJFrame

   
   class SimulatedKinematicsPlausible : public ::crclj::java::lang::Object {
       public:
           SimulatedKinematicsPlausible(jobject _jthis, bool copy);
           SimulatedKinematicsPlausible(const SimulatedKinematicsPlausible &);
           
    SimulatedKinematicsPlausible();
    ~SimulatedKinematicsPlausible();
    jdouble getScale();
    void setScale(jdouble double_0);
    void setSeglengths(jdoubleArray doubleArray_0);
    void setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length);
    ::crclj::crcl::base::PoseType jointsToPose(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1);
    ::crclj::crcl::base::PoseType jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1);
    ::crclj::crcl::base::PoseType jointsToPose(jdoubleArray doubleArray_0);
    ::crclj::crcl::base::PoseType jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length);
    jdoubleArray getSeglengths();
    jdoubleArray poseToJoints(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1);
    jdoubleArray poseToJoints(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1);
   }; // end class SimulatedKinematicsPlausible

   
   class GripperJFrame : public ::crclj::javax::swing::JFrame {
       public:
           GripperJFrame(jobject _jthis, bool copy);
           GripperJFrame(const GripperJFrame &);
           
    GripperJFrame();
    ~GripperJFrame();
    void setPort(jint int_0);
    jint getDelayMillis();
    void setDelayMillis(jint int_0);
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
    jint getPort();
   }; // end class GripperJFrame
  } // end namespace utils


  namespace base{
   
   class RotAccelType : public DataThingType {
       public:
           RotAccelType(jobject _jthis, bool copy);
           RotAccelType(const RotAccelType &);
           
    RotAccelType();
    ~RotAccelType();
   }; // end class RotAccelType

   
   class ActuateJointsType : public MiddleCommandType {
       public:
           ActuateJointsType(jobject _jthis, bool copy);
           ActuateJointsType(const ActuateJointsType &);
           
    ActuateJointsType();
    ~ActuateJointsType();
    ::crclj::java::util::List getActuateJoint();
   }; // end class ActuateJointsType

   
   class MessageType : public MiddleCommandType {
       public:
           MessageType(jobject _jthis, bool copy);
           MessageType(const MessageType &);
           
    MessageType();
    ~MessageType();
    void setMessage(jstring string_0);
    void setMessage(const char * easyArg_0);
    jstring getMessage();
   }; // end class MessageType

   
   class TransAccelAbsoluteType : public TransAccelType {
       public:
           TransAccelAbsoluteType(jobject _jthis, bool copy);
           TransAccelAbsoluteType(const TransAccelAbsoluteType &);
           
    TransAccelAbsoluteType();
    ~TransAccelAbsoluteType();
    ::crclj::java::math::BigDecimal getSetting();
    void setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class TransAccelAbsoluteType

   
   class TransSpeedType : public DataThingType {
       public:
           TransSpeedType(jobject _jthis, bool copy);
           TransSpeedType(const TransSpeedType &);
           
    TransSpeedType();
    ~TransSpeedType();
   }; // end class TransSpeedType

   
   class TransSpeedRelativeType : public TransSpeedType {
       public:
           TransSpeedRelativeType(jobject _jthis, bool copy);
           TransSpeedRelativeType(const TransSpeedRelativeType &);
           
    TransSpeedRelativeType();
    ~TransSpeedRelativeType();
    void setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFraction();
   }; // end class TransSpeedRelativeType

   
   class RunProgramType : public MiddleCommandType {
       public:
           RunProgramType(jobject _jthis, bool copy);
           RunProgramType(const RunProgramType &);
           
    RunProgramType();
    ~RunProgramType();
    jstring getProgramText();
    void setProgramText(jstring string_0);
    void setProgramText(const char * easyArg_0);
   }; // end class RunProgramType
  } // end namespace base


  namespace utils{
   
   class PerfTest : public ::crclj::java::lang::Object {
       public:
           PerfTest(jobject _jthis, bool copy);
           PerfTest(const PerfTest &);
           
    PerfTest();
    ~PerfTest();
    static void runPerfTest(jboolean boolean_0);
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class PerfTest
  } // end namespace utils


  namespace base{
   
   class RotSpeedType : public DataThingType {
       public:
           RotSpeedType(jobject _jthis, bool copy);
           RotSpeedType(const RotSpeedType &);
           
    RotSpeedType();
    ~RotSpeedType();
   }; // end class RotSpeedType

   
   class GripperStatusType : public DataThingType {
       public:
           GripperStatusType(jobject _jthis, bool copy);
           GripperStatusType(const GripperStatusType &);
           
    GripperStatusType();
    ~GripperStatusType();
    jstring getGripperName();
    void setGripperName(jstring string_0);
    void setGripperName(const char * easyArg_0);
   }; // end class GripperStatusType

   
   class SetTransSpeedType : public MiddleCommandType {
       public:
           SetTransSpeedType(jobject _jthis, bool copy);
           SetTransSpeedType(const SetTransSpeedType &);
           
    SetTransSpeedType();
    ~SetTransSpeedType();
    TransSpeedType getTransSpeed();
    void setTransSpeed(TransSpeedType  &transSpeedType_0);
   }; // end class SetTransSpeedType

   
   class SetForceUnitsType : public MiddleCommandType {
       public:
           SetForceUnitsType(jobject _jthis, bool copy);
           SetForceUnitsType(const SetForceUnitsType &);
           
    SetForceUnitsType();
    ~SetForceUnitsType();
   }; // end class SetForceUnitsType

   
   class RotAccelRelativeType : public RotAccelType {
       public:
           RotAccelRelativeType(jobject _jthis, bool copy);
           RotAccelRelativeType(const RotAccelRelativeType &);
           
    RotAccelRelativeType();
    ~RotAccelRelativeType();
    void setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFraction();
   }; // end class RotAccelRelativeType
  } // end namespace base


  namespace utils{
   
   class SimServerOuterStub : public ::crclj::java::lang::Object {
       public:
           SimServerOuterStub(jobject _jthis, bool copy);
           SimServerOuterStub(const SimServerOuterStub &);
           
    SimServerOuterStub();
    SimServerOuterStub(jboolean boolean_0,jboolean boolean_1,jboolean boolean_2,jboolean boolean_3,jboolean boolean_4,jboolean boolean_5,jboolean boolean_6,jboolean boolean_7,jboolean boolean_8,jboolean boolean_9);
    ~SimServerOuterStub();
    void showMessage(jstring string_0);
    void showMessage(const char * easyArg_0);
    void showDebugMessage(jstring string_0);
    void showDebugMessage(const char * easyArg_0);
    jboolean isEXISelected();
    void updateConnectedClients(jint int_0);
    jboolean isValidateXMLSelected();
    jboolean isSendStatusWithoutRequestSelected();
    jboolean isAppendZeroSelected();
    jboolean isRandomPacketSelected();
    jboolean isReplaceStateSelected();
    jboolean isEditingStatus();
    void updateCycleCount(jint int_0);
    void updatePanels(jboolean boolean_0);
    void updateIsInitialized(jboolean boolean_0);
    void updateCurrentCommandType(jstring string_0);
    void updateCurrentCommandType(const char * easyArg_0);
    void updateEndEffector(jstring string_0);
    void updateEndEffector(const char * easyArg_0);
    void updateToolChangerIsOpen(jboolean boolean_0);
    jboolean isInitializedSelected();
    void finishSetCurrentWaypoint(jint int_0);
    void updateNumWaypoints(jint int_0);
    jboolean isDebugMoveDoneSelected();
    jboolean isDebugSendStatusSelected();
    jboolean isDebugReadCommandSelected();
    jboolean isReplaceXmlHeaderSelected();
   }; // end class SimServerOuterStub

   
   class SimServerOuter : public ::crclj::java::lang::Object {
       public:
           SimServerOuter(jobject _jthis, bool copy);
           SimServerOuter(const SimServerOuter &);
           
    SimServerOuter();
    ~SimServerOuter();
    void showMessage(jstring string_0);
    void showMessage(const char * easyArg_0);
    void showDebugMessage(jstring string_0);
    void showDebugMessage(const char * easyArg_0);
    jboolean isEXISelected();
    void updateConnectedClients(jint int_0);
    jboolean isValidateXMLSelected();
    jboolean isSendStatusWithoutRequestSelected();
    jboolean isAppendZeroSelected();
    jboolean isRandomPacketSelected();
    jboolean isReplaceStateSelected();
    jboolean isEditingStatus();
    void updateCycleCount(jint int_0);
    void updatePanels(jboolean boolean_0);
    void updateIsInitialized(jboolean boolean_0);
    void updateCurrentCommandType(jstring string_0);
    void updateCurrentCommandType(const char * easyArg_0);
    void updateEndEffector(jstring string_0);
    void updateEndEffector(const char * easyArg_0);
    void updateToolChangerIsOpen(jboolean boolean_0);
    jboolean isInitializedSelected();
    void finishSetCurrentWaypoint(jint int_0);
    void updateNumWaypoints(jint int_0);
    jboolean isDebugMoveDoneSelected();
    jboolean isDebugSendStatusSelected();
    jboolean isDebugReadCommandSelected();
    jboolean isReplaceXmlHeaderSelected();
   }; // end class SimServerOuter

   
   class SimServerInner : public ::crclj::java::lang::Object {
       public:
           SimServerInner(jobject _jthis, bool copy);
           SimServerInner(const SimServerInner &);
           
    protected:
    SimServerInner();
    public:
    SimServerInner(SimServerOuter  &simServerOuter_0);
    ~SimServerInner();
    ::crclj::crcl::base::CRCLStatusType getStatus();
    void setCmdSchema(jobjectArray fileArray_0);
    void setStatSchema(jobjectArray fileArray_0);
    jboolean isMoveStraight();
    void setMoveStraight(jboolean boolean_0);
    void setJointPosition(jdouble double_0,jint int_1);
    jdoubleArray getSeglengths();
    void setPort(jint int_0);
    jlong getDelayMillis();
    void setDelayMillis(jlong long_0);
    void restartServer();
    void updateConnectedClients();
    XpathUtils getXpu();
    void simulatedTeleportToPose(::crclj::crcl::base::PoseType  &poseType_0);
    void setCommandedJointPosition(jdouble double_0,jint int_1);
    jdoubleArray getJointPositions();
    void setGoalPose(::crclj::crcl::base::PoseType  &poseType_0);
    jboolean isFinishedMove();
    jboolean checkPose(::crclj::crcl::base::PoseType  &poseType_0);
    jdouble getJointSpeedMax();
    void setJointSpeedMax(jdouble double_0);
    ::crclj::crcl::base::PoseType limitSpeedAccel(::crclj::crcl::base::PoseType  &poseType_0,::crclj::crcl::base::PoseType  &poseType_1);
    jdoubleArray getStraightMoveCommandedJointVals(::crclj::crcl::base::PoseType  &poseType_0);
    void setStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0);
    void closeServer();
    ::crclj::javax::xml::datatype::XMLGregorianCalendar getXMLGregorianCalendarNow();
    void goalPoseToCommandedPositions(::crclj::crcl::base::PoseType  &poseType_0);
    jint getCurrentWaypoint();
    void setCurrentWaypoint(jint int_0);
    void printClientStates(::crclj::java::io::PrintStream  &printStream_0);
    static void printAllClientStates(::crclj::java::io::PrintStream  &printStream_0);
    void runAcceptClients();
    jdouble getCurTransSpeed();
    void setCurTransSpeed(jdouble double_0);
    jdouble getCommandedTransSpeed();
    void setCommandedTransSpeed(jdouble double_0);
    jdouble getCurTransAccel();
    void setCurTransAccel(jdouble double_0);
    jdouble getCommandedTransAccel();
    void setCommandedTransAccel(jdouble double_0);
    jdouble getCurRotSpeed();
    void setCurRotSpeed(jdouble double_0);
    jdouble getCommandedRotSpeed();
    void setCommandedRotSpeed(jdouble double_0);
    jdouble getCurRotAccel();
    void setCurRotAccel(jdouble double_0);
    jdouble getCommandedRotAccel();
    void setCommandedRotAccel(jdouble double_0);
    ::crclj::crcl::base::PoseToleranceType getExpectedEndPoseTolerance();
    void setExpectedEndPoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0);
    ::crclj::crcl::base::PoseToleranceType getExpectedIntermediatePoseTolerance();
    void setExpectedIntermediatePoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0);
    ::crclj::java::util::List getWaypoints();
    void setWaypoints(::crclj::java::util::List  &list_0);
    jstring getStatusXmlString();
    CRCLSocket getCheckerCRCLSocket();
    void reset();
    jint getPort();
   }; // end class SimServerInner

   
   class MultiLineStringJPanel : public ::crclj::javax::swing::JPanel {
       public:
           MultiLineStringJPanel(jobject _jthis, bool copy);
           MultiLineStringJPanel(const MultiLineStringJPanel &);
           
    MultiLineStringJPanel();
    ~MultiLineStringJPanel();
    static jstring editText(jstring string_0);
    static jstring editText(jstring string_0,::crclj::java::awt::Frame  &frame_1,jstring string_2,jboolean boolean_3);
    static jboolean showText(jstring string_0);
    static jboolean showText(jstring string_0,::crclj::java::awt::Frame  &frame_1,jstring string_2,jboolean boolean_3);
   }; // end class MultiLineStringJPanel

   
   class ObjTableJPanel : public ::crclj::javax::swing::JPanel {
       public:
           ObjTableJPanel(jobject _jthis, bool copy);
           ObjTableJPanel(const ObjTableJPanel &);
           
    ObjTableJPanel();
    ~ObjTableJPanel();
    ::crclj::java::lang::Object getObj();
    void setObj(::crclj::java::lang::Object  &object_0);
    static ::crclj::java::lang::Object editObject(::crclj::java::lang::Object  &object_0,XpathUtils  &xpathUtils_1,::crclj::java::util::function::Predicate  &predicate_2);
    static ::crclj::java::lang::Object editObject(::crclj::java::lang::Object  &object_0,::crclj::java::awt::Frame  &frame_1,jstring string_2,jboolean boolean_3,XpathUtils  &xpathUtils_4,::crclj::java::util::function::Predicate  &predicate_5);
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
    static ::crclj::java::util::List getClasses();
   }; // end class ObjTableJPanel
  } // end namespace utils


  namespace base{
   
   class CRCLProgramType : public DataThingType {
       public:
           CRCLProgramType(jobject _jthis, bool copy);
           CRCLProgramType(const CRCLProgramType &);
           
    CRCLProgramType();
    ~CRCLProgramType();
    InitCanonType getInitCanon();
    void setInitCanon(InitCanonType  &initCanonType_0);
    ::crclj::java::util::List getMiddleCommand();
    EndCanonType getEndCanon();
    void setEndCanon(EndCanonType  &endCanonType_0);
   }; // end class CRCLProgramType

   
   class VectorType : public DataThingType {
       public:
           VectorType(jobject _jthis, bool copy);
           VectorType(const VectorType &);
           
    VectorType();
    ~VectorType();
    ::crclj::java::math::BigDecimal getK();
    ::crclj::java::math::BigDecimal getI();
    ::crclj::java::math::BigDecimal getJ();
    void setI(::crclj::java::math::BigDecimal  &bigDecimal_0);
    void setJ(::crclj::java::math::BigDecimal  &bigDecimal_0);
    void setK(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class VectorType

   
   class SetEndEffectorType : public MiddleCommandType {
       public:
           SetEndEffectorType(jobject _jthis, bool copy);
           SetEndEffectorType(const SetEndEffectorType &);
           
    SetEndEffectorType();
    ~SetEndEffectorType();
    ::crclj::java::math::BigDecimal getSetting();
    void setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class SetEndEffectorType

   
   class SetTorqueUnitsType : public MiddleCommandType {
       public:
           SetTorqueUnitsType(jobject _jthis, bool copy);
           SetTorqueUnitsType(const SetTorqueUnitsType &);
           
    SetTorqueUnitsType();
    ~SetTorqueUnitsType();
   }; // end class SetTorqueUnitsType

   
   class ConfigureJointReportType : public DataThingType {
       public:
           ConfigureJointReportType(jobject _jthis, bool copy);
           ConfigureJointReportType(const ConfigureJointReportType &);
           
    ConfigureJointReportType();
    ~ConfigureJointReportType();
    ::crclj::java::math::BigInteger getJointNumber();
    void setJointNumber(::crclj::java::math::BigInteger  &bigInteger_0);
    jboolean isReportPosition();
    void setReportPosition(jboolean boolean_0);
    jboolean isReportTorqueOrForce();
    void setReportTorqueOrForce(jboolean boolean_0);
    jboolean isReportVelocity();
    void setReportVelocity(jboolean boolean_0);
   }; // end class ConfigureJointReportType

   
   class SetRotAccelType : public MiddleCommandType {
       public:
           SetRotAccelType(jobject _jthis, bool copy);
           SetRotAccelType(const SetRotAccelType &);
           
    SetRotAccelType();
    ~SetRotAccelType();
    RotAccelType getRotAccel();
    void setRotAccel(RotAccelType  &rotAccelType_0);
   }; // end class SetRotAccelType

   
   class SetAngleUnitsType : public MiddleCommandType {
       public:
           SetAngleUnitsType(jobject _jthis, bool copy);
           SetAngleUnitsType(const SetAngleUnitsType &);
           
    SetAngleUnitsType();
    ~SetAngleUnitsType();
   }; // end class SetAngleUnitsType

   
   class CommandStatusType : public DataThingType {
       public:
           CommandStatusType(jobject _jthis, bool copy);
           CommandStatusType(const CommandStatusType &);
           
    CommandStatusType();
    ~CommandStatusType();
    ::crclj::java::math::BigInteger getCommandID();
    void setCommandID(::crclj::java::math::BigInteger  &bigInteger_0);
    ::crclj::java::math::BigInteger getStatusID();
    void setStatusID(::crclj::java::math::BigInteger  &bigInteger_0);
   }; // end class CommandStatusType

   
   class RotSpeedRelativeType : public RotSpeedType {
       public:
           RotSpeedRelativeType(jobject _jthis, bool copy);
           RotSpeedRelativeType(const RotSpeedRelativeType &);
           
    RotSpeedRelativeType();
    ~RotSpeedRelativeType();
    void setFraction(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFraction();
   }; // end class RotSpeedRelativeType

   
   class RotAccelAbsoluteType : public RotAccelType {
       public:
           RotAccelAbsoluteType(jobject _jthis, bool copy);
           RotAccelAbsoluteType(const RotAccelAbsoluteType &);
           
    RotAccelAbsoluteType();
    ~RotAccelAbsoluteType();
    ::crclj::java::math::BigDecimal getSetting();
    void setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class RotAccelAbsoluteType

   
   class SetMotionCoordinationType : public MiddleCommandType {
       public:
           SetMotionCoordinationType(jobject _jthis, bool copy);
           SetMotionCoordinationType(const SetMotionCoordinationType &);
           
    SetMotionCoordinationType();
    ~SetMotionCoordinationType();
    jboolean isCoordinated();
    void setCoordinated(jboolean boolean_0);
   }; // end class SetMotionCoordinationType

   
   class ActuateJointType : public DataThingType {
       public:
           ActuateJointType(jobject _jthis, bool copy);
           ActuateJointType(const ActuateJointType &);
           
    ActuateJointType();
    ~ActuateJointType();
    ::crclj::java::math::BigInteger getJointNumber();
    ::crclj::java::math::BigDecimal getJointPosition();
    void setJointNumber(::crclj::java::math::BigInteger  &bigInteger_0);
    void setJointPosition(::crclj::java::math::BigDecimal  &bigDecimal_0);
    JointDetailsType getJointDetails();
    void setJointDetails(JointDetailsType  &jointDetailsType_0);
   }; // end class ActuateJointType

   
   class TransSpeedAbsoluteType : public TransSpeedType {
       public:
           TransSpeedAbsoluteType(jobject _jthis, bool copy);
           TransSpeedAbsoluteType(const TransSpeedAbsoluteType &);
           
    TransSpeedAbsoluteType();
    ~TransSpeedAbsoluteType();
    ::crclj::java::math::BigDecimal getSetting();
    void setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class TransSpeedAbsoluteType

   
   class PoseToleranceType : public DataThingType {
       public:
           PoseToleranceType(jobject _jthis, bool copy);
           PoseToleranceType(const PoseToleranceType &);
           
    PoseToleranceType();
    ~PoseToleranceType();
    ::crclj::java::math::BigDecimal getXPointTolerance();
    void setXPointTolerance(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getYPointTolerance();
    void setYPointTolerance(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getZPointTolerance();
    void setZPointTolerance(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getXAxisTolerance();
    void setXAxisTolerance(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getZAxisTolerance();
    void setZAxisTolerance(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class PoseToleranceType

   
   class StopMotionType : public MiddleCommandType {
       public:
           StopMotionType(jobject _jthis, bool copy);
           StopMotionType(const StopMotionType &);
           
    StopMotionType();
    ~StopMotionType();
   }; // end class StopMotionType

   
   class ConfigureJointReportsType : public MiddleCommandType {
       public:
           ConfigureJointReportsType(jobject _jthis, bool copy);
           ConfigureJointReportsType(const ConfigureJointReportsType &);
           
    ConfigureJointReportsType();
    ~ConfigureJointReportsType();
    jboolean isResetAll();
    void setResetAll(jboolean boolean_0);
    ::crclj::java::util::List getConfigureJointReport();
   }; // end class ConfigureJointReportsType

   
   class CRCLCommandInstanceType : public DataThingType {
       public:
           CRCLCommandInstanceType(jobject _jthis, bool copy);
           CRCLCommandInstanceType(const CRCLCommandInstanceType &);
           
    CRCLCommandInstanceType();
    ~CRCLCommandInstanceType();
    void setCRCLCommand(CRCLCommandType  &cRCLCommandType_0);
    CRCLCommandType getCRCLCommand();
   }; // end class CRCLCommandInstanceType

   
   class SetRotSpeedType : public MiddleCommandType {
       public:
           SetRotSpeedType(jobject _jthis, bool copy);
           SetRotSpeedType(const SetRotSpeedType &);
           
    SetRotSpeedType();
    ~SetRotSpeedType();
    RotSpeedType getRotSpeed();
    void setRotSpeed(RotSpeedType  &rotSpeedType_0);
   }; // end class SetRotSpeedType

   
   class ParallelGripperStatusType : public GripperStatusType {
       public:
           ParallelGripperStatusType(jobject _jthis, bool copy);
           ParallelGripperStatusType(const ParallelGripperStatusType &);
           
    ParallelGripperStatusType();
    ~ParallelGripperStatusType();
    ::crclj::java::math::BigDecimal getSeparation();
    void setSeparation(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class ParallelGripperStatusType

   
   class SetEndEffectorParametersType : public MiddleCommandType {
       public:
           SetEndEffectorParametersType(jobject _jthis, bool copy);
           SetEndEffectorParametersType(const SetEndEffectorParametersType &);
           
    SetEndEffectorParametersType();
    ~SetEndEffectorParametersType();
    ::crclj::java::util::List getParameterSetting();
   }; // end class SetEndEffectorParametersType

   
   class ThreeFingerGripperStatusType : public GripperStatusType {
       public:
           ThreeFingerGripperStatusType(jobject _jthis, bool copy);
           ThreeFingerGripperStatusType(const ThreeFingerGripperStatusType &);
           
    ThreeFingerGripperStatusType();
    ~ThreeFingerGripperStatusType();
    ::crclj::java::math::BigDecimal getFinger1Position();
    void setFinger1Position(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFinger2Position();
    void setFinger2Position(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFinger1Force();
    ::crclj::java::math::BigDecimal getFinger3Position();
    void setFinger3Position(::crclj::java::math::BigDecimal  &bigDecimal_0);
    void setFinger1Force(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFinger2Force();
    void setFinger2Force(::crclj::java::math::BigDecimal  &bigDecimal_0);
    ::crclj::java::math::BigDecimal getFinger3Force();
    void setFinger3Force(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class ThreeFingerGripperStatusType
  } // end namespace base


  namespace utils{
   
   class PendantClientOuter : public ::crclj::java::lang::Object {
       public:
           PendantClientOuter(jobject _jthis, bool copy);
           PendantClientOuter(const PendantClientOuter &);
           
    PendantClientOuter();
    ~PendantClientOuter();
    void finishConnect();
    void showMessage(jstring string_0);
    void showMessage(const char * easyArg_0);
    void showMessage(::crclj::java::lang::Throwable  &throwable_0);
    jboolean showDebugMessage(jstring string_0);
    jboolean showDebugMessage(const char * easyArg_0);
    jboolean validateXmlSelected();
    jboolean replaceStateSelected();
    void finishDisconnect();
    void finishSetStatus();
    void checkXmlQuery(CRCLSocket  &cRCLSocket_0);
    void stopPollTimer();
    void checkPollSelected();
    jboolean isDebugWaitForDoneSelected();
    jboolean isDebugSendCommandSelected();
    jboolean isDebugReadStatusSelected();
    void showCurrentProgramLine(jint int_0);
    void finishOpenXmlProgramFile(::crclj::java::io::File  &file_0,::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_1);
    ::crclj::crcl::base::CRCLProgramType editProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    void showLastProgramLineExecTimeMillisDists(jlong long_0,jdouble double_1);
    jboolean isRecordPoseSelected();
    jboolean isEXISelected();
    jboolean isUseReadStatusThreadSelected();
    jstring getHost();
    jint getPort();
   }; // end class PendantClientOuter

   
   class SideViewJPanel : public ::crclj::javax::swing::JPanel {
       public:
           SideViewJPanel(jobject _jthis, bool copy);
           SideViewJPanel(const SideViewJPanel &);
           
    SideViewJPanel();
    ~SideViewJPanel();
    jdoubleArray getJointvals();
    void setJointvals(jdoubleArray doubleArray_0);
    void setJointvals(jdouble * easyArg_0,jsize easyArg_0_length);
    void setSeglengths(jdoubleArray doubleArray_0);
    void setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length);
    jdoubleArray getSeglengths();
   }; // end class SideViewJPanel

   
   class SimulatedKinematicsSimple : public ::crclj::java::lang::Object {
       public:
           SimulatedKinematicsSimple(jobject _jthis, bool copy);
           SimulatedKinematicsSimple(const SimulatedKinematicsSimple &);
           
    SimulatedKinematicsSimple();
    ~SimulatedKinematicsSimple();
    jdouble getScale();
    void setScale(jdouble double_0);
    void setSeglengths(jdoubleArray doubleArray_0);
    void setSeglengths(jdouble * easyArg_0,jsize easyArg_0_length);
    ::crclj::crcl::base::PoseType jointsToPose(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1);
    ::crclj::crcl::base::PoseType jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1);
    ::crclj::crcl::base::PoseType jointsToPose(jdoubleArray doubleArray_0);
    ::crclj::crcl::base::PoseType jointsToPose(jdouble * easyArg_0,jsize easyArg_0_length);
    jdoubleArray getSeglengths();
    jdoubleArray poseToJoints(jdoubleArray doubleArray_0,::crclj::crcl::base::PoseType  &poseType_1);
    jdoubleArray poseToJoints(jdouble * easyArg_0,jsize easyArg_0_length,::crclj::crcl::base::PoseType easyArg_1);
   }; // end class SimulatedKinematicsSimple

   
   class XpathQueryJFrame : public ::crclj::javax::swing::JFrame {
       public:
           XpathQueryJFrame(jobject _jthis, bool copy);
           XpathQueryJFrame(const XpathQueryJFrame &);
           
    XpathQueryJFrame();
    ~XpathQueryJFrame();
    void setQuery(jstring string_0);
    void setQuery(const char * easyArg_0);
    jstring runQuery(jstring string_0,jstring string_1);
    jstring runQuery(const char * easyArg_0,const char * easyArg_1);
    void setResult(jstring string_0);
    void setResult(const char * easyArg_0);
    void Message(jstring string_0);
    void Message(const char * easyArg_0);
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
    jstring getQuery();
    jstring getResult();
   }; // end class XpathQueryJFrame
  } // end namespace utils


  namespace base{
   
   class InitCanonType : public CRCLCommandType {
       public:
           InitCanonType(jobject _jthis, bool copy);
           InitCanonType(const InitCanonType &);
           
    InitCanonType();
    ~InitCanonType();
   }; // end class InitCanonType

   
   class JointStatusesType : public DataThingType {
       public:
           JointStatusesType(jobject _jthis, bool copy);
           JointStatusesType(const JointStatusesType &);
           
    JointStatusesType();
    ~JointStatusesType();
    ::crclj::java::util::List getJointStatus();
   }; // end class JointStatusesType

   
   class JointStatusType : public DataThingType {
       public:
           JointStatusType(jobject _jthis, bool copy);
           JointStatusType(const JointStatusType &);
           
    JointStatusType();
    ~JointStatusType();
    ::crclj::java::math::BigInteger getJointNumber();
    ::crclj::java::math::BigDecimal getJointPosition();
    ::crclj::java::math::BigDecimal getJointVelocity();
    ::crclj::java::math::BigDecimal getJointTorqueOrForce();
    void setJointNumber(::crclj::java::math::BigInteger  &bigInteger_0);
    void setJointPosition(::crclj::java::math::BigDecimal  &bigDecimal_0);
    void setJointVelocity(::crclj::java::math::BigDecimal  &bigDecimal_0);
    void setJointTorqueOrForce(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class JointStatusType

   
   class MoveThroughToType : public MiddleCommandType {
       public:
           MoveThroughToType(jobject _jthis, bool copy);
           MoveThroughToType(const MoveThroughToType &);
           
    MoveThroughToType();
    ~MoveThroughToType();
    jboolean isMoveStraight();
    void setMoveStraight(jboolean boolean_0);
    ::crclj::java::util::List getWaypoint();
    ::crclj::java::math::BigInteger getNumPositions();
    void setNumPositions(::crclj::java::math::BigInteger  &bigInteger_0);
   }; // end class MoveThroughToType
  } // end namespace base


  namespace utils{
   
   class TestInstance : public ::crclj::java::lang::Object {
       public:
           TestInstance(jobject _jthis, bool copy);
           TestInstance(const TestInstance &);
           
    TestInstance();
    ~TestInstance();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class TestInstance

   
   class SimServer : public ::crclj::javax::swing::JFrame {
       public:
           SimServer(jobject _jthis, bool copy);
           SimServer(const SimServer &);
           
    SimServer();
    ~SimServer();
    jboolean checkStatusValid(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0);
    jboolean isToolChangerOpen();
    void setToolChangerOpen(jboolean boolean_0);
    void showMessage(::crclj::java::lang::Throwable  &throwable_0);
    void showMessage(jstring string_0);
    void showMessage(const char * easyArg_0);
    void showDebugMessage(jstring string_0);
    void showDebugMessage(const char * easyArg_0);
    jboolean isEXISelected();
    void updateConnectedClients(jint int_0);
    jboolean isValidateXMLSelected();
    jboolean isSendStatusWithoutRequestSelected();
    jboolean isAppendZeroSelected();
    jboolean isRandomPacketSelected();
    jboolean isReplaceStateSelected();
    jboolean isEditingStatus();
    void updateCycleCount(jint int_0);
    void updatePanels(jboolean boolean_0);
    void updateIsInitialized(jboolean boolean_0);
    void updateCurrentCommandType(jstring string_0);
    void updateCurrentCommandType(const char * easyArg_0);
    void updateEndEffector(jstring string_0);
    void updateEndEffector(const char * easyArg_0);
    void updateToolChangerIsOpen(jboolean boolean_0);
    jboolean isInitializedSelected();
    void finishSetCurrentWaypoint(jint int_0);
    jboolean checkPose(::crclj::crcl::base::PoseType  &poseType_0);
    void updateNumWaypoints(jint int_0);
    jboolean isDebugMoveDoneSelected();
    jboolean isDebugSendStatusSelected();
    jboolean isDebugReadCommandSelected();
    jboolean isReplaceXmlHeaderSelected();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class SimServer

   
   class CmdLineSimServer : public ::crclj::java::lang::Object {
       public:
           CmdLineSimServer(jobject _jthis, bool copy);
           CmdLineSimServer(const CmdLineSimServer &);
           
    CmdLineSimServer();
    ~CmdLineSimServer();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class CmdLineSimServer
  } // end namespace utils
 } // end namespace crcl


 namespace rcs{
  namespace posemath{
   
   class PmPose : public ::crclj::java::lang::Object {
       public:
           PmPose(jobject _jthis, bool copy);
           PmPose(const PmPose &);
           
    PmPose(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3,jdouble double_4,jdouble double_5,jdouble double_6);
    PmPose();
    PmPose(PmCartesian  &pmCartesian_0,PmQuaternion  &pmQuaternion_1);
    PmPose(PmCartesian  &pmCartesian_0,PmRpy  &pmRpy_1);
    ~PmPose();
    jfloatArray toMatFloatArrayTranspose();
    jboolean equals(PmPose  &pmPose_0);
    jstring toString();
    PmPose clone();
   }; // end class PmPose
  } // end namespace posemath
 } // end namespace rcs


 namespace crcl{
  namespace utils{
   
   class AnnotatedPose : public ::crclj::rcs::posemath::PmPose {
       public:
           AnnotatedPose(jobject _jthis, bool copy);
           AnnotatedPose(const AnnotatedPose &);
           
    protected:
    AnnotatedPose();
    public:
    AnnotatedPose(jlong long_0,::crclj::java::math::BigInteger  &bigInteger_1,jstring string_2,::crclj::rcs::posemath::PmCartesian  &pmCartesian_3,::crclj::rcs::posemath::PmQuaternion  &pmQuaternion_4,::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_5);
    AnnotatedPose(jlong easyArg_0,::crclj::java::math::BigInteger easyArg_1,const char * easyArg_2,::crclj::rcs::posemath::PmCartesian easyArg_3,::crclj::rcs::posemath::PmQuaternion easyArg_4,::crclj::crcl::base::CRCLStatusType easyArg_5);
    ~AnnotatedPose();
    jlong getTime();
    ::crclj::crcl::base::CRCLStatusType getStatus();
    ::crclj::java::math::BigInteger getCmdId();
    jstring getCommandName();
    ::crclj::rcs::posemath::PmCartesian getTran();
    ::crclj::rcs::posemath::PmQuaternion getRot();
   }; // end class AnnotatedPose

   
   class CRCLSocket : public ::crclj::java::lang::Object {
       public:
           CRCLSocket(jobject _jthis, bool copy);
           CRCLSocket(const CRCLSocket &);
           
    protected:
    CRCLSocket();
    public:
    CRCLSocket(jstring string_0,jint int_1);
    CRCLSocket(const char * easyArg_0,jint easyArg_1);
    ~CRCLSocket();
    ::crclj::java::net::InetAddress getInetAddress();
    jboolean isConnected();
    jint getLocalPort();
    ::crclj::java::util::function::UnaryOperator getStatusStringInputFilter();
    void setStatusStringInputFilter(::crclj::java::util::function::UnaryOperator  &unaryOperator_0);
    ::crclj::java::util::function::UnaryOperator getStatusStringOutputFilter();
    void setStatusStringOutputFilter(::crclj::java::util::function::UnaryOperator  &unaryOperator_0);
    jboolean isJaxbFragment();
    void setJaxbFragment(jboolean boolean_0);
    jstring getLastStatusString();
    jstring getLastCommandString();
    ::crclj::javax::xml::validation::Schema getProgramSchema();
    void setProgramSchema(::crclj::javax::xml::validation::Schema  &schema_0);
    ::crclj::javax::xml::validation::Schema getCmdSchema();
    void setCmdSchema(::crclj::javax::xml::validation::Schema  &schema_0);
    ::crclj::javax::xml::validation::Schema getStatSchema();
    void setStatSchema(::crclj::javax::xml::validation::Schema  &schema_0);
    jstring getReadInProgressString();
    jstring readUntilEndTag(jstring string_0,::crclj::java::io::InputStream  &inputStream_1);
    jstring readUntilEndTag(const char * easyArg_0,::crclj::java::io::InputStream easyArg_1);
    ::crclj::crcl::base::CRCLCommandInstanceType stringToCommand(jstring string_0,jboolean boolean_1);
    ::crclj::crcl::base::CRCLCommandInstanceType stringToCommand(const char * easyArg_0,jboolean easyArg_1);
    ::crclj::crcl::base::CRCLCommandInstanceType readCommandFromStream(::crclj::java::io::InputStream  &inputStream_0,jboolean boolean_1);
    ::crclj::crcl::base::CRCLProgramType stringToProgram(jstring string_0,jboolean boolean_1);
    ::crclj::crcl::base::CRCLProgramType stringToProgram(const char * easyArg_0,jboolean easyArg_1);
    ::crclj::crcl::base::CRCLCommandInstanceType readCommand(jboolean boolean_0);
    ::crclj::crcl::base::CRCLStatusType stringToStatus(jstring string_0,jboolean boolean_1);
    ::crclj::crcl::base::CRCLStatusType stringToStatus(const char * easyArg_0,jboolean easyArg_1);
    ::crclj::crcl::base::CRCLStatusType readStatusFromStream(::crclj::java::io::InputStream  &inputStream_0,jboolean boolean_1);
    jboolean isEXIEnabled();
    jboolean isPrefixEXISizeEnabled();
    void setPrefixEXISizeEnabled(jboolean boolean_0);
    void setEXIEnabled(jboolean boolean_0);
    jbyteArray statusToEXI(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0);
    jbyteArray commandToEXI(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0);
    static jstring statToDebugString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0);
    void writeEXIStatusToStream(::crclj::java::io::OutputStream  &outputStream_0,::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_1);
    void writeEXICommandToStream(::crclj::java::io::OutputStream  &outputStream_0,::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_1);
    ::crclj::crcl::base::CRCLStatusType exiToStatus(jbyteArray byteArray_0);
    ::crclj::crcl::base::CRCLStatusType exiToStatus(jbyte * easyArg_0,jsize easyArg_0_length);
    ::crclj::crcl::base::CRCLCommandInstanceType exiToCommand(jbyteArray byteArray_0);
    ::crclj::crcl::base::CRCLCommandInstanceType exiToCommand(jbyte * easyArg_0,jsize easyArg_0_length);
    ::crclj::crcl::base::CRCLStatusType readStatusFromEXIStream(::crclj::java::io::InputStream  &inputStream_0);
    ::crclj::crcl::base::CRCLStatusType readStatusFromSaxSource(::crclj::javax::xml::transform::sax::SAXSource  &sAXSource_0);
    ::crclj::crcl::base::CRCLCommandInstanceType readCommandFromEXIStream(::crclj::java::io::InputStream  &inputStream_0);
    ::crclj::crcl::base::CRCLStatusType readStatus(jboolean boolean_0);
    jstring commandToString(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0,jboolean boolean_1);
    jstring commandToString(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1);
    jstring programToString(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1);
    jstring commandToPrettyString(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1);
    jstring commandToPrettyDocString(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1);
    jstring programToPrettyString(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1);
    jstring programToPrettyDocString(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1);
    void writeCommand(::crclj::crcl::base::CRCLCommandInstanceType  &cRCLCommandInstanceType_0,jboolean boolean_1);
    void writeWithFill(jstring string_0);
    void writeWithFill(const char * easyArg_0);
    void writeProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0,jboolean boolean_1);
    jboolean isReplaceHeader();
    void setReplaceHeader(jboolean boolean_0);
    jstring statusToString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,jboolean boolean_1);
    jstring statusToPrettyString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,jboolean boolean_1);
    static jobjectArray findSchemaFiles();
    static jobjectArray reorderStatSchemaFiles(jobjectArray fileArray_0);
    static ::crclj::java::util::List reorderStatSchemaFiles(::crclj::java::util::List  &list_0);
    static ::crclj::javax::xml::validation::Schema filesToSchema(jobjectArray fileArray_0);
    static jobjectArray readStatSchemaFiles(::crclj::java::io::File  &file_0);
    static void saveProgramSchemaFiles(::crclj::java::io::File  &file_0,jobjectArray fileArray_1);
    static void saveStatSchemaFiles(::crclj::java::io::File  &file_0,jobjectArray fileArray_1);
    static jobjectArray reorderCommandSchemaFiles(jobjectArray fileArray_0);
    static ::crclj::java::util::List reorderCommandSchemaFiles(::crclj::java::util::List  &list_0);
    static ::crclj::java::util::List reorderProgramSchemaFiles(::crclj::java::util::List  &list_0);
    static jobjectArray reorderProgramSchemaFiles(jobjectArray fileArray_0);
    static jobjectArray readCmdSchemaFiles(::crclj::java::io::File  &file_0);
    static jobjectArray readProgramSchemaFiles(::crclj::java::io::File  &file_0);
    static void saveCmdSchemaFiles(::crclj::java::io::File  &file_0,jobjectArray fileArray_1);
    void writeStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,jboolean boolean_1);
    void close();
    jint available();
    jint getPort();
   }; // end class CRCLSocket
  } // end namespace utils


  namespace base{
   
   class VacuumGripperStatusType : public GripperStatusType {
       public:
           VacuumGripperStatusType(jobject _jthis, bool copy);
           VacuumGripperStatusType(const VacuumGripperStatusType &);
           
    VacuumGripperStatusType();
    ~VacuumGripperStatusType();
    jboolean isIsPowered();
    void setIsPowered(jboolean boolean_0);
   }; // end class VacuumGripperStatusType

   
   class GetStatusType : public MiddleCommandType {
       public:
           GetStatusType(jobject _jthis, bool copy);
           GetStatusType(const GetStatusType &);
           
    GetStatusType();
    ~GetStatusType();
   }; // end class GetStatusType

   
   class RotSpeedAbsoluteType : public RotSpeedType {
       public:
           RotSpeedAbsoluteType(jobject _jthis, bool copy);
           RotSpeedAbsoluteType(const RotSpeedAbsoluteType &);
           
    RotSpeedAbsoluteType();
    ~RotSpeedAbsoluteType();
    ::crclj::java::math::BigDecimal getSetting();
    void setSetting(::crclj::java::math::BigDecimal  &bigDecimal_0);
   }; // end class RotSpeedAbsoluteType
  } // end namespace base


  namespace utils{
   
   class PendantClient : public ::crclj::javax::swing::JFrame {
       public:
           PendantClient(jobject _jthis, bool copy);
           PendantClient(const PendantClient &);
           
    PendantClient(jstring string_0);
    PendantClient(const char * easyArg_0);
    PendantClient();
    ~PendantClient();
    jboolean isConnected();
    void finishConnect();
    void showMessage(jstring string_0);
    void showMessage(const char * easyArg_0);
    void showMessage(::crclj::java::lang::Throwable  &throwable_0);
    jboolean showDebugMessage(jstring string_0);
    jboolean showDebugMessage(const char * easyArg_0);
    jboolean validateXmlSelected();
    jboolean replaceStateSelected();
    void finishDisconnect();
    void finishSetStatus();
    void checkXmlQuery(CRCLSocket  &cRCLSocket_0);
    void stopPollTimer();
    void checkPollSelected();
    jboolean isDebugWaitForDoneSelected();
    jboolean isDebugSendCommandSelected();
    jboolean isDebugReadStatusSelected();
    void showCurrentProgramLine(jint int_0);
    void finishOpenXmlProgramFile(::crclj::java::io::File  &file_0,::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_1);
    ::crclj::crcl::base::CRCLProgramType editProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    void showLastProgramLineExecTimeMillisDists(jlong long_0,jdouble double_1);
    jboolean isRecordPoseSelected();
    jboolean isEXISelected();
    jboolean isUseReadStatusThreadSelected();
    void openXmlProgramFile(::crclj::java::io::File  &file_0);
    void saveXmlProgramFile(::crclj::java::io::File  &file_0);
    jdouble getRpyJogIncrement();
    void setRpyJogIncrement(jdouble double_0);
    void showProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    void setStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0);
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
    void connect(jstring string_0,jint int_1);
    void connect(const char * easyArg_0,jint easyArg_1);
    jstring getHost();
    jint getPort();
   }; // end class PendantClient

   
   class CmdLineClient : public ::crclj::java::lang::Object {
       public:
           CmdLineClient(jobject _jthis, bool copy);
           CmdLineClient(const CmdLineClient &);
           
    CmdLineClient();
    ~CmdLineClient();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class CmdLineClient

   
   class CRCLSocketExample : public ::crclj::java::lang::Object {
       public:
           CRCLSocketExample(jobject _jthis, bool copy);
           CRCLSocketExample(const CRCLSocketExample &);
           
    CRCLSocketExample();
    ~CRCLSocketExample();
    static void main(jobjectArray stringArray_0);
    static void main(int argc,const char **argv);
   }; // end class CRCLSocketExample

   
   class PendantClientInner : public ::crclj::java::lang::Object {
       public:
           PendantClientInner(jobject _jthis, bool copy);
           PendantClientInner(const PendantClientInner &);
           
    protected:
    PendantClientInner();
    public:
    PendantClientInner(PendantClientOuter  &pendantClientOuter_0);
    ~PendantClientInner();
    void abort();
    void disconnect();
    jboolean isConnected();
    ::crclj::crcl::base::CRCLStatusType getStatus();
    void setProgramSchema(jobjectArray fileArray_0);
    void setCmdSchema(jobjectArray fileArray_0);
    void setStatSchema(jobjectArray fileArray_0);
    static ::crclj::java::util::Optional getJointStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,::crclj::java::math::BigInteger  &bigInteger_1);
    void readStatus();
    ::crclj::java::math::BigDecimal getJointPosition(::crclj::java::math::BigInteger  &bigInteger_0);
    void waitForPause();
    jboolean runProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    jboolean runTest();
    void setCmdId(::crclj::java::math::BigInteger  &bigInteger_0);
    void setJogInterval(jint int_0);
    void openXmlProgramFile(::crclj::java::io::File  &file_0);
    void saveXmlProgramFile(::crclj::java::io::File  &file_0);
    jdouble getJogIncrement();
    void setProgram(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    jboolean incAndSendCommand(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0);
    CRCLSocket getCRCLSocket();
    jint getJogInterval();
    jdouble getXyzJogIncrement();
    CRCLSocket getTempCRCLSocket();
    jobjectArray getProgramSchemaFiles();
    ::crclj::java::util::function::Predicate getCheckProgramValidPredicate();
    ::crclj::java::util::function::Predicate getCheckCommandValidPredicate();
    jint getPoll_ms();
    void setPoll_ms(jint int_0);
    void setJogIncrement(jdouble double_0);
    void setXyzJogIncrement(jdouble double_0);
    void startRunTestThread();
    void startRunProgramThread();
    jboolean isPaused();
    jboolean isRunningProgram();
    void unpause();
    ::crclj::crcl::base::CRCLProgramType getProgram();
    void savePoseListToCsvFile(jstring string_0);
    void savePoseListToCsvFile(const char * easyArg_0);
    ::crclj::java::util::List getPoseList();
    void startStatusReaderThread();
    void stopStatusReaderThread();
    void closeTestProgramThread();
    jboolean requestStatus();
    jboolean checkProgramValid(::crclj::crcl::base::CRCLProgramType  &cRCLProgramType_0);
    jboolean checkCommandValid(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0);
    jobjectArray getCmdSchemaFiles();
    jboolean sendCommand(::crclj::crcl::base::CRCLCommandType  &cRCLCommandType_0);
    jboolean waitForDone(::crclj::java::math::BigInteger  &bigInteger_0,jlong long_1);
    jlong getWaitForDoneDelay();
    void setWaitForDoneDelay(jlong long_0);
    static ::crclj::java::util::stream::Stream getJointValues(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,::crclj::java::util::Collection  &collection_1);
    static jstring getJointString(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0,::crclj::java::util::function::Function  &function_1,::crclj::java::util::Collection  &collection_2);
    void pause();
    jboolean isDone(::crclj::java::math::BigInteger  &bigInteger_0);
    ::crclj::java::math::BigInteger getCmdId();
    XpathUtils getXpu();
    void setStatus(::crclj::crcl::base::CRCLStatusType  &cRCLStatusType_0);
    ::crclj::crcl::base::PoseToleranceType getExpectedEndPoseTolerance();
    void setExpectedEndPoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0);
    ::crclj::crcl::base::PoseToleranceType getExpectedIntermediatePoseTolerance();
    void setExpectedIntermediatePoseTolerance(::crclj::crcl::base::PoseToleranceType  &poseToleranceType_0);
    void connect(jstring string_0,jint int_1);
    void connect(const char * easyArg_0,jint easyArg_1);
   }; // end class PendantClientInner
  } // end namespace utils
 } // end namespace crcl


 namespace java{
  namespace lang{
   
   class Number : public Object {
       public:
           Number(jobject _jthis, bool copy);
           Number(const Number &);
           
    Number();
    ~Number();
    jbyte byteValue();
    jshort shortValue();
    jint intValue();
    jlong longValue();
    jfloat floatValue();
    jdouble doubleValue();
   }; // end class Number
  } // end namespace lang


  namespace math{
   
   class BigDecimal : public ::crclj::java::lang::Number {
       public:
           BigDecimal(jobject _jthis, bool copy);
           BigDecimal(const BigDecimal &);
           
    protected:
    BigDecimal();
    public:
    BigDecimal(jdouble double_0);
    BigDecimal(jcharArray charArray_0,jint int_1,jint int_2);
    BigDecimal(jchar * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2);
    BigDecimal(jcharArray charArray_0);
    BigDecimal(jchar * easyArg_0,jsize easyArg_0_length);
    BigDecimal(jint int_0);
    BigDecimal(jlong long_0);
    BigDecimal(BigInteger  &bigInteger_0,jint int_1);
    BigDecimal(BigInteger  &bigInteger_0);
    BigDecimal(jstring string_0);
    BigDecimal(const char * easyArg_0);
    ~BigDecimal();
    jint precision();
    BigDecimal divideToIntegralValue(BigDecimal  &bigDecimal_0);
    jobjectArray divideAndRemainder(BigDecimal  &bigDecimal_0);
    BigDecimal plus();
    BigInteger unscaledValue();
    BigDecimal movePointLeft(jint int_0);
    BigDecimal movePointRight(jint int_0);
    BigDecimal scaleByPowerOfTen(jint int_0);
    BigDecimal stripTrailingZeros();
    jstring toEngineeringString();
    jstring toPlainString();
    BigInteger toBigInteger();
    BigInteger toBigIntegerExact();
    jlong longValueExact();
    jint intValueExact();
    jshort shortValueExact();
    jbyte byteValueExact();
    BigDecimal subtract(BigDecimal  &bigDecimal_0);
    BigDecimal multiply(BigDecimal  &bigDecimal_0);
    BigDecimal setScale(jint int_0);
    BigDecimal setScale(jint int_0,jint int_1);
    BigDecimal negate();
    BigDecimal add(BigDecimal  &bigDecimal_0);
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jstring toString();
    jint hashCode();
    BigDecimal abs();
    BigDecimal pow(jint int_0);
    BigDecimal min(BigDecimal  &bigDecimal_0);
    BigDecimal max(BigDecimal  &bigDecimal_0);
    jint compareTo(BigDecimal  &bigDecimal_0);
    jint intValue();
    jlong longValue();
    jfloat floatValue();
    jdouble doubleValue();
    static BigDecimal valueOf(jlong long_0,jint int_1);
    static BigDecimal valueOf(jlong long_0);
    static BigDecimal valueOf(jdouble double_0);
    jint signum();
    BigDecimal divide(BigDecimal  &bigDecimal_0,jint int_1,jint int_2);
    BigDecimal divide(BigDecimal  &bigDecimal_0,jint int_1);
    BigDecimal divide(BigDecimal  &bigDecimal_0);
    BigDecimal remainder(BigDecimal  &bigDecimal_0);
    BigDecimal ulp();
    jint scale();
   }; // end class BigDecimal
  } // end namespace math


  namespace util{
   
   class List : public ::crclj::java::lang::Object {
       public:
           List(jobject _jthis, bool copy);
           List(const List &);
           
    List();
    ~List();
    jboolean add(::crclj::java::lang::Object  &object_0);
    void add(jint int_0,::crclj::java::lang::Object  &object_1);
    jboolean remove(::crclj::java::lang::Object  &object_0);
    ::crclj::java::lang::Object remove(jint int_0);
    ::crclj::java::lang::Object get(jint int_0);
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jint hashCode();
    jint indexOf(::crclj::java::lang::Object  &object_0);
    void clear();
    jboolean isEmpty();
    jint lastIndexOf(::crclj::java::lang::Object  &object_0);
    jboolean contains(::crclj::java::lang::Object  &object_0);
    void replaceAll(function::UnaryOperator  &unaryOperator_0);
    jint size();
    List subList(jint int_0,jint int_1);
    jobjectArray toArray();
    jobjectArray toArray(jobjectArray objectArray_0);
    jboolean addAll(Collection  &collection_0);
    jboolean addAll(jint int_0,Collection  &collection_1);
    ::crclj::java::lang::Object set(jint int_0,::crclj::java::lang::Object  &object_1);
    jboolean containsAll(Collection  &collection_0);
    jboolean removeAll(Collection  &collection_0);
    jboolean retainAll(Collection  &collection_0);
   }; // end class List
  } // end namespace util


  namespace lang{
   
   class Throwable : public Object {
       public:
           Throwable(jobject _jthis, bool copy);
           Throwable(const Throwable &);
           
    Throwable(jstring string_0,Throwable  &throwable_1);
    Throwable(const char * easyArg_0,Throwable easyArg_1);
    Throwable(jstring string_0);
    Throwable(const char * easyArg_0);
    Throwable();
    ~Throwable();
    void printStackTrace();
    void printStackTrace(::crclj::java::io::PrintStream  &printStream_0);
    Throwable fillInStackTrace();
    Throwable getCause();
    Throwable initCause(Throwable  &throwable_0);
    jstring toString();
    jstring getMessage();
    jstring getLocalizedMessage();
     void addSuppressed(Throwable  &throwable_0);
     jobjectArray getSuppressed();
   }; // end class Throwable
  } // end namespace lang


  namespace io{
   
   class File : public ::crclj::java::lang::Object {
       public:
           File(jobject _jthis, bool copy);
           File(const File &);
           
    protected:
    File();
    public:
    File(jstring string_0,jstring string_1);
    File(const char * easyArg_0,const char * easyArg_1);
    File(jstring string_0);
    File(const char * easyArg_0);
    File(File  &file_0,jstring string_1);
    File(File easyArg_0,const char * easyArg_1);
    ~File();
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jstring toString();
    jint hashCode();
    jint compareTo(File  &file_0);
    jstring getName();
    jlong length();
    jstring getParent();
    jboolean isAbsolute();
    jstring getCanonicalPath();
    jboolean deleteMethod();
    jboolean setReadOnly();
    jobjectArray list();
    File getParentFile();
    jstring getPath();
    jstring getAbsolutePath();
    File getAbsoluteFile();
    File getCanonicalFile();
    jboolean canRead();
    jboolean canWrite();
    jboolean exists();
    jboolean isDirectory();
    jboolean isFile();
    jboolean isHidden();
    jlong lastModified();
    jboolean createNewFile();
    void deleteOnExit();
    jobjectArray listFiles();
    jboolean mkdir();
    jboolean mkdirs();
    jboolean renameTo(File  &file_0);
    jboolean setLastModified(jlong long_0);
    jboolean setWritable(jboolean boolean_0);
    jboolean setWritable(jboolean boolean_0,jboolean boolean_1);
    jboolean setReadable(jboolean boolean_0,jboolean boolean_1);
    jboolean setReadable(jboolean boolean_0);
    jboolean setExecutable(jboolean boolean_0);
    jboolean setExecutable(jboolean boolean_0,jboolean boolean_1);
    jboolean canExecute();
    static jobjectArray listRoots();
    jlong getTotalSpace();
    jlong getFreeSpace();
    jlong getUsableSpace();
    static File createTempFile(jstring string_0,jstring string_1);
    static File createTempFile(jstring string_0,jstring string_1,File  &file_2);
   }; // end class File
  } // end namespace io
 } // end namespace java


 namespace javax{
  namespace xml{
   namespace bind{
    
    class JAXBElement : public ::crclj::java::lang::Object {
        public:
            JAXBElement(jobject _jthis, bool copy);
            JAXBElement(const JAXBElement &);
            
     protected:
     JAXBElement();
     public:
     ~JAXBElement();
     jboolean isNil();
     void setNil(jboolean boolean_0);
     jboolean isGlobalScope();
     jboolean isTypeSubstituted();
     ::crclj::java::lang::Object getValue();
     void setValue(::crclj::java::lang::Object  &object_0);
    }; // end class JAXBElement
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
        
        class Vector3D : public ::crclj::java::lang::Object {
            public:
                Vector3D(jobject _jthis, bool copy);
                Vector3D(const Vector3D &);
                
         protected:
         Vector3D();
         public:
         Vector3D(jdouble double_0,Vector3D  &vector3D_1);
         Vector3D(jdouble double_0,jdouble double_1);
         Vector3D(jdoubleArray doubleArray_0);
         Vector3D(jdouble * easyArg_0,jsize easyArg_0_length);
         Vector3D(jdouble double_0,jdouble double_1,jdouble double_2);
         Vector3D(jdouble double_0,Vector3D  &vector3D_1,jdouble double_2,Vector3D  &vector3D_3);
         Vector3D(jdouble double_0,Vector3D  &vector3D_1,jdouble double_2,Vector3D  &vector3D_3,jdouble double_4,Vector3D  &vector3D_5);
         Vector3D(jdouble double_0,Vector3D  &vector3D_1,jdouble double_2,Vector3D  &vector3D_3,jdouble double_4,Vector3D  &vector3D_5,jdouble double_6,Vector3D  &vector3D_7);
         ~Vector3D();
         static jdouble distanceSq(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         static jdouble distance(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         jdouble getAlpha();
         jdouble getX();
         jdouble getY();
         jdouble getZ();
         static jdouble angle(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         Vector3D negate();
         Vector3D getZero();
         Vector3D scalarMultiply(jdouble double_0);
         static jdouble dotProduct(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         static jdouble distanceInf(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         static jdouble distance1(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         jdouble getNorm();
         jdouble getNorm1();
         jdouble getNormSq();
         jdouble getNormInf();
         jdouble getDelta();
         Vector3D orthogonal();
         static Vector3D crossProduct(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         jboolean equals(::crclj::java::lang::Object  &object_0);
         jstring toString();
         jint hashCode();
         jdoubleArray toArray();
         jboolean isNaN();
         Vector3D normalize();
         jboolean isInfinite();
        }; // end class Vector3D

        
        class Rotation : public ::crclj::java::lang::Object {
            public:
                Rotation(jobject _jthis, bool copy);
                Rotation(const Rotation &);
                
         protected:
         Rotation();
         public:
         Rotation(Vector3D  &vector3D_0,jdouble double_1);
         Rotation(Vector3D  &vector3D_0,Vector3D  &vector3D_1,Vector3D  &vector3D_2,Vector3D  &vector3D_3);
         Rotation(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3,jboolean boolean_4);
         Rotation(Vector3D  &vector3D_0,Vector3D  &vector3D_1);
         ~Rotation();
         static jdouble distance(Rotation  &rotation_0,Rotation  &rotation_1);
         Vector3D getAxis();
         jdouble getAngle();
         Rotation revert();
         jdouble getQ0();
         jdouble getQ1();
         jdouble getQ2();
         jdouble getQ3();
         void applyTo(jdoubleArray doubleArray_0,jdoubleArray doubleArray_1);
         void applyTo(jdouble * easyArg_0,jsize easyArg_0_length,jdouble * easyArg_1,jsize easyArg_1_length);
         Rotation applyTo(Rotation  &rotation_0);
         Vector3D applyTo(Vector3D  &vector3D_0);
         void applyInverseTo(jdoubleArray doubleArray_0,jdoubleArray doubleArray_1);
         void applyInverseTo(jdouble * easyArg_0,jsize easyArg_0_length,jdouble * easyArg_1,jsize easyArg_1_length);
         Vector3D applyInverseTo(Vector3D  &vector3D_0);
         Rotation applyInverseTo(Rotation  &rotation_0);
        }; // end class Rotation
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
    
    class Point2D : public ::crclj::java::lang::Object {
        public:
            Point2D(jobject _jthis, bool copy);
            Point2D(const Point2D &);
            
     protected:
     Point2D();
     public:
     ~Point2D();
     jdouble distanceSq(Point2D  &point2D_0);
     static jdouble distanceSq(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3);
     jdouble distanceSq(jdouble double_0,jdouble double_1);
     jdouble distance(Point2D  &point2D_0);
     jdouble distance(jdouble double_0,jdouble double_1);
     static jdouble distance(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3);
     void setLocation(Point2D  &point2D_0);
     void setLocation(jdouble double_0,jdouble double_1);
     jdouble getX();
     jdouble getY();
     jboolean equals(::crclj::java::lang::Object  &object_0);
     jint hashCode();
     ::crclj::java::lang::Object clone();
    }; // end class Point2D

    
    class Point2DDouble : public Point2D {
        public:
            Point2DDouble(jobject _jthis, bool copy);
            Point2DDouble(const Point2DDouble &);
            
     Point2DDouble();
     Point2DDouble(jdouble double_0,jdouble double_1);
     ~Point2DDouble();
     void setLocation(jdouble double_0,jdouble double_1);
     jdouble getX();
     jdouble getY();
     jstring toString();
    }; // end class Point2DDouble
   } // end namespace geom
  } // end namespace awt
 } // end namespace java


 namespace rcs{
  namespace posemath{
   
   class PmCartesian : public ::crclj::java::awt::geom::Point2DDouble {
       public:
           PmCartesian(jobject _jthis, bool copy);
           PmCartesian(const PmCartesian &);
           
    PmCartesian();
    PmCartesian(jdouble double_0,jdouble double_1,jdouble double_2);
    ~PmCartesian();
    jdouble getX();
    jdouble getY();
    void setX(jdouble double_0);
    void setY(jdouble double_0);
    jdouble getZ();
    void setZ(jdouble double_0);
    jdouble mag();
    jdouble distFrom(PmCartesian  &pmCartesian_0);
    PmCartesian subtract(PmCartesian  &pmCartesian_0);
    PmCartesian multiply(jdouble double_0);
    PmCartesian add(PmCartesian  &pmCartesian_0);
    jboolean equals(PmCartesian  &pmCartesian_0);
    jstring toString();
    PmCartesian clone();
    static PmCartesian valueOf(jstring string_0);
   }; // end class PmCartesian

   
   class PmRotationVector : public ::crclj::java::lang::Object {
       public:
           PmRotationVector(jobject _jthis, bool copy);
           PmRotationVector(const PmRotationVector &);
           
    PmRotationVector(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3);
    PmRotationVector();
    ~PmRotationVector();
    PmRotationVector inv();
    PmRotationVector multiply(PmRotationVector  &pmRotationVector_0);
    PmRotationVector multiply(jdouble double_0);
    PmRotationVector clone();
   }; // end class PmRotationVector

   
   class PmRotationMatrix : public ::crclj::java::lang::Object {
       public:
           PmRotationMatrix(jobject _jthis, bool copy);
           PmRotationMatrix(const PmRotationMatrix &);
           
    PmRotationMatrix();
    PmRotationMatrix(PmCartesian  &pmCartesian_0,PmCartesian  &pmCartesian_1,PmCartesian  &pmCartesian_2);
    PmRotationMatrix(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3,jdouble double_4,jdouble double_5,jdouble double_6,jdouble double_7,jdouble double_8);
    ~PmRotationMatrix();
    PmRotationMatrix inv();
    PmRotationMatrix multiply(PmRotationMatrix  &pmRotationMatrix_0);
    PmCartesian multiply(PmCartesian  &pmCartesian_0);
    jstring toString();
   }; // end class PmRotationMatrix

   
   class PmRpy : public ::crclj::java::lang::Object {
       public:
           PmRpy(jobject _jthis, bool copy);
           PmRpy(const PmRpy &);
           
    PmRpy(jdouble double_0,jdouble double_1,jdouble double_2);
    PmRpy();
    PmRpy(PmQuaternion  &pmQuaternion_0);
    ~PmRpy();
    jdouble getY();
    void setY(jdouble double_0);
    jdouble getR();
    void norm();
    jdouble getP();
    void setR(jdouble double_0);
    void setP(jdouble double_0);
    jstring toString();
    PmRpy clone();
   }; // end class PmRpy
  } // end namespace posemath
 } // end namespace rcs


 namespace org{
  namespace w3c{
   namespace dom{
    
    class Node : public ::crclj::java::lang::Object {
        public:
            Node(jobject _jthis, bool copy);
            Node(const Node &);
            
     Node();
     ~Node();
     jstring getNodeName();
     jstring getNodeValue();
     void setNodeValue(jstring string_0);
     void setNodeValue(const char * easyArg_0);
     jshort getNodeType();
     Node getParentNode();
     NodeList getChildNodes();
     Node getFirstChild();
     Node getLastChild();
     Node getPreviousSibling();
     Node getNextSibling();
     Node insertBefore(Node  &node_0,Node  &node_1);
     Node replaceChild(Node  &node_0,Node  &node_1);
     Node removeChild(Node  &node_0);
     Node appendChild(Node  &node_0);
     jboolean hasChildNodes();
     Node cloneNode(jboolean boolean_0);
     void setPrefix(jstring string_0);
     void setPrefix(const char * easyArg_0);
     jboolean hasAttributes();
     jstring getBaseURI();
     jshort compareDocumentPosition(Node  &node_0);
     jstring getTextContent();
     void setTextContent(jstring string_0);
     void setTextContent(const char * easyArg_0);
     jboolean isSameNode(Node  &node_0);
     jstring lookupPrefix(jstring string_0);
     jstring lookupPrefix(const char * easyArg_0);
     jboolean isDefaultNamespace(jstring string_0);
     jboolean isDefaultNamespace(const char * easyArg_0);
     jstring lookupNamespaceURI(jstring string_0);
     jstring lookupNamespaceURI(const char * easyArg_0);
     jboolean isEqualNode(Node  &node_0);
     ::crclj::java::lang::Object getFeature(jstring string_0,jstring string_1);
     ::crclj::java::lang::Object getFeature(const char * easyArg_0,const char * easyArg_1);
     ::crclj::java::lang::Object getUserData(jstring string_0);
     ::crclj::java::lang::Object getUserData(const char * easyArg_0);
     jstring getPrefix();
     jstring getNamespaceURI();
     jstring getLocalName();
     void normalize();
     jboolean isSupported(jstring string_0,jstring string_1);
     jboolean isSupported(const char * easyArg_0,const char * easyArg_1);
    }; // end class Node

    
    class NodeList : public ::crclj::java::lang::Object {
        public:
            NodeList(jobject _jthis, bool copy);
            NodeList(const NodeList &);
            
     NodeList();
     ~NodeList();
     Node item(jint int_0);
     jint getLength();
    }; // end class NodeList
   } // end namespace dom
  } // end namespace w3c
 } // end namespace org


 namespace javax{
  namespace xml{
   namespace datatype{
    
    class XMLGregorianCalendar : public ::crclj::java::lang::Object {
        public:
            XMLGregorianCalendar(jobject _jthis, bool copy);
            XMLGregorianCalendar(const XMLGregorianCalendar &);
            
     XMLGregorianCalendar();
     ~XMLGregorianCalendar();
     jboolean isValid();
     void setTime(jint int_0,jint int_1,jint int_2);
     void setTime(jint int_0,jint int_1,jint int_2,::crclj::java::math::BigDecimal  &bigDecimal_3);
     void setTime(jint int_0,jint int_1,jint int_2,jint int_3);
     jint getYear();
     jint getMonth();
     void setYear(::crclj::java::math::BigInteger  &bigInteger_0);
     void setYear(jint int_0);
     void setMonth(jint int_0);
     jint getDay();
     jint getSecond();
     void setFractionalSecond(::crclj::java::math::BigDecimal  &bigDecimal_0);
     ::crclj::java::math::BigInteger getEon();
     void setTimezone(jint int_0);
     ::crclj::java::math::BigInteger getEonAndYear();
     ::crclj::java::math::BigDecimal getFractionalSecond();
     jint getMinute();
     jint getMillisecond();
     void setMillisecond(jint int_0);
     jint getTimezone();
     jint getHour();
     void setHour(jint int_0);
     void setMinute(jint int_0);
     void setDay(jint int_0);
     void setSecond(jint int_0);
     jstring toXMLFormat();
     jboolean equals(::crclj::java::lang::Object  &object_0);
     jstring toString();
     jint hashCode();
     ::crclj::java::lang::Object clone();
     void clear();
     jint compare(XMLGregorianCalendar  &xMLGregorianCalendar_0);
     XMLGregorianCalendar normalize();
     void reset();
    }; // end class XMLGregorianCalendar
   } // end namespace datatype
  } // end namespace xml
 } // end namespace javax


 namespace java{
  namespace io{
   
   class OutputStream : public ::crclj::java::lang::Object {
       public:
           OutputStream(jobject _jthis, bool copy);
           OutputStream(const OutputStream &);
           
    OutputStream();
    ~OutputStream();
    void write(jbyteArray byteArray_0,jint int_1,jint int_2);
    void write(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2);
    void write(jbyteArray byteArray_0);
    void write(jbyte * easyArg_0,jsize easyArg_0_length);
    void write(jint int_0);
    void flush();
    void close();
   }; // end class OutputStream

   
   class FilterOutputStream : public OutputStream {
       public:
           FilterOutputStream(jobject _jthis, bool copy);
           FilterOutputStream(const FilterOutputStream &);
           
    protected:
    FilterOutputStream();
    public:
    FilterOutputStream(OutputStream  &outputStream_0);
    ~FilterOutputStream();
    void write(jbyteArray byteArray_0,jint int_1,jint int_2);
    void write(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2);
    void write(jbyteArray byteArray_0);
    void write(jbyte * easyArg_0,jsize easyArg_0_length);
    void write(jint int_0);
    void flush();
    void close();
   }; // end class FilterOutputStream

   
   class PrintStream : public FilterOutputStream {
       public:
           PrintStream(jobject _jthis, bool copy);
           PrintStream(const PrintStream &);
           
    protected:
    PrintStream();
    public:
    PrintStream(OutputStream  &outputStream_0);
    PrintStream(OutputStream  &outputStream_0,jboolean boolean_1);
    PrintStream(OutputStream  &outputStream_0,jboolean boolean_1,jstring string_2);
    PrintStream(OutputStream easyArg_0,jboolean easyArg_1,const char * easyArg_2);
    PrintStream(jstring string_0);
    PrintStream(const char * easyArg_0);
    PrintStream(jstring string_0,jstring string_1);
    PrintStream(const char * easyArg_0,const char * easyArg_1);
    PrintStream(File  &file_0,jstring string_1);
    PrintStream(File easyArg_0,const char * easyArg_1);
    PrintStream(File  &file_0);
    ~PrintStream();
    void println(jdouble double_0);
    void println(jfloat float_0);
    void println(jlong long_0);
    void println(::crclj::java::lang::Object  &object_0);
    void println(jstring string_0);
    void println(const char * easyArg_0);
    void println(jcharArray charArray_0);
    void println(jchar * easyArg_0,jsize easyArg_0_length);
    void println();
    void println(jboolean boolean_0);
    void println(jchar char_0);
    void println(jint int_0);
    PrintStream append(jchar char_0);
    PrintStream format(jstring string_0,jobjectArray objectArray_1);
    void write(jint int_0);
    void write(jbyteArray byteArray_0,jint int_1,jint int_2);
    void write(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2);
    void print(jboolean boolean_0);
    void print(jlong long_0);
    void print(jdouble double_0);
    void print(jfloat float_0);
    void print(::crclj::java::lang::Object  &object_0);
    void print(jstring string_0);
    void print(const char * easyArg_0);
    void print(jcharArray charArray_0);
    void print(jchar * easyArg_0,jsize easyArg_0_length);
    void print(jchar char_0);
    void print(jint int_0);
    void flush();
    void close();
    jboolean checkError();
    PrintStream printf(jstring string_0,jobjectArray objectArray_1);
   }; // end class PrintStream
  } // end namespace io


  namespace util{
   namespace function{
    
    class Predicate : public ::crclj::java::lang::Object {
        public:
            Predicate(jobject _jthis, bool copy);
            Predicate(const Predicate &);
            
     Predicate();
     ~Predicate();
     static Predicate isEqual(::crclj::java::lang::Object  &object_0);
     Predicate negate();
     jboolean test(::crclj::java::lang::Object  &object_0);
     Predicate andMethod(Predicate  &predicate_0);
     Predicate orMethod(Predicate  &predicate_0);
    }; // end class Predicate
   } // end namespace function
  } // end namespace util


  namespace math{
   
   class BigInteger : public ::crclj::java::lang::Number {
       public:
           BigInteger(jobject _jthis, bool copy);
           BigInteger(const BigInteger &);
           
    protected:
    BigInteger();
    public:
    BigInteger(jbyteArray byteArray_0);
    BigInteger(jbyte * easyArg_0,jsize easyArg_0_length);
    BigInteger(jint int_0,jbyteArray byteArray_1);
    BigInteger(jint easyArg_0,jbyte * easyArg_1,jsize easyArg_1_length);
    BigInteger(jstring string_0,jint int_1);
    BigInteger(const char * easyArg_0,jint easyArg_1);
    BigInteger(jstring string_0);
    BigInteger(const char * easyArg_0);
    ~BigInteger();
    jobjectArray divideAndRemainder(BigInteger  &bigInteger_0);
    jlong longValueExact();
    jint intValueExact();
    jshort shortValueExact();
    jbyte byteValueExact();
    jint bitLength();
    jboolean testBit(jint int_0);
    BigInteger nextProbablePrime();
    BigInteger modPow(BigInteger  &bigInteger_0,BigInteger  &bigInteger_1);
    BigInteger modInverse(BigInteger  &bigInteger_0);
    BigInteger clearBit(jint int_0);
    jint getLowestSetBit();
    jboolean isProbablePrime(jint int_0);
    BigInteger mod(BigInteger  &bigInteger_0);
    BigInteger notMethod();
    BigInteger subtract(BigInteger  &bigInteger_0);
    BigInteger multiply(BigInteger  &bigInteger_0);
    BigInteger negate();
    BigInteger shiftRight(jint int_0);
    BigInteger setBit(jint int_0);
    BigInteger flipBit(jint int_0);
    BigInteger gcd(BigInteger  &bigInteger_0);
    BigInteger add(BigInteger  &bigInteger_0);
    jint bitCount();
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jstring toString();
    jstring toString(jint int_0);
    jint hashCode();
    BigInteger abs();
    BigInteger pow(jint int_0);
    BigInteger min(BigInteger  &bigInteger_0);
    BigInteger max(BigInteger  &bigInteger_0);
    jint compareTo(BigInteger  &bigInteger_0);
    jint intValue();
    jlong longValue();
    jfloat floatValue();
    jdouble doubleValue();
    static BigInteger valueOf(jlong long_0);
    jint signum();
    BigInteger shiftLeft(jint int_0);
    BigInteger divide(BigInteger  &bigInteger_0);
    BigInteger remainder(BigInteger  &bigInteger_0);
    jbyteArray toByteArray();
    BigInteger andMethod(BigInteger  &bigInteger_0);
    BigInteger orMethod(BigInteger  &bigInteger_0);
    BigInteger xorMethod(BigInteger  &bigInteger_0);
    BigInteger andNot(BigInteger  &bigInteger_0);
   }; // end class BigInteger
  } // end namespace math
 } // end namespace java


 namespace rcs{
  namespace posemath{
   
   class PmQuaternion : public ::crclj::java::lang::Object {
       public:
           PmQuaternion(jobject _jthis, bool copy);
           PmQuaternion(const PmQuaternion &);
           
    PmQuaternion();
    PmQuaternion(PmRpy  &pmRpy_0);
    PmQuaternion(jdouble double_0,jdouble double_1,jdouble double_2,jdouble double_3);
    PmQuaternion(PmRotationMatrix  &pmRotationMatrix_0);
    PmQuaternion(PmRotationVector  &pmRotationVector_0);
    ~PmQuaternion();
    jdouble getX();
    jdouble getY();
    jdouble getS();
    void setS(jdouble double_0);
    void setX(jdouble double_0);
    void setY(jdouble double_0);
    jdouble getZ();
    void setZ(jdouble double_0);
    PmQuaternion multipy(PmQuaternion  &pmQuaternion_0);
    jboolean equals(PmRotationVector  &pmRotationVector_0);
    jboolean equals(PmRotationMatrix  &pmRotationMatrix_0);
    jboolean equals(PmQuaternion  &pmQuaternion_0);
    jstring toString();
    PmQuaternion clone();
   }; // end class PmQuaternion
  } // end namespace posemath
 } // end namespace rcs


 namespace java{
  namespace net{
   
   class InetAddress : public ::crclj::java::lang::Object {
       public:
           InetAddress(jobject _jthis, bool copy);
           InetAddress(const InetAddress &);
           
    protected:
    InetAddress();
    public:
    ~InetAddress();
    static InetAddress getLoopbackAddress();
    jboolean isMulticastAddress();
    jboolean isAnyLocalAddress();
    static InetAddress getByName(jstring string_0);
    static InetAddress getLocalHost();
    jboolean isLoopbackAddress();
    jboolean isLinkLocalAddress();
    jboolean isSiteLocalAddress();
    jboolean isMCGlobal();
    jboolean isMCNodeLocal();
    jboolean isMCLinkLocal();
    jboolean isMCSiteLocal();
    jboolean isMCOrgLocal();
    jboolean isReachable(jint int_0);
    jstring getCanonicalHostName();
    static InetAddress getByAddress(jstring string_0,jbyteArray byteArray_1);
    static InetAddress getByAddress(jbyteArray byteArray_0);
    static jobjectArray getAllByName(jstring string_0);
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jstring toString();
    jint hashCode();
    jbyteArray getAddress();
    jstring getHostAddress();
    jstring getHostName();
   }; // end class InetAddress
  } // end namespace net


  namespace util{
   namespace function{
    
    class UnaryOperator : public ::crclj::java::lang::Object {
        public:
            UnaryOperator(jobject _jthis, bool copy);
            UnaryOperator(const UnaryOperator &);
            
     UnaryOperator();
     ~UnaryOperator();
     static UnaryOperator identity();
    }; // end class UnaryOperator
   } // end namespace function
  } // end namespace util
 } // end namespace java


 namespace javax{
  namespace xml{
   namespace validation{
    
    class Schema : public ::crclj::java::lang::Object {
        public:
            Schema(jobject _jthis, bool copy);
            Schema(const Schema &);
            
     protected:
     Schema();
     public:
     ~Schema();
    }; // end class Schema
   } // end namespace validation
  } // end namespace xml
 } // end namespace javax


 namespace java{
  namespace io{
   
   class InputStream : public ::crclj::java::lang::Object {
       public:
           InputStream(jobject _jthis, bool copy);
           InputStream(const InputStream &);
           
    InputStream();
    ~InputStream();
    jint read(jbyteArray byteArray_0,jint int_1,jint int_2);
    jint read(jbyte * easyArg_0,jsize easyArg_0_length,jint easyArg_1,jint easyArg_2);
    jint read(jbyteArray byteArray_0);
    jint read(jbyte * easyArg_0,jsize easyArg_0_length);
    jint read();
    void close();
    void mark(jint int_0);
    jlong skip(jlong long_0);
    jint available();
    jboolean markSupported();
    void reset();
   }; // end class InputStream
  } // end namespace io
 } // end namespace java


 namespace javax{
  namespace xml{
   namespace transform{
    namespace sax{
     
     class SAXSource : public ::crclj::java::lang::Object {
         public:
             SAXSource(jobject _jthis, bool copy);
             SAXSource(const SAXSource &);
             
      SAXSource();
      ~SAXSource();
      jstring getSystemId();
      void setSystemId(jstring string_0);
      void setSystemId(const char * easyArg_0);
     }; // end class SAXSource
    } // end namespace sax
   } // end namespace transform
  } // end namespace xml
 } // end namespace javax


 namespace java{
  namespace util{
   
   class Optional : public ::crclj::java::lang::Object {
       public:
           Optional(jobject _jthis, bool copy);
           Optional(const Optional &);
           
    protected:
    Optional();
    public:
    ~Optional();
    jboolean isPresent();
    static Optional ofNullable(::crclj::java::lang::Object  &object_0);
    ::crclj::java::lang::Object orElse(::crclj::java::lang::Object  &object_0);
    Optional flatMap(function::Function  &function_0);
    ::crclj::java::lang::Object get();
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jstring toString();
    jint hashCode();
    static Optional of(::crclj::java::lang::Object  &object_0);
    static Optional empty();
    Optional filter(function::Predicate  &predicate_0);
    Optional map(function::Function  &function_0);
   }; // end class Optional

   namespace stream{
    
    class Stream : public ::crclj::java::lang::Object {
        public:
            Stream(jobject _jthis, bool copy);
            Stream(const Stream &);
            
     Stream();
     ~Stream();
     Stream distinct();
     jboolean allMatch(::crclj::java::util::function::Predicate  &predicate_0);
     Optional findFirst();
     jboolean anyMatch(::crclj::java::util::function::Predicate  &predicate_0);
     jboolean noneMatch(::crclj::java::util::function::Predicate  &predicate_0);
     static Stream iterate(::crclj::java::lang::Object  &object_0,::crclj::java::util::function::UnaryOperator  &unaryOperator_1);
     Optional findAny();
     Stream flatMap(::crclj::java::util::function::Function  &function_0);
     Stream sorted();
     Stream limit(jlong long_0);
     jlong count();
     static Stream concat(Stream  &stream_0,Stream  &stream_1);
     jobjectArray toArray();
     Stream skip(jlong long_0);
     static Stream of(jobjectArray objectArray_0);
     static Stream of(::crclj::java::lang::Object  &object_0);
     static Stream empty();
     Stream filter(::crclj::java::util::function::Predicate  &predicate_0);
     Stream map(::crclj::java::util::function::Function  &function_0);
    }; // end class Stream
   } // end namespace stream


   
   class Collection : public ::crclj::java::lang::Object {
       public:
           Collection(jobject _jthis, bool copy);
           Collection(const Collection &);
           
    Collection();
    ~Collection();
    jboolean add(::crclj::java::lang::Object  &object_0);
    jboolean remove(::crclj::java::lang::Object  &object_0);
    jboolean equals(::crclj::java::lang::Object  &object_0);
    jint hashCode();
    void clear();
    jboolean isEmpty();
    jboolean contains(::crclj::java::lang::Object  &object_0);
    jint size();
    jobjectArray toArray(jobjectArray objectArray_0);
    jobjectArray toArray();
    jboolean addAll(Collection  &collection_0);
    stream::Stream stream();
    jboolean containsAll(Collection  &collection_0);
    jboolean removeAll(Collection  &collection_0);
    jboolean retainAll(Collection  &collection_0);
    jboolean removeIf(function::Predicate  &predicate_0);
    stream::Stream parallelStream();
   }; // end class Collection

   namespace function{
    
    class Function : public ::crclj::java::lang::Object {
        public:
            Function(jobject _jthis, bool copy);
            Function(const Function &);
            
     Function();
     ~Function();
     Function compose(Function  &function_0);
     Function andThen(Function  &function_0);
     ::crclj::java::lang::Object apply(::crclj::java::lang::Object  &object_0);
     static Function identity();
    }; // end class Function
   } // end namespace function
  } // end namespace util
 } // end namespace java




// end namespace crclj
}

// end #ifndef crclj_h
#endif

