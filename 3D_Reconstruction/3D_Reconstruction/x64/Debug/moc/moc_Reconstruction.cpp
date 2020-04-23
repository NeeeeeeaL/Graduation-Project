/****************************************************************************
** Meta object code from reading C++ file 'Reconstruction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Reconstruction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Reconstruction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Reconstruction_t {
    QByteArrayData data[12];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Reconstruction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Reconstruction_t qt_meta_stringdata_Reconstruction = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Reconstruction"
QT_MOC_LITERAL(1, 15, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 62, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 86, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(6, 110, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(7, 134, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(8, 158, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(9, 182, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(10, 206, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(11, 230, 22) // "on_actionPMP_triggered"

    },
    "Reconstruction\0on_pushButton_clicked\0"
    "\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_actionOpen_triggered\0"
    "on_actionSave_triggered\0on_actionPMP_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Reconstruction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Reconstruction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Reconstruction *_t = static_cast<Reconstruction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_pushButton_6_clicked(); break;
        case 6: _t->on_pushButton_7_clicked(); break;
        case 7: _t->on_actionOpen_triggered(); break;
        case 8: _t->on_actionSave_triggered(); break;
        case 9: _t->on_actionPMP_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Reconstruction::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Reconstruction.data,
      qt_meta_data_Reconstruction,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Reconstruction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Reconstruction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Reconstruction.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Reconstruction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
