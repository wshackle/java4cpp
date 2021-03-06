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
export TEST_PROJECT_DIR="${BASE_DIR}/examples/test/java/test";

export TEST_JAR="${TEST_PROJECT_DIR}/target/test-1.0-SNAPSHOT.jar";

if uname -m | grep 64 >/dev/null 2>/dev/null ; then
    export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ;
else
    export JVM_LIBDIR="${JAVA_HOME}/jre/lib/i386/server" ;
fi

echo JAVA_HOME="${JAVA_HOME}"
ls -ld "${JAVA_HOME}"; 

if test ! -f  "${TEST_JAR}" ; then
    (cd "${TEST_PROJECT_DIR}"; mvn package );
fi

echo TEST_JAR="${TEST_JAR}"
ls -l "${TEST_JAR}"

export JAVA4CPP_JAR=`find ../../../target/ -name java4cpp*-with-dependencies.jar | head -n 1`;

#"${JAVA_HOME}/bin/java" -jar ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar -v --natives NativeRunnable=java.lang.Runnable NativeDoubleOp=java.util.function.DoubleUnaryOperator -n test -j "${TEST_JAR}";
"${JAVA_HOME}/bin/java" -jar "${JAVA4CPP_JAR}" -v --natives NativeRunnable=java.lang.Runnable -n test -j "${TEST_JAR}";
"${JAVA_HOME}/bin/javac" -g NativeRunnable.java


. ./compile_test.sh

pwd
ls -l test
ls -l `pwd`"/test"
