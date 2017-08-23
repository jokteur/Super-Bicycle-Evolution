TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    universe.cpp \
    creature.cpp \
    scheduler.cpp \
    event.cpp \
    neuralsystem.cpp

HEADERS += \
    universe.h \
    creature.h \
    scheduler.h \
    event.h \
    neuralsystem.h
