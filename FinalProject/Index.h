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
    virtual void makeEmpty() = 0;
    virtual void insert(std::string&,int&)= 0;
    //virtual void addWords(std::string*, int*) = 0;
    virtual bool contains(std::string);

private:
    int wordCount;
};

#endif // INDEX_H
