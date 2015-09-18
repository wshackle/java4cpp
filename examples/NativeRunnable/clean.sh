#!/bin/sh

set -x;

orig_dir=`pwd`;
this_dir=`pwd`;

#CLEANNATIVERUNNABLE.sh
if test ! -f ./clean.sh || grep -v '#CLEANNATIVERUNNABLE.sh'  ./clean.sh  ; then 
    this_dir=`(cd "${0%%clean.sh}"; pwd)`;
fi

cd $this_dir;
\rm -rf nr nr.exe JavaForCpp* *.class *.o *.obj NativeRunnable.java > /dev/null 2>/dev/null || true

cd $orig_dir;