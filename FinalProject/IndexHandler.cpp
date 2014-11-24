#include "IndexHandler.h"
using namespace std;


IndexHandler::IndexHandler()
{
    myWordParser = new wordParser();
    myIndex = new HashTable<string>();
    //Want default data structure
    //Index* myIndex = new AVLTree();

    memoryInputFile = new char[80];
    memoryOutputFile = new char[80];

    //set default input and output files
    strcpy(memoryInputFile,"input.txt");
    strcpy(memoryOutputFile,"output.txt");
}

IndexHandler::~Indexhandler(){
    delete myWordParser;
    delete myIndex;
    delete[] memoryInputFile;
    delete[] memoryOutputFile;
}

//functions to manage storing off index in hard memory
void IndexHandler::setOutputFile(char* passedFile){
    memoryOutputFile = passedFile;
}

char* IndexHandler::getOutputFile(void){
    return memoryOutputFile;
}

void IndexHandler::setInputFile(char* passedFile){
    memoryInputFile = passedFile;
}

char* IndexHandler::getInputfile(void){
    return memoryInputFile;
}

//function reads formatted saved data into whatever data structure
//indicated by argument
void IndexHandler::buildIndexFromMemory(int choice){
    //Finished after 24th Deadline
}

//writes index to hard memory specified by output file
void IndexHandler::storeOffIndexToMemory(void){

    //Finished after 24th Deadline
}

//Will ask user for input and then will go and print out page numbers
//of the word request
void IndexHandler::findUserWords(void){
    string userWord;
  while(1){
    cout<<"Please Enter Word: ";
    cin>>userWord;
    cout<<endl;
    cout<<"Pages with "<<userWord<<":"<<endl;

    vector<int>* userWordPages = myIndex.findWord(userWord);
    //cycle through vector and print out all words
    for(int i = 0;userWordPages->size();i++){
        cout<<userWordPages->at(i)<<endl;
    }

    //Ask user if wants to keep searching for word
    int choice;
    cout<<"Enter 1 to continue or 0 to exit:"<<;
    cin>>choice;
    if(choice==0){
        break;
    }else{
        cout<<endl;
    }

   }

}


//functions to add or find words form index after stemming and stop
//words done

void IndexHandler::indexBodyOfText(char *body, int pageID){

    stringstream ss;
    string buffer;
    int length = strlen(body);

    //change punctuation to whitspace
    for (int i = 0; i < length; ++i){

        if ( (body[i]!=39) && !(body[i]>=48 && body[i]<=57) //if character is not ', 0-9, A-Z, or a-z
             && !(body[i]>=65 && body[i]<=90) && !(body[i]>=97 && body[i]<=122))
            body[i] = ' '; //change to whitespace
    }

    ss << body;
    while (ss >> buffer ){

        string stemmed = myWordParser.stopAndStem(buffer);

        //if did not send empty string then insert in index
        if(!stemmed.empty()){
            myIndex.insert(stemmed,pageID);
        }

    }

    ss.flush();
}


/*void IndexHandler::addWord(string &singleWord, int pageID){
    //check if word is stop word
    bool result = myWordParser->isStopWord(singleWord);

    string* newStemmedWord;
    //if not stop word then stem and add to index
    if(result == false){
        newStemmedWord = myWordParser->stemWord(singleWord);
        //addWord to index
        myIndex->addWord(newStemmedWord, pageID);
    }

}*/

//same as addWord except for array of strings all on the same page
void IndexHandler::addWords(string word, int pageID){
    //myIndex->insert(word,pageID);
}

//returns all page numbers that word appeared on as stored in
//index
std::vector<int>* IndexHandler::findWord(string* passedWord){
    myIndex->findWord(passedWord);
}

//function used by MaintMode to clear entire index
void IndexHandler::clearIndex(void){
    myIndex->makeEmpty();
}


