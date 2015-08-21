#!/bin/bash
set -x;

reset; 

if test ! -f ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ; then
    ( set -x; cd ../../../ ; mvn package; );
fi

rm test[0-9]*.h test[0-9]*.cpp 2>/dev/null || true

java -jar ../../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar -n test -j Test.jar;

export JAVA_HOME=/usr/local/jdk1.8.0_40/ ;
ls -ld "${JAVA_HOME}"; 
export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ; 
ls -ld "${JVM_LIBDIR}";
ls -l "${JVM_LIBDIR}";  

g++ -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" test[0-9]*.cpp use_test.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o test
ls -l test

