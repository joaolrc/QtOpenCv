/****************************************************************************
** Meta object code from reading C++ file 'qcvwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../QtOpenCvNew/qcvwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcvwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCvWidget_t {
    const uint offsetsAndSize[18];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QCvWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QCvWidget_t qt_meta_stringdata_QCvWidget = {
    {
QT_MOC_LITERAL(0, 9), // "QCvWidget"
QT_MOC_LITERAL(10, 19), // "signalSendStreamSrc"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 6), // "stream"
QT_MOC_LITERAL(38, 16), // "slotRcvNewFrames"
QT_MOC_LITERAL(55, 7), // "QImage&"
QT_MOC_LITERAL(63, 5), // "inpFr"
QT_MOC_LITERAL(69, 5), // "outFr"
QT_MOC_LITERAL(75, 20) // "slotRcvInvalidCapDev"

    },
    "QCvWidget\0signalSendStreamSrc\0\0stream\0"
    "slotRcvNewFrames\0QImage&\0inpFr\0outFr\0"
    "slotRcvInvalidCapDev"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCvWidget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   35,    2, 0x08,    2 /* Private */,
       8,    0,   40,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,

       0        // eod
};

void QCvWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCvWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendStreamSrc((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotRcvNewFrames((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 2: _t->slotRcvInvalidCapDev(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QCvWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCvWidget::signalSendStreamSrc)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QCvWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QCvWidget.offsetsAndSize,
    qt_meta_data_QCvWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QCvWidget_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *QCvWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCvWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCvWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QCvWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QCvWidget::signalSendStreamSrc(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
