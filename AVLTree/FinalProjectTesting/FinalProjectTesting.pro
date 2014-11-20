TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    SeparateChaining.cpp \
    IndexAVLNode.cpp \
    StopWordsHashTable.cpp

HEADERS += \
    SeparateChaining.h \
    AVLNode.h \
    IndexAVLNode.h \
    StopWordsHashTable.h \
    StopWordsAvlTree.h \
    AvlTree.h

