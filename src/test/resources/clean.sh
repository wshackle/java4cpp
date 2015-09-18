#!/bin/sh

set -x;

orig_dir=`pwd`;
this_dir=`pwd`;

#CLEANTESTRESOURCES.sh
if test ! -f ./clean.sh || grep -v '#CLEANTESTRESOURCES.sh'  ./clean.sh  ; then 
    this_dir=`(cd "${0%%clean.sh}"; pwd)`;
fi

cd $this_dir;

\rm *.o *.obj *.class core hs_err*.log crclj*.cpp crclj*.h core core.[0-9]* hs_*.log *.o crclj_test test[0-9]*.h test[0-9]*.cpp NativeRunnable* 2>/dev/null || true

cd $orig_dir;