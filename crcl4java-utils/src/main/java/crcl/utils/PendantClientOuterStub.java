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


import crcl.base.CRCLProgramType;
import java.io.File;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class PendantClientOuterStub implements PendantClientOuter{

    @Override
    public void showMessage(String s) {
        final String sWithThread = "Thread:" + Thread.currentThread().getName()+" "+s;
        Logger.getLogger(this.getClass().getName()).log(Level.FINE, sWithThread);
    }

    @Override
    public void showMessage(Throwable t) {
        Logger.getLogger(this.getClass().getName()).log(Level.SEVERE, t.toString());
    }

    @Override
    public boolean showDebugMessage(String s) {
        showMessage(s);
        return false;
    }

    private final boolean validateXml;
    
    @Override
    public boolean validateXmlSelected() {
        return this.validateXml;
    }

    private final boolean replaceState;
    
    @Override
    public boolean replaceStateSelected() {
        return this.replaceState;
    }

    private final String host;
    
    @Override
    public String getHost() {
        return this.host;
    }

    private final int port;
    @Override
    public int getPort() {
        return this.port;
    }

    @Override
    public void finishDisconnect() {
    }

    @Override
    public void finishConnect() {
    }

    @Override
    public void finishSetStatus() {
    }

    @Override
    public void checkXmlQuery(CRCLSocket crclSocket) {
    }

    @Override
    public void stopPollTimer() {
    }

    @Override
    public void checkPollSelected() {
    }

    private final boolean debugWaitForDone;
    
    @Override
    public boolean isDebugWaitForDoneSelected() {
        return this.debugWaitForDone;
    }

    private final boolean debugSendCommand;
    
    @Override
    public boolean isDebugSendCommandSelected() {
        return this.debugSendCommand;
    }

    private final boolean debugReadStatus;
    
    @Override
    public boolean isDebugReadStatusSelected() {
        return this.debugReadStatus;
    }

    
    @Override
    public void showCurrentProgramLine(int line) {
    }

    @Override
    public void finishOpenXmlProgramFile(File f, CRCLProgramType program) {
    }

    @Override
    public CRCLProgramType editProgram(CRCLProgramType program) {
        return program;
    }

    @Override
    public void showLastProgramLineExecTimeMillisDists(long millis, double dist) {
    }

    private final boolean recordPose;
    @Override
    public boolean isRecordPoseSelected() {
        return this.recordPose;
    }

    private static boolean prop(String propName, boolean defaultVal) {
        return Boolean.valueOf(System.getProperty(propName,Boolean.toString(defaultVal)));
    }
    
    public PendantClientOuterStub() {
        this(
                prop("crcjava.PendandClient.validateXML",false),// validateXML
                prop("crcjava.PendandClient.replaceState",false),// validateXML
                System.getProperty("crcljava.host","localhost"), //host
                Integer.valueOf(System.getProperty("crcljava.port",
                        Integer.toString(CRCLSocket.DEFAULT_PORT))), //port
                prop("crcjava.PendandClient.debugWaitForDone",false),// debugWaitForDone
                prop("crcjava.PendandClient.debugSendCommand",false),// debugSendCommand
                prop("crcjava.PendandClient.debugReadStatus",false),// debugReadStatus
                prop("crcjava.PendandClient.recordPose",false),// recordPose
                prop("crcjava.PendandClient.exiSelected",false),// exiSelected
                prop("crcjava.PendandClient.useReadStatusThreadSelected",true)// exiSelected
        );
    }
    
    public PendantClientOuterStub
        (
                boolean validateXml,
                boolean replaceState, 
                String host, 
                int port, 
                boolean debugWaitForDone, 
                boolean debugSendCommand, 
                boolean debugReadStatus,
                boolean recordPose,
                boolean exiSelected,
                boolean useReadStatusThreadSelected) {
        this.validateXml = validateXml;
        this.replaceState = replaceState;
        this.host = host;
        this.port = port;
        this.debugWaitForDone = debugWaitForDone;
        this.debugSendCommand = debugSendCommand;
        this.debugReadStatus  = debugReadStatus;
        this.recordPose = recordPose;
        this.exiSelected = exiSelected;
        this.useReadStatusThreadSelected = useReadStatusThreadSelected;
    }
    
    
    private final boolean exiSelected;

    @Override
    public boolean isEXISelected() {
        return this.exiSelected;
    }
    
    private final boolean useReadStatusThreadSelected;

    @Override
    public boolean isUseReadStatusThreadSelected() {
        return this.useReadStatusThreadSelected;
    }
    
}
