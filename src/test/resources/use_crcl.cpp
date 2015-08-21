
#include "crclj.h"
#include <iostream>

using namespace crclj;
using namespace crclj::crcl::base;
using namespace crclj::crcl::utils;
using namespace crclj::java::math;
using namespace crclj::java::util;

using namespace std;

int main(int argc, const char **argv) {

    try {
        // Connect to the server
        CRCLSocket s("localhost", 64444);


        // Create an instance to wrap all commands.
        CRCLCommandInstanceType instance;

        // Create and send init command.
        InitCanonType initCmd;
        initCmd.setCommandID(BigInteger::valueOf(7));
        instance.setCRCLCommand(initCmd);
        s.writeCommand(instance, JNI_FALSE);

        // Create and send MoveTo command.
        MoveToType moveTo;
        moveTo.setCommandID(BigInteger::valueOf(8));
        PoseType pose;
        PointType pt;
        pt.setX(BigDecimal::valueOf(1.1));
        pt.setY(BigDecimal::valueOf(0.0));
        pt.setZ(BigDecimal::valueOf(0.1));
        pose.setPoint(pt);
        VectorType xAxis;
        xAxis.setI(BigDecimal::getONE());
        xAxis.setI(BigDecimal::getZERO());
        xAxis.setI(BigDecimal::getZERO());
        pose.setXAxis(xAxis);
        VectorType zAxis;
        zAxis.setI(BigDecimal::getZERO());
        zAxis.setI(BigDecimal::getZERO());
        zAxis.setI(BigDecimal::getZERO());
        pose.setXAxis(zAxis);
        moveTo.setEndPosition(pose);
        moveTo.setMoveStraight(false);
        s.writeCommand(instance, false);


        GetStatusType getStat;
        getStat.setCommandID(BigInteger::valueOf(9));
        instance.setCRCLCommand(getStat);
        s.writeCommand(instance, JNI_FALSE);
        
        CRCLStatusType stat = s.readStatus(JNI_FALSE);
        CommandStatusType cmdStat = stat.getCommandStatus();
        BigInteger IDback = cmdStat.getCommandID();
        PrintObject("Command ID=", IDback);
        PrintObject("stat=",stat);
        pose = stat.getPose();
        PrintObject("pose=",pose);
        pt = pose.getPoint();
        PrintObject("X:",pt.getX());
        PrintObject("Y:",pt.getY());
        PrintObject("Z:",pt.getZ());
        JointStatusesType jst = stat.getJointStatuses();
        List l = jst.getJointStatus();
        for (int i = 0; i < l.size(); i++) {
            JointStatusType elem;
            elem = JointStatusType::cast(l.get(i));
            PrintObject("Joint Number :",elem.getJointNumber());
            PrintObject("Joint Position :",elem.getJointPosition());
        }

        cout << " End of C++ main() reached. " << endl;
    } catch (jthrowable t) {
        PrintJThrowable("Exception Thrown : ", t);
    }
}