TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    XMLParser.cpp \
    IndexHandler.cpp \
    XMLFileParser.cpp \
    LookUpTable.cpp \
    UserMode.cpp \
    MaintMode.cpp \
    InteractiveMode.cpp \
    StressMode.cpp \
    wordParser.cpp \
    HashTable.cpp \
    IndexAVLNode.cpp \
    StopWordsHashTable.cpp \
    Index.cpp

HEADERS += \
    rapidxml.hpp\
    rapidxml_print.hpp\
    rapidxml_utils.hpp\
    rapidxml_iterators.hpp\
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
    AvlTree.h \
    IndexAVLNode.h \
    StopWordsHashTable.h \
    StopWordsAvlTree.h

