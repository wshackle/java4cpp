
NativeRunnable Example
----------------------

This provides an example where a C++ class is created to implement a Java Interface.

The script build.sh builds and runs the example.
The script clean.sh deletes all files created by build.sh.

The argument to java4cpp --natives NativeRunnable=java.lang.Runnable tells java4cpp to generate a stub java class that will be implented in C++.  

The C++ nr.cpp implements this class and passes an instance of it as an argument to a Java class that will then callback to the C++ class.
