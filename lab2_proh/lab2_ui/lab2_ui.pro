TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        person.cpp

INCLUDEPATH += ../lab2_lib
LIBS += -L../lab2_lib/debug# -llab2_lib

HEADERS += \
    interractiveInput.h \
    menu.h \
    person.h \
    ui.h
