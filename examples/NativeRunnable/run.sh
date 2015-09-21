#!/bin/sh

set -x;

if test ! -e ./nr ; then
    ./build.sh
fi

echo Running with C++ main
./nr || exit 1

echo Running with Java main
java CallNativeRunnable || exit 1


