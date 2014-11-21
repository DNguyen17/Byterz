#include <iostream>
#include"XMLParser.h"

using namespace std;

int main()
{
    XMLParser myXMLParser;
    myXMLParser.loadStopTable();
    myXMLParser.storeOffXMLData();
    myXMLParser.findUserWords();
}

