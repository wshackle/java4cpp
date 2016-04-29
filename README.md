Java 4 C++ (java4cpp)
====

A utility for  creating C++ wrapper classes for a Java Library(.jar file) or class file.

Build
-----


To build one needs:
  * JDK 1.8+ (http://www.oracle.com/technetwork/java/javase/downloads/index.html)  and
  * maven(https://maven.apache.org/download.cgi) 
  
Use the command:

    mvn package
    
OR 

  * An IDE bundled with both maven and a JDK such as Netbeans, IntelliJ, or Eclipse.
      * Netbeans will open a maven project with File -> Open Project just like Netbeans generated Ant projects.
      * IntelliJ and Eclipse both have options to import maven projects.

Run
---

Run directly with: 

    java -jar target/java4cpp-1.2-SNAPSHOT-jar-with-dependencies.jar
    
Possible options are:


     -?,--help              Print this message
     -c,--class <arg>       Single Java class to extract.
     -h,--header <arg>      Output C++ header file.
     -j,--jar <arg>         Input jar file
     -l,--limit <arg>       Maximum limit on classes to extract from
                            jars.[default=200]
     -n,--namespace <arg>   C++ namespace for newly generated classes.
     -o,--output <arg>      Output C++ source file.
     -p,--package <arg>     Java Package prefix to extract


Example
-------

Given the following java class:


    public class Simple {

        final int value;

        public Simple(int value) {
            this.value = value;
        }

        public int getValue() {
            return value;
        }
    }

Compiled just with:

     javac Simple.java

C++ header and sources could be generated with:

    java -jar ../../target/java4cpp-1.0-SNAPSHOT-jar-with-dependencies.jar -c Simple 

So that the C++ code to use the class could be just this:


    #include "simple.h"
    #include <iostream>

    using namespace simple;
    using namespace std;

    int main(int argc, const  char **argv){

            Simple s(4);
            cout << "s.getValue() = " << s.getValue() << endl;

    }

For complete compile and link instructions, Visual Studio Solution and Project files etc. see the examples/simple subdirectory. For more advanced options see the other examples directories( TO BE DEVELOPED ) and/or wiki (https://github.com/wshackle/java4cpp/wiki) 


[![Build Status](https://travis-ci.org/wshackle/java4cpp.svg)](https://travis-ci.org/wshackle/java4cpp)
