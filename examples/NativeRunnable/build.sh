#!/bin/sh

set -x;

if test "x${JAVA_HOME}" = "x" -a -d /usr/local/jdk1.8.0_60/bin/ ; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/;
fi

if test "x${JAVA_HOME}" = "x" ; then
    echo "Please install JDK 1.8 or higher and set JAVA_HOME to this directory";
    exit 1;
fi

./clean.sh


"${JAVA_HOME}/bin/javac" -g CallRunnable.java
../../run.sh -verbose -natives NativeRunnable=java.lang.Runnable -c CallRunnable --loadlibname nr || exit 1
"${JAVA_HOME}/bin/javac" -g *.java



if test "x${JVM_LIB_DIR}" = "x" ; then
    export JVM_LIB_DIR=`find ${JAVA_HOME} -name libjvm.so | head -n 1 | sed 's#libjvm.so##g'`;
fi

g++ -shared -fPIC -D_REENTRANT -D_POSIX_C_SOURCE -I "${JAVA_HOME}/include" -I "${JAVA_HOME}/include/linux" nr.cpp JavaForCpp*.cpp -o libnr.so

g++ -D_REENTRANT -D_POSIX_C_SOURCE -I "${JAVA_HOME}/include" -I "${JAVA_HOME}/include/linux"  main.cpp -L `pwd`  -Wl,--rpath `pwd` -lnr  -L "${JVM_LIB_DIR}" -Wl,--rpath "${JVM_LIB_DIR}" -ljvm -o nr
