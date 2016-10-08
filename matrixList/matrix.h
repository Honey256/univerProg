#include <iostream>
#include <string.h>


class MatrixList{

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

    void insertItemR( float value, int row, int column );

    void insertItemC( float value, int row, int column );

    bool sqrValid( MatrixList *matrix );

    bool multValid( MatrixList *matrix1, MatrixList *matrix2 );

    bool sumValid( MatrixList *matrix1, MatrixList *matrix2 );

public:

    MatrixList();

    MatrixList( const MatrixList& matrix );

    MatrixList operator=(const MatrixList matrix);

    MatrixList( int row, int column );

    ~MatrixList();
    
    void addItem( float value, int line, int column );

    void changeItem( float value, int row, int column );

    void addRow( std::string str );

    void addRow( std::string str, int row );

    void addColumn( std::string str );

    void addColumn( std::string str, int column );

    void removeRow( int row );

    void removeColumn( int column );

    void printList();

    void swap( Node *first, Node *second );

    float determinant( MatrixList matrix );

    float addition( MatrixList matrix, int row, int column );

    MatrixList operator+( MatrixList matrix2 ) const;

    MatrixList operator*( MatrixList matrix2 ) const;

    void matrixSum( MatrixList matrix1, MatrixList matrix2 );
    
    void matrixMult( MatrixList matrix1, MatrixList matrix2 );

    void transposition();

    void matrixRev( MatrixList matrix );

    float get( int row, int column );
    
    void find( float value );

    int rank();

};