#-------------------------------------------------
#
# Project created by QtCreator 2021-12-14T16:52:04
#
#-------------------------------------------------

QT       += core gui

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UPROG
TEMPLATE = app

load(moc)

QMAKE_MOC_SRC += -DBOOST_PYTHON_HPP_INCLUDED_


SOURCES += main.cpp\
        mainwindow.cpp \
    QPython2.cpp \
    MenuBuilder.cpp \
    dosmenu/DSLineEdit.cpp \
    dosmenu/DOSProxyStyle.cpp \
    filedialog/FileFilterProxyModel.cpp \
    fwtable/FWTableView.cpp \
    fwtable/FWTableModel.cpp \
    fwtable/FWItemDelegate.cpp \
    submenu/HFComboBox.cpp \
    MainApplication.cpp \
    submenu/HFLabel.cpp

HEADERS  += mainwindow.h \
    QPython2.h \
    MenuBuilder.h \
    dosmenu/DSLineEdit.h \
    dosmenu/DOSProxyStyle.h \
    filedialog/FileFilterProxyModel.h \
    fwtable/FWTableView.h \
    fwtable/FWTableModel.h \
    fwtable/FWTableCommon.h \
    fwtable/FWItemDelegate.h \
    submenu/HFComboBox.h \
    ../../UProgBase.h \
    ../../UControlBase.h \
    ../../UCommon.h \
    MainApplication.h \
    submenu/HFLabel.h

FORMS    += mainwindow.ui


contains(QT_ARCH, i386) {

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lI2C
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lI2C

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lQParallelPort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lQParallelPort

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Device/Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lAT17
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Device/Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lAT17

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../boost_1_59_0/lib32-msvc-10.0/ -lboost_python-vc100-mt-1_59
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../boost_1_59_0/lib32-msvc-10.0/ -lboost_python-vc100-mt-gd-1_59

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../boost_1_59_0/lib32-msvc-10.0/ -lboost_python-vc100-mt-1_59
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../boost_1_59_0/lib32-msvc-10.0/ -lboost_python-vc100-mt-gd-1_59

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../boost_1_59_0/lib32-msvc-10.0/ -llibboost_python-vc100-mt-1_59
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../boost_1_59_0/lib32-msvc-10.0/ -llibboost_python-vc100-mt-gd-1_59

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Python27/libs/ -lpython27
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Python27/libs/ -lpython27

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Device/UDevice/build-UDevice-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lUDevice
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Device/UDevice/build-UDevice-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lUDevice

} else {

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lI2C
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Interface/I2C/build-I2C-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lI2C

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lQParallelPort
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Interface/QParallelPort/build-QParallelPort-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lQParallelPort

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Device/Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lAT17
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Device/Atmel/AT17/build-AT17-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lAT17

LIBS += -L$$PWD/../../../../../../usr/lib/python2.7/config-x86_64-linux-gnu/ -lpython2.7
LIBS += -L$$PWD/../../../../../../usr/local/boost/lib/ -lboost_python

unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Device/UDevice/build-UDevice-Desktop_Qt_5_0_2_GCC_64bit-Release/ -lUDevice
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Device/UDevice/build-UDevice-Desktop_Qt_5_0_2_GCC_64bit-Debug/ -lUDevice

}

INCLUDEPATH += $$PWD/../../Interface/I2C/I2C
DEPENDPATH += $$PWD/../../Interface/I2C/I2C

INCLUDEPATH += $$PWD/../../Interface/QParallelPort/QParallelPort
DEPENDPATH += $$PWD/../../Interface/QParallelPort/QParallelPort

INCLUDEPATH += $$PWD/../../Device/Atmel/AT17/AT17
DEPENDPATH += $$PWD/../../Device/Atmel/AT17/AT17

INCLUDEPATH += $$PWD/../../Device/UDevice/UDevice
DEPENDPATH += $$PWD/../../Device/UDevice/UDevice

INCLUDEPATH += $$PWD/../../../../boost_1_59_0
DEPENDPATH += $$PWD/../../../../boost_1_59_0

INCLUDEPATH += $$PWD/../../../../Python27/include
DEPENDPATH += $$PWD/../../../../Python27/include

DEPENDPATH += $$PWD/../../../../../../usr/include/python2.7
INCLUDEPATH += $$PWD/../../../../../../usr/include/python2.7

DEPENDPATH += $$PWD/../../../../../../usr/local/boost/include
INCLUDEPATH += $$PWD/../../../../../../usr/local/boost/include

win32:CONFIG(debug, debug|release){

    QMAKE_COMPILER_DEFINES = _WIN32

}

win32:CONFIG(release, debug|release){

    QMAKE_COMPILER_DEFINES = _WIN32

}
