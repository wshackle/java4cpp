#!/bin/sh

set -x;
if test "x${JAVA_HOME}" = "x"; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/ ;
fi

ls -ld "${JAVA_HOME}"; 
if uname -m | grep 64 >/dev/null 2>/dev/null ; then
    export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ;
else
    export JVM_LIBDIR="${JAVA_HOME}/jre/lib/i386/server" ;
fi 
ls -ld "${JVM_LIBDIR}";
ls -l "${JVM_LIBDIR}"; 

"${JAVA_HOME}/bin/javac" -g *.java
g++ -O0 -g -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" test*.cpp use_test.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o test