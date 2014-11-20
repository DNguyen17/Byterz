TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    SeparateChaining.cpp \
    IndexAVLNode.cpp

HEADERS += \
    AVLTree.h \
    SeparateChaining.h \
    AVLNode.h \
    IndexAVLNode.h

