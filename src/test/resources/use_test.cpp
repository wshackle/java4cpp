
#include "test.h"
#include <iostream>

using namespace test::testpackage;
using namespace test;
using namespace std;

int main(int argc, const char **argv) {
    
    //SetDebugJ4Cpp(true);
    Test t;
    jint i  = t.getI();
    cout << "i = " << i << endl;
    jstring str = t.funcReturningString();
    jboolean iscopy = false;
    const char *cstr = test::getEnv()->GetStringUTFChars(str,&iscopy);
    cout << "str = " <<  cstr << endl;
    cout << "iscopy=" << (iscopy==JNI_TRUE) << endl;
    if(iscopy == JNI_TRUE) {
        test::getEnv()->ReleaseStringUTFChars(str,cstr);
    }
    cstr = test::getEnv()->GetStringUTFChars(t.toString(),&iscopy);
    cout << "t.toString() = " <<  cstr << endl;
    test::getEnv()->ReleaseStringUTFChars(str,cstr);
//    std::string args[] = { "-a","1","-b","2","-c","3"};
    Test::main(argc,argv);
    Test t2 = Test::getTestStatic();
    cstr = test::getEnv()->GetStringUTFChars(t2.toString(),&iscopy);
    cout << "t2.toString() = " <<  cstr << endl;
    test::getEnv()->ReleaseStringUTFChars(str,cstr);
    i  = t2.getI();
    cout << "i = " << i << endl;
}