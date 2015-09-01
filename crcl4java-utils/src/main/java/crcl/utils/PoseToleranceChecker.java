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


import crcl.base.AngleUnitEnumType;
import crcl.base.PointType;
import crcl.base.PoseType;
import crcl.base.PoseToleranceType;
import crcl.base.VectorType;
import java.math.BigDecimal;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class PoseToleranceChecker {
    
    private PoseToleranceChecker() {
        // Can't call me
    }
    
    
    static public boolean containsNull(PointType pt) {
        return  pt == null
                || pt.getX() == null 
                || pt.getY() == null
                || pt.getZ() == null;
    }
    
    static public boolean containsNull(VectorType vec) {
        return  vec == null
                || vec.getI() == null 
                || vec.getJ() == null
                || vec.getK() == null;
    }
    
    
    static public boolean containsNull(PoseType pose) {
        return pose == null
                || containsNull(pose.getPoint())
                || containsNull(pose.getXAxis())
                || containsNull(pose.getZAxis());
    }
    
    static public boolean containsNull(PoseToleranceType tol) {
        return tol == null
                || tol.getXPointTolerance() == null
                || tol.getYPointTolerance() == null
                || tol.getZPointTolerance() == null
                || tol.getXAxisTolerance() == null
                || tol.getZAxisTolerance() == null;
    }
    
    
    static public boolean isInTolerance(BigDecimal v1, BigDecimal v2, BigDecimal tol) {
           return v1.subtract(v2).abs().compareTo(tol) <= 0;
    }
    
    static public boolean isInTolerance(final PointType pt1, final PointType pt2, final PoseToleranceType tol) {
        return 
                isInTolerance(pt1.getX(),pt2.getX(),tol.getXPointTolerance())
                && isInTolerance(pt1.getY(),pt2.getY(),tol.getYPointTolerance())
                && isInTolerance(pt1.getZ(),pt2.getZ(),tol.getZPointTolerance());
    }
    
    static public boolean isInTolerance(VectorType v1, VectorType v2, BigDecimal tol, AngleUnitEnumType angleType) {
        if(null == tol) {
            return true;
        }
        BigDecimal dot = CRCLPosemath.dot(v1, v2);
        if(angleType == AngleUnitEnumType.DEGREE) {
            return dot.doubleValue() > Math.cos(Math.toRadians(tol.doubleValue()));
        }
        return dot.doubleValue() > Math.cos(tol.doubleValue());
    }

    static public boolean isInTolerance(final PoseType pose1, final PoseType pose2, 
            final PoseToleranceType tol, final AngleUnitEnumType angleType) {
        return isInTolerance(pose1.getPoint(),pose2.getPoint(),tol)
               && isInTolerance(pose1.getXAxis(),pose2.getXAxis(),tol.getXAxisTolerance(),angleType)
               && isInTolerance(pose1.getZAxis(),pose2.getZAxis(),tol.getZAxisTolerance(),angleType);
    }
    
    
}
