#include <iostream>
#include"XMLParser.h"
#include"FakeXMLParser.h"
using namespace std;
/*
int main()
{
    XMLParser myXMLParser;
    myXMLParser.loadStopTable();
    myXMLParser.storeOffXMLData("output.txt");
    myXMLParser.findUserWords();
}
*/
int main()
{
    FakeXMLParser myXMLParser;
    myXMLParser.loadStopTable();
    myXMLParser.storeOffXMLData();
    myXMLParser.findUserWords();
}
