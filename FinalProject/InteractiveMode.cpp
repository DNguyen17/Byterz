#include "InteractiveMode.h"
using namespace std;
#include<vector>
#include<iterator>
#include<cmath>
void andFunction(vector<string>& nextWords);
void orFunction(vector<string>& nextWords);
void ltFunction(vector<string>& nextWords);
void usernameFunction(vector<string>& nextWords);
void notFunction(vector<string>& nextWords);
void gtFunction(vector<string>& nextWords);

InteractiveMode::InteractiveMode()
{
    myXMLParser = new XMLParser();
    IMHandler = NULL;
    finalPages.clear();
    finalTF.clear();
    finalTitles.clear();
    currAuthor = "";
    currMaxDate = "";
    currMinDate = "";
}

InteractiveMode::~InteractiveMode(){
    delete myXMLParser;
}

void InteractiveMode::insertionSort(vector<int>* passedVec, int start, int end){
      int i, j;
     int tempPage;
     int tempCount;
     int length = end - start + 1;

     for (i = start + 2; i < start + length; i++) {
         //cout<<"i is "<<i<<endl;
         //cout<<"j is "<<j<<endl;
         j = i;
         i++;
         while (j > start && (passedVec->at(j-1)<passedVec->at(j+1))){
             tempPage = passedVec->at(j);
             tempCount = passedVec->at(j+1);
             passedVec->at(j) = passedVec->at(j-2);
             passedVec->at(j+1) = passedVec->at(j-1);
             passedVec->at(j-2) = tempPage;
             passedVec->at(j-1) = tempCount;

             j = j-2;
         }//end of while loop

    }


}

//will create Index of Avl or Hash Table
void InteractiveMode::createIndex(int choice){
    if(choice == 1){
        IMHandler = new IndexHandler(1);
    }
    else{

        IMHandler = new IndexHandler(0);
    }
}

void InteractiveMode::interactiveUI(){
    while(1){
        if(IMHandler == NULL){
            int userChoice;
            while(1){

                cout<<"Pick Which Data Structure to Load index into:"<<endl;
                cout<<"Enter 0 for Hash Table"<<endl;
                cout<<"Enter 1 for AVL Tree"<<endl;

                cout<<"User Choice: ";
                cin>>userChoice;
                if(userChoice != 1 && userChoice != 0){
                    cout<<"Invalid Number!"<<endl;
                    cout<<endl;
                    continue;
                }
                else{
                    createIndex(userChoice);
                    break;
                }
            }

       }

        //beginning of loop that
        cout<<"Please Enter Query (or END to Quit):";
        string userQuery;
        cin.ignore();
        getline(cin,userQuery);

        bool end = processQuery(userQuery);
        if(end == true){
            break;
        }

    }
}

//will return true if user entered "EXIT" so loop will stop

