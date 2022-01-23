set UPROG_NAME=UPROG
set UDEVICE_NAME=UDevice
set AT17_NAME=AT17
set I2C_NAME=I2C
set QPARALLELPORT_NAME=QParallelPort
MKDIR Release
MKDIR Release/UPROG
XCOPY /Y ..\..\..\%UPROG_NAME%\images Release\%UPROG_NAME%\images\
XCOPY /Y ..\..\..\%UPROG_NAME%\json Release\%UPROG_NAME%\json\
XCOPY /Y /S /E ..\..\..\%UPROG_NAME%\schematics Release\%UPROG_NAME%\schematics\
XCOPY /Y ..\..\..\UPROG\build-%UPROG_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Release\python Release\%UPROG_NAME%\bin\python\
COPY  /Y ..\..\..\UPROG\build-%UPROG_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Release\release\%UPROG_NAME%.exe Release\%UPROG_NAME%\bin\%UPROG_NAME%.exe
COPY /Y ..\..\..\Device\%UDEVICE_NAME%\build-%UDEVICE_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Release\release\%UDEVICE_NAME%.dll Release\UPROG\bin\%UDEVICE_NAME%.dll
COPY /Y ..\..\..\Device\Atmel\%AT17_NAME%\build-%AT17_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Release\release\%AT17_NAME%.dll Release\UPROG\bin\%AT17_NAME%.dll
COPY /Y ..\..\..\Interface\%I2C_NAME%\build-%I2C_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Release\release\%I2C_NAME%.dll Release\UPROG\bin\%I2C_NAME%.dll
COPY /Y ..\..\..\Interface\%QPARALLELPORT_NAME%\build-%QPARALLELPORT_NAME%-Desktop_Qt_5_0_2_MSVC2010_32bit-Release\release\%QPARALLELPORT_NAME%.dll Release\UPROG\bin\%QPARALLELPORT_NAME%.dll
XCOPY /Y /S /E DLL\Release Release\UPROG\bin\
ECHO UPROG > Release\UPROG\bin\UPROG.bat
ECHO CD Release\UPROG\bin\ > UPROG_Release.bat
ECHO UPROG >> UPROG_Release.bat
ECHO DEPLOY DONE
pause