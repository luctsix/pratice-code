/****************************************************************************
** Meta object code from reading C++ file 'teacher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SignalSlot/teacher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teacher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Teacher_t {
    QByteArrayData data[7];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Teacher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Teacher_t qt_meta_stringdata_Teacher = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Teacher"
QT_MOC_LITERAL(1, 8, 15), // "teachClassBegin"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "teachClassOver"
QT_MOC_LITERAL(4, 40, 9), // "teachMath"
QT_MOC_LITERAL(5, 50, 12), // "teachChinese"
QT_MOC_LITERAL(6, 63, 12) // "teachEnglish"

    },
    "Teacher\0teachClassBegin\0\0teachClassOver\0"
    "teachMath\0teachChinese\0teachEnglish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Teacher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Teacher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Teacher *_t = static_cast<Teacher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->teachClassBegin(); break;
        case 1: _t->teachClassOver(); break;
        case 2: _t->teachMath(); break;
        case 3: _t->teachChinese(); break;
        case 4: _t->teachEnglish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Teacher::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Teacher::teachClassBegin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Teacher::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Teacher::teachClassOver)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Teacher::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Teacher::teachMath)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Teacher::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Teacher::teachChinese)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Teacher::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Teacher::teachEnglish)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Teacher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Teacher.data,
      qt_meta_data_Teacher,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Teacher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Teacher::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Teacher.stringdata0))
        return static_cast<void*>(const_cast< Teacher*>(this));
    return QObject::qt_metacast(_clname);
}

int Teacher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Teacher::teachClassBegin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Teacher::teachClassOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Teacher::teachMath()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Teacher::teachChinese()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Teacher::teachEnglish()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
