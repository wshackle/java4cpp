#!/bin/sh

set -x;

if test ! -e ./nr ; then
    ./build.sh
fi

./nr
