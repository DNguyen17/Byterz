#ifndef XMLPARSER_H
#define XMLPARSER_H

#include"IndexHandler.h"
#include"LookUpTable.h"
#include"XMLFileParser.h"
#include"XMLFileParser.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

class XMLParser
{
public:
    //Constructor, Destructor
    XMLParser();
    ~XMLParser();

    void loadStopTable();
    void storeOffXMLData();
    void setXMLDumpFile(string&);
    void findUserWords();
    void storeOffNewData(string& fileName);
    void clearIndex();
    void buildIndexFromMemory(int choice);

private:
    //private helper function
    //void indexBodyOfText(std::string* body, std::string pageID);
    void  addPagesToLookup();
    void  addSinglePageToLookup();

    IndexHandler* myHandler;
    //LookUpTable* myLookUpTable;
    char* XMLDumpFile;
    XMLFileParser myParser;
    xml_document<> doc;
    xml_node<>* docNode;
    int id;

    //char* title;
    //char* text;

};

#endif // XMLPARSER_H
