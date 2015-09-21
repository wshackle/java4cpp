#!/bin/bash

set -x;

if test "x${JAVA_HOME}" = "x" -a -d /usr/local/jdk1.8.0_60/bin/ ; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/;
fi

if test "x${JAVA_HOME}" = "x" ; then
    echo "Please install JDK 1.8 or higher and set JAVA_HOME to this directory";
    exit 1;
fi

orig_dir=`pwd`;
top_dir=`pwd`
#JAVA4CPPRUN.sh
if test ! -f ./run.sh || grep -v '#JAVA4CPPRUN.sh'  ./run.sh >/dev/null 2>/dev/null ; then 
    top_dir=`(cd "${0%%run.sh}"; pwd)`;
fi
echo ${@}
pwd
"${JAVA_HOME}/bin/java" -version

if "${JAVA_HOME}/bin/java" -version 2>&1 | grep java | grep version | grep 1.8 >/dev/null 2>/dev/null ; then
    "${JAVA_HOME}/bin/java" -jar ${top_dir}/target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ${@}
else 
    echo "PLEASE install JDK 1.8"
    exit 1;
fi


