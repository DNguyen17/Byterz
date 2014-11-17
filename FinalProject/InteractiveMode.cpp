#include "InteractiveMode.h"
using namespace std;
#include<vector>

InteractiveMode::InteractiveMode()
{
    IModeHandler = new IndexHandler();
}

void InteractiveMode::printPages(string word){
    vector<int>* pageNumbers = IModeHandler->findWord(word);

    cout<<"Page Numbers for "<<word<<":"<<endl;
    for(int i = 0;i<pageNumbers.size();i++){
        cout<<"Page "<<pageNumbers.at(i)<<endl;
    }

}
