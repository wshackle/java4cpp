#!/bin/sh

set -x;
if test "x${JAVA_HOME}" = "x"; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/ ;
fi

ls -ld "${JAVA_HOME}"; 
if uname -m | grep 64 >/dev/null 2>/dev/null ; then
    if test -d "${JAVA_HOME}/jre/lib/amd64/server" ; then 
        export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ;
    elif test -d "${JAVA_HOME}/jre/lib/server" ; then
      export JVM_LIBDIR="${JAVA_HOME}/jre/lib/server" ;
    elif test -d "${JAVA_HOME}/lib/server" ; then
      export JVM_LIBDIR="${JAVA_HOME}/lib/server" ;
    else 
        echo "NO JVM_LIBDIR"
        exit 1;
    fi
else
    if test -d "${JAVA_HOME}/jre/lib/i386/server" ; then 
        export JVM_LIBDIR="${JAVA_HOME}/jre/lib/i386/server" ;
    elif test -d "${JAVA_HOME}/jre/lib/server" ; then
      export JVM_LIBDIR="${JAVA_HOME}/jre/lib/server" ;
    elif test -d "${JAVA_HOME}/lib/server" ; then
      export JVM_LIBDIR="${JAVA_HOME}/lib/server" ;
    else 
        echo "NO JVM_LIBDIR"
        exit 1;
    fi   
fi 
ls -ld "${JVM_LIBDIR}";
ls -l "${JVM_LIBDIR}"; 

"${JAVA_HOME}/bin/javac" -g NativeRunnable.java
g++ -O0 -g -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" test_nativerunnable.cpp test0.cpp test1.cpp use_test.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o test 2> /tmp/compile_err$$.txt || (cat /tmp/compile_err$$.txt && exit 1)