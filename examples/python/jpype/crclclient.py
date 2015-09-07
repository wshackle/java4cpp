#!/usr/bin/python

# CRCL Client Example using Java CRCL Library and JPype (http://jpype.sourceforge.net/)
# Run with:
# python crclclient.py

from jpype import *

startJVM("/usr/local/jdk1.8.0_60/jre/lib/i386/client/libjvm.so","-Djava.class.path=../../../crcl4java-utils/target/crcl4java-utils-1.0-SNAPSHOT-jar-with-dependencies.jar")
crcl = JPackage('crcl')
#CRCLSocket = JClass('crcl.utils.CRCLSocket')
BigInteger = JClass('java.math.BigInteger')
BigDecimal = JClass('java.math.BigDecimal')

print "Connect"
s = crcl.utils.CRCLSocket(JString("localhost"), JInt(64444))
instance = crcl.base.CRCLCommandInstanceType()

## Create and send InitCanon command
print "Send InitCanon"
init = crcl.base.InitCanonType()
init.setCommandID(BigInteger.valueOf(7))
instance.setCRCLCommand(init)
s.writeCommand(instance)
    
## Create and send MoveTo command.
print "Send MoveTo"
moveTo = crcl.base.MoveToType()
moveTo.setCommandID(BigInteger.valueOf(8))
pose = crcl.base.PoseType()
pt = crcl.base.PointType()
pt.setX(BigDecimal.valueOf(1.1))
pt.setY(BigDecimal.valueOf(0.0))
pt.setZ(BigDecimal.valueOf(0.1))
pose.setPoint(pt)
xAxis = crcl.base.VectorType()
xAxis.setI(BigDecimal.ONE)
xAxis.setI(BigDecimal.ZERO)
xAxis.setI(BigDecimal.ZERO)
pose.setXAxis(xAxis)
zAxis = crcl.base.VectorType()
zAxis.setI(BigDecimal.ZERO)
zAxis.setI(BigDecimal.ZERO)
zAxis.setI(BigDecimal.ONE)
pose.setXAxis(zAxis)
moveTo.setEndPosition(pose)
moveTo.setMoveStraight(False)
s.writeCommand(instance)


### Create and send getStatus request.
print "Send GetStatus"
getStat = crcl.base.GetStatusType()
getStat.setCommandID(BigInteger.valueOf(9))
instance.setCRCLCommand(getStat)
s.writeCommand(instance)

### Read status from server
stat = s.readStatus()


### Print out the status details.
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

shutdownJVM() 