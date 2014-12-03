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

    XMLParser parser;
    //string name = "WikiDumpPart.xml";
    //parser.setXMLDumpFile(name);
    parser.storeOffXMLData("output.txt");
    //parser.storeOffNewData(name);

    return 0;
}

