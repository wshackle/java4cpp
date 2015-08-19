#!/bin/bash
set -x;

reset; 

if test ! -f target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ; then
    mvn package;
fi

rm test*.h test*.cpp 2>/dev/null || true

java -jar target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar -n test -j src/test/resources/Test.jar;

export JAVA_HOME=/usr/local/jdk1.8.0_40/ ;
ls -ld "${JAVA_HOME}"; 
export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ; 
ls -ld "${JVM_LIBDIR}";
ls -l "${JVM_LIBDIR}";  

rm src/test/resources/test*.cpp src/test/resources/test*.h 2>/dev/null || true

cp test*.h test*.cpp src/test/resources/ ; 
rm test*.h test*.cpp 2>/dev/null || true
 g++ -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" src/test/resources/test*.cpp src/test/resources/use_test.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o test
ls -l test

