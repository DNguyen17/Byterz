#ifndef WORDPARSER_H
#define WORDPARSER_H
#include<string>
#include"HashTable.h"
#include<vector>


class wordParser
{

public:
    wordParser();
    ~wordParser(){}

    //function analyze stop words
    bool wordParser::isStopWord(string* word);
    //stems words
    bool wordParser::isStopWord(string* word);

    string* stemWord(string*);
    
private:

    Index* stopWordsList;
};

#endif // WORDPARSER_H
