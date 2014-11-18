#include "XMLParser.h"
using namespace std;

XMLParser::XMLParser()
{
    XMLDumpFile = nullptr;
}

XMLParser::~XMLParser(){
    //delete myHandler;
    //delete myLookUpTable;
    delete[] XMLDumpFile;

}

void XMLParser::setXMLDumpFile(string passedFile){

    ifstream ifs(passedFile);
    ifs.seekg(0, ifs.end);
    int length = ifs.tellg();
    ifs.seekg(0, ifs.beg);

    XMLDumpFile = new char[length];

    ifs.read (XMLDumpFile,length);
}

//will cycle through all of XML documents in XML dump and index
//all of the words at first into a data structure. The data
//structure will then be saved off to hard memory for persistance
void XMLParser::storeOffXMLData(char * DumpName){


}
//will store off author, titl, ID, and XML file name in hard memory

void XMLParser::addPagesToLookup(){

}

void XMLParser::addSinglePageToLookup(){

}
