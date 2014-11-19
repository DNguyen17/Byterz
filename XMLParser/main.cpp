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

    /*ifstream ifs("WikiDumpPart1.xml");
    ifs.seekg(0, ifs.end);
    int length = ifs.tellg();
    ifs.seekg(0, ifs.beg);

    char * buffer = new char[length];

    ifs.read (buffer,length);

    if (ifs)
        std::cout << "all characters read successfully." << endl;
    else
        std::cout << "error: only " << ifs.gcount() << " could be read" << endl;
    ifs.close();

    //parsing
    xml_document<> doc;
    doc.parse<0>(buffer);
    xml_node<>* node = doc.first_node("mediawiki");
    cout << "find page: " << node->first_node("page") << endl;
    xml_node<>* pageNode = node->first_node("page");
    pageNode = pageNode->next_sibling("page");
    pageNode = pageNode->next_sibling("page");
    cout << "node name: " << pageNode->name() << endl;
    xml_node<>* titleNode = pageNode->first_node("title");
    xml_node<>* idNode = pageNode->first_node("id");
    xml_node<>* textNode = pageNode->first_node("revision")->first_node("text");
    cout << "title: " << titleNode->value() << endl;
    cout << "page id: " << idNode->value() << endl;
    cout << "Text Body:\n" << textNode->value() << endl;

    delete[] buffer;*/

    XMLParser parser;
    parser.setXMLDumpFile("WikiDumpPart1.xml");
    parser.storeOffXMLData("output.txt");


    return 0;
}

