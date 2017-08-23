TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    universe.cpp \
    creature.cpp \
    neuronalsystem.cpp \
    scheduler.cpp \
    event.cpp

HEADERS += \
    universe.h \
    creature.h \
    neuronalsystem.h \
    scheduler.h \
    event.h