bool InteractiveMode::processQuery(string userQuery){
        string delimiter = " ";
        cout<<"userQuery at beginning of processQuery "<<userQuery<<endl;

        //eliminate any leading white space
        while(1){
           if(delimiter.compare(userQuery.substr(0,1)) == 0){
               userQuery = userQuery.substr(1,userQuery.size()-1);
           }
           else{
               break;
           }
        }
        //get first string of user keyword
        string firstCommand = userQuery.substr(0,userQuery.find(delimiter));


        //check that the first word is not END
        if(firstCommand.compare("END") == 0){
            cout<<"ProcessQuery:Selected to End program";
            return true;
        }

        vector<string> keyWords;
        keyWords.push_back("AND");
        keyWords.push_back("OR");
        keyWords.push_back("NOT");
        keyWords.push_back("DATEGT");
        keyWords.push_back("DATELT");
        keyWords.push_back("USERNAME");

       //make sure first commmand is either AND or OR
       //RULE must start wiht AND or OR!!!!
        bool correctStart = false;
        for(int i = 0;i<2;i++){
            if(firstCommand.compare(keyWords.at(i)) == 0){
                correctStart = true;
            }
        }

        if(correctStart != true){
            cout<<"Need to Enter AND or OR as first word in Query!"<<endl;
            return false;
        }

        //gets rid of first word from user string
        userQuery = userQuery.substr(userQuery.find(delimiter)+1,userQuery.size());

        //cout<<"NewUserQuery "<<userQuery<<endl;
        //cout<<"size = "<<userQuery.size()<<endl;

        cout<<"First Command"<<firstCommand;
        string currKeyWord = firstCommand;

        //get all words until next keyword
        vector<string> nextWords;
        string currWord;

        //need loop that checks userQuery not empty
        while(!currKeyWord.empty()){
            cout<<"\nCurrKeyWord = "<<currKeyWord<<endl;
            //while loop that collects all following words after keyword;
            while(1){
                //eliminate whitespace
                while(1){
                   if(delimiter.compare(userQuery.substr(0,1)) == 0){
                       userQuery = userQuery.substr(1,userQuery.size()-1);
                   }
                   else{
                       break;
                   }
                }
                //check that userQuery string not empty
                if(userQuery.empty()){
                   currWord = "";
                   break;
                }
                else{
                    cout<<"UserQuery = "<<userQuery<<endl;
                    //get next word
                    currWord = userQuery.substr(0,userQuery.find(delimiter));
                    cout<<"CurrWord collected = "<<currWord<<endl;
                    //take off processed word from userQuery
                    if(userQuery.size() <= currWord.size()+1){
                        userQuery = "";
                    }
                    else{
                     userQuery = userQuery.substr(userQuery.find(delimiter)+1,userQuery.size());
                    cout<<"UserQuery after deletion = "<<userQuery<<endl;

                    }
                }

                //cout<<"inside loop"<<endl;
                bool breakFlag = 0;
                //check nextWord not match any of key words
                for(int i = 0;i<keyWords.size();i++){
                    if(currWord.compare(keyWords.at(i)) == 0){
                        breakFlag = 1;

                        break;
                    }
                }


                if(breakFlag == 1){
                    break;
                }

                //haven't encountered keyword yet
                nextWords.push_back(currWord);

            }

            //once break and have keyword

            //verify that at least got one argument
            if(nextWords.size()<1){
                cout<<"Keyword was followed by no arguments so just ignoring"<<endl;
                currKeyWord = currWord;
                //cout<<"currKeyWord inside empty list catcher = "<<currKeyWord;
                continue;

            }

            //call the keyword function
            if(currKeyWord.compare("AND") == 0){
                //create vectors to pass by reference
                vector<int>* andPagesList;
                vector<double>* andTFIDFLIst;
                andPages(nextWords,andPagesList,andTFIDFList);
                totalPages = *(pagesAndTF->at(0));
                totalTF = *(pagesAndTF->at(1));

            }
            else if(currKeyWord.compare("OR") == 0){
                vector< vector<int>* >* pagesAndTF = orPages(nextWords);
                totalPages = *(pagesAndTF->at(0));
                totalTF = *(pagesAndTF->at(1));
            }
            else if(currKeyWord.compare("NOT") == 0){
                vector< vector<int>* >* pagesAndTF = notPages(nextWords);
                totalPages = *(pagesAndTF->at(0));
                totalTF = *(pagesAndTF->at(1));


            }else if(currKeyWord.compare("DATEGT") == 0){
                gtFunction(nextWords);

            }
            else if(currKeyWord.compare("DATELT") == 0){
                ltFunction(nextWords);
            }
            else if(currKeyWord.compare("USERNAME") == 0){
                usernameFunction(nextWords);
            }


            //set next key word to what was currently stored in currWord
            currKeyWord = currWord;
            cout<<currKeyWord<<endl;
            //clear next words
            nextWords.clear();
        }
}

/*
void InteractiveMode::printPages(string word){
    vector<int>* pageNumbers = IModeHandler->findWord(word);

    cout<<"Page Numbers for "<<word<<":"<<endl;
    for(int i = 0;i<pageNumbers.size();i++){
        cout<<"Page "<<pageNumbers.at(i)<<endl;
    }

}
*/

//finds intersection of all vectors in list

void andFunction(vector<string>& nextWords){
        cout<<"AND function:"<<endl;
        cout<<"Collected next words"<<endl;
        //print out all following words
        for(int y = 0;y<nextWords.size();y++){
            cout<<nextWords.at(y)<<" size: "<<nextWords.at(y).size()<<endl;
        }
}

void orFunction(vector<string>& nextWords){
        cout<<"OR function:"<<endl;
        cout<<"Collected next words"<<endl;
        //print out all following words
        for(int y = 0;y<nextWords.size();y++){
            cout<<nextWords.at(y)<<" size: "<<nextWords.at(y).size()<<endl;
        }
}

void notFunction(vector<string>& nextWords){
        cout<<"NOT function:"<<endl;
        cout<<"Collected next words"<<endl;
        //print out all following words
        for(int y = 0;y<nextWords.size();y++){

            cout<<nextWords.at(y)<<" size: "<<nextWords.at(y).size()<<endl;
        }
}

