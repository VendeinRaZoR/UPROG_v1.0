set UPROG_NAME=UPROG
set UDEVICE_NAME=UDevice
set AT17_NAME=AT17
set I2C_NAME=I2C
set QPARALLELPORT_NAME=QParallelPort
MKDIR Debug
MKDIR Debug/UPROG
XCOPY /Y ..\..\..\%UPROG_NAME%\images Debug\%UPROG_NAME%\images\
XCOPY /Y ..\..\..\%UPROG_NAME%\json Debug\%UPROG_NAME%\json\
XCOPY /Y /S /E ..\..\..\%UPROG_NAME%\schematics Debug\%UPROG_NAME%\schematics\
XCOPY /Y ..\..\..\UPROG\build-UPROG-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug\python Debug\%UPROG_NAME%\bin\python\
COPY  /Y ..\..\..\UPROG\build-UPROG-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug\debug\UPROG.exe Debug\UPROG\bin\UPROG.exe
COPY /Y ..\..\..\Device\%UDEVICE_NAME%\build-%UDEVICE_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug\debug\%UDEVICE_NAME%.dll Debug\UPROG\bin\%UDEVICE_NAME%.dll
COPY /Y ..\..\..\Device\Atmel\%AT17_NAME%\build-%AT17_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug\debug\%AT17_NAME%.dll Debug\UPROG\bin\%AT17_NAME%.dll
COPY /Y ..\..\..\Interface\%I2C_NAME%\build-%I2C_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug\debug\%I2C_NAME%.dll Debug\UPROG\bin\%I2C_NAME%.dll
COPY /Y ..\..\..\Interface\%QPARALLELPORT_NAME%\build-%QPARALLELPORT_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug\debug\%QPARALLELPORT_NAME%.dll Debug\UPROG\bin\%QPARALLELPORT_NAME%.dll
XCOPY /Y /S /E DLL\Debug Debug\UPROG\bin\
ECHO UPROG > Debug\UPROG\bin\UPROG.bat
ECHO CD Debug\UPROG\bin\ > UPROG_Debug.bat
ECHO UPROG >> UPROG_Debug.bat
ECHO DEPLOY DONE
pause