/****************************************************************************
** Meta object code from reading C++ file 'OpenCvAgent.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../QtOpenCvNew/OpenCvAgent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenCvAgent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenCvAgent_t {
    const uint offsetsAndSize[30];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_OpenCvAgent_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_OpenCvAgent_t qt_meta_stringdata_OpenCvAgent = {
    {
QT_MOC_LITERAL(0, 11), // "OpenCvAgent"
QT_MOC_LITERAL(12, 30), // "signalWarnInvalidCaptureDevice"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 16), // "signalSendFrames"
QT_MOC_LITERAL(61, 7), // "QImage&"
QT_MOC_LITERAL(69, 13), // "frameOriginal"
QT_MOC_LITERAL(83, 14), // "frameProcessed"
QT_MOC_LITERAL(98, 19), // "slotProcessNewFrame"
QT_MOC_LITERAL(118, 13), // "setFilterType"
QT_MOC_LITERAL(132, 10), // "filterType"
QT_MOC_LITERAL(143, 20), // "slotPlayStreamSource"
QT_MOC_LITERAL(164, 6), // "stream"
QT_MOC_LITERAL(171, 7), // "setHmin"
QT_MOC_LITERAL(179, 6), // "thresh"
QT_MOC_LITERAL(186, 15) // "setBinaryThresh"

    },
    "OpenCvAgent\0signalWarnInvalidCaptureDevice\0"
    "\0signalSendFrames\0QImage&\0frameOriginal\0"
    "frameProcessed\0slotProcessNewFrame\0"
    "setFilterType\0filterType\0slotPlayStreamSource\0"
    "stream\0setHmin\0thresh\0setBinaryThresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenCvAgent[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    0 /* Public */,
       3,    2,   57,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   62,    2, 0x08,    4 /* Private */,
       8,    1,   63,    2, 0x08,    5 /* Private */,
      10,    1,   66,    2, 0x0a,    7 /* Public */,
      12,    1,   69,    2, 0x0a,    9 /* Public */,
      14,    1,   72,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void OpenCvAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenCvAgent *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalWarnInvalidCaptureDevice(); break;
        case 1: _t->signalSendFrames((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 2: _t->slotProcessNewFrame(); break;
        case 3: _t->setFilterType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotPlayStreamSource((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setHmin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setBinaryThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OpenCvAgent::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenCvAgent::signalWarnInvalidCaptureDevice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OpenCvAgent::*)(QImage & , QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenCvAgent::signalSendFrames)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject OpenCvAgent::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OpenCvAgent.offsetsAndSize,
    qt_meta_data_OpenCvAgent,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_OpenCvAgent_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<QImage &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *OpenCvAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenCvAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenCvAgent.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OpenCvAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void OpenCvAgent::signalWarnInvalidCaptureDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void OpenCvAgent::signalSendFrames(QImage & _t1, QImage & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
