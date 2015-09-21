#include <iostream>

#include "JavaForCpp.h"

using namespace JavaForCpp;

int main(int argc, const char **argv) {
    NativeRunnable nr;
    CallRunnable cr;
    cr.call(nr);
}
