
SET mypath=%~dp0
cd %mypath%

REM Set JDK Installation directory.
REM This will likely need to be edited on each system.
set JAVA_HOME=C:\Program Files\Java\jdk1.8.0_92

REM Set location of jvm.ib file.
set JVM_LIBDIR=%JAVA_HOME%\lib

REM Set Location of jvm.dll file.
set JVM_DLLDIR=%JAVA_HOME%\jre\bin\server

set PATH=%JAVA_HOME%\bin:%JVM_DLLDIR%:%PATH%

REM Set Visual Studio (with C++) Installation directory.
REM This will likely need to be edited on each system.
set MSVISUALC_DIR=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC

echo %MSVISUALC_DIR%

rem cd "%MSVISUALC_DIR%"
call "%MSVISUALC_DIR%\vcvarsall.bat" x64
rem cd %mypath%

REM Just check these in case we got it wrong
dir "%JAVA_HOME%"
dir "%JVM_LIBDIR%\jvm.lib"
dir "%JVM_DLLDIR%\jvm.dll"



cl.exe /EHsc /I "%JAVA_HOME%\include"  /I "%JAVA_HOME%\include\win32" crclj*.cpp use_crcl.cpp  /link "/LIBPATH:%JVM_LIBDIR%" jvm.lib /out:crclj_test.exe

