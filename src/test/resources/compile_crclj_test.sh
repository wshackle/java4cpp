#!/bin/sh

set -x;

if test ! -f ./compile_crclj_test.sh ; then 
    cd "${0%%compile_crclj_test.sh}";
fi

pwd

if test "x${JAVA_HOME}" = "x"; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/ ;
fi

ls -ld "${JAVA_HOME}"; 
export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ; 
ls -ld "${JVM_LIBDIR}";
ls -l "${JVM_LIBDIR}"; 

g++ -O0 -g -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" crclj*.cpp use_crcl.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o crclj_test