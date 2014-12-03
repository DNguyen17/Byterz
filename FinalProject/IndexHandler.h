#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H
#include"WordParser2.h"
#include"Index.h"
#include<string>
#include<vector>
#include<sstream>
#include"HashTable.h"
#include"Index.h"

class IndexHandler
{
public:
    IndexHandler();
    ~IndexHandler();

    //functions to interface with hard memory storage
    void  setOutputFile(char* passedFile);
    char*  getOutputFile(void);
    void  setInputFile(char* passedFile);
    char*  getInputfile(void);
    void  buildIndexFromMemory(int choice);
    void  storeOffIndexToMemory(void);

    void indexBodyOfText(char *body, int pageID);
    void  addWord(std::string singleWord, int pageID);
    //void  addWords(std::string* words, int pageID);
    std::vector<int>*  findWord(std::string & passedWord);
    void clearIndex(void);

    void findUserWords(void);

    void insertionSort(vector<int>* passedVec, int start, int end);
    void loadStopTable();

private:
    WordParser2* myWordParser;
    Index* myIndex;
    char* memoryInputFile;
    char* memoryOutputFile;
};

#endif // INDEXHANDLER_H
