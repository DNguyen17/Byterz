TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    XMLParser.cpp \
    IndexHandler.cpp \
    XMLFileParser.cpp \
    Iindex.cpp \
    LookUpTable.cpp \
    UserMode.cpp \
    MaintMode.cpp \
    InteractiveMode.cpp \
    StressMode.cpp \
    wordParser.cpp \
    HashTable.cpp \
    AVLTree.cpp

HEADERS += \
    XMLParser.h \
    IndexHandler.h \
    XMLFileParser.h \
    Index.h \
    LookUpTable.h \
    UserMode.h \
    MaintMode.h \
    InteractiveMode.h \
    StressMode.h \
    wordParser.h \
    HashTable.h \
    AVLTree.h

