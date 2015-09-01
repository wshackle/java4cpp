/*
 * This software is public domain software, however it is preferred
 * that the following disclaimers be attached.
 * Software Copywrite/Warranty Disclaimer
 * 
 * This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. NIST Real-Time Control System software is an experimental
 * system. NIST assumes no responsibility whatsoever for its use by other
 * parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic. We would appreciate
 * acknowledgement if the software is used. This software can be
 * redistributed and/or modified freely provided that any derivative works
 * bear some notice that they are derived from it, and any modified
 * versions bear some notice that they have been modified.
 * 
 */
package crcl.utils;

import com.siemens.ct.exi.exceptions.EXIException;
import crcl.base.ActuateJointType;
import crcl.base.ActuateJointsType;
import crcl.base.AngleUnitEnumType;
import crcl.base.CRCLCommandInstanceType;
import crcl.base.CRCLCommandType;
import crcl.base.CRCLStatusType;
import crcl.base.CloseToolChangerType;
import crcl.base.CommandStateEnumType;
import crcl.base.CommandStatusType;
import crcl.base.ConfigureJointReportType;
import crcl.base.ConfigureJointReportsType;
import crcl.base.DwellType;
import crcl.base.EndCanonType;
import crcl.base.GetStatusType;
import crcl.base.InitCanonType;
import crcl.base.JointStatusType;
import crcl.base.JointStatusesType;
import crcl.base.LengthUnitEnumType;
import static crcl.base.LengthUnitEnumType.INCH;
import static crcl.base.LengthUnitEnumType.METER;
import static crcl.base.LengthUnitEnumType.MILLIMETER;
import crcl.base.MessageType;
import crcl.base.MoveScrewType;
import crcl.base.MoveThroughToType;
import crcl.base.MoveToType;
import crcl.base.OpenToolChangerType;
import crcl.base.PoseAndSetType;
import crcl.base.PoseType;
import crcl.base.PoseToleranceType;
import crcl.base.RotAccelAbsoluteType;
import crcl.base.RotAccelRelativeType;
import crcl.base.RotAccelType;
import crcl.base.RotSpeedAbsoluteType;
import crcl.base.RotSpeedRelativeType;
import crcl.base.RotSpeedType;
import crcl.base.SetAngleUnitsType;
import crcl.base.SetEndEffectorType;
import crcl.base.SetEndPoseToleranceType;
import crcl.base.SetIntermediatePoseToleranceType;
import crcl.base.SetLengthUnitsType;
import crcl.base.SetRotAccelType;
import crcl.base.SetRotSpeedType;
import crcl.base.SetTransAccelType;
import crcl.base.SetTransSpeedType;
import crcl.base.StopMotionType;
import crcl.base.TransAccelAbsoluteType;
import crcl.base.TransAccelRelativeType;
import crcl.base.TransAccelType;
import crcl.base.TransSpeedAbsoluteType;
import crcl.base.TransSpeedRelativeType;
import crcl.base.TransSpeedType;
import java.io.File;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.bind.JAXBException;
import javax.xml.datatype.DatatypeConfigurationException;
import javax.xml.datatype.DatatypeFactory;
import javax.xml.datatype.XMLGregorianCalendar;
import javax.xml.parsers.ParserConfigurationException;
import static crcl.utils.CRCLPosemath.maxDiffDoubleArray;
import static crcl.utils.CRCLPosemath.multiply;
import static crcl.utils.CRCLPosemath.pointToPmCartesian;
import static crcl.utils.CRCLPosemath.shift;
import static crcl.utils.CRCLPosemath.toPmRotationVector;
import static crcl.utils.CRCLPosemath.toPoseType;
import static crcl.utils.CRCLPosemath.vectorToPmCartesian;
import java.io.EOFException;
import java.io.PrintStream;
import java.net.SocketException;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.Optional;
import java.util.Set;
import org.xml.sax.SAXException;
import rcs.posemath.PmCartesian;
import rcs.posemath.PmException;
import rcs.posemath.PmRotationVector;
import rcs.posemath.Posemath;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class SimServerInner {

    private final static Set<SimServerInner> runningServers = new HashSet<>();

    private final XpathUtils xpu;
    private final SimServerOuter outer;
    Queue<CRCLCommandInstanceType> cmdQueue = new ConcurrentLinkedQueue<CRCLCommandInstanceType>();

    double[] jointPositions; // = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
    double[] lastJointPositions;// = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
    double[] commandedJointPositions;// = new double[]{0.0, 45.0, -90.0, 90.0, 0.0, 0.0};
    double[] jointVelocites;// = new double[jointPositions.length];
    double[] jointmins; // = new double[]{-170.0, 5.0, -170.0, +10.0, -135.0, -135.0};
    double[] jointmaxs;// = new double[]{+170.0, 85.0, -10.0, 170.0, +135.0, +135.0};
    double[] seglengths;// = SimulatedKinematicsPlausible.DEFAULT_SEGLENGTHS;

//    double[] jointPositions = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
//    double[] lastJointPositions = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
//    double[] commandedJointPositions = new double[]{0.0, 45.0, -90.0, 90.0, 0.0, 0.0};
//    double[] jointVelocites = new double[jointPositions.length];
//    double jointmins[] = new double[]{-170.0, 5.0, -170.0, +10.0, -135.0, -135.0};
//    double jointmaxs[] = new double[]{+170.0, 85.0, -10.0, 170.0, +135.0, +135.0};
//    double seglengths[] = SimulatedKinematicsPlausible.DEFAULT_SEGLENGTHS;
    private PoseType goalPose;

    private double maxTransSpeed = getDoubleProperty("SimServer.maxTransSpeed", 2.0);
    private double maxTransAccel = getDoubleProperty("SimServer.maxTransAccell", 2.0);

    private double curTransSpeed = 0;
    private double commandedTransSpeed = maxTransSpeed * 0.5;
    private double curTransAccel = 0;
    private double commandedTransAccel = maxTransAccel * 0.5;

    private double maxRotSpeed = getDoubleProperty("SimServer.maxRotSpeed", 2.0);
    private double maxRotAccel = getDoubleProperty("SimServer.maxRotAccell", 2.0);

    private double curRotSpeed = 0;
    private double commandedRotSpeed = maxRotSpeed * 0.5;
    private double curRotAccel = 0;
    private double commandedRotAccel = maxRotAccel * 0.5;

    private void resetToPlausibleDefaults() {
        jointPositions = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
        lastJointPositions = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
        commandedJointPositions = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
        jointVelocites = new double[jointPositions.length];
        jointmins = new double[]{-170.0, 5.0, -170.0, +10.0, -135.0, -135.0};
        jointmaxs = new double[]{+170.0, 85.0, -10.0, 170.0, +135.0, +135.0};
        seglengths = SimulatedKinematicsPlausible.DEFAULT_SEGLENGTHS;
    }

    private void resetToSimpleDefaults() {
        jointPositions = Arrays.copyOf(SimulatedKinematicsSimple.DEFAULT_JOINTVALS, SimulatedKinematicsSimple.DEFAULT_JOINTVALS.length);
        lastJointPositions = Arrays.copyOf(SimulatedKinematicsSimple.DEFAULT_JOINTVALS, SimulatedKinematicsSimple.DEFAULT_JOINTVALS.length);
        commandedJointPositions = Arrays.copyOf(SimulatedKinematicsSimple.DEFAULT_JOINTVALS, SimulatedKinematicsSimple.DEFAULT_JOINTVALS.length);;
        jointVelocites = new double[jointPositions.length];
        jointmins = null;// new double[]{-170.0, 5.0, -170.0, +10.0, -135.0, -135.0};
        jointmaxs = null;//new double[]{+170.0, 85.0, -10.0, 170.0, +135.0, +135.0};
        seglengths = SimulatedKinematicsSimple.DEFAULT_SEGLENGTHS;
    }

    private SimRobotEnum robotType = SimRobotEnum.SIMPLE;

    /**
     * Get the value of robotType
     *
     * @return the value of robotType
     */
    public SimRobotEnum getRobotType() {
        return robotType;
    }

    /**
     * Set the value of robotType
     *
     * @param robotType new value of robotType
     */
    public void setRobotType(SimRobotEnum robotType) {
        this.robotType = robotType;
        switch (robotType) {
            case PLAUSIBLE:
                resetToPlausibleDefaults();
                break;

            case SIMPLE:
                resetToSimpleDefaults();
                break;
        }
    }

    public SimServerInner(SimServerOuter _outer) throws ParserConfigurationException {
        this.outer = _outer;
        this.xpu = new XpathUtils();
        this.status = new CRCLStatusType();
        this.setRobotType(SimRobotEnum.SIMPLE);
        this.port = CRCLSocket.DEFAULT_PORT;
        String portPropertyString = System.getProperty("crcljava.port");
        if (null != portPropertyString) {
            this.setPort(Integer.valueOf(portPropertyString));
        }
    }

    public XpathUtils getXpu() {
        return xpu;
    }

    private int port;

    /**
     * Get the value of port
     *
     * @return the value of port
     */
    public int getPort() {
        return port;
    }

    public void simulatedTeleportToPose(PoseType pose) {
        switch (robotType) {
            case PLAUSIBLE:
                jointPositions = skPlausible.poseToJoints(this.jointPositions, pose);
                this.getStatus().setPose(skPlausible.jointsToPose(jointPositions, this.getStatus().getPose()));
                break;

            case SIMPLE:
                jointPositions = skSimple.poseToJoints(this.jointPositions, pose);
                this.getStatus().setPose(skSimple.jointsToPose(jointPositions, this.getStatus().getPose()));
                break;
        }
        commandedJointPositions = Arrays.copyOf(jointPositions, jointPositions.length);
        this.goalPose = null;
        this.setWaypoints(null);
        CommandStatusType cst = this.getStatus().getCommandStatus();
        if (cst == null) {
            cst = new CommandStatusType();
        }
        if (null == cst.getStatusID()) {
            cst.setStatusID(BigInteger.ONE);
        }
        setCommandState(CommandStateEnumType.DONE);
    }

    /**
     * Set the value of port
     *
     * @param port new value of port
     */
    public void setPort(int port) {
        this.port = port;
        if (null != this.ssock) {
            this.restartServer();
        }
    }

    private boolean moveStraight = false;

    /**
     * Get the value of moveStraight
     *
     * @return the value of moveStraight
     */
    public boolean isMoveStraight() {
        return moveStraight;
    }

    private ServerSocket ssock = null;
    private SimulatedKinematicsPlausible skPlausible = new SimulatedKinematicsPlausible();
    private SimulatedKinematicsSimple skSimple = new SimulatedKinematicsSimple();

    private CRCLStatusType status;

    private File[] statSchemaFiles = null;

    public void setJointPosition(double _position, int index) {
        this.jointPositions[index] = _position;
    }

    public void setCommandedJointPosition(double _position, int index) {
        this.commandedJointPositions[index] = _position;
    }

    public void reset() {
        jointPositions = Arrays.copyOf(SimulatedKinematicsPlausible.DEFAULT_JOINTVALS, SimulatedKinematicsPlausible.DEFAULT_JOINTVALS.length);
        switch (robotType) {
            case PLAUSIBLE:
                this.getStatus().setPose(skPlausible.jointsToPose(jointPositions, this.getStatus().getPose()));
                break;

            case SIMPLE:
                this.getStatus().setPose(skSimple.jointsToPose(jointPositions, this.getStatus().getPose()));
                break;
        }
        commandedJointPositions = Arrays.copyOf(jointPositions, jointPositions.length);
        this.goalPose = null;
        this.setWaypoints(null);
        CommandStatusType cst = this.getStatus().getCommandStatus();
        if (cst == null) {
            cst = new CommandStatusType();
        }
        if (null == cst.getStatusID()) {
            cst.setStatusID(BigInteger.ONE);
        }
        setCommandState(CommandStateEnumType.DONE);
    }

    public double[] getJointPositions() {
        return jointPositions;
    }

    public double[] getSeglengths() {
        return seglengths;
    }

    public void setGoalPose(PoseType goalPose) {
        this.goalPose = goalPose;
        if (null != goalPose) {
            checkPose(goalPose);
        }
    }

    private CRCLCommandType multiStepCommand = null;
    private int moveScrewStep = 0;

    public boolean isFinishedMove() {
        double jointdiffs[] = new double[this.jointPositions.length];
        Arrays.setAll(jointdiffs, (i) -> Math.abs(jointPositions[i] - commandedJointPositions[i]));
        double maxdiff = Arrays.stream(jointdiffs).max().orElse(0);
        if (maxdiff > getJointDiffMax()) {
            return false;
        }
        Arrays.setAll(jointdiffs, (i) -> Math.abs(jointPositions[i] - lastJointPositions[i]));
        maxdiff = Arrays.stream(jointdiffs).max().orElse(0);
        if (maxdiff > getJointDiffMax()) {
            return false;
        }
        return true;
    }

    private BigDecimal moveScriptTurnComplete = BigDecimal.ZERO;

    private boolean handleContinueMoveScrew(MoveScrewType moveScrew) {
        switch (moveScrewStep) {
            case 0:
                setCommandState(CommandStateEnumType.WORKING);
                if (moveScrew.getStartPosition() != null) {
                    goalPose = moveScrew.getStartPosition();
                    moveScrewStep = 1;
                } else {
                    moveScrewStep = 2;
                }
                break;

            case 1:
                if (isFinishedMove()) {
                    if (!PoseToleranceChecker.isInTolerance(status.getPose(), goalPose,
                            expectedEndPoseTolerance, angleType)) {
                        multiStepCommand = null;
                        setCommandState(CommandStateEnumType.ERROR);
                        return false;
                    }
                }
                break;

            case 2:
                if (moveScrew.getAxialDistanceFree() != null && moveScrew.getAxialDistanceFree().compareTo(BigDecimal.ZERO) > 0) {
                    goalPose = shift(status.getPose(),
                            multiply(moveScrew.getAxialDistanceFree(), status.getPose().getXAxis()));
                    setMoveStraight(true);
                    moveScrewStep = 3;
                } else {
                    moveScrewStep = 4;
                }
                break;

            case 3:
                if (isFinishedMove()) {
                    moveScrewStep = 4;
                }
                break;

            case 4:
                moveScriptTurnComplete = BigDecimal.ZERO;
                moveScrewStep = 5;
                break;

            case 5:
                multiStepCommand = null;
                setCommandState(CommandStateEnumType.DONE);
                return false;
        }
        return true;
//        setCommandState(CommandStateEnumType.DONE);
//        multiStepCommand = null;
//        return false;
    }

    private boolean handleMultiStepCommand() {
        if (null == multiStepCommand) {
            return false;
        }
        if (multiStepCommand instanceof MoveScrewType) {
            return handleContinueMoveScrew((MoveScrewType) multiStepCommand);
        }
        multiStepCommand = null;
        return false;
    }

    public void setCommandState(CommandStateEnumType state) {
        synchronized (status) {
            CommandStatusType cst = status.getCommandStatus();
            if (null == cst) {
                cst = new CommandStatusType();
                status.setCommandStatus(cst);
            }
            cst.setCommandState(state);
        }
    }

    public CommandStateEnumType getCommandState() {
        CommandStatusType cst = status.getCommandStatus();
        if (null == cst) {
            setCommandState(CommandStateEnumType.ERROR);
        }
        cst = status.getCommandStatus();
        return cst.getCommandState();
    }

    private void showMessage(String s) {
        outer.showMessage(s);
    }

    public boolean checkPose(PoseType goalPose) {
        PmCartesian xvec = vectorToPmCartesian(goalPose.getXAxis());
        if (Math.abs(xvec.mag() - 1.0) > 1e-3) {
            showMessage("Bad postion : xvec " + xvec + " has magnitude not equal to one.");
            setCommandState(CommandStateEnumType.ERROR);
            return false;
        }
        PmCartesian zvec = vectorToPmCartesian(goalPose.getZAxis());
        if (Math.abs(zvec.mag() - 1.0) > 1e-3) {
            showMessage("Bad postion : zvec " + zvec + " has magnitude not equal to one.");
            setCommandState(CommandStateEnumType.ERROR);
            return false;
        }
        if (Math.abs(Posemath.pmCartCartDot(xvec, zvec)) > 1e-3) {
            showMessage("Bad postion : xvec " + xvec + " and zvec " + zvec + " are not orthogonal.");
            setCommandState(CommandStateEnumType.ERROR);
            return false;
        }
        return true;
    }

    private static double getDoubleProperty(String propName, double defaultVal) {
        return Double.valueOf(System.getProperty(propName, Double.toString(defaultVal)));
    }

    public double getJointSpeedMax() {
        return jointSpeedMax;
    }

    public void setJointSpeedMax(double jointSpeedMax) {
        this.jointSpeedMax = jointSpeedMax;
    }

    private double jointSpeedMax = getDoubleProperty("SimServer.jointSpeedMax", 200.0);

    public PoseType limitSpeedAccel(PoseType goal,
            PoseType current) {
        PoseType newGoal = goal;
        try {
            PmCartesian goalPt = pointToPmCartesian(goalPose.getPoint());
            PmCartesian currentPt = pointToPmCartesian(current.getPoint());
            PmCartesian diffPt = goalPt.subtract(currentPt);
            double lastTransSpeed = this.curTransSpeed;
            double diffTransSpeed = diffPt.mag() / (delayMillis * 1e-3);
            this.curTransSpeed = diffTransSpeed;
            this.curTransAccel = this.curTransSpeed - lastTransSpeed;
            if (Math.abs(curTransAccel) > this.commandedTransAccel) {
                this.curTransSpeed = lastTransSpeed
                        + Math.signum(curTransAccel) * this.commandedTransAccel;
            }
            if (this.curTransSpeed > this.commandedTransSpeed) {
                this.curTransSpeed = this.commandedTransSpeed;
            }
            PmRotationVector goalRotv = toPmRotationVector(goalPose);
            PmRotationVector currentRotv = toPmRotationVector(current);
            PmRotationVector diffRotv = goalRotv.multiply(currentRotv.inv());
            double lastRotSpeed = this.curRotSpeed;
            double diffRotSpeed = diffRotv.s / (delayMillis * 1e-3);
            this.curRotSpeed = diffRotSpeed;
            this.curRotAccel = this.curRotSpeed - lastRotSpeed;
            if (Math.abs(curRotAccel) > this.commandedRotAccel) {
                this.curRotSpeed = lastRotSpeed
                        + Math.signum(curRotAccel) * this.commandedRotAccel;
            }
            if (this.curRotSpeed > this.commandedRotSpeed) {
                this.curRotSpeed = this.commandedRotSpeed;
            }
            double transMoveFraction = 1.0;
            if (Math.abs(diffTransSpeed - this.curTransSpeed) > this.commandedTransSpeed * 0.1
                    && Math.abs(diffTransSpeed) > 1e-6) {
                transMoveFraction = curTransSpeed / diffTransSpeed;
            }
            double rotMoveFraction = 1.0;
            if (Math.abs(diffRotSpeed - this.curRotSpeed) > this.commandedRotSpeed * 0.1
                    && Math.abs(diffRotSpeed) > 1e-6) {
                rotMoveFraction = curRotSpeed / diffRotSpeed;
            }
            double moveFraction = Math.min(transMoveFraction, rotMoveFraction);
            assert (moveFraction > 0);
            if (moveFraction < 0.99) {
                PmCartesian newGoalPt = currentPt.add(diffPt.multiply(moveFraction));
                PmRotationVector newGoalRotv = currentRotv.multiply(diffRotv.multiply(moveFraction));
                newGoal = toPoseType(newGoalPt, newGoalRotv);
            }
        } catch (PmException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            outer.showMessage(ex.toString());
        }
        return newGoal;
    }

    private static final Logger LOGGER = Logger.getLogger(SimServerInner.class.getName());

    ;

    public double[] getStraightMoveCommandedJointVals(PoseType curGoalPose) {
        try {
            final double JOINT_DIFF_MAX = getJointDiffMax();
            PmCartesian goalPt = pointToPmCartesian(curGoalPose.getPoint());
            PmCartesian currentPt = pointToPmCartesian(status.getPose().getPoint());
            PmCartesian diffPt = goalPt.subtract(currentPt);
            PmRotationVector goalRotv = toPmRotationVector(curGoalPose);
            PmRotationVector currentRotv = toPmRotationVector(status.getPose());
            PmRotationVector diffRotv = goalRotv.multiply(currentRotv.inv());
            PoseType newGoalPose = curGoalPose;
            goalPoseToCommandedPositions(newGoalPose);
            double maxdiff = maxDiffDoubleArray(this.commandedJointPositions, this.jointPositions);
            double scale = 1.0;
            while (maxdiff > JOINT_DIFF_MAX) {
                scale *= JOINT_DIFF_MAX / (maxdiff + 0.01);
                PmCartesian scaledDiffPt = diffPt.multiply(scale);
                PmCartesian newGoalPt = currentPt.add(scaledDiffPt);
                PmRotationVector scaledDiffRot = diffRotv.multiply(scale);
                PmRotationVector newGoalRotv = currentRotv.multiply(scaledDiffRot);
                newGoalPose = toPoseType(newGoalPt, newGoalRotv);
                this.goalPoseToCommandedPositions(newGoalPose);
                maxdiff = maxDiffDoubleArray(this.commandedJointPositions, this.jointPositions);
            }
        } catch (PmException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return this.commandedJointPositions;
    }

    private int cycle_count = 0;

    public void setCmdSchema(File[] fa) {
        try {
            fa = CRCLSocket.reorderCommandSchemaFiles(fa);
            CRCLSocket.defaultCmdSchema = CRCLSocket.filesToSchema(fa);
            for (ClientState state : this.clientStates) {
                state.getCs().setCmdSchema(CRCLSocket.defaultCmdSchema);
            }
        } catch (SAXException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public void setStatSchema(File[] fa) {
        try {
            fa = CRCLSocket.reorderStatSchemaFiles(fa);
            CRCLSocket.defaultStatSchema = CRCLSocket.filesToSchema(fa);
            for (ClientState state : this.clientStates) {
                state.getCs().setStatSchema(CRCLSocket.defaultStatSchema);
            }
            this.statSchemaFiles = fa;
            xpu.setSchemaFiles(statSchemaFiles);
        } catch (SAXException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public synchronized void setStatus(CRCLStatusType status) {
        this.status = status;
    }

    private List<ClientState> clientStates = new ArrayList<>();
    private Map<CRCLSocket, Thread> clientThreadMap = new HashMap<>();

    /**
     * Set the value of moveStraight
     *
     * @param moveStraight new value of moveStraight
     */
    public void setMoveStraight(boolean moveStraight) {
        this.moveStraight = moveStraight;
    }

    Thread simThread = null;

    private volatile int close_count = 0;

    public void closeServer() {
        try {
            SimServerInner.runningServers.remove(this);
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.close_count++;
//        System.out.println("close_count = " + close_count);
        if (null != acceptClientsThread) {
            try {
                acceptClientsThread.interrupt();
                acceptClientsThread.join(100);
                acceptClientsThread = null;
            } catch (InterruptedException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
        if (null != simThread) {
            try {
                simThread.interrupt();
                simThread.join(100);
            } catch (InterruptedException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
            simThread = null;
        }
        if (null != clientStates) {
            for (ClientState s : clientStates) {
                try {
                    s.close();
                } catch (Exception ex) {
                    LOGGER.log(Level.SEVERE, null, ex);
                }
            }
            clientStates.removeAll(clientStates);
        }
        if (null != ssock) {
            try {
                this.ssock.close();
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
            this.ssock = null;
        }
        this.updateConnectedClients();
        this.lastStatusMap = null;
    }

    BigInteger maxCmdId = BigInteger.ONE;

    private static class LastStatusInfo {

        BigInteger lastSentCid = null;
        CommandStateEnumType lastSentState = null;
    };

    Map<CRCLSocket, LastStatusInfo> lastStatusMap = null;

    private void sendStatus(CRCLSocket socket) {
        CRCLSocket curSocket = socket;
        try {
            if (null == socket) {
                if (!outer.isSendStatusWithoutRequestSelected()
                        || null == clientStates
                        || clientStates.size() < 1) {
                    return;
                }
            }
            synchronized (status) {
                CommandStatusType cst = status.getCommandStatus();
                if (null == cst) {
                    cst = new CommandStatusType();
                    status.setCommandStatus(cst);
                }
                if (null == getCommandState()) {
                    setCommandState(CommandStateEnumType.WORKING);
                }
                BigInteger sid = cst.getStatusID();
                if (sid == null) {
                    cst.setStatusID(BigInteger.ONE);
                }
                BigInteger cid = cst.getCommandID();
                if (cid == null) {
                    cst.setCommandID(BigInteger.ONE);
                }
//            outer.showDebugMessage("status="+CRCLSocket.statToDebugString(status));
                if (null != socket) {
                    try {
                        socket.appendTrailingZero = outer.isAppendZeroSelected();
                        socket.randomPacketing = outer.isRandomPacketSelected();
                        socket.setReplaceHeader(outer.isReplaceXmlHeaderSelected());
                        if (outer.isReplaceStateSelected()) {
                            socket.setStatusStringOutputFilter(CRCLSocket.removeCRCLFromState);
                        } else {
                            socket.setStatusStringOutputFilter(null);
                        }
                        boolean new_state = true;
                        if (null != this.lastStatusMap) {
                            LastStatusInfo lsi = this.lastStatusMap.get(socket);
                            new_state = (null == lsi
                                    || null == lsi.lastSentCid
                                    || null == lsi.lastSentState
                                    || !lsi.lastSentCid.equals(status.getCommandStatus().getCommandID())
                                    || !lsi.lastSentState.equals(status.getCommandStatus().getCommandState()));
                        }
                        if (outer.isDebugSendStatusSelected() && new_state) {
                            outer.showDebugMessage("Status sent to " + socket.getInetAddress() + ":" + socket.getPort()
                                    + " CommandId="
                                    + status.getCommandStatus().getCommandID()
                                    + " StatusId="
                                    + status.getCommandStatus().getStatusID()
                                    + " State="
                                    + status.getCommandStatus().getCommandState());
                        }
                        socket.writeStatus(status, outer.isValidateXMLSelected());
                        if (outer.isDebugSendStatusSelected() && new_state) {
                            outer.showDebugMessage("writeStatus Complete");
                        }
                        if (new_state) {
                            if (null == this.lastStatusMap) {
                                this.lastStatusMap = new IdentityHashMap<>();
                            }
                            LastStatusInfo lsi = new LastStatusInfo();
                            lsi.lastSentCid = status.getCommandStatus().getCommandID();
                            lsi.lastSentState = status.getCommandStatus().getCommandState();
                            this.lastStatusMap.put(socket, lsi);
                        }
                    } catch (IOException ex) {
                        LOGGER.log(Level.SEVERE, null, ex);
                        try {
                            socket.close();
                        } catch (IOException ex1) {
                            LOGGER.log(Level.SEVERE, null, ex1);
                        }
                        this.clientStates.remove(socket);
//                    showMessage(ex);
                    } catch (InterruptedException | EXIException ex) {
                        LOGGER.log(Level.SEVERE, null, ex);
                    }
                    return;
                }
                curSocket = clientStates.get(0).getCs();
                if (outer.isReplaceStateSelected()) {
                    curSocket.setStatusStringOutputFilter(CRCLSocket.removeCRCLFromState);
                } else {
                    curSocket.setStatusStringOutputFilter(null);
                }
                boolean new_state = true;
                if (null != this.lastStatusMap) {
                    LastStatusInfo lsi = this.lastStatusMap.get(curSocket);
                    new_state = (null == lsi
                            || null == lsi.lastSentCid
                            || null == lsi.lastSentState
                            || !lsi.lastSentCid.equals(status.getCommandStatus().getCommandID())
                            || !lsi.lastSentState.equals(status.getCommandStatus().getCommandState()));
                }
                if (outer.isDebugSendStatusSelected() && new_state) {
                    outer.showDebugMessage("Status sent to " + socket.getInetAddress() + ":" + socket.getPort()
                            + " CommandId="
                            + status.getCommandStatus().getCommandID()
                            + " StatusId="
                            + status.getCommandStatus().getStatusID()
                            + " State="
                            + status.getCommandStatus().getCommandState());
                }
                String xmls = curSocket.statusToString(status, outer.isValidateXMLSelected());
//            System.out.println("SimServer.sendStatus() : xmls = " + xmls);
//            String strout = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"+xmls;

//            byte ba[] = xmls.getBytes();
//            byte fill[] = new byte[2000];
                int write_count = 0;
                for (int i = 0; i < clientStates.size(); i++) {
                    curSocket = clientStates.get(i).getCs();

                    try {
                        curSocket.appendTrailingZero = outer.isAppendZeroSelected();
                        curSocket.randomPacketing = outer.isRandomPacketSelected();
                        curSocket.setReplaceHeader(outer.isReplaceXmlHeaderSelected());
                        curSocket.writeWithFill(xmls);
                        write_count++;
                    } catch (IOException ex) {
                        try {
                            LOGGER.log(Level.SEVERE, null, ex);
                            clientStates.remove(i);
                            Thread t = clientThreadMap.get(curSocket);
                            t.interrupt();
                            t.join(100);
                            clientThreadMap.remove(curSocket);
                            updateConnectedClients();
                        } catch (InterruptedException ex1) {
                            LOGGER.log(Level.SEVERE, null, ex1);
                        }
                    } catch (InterruptedException ex) {
                        LOGGER.log(Level.SEVERE, null, ex);
                    }
                }
                if (outer.isDebugSendStatusSelected() && new_state) {
                    outer.showDebugMessage("writeStatus  to " + write_count + " clients complete.");
                }
                if (new_state) {
                    if (null == this.lastStatusMap) {
                        this.lastStatusMap = new IdentityHashMap<>();
                    }
                    LastStatusInfo lsi = new LastStatusInfo();
                    lsi.lastSentCid = status.getCommandStatus().getCommandID();
                    lsi.lastSentState = status.getCommandStatus().getCommandState();
                    this.lastStatusMap.put(socket, lsi);
                }
            }
//            System.out.println("SimServer.sendStatus() sent data to " + write_count + " clients.");
        } catch (JAXBException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage(ex + "\n" + ((curSocket != null) ? curSocket.getLastStatusString() : ""));
        }
    }

    private boolean isCoordinated(PoseType pose) {
        if (pose instanceof PoseAndSetType) {
            PoseAndSetType pas = (PoseAndSetType) pose;
            return pas.isCoordinated();
        }
        return false;
    }

    public XMLGregorianCalendar getXMLGregorianCalendarNow()
            throws DatatypeConfigurationException {
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        DatatypeFactory datatypeFactory = DatatypeFactory.newInstance();
        XMLGregorianCalendar now
                = datatypeFactory.newXMLGregorianCalendar(gregorianCalendar);
        return now;
    }

    private boolean executingMoveCommand = false;

    private synchronized void incStatusId() {
        synchronized (status) {
            CommandStatusType cst = status.getCommandStatus();
            if (null != cst) {
                cst.setStatusID(
                        Optional.ofNullable(cst.getStatusID())
                        .orElse(BigInteger.ZERO)
                        .add(BigInteger.ONE)
                );
            }
        }
    }

    /**
     *
     * @return the boolean
     */
    private synchronized boolean updateStatus() {
        boolean jointschanged = false;
        synchronized (status) {
            if (!outer.isEditingStatus()) {
                if (null == status.getCommandStatus()) {
                    CommandStatusType cst = new CommandStatusType();
                    cst.setCommandID(BigInteger.ONE);
                    cst.setStatusID(BigInteger.ONE);
                    cst.setCommandState(CommandStateEnumType.WORKING);
                    status.setCommandStatus(new CommandStatusType());
                }
                this.incStatusId();
                if (null == goalPose
                        && null != waypoints
                        && this.currentWaypoint < waypoints.size() - 1) {
                    int new_waypoint = this.currentWaypoint + 1;
                    this.setCurrentWaypoint(new_waypoint);
                    this.goalPose = this.waypoints.get(this.currentWaypoint);
                }
                if (null != goalPose) {
                    PoseType curGoalPose = this.limitSpeedAccel(goalPose, status.getPose());
                    if (this.moveStraight || isCoordinated(goalPose)) {
                        this.commandedJointPositions = getStraightMoveCommandedJointVals(curGoalPose);
                    } else {
                        goalPoseToCommandedPositions(curGoalPose);
                    }
                }
                final double JOINT_DIFF_MAX = getJointDiffMax();
                for (int i = 0; i < jointPositions.length; i++) {
                    if (Math.abs(commandedJointPositions[i] - jointPositions[i]) < JOINT_DIFF_MAX) {
                        if (Math.abs(commandedJointPositions[i] - jointPositions[i]) > 1e-4) {
                            jointschanged = true;
                        }
                        jointPositions[i] = commandedJointPositions[i];

                    } else {
                        jointPositions[i] += JOINT_DIFF_MAX * Math.signum(commandedJointPositions[i] - jointPositions[i]);
                        jointschanged = true;
                    }
                    if (jointmins != null && jointmins.length > i && jointPositions[i] < jointmins[i]) {
                        goalPose = null;
                        setCommandState(CommandStateEnumType.ERROR);
                        showMessage("Joint " + (i + 1) + " at " + jointPositions[i] + " less than limit " + jointmins[i]);
                        jointPositions[i] = jointmins[i];
                        commandedJointPositions[i] = jointPositions[i];
                    }
                    if (jointmaxs != null && jointmaxs.length > i && jointPositions[i] > jointmaxs[i]) {
                        goalPose = null;
                        setCommandState(CommandStateEnumType.ERROR);
                        showMessage("Joint " + (i + 1) + " at " + jointPositions[i] + " more than limit " + jointmaxs[i]);
                        jointPositions[i] = jointmaxs[i];
                        commandedJointPositions[i] = jointPositions[i];
                    }
                    jointVelocites[i] = (jointPositions[i] - lastJointPositions[i]) / (1000.0 * delayMillis);
                    lastJointPositions[i] = jointPositions[i];
                    JointStatusesType jsst = status.getJointStatuses();
                    if (null == jsst) {
                        jsst = new JointStatusesType();
                        status.setJointStatuses(jsst);
                    }
                    List<JointStatusType> jsl = jsst.getJointStatus();
                    JointStatusType js = null;
                    if (i < jsl.size()) {
                        js = jsl.get(i);
                    }
                    if (null == js) {
                        js = new JointStatusType();
                        jsl.add(i, js);
                    }
                    js.setJointNumber(BigInteger.valueOf(i + 1));
                    js.setJointPosition(BigDecimal.valueOf(jointPositions[i]));
                    if (null != cjrList && cjrList.size() > 0) {
                        js.setJointPosition(null);
                        js.setJointVelocity(null);
                        js.setJointTorqueOrForce(null);
                        for (ConfigureJointReportType cjrt : this.cjrList) {
                            if (cjrt.getJointNumber().compareTo(js.getJointNumber()) == 0) {
                                if (cjrt.isReportPosition()) {
                                    js.setJointPosition(BigDecimal.valueOf(jointPositions[i]));
                                }
                                if (cjrt.isReportVelocity()) {
                                    js.setJointVelocity(BigDecimal.valueOf(jointVelocites[i]));
                                }
                                if (cjrt.isReportTorqueOrForce()) {
                                    js.setJointTorqueOrForce(BigDecimal.TEN);
                                }
                            }
                        }
                    } else {
                        js.setJointPosition(BigDecimal.valueOf(jointPositions[i]));
                    }
                }
                if (jointschanged || null == status.getPose()) {
                    switch (robotType) {
                        case PLAUSIBLE:
                            status.setPose(skPlausible.jointsToPose(jointPositions, status.getPose()));
                            break;

                        case SIMPLE:
                            status.setPose(skSimple.jointsToPose(jointPositions, status.getPose()));
                            break;
                    }
//                try {
////                    status.getPose().setTimestamp(getXMLGregorianCalendarNow());
//                } catch (DatatypeConfigurationException ex) {
//                    LOGGER.log(Level.SEVERE, null, ex);
//                }
                }
                outer.updatePanels(jointschanged);
                if (!jointschanged
                        && this.getCommandState() == CommandStateEnumType.WORKING
                        && executingMoveCommand) {
                    if (null == goalPose
                            || null == this.waypoints
                            || this.currentWaypoint >= this.waypoints.size()) {
                        setCommandState(CommandStateEnumType.DONE);
                        if (outer.isDebugMoveDoneSelected()) {
                            outer.showDebugMessage("SimServerInner DONE move command: " + status.getCommandStatus().getCommandID());
                            outer.showDebugMessage("SimServerInner jointpositions = " + Arrays.toString(jointPositions));
                        }
                        this.setMoveStraight(false);
                        this.setWaypoints(null);
                    } else {
                        goalPose = null;
                    }
                }
                cycle_count++;
            }
        }
        return false;
    }

    private double getJointDiffMax() {
        return jointSpeedMax * delayMillis * 1e-3;
    }

    /**
     *
     * @param _goalPose the value of _goalPose
     */
    public void goalPoseToCommandedPositions(PoseType _goalPose) {
        switch (robotType) {
            case PLAUSIBLE:
                this.commandedJointPositions = skPlausible.poseToJoints(this.commandedJointPositions, _goalPose);
                break;

            case SIMPLE:
                this.commandedJointPositions = skSimple.poseToJoints(this.commandedJointPositions, _goalPose);
                break;
        }
    }
    private int currentWaypoint;

    /**
     * Get the value of currentWaypoint
     *
     * @return the value of currentWaypoint
     */
    public int getCurrentWaypoint() {
        return currentWaypoint;
    }

    /**
     * Set the value of currentWaypoint
     *
     * @param currentWaypoint new value of currentWaypoint
     */
    public void setCurrentWaypoint(int currentWaypoint) {
        this.currentWaypoint = currentWaypoint;
        outer.finishSetCurrentWaypoint(currentWaypoint);
    }

    public void printClientStates(final PrintStream ps) {
        if (null != clientStates) {
            clientStates.forEach(ps::println);
        }
        if (null != this.cmdQueue) {
            ps.println("cmdQueue.peek() = " + cmdQueue.peek());
        }
    }

    static public void printAllClientStates(final PrintStream ps) {
        SimServerInner.runningServers.forEach(s -> s.printClientStates(ps));
    }

    private final boolean enableGetStatusIDCheck
            = Boolean.valueOf(System.getProperty("crcl.utils.SimServerInner.enableGetStatusIDCheck", "false"));

    private void readCommandsRepeatedly(ClientState state) {
        final int start_close_count = this.close_count;
        final CRCLSocket cs = state.getCs();
        try {
            while (!Thread.currentThread().isInterrupted()) {
                final CRCLCommandInstanceType cmdInstance
                        = cs.readCommand(outer.isValidateXMLSelected());
                LOGGER.log(Level.FINER, () -> "cmdInstance = " + cmdInstance);
                if (null != cmdInstance && null != cmdInstance.getCRCLCommand()) {
                    CRCLCommandType cmd = cmdInstance.getCRCLCommand();
                    LOGGER.log(Level.FINEST, () -> "SimServerInner.readCommandsRepeatedly() : cmd = " + cmd+ ", state="+state);
                    if (cmd instanceof GetStatusType) {
                        state.getStatusRequests++;
                        state.lastStatRequestTime = System.currentTimeMillis();
                        GetStatusType getStatus = (GetStatusType) cmd;
                        if (outer.isDebugReadCommandSelected() && !getStatus.getCommandID().equals(state.getStatusCmdId)) {
                            outer.showDebugMessage("SimServerInner.readCommandsRepeatedly() :  (getStatus=" + getStatus + " ID=" + getStatus.getCommandID() + ") state = " + state);
                        }
                        state.getStatusCmdId = getStatus.getCommandID();
                        if (enableGetStatusIDCheck
                                && !state.getStatusCmdId.equals(state.cmdId)) {
                            LOGGER.log(Level.SEVERE,
                                    "SimServerInner.readCommandsRepeatedly() : state.getStatusCmdId="
                                    + state.getStatusCmdId + ", state.cmdId = " + state.cmdId
                                    + ",status=" + CRCLSocket.statToDebugString(status));
                            LOGGER.setLevel(Level.OFF);
                            new Thread(() -> closeServer()).start();
                            return;
                        }
                        synchronized (status) {
                            CommandStatusType cst = status.getCommandStatus();
                            if (null == cst) {
                                cst = new CommandStatusType();
                                setCommandState(CommandStateEnumType.WORKING);
                                cst.setCommandID(cmd.getCommandID());
                                cst.setStatusID(BigInteger.ONE);
                                status.setCommandStatus(cst);
                            }
                            SimServerInner.this.sendStatus(cs);
                        }
                        continue;
                    }
                    state.cmdsRecieved++;
                    state.lastCmdTime = System.currentTimeMillis();
                    state.cmdId = cmdInstance.getCRCLCommand().getCommandID();
                    if (outer.isDebugReadCommandSelected()) {
                        outer.showDebugMessage("SimServerInner.readCommandsRepeatedly() : cmdInstance.getCRCLCommand() = " + cmdInstance.getCRCLCommand()
                                + " cmdInstance.getCRCLCommand().getCommandID() = " + cmdInstance.getCRCLCommand().getCommandID() + ", state=" + state);
                    }
                    SimServerInner.this.cmdQueue.offer(cmdInstance);
                }
            }
        } catch (SocketException se) {
            try {
                cs.close();
            } catch (IOException ex1) {
                LOGGER.log(Level.SEVERE, null, ex1);
            }
            this.clientStates.remove(state);
            return;
        } catch (JAXBException | IllegalStateException ex) {
//            System.err.println("ex.getCause() ="+ex.getCause());
//            if(null != ex.getCause()) {
//                System.err.println("ex.getCause().getCause()="+ex.getCause().getCause());
//            }
//            System.out.println("start_close_count = " + start_close_count);
//            System.out.println("close_count = " + close_count);
            if (ex.getCause() instanceof EOFException) {
                try {
                    cs.close();
                } catch (IOException ex1) {
                    LOGGER.log(Level.SEVERE, null, ex1);
                }
                this.clientStates.remove(state);
                return;
            }
            if (null != ex.getCause() && ex.getCause().getCause() instanceof EOFException) {
                try {
                    cs.close();
                } catch (IOException ex1) {
                    LOGGER.log(Level.SEVERE, null, ex1);
                }
                this.clientStates.remove(state);
                return;
            }
//            System.out.println("start_close_count = " + start_close_count);
//            System.out.println("close_count = " + close_count);
            if (close_count <= start_close_count) {
                System.err.println("String to parse was:" + cs.getLastCommandString());
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex.toString() + "\nString to parse was:" + cs.getLastCommandString());
            }
        } catch (IOException ex) {
//            System.out.println("start_close_count = " + start_close_count);
//            System.out.println("close_count = " + close_count);
            if (close_count <= start_close_count) {
                String str = cs.getReadInProgressString();
                if (str.length() == 0) {
                    return;
                }
                LOGGER.log(Level.SEVERE, "ReadInProgressString:" + str);
                LOGGER.log(Level.SEVERE, null, ex);
            }
            try {
                cs.close();
            } catch (IOException ex1) {
                LOGGER.log(Level.SEVERE, null, ex1);
            }
            this.clientStates.remove(state);
        } catch (EXIException ex) {
            System.err.println("ex.getCause() =" + ex.getCause());
//            System.out.println("start_close_count = " + start_close_count);
//            System.out.println("close_count = " + close_count);
            if (ex.getCause() instanceof EOFException) {
                try {
                    cs.close();
                } catch (IOException ex1) {
                    LOGGER.log(Level.SEVERE, null, ex1);
                }
                this.clientStates.remove(state);
                return;
            }
            if (close_count <= start_close_count) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
    }

    private static class ClientState implements AutoCloseable {

        private final CRCLSocket cs;
        public int getStatusRequests = 0;
        public int cmdsRecieved = 0;
        public long lastCmdTime = 0;
        public long lastStatRequestTime = 0;
        BigInteger getStatusCmdId = null;
        BigInteger cmdId = null;

        public ClientState(CRCLSocket cs) {
            this.cs = cs;
        }

        @Override
        public void close() throws Exception {
            cs.close();
        }

        public CRCLSocket getCs() {
            return cs;
        }

        @Override
        public String toString() {
            return "ClientState{" + "cs=" + cs + ", getStatusRequests=" + getStatusRequests + ", cmdsRecieved=" + cmdsRecieved + ", lastCmdTime=" + lastCmdTime + ", lastStatRequestTime=" + lastStatRequestTime + ", getStatusCmdId=" + getStatusCmdId + ", cmdId=" + cmdId + '}';
        }

    }

    public void runAcceptClients() {
        final int start_close_count = this.close_count;
        while (!Thread.currentThread().isInterrupted()) {
            try {
                final Socket s = ssock.accept();
                final CRCLSocket cs = new CRCLSocket(s);
                final ClientState state = new ClientState(cs);
                cs.setEXIEnabled(outer.isEXISelected());
                clientStates.add(state);
                Thread t = new Thread(() -> readCommandsRepeatedly(state),
                        "client" + s.getInetAddress().toString() + ":" + s.getPort()
                );
                clientThreadMap.put(cs, t);
                t.start();
                this.updateConnectedClients();
            } catch (SocketException ex) {
                if (close_count <= start_close_count) {
                    LOGGER.log(Level.SEVERE, null, ex);
                }
            } catch (IOException | EXIException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
    }
    Thread acceptClientsThread = null;

    private static long getLongProperty(String propName, long defaultLong) {
        return Long.valueOf(System.getProperty(propName, Long.toString(defaultLong)));
    }

    private long delayMillis = getLongProperty("SimServer.delayMillis", 100);

    public double getCurTransSpeed() {
        return curTransSpeed;
    }

    public void setCurTransSpeed(double curTransSpeed) {
        this.curTransSpeed = curTransSpeed;
    }

    public double getCommandedTransSpeed() {
        return commandedTransSpeed;
    }

    public void setCommandedTransSpeed(double commandedTransSpeed) {
        this.commandedTransSpeed = commandedTransSpeed;
    }

    public double getCurTransAccel() {
        return curTransAccel;
    }

    public void setCurTransAccel(double curTransAccel) {
        this.curTransAccel = curTransAccel;
    }

    public double getCommandedTransAccel() {
        return commandedTransAccel;
    }

    public void setCommandedTransAccel(double commandedTransAccel) {
        this.commandedTransAccel = commandedTransAccel;
    }

    public double getCurRotSpeed() {
        return curRotSpeed;
    }

    public void setCurRotSpeed(double curRotSpeed) {
        this.curRotSpeed = curRotSpeed;
    }

    public double getCommandedRotSpeed() {
        return commandedRotSpeed;
    }

    public void setCommandedRotSpeed(double commandedRotSpeed) {
        this.commandedRotSpeed = commandedRotSpeed;
    }

    public double getCurRotAccel() {
        return curRotAccel;
    }

    public void setCurRotAccel(double curRotAccel) {
        this.curRotAccel = curRotAccel;
    }

    public double getCommandedRotAccel() {
        return commandedRotAccel;
    }

    public void setCommandedRotAccel(double commandedRotAccel) {
        this.commandedRotAccel = commandedRotAccel;
    }

    /**
     * Get the value of delayMillis
     *
     * @return the value of delayMillis
     */
    public long getDelayMillis() {
        return delayMillis;
    }

    /**
     * Set the value of delayMillis
     *
     * @param delay_millis new value of delayMillis
     */
    public void setDelayMillis(long delay_millis) {
        this.delayMillis = delay_millis;
    }

    private static final double SCALE_FUDGE_FACTOR = 0.5;

    private ConfigureJointReportsType cjr = null;
    private List<ConfigureJointReportType> cjrList = null;

    private AngleUnitEnumType angleType = AngleUnitEnumType.RADIAN;

    /**
     * Get the value of angleType
     *
     * @return the value of angleType
     */
    public AngleUnitEnumType getAngleType() {
        return angleType;
    }

    public void setAngleType(AngleUnitEnumType newAngleType) {
        this.angleType = newAngleType;
    }

    private PoseToleranceType expectedEndPoseTolerance = new PoseToleranceType();

    /**
     * Get the value of expectedEndPoseTolerance
     *
     * @return the value of expectedEndPoseTolerance
     */
    public PoseToleranceType getExpectedEndPoseTolerance() {
        return expectedEndPoseTolerance;
    }

    /**
     * Set the value of expectedEndPoseTolerance
     *
     * @param expectedEndPoseTolerance new value of expectedEndPoseTolerance
     */
    public void setExpectedEndPoseTolerance(PoseToleranceType expectedEndPoseTolerance) {
        this.expectedEndPoseTolerance = expectedEndPoseTolerance;
    }

    private PoseToleranceType expectedIntermediatePoseTolerance;

    /**
     * Get the value of expectedIntermediatePoseTolerance
     *
     * @return the value of expectedIntermediatePoseTolerance
     */
    public PoseToleranceType getExpectedIntermediatePoseTolerance() {
        return expectedIntermediatePoseTolerance;
    }

    /**
     * Set the value of expectedIntermediatePoseTolerance
     *
     * @param expectedIntermediatePoseToleranceType new value of
     * expectedIntermediatePoseTolerance
     */
    public void setExpectedIntermediatePoseTolerance(PoseToleranceType expectedIntermediatePoseToleranceType) {
        this.expectedIntermediatePoseTolerance = expectedIntermediatePoseToleranceType;
    }

    public void updateConnectedClients() {
        outer.updateConnectedClients(Math.max(clientStates.size(), clientThreadMap.size()));
    }

    private long dwellEndTime = 0;

    private void readCommand() {
        if (dwellEndTime > 0 && System.currentTimeMillis() < dwellEndTime) {
//            System.out.println("Dwelling");
//            System.out.println("dwellEndTime = " + dwellEndTime);
//            System.out.println("System.currentTimeMillis() = " + System.currentTimeMillis());
//            System.out.println("(dwellEndTime - System.currentTimeMillis()) = " + (dwellEndTime - System.currentTimeMillis()));
//            System.out.println("getCommandState() = " + getCommandState());
//            System.out.println("status.getCommandStatus().getCommandID() = " + status.getCommandStatus().getCommandID());
            return;
        }
        if (dwellEndTime > 0) {
            setCommandState(CommandStateEnumType.DONE);
            dwellEndTime = 0;
            return;
        }
        CRCLCommandInstanceType instance = cmdQueue.poll();
        while (null != instance) {
            CRCLCommandType cmd = instance.getCRCLCommand();
            if (null == cmd) {
                System.err.println("cmd is null");
                return;
            }
            if (outer.isDebugReadCommandSelected()) {
                outer.showDebugMessage("SimServerInner.readCommand() : cmd = " + cmd
                        + " cmd.getCommandID() = " + cmd.getCommandID());
            }
            String cmdName = cmd.getClass().getCanonicalName();
            int pindex = cmdName.indexOf('.');
            if (pindex > 0) {
                cmdName = cmdName.substring(pindex + 1);
            }
            outer.updateCurrentCommandType(cmdName);
            synchronized (status) {
                CommandStatusType cst = status.getCommandStatus();
                if (null == cst) {
                    cst = new CommandStatusType();
                    status.setCommandStatus(cst);
                }
                if (getCommandState() == CommandStateEnumType.DONE) {
                    setCommandState(CommandStateEnumType.WORKING);
                }
            }
            executingMoveCommand = false;

//            System.out.println("cmd = " + cmd);
//            System.out.println("cmd.getCommandID() = " + cmd.getCommandID());
            if (cmd instanceof InitCanonType) {
                InitCanonType init = (InitCanonType) cmd;
                setCommandState(CommandStateEnumType.DONE);
                outer.updateIsInitialized(true);
//                System.out.println("INIT");
                this.setWaypoints(null);
                this.setGoalPose(null);
                this.commandedJointPositions = Arrays.copyOf(jointPositions, jointPositions.length);
            } else {
                if (this.getCommandState() == CommandStateEnumType.DONE) {
                    this.setWaypoints(null);
                }
                if (!outer.isInitializedSelected()) {
                    setCommandState(CommandStateEnumType.ERROR);
                    showMessage("Command other than init recieved when not initialized.");
                    return;
                }
                if (cmd instanceof SetEndEffectorType) {
                    SetEndEffectorType seet = (SetEndEffectorType) cmd;
                    outer.updateEndEffector(seet.getSetting().toString());
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof CloseToolChangerType) {
                    CloseToolChangerType ctc = (CloseToolChangerType) cmd;
                    outer.updateToolChangerIsOpen(false);
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof OpenToolChangerType) {
                    OpenToolChangerType otc = (OpenToolChangerType) cmd;
                    outer.updateToolChangerIsOpen(true);
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof MessageType) {
                    MessageType mt = (MessageType) cmd;
                    this.showMessage("MESSAGE: " + mt.getMessage() + "\n");
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof ConfigureJointReportsType) {
                    cjr = (ConfigureJointReportsType) cmd;
                    if (cjr.isResetAll() || null == this.cjrList) {
                        this.cjrList = new ArrayList<ConfigureJointReportType>();
                    }
                    this.cjrList.addAll(cjr.getConfigureJointReport());
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetLengthUnitsType) {
                    SetLengthUnitsType slu = (SetLengthUnitsType) cmd;
                    LengthUnitEnumType lu = slu.getUnitName();
                    setLengthUnit(lu);
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetTransSpeedType) {
                    SetTransSpeedType sts = (SetTransSpeedType) cmd;
                    TransSpeedType ts = sts.getTransSpeed();
                    if (ts instanceof TransSpeedAbsoluteType) {
                        TransSpeedAbsoluteType tsa = (TransSpeedAbsoluteType) ts;
                        this.setCommandedTransSpeed(tsa.getSetting().doubleValue());
                    } else if (ts instanceof TransSpeedRelativeType) {
                        TransSpeedRelativeType tsr = (TransSpeedRelativeType) ts;
                        this.setCommandedTransSpeed(tsr.getFraction().doubleValue() * maxTransSpeed);
                    } else {
                        outer.showMessage("Unrecognized type of TransSpeed in SetTransSpeedType");
                        setCommandState(CommandStateEnumType.ERROR);
                        return;
                    }
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetTransAccelType) {
                    SetTransAccelType sts = (SetTransAccelType) cmd;
                    TransAccelType ts = sts.getTransAccel();
                    if (ts instanceof TransAccelAbsoluteType) {
                        TransAccelAbsoluteType taa = (TransAccelAbsoluteType) ts;
                        this.setCommandedTransAccel(taa.getSetting().doubleValue());
                    } else if (ts instanceof TransAccelRelativeType) {
                        TransAccelRelativeType tar = (TransAccelRelativeType) ts;
                        this.setCommandedTransAccel(tar.getFraction().doubleValue() * maxTransAccel);
                    } else {
                        outer.showMessage("Unrecognized type of TransAccel in SetTransAccelType");
                        setCommandState(CommandStateEnumType.ERROR);
                        return;
                    }
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetRotSpeedType) {
                    SetRotSpeedType sts = (SetRotSpeedType) cmd;
                    RotSpeedType ts = sts.getRotSpeed();
                    if (ts instanceof RotSpeedAbsoluteType) {
                        RotSpeedAbsoluteType tsa = (RotSpeedAbsoluteType) ts;
                        this.setCommandedRotSpeed(tsa.getSetting().doubleValue());
                    } else if (ts instanceof RotSpeedRelativeType) {
                        RotSpeedRelativeType tsr = (RotSpeedRelativeType) ts;
                        this.setCommandedRotSpeed(tsr.getFraction().doubleValue() * maxRotSpeed);
                    } else {
                        outer.showMessage("Unrecognized type of RotSpeed in SetRotSpeedType");
                        setCommandState(CommandStateEnumType.ERROR);
                        return;
                    }
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetRotAccelType) {
                    SetRotAccelType sts = (SetRotAccelType) cmd;
                    RotAccelType ts = sts.getRotAccel();
                    if (ts instanceof RotAccelAbsoluteType) {
                        RotAccelAbsoluteType taa = (RotAccelAbsoluteType) ts;
                        this.setCommandedRotAccel(taa.getSetting().doubleValue());
                    } else if (ts instanceof RotAccelRelativeType) {
                        RotAccelRelativeType tar = (RotAccelRelativeType) ts;
                        this.setCommandedRotAccel(tar.getFraction().doubleValue() * maxRotAccel);
                    } else {
                        outer.showMessage("Unrecognized type of RotAccel in SetRotAccelType");
                        setCommandState(CommandStateEnumType.ERROR);
                        return;
                    }
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof EndCanonType) {
                    EndCanonType end = (EndCanonType) cmd;
                    setCommandState(CommandStateEnumType.DONE);
//                    System.out.println("END");
                    outer.updateIsInitialized(false);
                    this.setWaypoints(null);
                    this.setGoalPose(null);
                    this.commandedJointPositions = Arrays.copyOf(jointPositions, jointPositions.length);
                } else if (cmd instanceof MoveThroughToType) {
                    this.executingMoveCommand = true;
                    MoveThroughToType mv = (MoveThroughToType) cmd;
//                    System.out.println("MoveThroughToType");
//                    System.out.println("mv.getNumPositions() = " + mv.getNumPositions());
//                    System.out.println("mv.isMoveStraight() = " + mv.isMoveStraight());
                    List<PoseType> wpts = mv.getWaypoint();
                    int numpositions = mv.getNumPositions().intValue();
                    if (numpositions < 2) {
                        throw new RuntimeException("MoveThroughToType must set NumPositions to at-least 2 but NumPositions=" + numpositions + ".");
                    }
                    if (wpts.size() < 2) {
                        throw new RuntimeException("MoveThroughToType must have at-least two waypoints but " + wpts.size() + " were given.");
                    }
                    if (wpts.size() != numpositions) {
                        throw new RuntimeException("MoveThroughToType has NumPositions=" + numpositions + " but " + wpts.size() + " waypoints.");
                    }
                    this.setWaypoints(wpts);
//                    System.out.println("wpts = " + wpts);
                    if (null != wpts) {
                        for (PoseType pose : wpts) {
                            checkPose(pose);
                        }
                    }
                    this.setCommandState(CommandStateEnumType.WORKING);
                    this.setCurrentWaypoint(0);
                    this.setGoalPose(wpts.get(0));

//                } else if (cmd instanceof SetJointControlModesType) {
//                    SetJointControlModesType setjcm = (SetJointControlModesType) cmd;
//                    List<JointControlModeType> ljcm = setjcm.getJointControlMode();
//                    for (JointControlModeType jcm : ljcm) {
//                        int index = jcm.getJointNumber().intValue();
//                        if (index < 0 || index > this.controlmodes.length) {
//                            setCommandState(CommandStateEnumType.ERROR);
//                            Message("Bad joint index:" + index);
//                            break;
//                        }
//                        this.controlmodes[index] = jcm.getMode();
//                    }
                } else if (cmd instanceof ActuateJointsType) {
                    this.executingMoveCommand = true;
                    ActuateJointsType ajst = (ActuateJointsType) cmd;
                    this.goalPose = null;
                    List<ActuateJointType> ajl = ajst.getActuateJoint();
                    for (ActuateJointType aj : ajl) {
                        int index = aj.getJointNumber().intValue() - 1;
                        if (index < 0 || index > this.jointPositions.length) {
                            setCommandState(CommandStateEnumType.ERROR);
                            showMessage("Bad joint index:" + index);
                            break;
                        }
                        if (index >= 0 && index < this.jointPositions.length) {
                            this.commandedJointPositions[index] = aj.getJointPosition().doubleValue();
                        }
                    }
                    outer.showDebugMessage("SimServer commandedJointPositions = " + Arrays.toString(commandedJointPositions));
                    setCommandState(CommandStateEnumType.WORKING);
                    outer.updatePanels(true);
                } else if (cmd instanceof MoveToType) {
                    this.executingMoveCommand = true;
                    MoveToType moveto = (MoveToType) cmd;
                    this.setGoalPose(moveto.getEndPosition());
                    setCommandState(CommandStateEnumType.WORKING);
                    this.setMoveStraight(moveto.isMoveStraight());
                    this.setCurrentWaypoint(0);
                    outer.updatePanels(true);
                } else if (cmd instanceof StopMotionType) {
                    this.executingMoveCommand = true;
                    StopMotionType stop = (StopMotionType) cmd;
                    this.setGoalPose(null);
                    this.setWaypoints(null);
                    System.arraycopy(this.jointPositions, 0, this.commandedJointPositions, 0,
                            Math.min(this.jointPositions.length, this.commandedJointPositions.length));
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetAngleUnitsType) {
                    SetAngleUnitsType setAngle = (SetAngleUnitsType) cmd;
                    this.setAngleType(setAngle.getUnitName());
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetEndPoseToleranceType) {
                    SetEndPoseToleranceType endPoseTol = (SetEndPoseToleranceType) cmd;
                    this.setExpectedEndPoseTolerance(endPoseTol.getTolerance());
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof SetIntermediatePoseToleranceType) {
                    SetIntermediatePoseToleranceType intermediatePoseTol = (SetIntermediatePoseToleranceType) cmd;
                    this.setExpectedIntermediatePoseTolerance(intermediatePoseTol.getTolerance());
                    setCommandState(CommandStateEnumType.DONE);
                } else if (cmd instanceof DwellType) {
                    DwellType dwellCmd = (DwellType) cmd;
                    dwellEndTime = System.currentTimeMillis() + dwellCmd.getDwellTime().longValue() * 1000;
                    setCommandState(CommandStateEnumType.WORKING);
                } else if (cmd instanceof MoveScrewType) {
                    MoveScrewType moveScrew = (MoveScrewType) cmd;
                    setCommandState(CommandStateEnumType.WORKING);
                    this.multiStepCommand = moveScrew;
                    this.moveScrewStep = 0;
                } else {
                    setCommandState(CommandStateEnumType.DONE);
//                    System.err.println("Ignored type: " + cmd.getClass().getSimpleName());
                    outer.showDebugMessage("\nIgnored type: " + cmd.getClass().getSimpleName() + "\n");
//                    showMessage("Unrecognized command type: " + cmd.getClass().getSimpleName());
                }
            }
            synchronized (status) {
                status.getCommandStatus().setCommandID(cmd.getCommandID());
            }
            instance = cmdQueue.poll();
        }
    }

    public void setLengthUnit(LengthUnitEnumType lu) {
        outer.updateLengthUnit(lu);
        switch (robotType) {
            case PLAUSIBLE:
                switch (lu) {
                    case METER:
                        this.skPlausible.setScale(0.01 * SCALE_FUDGE_FACTOR);
                        break;

                    case INCH:
                        this.skPlausible.setScale(0.393701 * SCALE_FUDGE_FACTOR);
                        break;

                    case MILLIMETER:
                        this.skPlausible.setScale(10.0 * SCALE_FUDGE_FACTOR);
                        break;
                }
                break;

            case SIMPLE:
                switch (lu) {
                    case METER:
                        this.skSimple.setScale(0.01 * SCALE_FUDGE_FACTOR);
                        break;

                    case INCH:
                        this.skSimple.setScale(0.393701 * SCALE_FUDGE_FACTOR);
                        break;

                    case MILLIMETER:
                        this.skSimple.setScale(10.0 * SCALE_FUDGE_FACTOR);
                        break;
                }
                break;
        }
    }
    private List<PoseType> waypoints;

    /**
     * Get the value of waypoints
     *
     * @return the value of waypoints
     */
    public List<PoseType> getWaypoints() {
        return waypoints;
    }

    /**
     * Set the value of waypoints
     *
     * @param waypoints new value of waypoints
     */
    public void setWaypoints(List<PoseType> waypoints) {
        this.waypoints = waypoints;
        if (null != waypoints) {
            outer.updateNumWaypoints(waypoints.size());
        } else {
            outer.updateNumWaypoints(0);
            this.setCurrentWaypoint(0);
        }
    }

    public void restartServer() {
        try {
            closeServer();
            ssock = new ServerSocket(port);
            if (port == 0) {
                // This is a hack so the integration test can be run on a port 
                // found automatically with the client run in the same 
                // process.
                // For this test only force port to zero then it will be bound
                // to a free port which gets passed back to the client with a system property.
                this.port = ssock.getLocalPort();
                System.setProperty("crcljava.port", Integer.toString(port));
            }
            ssock.setReuseAddress(true);
            acceptClientsThread = new Thread(this::runAcceptClients,
                    "acceptClientsThread");
            acceptClientsThread.start();
            final int start_close_count = this.close_count;
            simThread = new Thread(new Runnable() {
                @Override
                public void run() {

                    try {
                        while (!Thread.currentThread().isInterrupted()) {
                            Thread.sleep(delayMillis);
                            if (!handleMultiStepCommand()) {
                                readCommand();
                            }
                            if (!updateStatus()) {
                                sendStatus(null);
                            }
                        }
                    } catch (InterruptedException ex) {
                        if (SimServerInner.this.close_count <= start_close_count) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        }
                    }
                }
            }, "simThread");
            simThread.start();
            SimServerInner.runningServers.add(this);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage("Can not start server on port " + port + " : " + ex.getMessage());
        }
    }

    public CRCLStatusType getStatus() {
        return status;
    }

    public String getStatusXmlString() throws JAXBException {
        return this.getCheckerCRCLSocket().statusToPrettyString(this.getStatus(), false);
    }

    private CRCLSocket checkerCRCLSocket = null;

    public CRCLSocket getCheckerCRCLSocket() {
        if (null == checkerCRCLSocket) {
            checkerCRCLSocket = new CRCLSocket();
        }
        return checkerCRCLSocket;
    }

}
