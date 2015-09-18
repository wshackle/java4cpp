#include <iostream>

#include "JavaForCpp.h"

using namespace JavaForCpp;

void NativeRunnable::runNative() {
     std::cout << "Ran NativeRunnable::run()" << std::endl;
}

int main(int argc, const char **argv) {
    NativeRunnable nr;
    CallRunnable cr;
    cr.call(nr);
}
