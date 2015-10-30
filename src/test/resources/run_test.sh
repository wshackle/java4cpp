#!/bin/sh

set -x;
pwd

ulimit -c unlimited

 ./compile_test.sh  &&./test
