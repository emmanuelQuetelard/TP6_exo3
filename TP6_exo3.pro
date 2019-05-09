TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L ~/TP6/build-TP6-Desktop_Qt_5_12_0_GCC_64bit-Debug -lUtil

SOURCES += \
        main.cpp \
    duree.cpp \
    dureeeditable.cpp

HEADERS += \
    duree.h \
    cexception.h \
    cstcoderr.h \
    ieditable.hpp \
    dureeeditable.h
