#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "XMLParser.h"
#include "XMLFileParser.h"

using namespace std;
using namespace rapidxml;

int main()
{
    //reading in file
    //http://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c

    //ofstream obj("splitwords.txt");
    XMLParser parser;
    //string name = "WikiDumpPart1.xml";
    //parser.setXMLDumpFile(name);
    parser.storeOffXMLData("output.txt");
    //parser.storeOffNewData(name, obj);

    return 0;
}

