#include <iostream>
#include "AvlTree.h"
using namespace std;

    // Test program
int main( )
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
    cout << "Test finished" << endl;
    return 0;
}
