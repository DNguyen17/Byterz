#include "IndexHandler.h"
using namespace std;


IndexHandler::IndexHandler()
{
    myWordParser = new wordParser();
    myIndex = new AVLTree();
    //Want default data structure
    //Index* myIndex = new AVLTree();

    memoryInputFile = new char[80];
    memoryOutputFile = new char[80];

    //set default input and output files
    strcpy(memoryInputFile,"input.txt");
    strcpy(memoryOutputFile,"output.txt");
}

IndexHandler::~Indexhandler(){
    delete myWordParser;
    delete myIndex;
    delete[] memoryInputFile;
    delete[] memoryOutputFile;
}

//functions to manage storing off index in hard memory
void IndexHandler::setOutputFile(char* passedFile){
    memoryOutputFile = passedFile;
}

char* IndexHandler::getOutputFile(void){
    return memoryOutputFile;
}

void IndexHandler::setInputFile(char* passedFile){
    memoryInputFile = passedFile;
}

char* IndexHandler::getInputfile(void){
    return memoryInputFile;
}

//function reads formatted saved data into whatever data structure
//indicated by argument
void IndexHandler::buildIndexFromMemory(int choice){

}

//writes index to hard memory specified by output file
void IndexHandler::storeOffIndexToMemory(void){

}

//functions to add or find words form index after stemming and stop
//words done
void IndexHandler::addWord(string* singleWord, int pageID){
    //check if word is stop word
    bool result = myWordParser->isStopWord(singleWord);

    string* newStemmedWord;
    //if not stop word then stem and add to index
    if(result == false){
        newStemmedWord = myWordParser->stemWord(singleWord);
        //addWord to index
        myIndex->addWord(newStemmedWord, pageID);
    }

}

//same as addWord except for array of strings all on the same page
void IndexHandler::addWords(string* words, int pageID){

}

//returns all page numbers that word appeared on as stored in
//index
std::vector<int>* IndexHandler::findWord(string* passedWord){
    myIndex->findWord(passedWord);
}

//function used by MaintMode to clear entire index
void clearIndex(void){
    myIndex->clearIndex();
}


