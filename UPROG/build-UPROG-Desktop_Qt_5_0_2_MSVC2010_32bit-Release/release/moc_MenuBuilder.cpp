/****************************************************************************
** Meta object code from reading C++ file 'MenuBuilder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UPROG/MenuBuilder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuBuilder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuBuilder_t {
    QByteArrayData data[7];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MenuBuilder_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MenuBuilder_t qt_meta_stringdata_MenuBuilder = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 10),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 25),
QT_MOC_LITERAL(4, 50, 23),
QT_MOC_LITERAL(5, 74, 4),
QT_MOC_LITERAL(6, 79, 21)
    },
    "MenuBuilder\0labelBlink\0\0"
    "on_lineEdit_returnPressed\0"
    "on_lineEdit_textChanged\0arg1\0"
    "on_radioButton_cheked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuBuilder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    1,   36,    2, 0x0a,
       6,    1,   39,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MenuBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuBuilder *_t = static_cast<MenuBuilder *>(_o);
        switch (_id) {
        case 0: _t->labelBlink(); break;
        case 1: _t->on_lineEdit_returnPressed(); break;
        case 2: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_radioButton_cheked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MenuBuilder::staticMetaObject = {
    { &UControlBase::staticMetaObject, qt_meta_stringdata_MenuBuilder.data,
      qt_meta_data_MenuBuilder,  qt_static_metacall, 0, 0}
};


const QMetaObject *MenuBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuBuilder.stringdata))
        return static_cast<void*>(const_cast< MenuBuilder*>(this));
    return UControlBase::qt_metacast(_clname);
}

int MenuBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UControlBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
