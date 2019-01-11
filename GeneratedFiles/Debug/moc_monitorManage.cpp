/****************************************************************************
** Meta object code from reading C++ file 'monitorManage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../monitorManage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitorManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_monitorManage_t {
    QByteArrayData data[17];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_monitorManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_monitorManage_t qt_meta_stringdata_monitorManage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "monitorManage"
QT_MOC_LITERAL(1, 14, 17), // "updateList_signed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 23), // "monitorRightMoveBtnSlot"
QT_MOC_LITERAL(4, 57, 22), // "monitorLeftMoveBtnSlot"
QT_MOC_LITERAL(5, 80, 14), // "ActionAddSlots"
QT_MOC_LITERAL(6, 95, 1), // "b"
QT_MOC_LITERAL(7, 97, 14), // "ActionDelSlots"
QT_MOC_LITERAL(8, 112, 16), // "ActionModifSlots"
QT_MOC_LITERAL(9, 129, 17), // "rspDlgManageSlots"
QT_MOC_LITERAL(10, 147, 16), // "MyEnum_RspManage"
QT_MOC_LITERAL(11, 164, 4), // "type"
QT_MOC_LITERAL(12, 169, 11), // "TAG_MONITOR"
QT_MOC_LITERAL(13, 181, 7), // "new_tag"
QT_MOC_LITERAL(14, 189, 28), // "tableViewRightdownSlots_left"
QT_MOC_LITERAL(15, 218, 3), // "pos"
QT_MOC_LITERAL(16, 222, 29) // "tableViewRightdownSlots_right"

    },
    "monitorManage\0updateList_signed\0\0"
    "monitorRightMoveBtnSlot\0monitorLeftMoveBtnSlot\0"
    "ActionAddSlots\0b\0ActionDelSlots\0"
    "ActionModifSlots\0rspDlgManageSlots\0"
    "MyEnum_RspManage\0type\0TAG_MONITOR\0"
    "new_tag\0tableViewRightdownSlots_left\0"
    "pos\0tableViewRightdownSlots_right"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_monitorManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
       9,    2,   71,    2, 0x0a /* Public */,
      14,    1,   76,    2, 0x0a /* Public */,
      16,    1,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, QMetaType::QPoint,   15,

       0        // eod
};

void monitorManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        monitorManage *_t = static_cast<monitorManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateList_signed(); break;
        case 1: _t->monitorRightMoveBtnSlot(); break;
        case 2: _t->monitorLeftMoveBtnSlot(); break;
        case 3: _t->ActionAddSlots((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->ActionDelSlots((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->ActionModifSlots((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->rspDlgManageSlots((*reinterpret_cast< MyEnum_RspManage(*)>(_a[1])),(*reinterpret_cast< const TAG_MONITOR(*)>(_a[2]))); break;
        case 7: _t->tableViewRightdownSlots_left((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->tableViewRightdownSlots_right((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (monitorManage::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&monitorManage::updateList_signed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject monitorManage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_monitorManage.data,
      qt_meta_data_monitorManage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *monitorManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *monitorManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_monitorManage.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CMonitorRsp"))
        return static_cast< CMonitorRsp*>(this);
    return QDialog::qt_metacast(_clname);
}

int monitorManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void monitorManage::updateList_signed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
