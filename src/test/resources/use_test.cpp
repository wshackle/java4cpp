
#include "test.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "test_nativerunnable.h"

using namespace test::testpackage;
using namespace test;
using namespace test::java::lang;
using namespace std;

int main(int argc, const char **argv) {

    try {


        Test t1;
        NativeRunnable nr;
        t1.setRunnable(nr);
        int start_number = nr.context->run_count;
        t1.runRunnable();
        if(nr.context->run_count != start_number + 1) {
            cerr << __FILE__ << ":" << __LINE__ << " (nr.context->run_count=" << nr.context->run_count << ") != (start_number + 1 = " << (start_number + 1) << ")" << endl;
            exit(1);
        }
        
//        NativeDoubleOp ndo;
//        t1.setDoubleOp(ndo);
//        jdouble dout = t1.applyDoubleOp(3.4);
//        cout << "dout = " << dout << endl;
//        if(abs(dout-4.4)> 0.01) {
//            cerr << __FILE__ << ":" << __LINE__ << " (abs(dout-4.4)=" << abs(dout-4.4) << ") > 0.01 "  << endl;
//            exit(1);
//        }
        
        t1.setI(13);
        PrintObject("t1=", t1);
        jint i = t1.getI();
        if (i != 13) {
            cerr << __FILE__ << ":" << __LINE__ << " (i=" << i << ") != 13" << endl;
            exit(1);
        }
        t1.setByteProp(14);
        jbyte b = t1.getByteProp();
        if (b != 14) {
            cerr << __FILE__ << ":" << __LINE__ << " (b=" << b << ") != 14" << endl;
            exit(1);
        }
        t1.setCharProp(15);
        jchar c = t1.getCharProp();
        if (c != 15) {
            cerr << __FILE__ << ":" << __LINE__ << " (c=" << c << ") != 15" << endl;
            exit(1);
        }
        t1.setShortProp(16);
        jshort s = t1.getShortProp();
        if (s != 16) {
            cerr << __FILE__ << ":" << __LINE__ << " (s=" << s << ") != 16" << endl;
            exit(1);
        }
        t1.setIntProp(17);
        i = t1.getIntProp();
        if (i != 17) {
            cerr << __FILE__ << ":" << __LINE__ << " (i=" << i << ") != 17" << endl;
            exit(1);
        }
        t1.setLongProp(18);
        jlong l = t1.getLongProp();
        if (l != 18) {
            cerr << __FILE__ << ":" << __LINE__ << " (l=" << l << ") != 18" << endl;
            exit(1);
        }
        t1.setFloatProp(19.5);
        jfloat f = t1.getFloatProp();
        if (abs(f - 19.5) > 0.0001) {
            cerr << __FILE__ << ":" << __LINE__ << " (f=" << f << ") != 19.5" << endl;
            exit(1);
        }
        t1.setDoubleProp(21.75);
        jdouble d = t1.getDoubleProp();
        if (abs(d - 21.75) > 0.0001) {
            cerr << __FILE__ << ":" << __LINE__ << " (d=" << f << ") != 21.75" << endl;
            exit(1);
        }
        t1.setStrProp("myString");
        jstring js = t1.getStrProp();
        const char *str = GetStringUTFChars(js);
        if (strcmp(str, "myString") != 0) {
            cerr << __FILE__ << ":" << __LINE__ << " (str=\"" << str << "\") != \"myString\"" << endl;
            exit(1);
        }
        ReleaseStringUTFChars(js, str);
        str = NULL;


        // Arrays
        jboolean boola[3] = {JNI_TRUE, JNI_FALSE, JNI_TRUE};
        t1.setBooleanArrayProp(boola, 3);
        jbooleanArray jboola = t1.getBooleanArrayProp();
        cout << "jboola=" << jboola << endl;
        PrintJBooleanArray("jboola=", jboola);
        jboolean *boolp = GetBooleanArrayElements(jboola);
        if (boola[0] != boolp[0] || boola[1] != boolp[1] || boola[2] != boolp[2]) {
            cerr << __FILE__ << ":" << __LINE__ << " boolean array elements do not match. " << endl;
            exit(1);
        }
        ReleaseBooleanArrayElements(jboola, boolp);

        jbyte bytea[3] = {22, 23, 24};
        t1.setByteArrayProp(bytea, 3);
        jbyteArray jbytea = t1.getByteArrayProp();
        PrintJByteArray("jbytea=", jbytea);
        jbyte *bytep = GetByteArrayElements(jbytea);
        if (bytea[0] != bytep[0] || bytea[1] != bytep[1] || bytea[2] != bytep[2]) {
            cerr << __FILE__ << ":" << __LINE__ << " byte array elements do not match. " << endl;
            exit(1);
        }
        ReleaseByteArrayElements(jbytea, bytep);

        jchar chara[3] = {'a', 'b', 'c'};
        t1.setCharArrayProp(chara, 3);
        jcharArray jchara = t1.getCharArrayProp();
        PrintJCharArray("jchara=", jchara);
        jchar *charp = GetCharArrayElements(jchara);
        if (chara[0] != charp[0] || chara[1] != charp[1] || chara[2] != charp[2]) {
            cerr << __FILE__ << ":" << __LINE__ << " char array elements do not match. " << endl;
            exit(1);
        }
        ReleaseCharArrayElements(jchara, charp);

        jshort shorta[3] = {31, 32, 33};
        t1.setShortArrayProp(shorta, 3);
        jshortArray jshorta = t1.getShortArrayProp();
        PrintJShortArray("jshorta=", jshorta);
        jshort *shortp = GetShortArrayElements(jshorta);
        if (shorta[0] != shortp[0] || shorta[1] != shortp[1] || shorta[2] != shortp[2]) {
            cerr << __FILE__ << ":" << __LINE__ << " short array elements do not match. " << endl;
            exit(1);
        }
        ReleaseShortArrayElements(jshorta, shortp);

        jint inta[3] = {28, 29, 30};
        t1.setIntArrayProp(inta, 3);
        jintArray jinta = t1.getIntArrayProp();
        PrintJIntArray("jinta=", jinta);
        jint *intp = GetIntArrayElements(jinta);
        if (inta[0] != intp[0] || inta[1] != intp[1] || inta[2] != intp[2]) {
            cerr << __FILE__ << ":" << __LINE__ << " int array elements do not match. " << endl;
            exit(1);
        }
        ReleaseIntArrayElements(jinta, intp);



        jlong longa[3] = {34, 35, 36};
        t1.setLongArrayProp(longa, 3);
        jlongArray jlonga = t1.getLongArrayProp();
        PrintJLongArray("jlonga=", jlonga);
        jlong *longp = GetLongArrayElements(jlonga);
        if (longa[0] != longp[0] || longa[1] != longp[1] || longa[2] != longp[2]) {
            cerr << __FILE__ << ":" << __LINE__ << " long array elements do not match. " << endl;
            exit(1);
        }
        ReleaseLongArrayElements(jlonga, longp);

        jfloat floata[3] = {37.5, 38.0, 39.75};
        t1.setFloatArrayProp(floata, 3);
        jfloatArray jfloata = t1.getFloatArrayProp();
        PrintJFloatArray("jfloata=", jfloata);
        jfloat *floatp = GetFloatArrayElements(jfloata);
        if (abs(floata[0] - floatp[0]) > 0.001 || abs(floata[1] - floatp[1]) > 0.001 || abs(floata[2] - floatp[2]) > 0.001) {
            cerr << __FILE__ << ":" << __LINE__ << " float array elements do not match. " << endl;
            exit(1);
        }
        ReleaseFloatArrayElements(jfloata, floatp);

        jdouble doublea[3] = {41.25, 42.5, 43.75};
        t1.setDoubleArrayProp(doublea, 3);
        jdoubleArray jdoublea = t1.getDoubleArrayProp();
        PrintJDoubleArray("jdoublea=", jdoublea);
        jdouble *doublep = GetDoubleArrayElements(jdoublea);
        if (abs(doublea[0] - doublep[0]) > 0.001 || abs(doublea[1] - doublep[1]) > 0.001 || abs(doublea[2] - doublep[2]) > 0.001) {
            cerr << __FILE__ << ":" << __LINE__ << " double array elements do not match. " << endl;
            exit(1);
        }
        ReleaseDoubleArrayElements(jdoublea, doublep);

        PrintObject("t1.getExternalPublicEnumProp()= ", t1.getExternalPublicEnumProp());

        Test t2;
        t2.setI(52);
        PrintObject("t2=", t2);
        cout << "Assign t1=t2 " << endl;
        t1 = t2;

        if (t1.getI() != 52) {
            cerr << __FILE__ << ":" << __LINE__ << " value of t1 not set after assignment to t2 " << endl;
            exit(1);
        }
        
        t2.setNonstaticIntField(4321);
        if(t2.getNonstaticIntField() != 4321) {
            cerr << __FILE__ << ":" << __LINE__ << " t2.getNonstaticIntField() != 4321" << endl;
            exit(1);
        }
        
        t2.setNonstaticIntegerField(Integer::valueOf(987));
        if(t2.getNonstaticIntegerField().intValue() != 987) {
            cerr << __FILE__ << ":" << __LINE__ << " t2.getNonstaticIntegerField().getValue() != 987" << endl;
            exit(1);
        }
        
        t2.setStaticIntField(753);
        if(t2.getStaticIntField() != 753) {
            cerr << __FILE__ << ":" << __LINE__ << " t2.getStaticIntField() != 753" << endl;
            exit(1);
        }
        
        t2.setStaticIntegerField(Integer::valueOf(951));
        if(t2.getStaticIntegerField().intValue() != 951) {
            cerr << __FILE__ << ":" << __LINE__ << " t2.getStaticIntegerField().intValue() != 951" << endl;
            exit(1);
        }
        
        t2.setEnumABC(TestMyEnum::getA());
        if(!t2.getEnumABC().equals(TestMyEnum::getA())) {
            cerr << __FILE__ << ":" << __LINE__ << " !t2.getEnumABC().equals(TestMyEnum::getA()" << endl;
            exit(1);
        }
        //    MyClient mc("localhost",8080);
        //    PrintObject("mc=",mc);
        //    
        //    //SetDebugJ4Cpp(true);
        //    Test t;
        //    A a;
        //    t.setStrProp("hello");
        //    PrintJObject("t.getStrProp()=",t.getStrProp());
        //    
        //    t.setClassObjectA(a);
        //    A b = t.getClassObjectA();
        //    PrintObject("b=",b);
        //    
        //    jint i  = t.getI();
        //    cout << "i = " << i << endl;
        //    jstring str = t.funcReturningString();
        //    jboolean iscopy = false;
        //    const char *cstr = test::getEnv()->GetStringUTFChars(str,&iscopy);
        //    cout << "str = " <<  cstr << endl;
        //    cout << "iscopy=" << (iscopy==JNI_TRUE) << endl;
        //    if(iscopy == JNI_TRUE) {
        //        test::getEnv()->ReleaseStringUTFChars(str,cstr);
        //    }
        //    cstr = test::getEnv()->GetStringUTFChars(t.toString(),&iscopy);
        //    cout << "t.toString() = " <<  cstr << endl;
        //    test::getEnv()->ReleaseStringUTFChars(str,cstr);
        ////    std::string args[] = { "-a","1","-b","2","-c","3"};
        //    Test::main(argc,argv);
        //    Test t2 = Test::getTestStatic();
        //    cstr = test::getEnv()->GetStringUTFChars(t2.toString(),&iscopy);
        //    cout << "t2.toString() = " <<  cstr << endl;
        //    test::getEnv()->ReleaseStringUTFChars(str,cstr);
        //    i  = t2.getI();
        //    cout << "i = " << i << endl;
        cout << "End of C++ main " << endl;
    } catch (jthrowable t) {
        PrintJThrowable("Exception Thrown : ", t);
    }
}