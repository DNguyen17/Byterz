#ifndef XMLFILEPARSER_H
#define XMLFILEPARSER_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;


//rapidXML allocate memory in its own pool. should we copy char* returned over? how do we deallocate

class XMLFileParser
{
private:
    ifstream ifs;
    char* file;
    xml_document<> doc;
    xml_node<> *pageNode, *textNode, *authorNode;

public:
    XMLFileParser();
    ~XMLFileParser();
    void setNodes(xml_node<> *node);
    char *findPageID();
    char *findTitle();
    char *findBodyText();
    char *findAuthor();

};

#endif // XMLFILEPARSER_H
