#ifndef AVLNODE_H
#define AVLNODE_H
using namespace std;

#endif // AVLNODE_H
template <typename Type> class AVLNode
{
    Type element;
    int height;
    AVLNode<Type>* left;
    AVLNode<Type>* right;
    AVLNode (Type theElem, AVLNode* l, AVLNode* r, int h = 0): element(theElem), left(l), right(r), height(h){}

    friend class AVLTree;
};
