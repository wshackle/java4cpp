
#include "crclj.h"
#include <iostream>

using namespace crclj;
using namespace crclj::crcl::base;
using namespace crclj::crcl::utils;
using namespace crclj::java::math;

using namespace std;

int main(int argc, const char **argv) {
     
    CRCLCommandInstanceType instance;
    InitCanonType initCmd;
    BigInteger ID("7");
    initCmd.setCommandID(ID);
    instance.setCRCLCommand(initCmd);
    CRCLSocket socket("localhost",64444);
    socket.writeCommand(instance,JNI_FALSE);
    GetStatusType getStat;
    getStat.setCommandID(ID);
    instance.setCRCLCommand(getStat);
    socket.writeCommand(instance,JNI_FALSE);
    CRCLStatusType stat = socket.readStatus(JNI_FALSE);
    CommandStatusType cmdStat = stat.getCommandStatus();
    BigInteger IDback = cmdStat.getCommandID();
    PrintObject("Command ID=",IDback);
    cout<< " End of C++ main() reached. " << endl;
    
}