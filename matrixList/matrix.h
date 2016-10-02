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

    LinkedList();

    LinkedList( const LinkedList& matrix );

    LinkedList operator=(const LinkedList matrix);

    LinkedList( int row, int column );

    ~LinkedList(){}
    
    void addItem( float value, int line, int column );

    void removeRow( int row );

    void removeColumn( int column );

    void printList();

    bool sqrValid( LinkedList *matrix );

    bool multValid( LinkedList *matrix1, LinkedList *matrix2 );

    bool sumValid( LinkedList *matrix1, LinkedList *matrix2 );

    void shuffle( Node *first, Node *second );

    float mDet( LinkedList matrix );

    float addition( LinkedList matrix, int row, int column );

    LinkedList operator+( LinkedList matrix2 ) const;

    LinkedList operator*( LinkedList matrix2 ) const;

    void mSum( LinkedList matrix1, LinkedList matrix2 );
    
    void mMult( LinkedList matrix1, LinkedList matrix2 );

    void transposition();

    void mRev( LinkedList matrix );

    float get( int row, int column );

};