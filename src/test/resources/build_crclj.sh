#!/bin/sh
set -x;

reset; 

if test ! -f ./build_crclj.sh ; then 
    cd "${0%%build_crclj.sh}";
fi

rm *.o *.obj core hs_err*.log


if test ! -f ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ; then
    ( set -x; cd ../../../ ; mvn package; );
fi

rm crclj*.cpp crclj*.h core core.[0-9]* hs_*.log *.o crclj_test >2/dev/null 

java -jar ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar  -p crcl -n crclj -j ${HOME}/crac/CRCLJava/target/CRCLJava-1.0-SNAPSHOT-jar-with-dependencies.jar;

#g++ -O0 -g -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" src/test/resources/crclj*.cpp src/test/resources/use_crcl.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o crclj_test
. ./compile_crclj_test.sh

pwd
ls -l crclj_test
ls -l `pwd`"/crclj_test"

