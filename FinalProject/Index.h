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

    virtual std::vector<int>* findWord(std::string&);
    virtual void makeEmpty();
    virtual bool insert(std::string&,int&);
    //virtual void addWords(std::string*, int*);
    virtual bool contains(std::string&);

private:
    int wordCount;
};

#endif // INDEX_H
