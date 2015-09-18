#!/bin/bash

set -x;
orig_dir=`pwd`;
top_dir=`pwd`
#JAVA4CPPRUN.sh
if test ! -f ./run.sh || grep -v '#JAVA4CPPRUN.sh'  ./run.sh >/dev/null 2>/dev/null ; then 
    top_dir=`(cd "${0%%run.sh}"; pwd)`;
fi
echo ${@}
pwd
java -jar ${top_dir}/target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar ${@}


