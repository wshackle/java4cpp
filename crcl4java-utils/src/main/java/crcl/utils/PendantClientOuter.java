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

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public interface PendantClientOuter {
    
    public void showMessage(String s);
    public void showMessage(Throwable t);
    public boolean showDebugMessage(String s);
    public boolean validateXmlSelected();
    public boolean replaceStateSelected();
    public String getHost();
    public int getPort();
    public void finishDisconnect();
    public void finishConnect();
    public void finishSetStatus();
    public void checkXmlQuery(CRCLSocket crclSocket);
    public void stopPollTimer();
    public void checkPollSelected();
    public boolean isDebugWaitForDoneSelected();
    public boolean isDebugSendCommandSelected();
    public boolean isDebugReadStatusSelected();
    public void showCurrentProgramLine(int line);
    public void showLastProgramLineExecTimeMillisDists(long millis, double dist);
    public void finishOpenXmlProgramFile(File f, CRCLProgramType program);
    public CRCLProgramType editProgram(CRCLProgramType program);
    public boolean isRecordPoseSelected();
    public boolean isEXISelected();
    public boolean isUseReadStatusThreadSelected();
}
