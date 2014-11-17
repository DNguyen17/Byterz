#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H
#include"wordParser.h"
#include"Index.h"
#include<string>
#include<vector>

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

    void  addWord(std::string* singleWord, int pageID);
    void  addWords(std::string* words, int pageID);
    std::vector<int>*  findWord(std::string* passedWord);
    void clearIndex(void);

private:
    wordParser myWordParser;
    Index myIndex;
    char* memoryInputFile;
    char* memoryOutputFile;
};

#endif // INDEXHANDLER_H
