#include "XMLParser.h"

XMLParser::XMLParser()
{
    XMLDumpFile = nullptr;
    //title = nullptr;
    id = 0;
    text = nullptr;
}

XMLParser::~XMLParser(){
    //delete myHandler;
    //delete myLookUpTable;

    if (XMLDumpFile != nullptr)
        delete[] XMLDumpFile;
    XMLDumpFile = nullptr;

    /*if (title != nullptr)
        delete[] title;
    title = nullptr;*/

    if (text != nullptr)
        delete[] text;
    text = nullptr;

    myParser.~XMLFileParser();
    doc.clear(); //deallocate memory pool of rapidxml class
}

//http://www.cplusplus.com/reference/istream/istream/read/
void XMLParser::setXMLDumpFile(string &passedFile){

    if (XMLDumpFile != nullptr){
        delete[] XMLDumpFile;
        XMLDumpFile = nullptr;
    }

    ifstream ifs(passedFile);

    if (!ifs){

        cerr << "unable to open dump file" << endl;
        exit(1);
    }

    ifs.seekg(0, ifs.end);
    int length = ifs.tellg();
    ifs.seekg(0, ifs.beg);

    XMLDumpFile = new char[length];

    ifs.read (XMLDumpFile,length);
    ifs.close();
}

//will cycle through all of XML documents in XML dump and index
//all of the words at first into a data structure. The data
//structure will then be saved off to hard memory for persistance
void XMLParser::storeOffXMLData(const char * DumpName){

    ofstream ofs(DumpName);
    int i = 1;
    ofstream fout("splitWords.txt");

    //loop through all files
    while (i <= 1){

        string fileName = "WikiDumpPart";
        fileName += to_string(i);
        fileName += ".xml";
        storeOffNewData(fileName, fout);

        /*setXMLDumpFile(fileName);
        doc.clear();
        doc.parse<0>(XMLDumpFile);
        docNode = doc.first_node("mediawiki");
        xml_node<>* pageNode = docNode->first_node("page");

        //loop through all pages in one file
        while(pageNode !=0 ){

            myParser.setNodes(pageNode);

            //title = new char[strlen(myParser.findTitle())+1];
            //strcpy(title, myParser.findTitle());
            //ofs << "title: " << title << "\t";

            id = myParser.findPageID();
            //ofs << "id: " << id << endl;

            //if (myParser.findAuthor() != nullptr){
             //   author = myParser.findAuthor();
              //  ofs << "\tauthor: " << author << endl;
            //}

            text = new char[strlen(myParser.findBodyText())+1];
            strcpy(text, myParser.findBodyText());
            indexBodyOfText(text, id, fout);

            pageNode = pageNode->next_sibling("page");

            //delete[] title;
            //title = nullptr;

            delete[] text;
            text = nullptr;

        }*/

        ++i;
    }

    ofs.close();
    fout.close();

}
//will store off author, title, ID, and XML file name in hard memory

void XMLParser::addPagesToLookup(){

}

void XMLParser::addSinglePageToLookup(){

}

void XMLParser::indexBodyOfText(char *body, int pageID, ofstream &fout){

    stringstream ss;
    string buffer;
    //char* buffer = new char[strlen(body)]; //to be passed elsewhere, probably should not delete

    int length = strlen(body);
    for (int i = 0; i < length; ++i){
        //if (body[i] < 48 || (body[i] >= 58 && body[i] < 65)
        //        || (body[i] >= 91 && body[i] < 97) || body[i] >= 123)

        if (!(body[i]>=48 && body[i]<=57) //if character is not ', 0-9, A-Z, or a-z
             && !(body[i]>=65 && body[i]<=90) && !(body[i]>=97 && body[i]<=122))
            body[i] = ' '; //change to whitespace
    }

    ss << body;
    while (ss >> buffer){

        //ss >> buffer;
        fout << buffer << endl;

        /*if (ss.peek() == '<'){ //get rid of XML nodes
            ss.ignore(strlen(body), '>');
        }

        else if ((ss.peek() < 48) || (ss.peek() >= 60 && ss.peek() < 65)
                 || (ss.peek() >= 91 && ss.peek() < 97) || ss.peek() >= 123){
            ss.ignore();
        }

        else {
            ss >> buffer;

            //remove punctuation in buffer? code from
            //http://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
            //remove_if(buffer.begin(), buffer.end(), std::ptr_fun<int, int>(&std::ispunct));

            fout << buffer << endl;
            //string stemmed = myWordParser.stopAndStem(buffer);
            if(stemmed != ""){

            }*/
        //}
    }
    /*char* first = body;
    char* space = strchr(first, ' ');
    char* newline = strchr(first,'\n');
    char* tab = strchr(first, '\t');
    char* split = nullptr;

    while (space != nullptr){

        split = space;
        if ((newline < space) && newline != nullptr)
            split = newline;
        if ((tab < split) && tab != nullptr)
            split = tab;

        split[0] = '\0';

        fout << first << endl;

        first = split+1;
        newline = strchr(first, '\n');
        space = strchr(first, ' ');
        tab = strchr(first, '\t');
    }

    fout << first << endl;*/
    //ss.flush();
    //delete[] buffer;

}

/*char* XMLParser::getAuthor()
{
    if (myParser.findAuthor() == nullptr)
        return nullptr;

    //return author;
}*/

void XMLParser::storeOffNewData(string &fileName, ofstream& fout)
{
    setXMLDumpFile(fileName);

    doc.clear();
    doc.parse<0>(XMLDumpFile);
    docNode = doc.first_node("mediawiki");
    xml_node<>* pageNode = docNode->first_node("page");
    //ofstream ofs("output.txt");

    //myParser.setNodes(pageNode);
    //fout << myParser.findPageID() << ", ";
    //loop through all pages in one file
    while(pageNode !=0 ){

        myParser.setNodes(pageNode);

        id = myParser.findPageID();
        text = new char[strlen(myParser.findBodyText())+1];
        strcpy(text, myParser.findBodyText());

        indexBodyOfText(text, id, fout);

        /*if (pageNode->next_sibling("page") == 0)
            fout << myParser.findPageID() << endl;*/ //finding page ranges
        pageNode = pageNode->next_sibling("page");

        delete[] text;
        text = nullptr;
    }

    //fout.close();


}
