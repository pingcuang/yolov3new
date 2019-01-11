/****************************************************************************
** Meta object code from reading C++ file 'rspDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rspDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rspDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rspDlg_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rspDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rspDlg_t qt_meta_stringdata_rspDlg = {
    {
QT_MOC_LITERAL(0, 0, 6), // "rspDlg"
QT_MOC_LITERAL(1, 7, 19), // "rspDlgManageSignals"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "MyEnum_RspManage"
QT_MOC_LITERAL(4, 45, 4), // "type"
QT_MOC_LITERAL(5, 50, 11), // "TAG_MONITOR"
QT_MOC_LITERAL(6, 62, 3), // "tag"
QT_MOC_LITERAL(7, 66, 10), // "okBtnSlots"
QT_MOC_LITERAL(8, 77, 13) // "cacelBtnSlots"

    },
    "rspDlg\0rspDlgManageSignals\0\0"
    "MyEnum_RspManage\0type\0TAG_MONITOR\0tag\0"
    "okBtnSlots\0cacelBtnSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rspDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   34,    2, 0x08 /* Private */,
       8,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rspDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rspDlg *_t = static_cast<rspDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rspDlgManageSignals((*reinterpret_cast< MyEnum_RspManage(*)>(_a[1])),(*reinterpret_cast< const TAG_MONITOR(*)>(_a[2]))); break;
        case 1: _t->okBtnSlots(); break;
        case 2: _t->cacelBtnSlots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (rspDlg::*_t)(MyEnum_RspManage , const TAG_MONITOR & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rspDlg::rspDlgManageSignals)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject rspDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rspDlg.data,
      qt_meta_data_rspDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rspDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rspDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rspDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int rspDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void rspDlg::rspDlgManageSignals(MyEnum_RspManage _t1, const TAG_MONITOR & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
