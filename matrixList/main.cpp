#include "matrix.h"


int main(){

    LinkedList *matrix1 = new LinkedList();
    
    matrix1->addItem( 1, 1, 1 );
    matrix1->addItem( 2, 1, 2 );
    matrix1->addItem( 3, 1, 3 );
    matrix1->addItem( 4, 1, 4 );
    matrix1->addItem( 5, 1, 5 );

    matrix1->addItem( 1, 2, 1 );
    matrix1->addItem( 4, 2, 2 );
    matrix1->addItem( 8, 2, 3 );
    matrix1->addItem( 7, 2, 4 );
    matrix1->addItem( 7, 2, 5 );

    matrix1->addItem( 2, 3, 1 );
    matrix1->addItem( 2, 3, 2 );
    matrix1->addItem( 8, 3, 3 );
    matrix1->addItem( 3, 3, 4 );
    matrix1->addItem( 4, 3, 5 );

    matrix1->addItem( 2, 4, 1 );
    matrix1->addItem( 2, 4, 2 );
    matrix1->addItem( 1, 4, 3 );
    matrix1->addItem( 5, 4, 4 );
    matrix1->addItem( 7, 4, 5 );

    matrix1->addItem( 1, 5, 1 );
    matrix1->addItem( 2, 5, 2 );
    matrix1->addItem( 5, 5, 3 );
    matrix1->addItem( 4, 5, 4 );
    matrix1->addItem( 3, 5, 5 );

    /*LinkedList *matrix2= new LinkedList();

    matrix2->addItem(1, 1, 1);
    matrix2->addItem(0, 1, 2);
    matrix2->addItem(0, 1, 3);
    matrix2->addItem(0, 1, 4);
    matrix2->addItem(0, 1, 5);

    matrix2->addItem(0, 2, 1);
    matrix2->addItem(1, 2, 2);
    matrix2->addItem(0, 2, 3);
    matrix2->addItem(0, 2, 4);
    matrix2->addItem(0, 2, 5);

    matrix2->addItem(0, 3, 1);
    matrix2->addItem(0, 3, 2);
    matrix2->addItem(1, 3, 3);
    matrix2->addItem(0, 3, 4);
    matrix2->addItem(0, 3, 5);

    matrix2->addItem(0, 4, 1);
    matrix2->addItem(0, 4, 2);
    matrix2->addItem(0, 4, 3);
    matrix2->addItem(1, 4, 4);
    matrix2->addItem(0, 4, 5);

    matrix1->addItem(0, 5, 1);
    matrix1->addItem(0, 5, 2);
    matrix1->addItem(0, 5, 3);
    matrix1->addItem(0, 5, 4);
    matrix1->addItem(1, 5, 5);*/

    matrix1->printList();

    return 0;
}