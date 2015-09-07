#!/usr/bin/jython

# CRCL Client Example using Java CRCL Library and Jython (http://www.jython.org) 
# Run with:
# env CLASSPATH=../../../crcl4java-utils/target/crcl4java-utils-1.0-SNAPSHOT-jar-with-dependencies.jar jython crclclient.py

from crcl.base import *
from crcl.utils import CRCLSocket
from java.math import *
import java.lang.Boolean

print "Connect"
s = CRCLSocket("localhost", 64444)
instance = CRCLCommandInstanceType()

## Create and send InitCanon command
print "Send InitCanon"
init = InitCanonType()
init.setCommandID(BigInteger.valueOf(7))
instance.setCRCLCommand(init)
s.writeCommand(instance)
#    
## Create and send MoveTo command.
print "Send MoveTo"
moveTo = MoveToType()
moveTo.setCommandID(BigInteger.valueOf(8))
pose = PoseType()
pt = PointType()
pt.setX(BigDecimal.valueOf(1.1))
pt.setY(BigDecimal.valueOf(0.0))
pt.setZ(BigDecimal.valueOf(0.1))
pose.setPoint(pt)
xAxis = VectorType()
xAxis.setI(BigDecimal.ONE)
xAxis.setI(BigDecimal.ZERO)
xAxis.setI(BigDecimal.ZERO)
pose.setXAxis(xAxis)
zAxis = VectorType()
zAxis.setI(BigDecimal.ZERO)
zAxis.setI(BigDecimal.ZERO)
zAxis.setI(BigDecimal.ONE)
pose.setXAxis(zAxis)
moveTo.setEndPosition(pose)
moveTo.setMoveStraight(java.lang.Boolean.FALSE)
s.writeCommand(instance)


## Create and send getStatus request.
print "Send GetStatus"
getStat = GetStatusType()
getStat.setCommandID(BigInteger.valueOf(9))
instance.setCRCLCommand(getStat)
s.writeCommand(instance)

## Read status from server
stat = s.readStatus()


## Print out the status details.
cmdStat = stat.getCommandStatus()
IDback = cmdStat.getCommandID()
print "Status:"
print("CommandID = " + IDback.toString())
print("State = " + cmdStat.getCommandState().toString())
pt = stat.getPose().getPoint()
print("pose = " + pt.getX().toString() + "," + pt.getY().toString() + "," + pt.getZ().toString())
jst = stat.getJointStatuses()
l = jst.getJointStatus()
print "Joints:" 
for i in range(0,l.size()):
    js = l.get(i)
    print("Num="+js.getJointNumber().toString()+" Pos="+js.getJointPosition().toString())