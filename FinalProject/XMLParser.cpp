#include "XMLParser.h"
using namespace std;

XMLParser::XMLParser()
{
    myHandler = new IndexHandler();
    myLookUpTable = new LookUpTable();
    myParser = new XMLFileParser();

    XMLDumpFile = new char[80];
    //default input file
    strcpy(XMLDumpFile,"XMLDump.xml");
}

XMLParser::~XMLParser(){
    delete myHandler;
    delete myLookUpTable;
    delete[] XMLDumpFile;

}

void XMLParser::setXMLDumpFile(char* passedFile){
    XMLDumpFile = passedFile;
}

//will cycle through all of XML documents in XML dump and index
//all of the words at first into a data structure. The data
//structure will then be saved off to hard memory for persistance
void XMLParser::storeOffXMLData(char * DumpName){
   //open XML file from XMLDumpFile

    char* fileName = new char[80];
    while(/*not reached end of XML Dump*/){
        //get new XML file name fileName
        strcpy(fileName,/*somehow get fileName of XML */);

        //uses XMLFileParserObject ot retrive all desired informatoin
        //from XML file and then stores off information in data structure
        //or lookup table

        string* bodyAndID = myParser->getBodyandID(fileName);
        addBodyTextToIndex(bodyAndID[0], bodyAndID[1]);

        //store off information for lookup Table (Not included 24th Demo
        string author = myParser->getAuthor(fileName);
        string title = myParser->getTitle(fileName);
        string date = myParser->getDate(fileName);
    }

    //processed all XML files
    myHandler->storeOffIndexMemory();


}

//function stores all words in page into data structure index
void XMLParser::indexBodyOfText(string* body, string pageID){
    //loop through every word and send it to be indexed
    //************could be optimized somehow by analyzing
    //if word is stop word before sending to be indexed??*******//

    //Loop that will go through and send each word and page to
    //index handler to be inserted into data structure
    myHandler->addWord(word,pageID);

}

//will store off authro, titl, ID, and XML file name in hard memory
//Not for 24th Due date
void XMLParser::addPagesToLookup(){

}

void XMLParser::addSinglePageToLookup(){

}
