#!/bin/sh

set -x;

if test ! -e ./nr ; then
    ./build.sh
fi

echo Running with C++ main
./nr || exit 1

echo 

if test "x${JAVA_HOME}" = "x" -a -d /usr/local/jdk1.8.0_60/bin/ ; then
    export JAVA_HOME=/usr/local/jdk1.8.0_60/;
fi

if test "x${JAVA_HOME}" = "x" ; then
    echo "Please install JDK 1.8 or higher and set JAVA_HOME to this directory";
    exit 1;
fi

echo Running with Java main
echo 
echo "${JAVA_HOME}/bin/java" CallNativeRunnable 
echo

"${JAVA_HOME}/bin/java" CallNativeRunnable || exit 1


