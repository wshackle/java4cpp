
File Descriptions
-----------------

The java source code in Simple.java can be compiled just with:

     javac Simple.java

C++ header and sources could be generated with:

    java -jar ../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar -c Simple 

The generated files include:  
* simple.h -- C++ header to be included by users.
* simple0.h -- C++ header included by generated source. Users should not directly include this.
* simple_fwd.h -- C++ header file with forward definitions only. Can be included in other C++ header files where only partial type definitions with minimal dependancy are needed.
* simple0.cpp -- C++ generated source that makes direct JNI calls that should be compiled and linked in to the application possibly in a separate library.

The file use_simple_java.cpp contains the C++ example source code using the generated files with a main method.

Windows Build
-------------

The following instructions were tested on an x64 Windows 7 computer with Visual Studio 2010 and JDK 1.8.0_60 for Windows(x64).
Please adjust paths and settings locations as appropriate to match your system. All settings are merely suggested. Once you 
have a working setup feel free to experiment with the alternatives.


The Simple sudirectory contains the Visual Studio solutions and projects generated.

* Close Visual Studio if it is open so it will get the next environment setting change.

* Add the location of jvm.dll which comes with Java JDK to the Windows Path.
     * In Control Panel, use the text field on the upper right to search for Environment.
     * Under System , click "Edit Environment Variables For Your Account"
          * Select the item for PATH. Add the location of jvm.dll (eg "C:\Program Files\Java\jre1.8.0_60\bin\server;")
          * Click OK in that dialog and then in the parent dialog.
          
* (Re) Open Visual Studio
    * Select File -> New Project.
    * Under Templates select Visual C++, and Win32 Console Application.
    * Click Next.
    * Under Application Settings select Console Application. 
        * Check Empty Project.
        * Uncheck Precompiled Headers
        * Uncheck Security Development Lifecycle(SDL) checks
        * Uncheck ATL (if checked)
        * Uncheck MFC (if checked)
    * Select Source Files and Add Existing Item to add simple0.cpp and use_simple_java.cpp.
    * Select Header Files and Add Existing Items to add simple.h, simple0.h and simple_fwd.h.
    * If you are running on an x64 system and have the x64 version of the JDK installed:
        * Goto Build -> Configuration Manager
        * Under Active Solution Platforms choose New.
        * Under Type or select new platform choose x64.
        * Leave Copy Settings From: Win32 Selected and leave create new project platform checkbox selected, click OK.
    * Under Project -> Properties -> Configuration Properties -> VC++ Directories
        * Add the JDK's include subdirectory and the win32 subdirectory of that to the Include Directories:
             * (eg. C:\Program Files\Java\jdk1.8.0_60\include;C:\Program Files\Java\jdk1.8.0_60\include\win32;$(IncludePath) )
        * Add the JDK's lib subdirectory to Library Directories:
             * (eg. C:\Program Files\Java\jdk1.8.0_60\lib;$(LibraryPath) )
        * Click Apply
    * Under Project -> Properties -> Linker -> Input
        * Add jvm.lib to Additional Dependancies.
        * Click Apply
    * Use Build -> Build Solution to build the application.
    * Use Debug -> Start without Debugging.
        * Output window should print s.getValue() = 4. 
        * The C++ application has successfully run passing an argument to a Java class method and recieving a return value from a Java class.




