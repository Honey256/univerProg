#include <iostream>
#include <string.h>


class LinkedList{

public:
    struct Node{
    	int value;
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

    ~LinkedList(){
    }

    void addItem( int value, int line, int column ){
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

};

int main(){

    LinkedList *l = new LinkedList();
    
   

    l->addItem(11, 1, 1);
    l->addItem(12, 1, 2);
    l->addItem(13, 1, 3);
    l->addItem(14, 1, 4);

    l->addItem(21, 2, 1);
    l->addItem(22, 2, 2);
    l->addItem(23, 2, 3);
    l->addItem(24, 2, 4);

    l->addItem(31, 3, 1);
    l->addItem(32, 3, 2);
    l->addItem(33, 3, 3);
    l->addItem(34, 3, 4);

    l->addItem(41, 4, 1);
    l->addItem(42, 4, 2);
    l->addItem(43, 4, 3);
    l->addItem(44, 4, 4);

 	l->addItem(51, 5, 1);
    l->addItem(52, 5, 2);
    l->addItem(53, 5, 3);
    l->addItem(54, 5, 4);
    
    l->printList();
    return 0;
}
