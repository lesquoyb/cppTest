TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
SOURCES += main.cpp \
    point.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    demolauncher.h \
    demotest1.h \
    point.h \
    vecteur.h \
    ../cpptest.h \
    ../cpptestfacade.h \
    ../cpptesttools.h

