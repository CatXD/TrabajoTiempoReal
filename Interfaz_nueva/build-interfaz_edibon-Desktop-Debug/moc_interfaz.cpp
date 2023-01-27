/****************************************************************************
** Meta object code from reading C++ file 'interfaz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interfaz_edibon_Rpi_Al/interfaz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfaz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Interfaz_t {
    QByteArrayData data[18];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Interfaz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Interfaz_t qt_meta_stringdata_Interfaz = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Interfaz"
QT_MOC_LITERAL(1, 9, 15), // "muestraDatoSlot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 1), // "t"
QT_MOC_LITERAL(4, 28, 3), // "ref"
QT_MOC_LITERAL(5, 32, 1), // "u"
QT_MOC_LITERAL(6, 34, 1), // "y"
QT_MOC_LITERAL(7, 36, 21), // "on_botonParar_clicked"
QT_MOC_LITERAL(8, 58, 24), // "on_botonReanudar_clicked"
QT_MOC_LITERAL(9, 83, 25), // "on_botonFinalizar_clicked"
QT_MOC_LITERAL(10, 109, 29), // "on_botonSetReferencia_clicked"
QT_MOC_LITERAL(11, 139, 29), // "on_botonSetParametros_clicked"
QT_MOC_LITERAL(12, 169, 28), // "on_toggleModoControl_clicked"
QT_MOC_LITERAL(13, 198, 26), // "on_dVelocidad_valueChanged"
QT_MOC_LITERAL(14, 225, 5), // "value"
QT_MOC_LITERAL(15, 231, 25), // "on_dPosicion_valueChanged"
QT_MOC_LITERAL(16, 257, 9), // "onTimeout"
QT_MOC_LITERAL(17, 267, 22) // "on_bSetPeriodo_clicked"

    },
    "Interfaz\0muestraDatoSlot\0\0t\0ref\0u\0y\0"
    "on_botonParar_clicked\0on_botonReanudar_clicked\0"
    "on_botonFinalizar_clicked\0"
    "on_botonSetReferencia_clicked\0"
    "on_botonSetParametros_clicked\0"
    "on_toggleModoControl_clicked\0"
    "on_dVelocidad_valueChanged\0value\0"
    "on_dPosicion_valueChanged\0onTimeout\0"
    "on_bSetPeriodo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interfaz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   69,    2, 0x0a /* Public */,
       7,    0,   78,    2, 0x08 /* Private */,
       8,    0,   79,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    1,   84,    2, 0x08 /* Private */,
      15,    1,   87,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Interfaz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Interfaz *_t = static_cast<Interfaz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->muestraDatoSlot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->on_botonParar_clicked(); break;
        case 2: _t->on_botonReanudar_clicked(); break;
        case 3: _t->on_botonFinalizar_clicked(); break;
        case 4: _t->on_botonSetReferencia_clicked(); break;
        case 5: _t->on_botonSetParametros_clicked(); break;
        case 6: _t->on_toggleModoControl_clicked(); break;
        case 7: _t->on_dVelocidad_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_dPosicion_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onTimeout(); break;
        case 10: _t->on_bSetPeriodo_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Interfaz::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Interfaz.data,
      qt_meta_data_Interfaz,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Interfaz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interfaz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Interfaz.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Interfaz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
