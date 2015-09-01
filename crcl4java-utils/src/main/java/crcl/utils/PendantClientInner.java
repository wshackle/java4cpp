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
import crcl.base.CRCLProgramType;
import crcl.base.CRCLStatusType;
import crcl.base.CommandStateEnumType;
import crcl.base.DwellType;
import crcl.base.EndCanonType;
import crcl.base.GetStatusType;
import crcl.base.InitCanonType;
import crcl.base.JointSpeedAccelType;
import crcl.base.JointStatusType;
import crcl.base.JointStatusesType;
import crcl.base.MiddleCommandType;
import crcl.base.MoveScrewType;
import crcl.base.MoveThroughToType;
import crcl.base.MoveToType;
import crcl.base.PoseType;
import crcl.base.PoseToleranceType;
import crcl.base.SetAngleUnitsType;
import crcl.base.SetEndPoseToleranceType;
import crcl.base.SetIntermediatePoseToleranceType;
import crcl.base.StopConditionEnumType;
import crcl.base.StopMotionType;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Optional;
import java.util.Set;
import java.util.TreeSet;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import javax.xml.bind.JAXBException;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPathExpressionException;
import org.xml.sax.SAXException;
import rcs.posemath.PmCartesian;
import rcs.posemath.PmException;
import rcs.posemath.PmPose;
import rcs.posemath.PmRpy;
import rcs.posemath.Posemath;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class PendantClientInner {

    private Thread runTestProgramThread = null;

    private CRCLStatusType status;
    private CRCLSocket crclSocket = null;

    private final PendantClientOuter outer;
    private double jogIncrement = 3.0;

    private CRCLProgramType program;

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

    /**
     * Get the value of program
     *
     * @return the value of program
     */
    public CRCLProgramType getProgram() {
        return program;
    }

    /**
     * Set the value of program
     *
     * @param program new value of program
     */
    public void setProgram(CRCLProgramType program) {
        this.program = program;
    }

    public CRCLSocket getCRCLSocket() {
        return this.crclSocket;
    }

    public PendantClientInner(PendantClientOuter outer) throws ParserConfigurationException {
        this.outer = outer;
        this.xpu = new XpathUtils();
        this.expectedEndPoseTolerance = new PoseToleranceType();
        this.expectedEndPoseTolerance.setXAxisTolerance(BIG_DECIMAL_FIVE_DEGREES_IN_RADIANS);
        this.expectedEndPoseTolerance.setZAxisTolerance(BIG_DECIMAL_FIVE_DEGREES_IN_RADIANS);
        this.expectedEndPoseTolerance.setXPointTolerance(BIG_DECIMAL_POINT_01);
        this.expectedEndPoseTolerance.setYPointTolerance(BIG_DECIMAL_POINT_01);
        this.expectedEndPoseTolerance.setZPointTolerance(BIG_DECIMAL_POINT_01);

        this.expectedIntermediatePoseTolerance = new PoseToleranceType();
        this.expectedIntermediatePoseTolerance.setXAxisTolerance(BIG_DECIMAL_FIVE_DEGREES_IN_RADIANS);
        this.expectedIntermediatePoseTolerance.setZAxisTolerance(BIG_DECIMAL_FIVE_DEGREES_IN_RADIANS);
        this.expectedIntermediatePoseTolerance.setXPointTolerance(BIG_DECIMAL_POINT_01);
        this.expectedIntermediatePoseTolerance.setYPointTolerance(BIG_DECIMAL_POINT_01);
        this.expectedIntermediatePoseTolerance.setZPointTolerance(BIG_DECIMAL_POINT_01);
    }
    public static final BigDecimal BIG_DECIMAL_POINT_01 = new BigDecimal("0.01");
    public static final BigDecimal BIG_DECIMAL_FIVE_DEGREES_IN_RADIANS = BigDecimal.valueOf(Math.PI / 36);

    private volatile int close_test_count = 0;

    public void closeTestProgramThread() {
        close_test_count++;
        if (null != runTestProgramThread) {
            if (runTestProgramThread.equals(Thread.currentThread())) {
                return;
            }
            this.runTestProgramThread.interrupt();
            try {
                this.runTestProgramThread.join(100);
            } catch (InterruptedException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
            this.runTestProgramThread = null;
        }
    }
    public static final Logger LOGGER = Logger.getLogger(PendantClientInner.class.getName());

    public boolean isDone(BigInteger minCmdId) {
        return this.status != null
                && this.status.getCommandStatus() != null
                && this.status.getCommandStatus().getCommandID() != null
                && this.status.getCommandStatus().getCommandID().compareTo(minCmdId) >= 0
                && this.status.getCommandStatus().getCommandState() != CommandStateEnumType.WORKING;
    }

    int request_status_count = 0;
    public boolean requestStatus() {
//        try {
//            Thread.sleep(100);
//        } catch (InterruptedException ex) {
//            Logger.getLogger(PendantClientInner.class.getName()).log(Level.SEVERE, null, ex);
//        }
        request_status_count++;
        LOGGER.log(Level.FINEST,() -> "PendantClientInner.requestStatus() : request_status_count="+request_status_count);
        boolean result = false;
        synchronized (this) {
            if (null == cmdId) {
                cmdId = BigInteger.ONE;
            }
            getStatusMsg.setCommandID(cmdId);
            result = this.sendCommand(getStatusMsg);
        }
        LOGGER.log(Level.FINEST, () -> "PendantClientInner.requestStatus() : returning from RequestStatus() "+ request_status_count);
        return result;
    }

    private final GetStatusType getStatusMsg = new GetStatusType();
    private int jogInterval = 200;

    private double xyzJogIncrement = 3.0;
    private int poll_ms = jogInterval;

    private BigInteger cmdId = BigInteger.ONE;

    private void showMessage(String s) {
        outer.showMessage(s);
    }

    private void showDebugMessage(String s) {
        outer.showDebugMessage(s);
    }

    private void showMessage(Throwable t) {
        outer.showMessage(t);
    }

    private final XpathUtils xpu;

    public XpathUtils getXpu() {
        return this.xpu;
    }

    private CRCLSocket checkerCRCLSocket = null;
    private CRCLCommandInstanceType checkerCommandInstance = null;

    private final Predicate<CRCLProgramType> checkProgramValidPredicate
            = this::checkProgramValid;

    public Predicate<CRCLProgramType> getCheckProgramValidPredicate() {
        return checkProgramValidPredicate;
    }

    public Predicate<CRCLCommandType> getCheckCommandValidPredicate() {
        return checkCommandValidPredicate;
    }

    public boolean checkProgramValid(CRCLProgramType prog) {
        try {

            if (null == checkerCRCLSocket) {
                checkerCRCLSocket = new CRCLSocket();
            }
            if (null == checkerCommandInstance) {
                checkerCommandInstance = new CRCLCommandInstanceType();
            }
            String s = checkerCRCLSocket.programToPrettyString(prog, true);
            return MultiLineStringJPanel.showText(s);
        } catch (Exception ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage(ex);
        }
        return false;
    }

    private final Predicate<CRCLCommandType> checkCommandValidPredicate
            = this::checkCommandValid;

    public CRCLSocket getTempCRCLSocket() {
        CRCLSocket tmpcs = checkerCRCLSocket;
        if (tmpcs == null) {
            if (null == checkerCRCLSocket) {
                checkerCRCLSocket = new CRCLSocket();
            }
            tmpcs = this.checkerCRCLSocket;
        }
        return tmpcs;
    }

    public boolean checkCommandValid(CRCLCommandType cmdObj) {
        try {

            if (null == checkerCRCLSocket) {
                checkerCRCLSocket = new CRCLSocket();
            }
            if (null == checkerCommandInstance) {
                checkerCommandInstance = new CRCLCommandInstanceType();
            }
            checkerCommandInstance.setCRCLCommand(cmdObj);
            String s = checkerCRCLSocket.commandToPrettyString(checkerCommandInstance, true);
            if (cmdObj instanceof MoveThroughToType) {
                MoveThroughToType mtt = (MoveThroughToType) cmdObj;
                int num_positions = mtt.getNumPositions().intValue();
                if (num_positions < 2) {
                    throw new RuntimeException("MoveThroughToType : NumPositions must be at-least 2 but was " + num_positions);
                }
                int wpts_length = mtt.getWaypoint().size();
                if (wpts_length != num_positions) {
                    throw new RuntimeException("MoveThroughToType : NumPositions must equal number of waypoints but NumPostions=" + num_positions
                            + " but number of waypoints = " + wpts_length);
                }
            }
            return MultiLineStringJPanel.showText(s);
        } catch (Exception ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage(ex);
        }
        return false;
    }

    private File[] cmdSchemaFiles = null;
    private File[] programSchemaFiles = null;

    public synchronized void setStatSchema(File[] fa) {
        try {
            fa = CRCLSocket.reorderStatSchemaFiles(fa);
            CRCLSocket.defaultStatSchema = CRCLSocket.filesToSchema(fa);
            if (null != this.crclSocket) {
                this.crclSocket.setStatSchema(CRCLSocket.defaultStatSchema);
            }
        } catch (SAXException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

//    public String getDocumentation(String name) throws SAXException, IOException, XPathExpressionException, ParserConfigurationException {
//        return xpu.queryXml(cmdSchemaFiles, "/schema/complexType[@name=\""+name+"\"]/annotation/documentation/text()");
//    }
    public synchronized void setCmdSchema(File[] fa) {
        try {
            fa = CRCLSocket.reorderCommandSchemaFiles(fa);
            CRCLSocket.defaultCmdSchema = CRCLSocket.filesToSchema(fa);
            if (null != this.crclSocket) {
                this.crclSocket.setCmdSchema(CRCLSocket.defaultCmdSchema);
            }
            cmdSchemaFiles = fa;
            this.xpu.setSchemaFiles(cmdSchemaFiles);
        } catch (SAXException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public synchronized void setProgramSchema(File[] fa) {
        try {
            fa = CRCLSocket.reorderProgramSchemaFiles(fa);
            CRCLSocket.defaultProgramSchema = CRCLSocket.filesToSchema(fa);
            if (null != this.crclSocket) {
                this.crclSocket.setProgramSchema(CRCLSocket.defaultProgramSchema);
            }
            programSchemaFiles = fa;
//            xpu.setSchemaFiles(cmdSchemaFiles);
        } catch (SAXException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public File[] getCmdSchemaFiles() {
        return cmdSchemaFiles;
    }

    public File[] getProgramSchemaFiles() {
        return programSchemaFiles;
    }

    public void openXmlProgramFile(File f) throws ParserConfigurationException, JAXBException, XPathExpressionException, IOException, SAXException {
        String s = this.xpu.queryXml(f, "/");
        CRCLSocket cs = checkerCRCLSocket;
        if (null == cs) {
            if (null == checkerCRCLSocket) {
                checkerCRCLSocket = new CRCLSocket();
            }
            cs = checkerCRCLSocket;
        }
        CRCLProgramType program
                = cs.stringToProgram(s, outer.validateXmlSelected());

        if (null == program.getName() || program.getName().length() < 1) {
            String fname = f.getName();
            if (fname.endsWith(".xml")) {
                fname = fname.substring(0, fname.length() - 4);
            }
            program.setName(fname);
        }
        this.setProgram(program);
        outer.finishOpenXmlProgramFile(f, program);
//        cmdId = cmdId.add(BigInteger.ONE);
//        cmd.setCommandID(cmdId);
//        this.sendCommand(cmd);
//        this.saveRecentCommand(cmd);
    }

    public void saveXmlProgramFile(File f) throws ParserConfigurationException, JAXBException, XPathExpressionException, IOException, SAXException {
        CRCLSocket cs = checkerCRCLSocket;
        if (null == cs) {
            if (null == checkerCRCLSocket) {
                checkerCRCLSocket = new CRCLSocket();
            }
            cs = checkerCRCLSocket;
        }
        if (null == program.getName() || program.getName().length() < 1) {
            String fname = f.getName();
            if (fname.endsWith(".xml")) {
                fname = fname.substring(0, fname.length() - 4);
            }
            program.setName(fname);
        }
        String str
                = cs.programToPrettyString(program, outer.validateXmlSelected());
        try (PrintWriter pw = new PrintWriter(new FileWriter(f))) {
            pw.println(str);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage(ex);
        }
    }

    private CRCLCommandType lastCommandSent = null;
    private CRCLCommandType prevLastCommandSent = null;

    private synchronized boolean sendCommandPrivate(CRCLCommandType cmd) {
        try {
            if (null == crclSocket) {
                showMessage("Can not send command when not connected.");
                return false;
            }
            CRCLCommandInstanceType cmdInstance
                    = new CRCLCommandInstanceType();
            cmdInstance.setCRCLCommand(cmd);
            if (!(cmdInstance.getCRCLCommand() instanceof GetStatusType)) {
                prevLastCommandSent = lastCommandSent;
                lastCommandSent = cmdInstance.getCRCLCommand();
            }
            crclSocket.writeCommand(cmdInstance, outer.validateXmlSelected());
            return true;
        } catch (JAXBException | IOException | EXIException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage(ex);
        } catch (InterruptedException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return false;
    }

    private synchronized void incCommandID(CRCLCommandType cmd) {
        if (null == cmdId) {
            cmdId = BigInteger.ZERO;
        }
        if (null != cmd.getCommandID()
                && cmd.getCommandID().compareTo(cmdId) > 0) {
            cmdId = cmd.getCommandID();
        }
        if (null != status
                && null != status.getCommandStatus()
                && null != status.getCommandStatus().getCommandID()
                && status.getCommandStatus().getCommandID().compareTo(cmdId) > 0) {
            cmdId = status.getCommandStatus().getCommandID();
        }
        cmdId = cmdId.add(BigInteger.ONE);
        cmd.setCommandID(cmdId);
    }

    public boolean incAndSendCommand(CRCLCommandType cmd) {
        this.incCommandID(cmd);
        return sendCommand(cmd);
    }

    public synchronized boolean sendCommand(CRCLCommandType cmd) {
        if (null == cmd) {
            throw new IllegalArgumentException("cmd can not be null");
        }
        if (null == this.crclSocket) {
            throw new IllegalStateException("crclSocket must not be null.");
        }
        if (!(cmd instanceof GetStatusType) && outer.isDebugSendCommandSelected()) {
            showDebugMessage("PendantClientInner.sendCommand() : cmd = " + cmdString(cmd));
        }
        if (cmd instanceof SetAngleUnitsType) {
            SetAngleUnitsType setAngle = (SetAngleUnitsType) cmd;
            this.setAngleType(setAngle.getUnitName());
        } else if (cmd instanceof SetEndPoseToleranceType) {
            SetEndPoseToleranceType endPoseTol = (SetEndPoseToleranceType) cmd;
            this.setExpectedEndPoseTolerance(endPoseTol.getTolerance());
        } else if (cmd instanceof SetIntermediatePoseToleranceType) {
            SetIntermediatePoseToleranceType intermediatePoseTol = (SetIntermediatePoseToleranceType) cmd;
            this.setExpectedIntermediatePoseTolerance(intermediatePoseTol.getTolerance());
        }
        boolean ret = this.sendCommandPrivate(cmd);
        if (!(cmd instanceof GetStatusType) && outer.isDebugSendCommandSelected()) {
            showDebugMessage("PendantClientInner.sendCommand() : ret = " + ret);
        }
        return ret;
    }

    public void abort() {
        this.closeTestProgramThread();
        unpause();
        stopMotion(StopConditionEnumType.FAST);
    }

    /**
     *
     * @param stopType the value of stopType
     */
    public void stopMotion(StopConditionEnumType stopType) {
        StopMotionType stop = new StopMotionType();
        stop.setStopCondition(stopType);
        this.incAndSendCommand(stop);
    }

    /**
     *
     * @param minCmdId the value of minCmdId
     * @param timeoutMilliSeconds the value of timeoutMilliSeconds
     * @return the boolean
     * @throws InterruptedException when Thread interrupted
     */
    public boolean waitForDone(BigInteger minCmdId, long timeoutMilliSeconds)
            throws InterruptedException {

        boolean returnDone = false;
        try {
            if (outer.isDebugWaitForDoneSelected()) {
                showDebugStatus();
            }
            long start = System.currentTimeMillis();
            long timeDiff = System.currentTimeMillis() - start;
            int old_pause_count = this.pause_count;
            final long fullTimeout = timeoutMilliSeconds
                    + ((waitForDoneDelay > 0) ? 2 * waitForDoneDelay : 0);
            while (!Thread.currentThread().isInterrupted()
                    && !isDone(minCmdId)
                    && timeDiff < fullTimeout) {
                if (outer.isDebugWaitForDoneSelected()) {
                    showDebugStatus();
                    showDebugMessage("PendantClient waitForDone(" + minCmdId + ") timeDiff = " + timeDiff + " / " + timeoutMilliSeconds + " = " + ((double) timeDiff) / timeoutMilliSeconds);
                }
                if (waitForDoneDelay > 0) {
                    Thread.sleep(waitForDoneDelay);
                }
                if (!requestStatus()) {
                    return false;
                }
                if (null == readerThread) {
                    readStatus();
                }
                if (this.pause_count != old_pause_count || this.paused) {
                    return false;
                }
                if (this.pause_count != old_pause_count || this.paused) {
                    return false;
                }
                timeDiff = System.currentTimeMillis() - start;
            }
            if (outer.isDebugWaitForDoneSelected()) {
                showDebugMessage("PendantClient waitForDone(" + minCmdId + ") returning");
                showDebugStatus();
                showDebugMessage("PendantClient timeDiff = " + timeDiff + " / " + timeoutMilliSeconds + " = " + ((double) timeDiff) / timeoutMilliSeconds);
                if (timeDiff >= timeoutMilliSeconds) {
                    showMessage("Timed out waiting for DONE.");
                }
            }
            returnDone = !Thread.currentThread().isInterrupted()
                    && isDone(minCmdId);
        } catch (NullPointerException ex) {
            // Ugly hack hoping to catch strange debugging problem.
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return returnDone;
    }

    private static long getLongProperty(String propName, long defaultLong) {
        return Long.valueOf(System.getProperty(propName, Long.toString(defaultLong)));
    }

    private long waitForDoneDelay = getLongProperty("PendantClient.waitForDoneDelay", 200);

    public long getWaitForDoneDelay() {
        return waitForDoneDelay;
    }

    public void setWaitForDoneDelay(long waitForDoneDelay) {
        this.waitForDoneDelay = waitForDoneDelay;
    }

    private void showDebugStatus() {
        if (null == this.status) {
            showDebugMessage("PendantClient this.status == null");
        } else {
            if (null == this.status.getCommandStatus()) {
                showDebugMessage("PendantClient this.status.getCommandStatus() == null");
            } else {
                showDebugMessage("PendantClient this.status.getCommandStatus().getCommandID() ="
                        + this.status.getCommandStatus().getCommandID());
                showDebugMessage("PendantClient this.status.getCommandStatus().getCommandState() ="
                        + this.status.getCommandStatus().getCommandState());
            }
        }
    }

    Thread readerThread = null;

    /**
     * Set the value of status
     *
     * @param status new value of status
     */
    public void setStatus(CRCLStatusType status) {
        this.status = status;
        outer.finishSetStatus();
    }

    public CRCLStatusType getStatus() {
        return this.status;
    }

    private List<AnnotatedPose> poseList = null;

    public List<AnnotatedPose> getPoseList() {
        return poseList;
    }

    public static interface TrySupplier<T> {

        public T tryGet() throws Throwable;

    };

    public static <T> Optional<T> tryGet(TrySupplier<T> ts) {
        try {
            return Optional.of(ts.tryGet());
        } catch (Throwable ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return Optional.empty();
    }

    public static Optional<JointStatusType> getJointStatus(CRCLStatusType status, BigInteger id) {
        return Optional.ofNullable(status)
                .map((x) -> x.getJointStatuses())
                .filter((x) -> x != null)
                .map((x) -> x.getJointStatus())
                .flatMap((x) -> x.stream().filter((x2) -> x2.getJointNumber().compareTo(id) == 0).findAny());
    }

    public static Stream<JointStatusType> getJointValues(CRCLStatusType status,
            Collection<BigInteger> ids) {
        return ids.stream()
                .map((x) -> getJointStatus(status, x))
                .flatMap((x) -> x.map(Stream::of).orElseGet(Stream::empty));
    }

    public static String getJointString(CRCLStatusType status,
            Function<JointStatusType, String> mapper,
            Collection<BigInteger> ids) {
        return getJointValues(status, ids)
                .map(mapper)
                .collect(Collectors.joining(","));
    }

    public void savePoseListToCsvFile(String poseFileName) throws IOException, PmException {
        if (null == poseFileName
                || this.getPoseList() == null
                || this.getPoseList().isEmpty()) {
            return;
        }
        List<JointStatusesType> jss
                = this.getPoseList()
                .stream()
                .map((x) -> x.getStatus())
                .filter((x) -> x != null)
                .map((x) -> x.getJointStatuses())
                .filter((x) -> x != null)
                .collect(Collectors.toList());
        final Set<BigInteger> jointIds = new TreeSet<>();
        jss.stream()
                .flatMap((x) -> x.getJointStatus().stream())
                .forEach((x) -> jointIds.add(x.getJointNumber()));
        Optional<JointStatusesType> exampleJss = jss.stream().findAny();
        Optional<JointStatusType> exampleJs
                = exampleJss
                .map((x) -> x.getJointStatus())
                .map((x) -> x.stream().findAny())
                .orElse(Optional.empty());
        final boolean havePos
                = exampleJs
                .map((x) -> x.getJointPosition() != null)
                .orElse(false);
        final boolean haveVel
                = exampleJs
                .map((x) -> x.getJointVelocity() != null)
                .orElse(false);
        final boolean haveForce
                = exampleJs
                .map((x) -> x.getJointTorqueOrForce() != null)
                .orElse(false);

        final PmRpy rpyZero = new PmRpy();
        try (PrintWriter pw = new PrintWriter(new FileWriter(poseFileName))) {
            String headers = "time,cmdId,cmdName,x,y,z,roll,pitch,yaw,"
                    + (havePos ? jointIds.stream().map((x) -> "Joint" + x + "Pos").collect(Collectors.joining(",")) : "")
                    + (haveVel ? jointIds.stream().map((x) -> "Joint" + x + "Vel").collect(Collectors.joining(",")) : "")
                    + (haveForce ? jointIds.stream().map((x) -> "Joint" + x + "Force").collect(Collectors.joining(",")) : "");
            pw.println(headers);
            this.getPoseList()
                    .stream()
                    .map((pose) -> {
                        PmRpy rpy = tryGet(() -> Posemath.toRpy(pose.rot)).orElse(rpyZero);
                        Stream stream = Stream.builder()
                        .add(pose.getTime())
                        .add(pose.getCmdId())
                        .add(pose.getCommandName())
                        .add(pose.tran.x)
                        .add(pose.tran.y)
                        .add(pose.tran.z)
                        .add(Math.toDegrees(rpy.r))
                        .add(Math.toDegrees(rpy.p))
                        .add(Math.toDegrees(rpy.y))
                        .build();
                        if (havePos) {
                            stream = Stream.concat(stream, getJointValues(status, jointIds)
                                    .map((x) -> x.getJointPosition())
                            );
                        }
                        if (haveVel) {
                            stream = Stream.concat(stream, getJointValues(status, jointIds)
                                    .map((x) -> x.getJointVelocity())
                            );
                        }
                        if (haveForce) {
                            stream = Stream.concat(stream, getJointValues(status, jointIds)
                                    .map((x) -> x.getJointTorqueOrForce())
                            );
                        }
                        return stream
                        .map((x) -> x.toString())
                        .collect(Collectors.joining(","));
                    })
                    .forEach((s) -> pw.println(s));
        }
    }

    public void readStatus() {
        try {
            if (outer.replaceStateSelected()) {
                crclSocket.setStatusStringInputFilter(CRCLSocket.addCRCLToState);
            } else {
                crclSocket.setStatusStringInputFilter(null);
            }
            final CRCLStatusType curStatus
                    = crclSocket.readStatus(outer.validateXmlSelected());
            if (outer.isDebugReadStatusSelected()) {
                //outer.showDebugMessage("curStatus = "+curStatus);
                String statString = crclSocket.getLastStatusString();
                outer.showDebugMessage("crclSocket.getLastStatusString() = " + statString);
                if (null != curStatus
                        && (null == statString || statString.length() < 1)) {
                    outer.showDebugMessage("crclSocket.statusToString(curStatus,false)="
                            + crclSocket.statusToString(curStatus, false));
                }
            }
            if (curStatus == null) {
                return;
            }
            outer.checkXmlQuery(crclSocket);
            if (outer.isRecordPoseSelected()
                    && null != curStatus.getPose()) {
                if (null == poseList) {
                    poseList = new ArrayList<>();
                }
                PmPose pmPose = CRCLPosemath.toPmPose(curStatus.getPose());
                BigInteger cmdId2
                        = Optional.ofNullable(status)
                        .map((x) -> x.getCommandStatus())
                        .map((x) -> x.getCommandID())
                        .orElse(cmdId);
                AnnotatedPose annotatedPose
                        = new AnnotatedPose(System.currentTimeMillis(),
                                cmdId2,
                                cmdId.compareTo(cmdId2) <= 0 ? cmdNameString(lastCommandSent) : cmdNameString(prevLastCommandSent),
                                pmPose.tran, pmPose.rot,
                                status
                        );
                poseList.add(annotatedPose);
            }
            this.setStatus(curStatus);

        } catch (IOException | IllegalStateException ex) {
            if (disconnecting) {
                return;
            }
            LOGGER.log(Level.SEVERE, null, ex);
            this.showMessage(ex);
            java.awt.EventQueue.invokeLater(new Runnable() {

                @Override
                public void run() {
                    try {
                        PendantClientInner.this.disconnect();
                    } catch (Exception e) {
                        // ignore
                    }
                }
            });

        } catch (JAXBException ex) {
            if (disconnecting) {
                return;
            }
            LOGGER.log(Level.SEVERE, null, ex);
            this.showMessage(ex.toString() + "\n" + crclSocket.getLastStatusString() + "\n");
            java.awt.EventQueue.invokeLater(new Runnable() {

                @Override
                public void run() {
                    try {
                        disconnect();
                    } catch (Exception e) {
                        // ignore
                    }
                }
            });
        } catch (Exception ex) {
            if (disconnecting) {
                return;
            }
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public boolean isConnected() {
        return null != this.crclSocket && this.crclSocket.isConnected();
    }

    public synchronized void connect(String host, int port) {
        try {
            disconnect();
            disconnecting = false;
            crclSocket = new CRCLSocket(host, port);
            crclSocket.setEXIEnabled(outer.isEXISelected());
            startStatusReaderThread();
            outer.finishConnect();
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage("Can't connect to " + host + ":" + port + " -- " + ex.getMessage());
        } catch (EXIException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public void startStatusReaderThread() {
        this.stopStatusReaderThread();
        if (outer.isUseReadStatusThreadSelected()) {
            readerThread = new Thread(new Runnable() {

                @Override
                public void run() {
                    final Thread t = Thread.currentThread();
                    while (!t.isInterrupted()
                            && !stopStatusReaderFlag
                            && null != crclSocket
                            && crclSocket.isConnected()) {
                        PendantClientInner.this.readStatus();
                    }
                }
            }, "PendantClientInner.statusReaderThread");
            readerThread.start();
        }
    }

    private boolean disconnecting = false;

    public synchronized void disconnect() {
        disconnecting = true;
        if (null != crclSocket) {
            try {
                crclSocket.close();
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
            crclSocket = null;
        }
        stopStatusReaderThread();
        if (null != runTestProgramThread && !runTestProgramThread.equals(Thread.currentThread())) {
            this.closeTestProgramThread();
        }
        outer.finishDisconnect();
    }

    private boolean stopStatusReaderFlag = false;

    public void stopStatusReaderThread() {
        if (null != readerThread) {
            try {
                stopStatusReaderFlag = true;
                readerThread.interrupt();
                readerThread.join(1500);
            } catch (InterruptedException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } finally {
                readerThread = null;
                stopStatusReaderFlag = false;
            }

        }
    }

    private BigDecimal jointTol = BigDecimal.valueOf(jogIncrement / 5.0);

    private boolean testCommandEffect(CRCLCommandType cmd, long cmdStartTime) {
        if (cmd instanceof ActuateJointsType) {
            return testAcutateJointsEffect((ActuateJointsType) cmd);
        }
        if (cmd instanceof MoveThroughToType) {
            return testMoveThroughToEffect((MoveThroughToType) cmd);
        }
        if (cmd instanceof MoveToType) {
            return testMoveToEffect((MoveToType) cmd);
        }
        if (cmd instanceof DwellType) {
            return testDwellEffect((DwellType) cmd, cmdStartTime);
        }
        return true;
    }

    private boolean testAcutateJointsEffect(ActuateJointsType ajst) {
        List<ActuateJointType> ajl = ajst.getActuateJoint();
        for (ActuateJointType aj : ajl) {
            List<JointStatusType> jointListTest = status.getJointStatuses().getJointStatus();
            JointStatusType jointStatusTest = null;
            for (int j = 0; j < jointListTest.size(); j++) {
                JointStatusType jsj = jointListTest.get(j);
                if (jsj.getJointNumber().compareTo(aj.getJointNumber()) == 0) {
                    jointStatusTest = jointListTest.get(j);
                    break;
                }
            }
            if (null == jointStatusTest) {
                showMessage("Test program failed : no jointStatus for " + aj.getJointNumber());
                return false;
            }
            BigDecimal jointDiff = jointStatusTest.getJointPosition().subtract(aj.getJointPosition()).abs();
            if (jointDiff.compareTo(jointTol) > 0) {
                showMessage("Test program failed measured position differs from commanded position.\n"
                        + "JointNumber: " + aj.getJointNumber() + "\n"
                        + "Commanded :" + aj.getJointPosition() + "\n"
                        + "Status (Measured): " + jointStatusTest.getJointPosition() + "\n"
                        + "Diff: " + jointDiff);
                return false;
            }
        }
        return true;
    }

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

    private boolean testMoveThroughToEffect(MoveThroughToType moveThroughTo) {
        PoseType curPose = status.getPose();
        PoseType cmdPose = moveThroughTo.getWaypoint().get(moveThroughTo.getNumPositions().intValue() - 1);
        return PoseToleranceChecker.isInTolerance(curPose, cmdPose, expectedEndPoseTolerance, angleType);
    }

    private boolean testDwellEffect(DwellType dwell, long startTime) {
        long elapsed = System.currentTimeMillis() - startTime;
        long expected = (long) (dwell.getDwellTime().doubleValue() * 1000.0);
        if (Math.abs(elapsed - expected) > 1500) {
            outer.showMessage("Dwell expected to take " + expected + " ms but took " + elapsed + " ms.");
            return false;
        }
        return true;
    }

    private boolean testMoveToEffect(MoveToType moveTo) {
        PoseType curPose = status.getPose();
        if (PoseToleranceChecker.containsNull(curPose)) {
            outer.showMessage("MoveTo Failed current pose contains null.");
            return false;
        }
        PoseType cmdPose = moveTo.getEndPosition();
        if (PoseToleranceChecker.containsNull(curPose)) {
            outer.showMessage("MoveTo Failed cmdPose contains null.");
            return false;
        }
        if (!PoseToleranceChecker.isInTolerance(curPose, cmdPose, expectedEndPoseTolerance, angleType)) {
            outer.showMessage("MoveTo Failed : diference between curPose and cmdPose exceeds tolerance.");
            return false;
        }
        return true;
    }

    private volatile BlockingQueue<Object> pauseQueue = new ArrayBlockingQueue<Object>(1);
    private volatile boolean paused = false;
    private volatile int waiting_for_pause_queue = 0;
    private volatile int pause_count = 0;

    public void pause() {
        pause_count++;
        pauseQueue.clear();
        paused = true;
        stopMotion(StopConditionEnumType.NORMAL);
    }

    public void waitForPause() throws InterruptedException {
        while (paused) {
            waiting_for_pause_queue++;
            pauseQueue.take();
            waiting_for_pause_queue--;
        }
    }

    public void unpause() {
        paused = false;
        for (int i = 0; i < waiting_for_pause_queue + 1; i++) {
            try {
                pauseQueue.put(this);
            } catch (InterruptedException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
    }

    long programCommandStartTime;

    public boolean runProgram(CRCLProgramType prog) {
        final int start_close_test_count = this.close_test_count;
        try {
            if (null == this.crclSocket) {
                this.connect(outer.getHost(), outer.getPort());
            }
            outer.stopPollTimer();
            outer.showCurrentProgramLine(0);
//            this.stopStatusReaderThread();
            cmdId = BigInteger.ZERO;
            programCommandStartTime = System.currentTimeMillis();
            PmCartesian p0 = getPoseCart();

            InitCanonType initCmd = prog.getInitCanon();
            if (!testCommand(initCmd)) {
                return false;
            }
            long time_to_exec = System.currentTimeMillis() - programCommandStartTime;
            PmCartesian p1 = getPoseCart();
            outer.showLastProgramLineExecTimeMillisDists(time_to_exec, p1.distFrom(p0));
            p0 = p1;
            outer.showCurrentProgramLine(1);
            List<MiddleCommandType> middleCommands = prog.getMiddleCommand();
            for (int i = 0; i < middleCommands.size(); i++) {
                programCommandStartTime = System.currentTimeMillis();
                MiddleCommandType cmd = middleCommands.get(i);
                if (!testCommand(cmd)) {
                    return false;
                }
                time_to_exec = System.currentTimeMillis() - programCommandStartTime;
                p1 = getPoseCart();
                outer.showLastProgramLineExecTimeMillisDists(time_to_exec, p1.distFrom(p0));
                p0 = p1;
                outer.showCurrentProgramLine(i + 2);
            }
            programCommandStartTime = System.currentTimeMillis();
            EndCanonType endCmd = prog.getEndCanon();
            if (!testCommand(endCmd)) {
                return false;
            }
            time_to_exec = System.currentTimeMillis() - programCommandStartTime;
            outer.showLastProgramLineExecTimeMillisDists(time_to_exec, 0);
            outer.showCurrentProgramLine(middleCommands.size() + 2);
            outer.showDebugMessage("testProgram() succeeded");
            return true;
        } catch (InterruptedException ex) {
            if (close_test_count <= start_close_test_count) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
        return false;
    }

    private PmCartesian getPoseCart() {
        PmCartesian p0
                = Optional.ofNullable(status)
                .map(x -> x.getPose())
                .filter(x -> x != null)
                .map(x -> x.getPoint())
                .filter(x -> x != null)
                .map(CRCLPosemath::pointToPmCartesian)
                .orElse(new PmCartesian());
        return p0;
    }

    public boolean isPaused() {
        return this.paused;
    }

    public boolean isRunningProgram() {
        return !paused
                && null != this.runTestProgramThread
                && this.runTestProgramThread.isAlive();
    }

    /**
     * Tests if an automatically generated set of commands appears to be
     * correctly implemented by the server.
     *
     * @return false for failure or true for success
     */
    public boolean runTest() {
        try {
            if (null == this.crclSocket) {
                this.connect(outer.getHost(), outer.getPort());
            }
            outer.stopPollTimer();
            InitCanonType initCmd = new InitCanonType();
            if (!testCommand(initCmd)) {
                return false;
            }
            Thread.sleep(1000);
            jointTol = BigDecimal.valueOf(jogIncrement / 5.0);
            if (null != status.getJointStatuses()) {
                List<JointStatusType> jointList = status.getJointStatuses().getJointStatus();
                for (int i = 0; i < jointList.size(); i++) {
                    JointStatusType js = jointList.get(i);
                    ActuateJointsType ajst = new ActuateJointsType();
                    List<ActuateJointType> ajl = ajst.getActuateJoint();
                    ActuateJointType aj = new ActuateJointType();
                    aj.setJointNumber(js.getJointNumber());
                    BigDecimal origPosition = BigDecimal.valueOf(js.getJointPosition().doubleValue());
                    aj.setJointPosition(js.getJointPosition().add(BigDecimal.valueOf(jogIncrement)));
                    JointSpeedAccelType jsa = new JointSpeedAccelType();
                    aj.setJointDetails(jsa);
                    ajl.add(aj);
                    if (!testCommand(ajst)) {
                        return false;
                    }
                    Thread.sleep(2000);
                    ajst = new ActuateJointsType();
                    ajl = ajst.getActuateJoint();
                    aj = new ActuateJointType();
                    aj.setJointNumber(js.getJointNumber());
                    aj.setJointPosition(origPosition);
                    jsa = new JointSpeedAccelType();
                    aj.setJointDetails(jsa);
                    ajl.add(aj);
                    if (!testCommand(ajst)) {
                        return false;
                    }
                }
            }
            EndCanonType endCmd = new EndCanonType();
            if (!testCommand(endCmd)) {
                return false;
            }
            showMessage("Test program ran successfully.");
            return true;
        } catch (InterruptedException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            return false;
        } finally {
            outer.checkPollSelected();
        }
    }

    private String cmdNameString(CRCLCommandType cmd) {
        if (null == cmd) {
            return "";
        }
        String cmdName = cmd.getClass().getSimpleName();
        final String prefix = "crcl.base.";
        if (cmdName.startsWith(prefix)) {
            return cmdName.substring(prefix.length());
        }
        return cmdName;
    }

    private String cmdString(CRCLCommandType cmd) {
        String cmdName = cmdNameString(cmd);
        return cmdName + " with ID = " + cmd.getCommandID() + ", \txml: " + this.getTempCRCLSocket().commandToString(cmd, false);
    }

    public BigDecimal getJointPosition(BigInteger jointNumber) {
        if (null == status || null == status.getJointStatuses()) {
            return null;
        }
        List<JointStatusType> jsl = status.getJointStatuses().getJointStatus();
        if (null == jsl) {
            return null;
        }
        for (JointStatusType js : jsl) {
            if (js.getJointNumber().compareTo(jointNumber) == 0) {
                return js.getJointPosition();
            }
        }
        return null;
    }

    private long getTimeoutForAcuateJoints(ActuateJointsType ajst) {
        List<ActuateJointType> ajl = ajst.getActuateJoint();
        BigDecimal diff = BigDecimal.ZERO;
        for (ActuateJointType aj : ajl) {
            BigDecimal jp = getJointPosition(aj.getJointNumber());
            if (null != jp) {
                diff = diff.max(jp.subtract(aj.getJointPosition()).abs());
            }
        }
        return 2000 + (long) (diff.doubleValue() * 1000.0);
    }

    private long getTimeoutForMoveThroughTo(MoveThroughToType cmd) {
        return 90000;
    }

    private long getTimeoutForMoveTo(MoveToType cmd) {
        return 90000;
    }

    private long getTimeoutForMoveScrew(MoveScrewType cmd) {
        return 90000;
    }

    private long getTimeoutForDwell(DwellType cmd) {
        return (long) (1500 + cmd.getDwellTime().doubleValue() * 1000);
    }

    private long getTimeout(CRCLCommandType cmd) {
        if (cmd instanceof ActuateJointsType) {
            return getTimeoutForAcuateJoints((ActuateJointsType) cmd);
        }
        if (cmd instanceof MoveThroughToType) {
            return getTimeoutForMoveThroughTo((MoveThroughToType) cmd);
        }
        if (cmd instanceof MoveToType) {
            return getTimeoutForMoveTo((MoveToType) cmd);
        }
        if (cmd instanceof MoveScrewType) {
            return getTimeoutForMoveScrew((MoveScrewType) cmd);
        }
        if (cmd instanceof DwellType) {
            return getTimeoutForDwell((DwellType) cmd);
        }
        return 3000;
    }

    /**
     *
     * @param cmd the value of command to test
     * @param timeout the value of timeout
     * @return false for failure or true for success
     * @throws InterruptedException
     */
    private boolean testCommand(CRCLCommandType cmd) throws InterruptedException {
        final long timeout = getTimeout(cmd);
        int pause_count_start = this.pause_count;
        long testCommandStartTime = System.currentTimeMillis();
        do {
            if (null == crclSocket) {
                throw new IllegalStateException("crclSocket must not be null");
            }
            if (cmd instanceof GetStatusType) {
                showDebugMessage("Ignoring command GetStatusType inside a program.");
                return true;
            }
            this.waitForPause();
            pause_count_start = this.pause_count;
            if (!incAndSendCommand(cmd)) {
                final String cmdString = cmdString(cmd);
                if (pause_count_start != this.pause_count) {
                    continue;
                }
                showMessage("Can not send " + cmdString + ".");
                return false;
            }
            final String cmdString = cmdString(cmd);
            long sendCommandTime = System.currentTimeMillis();
            if (!waitForDone(cmd.getCommandID(), timeout)) {
                if (pause_count_start != this.pause_count) {
                    continue;
                }
                long curTime = System.currentTimeMillis();
                showMessage("Test Progam failed waiting for DONE from " + cmdString + ".\n"
                        + "sendCommandTime=" + sendCommandTime + "\n"
                        + "curTime = " + curTime + "\n"
                        + "(curTime-sendCommandTime)=" + (curTime - sendCommandTime) + "\n"
                        + "timeout=" + timeout + "\n"
                        + "cmd.getCommandID() = " + cmd.getCommandID() + "\n"
                        + ((status == null || status.getCommandStatus() == null)
                                ? "status.getCommandStatus()=null\n"
                                : ("status.getCommandStatus().getCommandID()=" + status.getCommandStatus().getCommandID() + "\n"
                                + "status.getCommandStatus().getCommandState()=" + status.getCommandStatus().getCommandState() + "\n"))
                );
                SimServerInner.printAllClientStates(System.err);
                Thread.getAllStackTraces().entrySet().forEach((x) -> {
                    System.err.println("Thread:" + x.getKey().getName());
                    Arrays.stream(x.getValue()).forEach((xx) -> {
                        System.err.println("\t" + xx);
                    });
                    System.err.println("");
                });
                return false;
            }
        } while (pause_count_start != this.pause_count);

        return testCommandEffect(cmd, testCommandStartTime);
    }

    public void startRunProgramThread() {
        this.closeTestProgramThread();
        this.runTestProgramThread = new Thread(new Runnable() {

            @Override
            public void run() {
                runProgram(program);
            }

        }, "PendantClientInner.runProgram");
        this.runTestProgramThread.start();
    }

    public void startRunTestThread() {
        this.closeTestProgramThread();
        this.runTestProgramThread = new Thread(new Runnable() {

            @Override
            public void run() {
                runTest();
            }

        }, "PendantClientInner.runTest");
        this.runTestProgramThread.start();
    }

    public int getPoll_ms() {
        return poll_ms;
    }

    public void setPoll_ms(int poll_ms) {
        this.poll_ms = poll_ms;
    }

    public BigInteger getCmdId() {
        return cmdId;
    }

    public synchronized void setCmdId(BigInteger cmdId) {
        this.cmdId = cmdId;
    }

    public double getJogIncrement() {
        return jogIncrement;
    }

    public void setJogIncrement(double jogIncrement) {
        this.jogIncrement = jogIncrement;
    }

    public double getXyzJogIncrement() {
        return xyzJogIncrement;
    }

    public void setXyzJogIncrement(double xyzJogIncrement) {
        this.xyzJogIncrement = xyzJogIncrement;
    }

    public int getJogInterval() {
        return jogInterval;
    }

    public void setJogInterval(int jogInterval) {
        this.jogInterval = jogInterval;
    }

}
