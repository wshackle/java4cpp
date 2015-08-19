#!/bin/bash
set -x;

reset; 
if test ! -f target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ; then
    mvn package;
fi

rm crclj*.cpp crclj*.h core core.[0-9]* hs_*.log *.o crclj_test >2/dev/null 

java -jar target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar  -l 10000 -n crclj -j ../crac/CRCLJava/target/CRCLJava-1.0-SNAPSHOT-jar-with-dependencies.jar;

export JAVA_HOME=/usr/local/jdk1.8.0_40/ ;
ls -ld "${JAVA_HOME}"; 
export JVM_LIBDIR="${JAVA_HOME}/jre/lib/amd64/server" ; 
ls -ld "${JVM_LIBDIR}";
ls -l "${JVM_LIBDIR}"; 
rm src/test/resources/crclj*.cpp src/test/resources/crclj*.h 2>/dev/null || true
 
cp crcl*.h crcl*.cpp src/test/resources/ ; 
rm crclj*.cpp crclj*.h 2>/dev/null || true
 g++ -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" src/test/resources/crclj*.cpp src/test/resources/use_crcl.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o crclj_test
ls -l crclj_test

