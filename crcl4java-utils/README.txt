To Build:

Download the latest JDK (at-least 1.8+)  from http://www.oracle.com/technetwork/java/javase/downloads/index.html

( getting the bundled Netbeans is recommended but not required)

To build with netbeans simply open this directory as a project (File-> Open Project ...)  and choose 
(Run -> Build Project (CRCLJava) ).

To build on the command line:

export JAVA_HOME=[path_to_jdk_1.8+]
sudo apt-get install maven
mvn clean package

To run graphical launcher:

[path_to_jdk_1.8+]/bin/java -jar target/CRCLJava-1.0-SNAPSHOT-jar-with-dependencies.jar 

or use the convenience scripts run.sh or run.bat

./run.sh

or on Windows

run.bat


For example to run the server in the background on port 5004

./run.sh --mode CmdLineServer --port 5004 &

or on Windows

run.bat --mode CmdLineServer --port 5004

To have the client send a program one command at a time and check status:

./run.sh --mode CmdLineClient --host localhost --port 5004 --program ../xml/crcl/xmlInstanceFiles/programExample.xml

or on Windows

run.bat --mode CmdLineClient --host localhost --port 5004 --program ..\xml\crcl\xmlInstanceFiles\programExample.xml

The program shows two buttons to launch either the server or client (one could even launch multiple clients/servers)
