/**************************************************************
 * This C++ file was autogenerated by java4cpp. 
 * It is intended to be modified. It will not be overwritten if it already exists.
 *
 **************************************************************/

#include "test.h"
#include "test_nativerunnable.h"

namespace test {

     void NativeRunnable::initContext(NativeRunnableContext *ctx, bool isref) {
         context = new NativeRunnableContext();
         context->run_count = 0;
    }

    void NativeRunnable::deleteContext() {
        if(NULL != context) {
            delete context;
            context = NULL;
        }
    }

    void NativeRunnable::runNative() {
        if(NULL != context) {
            context->run_count++;
        }
        return;
    }


}
// End of test

/**************************************************************
 * This C++ file was autogenerated by java4cpp. 
 * It is intended to be modified. It will not be overwritten if it already exists.
 *
 **************************************************************/