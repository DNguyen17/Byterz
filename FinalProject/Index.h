#ifndef INDEX_H
#define INDEX_H
#include<string>
#include<vector>

class Index
{
public:
    Index();
    ~Index();

    //getters, setters
    int getWordCount(void);
    void setWordCount(int);
    void incrementWordCount(void);

    virtual std::vector<int>* findWord(std::string*)=0;
    virtual void clearIndex() = 0;
    virtual void addWord(std::string*,int)= 0;
    virtual void addWords(std::string*, int*) = 0;
    virtual bool findInList(std::string);

private:
    int wordCount;
};

#endif // INDEX_H
