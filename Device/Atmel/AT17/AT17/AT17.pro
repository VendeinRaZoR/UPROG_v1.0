#-------------------------------------------------
#
# Project created by QtCreator 2021-12-14T18:02:31
#
#-------------------------------------------------

QT       -= gui

TARGET = AT17
TEMPLATE = lib

DEFINES += AT17_LIBRARY

SOURCES += AT17.cpp

HEADERS += AT17.h\
        at17_global.h \
    ../../../../UProgBase.h \
    ../../../../UControlBase.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

contains(QT_ARCH, i386) {

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lI2C
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lI2C

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lQParallelPort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lQParallelPort

} else {

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lI2C
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lI2C

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lQParallelPort
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lQParallelPort

}

INCLUDEPATH += $$PWD/../../../../Interface/I2C/I2C
DEPENDPATH += $$PWD/../../../../Interface/I2C/I2C

INCLUDEPATH += $$PWD/../../../../Interface/QParallelPort/QParallelPort
DEPENDPATH += $$PWD/../../../../Interface/QParallelPort/QParallelPort
