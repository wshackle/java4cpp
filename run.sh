#!/bin/sh

#CRCL4JAVARUN.sh
if test ! -f ./run.sh || grep -v '#CRCL4JAVARUN.sh'  ./run.sh  ; then 
    cd "${0%%run.sh}";
fi

if test "x" != "x${JAVA_HOME}" ; then
    export PATH="${JAVA_HOME}/bin/:${PATH}";
fi

export JARFILE=crcl4java-ui/target/crcl4java-ui-1.0-SNAPSHOT-jar-with-dependencies.jar
if test ! -f "${JARFILE}" ; then
    mvn -version || ( echo "Please install maven." && false)
    mvn package
fi;

\rm -f run[0-9]*.log run[0-9]*.err >/dev/null 2>/dev/null || true

java -jar "${JARFILE}" $* > run$$.log 2> run$$.err

