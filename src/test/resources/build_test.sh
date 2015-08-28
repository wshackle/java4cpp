#!/bin/bash
set -x;

reset; 

if test ! -f ./build_test.sh ; then 
    cd "${0%%build_test.sh}";
fi

rm core hs_*.log *.o *.obj

if test ! -f ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ; then
    ( set -x; cd ../../../ ; mvn package; );
fi

rm test[0-9]*.h test[0-9]*.cpp 2>/dev/null || true

export BASE_DIR=`( cd ../../..; pwd )`;
export TEST_PROJECT_DIR="${BASE_DIR}/examples/test/java/Test";

export TEST_JAR="${TEST_PROJECT_DIR}/dist/Test.jar";

if test "x${JAVA_HOME}" = "x"; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/ ;
fi

echo JAVA_HOME="${JAVA_HOME}"
ls -ld "${JAVA_HOME}"; 

if test ! -f  "${TEST_JAR}" ; then
    (cd "${TEST_PROJECT_DIR}"; ant -Dplatforms.JDK_1.7.home="${JAVA_HOME}"  jar );
fi

echo TEST_JAR="${TEST_JAR}"
ls -l "${TEST_JAR}"

java -jar ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar -n test -j "${TEST_JAR}";


. ./compile_test.sh

pwd
ls -l test
ls -l `pwd`"/test"
