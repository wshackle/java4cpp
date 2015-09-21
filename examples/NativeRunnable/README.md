
NativeRunnable Example
----------------------

This provides an example where a C++ class is created to implement a Java Interface.

The script build.sh builds and runs the example.
The script clean.sh deletes all files created by build.sh.

The build script sets up the implementation so it can be used from either C++ or Java.

The argument to java4cpp --natives NativeRunnable=java.lang.Runnable tells java4cpp to generate a stub java class that will be implented in C++.  

nr.cpp implements this class.

main.cpp creates an intsance of NativeRunnable and passes it as an argument to a Java class that will then callback to the C++ class.

