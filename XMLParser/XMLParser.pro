TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
           XMLFileParser.cpp \
    XMLParser.cpp


HEADERS += rapidxml.hpp\
           rapidxml_print.hpp\
           rapidxml_utils.hpp\
           rapidxml_iterators.hpp\
           XMLFileParser.h\
    XMLParser.h


include(deployment.pri)
qtcAddDeployment()

