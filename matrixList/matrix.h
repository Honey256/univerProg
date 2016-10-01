#include <iostream>
#include <string.h>


class LinkedList{

public:
    struct Node{
    	float value;
        Node *next;
        Node *prev;
        Node *up;
        Node *down;
    };

private:
    Node *head;

public:

    LinkedList(){

        this->head = NULL;
    }

    LinkedList( const LinkedList& matrix );

    ~LinkedList(){
    }

    void addItem( float value, int line, int column );

    void removeRow( int row );

    void removeColumn( int column );

    void printList();

    void shuffle( Node *first, Node *second );

    float mDet( LinkedList matrix );

    float addition( LinkedList matrix, int row, int column );

    void mSum( LinkedList matrix1, LinkedList matrix2 );

    void mMult( LinkedList matrix1, LinkedList matrix2 );

    void transposition();

    void mRev( LinkedList matrix );

};