#include <iostream>

#include "javaforcpp.h"


namespace javaforcpp {

    class NativeRunnableContext {
        // add any data to store per object
    };

    void NativeRunnable::runNative() {
        std::cout << "Ran NativeRunnable::run()" << std::endl;
    }

    void NativeRunnable::initContext(NativeRunnableContext *ctx, bool isref) {
        std::cout << "Starting NativeRunnable::initContext()" << std::endl;
        context = new NativeRunnableContext();
        std::cout << "Ran NativeRunnable::initContext()" << std::endl;
    }

    void NativeRunnable::deleteContext() {
        std::cout << "Starting NativeRunnable::deleteContext()" << std::endl;
        if (NULL != context) {
            delete context;
        }
        std::cout << "Ran NativeRunnable::deleteContext()" << std::endl;
    }
}
