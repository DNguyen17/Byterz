#include <iostream>
#include<string>
#include "AvlTree.h"
#include"IndexAVLNode.h"
#include<vector>
#include"SeparateChaining.h"
using namespace std;

//Test program for AVL trees with IndexAVLNodes as nodes
/*int main(){
    AvlTree<string> t;
    vector<int>* myVector = new vector<int>;
    for(int i = 0;i<10;i++){
        myVector->push_back(i);
    }


    vector<int>* myVector1 = new vector<int>;
    myVector1->push_back(42);

    vector<int>* myVector2 = new vector<int>;
    myVector2->push_back(80);

    t.insert("dog",myVector);
    t.insert("aa",myVector1);
    t.insert("yo",myVector2);

    vector<int>* newVector = new vector<int>;
    newVector->push_back(14);
    newVector->push_back(20);
    t.insert("dog",newVector);

    t.printTree();
}*/
    // Test program for AVL tree
/*int main( )
{
    AvlTree<int> t, t2;
    int NUMS = 20;
    const int GAP  =   37;
    int i;
    int myArray[] = {1, 3, 6, 9, 11, 17, 18, 45, 24, 19, 18, 22, 20};
    int size = 13;

    cout << "Checking... (no more output means success)" << endl;

    /*for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );*/
/*
    for(i = 0;i<size;i++){
        t.insert(myArray[i]);
    }

    t.printTree( );
/*    if( t.findMin( ) != 1 || t.findMax( ) != NUMS - 1 )
        cout << "FindMin or FindMax error!" << endl;

    t2 = t;

    for( i = 1; i < NUMS; i++ )
        if( !t2.contains( i ) )
            cout << "Find error1!" << endl;
    if( t2.contains( 0 ) )
        cout << "ITEM_NOT_FOUND failed!" << endl;
*/
 /*   cout << "Test finished" << endl;
    return 0;
}
*/

//Test program for hash table
#include <iostream>
#include "SeparateChaining.h"
using namespace std;

//Simple main
/*int main( )
{
    HashTable<string>* H = new HashTable<string>(6);

    const int NUMS = 4000;
    const int GAP  =   37;
    int i;

    string myArray[] =
    {"hey","there","dawg","how","Dawg","Dahn","Basketball","does","mouse","heydur","wasup","idk"};
    for(int i = 0;i<6;i++){
        H->insert(myArray[i]);
    }

    for(int i = 1;i<H->getSize();i++){
        cout<<(H->getList())[i].front()<<endl;
    }
*//*
    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        H.insert( i );
    for( i = 1; i < NUMS; i += 2 )
        H.remove( i );

    for( i = 2; i < NUMS; i += 2 )
        if( !H.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( H.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }

}*/

/**
 * A hash routine for string objects.
 */
int hash( const string & key , int size)
{
    int hashVal = 0;

    for( int i = 0; i < key.length( ); i++ )
        hashVal = 37 * hashVal + key[ i ];

    hashVal %= size;
    if( hashVal < 0 )
        hashVal += size;

    return hashVal;
}

int main(){


    vector<string> myVec;
    string myArray[] = {"hey","there","dawg","how","Dawg","Dahn","Basketball","does","mouse","heydur","wasup","idk"};
    for(int i = 0;i<sizeof(myArray)/sizeof(myArray[1]);i++){
        cout<<myArray[i]<<endl;
        myVec.push_back(myArray[i]);
    }

   HashTable<string> myTable;
   for(int j = 0;j<myVec.size();j++){

        myTable.insert(myVec.at(j),j);
   }

   myTable.print();

}
