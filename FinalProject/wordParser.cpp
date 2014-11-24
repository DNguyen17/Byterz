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

//stemms word
string* stemmer(string*){


    return ;
}

//function returns word after stemming or null if it is a stop word
string* stopAndStem(string* preStemmed){
    string* stemmedString  = new string();

    stemmedString = stemmer(preStemmed);
    //stem the string using 3rd part
    /*
    
    */
    //if the stemmed word is a stop word return null
    if(isStopWord(stemmedString))
        return "";
    //otherwise return the stemmed word
    else 
        return stemmedString;

}

