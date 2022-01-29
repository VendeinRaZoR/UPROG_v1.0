#-------------------------------------------------
#
# Project created by QtCreator 2022-01-29T18:45:19
#
#-------------------------------------------------

QT       -= gui

TARGET = PatternDev
TEMPLATE = lib

DEFINES += PATTERNDEV_LIBRARY

SOURCES += patterndev.cpp

HEADERS += patterndev.h\
        patterndev_global.h \
    ../../../../UProgBase.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
