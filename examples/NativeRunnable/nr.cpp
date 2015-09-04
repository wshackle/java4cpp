#include <iostream>

#include "JavaForCpp.h"

using namespace JavaForCpp;

void NativeRunnable::run() {
     std::cout << "ran NativeRunnable::run()" << std::endl;
}

int main(int argc, const char **argv) {
    NativeRunnable nr;
    nr.run();
}