void gtFunction(vector<string>& nextWords){
        cout<<"DATEGT function:"<<endl;
        cout<<"Collected next words"<<endl;
        //print out all following words
        for(int y = 0;y<nextWords.size();y++){
            cout<<nextWords.at(y)<<" size: "<<nextWords.at(y).size()<<endl;
        }
}

void ltFunction(vector<string>& nextWords){
        cout<<"DATELT function:"<<endl;
        cout<<"Collected next words"<<endl;
        //print out all following words
        for(int y = 0;y<nextWords.size();y++){
            cout<<nextWords.at(y)<<" size: "<<nextWords.at(y).size()<<endl;
        }
}

void usernameFunction(vector<string>& nextWords){
        cout<<"USERNAME function:"<<endl;
        cout<<"Collected next words"<<endl;
        //print out all following words
        for(int y = 0;y<nextWords.size();y++){
            cout<<nextWords.at(y)<<" size: "<<nextWords.at(y).size()<<endl;
        }
}
/*
//will loop through and add up all frequencies of all pages
int getTotalOccurances(std::vector<int> & passedList){
    int total = 0;
    for(int i = 0;i<passedList.size();i++){
        total = total + passsedList(i+1);
        i++;
    }

    return total;
}
*/
/**************NEED to Calculate Term frequency before combine*********/
void InteractiveMode::orPages(std::vector<string> & passedWords,
                              vector<int>* & orPageList,
                              vector<double>*& orTFList){
    //create vectors to hold pages and TFIDF
    orPageList = new vector<int>();
    orTFList = new vector<double>();

    double totalDocs =  IMHandler->getTotalDocs();
    for(int i = 0;i<passedWords.size();i++){

        //get list of pages for word
        vector<int>* pageList = IMHandler->findUserWord(passedWords.at(i));
        //calculate IDF for word
        double numberDocs = (pageList->size())/2;
        double IDF = log(totalDocs/(1+numberDocs));
        //for each page in list, add to total list or add frequency
        //to already existing index of page

        for(int j = 0;j<pageList->size();j++){
            //get total time word occured in whole corpus

            //calculate TF/IDF for specific page
            double TF = pageList->at(j+1);
            double TFIDF =  TF*IDF;

            //check if page already exist
            int index = totalContainsPage(orPageList,pageList->at(j));
            if(index > 0){
                //add term frequency if already exists
                orTFList->at(index) = orTFList->at(index) + TFIDF;
            }
            else{
                orPageList->push_back(pageList->at(j));
                orTFList->push_back(TFIDF);

            }
            //increment so go to next even index
            j++;
        }

    }

    //once processed all words the vectors have already been changed
    //by reference so not need to return anything

}
/**************NEED to Calculate Term frequency before combine*********/
vector<int>* InteractiveMode::orPagesAndReturn(std::vector<vector<int>*>* allList){
    vector<int>* mytotalPages = new vector<int>();
    for(int i = 0;i<allList->size();i++){
        for(int j = 0;j<allList->at(i)->size();j++){
            int index = containsPageAnd(mytotalPages,allList->at(i)->at(j));

        }
        /*for(int j = 0;j<pageList->size();j++){
            //check if page already exist
            int index = totalContainsPage(pageList->at(j));
            if(index > 0){
                //add term frequency if already exists
                totalTF.at(index) = totalTF.at(index) + pageList->at(j+1);
            }
            else{
                totalPages.push_back(pageList->at(j));
                totalTF.push_back(pageList->at(j+1));
            }

        }*/

    }
}


void InteractiveMode::andPages(std::vector<string> & passedWords,
                               vector<int>* & andPageList,
                               vector<double>* &andTFIDFList ){



    //assemble vector of page numbers of all words
    vector<vector<int>*>* allLists = new vector<vector<int>*>();
    for(int i = 0;i<passedWords.size();i++){
        allLists->push_back(IMHandler->findUserWord(passedWords.at(i)));
    }

    //get complete list of all total words
    vector<int>** andedPagesandTF = orPagesAndReturn(allLists);


    //check and see if all page numbers have

}


int InteractiveMode::totalContainsPage(vector<int>* passedPages,int page){
    for(int i = 0;i<passedPages->size();i++){
        if(passedPages->at(i) == page){
            return i;
        }

    }

    //if didn't find it
    return -1;
}




int InteractiveMode::containsPageAnd(vector<int>* myList,int page){
    for(int i = 0;i<myList->size();i++){
        if(myList->at(i) == page){
            return i;
        }

    }

    //if didn't find it
    return -1;
}


