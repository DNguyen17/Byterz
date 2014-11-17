#include "wordParser.h"
#include<fstream>
#include<iostream>
using namespace std;


wordParser::wordParser()
{
    stopWordsList = new HashTable<string>();
    //read in all of the stop words and store in HashTable
    ifstream stopWordFile;
    char* inputFile = new char[80];
    strcpy(inputFile,"StopWords.txt");
    stopWordFile.open(inputFile);

    if(!stopWordFile.is_open()){
        cerr<<"Stop Words File could not be opened"<<endl;

    }

    //loop that will go through and populate HashTable with all
    //stop words

    string buffer;
    while(stopWordFile>>buffer){
       stopWordsList->addWord(buffer);
    }

}

//function checks if stop word, returns true if stop word
bool wordParser::isStopWord(string* word){
    bool result = stopWordList->findInList(word);

    return result;
}

//function returns word after stemming
string* stemWord(string*){
    string* stemmedString  = new string();
    //stem the string using 3rd part
    /*

    */
    return stemmedString;

}

