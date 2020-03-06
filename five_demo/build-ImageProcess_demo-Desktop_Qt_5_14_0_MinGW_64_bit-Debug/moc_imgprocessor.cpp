/****************************************************************************
** Meta object code from reading C++ file 'imgprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ImageProcess_demo/imgprocessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImgProcessor_t {
    QByteArrayData data[22];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgProcessor_t qt_meta_stringdata_ImgProcessor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ImgProcessor"
QT_MOC_LITERAL(1, 13, 11), // "showNewFile"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "showOpenFile"
QT_MOC_LITERAL(4, 39, 13), // "showPrintText"
QT_MOC_LITERAL(5, 53, 14), // "showPrintImage"
QT_MOC_LITERAL(6, 68, 10), // "showZoomIn"
QT_MOC_LITERAL(7, 79, 11), // "showZoomOut"
QT_MOC_LITERAL(8, 91, 12), // "showRotate90"
QT_MOC_LITERAL(9, 104, 13), // "showRotate180"
QT_MOC_LITERAL(10, 118, 13), // "showRotate270"
QT_MOC_LITERAL(11, 132, 16), // "ShowFontComboBox"
QT_MOC_LITERAL(12, 149, 8), // "comboStr"
QT_MOC_LITERAL(13, 158, 15), // "ShowSizeSpinBox"
QT_MOC_LITERAL(14, 174, 9), // "spinValue"
QT_MOC_LITERAL(15, 184, 11), // "ShowBoldBtn"
QT_MOC_LITERAL(16, 196, 13), // "ShowItalicBtn"
QT_MOC_LITERAL(17, 210, 16), // "ShowUnderlineBtn"
QT_MOC_LITERAL(18, 227, 12), // "ShowColorBtn"
QT_MOC_LITERAL(19, 240, 24), // "ShowCurrentFormatChanged"
QT_MOC_LITERAL(20, 265, 15), // "QTextCharFormat"
QT_MOC_LITERAL(21, 281, 3) // "fmt"

    },
    "ImgProcessor\0showNewFile\0\0showOpenFile\0"
    "showPrintText\0showPrintImage\0showZoomIn\0"
    "showZoomOut\0showRotate90\0showRotate180\0"
    "showRotate270\0ShowFontComboBox\0comboStr\0"
    "ShowSizeSpinBox\0spinValue\0ShowBoldBtn\0"
    "ShowItalicBtn\0ShowUnderlineBtn\0"
    "ShowColorBtn\0ShowCurrentFormatChanged\0"
    "QTextCharFormat\0fmt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgProcessor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x09 /* Protected */,
      13,    1,  106,    2, 0x09 /* Protected */,
      15,    0,  109,    2, 0x09 /* Protected */,
      16,    0,  110,    2, 0x09 /* Protected */,
      17,    0,  111,    2, 0x09 /* Protected */,
      18,    0,  112,    2, 0x09 /* Protected */,
      19,    1,  113,    2, 0x09 /* Protected */,

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
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void ImgProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImgProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showNewFile(); break;
        case 1: _t->showOpenFile(); break;
        case 2: _t->showPrintText(); break;
        case 3: _t->showPrintImage(); break;
        case 4: _t->showZoomIn(); break;
        case 5: _t->showZoomOut(); break;
        case 6: _t->showRotate90(); break;
        case 7: _t->showRotate180(); break;
        case 8: _t->showRotate270(); break;
        case 9: _t->ShowFontComboBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->ShowSizeSpinBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->ShowBoldBtn(); break;
        case 12: _t->ShowItalicBtn(); break;
        case 13: _t->ShowUnderlineBtn(); break;
        case 14: _t->ShowColorBtn(); break;
        case 15: _t->ShowCurrentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImgProcessor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ImgProcessor.data,
    qt_meta_data_ImgProcessor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImgProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImgProcessor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ImgProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
