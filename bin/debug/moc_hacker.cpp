/****************************************************************************
** Meta object code from reading C++ file 'hacker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../HackTool/hacker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hacker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Hacker_t {
    QByteArrayData data[14];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Hacker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Hacker_t qt_meta_stringdata_Hacker = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 10),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 9),
QT_MOC_LITERAL(4, 29, 10),
QT_MOC_LITERAL(5, 40, 8),
QT_MOC_LITERAL(6, 49, 8),
QT_MOC_LITERAL(7, 58, 4),
QT_MOC_LITERAL(8, 63, 3),
QT_MOC_LITERAL(9, 67, 4),
QT_MOC_LITERAL(10, 72, 8),
QT_MOC_LITERAL(11, 81, 7),
QT_MOC_LITERAL(12, 89, 8),
QT_MOC_LITERAL(13, 98, 7)
    },
    "Hacker\0hackResult\0\0HackInfo&\0hackStatus\0"
    "QString&\0hackDone\0hack\0req\0stop\0"
    "dealComb\0combRes\0dealPerm\0permRes\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hacker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       4,    1,   52,    2, 0x06,
       6,    0,   55,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   56,    2, 0x0a,
       9,    0,   59,    2, 0x0a,
      10,    1,   60,    2, 0x0a,
      12,    1,   63,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,   11,
    QMetaType::Void, 0x80000000 | 5,   13,

       0        // eod
};

void Hacker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hacker *_t = static_cast<Hacker *>(_o);
        switch (_id) {
        case 0: _t->hackResult((*reinterpret_cast< HackInfo(*)>(_a[1]))); break;
        case 1: _t->hackStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->hackDone(); break;
        case 3: _t->hack((*reinterpret_cast< HackInfo(*)>(_a[1]))); break;
        case 4: _t->stop(); break;
        case 5: _t->dealComb((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->dealPerm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Hacker::*_t)(HackInfo & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Hacker::hackResult)) {
                *result = 0;
            }
        }
        {
            typedef void (Hacker::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Hacker::hackStatus)) {
                *result = 1;
            }
        }
        {
            typedef void (Hacker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Hacker::hackDone)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Hacker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Hacker.data,
      qt_meta_data_Hacker,  qt_static_metacall, 0, 0}
};


const QMetaObject *Hacker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hacker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Hacker.stringdata))
        return static_cast<void*>(const_cast< Hacker*>(this));
    return QObject::qt_metacast(_clname);
}

int Hacker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Hacker::hackResult(HackInfo & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Hacker::hackStatus(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Hacker::hackDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
