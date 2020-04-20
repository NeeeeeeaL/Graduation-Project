/****************************************************************************
** Meta object code from reading C++ file 'pmpTrans.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../pmpTrans.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pmpTrans.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PMPTrans_t {
    QByteArrayData data[9];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PMPTrans_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PMPTrans_t qt_meta_stringdata_PMPTrans = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PMPTrans"
QT_MOC_LITERAL(1, 9, 12), // "signalSwitch"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "signalNotOpen"
QT_MOC_LITERAL(4, 37, 13), // "signalNotGetP"
QT_MOC_LITERAL(5, 51, 22), // "on_actionFTP_triggered"
QT_MOC_LITERAL(6, 74, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 98, 22), // "on_pushButton1_clicked"
QT_MOC_LITERAL(8, 121, 22) // "on_pushButton2_clicked"

    },
    "PMPTrans\0signalSwitch\0\0signalNotOpen\0"
    "signalNotGetP\0on_actionFTP_triggered\0"
    "on_actionOpen_triggered\0on_pushButton1_clicked\0"
    "on_pushButton2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PMPTrans[] = {

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
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PMPTrans::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PMPTrans *_t = static_cast<PMPTrans *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSwitch(); break;
        case 1: _t->signalNotOpen(); break;
        case 2: _t->signalNotGetP(); break;
        case 3: _t->on_actionFTP_triggered(); break;
        case 4: _t->on_actionOpen_triggered(); break;
        case 5: _t->on_pushButton1_clicked(); break;
        case 6: _t->on_pushButton2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PMPTrans::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PMPTrans::signalSwitch)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PMPTrans::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PMPTrans::signalNotOpen)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PMPTrans::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PMPTrans::signalNotGetP)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PMPTrans::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PMPTrans.data,
      qt_meta_data_PMPTrans,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PMPTrans::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PMPTrans::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PMPTrans.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PMPTrans::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void PMPTrans::signalSwitch()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PMPTrans::signalNotOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PMPTrans::signalNotGetP()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
