#ifndef XMLPARSER_H
#define XMLPARSER_H

//#include"IndexHandler.h"
//#include"LookUpTable.h"
#include"XMLFileParser.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <algorithm>

using namespace std;
using namespace rapidxml;

class XMLParser
{

private:
    //private helper function
    void indexBodyOfText(char *body, int pageID, ofstream& fout);
    void  addPagesToLookup();
    void  addSinglePageToLookup();

    //IndexHandler* myHandler;
    //LookUpTable* myLookUpTable;
    char* XMLDumpFile;
    XMLFileParser myParser;
    xml_document<> doc;
    xml_node<>* docNode;

    char* title;
    int id;
    char* text;


public:
    //Constructor, Destructor
    XMLParser();
    ~XMLParser();

    void storeOffXMLData(const char *DumpName);
    void  setXMLDumpFile(string);

};

#endif // XMLPARSER_H
