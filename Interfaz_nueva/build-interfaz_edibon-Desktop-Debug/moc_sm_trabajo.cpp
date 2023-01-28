/****************************************************************************
** Meta object code from reading C++ file 'sm_trabajo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interfaz_edibon_Rpi_Al/sm_trabajo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sm_trabajo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SM_trabajo_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SM_trabajo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SM_trabajo_t qt_meta_stringdata_SM_trabajo = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SM_trabajo"
QT_MOC_LITERAL(1, 11, 12), // "PARAR_signal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15) // "REANUDAR_signal"

    },
    "SM_trabajo\0PARAR_signal\0\0REANUDAR_signal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SM_trabajo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SM_trabajo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SM_trabajo *_t = static_cast<SM_trabajo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PARAR_signal(); break;
        case 1: _t->REANUDAR_signal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SM_trabajo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SM_trabajo::PARAR_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SM_trabajo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SM_trabajo::REANUDAR_signal)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SM_trabajo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SM_trabajo.data,
      qt_meta_data_SM_trabajo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SM_trabajo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SM_trabajo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SM_trabajo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SM_trabajo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SM_trabajo::PARAR_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SM_trabajo::REANUDAR_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
