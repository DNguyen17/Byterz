#include <iostream>
#include"XMLParser.h"
#include"FakeXMLParser.h"
#include"InteractiveMode.h"
using namespace std;
/*
int main()
{
    XMLParser myXMLParser;
    myXMLParser.loadStopTable();
    myXMLParser.storeOffXMLData("output.txt");
    myXMLParser.findUserWords();
}

int main()
{
    FakeXMLParser myXMLParser;
    myXMLParser.loadStopTable();
    myXMLParser.storeOffXMLData();
    myXMLParser.findUserWords();
    char boo[] = "FakeParserIndex.txt";
    myXMLParser.storeOffIndex(boo);

}
*/
/*int main(){
    IndexHandler newHandler;
    char newFile[] = "FakeParserIndex.txt";

    newHandler.setInputFile(newFile);
    newHandler.loadStopTable();
    newHandler.buildIndexFromMemory(0);
    newHandler.findUserWords();
}*/

int main(){
    InteractiveMode IM;
    IM.interactiveUI();
}


