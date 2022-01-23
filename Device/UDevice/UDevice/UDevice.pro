#-------------------------------------------------
#
# Project created by QtCreator 2021-12-15T13:17:27
#
#-------------------------------------------------

QT       -= gui

TARGET = UDevice
TEMPLATE = lib

DEFINES += UDEVICE_LIBRARY

SOURCES += \
    UDevice.cpp

HEADERS +=\
        udevice_global.h \
    UDevice.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

contains(QT_ARCH, i386) {

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lI2C
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lI2C

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lQParallelPort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lQParallelPort

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lAT17
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lAT17

} else {

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lI2C
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lI2C

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lQParallelPort
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lQParallelPort

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lAT17
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lAT17

}

INCLUDEPATH += $$PWD/../../Atmel/AT17/AT17
DEPENDPATH += $$PWD/../../Atmel/AT17/AT17

INCLUDEPATH += $$PWD/../../../Interface/I2C/I2C
DEPENDPATH += $$PWD/../../../Interface/I2C/I2C

INCLUDEPATH += $$PWD/../../../Interface/QParallelPort/QParallelPort
DEPENDPATH += $$PWD/../../../Interface/QParallelPort/QParallelPort
