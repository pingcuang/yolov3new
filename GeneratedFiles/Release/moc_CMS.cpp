/****************************************************************************
** Meta object code from reading C++ file 'CMS.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CMS.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMS_t {
    QByteArrayData data[14];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMS_t qt_meta_stringdata_CMS = {
    {
QT_MOC_LITERAL(0, 0, 3), // "CMS"
QT_MOC_LITERAL(1, 4, 20), // "CmsUpdateMonitorList"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 26), // "mouseDoubleClickEvent_Item"
QT_MOC_LITERAL(4, 53, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(5, 70, 4), // "item"
QT_MOC_LITERAL(6, 75, 3), // "num"
QT_MOC_LITERAL(7, 79, 11), // "BtnMaxSlots"
QT_MOC_LITERAL(8, 91, 11), // "BtnMinSlots"
QT_MOC_LITERAL(9, 103, 13), // "BtnCloseSlots"
QT_MOC_LITERAL(10, 117, 18), // "BtnFullScreenSlots"
QT_MOC_LITERAL(11, 136, 29), // "pActionMonitorDrawRegionSlots"
QT_MOC_LITERAL(12, 166, 1), // "b"
QT_MOC_LITERAL(13, 168, 17) // "BtnRspManageSlots"

    },
    "CMS\0CmsUpdateMonitorList\0\0"
    "mouseDoubleClickEvent_Item\0QTreeWidgetItem*\0"
    "item\0num\0BtnMaxSlots\0BtnMinSlots\0"
    "BtnCloseSlots\0BtnFullScreenSlots\0"
    "pActionMonitorDrawRegionSlots\0b\0"
    "BtnRspManageSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    2,   55,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    1,   64,    2, 0x08 /* Private */,
      13,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void CMS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMS *_t = static_cast<CMS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CmsUpdateMonitorList(); break;
        case 1: _t->mouseDoubleClickEvent_Item((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->BtnMaxSlots(); break;
        case 3: _t->BtnMinSlots(); break;
        case 4: _t->BtnCloseSlots(); break;
        case 5: _t->BtnFullScreenSlots(); break;
        case 6: _t->pActionMonitorDrawRegionSlots((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->BtnRspManageSlots(); break;
        default: ;
        }
    }
}

const QMetaObject CMS::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CMS.data,
      qt_meta_data_CMS,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CCmsStyle"))
        return static_cast< CCmsStyle*>(this);
    if (!strcmp(_clname, "CMonitorRsp"))
        return static_cast< CMonitorRsp*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CMS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
