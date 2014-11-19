#include "XMLParser.h"
using namespace std;

XMLParser::XMLParser()
{
    XMLDumpFile = nullptr;
}

XMLParser::~XMLParser(){
    //delete myHandler;
    //delete myLookUpTable;

    if (XMLDumpFile != nullptr)
        delete[] XMLDumpFile;

    XMLDumpFile = nullptr;

}

//http://www.cplusplus.com/reference/istream/istream/read/
void XMLParser::setXMLDumpFile(string passedFile){

    ifstream ifs(passedFile);

    if (!ifs){

        cerr << "unable to open dump file" << endl;
        exit(1);
    }

    ifs.seekg(0, ifs.end);
    int length = ifs.tellg();
    ifs.seekg(0, ifs.beg);

    XMLDumpFile = new char[length];

    ifs.read (XMLDumpFile,length);
}

//will cycle through all of XML documents in XML dump and index
//all of the words at first into a data structure. The data
//structure will then be saved off to hard memory for persistance
void XMLParser::storeOffXMLData(const char * DumpName){

    ofstream ofs(DumpName);

    doc.parse<0>(XMLDumpFile);
    docNode = doc.first_node("mediawiki");
    xml_node<>* pageNode = docNode->first_node("page");
    myParser.setNodes(pageNode);
    ofs << "title: " << myParser.findTitle() << "\t";
    ofs << "id: " << myParser.findPageID() << endl;

    while(pageNode->next_sibling("page") !=0 )
    {
        pageNode = pageNode->next_sibling("page");
        myParser.setNodes(pageNode);
        ofs << "title: " << myParser.findTitle() << "\t";
        ofs << "id: " << myParser.findPageID() << endl;
    }



}
//will store off author, titl, ID, and XML file name in hard memory

void XMLParser::addPagesToLookup(){

}

void XMLParser::addSinglePageToLookup(){

}
