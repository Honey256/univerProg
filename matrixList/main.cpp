#include "matrix.h"


int main(){

    MatrixList matrix1;

    matrix1.addRow("1;2;3;4;5");

    matrix1.addRow("1;4;8;7;7");

    matrix1.addRow("2;2;8;3;4");

    matrix1.addRow("2;2;1;5;7");

    matrix1.addRow("1;2;5;4;3");

    matrix1.printList();

    std::cout << std::endl;




    MatrixList matrix2;

    matrix2.addColumn("1;1;2;2;1");

    matrix2.addColumn("2;4;2;2;2");

    matrix2.addColumn("3;8;8;1;5");

    matrix2.addColumn("4;7;3;5;4");

    matrix2.addColumn("5;7;4;7;3");  

    matrix2.printList();

    std::cout << std::endl;



    MatrixList matrix3;
    
    matrix3.addItem( 1, 1, 1 );
    matrix3.addItem( 2, 1, 2 );
    matrix3.addItem( 3, 1, 3 );
    matrix3.addItem( 4, 1, 4 );
    matrix3.addItem( 5, 1, 5 );

    matrix3.addItem( 1, 2, 1 );
    matrix3.addItem( 4, 2, 2 );
    matrix3.addItem( 8, 2, 3 );
    matrix3.addItem( 7, 2, 4 );
    matrix3.addItem( 7, 2, 5 );

    matrix3.addItem( 2, 3, 1 );
    matrix3.addItem( 2, 3, 2 );
    matrix3.addItem( 8, 3, 3 );
    matrix3.addItem( 3, 3, 4 );
    matrix3.addItem( 4, 3, 5 );

    matrix3.addItem( 2, 4, 1 );
    matrix3.addItem( 2, 4, 2 );
    matrix3.addItem( 1, 4, 3 );
    matrix3.addItem( 5, 4, 4 );
    matrix3.addItem( 7, 4, 5 );

    matrix3.addItem( 1, 5, 1 );
    matrix3.addItem( 2, 5, 2 );
    matrix3.addItem( 5, 5, 3 );
    matrix3.addItem( 4, 5, 4 );
    matrix3.addItem( 3, 5, 5 );

    matrix3.printList();

    return 0;
}