TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        flowimpl.cpp \
        functional.cpp \
        main.cpp \
        modelimpl.cpp \
        systemimpl.cpp \
        unitary.cpp \
        unitarytestsflow.cpp \
        unitarytestsmodel.cpp \
        unitarytestssystem.cpp

HEADERS += \
    flow.h \
    flowimpl.h \
    functional.h \
    model.h \
    modelimpl.h \
    system.h \
    systemimpl.h \
    unitary.h \
    unitarytestsflow.h \
    unitarytestsmodel.h \
    unitarytestssystem.h
