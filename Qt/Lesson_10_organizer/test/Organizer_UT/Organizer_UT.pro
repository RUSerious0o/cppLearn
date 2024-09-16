QT += testlib gui core quickwidgets widgets
CONFIG += qt warn_on depend_includepath testcase

TARGET = sample

TEMPLATE = app

HEADERS += \
    ../../mainwindow.h

SOURCES +=  \
    ./tst_organizer_ut.cpp \
    ../../mainwindow.cpp

FORMS += \
    ../../mainwindow.ui

RESOURCES += \
    ../../res.qrc
