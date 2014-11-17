#ifndef XMLPARSER_H
#define XMLPARSER_H

#include"IndexHandler.h"
#include"LookUpTable.h"
#include"XMLFileParser.h"
#include<string>

class XMLParser
{
public:
    //Constructor, Destructor
    XMLParser();
    ~XMLParser();


    void storeOffXMLData(char * DumpName);
    void  setXMLDumpFile(char *);

private:
    //private helper function
    void indexBodyOfText(std::string* body, std::string pageID);
    void  addPagesToLookup();
    void  addSinglePageToLookup();

    IndexHandler* myHandler;
    LookUpTable* myLookUpTable;
    char* XMLDumpFile;
    XMLFileParser myParser;
};

#endif // XMLPARSER_H
