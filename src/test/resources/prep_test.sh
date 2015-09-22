#!/bin/sh

set -x;
orig_dir=`pwd`;
test_dir=`pwd`
#JAVA4CPPPREPTEST.sh
if test ! -f ./prep_test.sh || grep -v '#JAVA4CPPPREPTEST.sh'  ./prep_test.sh >/dev/null 2>/dev/null ; then 
    test_dir=`(cd "${0%%prep_test.sh}"; pwd)`;
fi
( set -x; cd ${test_dir}; cd ../../../examples/test/java/test ; mvn package; cd ${orig_dir} )
