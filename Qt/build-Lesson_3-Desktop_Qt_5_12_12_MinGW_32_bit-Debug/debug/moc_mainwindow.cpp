/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lesson_8/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[465];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "onSaveFileActionTriggered"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 25), // "onOpenFileActionTriggered"
QT_MOC_LITERAL(4, 64, 33), // "onReadOnlyOpenFileActionTrigg..."
QT_MOC_LITERAL(5, 98, 19), // "onShowHelpTriggered"
QT_MOC_LITERAL(6, 118, 18), // "onNewFileTriggered"
QT_MOC_LITERAL(7, 137, 27), // "onShortcutsDialogShowAction"
QT_MOC_LITERAL(8, 165, 28), // "onTranslationChangeTriggered"
QT_MOC_LITERAL(9, 194, 26), // "onFileExplorerItemSelected"
QT_MOC_LITERAL(10, 221, 8), // "filePath"
QT_MOC_LITERAL(11, 230, 22), // "onChangeThemeTriggered"
QT_MOC_LITERAL(12, 253, 27), // "onChangeFontActionTriggered"
QT_MOC_LITERAL(13, 281, 27), // "onCopyFormatActionTriggered"
QT_MOC_LITERAL(14, 309, 28), // "onPasteFormatActionTriggered"
QT_MOC_LITERAL(15, 338, 30), // "onTextAlignLeftActionTriggered"
QT_MOC_LITERAL(16, 369, 31), // "onTextAlignRightActionTriggered"
QT_MOC_LITERAL(17, 401, 32), // "onTextAlignCenterActionTriggered"
QT_MOC_LITERAL(18, 434, 30) // "onAddDateToTextActionTriggered"

    },
    "MainWindow\0onSaveFileActionTriggered\0"
    "\0onOpenFileActionTriggered\0"
    "onReadOnlyOpenFileActionTriggered\0"
    "onShowHelpTriggered\0onNewFileTriggered\0"
    "onShortcutsDialogShowAction\0"
    "onTranslationChangeTriggered\0"
    "onFileExplorerItemSelected\0filePath\0"
    "onChangeThemeTriggered\0"
    "onChangeFontActionTriggered\0"
    "onCopyFormatActionTriggered\0"
    "onPasteFormatActionTriggered\0"
    "onTextAlignLeftActionTriggered\0"
    "onTextAlignRightActionTriggered\0"
    "onTextAlignCenterActionTriggered\0"
    "onAddDateToTextActionTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       9,    1,  101,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSaveFileActionTriggered(); break;
        case 1: _t->onOpenFileActionTriggered(); break;
        case 2: _t->onReadOnlyOpenFileActionTriggered(); break;
        case 3: _t->onShowHelpTriggered(); break;
        case 4: _t->onNewFileTriggered(); break;
        case 5: _t->onShortcutsDialogShowAction(); break;
        case 6: _t->onTranslationChangeTriggered(); break;
        case 7: _t->onFileExplorerItemSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onChangeThemeTriggered(); break;
        case 9: _t->onChangeFontActionTriggered(); break;
        case 10: _t->onCopyFormatActionTriggered(); break;
        case 11: _t->onPasteFormatActionTriggered(); break;
        case 12: _t->onTextAlignLeftActionTriggered(); break;
        case 13: _t->onTextAlignRightActionTriggered(); break;
        case 14: _t->onTextAlignCenterActionTriggered(); break;
        case 15: _t->onAddDateToTextActionTriggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
