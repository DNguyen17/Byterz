TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
QMAKE_CXXFLAGS +=

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    AVLTree.h \
    AVLNode.h

