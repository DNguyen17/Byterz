#ifndef INTERACTIVEMODE_H
#define INTERACTIVEMODE_H
#include"IndexHandler.h"
#include<string>
#include<vector>

class InteractiveMode
{
public:
    InteractiveMode();
    ~InteractiveMode(){}

private:
    IndexHandler* IModeHandler;
    std::vector<int>* printPages(std::string word);

};

#endif // INTERACTIVEMODE_H
