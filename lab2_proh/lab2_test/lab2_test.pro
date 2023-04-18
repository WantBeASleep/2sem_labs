QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
TEMPLATE = app

SOURCES += \
    main.cpp \
    tst_arraysequencetest.cpp \
    tst_dequetest.cpp \
    tst_linkedlistsequencetest.cpp


INCLUDEPATH += ../lab2_lib
LIBS += -L../lab2_lib/debug# -llab2_lib

HEADERS += \
    tst_arraysequencetest.h \
    tst_dequetest.h \
    tst_linkedlistsequencetest.h
