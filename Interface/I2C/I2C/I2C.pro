#-------------------------------------------------
#
# Project created by QtCreator 2021-12-14T18:08:29
#
#-------------------------------------------------

QT       -= gui

TARGET = I2C
TEMPLATE = lib

DEFINES += I2C_LIBRARY

SOURCES += \
    I2CLPT.cpp

HEADERS +=\
        i2c_global.h \
    I2CLPT.h \
    I2C.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

contains(QT_ARCH, i386) {

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lQParallelPort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lQParallelPort

} else {

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lQParallelPort
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lQParallelPort

}

INCLUDEPATH += $$PWD/../../QParallelPort/QParallelPort
DEPENDPATH += $$PWD/../../QParallelPort/QParallelPort
