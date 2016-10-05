//matrixLibrary

#include "matrix.h"


    MatrixList::MatrixList(){

        this->head = NULL;
    }

    MatrixList::MatrixList( const MatrixList& matrix ){
        
        int row = 1;
        int column = 1;

        Node *tmpHead = matrix.head;

        Node *tmpPtr = NULL;

        while ( tmpHead ){
            tmpPtr = tmpHead;

            while( tmpPtr ){

                addItem( tmpPtr->value, row, column );

                tmpPtr = tmpPtr->next;
                column++;              
            }

            tmpHead = tmpHead->down;
            row++;
            column = 1;

        }
    }

    MatrixList MatrixList::operator=( const MatrixList matrix ){
        
        int row = 1;
        int column = 1;

        Node *tmpHead = matrix.head;

        Node *tmpPtr = NULL;

        while ( tmpHead ){
            tmpPtr = tmpHead;

            while( tmpPtr ){

                addItem( tmpPtr->value, row, column );

                tmpPtr = tmpPtr->next;
                column++;              
            }

            tmpHead = tmpHead->down;
            row++;
            column = 1;
        }
        return *this;
    }

    MatrixList::MatrixList( int row, int column ){

        for ( int i = 1; i <= row; i++ ){

            for ( int j = 1; j <= column; j++ ){

                if ( i == j ){
                    addItem( 1, i, j );

                } else{
                    addItem( 0, i, j );
                }
            }
        }
    }

    void MatrixList::addItem( float value, int line, int column ){

		Node *newItem = new Node();
        newItem->value = value;
        Node *tmpHead = head;
        Node *tmpPtr = NULL;

        if ( line == 1 && column == 1 ){

        	head = newItem;
        	newItem->next = NULL;
        	newItem->prev = NULL;
        	newItem->up = NULL;
        	newItem->down = NULL;


        }

        if ( line == 1 && column > 1 ){

      		while( tmpHead->next ){
            	tmpHead = tmpHead->next;
        	}

        	tmpHead->next = newItem;
        	newItem->prev = tmpHead;
        	newItem->up = NULL;
        	newItem->down = NULL;
        	newItem->next = NULL;
        }

        if ( line > 1 && column == 1 ){

        	for ( int i = 1; i < line; i++ ){
        		tmpPtr = tmpHead;
        		tmpHead = tmpHead->down;
        	}

        	tmpPtr->down = newItem;
        	newItem->up = tmpPtr;
        	newItem->prev = NULL;
        	newItem->next = NULL;
        	newItem->down = NULL;
        }

        if ( line > 1 && column > 1 ){

        	for ( int i = 1; i < column; i++ ){
        		tmpPtr = tmpHead;
        		tmpHead = tmpHead->next;
        	}

        	for ( int i = 1; i < line; i++ ){
        		tmpPtr = tmpHead;
        		tmpHead = tmpHead->down;
       		}

       		tmpPtr->down = newItem;
       		newItem->up = tmpPtr;

       		tmpHead = tmpPtr->prev;
       		tmpHead = tmpHead->down;

       		tmpHead->next = newItem;
       		newItem->prev = tmpHead;
       		newItem->next = NULL;
       		newItem->down = NULL;
       	}
    }

    void MatrixList::changeItem( float value, int row, int column ){

        Node *tmpHead = head;

        for ( int i = 1; i < row; i++ ){
            tmpHead = tmpHead->down;
        }

        for ( int i = 1; i < column; i++ ){
            tmpHead = tmpHead->next;
        }

        tmpHead->value = value;
    }
 
    void MatrixList::insertItemR( float value, int row, int column ){

        Node *newItem = new Node();
        newItem->value = value;
        Node *tmpHead = head;
           


        if( row == 1 && column > 1){
            tmpHead = head->down;
        } else{

            for ( int i = 2; i < row; i++){
                tmpHead = tmpHead->down;
            }
        }

        for ( int j = 1; j < column; j++ ){
            tmpHead = tmpHead->next;
        }


        if ( row == 1 ){
            tmpHead->up = newItem;
            newItem->down = tmpHead;
            newItem->up = NULL;

            if ( column == 1 ){
                head = newItem;
                newItem->prev = NULL;
            }

            if ( column > 1 ){
                newItem->prev = tmpHead->prev->up;
                newItem->prev->next = newItem;
            }
        }

        if ( row > 1 ){
            newItem->up = tmpHead;
            newItem->down = tmpHead->down;

            if( column == 1 ){
                newItem->prev = NULL;
            }
            tmpHead->down = newItem;

            if( newItem->down ){
                newItem->down->up = newItem;            
            }

            if( column > 1 ){
                newItem->prev = newItem->up->prev->down;
                newItem->prev->next = newItem;
            }
        }
        newItem->next = NULL;    
    }

    void MatrixList::insertItemC( float value, int row, int column ){

        Node *newItem = new Node();
        newItem->value = value;
        Node *tmpHead = head;

        if( column == 1 && row > 1){
            tmpHead = head->next;
        } else{

            for ( int i = 2; i < column; i++ ){
                tmpHead = tmpHead->next;
            }
        }

        for ( int j = 1; j < row; j++ ){
            tmpHead = tmpHead->down;
        }

        if ( column == 1 ){
            tmpHead->prev = newItem;
            newItem->next = tmpHead;
            newItem->prev = NULL;

            if ( row == 1 ){
                head = newItem;
                newItem->up = NULL;
            }

            if ( row > 1 ){
                newItem->up = tmpHead->up->prev;
                newItem->up->down = newItem;
            }
        }

        if ( column > 1 ){
            newItem->prev = tmpHead;
            newItem->next = tmpHead->next;

            if( row == 1 ){
                newItem->up = NULL;
            }
            tmpHead->next = newItem;
            if( newItem->next ){
                newItem->next->prev = newItem;            
            }

            if( row > 1 ){
                newItem->up = newItem->prev->up->next;
                newItem->up->down = newItem;
            }
        }
        newItem->down = NULL;     
    }

    void MatrixList::addRow( std::string str ){

        float item = 0;
        int len = str.length();
        int row = 1;
        int column = 1;

        if( head == NULL ){
            
            for ( int i = 0; i <= len; i++ ){

                if ( str[i] > 47 && str[i] < 58 ){

                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        addItem( item, row, column );
                        column++;
                    }
                    
                    
                }

            }
            return;
        }

        int end = len / 2 + 1;
        int index = 1;
        int amt = 0;
        row = 2;
        Node *tmpHead = head;
        std::string newColumn;

        while( tmpHead->next ){
            index++;
            tmpHead = tmpHead->next;
        }

        int lenIndex = index * 2 - 1;
        tmpHead = head;

        while( tmpHead->down ){
            row++;
            newColumn += "0;";
            tmpHead = tmpHead->down;
        }
        newColumn += "0;0";

        if ( len < lenIndex ){
            len = lenIndex;
        }

        for( int i = 0; i <= len; i++ ){

            if ( amt >= index && amt < end ){

                if ( str[i] > 47 && str[i] < 58 ){
                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        addColumn(newColumn);
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        addItem( item, row, column );
                        amt++;
                        column++;
                    }
                }
            }

            if( amt < index && amt >= end ){
                addItem( 0, row, column );
                amt++;
                column++;
                i++;
            }

            if ( amt < index && amt < end ){

                if ( str[i] > 47 && str[i] < 58 ){

                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        addItem( item, row, column );
                        amt++;
                        column++;
                    }
                } 
            }             
        }
    }

    void MatrixList::addRow( std::string str, int row ){

        float item = 0;
        int len = str.length();
        int column = 1;
        int end = len / 2 + 1;
        int index = 1;
        int amt = 0;
        Node *tmpHead = head;
        std::string newColumn;

        while( tmpHead->next ){
            index++;
            tmpHead = tmpHead->next;
        }

        int lenIndex = index * 2 - 1;
        tmpHead = head;

        while( tmpHead->down ){
            newColumn += "0;";
            tmpHead = tmpHead->down;
        }
        newColumn += "0;0";


        if ( len < lenIndex ){
            len = lenIndex;
        }

        for( int i = 0; i <= len; i++ ){

            if ( amt >= index && amt < end ){

                if ( str[i] > 47 && str[i] < 58 ){
                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        addColumn(newColumn);
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        changeItem( item, row, column );
                        amt++;
                        column++;
                    }
                }
            }

            if( amt < index && amt >= end ){
                insertItemR( 0, row, column );
                amt++;
                column++;
                i++;
            }

            if ( amt < index && amt < end ){

                if ( str[i] > 47 && str[i] < 58 ){

                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        insertItemR( item, row, column );
                        amt++;
                        column++;
                    }
                }
            }
        }
    }

    void MatrixList::addColumn( std::string str ){

        float item = 0;
        int len = str.length();
        int row = 1;
        int column = 1;

        if( head == NULL ){
            
            for ( int i = 0; i <= len; i++ ){

                if ( str[i] > 47 && str[i] < 58 ){

                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        addItem( item, row, column );
                        row++;
                    }
                    
                    
                }

            }
            return;
        }

        int end = len / 2 + 1;
        int index = 1;
        int amt = 0;
        column = 2;
        Node *tmpHead = head;
        std::string newRow;

        while( tmpHead->down ){
            index++;
            tmpHead = tmpHead->down;
        }

        int lenIndex = index * 2 - 1;
        tmpHead = head;

        while( tmpHead->next ){
            column++;
            newRow += "0;";
            tmpHead = tmpHead->next;
        }
        newRow += "0;0";

        if ( len < lenIndex ){
            len = lenIndex;
        }

        for( int i = 0; i <= len; i++ ){

            if ( amt >= index && amt < end ){
                    
                if ( str[i] > 47 && str[i] < 58 ){

                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        addRow(newRow);
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        addItem( item, row, column );
                        amt++;
                        row++;
                    }
                }
            }

            if( amt < index && amt >= end ){
                addItem( 0, row, column );
                amt++;
                row++;
                i++;
            }

            if (amt < index && amt < end ){

                if ( str[i] > 47 && str[i] < 58 ){

                    if (str[i-1] > 47 && str[i-1] < 58){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        addItem( item, row, column );
                        amt++;
                        row++;
                    }
                }      
            } 
        }
    }

    void MatrixList::addColumn( std::string str, int column ){

        float item = 0;
        int len = str.length();
        int row = 1;
        int end = len / 2 + 1;
        int index = 1;
        int amt = 0;
        Node *tmpHead = head;
        std::string newRow;

        while( tmpHead->down ){
            index++;
            tmpHead = tmpHead->down;
        }

        int lenIndex = index * 2 - 1;
        tmpHead = head;

        while( tmpHead->next ){
            newRow += "0;";
            tmpHead = tmpHead->next;
        }
        newRow += "0;0";

        if ( len < lenIndex ){
            len = lenIndex;
        }

        for( int i = 0; i <= len; i++ ){

            if ( amt >= index && amt < end ){
                    
                if ( str[i] > 47 && str[i] < 58 ){

                    if ( str[i-1] > 47 && str[i-1] < 58 ){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        addRow(newRow);
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        changeItem( item, row, column );
                        amt++;
                        row++;
                    }
                }
            }

            if( amt < index && amt >= end ){
                insertItemC( 0, row, column );
                amt++;
                row++;
                i++;
            }

            if (amt < index && amt < end ){

                if ( str[i] > 47 && str[i] < 58 ){

                    if (str[i-1] > 47 && str[i-1] < 58){
                        item = item * 10 + str[i] - 48;
                    }

                    if ( str[i-1] < 48 || str[i-1] > 57 ){
                        item = str[i] - 48;
                    }

                    if ( str[i+1] < 48 || str[i+1] > 57 ){
                        insertItemC( item, row, column );
                        amt++;
                        row++;
                    }
                }      
            } 
        }
    }

    void MatrixList::removeRow( int row ){

    	Node *tmpHead = head;
    	Node *tmpPtr = NULL;

    	if ( row == 1 ){
    		head = head->down;

    		while ( tmpHead ){

    			tmpPtr = tmpHead->down;
    			tmpPtr->up = NULL;
    			tmpPtr = tmpHead;
    			tmpHead = tmpHead->next;

    			delete tmpPtr;
    			tmpPtr = NULL;
    		}
    		return;
    	}

    	int index = 1;
    	while ( tmpHead->down ){

    		tmpPtr = tmpHead;
    		tmpHead = tmpHead->down;
    		index++;
    	}

 
    	if ( row == index ){

    		tmpHead = tmpPtr;
    		tmpPtr = NULL;

    		while( tmpHead ){

    			tmpPtr = tmpHead->down;
    			delete tmpPtr;
    			tmpPtr = NULL;
    			tmpHead->down = NULL;
    			tmpHead = tmpHead->next;
    		}
    	}

    	tmpHead = head;
    	tmpPtr = NULL;

		if ( row > 1 && row < index ){

			for ( int i = 1; i < row; i++ ){
				tmpPtr = tmpHead;
				tmpHead = tmpHead->down;
			}

			tmpHead = tmpHead->down;

			while ( tmpPtr && tmpHead ){

				tmpPtr->down = tmpHead;
				delete tmpHead->up;
				tmpHead->up = tmpPtr;
				tmpHead = tmpHead->next;
				tmpPtr = tmpPtr->next;
			}
		}
    }

    void MatrixList::removeColumn( int column ){

        Node *tmpHead = head;
        Node *tmpPtr = NULL;

        if ( column == 1 ){
            head = head->next;

            while ( tmpHead ){

                tmpPtr = tmpHead->next;
                tmpPtr->prev = NULL;
                tmpPtr = tmpHead;
                tmpHead = tmpHead->down;

                delete tmpPtr;
                tmpPtr = NULL;
            }
            return;
        }

        int index = 1;
        while ( tmpHead->next ){

            tmpPtr = tmpHead;
            tmpHead = tmpHead->next;
            index++;
        }

 
        if ( column == index ){

            tmpHead = tmpPtr;
            tmpPtr = NULL;

            while( tmpHead ){

                tmpPtr = tmpHead->next;
                delete tmpPtr;
                tmpPtr = NULL;
                tmpHead->next = NULL;
                tmpHead = tmpHead->down;
            }
        }

        tmpHead = head;
        tmpPtr = NULL;

        if ( column > 1 && column < index ){

            for ( int i = 1; i < column; i++ ){
                tmpPtr = tmpHead;
                tmpHead = tmpHead->next;
            }

            tmpHead = tmpHead->next;

            while ( tmpPtr && tmpHead ){

                tmpPtr->next = tmpHead;
                delete tmpHead->prev;
                tmpHead->prev = tmpPtr;
                tmpHead = tmpHead->down;
                tmpPtr = tmpPtr->down;
            }
        }
    }

    void MatrixList::printList(){

        Node *tmpNode = head;
        Node *tmpHead = NULL;
        while ( tmpNode ){
        	tmpHead = tmpNode;

        	while( tmpHead ){
            std::cout << tmpHead->value << " ";
            tmpHead = tmpHead->next;        
        	}

        	std::cout << std::endl;
        	tmpNode = tmpNode->down;

        }
    }

    bool MatrixList::sqrValid( MatrixList *matrix ){

        Node *tmpHead = matrix->head;
        int row = 0;
        int column = 0;

        while( tmpHead->down ){
            row++;
            tmpHead = tmpHead->down;
        }

        while( tmpHead->next ){
            column++;
            tmpHead = tmpHead->next;
        }

        if ( row == column ){
            return 1;
        } else{
            return 0;
        }   
    }

    bool MatrixList::multValid( MatrixList *matrix1, MatrixList *matrix2 ){

        Node *tmpFirst = matrix1->head;
        Node *tmpSecond = matrix2->head;

        int column = 0;
        int row = 0;

        while( tmpFirst ){
            column++;
            tmpFirst = tmpFirst->next;
        }

        while( tmpSecond ){
            row++;
            tmpSecond = tmpSecond->down;    
        }

        if ( row == column ){
            return 1;
        }else{
            return 0;
        }
    }

    bool MatrixList::sumValid( MatrixList *matrix1, MatrixList *matrix2 ){

        Node *tmpFirst = matrix1->head;
        Node *tmpSecond = matrix2->head;

        int columnFirst = 0;
        int rowFirst = 0;
        int columnSecond = 0;
        int rowSecond = 0;

        while( tmpFirst ){
            columnFirst++;
            tmpFirst = tmpFirst->next;
        }

        while( tmpSecond ){
            columnSecond++;
            tmpSecond = tmpSecond->next;    
        }

        tmpFirst = matrix1->head;
        tmpSecond = matrix2->head;

        while( tmpFirst ){
            rowFirst++;
            tmpFirst = tmpFirst->down;
        }

        while( tmpSecond ){
            rowSecond++;
            tmpSecond = tmpSecond->down;    
        }

        if ( columnFirst == columnSecond && rowFirst == rowSecond ){
            return 1;
        }else{
            return 0;
        }
    }

    void MatrixList::swap( Node *first, Node *second ){

        Node *tmpFirst = first;
        Node *tmpSecond = second;
        Node *tmpPtr = NULL;

        if ( tmpFirst == NULL || tmpSecond == NULL ){return;}



        while ( tmpFirst->prev ){
            tmpFirst = tmpFirst->prev;
        }

        while ( tmpSecond->prev ){
            tmpSecond = tmpSecond->prev;
        }

        if( tmpSecond->up == NULL ){
            head = tmpFirst;
        }

        if ( tmpFirst->up == tmpSecond ){

            while( tmpFirst ){
                tmpPtr = tmpFirst->up;
                tmpFirst->up = tmpSecond->up;
                tmpSecond->up = tmpSecond->down;
                tmpSecond->down = tmpFirst->down;
                tmpFirst->down = tmpPtr;

                if( tmpFirst->up != NULL ){
                    tmpFirst->up->down = tmpFirst;
                }

                if( tmpSecond->down != NULL ){
                   tmpSecond->down->up = tmpSecond;
                }

                tmpFirst = tmpFirst->next;
                tmpSecond = tmpSecond->next;
            }
            return;
        }

        while(tmpFirst){
            tmpPtr = tmpSecond->down;
            tmpSecond->down = tmpFirst->down;
            tmpFirst->down = tmpPtr;

            tmpPtr = tmpFirst->up;
            tmpFirst->up = tmpSecond->up;
            tmpSecond->up = tmpPtr;

            tmpFirst->down->up = tmpFirst;
            tmpSecond->up->down = tmpSecond;

            if(tmpFirst->up != NULL){
                tmpFirst->up->down = tmpFirst;
            }

            if(tmpSecond->down != NULL){
                tmpSecond->down->up = tmpSecond;
            }

            tmpFirst = tmpFirst->next;
            tmpSecond = tmpSecond->next;

        }
    }

    float MatrixList::determinant( MatrixList matrix ){

        if ( sqrValid( &matrix ) == 0 ){return 0;}

        MatrixList *tmpMatrix = new MatrixList( matrix );
        
        int sign = 1;
        float tmpCoef;
        Node *tmpHead = tmpMatrix->head;
        Node *tmpLine = NULL;
        Node *tmpPtr = NULL;
        Node *tmpRow = NULL;
        Node *temp = NULL;

        while( tmpHead->next ){

            tmpLine = tmpHead->down;

            if( tmpHead->value == 0 && tmpHead->down ){

                if ( tmpLine->value == 0 ){

                    if( tmpLine->down ){
                        tmpLine = tmpLine->down;
                    } else {
                        return 0;
                    }
                }
                swap( tmpLine, tmpHead );
                tmpHead = temp->next->down;
                tmpLine = tmpHead->down;
                //tmpMatrix->printList();
                sign *= -1;
            }
       
            while( tmpLine->down ){

                tmpCoef = tmpLine->value / tmpHead->value;
                tmpPtr = tmpHead;
                tmpRow = tmpLine;

                while ( tmpRow ){

                    tmpRow->value = tmpRow->value - ( tmpPtr->value * tmpCoef );
                    tmpPtr = tmpPtr->next;
                    tmpRow = tmpRow->next;
                }

                tmpLine = tmpLine->down;
            }

            tmpCoef = tmpLine->value / tmpHead->value;
            tmpPtr = tmpHead;
            tmpRow = tmpLine;

            while ( tmpRow ){

                tmpRow->value = tmpRow->value - ( tmpPtr->value * tmpCoef );
                tmpPtr = tmpPtr->next;
                tmpRow = tmpRow->next;
            }
            temp = tmpHead;
            tmpHead = tmpHead->next->down;
        }

        float tmpDet = 1;
        tmpHead = tmpMatrix->head;

        while ( tmpHead->next ){
            tmpDet *= tmpHead->value;
            tmpHead = tmpHead->down->next;

        }

        tmpDet *= tmpHead->value;

        if ( tmpDet != 0 ){
            tmpDet *= sign;
        }
        
        return tmpDet;
    }

    float MatrixList::addition( MatrixList matrix, int row, int column ){


        if ( sqrValid( &matrix ) == 0 ){return 0;}

        MatrixList *mad = new MatrixList(matrix);

        mad->removeRow( row );
        mad->removeColumn( column );
        float tmpDet = determinant( *mad );

        if ( ( row + column ) % 2 != 0 ){
            tmpDet *= -1;
        }
        return tmpDet;
    }

    MatrixList MatrixList::operator+( MatrixList matrix2 ) const {


        Node *tmpFirstHead = head;
        Node *tmpSecondHead = matrix2.head;
        MatrixList *newMatrix = new MatrixList();
        Node *tmpFirst = NULL;
        Node *tmpSecond= NULL;

        int row = 1;
        int column = 1;
        int tmpValue = 0;

        while ( tmpFirstHead ){

             tmpFirst = tmpFirstHead;
             tmpSecond = tmpSecondHead;

             while( tmpFirst ){

                 tmpValue = tmpFirst->value + tmpSecond->value;

                 newMatrix->addItem( tmpValue, row, column );

                 tmpFirst = tmpFirst->next;
                 tmpSecond = tmpSecond->next;
                 column++;              
            }

            tmpFirstHead = tmpFirstHead->down;
            tmpSecondHead = tmpSecondHead->down;
            row++;
            column = 1;

        }
        return *newMatrix;
    }

    MatrixList MatrixList::operator*( MatrixList matrix2 ) const{

        Node *tmpFirstHead = NULL;
        Node *tmpSecondHead = NULL;

        Node *tmpFirst = head;
        Node *tmpSecond = matrix2.head;

        MatrixList *newMatrix = new MatrixList();


        float tmpValue = 0;
        int row = 1;
        int column = 1;

        while( tmpFirst ){

            while( tmpSecond ){

                tmpFirstHead = tmpFirst;
                tmpSecondHead = tmpSecond;

                while( tmpSecondHead && tmpFirstHead ){
                    tmpValue += tmpFirstHead->value * tmpSecondHead->value;
                    tmpFirstHead = tmpFirstHead->next;
                    tmpSecondHead = tmpSecondHead->down;
                }

                if ( tmpValue > 0.99 && tmpValue < 1 ){
                    tmpValue = 1;
                }

                if ( tmpValue > -0.001 && tmpValue < 0.001 ) {
                    tmpValue = 0;
                }

                newMatrix->addItem( tmpValue, row, column );
                tmpValue = 0;


                tmpSecond = tmpSecond->next;
                column++;


            }
            tmpSecond = matrix2.head;
            tmpFirst = tmpFirst->down;
            row++; 
            column = 1;
        }
        return *newMatrix;
    }  

    void MatrixList::matrixSum( MatrixList matrix1, MatrixList matrix2 ){

        if ( sumValid ( &matrix1, &matrix2 ) == 0){
            std::cerr << "invalid matrix";
            return;
        }

        Node *tmpFirstHead = matrix1.head;
        Node *tmpSecondHead = matrix2.head;
        Node *tmpFirst = NULL;
        Node *tmpSecond= NULL;

        int row = 1;
        int column = 1;
        int tmpValue = 0;

        while ( tmpFirstHead ){

            tmpFirst = tmpFirstHead;
            tmpSecond = tmpSecondHead;

            while( tmpFirst ){

                tmpValue = tmpFirst->value + tmpSecond->value;

                addItem( tmpValue, row, column );

                tmpFirst = tmpFirst->next;
                tmpSecond = tmpSecond->next;
                column++;              
            }

            tmpFirstHead = tmpFirstHead->down;
            tmpSecondHead = tmpSecondHead->down;
            row++;
            column = 1;

        }
    }

    void MatrixList::matrixMult( MatrixList matrix1, MatrixList matrix2 ){

        if ( multValid( &matrix1, &matrix2 ) == 0 ){
            std::cerr << "invalid matrix";
            return;
        }

        Node *tmpFirstHead = NULL;
        Node *tmpSecondHead = NULL;

        Node *tmpFirst = matrix1.head;
        Node *tmpSecond = matrix2.head;

        float tmpValue = 0;
        int row = 1;
        int column = 1;

        while( tmpFirst ){

            while( tmpSecond ){

                tmpFirstHead = tmpFirst;
                tmpSecondHead = tmpSecond;

                while( tmpSecondHead && tmpFirstHead ){
                    tmpValue += tmpFirstHead->value * tmpSecondHead->value;
                    tmpFirstHead = tmpFirstHead->next;
                    tmpSecondHead = tmpSecondHead->down;
                }

                if ( tmpValue > 0.99 && tmpValue < 1 ){
                    tmpValue = 1;
                }

                if ( tmpValue > -0.001 && tmpValue < 0.001 ) {
                    tmpValue = 0;
                }

                addItem( tmpValue, row, column );
                tmpValue = 0;


                tmpSecond = tmpSecond->next;
                column++;


            }
            tmpSecond = matrix2.head;
            tmpFirst = tmpFirst->down;
            row++; 
            column = 1;
            

        }
    }  

    void MatrixList::transposition(){
        //MatrixList * trMatrix = new MatrixList();

        Node *tmpNode = NULL;
        Node *tmpHead = head;

        int row = 1;
        int column = 1;

        while ( tmpHead ){
            tmpNode = tmpHead;

            while( tmpNode ){
                float tmpValue = tmpNode->value;
                addItem( tmpValue, row, column );
                tmpNode = tmpNode->down;
                column++;
                
            }
            tmpHead = tmpHead->next;
            row++;
            
            column = 1;
        }
    }

    void MatrixList::matrixRev( MatrixList matrix ){

        if ( sqrValid( &matrix ) == 0 ){
            std::cerr << "invalude matrix";
            return;
        }


        Node *tmpHead = matrix.head;
        Node *tmpColumn = NULL;
        float mainDet = determinant(matrix);
        int row = 1;
        int column = 1;

        while ( tmpHead ){
            tmpColumn = tmpHead;

            while( tmpColumn ){

                addItem( addition( matrix, row, column ), row, column );
                column++;
                tmpColumn = tmpColumn->next;
            }

            row++;
            column = 1;
            tmpHead = tmpHead->down;
        }
        transposition();
        tmpHead = head;
        tmpColumn = NULL;

        while ( tmpHead ){
            tmpColumn = tmpHead;

            while( tmpColumn ){
                tmpColumn->value = tmpColumn->value / mainDet;
                tmpColumn = tmpColumn->next;
            }
            tmpHead = tmpHead->down;
        }
    }

    float MatrixList::get( int row, int column ){

        Node *tmpHead = head;

        for ( int i = 1; i < row; i++ ){
            tmpHead = tmpHead->down;
        }

        for ( int j = 1; j < column; j++ ){
            tmpHead = tmpHead->next;
        }
        return tmpHead->value;
    }

    void MatrixList::find( float value ){

        Node *tmpHead = head;
        Node *tmpNode = head;
        float delta = 0.0001;
        int row = 1;
        int column = 1;

        while ( tmpHead ){
            tmpNode = tmpHead;

            while ( tmpNode ){

                if ( ( value - tmpNode->value ) < delta && ( value - tmpNode->value > -delta ) ){
                    std::cout << " ( "<< row << " | " << column << " ) " << std::endl;
                }
                column++;
                tmpNode = tmpNode -> next;
            }
            column = 1;
            row++;
            tmpHead = tmpHead->down;
        }
    }

    int MatrixList::rank(){

        int row = 1;
        int column = 1;
        int size = 0;
        float det;
        Node *tmpHead = head;

        while ( tmpHead->next ){
            column++;
            tmpHead = tmpHead->next;
        }
        
        while ( tmpHead->down ){
            row++;
            tmpHead = tmpHead->down;
        }


        MatrixList *newMatrix = new MatrixList(*this);

        size = row;

        if ( row > column ){

            for ( int i = column + 1; i <= row; i++ ){
                removeRow( i );
            }
            size = column;
            row = size;
        }

        if ( row < column ){

            for ( int i = row + 1; i <= column; i++ ){
                removeColumn(i);
            }
            size = row;
            column = size;
        }

        while( det == 0 && size > 0 ){
            det = determinant( *newMatrix );

            if ( det > 0 ){
                return size;
            }

            removeColumn( size );
            removeRow( size );
            size--;
        }
        return size;
    }