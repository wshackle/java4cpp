#include <iostream>

#include "javaforcpp.h"

using namespace javaforcpp;

int main(int argc, const char **argv) {
    NativeRunnable nr;
    CallRunnable cr;
    cr.call(nr);
}
