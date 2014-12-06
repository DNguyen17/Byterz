#ifndef INTERACTIVEMODE_H
#define INTERACTIVEMODE_H
#include"IndexHandler.h"
#include<string>
#include<vector>
#include<iostream>
#include<IndexHandler.h>
#include<XMLParser.h>


class InteractiveMode
{
public:
    InteractiveMode();
    ~InteractiveMode();

    bool processQuery(string);
    void interactiveUI();
    void createIndex(int choice);
private:
    //data members
    IndexHandler* IMHandler;
    XMLParser* myXMLParser;
    std::vector<int> finalPages;
    std::vector<string> finalTitles;
    std::vector<double> finalTF;
    std::vector<int> totalPages;
    std::vector<string> totalTitles;
    std::vector<double> totalTF;

    string currAuthor;
    string currMaxDate;
    string currMinDate;

    void insertionSort(vector<int>* passedVec, int start, int end);

    //std::vector<int>* printPages(std::string word);

   //boolean commands
    void orPages(std::vector<string>&);
    void andPages(std::vector<string>&);
    void notPages(std::vector<string>&);
    bool compareDates(string);

    vector<int>* orPagesAndReturn(std::vector<vector<int>*>* allList);
    //real functions
    int containsPageStacked(vector<int>* myList,int page);

    int totalContainsPage(int page);


};

#endif // INTERACTIVEMODE_H
