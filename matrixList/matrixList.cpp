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

    LinkedList(const LinkedList& matrix){
        
        int row = 1;
        int column = 1;

        Node *tmpHead = matrix.head;

        Node *tmpPtr = NULL;

        while (tmpHead){

            tmpPtr = tmpHead;
            while(tmpPtr){

                addItem(tmpPtr->value, row, column);

                tmpPtr = tmpPtr->next;
                column++;              
            }

            tmpHead = tmpHead->down;
            row++;
            column = 1;

        }
    }

    ~LinkedList(){
    }

    void addItem( float value, int line, int column ){
		Node *newItem = new Node();
        newItem->value = value;
        Node *tmpHead = head;
        Node *tmpPtr = NULL;
        if (line == 1 && column == 1){
        	head = newItem;
        	newItem->next = NULL;
        	newItem->prev = NULL;
        	newItem->up = NULL;
        	newItem->down = NULL;


        }
        if (line == 1 && column > 1){
      		while( tmpHead->next ){
            	tmpHead = tmpHead->next;
        	}
        	tmpHead->next = newItem;
        	newItem->prev = tmpHead;
        	newItem->up = NULL;
        	newItem->down = NULL;
        	newItem->next = NULL;
        }
        if (line > 1 && column == 1){
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
        if (line > 1 && column > 1){
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

    void removeRow( int row ){

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

    void removeColumn( int column ){

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

    void printList(){

        Node *tmpNode = head;
        Node *tmpHead = NULL;
        while (tmpNode){
        	tmpHead = tmpNode;

        	while( tmpHead ){
            std::cout << tmpHead->value << " ";
            tmpHead = tmpHead->next;        
        	}

        	std::cout << std::endl;
        	tmpNode = tmpNode->down;

        }
    }

    float mDet( LinkedList matrix){

        LinkedList *tmpMatrix = new LinkedList( matrix );

        float tmpCoef;
        Node *tmpHead = tmpMatrix->head;
        Node *tmpLine = NULL;
        Node *tmpPtr = NULL;
        Node *tmpRow = NULL;

        while( tmpHead->next ){

            tmpLine = tmpHead->down;
       
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

            tmpHead = tmpHead->next->down;
        }

        float tmpDet = 1;
        tmpHead = tmpMatrix->head;

        while ( tmpHead->next ){

            tmpDet *= tmpHead->value;
            tmpHead = tmpHead->down->next;

        }

        tmpDet *= tmpHead->value;
        return tmpDet;
    }

    float addition(LinkedList matrix, int row, int column){

        LinkedList *mad = new LinkedList(matrix);

        mad->removeRow(row);
        mad->removeColumn(column);
        float tmpDet = mDet(*mad);

        if ((row + column) % 2 != 0){
            tmpDet *= -1;
        }
        return tmpDet;
    }

    void mSum(LinkedList matrix1, LinkedList matrix2){
       // std::cout << matrix1.head->value;

        Node *tmpFirstHead = matrix1.head;
        Node *tmpSecondHead = matrix2.head;
        Node *tmpFirst = NULL;
        Node *tmpSecond= NULL;

        int row = 1;
        int column = 1;
        int tmpValue = 0;

        while (tmpFirstHead){

            tmpFirst = tmpFirstHead;
            tmpSecond = tmpSecondHead;

            while(tmpFirst){

                tmpValue = tmpFirst->value + tmpSecond->value;

                addItem(tmpValue, row, column);

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

    void mMult(LinkedList matrix1, LinkedList matrix2){

        Node *tmpFirstHead = NULL;
        Node *tmpSecondHead = NULL;

        Node *tmpFirst = matrix1.head;
        Node *tmpSecond = matrix2.head;

        float tmpValue = 0.0;
        int row = 1;
        int column = 1;
        while(tmpFirst){
            while(tmpSecond){

                tmpFirstHead = tmpFirst;
                tmpSecondHead = tmpSecond;
                while(tmpSecondHead && tmpFirstHead){
                    tmpValue += tmpFirstHead->value * tmpSecondHead->value;
                    tmpFirstHead = tmpFirstHead->next;
                    tmpSecondHead = tmpSecondHead->down;
                }
                addItem(tmpValue, row, column);
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

    void transposition(){
        //LinkedList * trMatrix = new LinkedList();

        Node *tmpNode = NULL;
        Node *tmpHead = head;

        int row = 1;
        int column = 1;
        while (tmpHead){
            tmpNode = tmpHead;
            while( tmpNode ){
                float tmpValue = tmpNode->value;
                addItem(tmpValue, row, column);
                tmpNode = tmpNode->down;
                column++;
                
            }
            tmpHead = tmpHead->next;
            row++;
            
            column = 1;
        }
    }

    void mRev(LinkedList matrix){
        Node *tmpHead = matrix.head;
        Node *tmpColumn = NULL;
        float mainDet = mDet(matrix);
        int row = 1;
        int column = 1;

        while (tmpHead){
            tmpColumn = tmpHead;

            while(tmpColumn){

                addItem(addition(matrix, row, column), row, column);
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
        while (tmpHead){
            tmpColumn = tmpHead;

            while(tmpColumn){
                tmpColumn->value = tmpColumn->value / mainDet;
                tmpColumn = tmpColumn->next;
            }
            tmpHead = tmpHead->down;
        }

    }

};

int main(){

    LinkedList *matrix1 = new LinkedList();
    
    matrix1->addItem(1, 1, 1);
    matrix1->addItem(2, 1, 2);
    matrix1->addItem(3, 1, 3);
    matrix1->addItem(4, 1, 4);
    matrix1->addItem(5, 1, 5);

    matrix1->addItem(1, 2, 1);
    matrix1->addItem(4, 2, 2);
    matrix1->addItem(7, 2, 3);
    matrix1->addItem(8, 2, 4);
    matrix1->addItem(7, 2, 5);

    matrix1->addItem(2, 3, 1);
    matrix1->addItem(2, 3, 2);
    matrix1->addItem(8, 3, 3);
    matrix1->addItem(3, 3, 4);
    matrix1->addItem(4, 3, 5);

    matrix1->addItem(2, 4, 1);
    matrix1->addItem(2, 4, 2);
    matrix1->addItem(1, 4, 3);
    matrix1->addItem(5, 4, 4);
    matrix1->addItem(7, 4, 5);

    matrix1->addItem(1, 5, 1);
    matrix1->addItem(2, 5, 2);
    matrix1->addItem(5, 5, 3);
    matrix1->addItem(4, 5, 4);
    matrix1->addItem(3, 5, 5);

    LinkedList *matrix2= new LinkedList();

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

    LinkedList *l = new LinkedList();
    
    l->mRev(*matrix1);
    LinkedList *m = new LinkedList();
    m->mMult(*matrix1, *l);

    m->printList();

    return 0;
}
