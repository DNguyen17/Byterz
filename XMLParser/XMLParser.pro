TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += rapidxml.hpp\
           rapidxml_print.hpp\
           rapidxml_utils.hpp\
           rapidxml_iterators.hpp

include(deployment.pri)
qtcAddDeployment()

