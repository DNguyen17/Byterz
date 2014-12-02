#include "FakeXMLParser.h"
#include<string>
#include<vector>
#include<iostream>
#include<fstream>

FakeXMLParser::FakeXMLParser()
{
    myHandler = new IndexHandler();
    myLookUpTable = new LookUpTable();

    title = nullptr;
    id = 0;
    text = nullptr;
}

FakeXMLParser::~FakeXMLParser(){
    delete myHandler;
    delete myLookUpTable;

    if (title != nullptr)
        delete[] title;
    title = nullptr;

    if (text != nullptr)
        delete[] text;
    text = nullptr;

    //myParser.~XMLFileParser();
    //doc.clear(); //deallocate memory pool of rapidxml class

}

void FakeXMLParser::loadStopTable(){
    myHandler->loadStopTable();
}

void FakeXMLParser::findUserWords(){
    myHandler->findUserWords();
}

void FakeXMLParser::storeOffIndex(char* output){
    myHandler->setOutputFile(output);
    myHandler->storeOffIndexToMemory();
}

void FakeXMLParser::storeOffXMLData(){
    //will just read from file and store
    //off words
    ifstream inputFile;
    inputFile.open("FakeParserWords.txt");

    string buffer;

    inputFile>>buffer;
    if(!inputFile){
        //cout<<"stop words list file did not open"<<endl;
        exit(1);
    }

    int pageNumber = 1;
    while(inputFile>>buffer ){
        cout<<buffer<<endl;
        if(buffer.size()<=1){
            pageNumber++;
            continue;
        }
        char* myChar = new char[buffer.size()+1];
        for(int i = 0;i<buffer.size();i++){
            myChar[i] = buffer.at(i);
        }
        myChar[buffer.size()] = '\0';

        myHandler->indexBodyOfText(myChar,pageNumber);
       //cout<<buffer<<endl;
    }

}

/*
    //open XML file from XMLDumpFile

    ofstream ofs(DumpName);
    int i = 100;
    //ofstream fout("splitWords.txt");

    //loop through all files
    while (i <= 179){

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
            //ofs << "title: " << title << "\t";

            id = myParser.findPageID();
            //ofs << "id: " << id << endl;

            text = new char[strlen(myParser.findBodyText())+1];
            strcpy(text, myParser.findBodyText());

            myHandler->indexBodyOfText(text, id);

            pageNode = pageNode->next_sibling("page");



            delete[] title;
            title = nullptr;

            delete[] text;
            text = nullptr;
        }

        ++i;
    }

    ofs.close();
    //fout.close();

*/



