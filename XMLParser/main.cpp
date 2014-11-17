#include <iostream>
#include <string>
#include <cstring>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
    string test = "<page>1234\n\t<title>cat and dog</title>\n</page>";
    char* buffer = new char[test.length()+1];
    strcpy(buffer,test.c_str());
    xml_document<> doc;
    doc.parse<0>(buffer);
    xml_node<>* pageNode = doc.first_node("page");
    cout << "page: " << pageNode->value() << endl;
    cout << "title: " << pageNode->first_node("title")->value() << endl;
    /*xml_node<>* titleNode = doc.first_node("title");
    cout << "title: " << titleNode->value() << endl;*/
    return 0;
}

