/****************************************************************************
** Meta object code from reading C++ file 'UProgBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UProgBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UProgBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IUProgCtrl_t {
    QByteArrayData data[10];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_IUProgCtrl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_IUProgCtrl_t qt_meta_stringdata_IUProgCtrl = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 8),
QT_MOC_LITERAL(5, 42, 10),
QT_MOC_LITERAL(6, 53, 9),
QT_MOC_LITERAL(7, 63, 5),
QT_MOC_LITERAL(8, 69, 10),
QT_MOC_LITERAL(9, 80, 7)
    },
    "IUProgCtrl\0progStatus\0\0writeDone\0"
    "readDone\0writeError\0readError\0error\0"
    "nLastError\0progRun\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IUProgCtrl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       3,    0,   52,    2, 0x05,
       4,    0,   53,    2, 0x05,
       5,    0,   54,    2, 0x05,
       6,    0,   55,    2, 0x05,
       7,    1,   56,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    0,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void IUProgCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IUProgCtrl *_t = static_cast<IUProgCtrl *>(_o);
        switch (_id) {
        case 0: _t->progStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->writeDone(); break;
        case 2: _t->readDone(); break;
        case 3: _t->writeError(); break;
        case 4: _t->readError(); break;
        case 5: _t->error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->progRun(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IUProgCtrl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IUProgCtrl::progStatus)) {
                *result = 0;
            }
        }
        {
            typedef void (IUProgCtrl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IUProgCtrl::writeDone)) {
                *result = 1;
            }
        }
        {
            typedef void (IUProgCtrl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IUProgCtrl::readDone)) {
                *result = 2;
            }
        }
        {
            typedef void (IUProgCtrl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IUProgCtrl::writeError)) {
                *result = 3;
            }
        }
        {
            typedef void (IUProgCtrl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IUProgCtrl::readError)) {
                *result = 4;
            }
        }
        {
            typedef void (IUProgCtrl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IUProgCtrl::error)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject IUProgCtrl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IUProgCtrl.data,
      qt_meta_data_IUProgCtrl,  qt_static_metacall, 0, 0}
};


const QMetaObject *IUProgCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IUProgCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IUProgCtrl.stringdata))
        return static_cast<void*>(const_cast< IUProgCtrl*>(this));
    return QObject::qt_metacast(_clname);
}

int IUProgCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void IUProgCtrl::progStatus(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IUProgCtrl::writeDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void IUProgCtrl::readDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void IUProgCtrl::writeError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void IUProgCtrl::readError()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void IUProgCtrl::error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
