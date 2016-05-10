
SET mypath=%~dp0
cd %mypath%

del /S /F *.o *.obj *.log *.exe crclj*.cpp crclj*.h crclj*.hpp


if NOT exist ..\..\..\target\java4cpp-1.4-SNAPSHOT-jar-with-dependencies.jar (
        cd ..\..\.. ; 
        mvn package;
        cd %mypath%
)

set CRCL_BASE=%UserProfile%\Documents\NetBeansProjects\GitHubProjects\usnistgov\crcl
dir %CRCL_BASE%
set CRCL_JAR=%CRCL_BASE%\tools\java\crcl4java\crcl4java-utils\target\crcl4java-utils-1.4-SNAPSHOT-jar-with-dependencies.jar
dir %CRCL_JAR%
java -jar ../../../target/java4cpp-1.4-SNAPSHOT-jar-with-dependencies.jar  --verbose -p crcl -n crclj -j "%CRCL_JAR%"

REM #g++ -O0 -g -I "${JAVA_HOME}/include"  -I "${JAVA_HOME}/include/linux" src/test/resources/crclj*.cpp src/test/resources/use_crcl.cpp  -L "${JVM_LIBDIR}" -Wl,--rpath "${JVM_LIBDIR}" -ljvm -o crclj_test
REM . ./compile_crclj_test.sh

REM pwd
REM ls -l crclj_test
REM ls -l `pwd`"/crclj_test"

compile_crclj_test.bat
