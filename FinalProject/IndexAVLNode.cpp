#include "IndexAVLNode.h"

IndexAVLNode::IndexAVLNode()
{
}


IndexAVLNode::IndexAVLNode(std::string word, IndexAVLNode* l,
                           IndexAVLNode* r, int h )
{
    left = l;
    right = r;
    element = word;
    pageNumbers = new PagesAvlTree<int>();
}

IndexAVLNode::IndexAVLNode(int Pages,std::string word, IndexAVLNode* l,
                IndexAVLNode* r, int h)
{
    height = h;
    left = l;
    right = r;
    this->pageNumbers = new PagesAvlTree<int>();
    pageNumbers->insert(Pages);
    element = word;

}
//constructor for clone function
IndexAVLNode::IndexAVLNode( string word, IndexAVLNode* l,IndexAVLNode* r
                                 ,PagesAvlTree<int>* newTree,int h){
    height = h;
    left = l;
    right = r;
    //delete existing pagenumbers
    delete pageNumbers;
    pageNumbers = newTree;
    element= word;

}

//copy constructor
/*IndexAVLNode::IndexAVLNode(IndexAVLNode y, IndexAVLNode* l, IndexAVLNode* r){
    left = l;
    right = r;
    this->element = y.element;
    //will now access the same vector as the one created
    this->pageNumbers = y.pageNumbers;

}*/

bool operator<(IndexAVLNode &a, IndexAVLNode &b){
    if(a.element.compare(b.element) < 0){
        return true;
    }
    else{
        return false;
    }
}

