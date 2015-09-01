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
 *  See http://www.copyright.gov/title17/92chap1.html#105
 * 
 */
package crcl.utils;

import crcl.base.CRCLStatusType;
import java.math.BigInteger;
import rcs.posemath.PmCartesian;
import rcs.posemath.PmPose;
import rcs.posemath.PmQuaternion;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class AnnotatedPose extends PmPose {
    
    private final long time;
    private final BigInteger cmdId;
    private final String commandName;
    private final CRCLStatusType status;

    /**
     *
     * @param time the value of time
     * @param cmdId the value of cmdId
     * @param commandName the value of commandName
     * @param starttran the value of starttran
     * @param startrot the value of startrot
     * @param status the value of status
     */
    public AnnotatedPose(
            long time, BigInteger cmdId, String commandName, PmCartesian starttran, PmQuaternion startrot, CRCLStatusType status) {
        super(starttran, startrot);
        this.time = time;
        this.cmdId = cmdId;
        this.commandName = commandName;
        this.status = status;
    }

    public long getTime() {
        return time;
    }

    public BigInteger getCmdId() {
        return cmdId;
    }

    public String getCommandName() {
        return commandName;
    }

    public PmCartesian getTran() {
        return tran;
    }

    public PmQuaternion getRot() {
        return rot;
    }

    public CRCLStatusType getStatus() {
        return status;
    }
    
    
    
}
