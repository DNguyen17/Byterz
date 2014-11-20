#include "XMLParser.h"
using namespace std;

XMLParser::XMLParser()
{
    XMLDumpFile = nullptr;
    title = nullptr;
    id = 0;
    text = nullptr;
}

XMLParser::~XMLParser(){
    //delete myHandler;
    //delete myLookUpTable;

    if (XMLDumpFile != nullptr)
        delete[] XMLDumpFile;
    XMLDumpFile = nullptr;

    if (title != nullptr)
        delete[] title;
    title = nullptr;

    if (text != nullptr)
        delete[] text;
    text = nullptr;

    myParser.~XMLFileParser();
    doc.clear(); //deallocate memory pool of rapidxml class
}

//http://www.cplusplus.com/reference/istream/istream/read/
void XMLParser::setXMLDumpFile(string passedFile){

    if (XMLDumpFile != nullptr){
        delete[] XMLDumpFile;
        XMLDumpFile = nullptr;
    }

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
    ifs.close();
}

//will cycle through all of XML documents in XML dump and index
//all of the words at first into a data structure. The data
//structure will then be saved off to hard memory for persistance
void XMLParser::storeOffXMLData(const char * DumpName){

    ofstream ofs(DumpName);
    int i = 1;

    //loop through all files
    while (i <= 2){

        string fileName = "WikiDumpPart";
        fileName += to_string(i);
        fileName += ".xml";

        setXMLDumpFile(fileName);
        doc.clear();
        doc.parse<0>(XMLDumpFile);
        docNode = doc.first_node("mediawiki");
        xml_node<>* pageNode = docNode->first_node("page");

        //loop through all pages in one file
        while(pageNode !=0 ){

            myParser.setNodes(pageNode);

            title = new char[strlen(myParser.findTitle())+1];
            strcpy(title, myParser.findTitle());
            ofs << "title: " << title << "\t";

            id = myParser.findPageID();
            ofs << "id: " << id << endl;

            text = new char[strlen(myParser.findBodyText())+1];
            strcpy(text, myParser.findBodyText());
            //ofs << myParser.findBodyText() << "\n" << endl;

            pageNode = pageNode->next_sibling("page");

            delete[] title;
            title = nullptr;

            delete[] text;
            text = nullptr;

        }

        ++i;
    }

    ofs.close();

}
//will store off author, title, ID, and XML file name in hard memory

void XMLParser::addPagesToLookup(){

}

void XMLParser::addSinglePageToLookup(){

}
