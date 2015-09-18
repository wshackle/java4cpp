#!/bin/sh

set -x;

./clean.sh

javac *.java
../../run.sh -verbose -natives NativeRunnable=java.lang.Runnable -c CallRunnable
javac *.java

if test "x${JAVA_HOME}" = "x" ; then
    export JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64/;
fi

if test "x${JVM_LIB_DIR}" = "x" ; then
    export JVM_LIB_DIR=`find ${JAVA_HOME} -name libjvm.so | head -n 1 | sed 's#libjvm.so##g'`;
fi

g++ -I "${JAVA_HOME}/include" -I "${JAVA_HOME}/include/linux"  nr.cpp JavaForCpp*.cpp -L "${JVM_LIB_DIR}" -Wl,--rpath "${JVM_LIB_DIR}" -ljvm -o nr
