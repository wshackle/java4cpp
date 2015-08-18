
#include "crclj.h"
#include <iostream>

using namespace crclj;
using namespace crclj::crcl::base;
using namespace crclj::crcl::utils;

using namespace std;

int main(int argc, const char **argv) {
    CRCLSocket socket("localhost",64444);
    CRCLCommandInstanceType instance;
    InitCanonType initCmd;
    crclj::java::math::BigInteger ID("7");
    initCmd.setCommandID(ID);
    instance.setCRCLCommand(initCmd);
    socket.writeCommand(instance,JNI_FALSE);
    cout<< " End of C++ main() reached. " << endl;
    
}