/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UPROG/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 8),
QT_MOC_LITERAL(4, 31, 10),
QT_MOC_LITERAL(5, 42, 9),
QT_MOC_LITERAL(6, 52, 5),
QT_MOC_LITERAL(7, 58, 10),
QT_MOC_LITERAL(8, 69, 23),
QT_MOC_LITERAL(9, 93, 21),
QT_MOC_LITERAL(10, 115, 12),
QT_MOC_LITERAL(11, 128, 18),
QT_MOC_LITERAL(12, 147, 13),
QT_MOC_LITERAL(13, 161, 19),
QT_MOC_LITERAL(14, 181, 13),
QT_MOC_LITERAL(15, 195, 10),
QT_MOC_LITERAL(16, 206, 2),
QT_MOC_LITERAL(17, 209, 15),
QT_MOC_LITERAL(18, 225, 17),
QT_MOC_LITERAL(19, 243, 12),
QT_MOC_LITERAL(20, 256, 2),
QT_MOC_LITERAL(21, 259, 35),
QT_MOC_LITERAL(22, 295, 4),
QT_MOC_LITERAL(23, 300, 35),
QT_MOC_LITERAL(24, 336, 33),
QT_MOC_LITERAL(25, 370, 27),
QT_MOC_LITERAL(26, 398, 5)
    },
    "MainWindow\0writeDone\0\0readDone\0"
    "writeError\0readError\0error\0nLastError\0"
    "on_pushButton_2_pressed\0on_pushButton_pressed\0"
    "getDataSheet\0getManufactureInfo\0"
    "getSchematics\0getSchematicsPixmap\0"
    "keyPressEvent\0QKeyEvent*\0vk\0keyReleaseEvent\0"
    "mouseReleaseEvent\0QMouseEvent*\0vm\0"
    "on_hfcomboBox_3_currentIndexChanged\0"
    "arg1\0on_hfcomboBox_2_currentIndexChanged\0"
    "on_hfcomboBox_currentIndexChanged\0"
    "on_tabWidget_currentChanged\0index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a,
       3,    0,  105,    2, 0x0a,
       4,    0,  106,    2, 0x0a,
       5,    0,  107,    2, 0x0a,
       6,    1,  108,    2, 0x0a,
       8,    0,  111,    2, 0x0a,
       9,    0,  112,    2, 0x0a,
      10,    0,  113,    2, 0x0a,
      11,    0,  114,    2, 0x0a,
      12,    0,  115,    2, 0x0a,
      13,    0,  116,    2, 0x0a,
      14,    1,  117,    2, 0x0a,
      17,    1,  120,    2, 0x0a,
      18,    1,  123,    2, 0x0a,
      21,    1,  126,    2, 0x0a,
      23,    1,  129,    2, 0x0a,
      24,    1,  132,    2, 0x0a,
      25,    1,  135,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->writeDone(); break;
        case 1: _t->readDone(); break;
        case 2: _t->writeError(); break;
        case 3: _t->readError(); break;
        case 4: _t->error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_2_pressed(); break;
        case 6: _t->on_pushButton_pressed(); break;
        case 7: _t->getDataSheet(); break;
        case 8: _t->getManufactureInfo(); break;
        case 9: _t->getSchematics(); break;
        case 10: _t->getSchematicsPixmap(); break;
        case 11: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 12: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 13: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 14: _t->on_hfcomboBox_3_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_hfcomboBox_2_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_hfcomboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
