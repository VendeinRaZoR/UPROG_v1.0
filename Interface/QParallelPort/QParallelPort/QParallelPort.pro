#-------------------------------------------------
#
# Project created by QtCreator 2021-12-14T18:15:31
#
#-------------------------------------------------

QT       -= gui

TARGET = QParallelPort
TEMPLATE = lib

DEFINES += QPARALLELPORT_LIBRARY

SOURCES += \
    QParallelPort.cpp

HEADERS +=\
        qparallelport_global.h \
    QParallelPort.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

!unix:!macx|win32: LIBS += -L$$PWD/../../inpout32/ -linpout32

INCLUDEPATH += $$PWD/../../inpout32
DEPENDPATH += $$PWD/../../inpout32
