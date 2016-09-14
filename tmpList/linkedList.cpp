    LinkedList::LinkedList(){
        this->head = NULL;
    }

    LinkedList::~LinkedList(){
    }

    void LinkedList::addItem( Student value ){

        Node *newItem = new Node();
        newItem->value = value;
        if( head == NULL ){
            head = newItem;
            newItem->next = NULL;
            return;
        }

        Node *tmpHead = head;
        Node *prev = NULL;

        while( tmpHead ){
            prev = tmpHead;
            tmpHead = tmpHead->next;
        }

        prev->next = newItem;
        newItem->next = NULL;
    }

    void LinkedList::printList(){

        Node *tmpNode = head;
        int count = 0;

        while( tmpNode ){
            std::cout << count << ") ";
            tmpNode->value.print();
            tmpNode = tmpNode->next;
            count++;
        }
    }

    void LinkedList::removeItem( Student stud ){

        if ( head == NULL ){
            std::cout << "empty list" << std::endl;
            return;
        }

        Node *prev = head;
        Node *current = head->next;

        if ( head->value == stud ){
            head = head->next;
            delete prev;
            return;
        }

        while ( current != NULL ){
            if ( current->value == stud ){
                 prev->next = current->next;
                 delete current;
                 return;
            } else{
                prev = current;
                current = current->next;
            }
        }
    }

    Student *LinkedList::getItem( int position ) {

        if (head == NULL){
            std::cout << "empty list" << std::endl;
            return NULL;
        }

        Node* tmpHead = head;
        int index = 0;

        while ( tmpHead && index < position ){
            tmpHead = tmpHead->next;
            index++;
        }
        if ( index == position ){
            return &(tmpHead->value);
        } else {
            return NULL;
        }
    }

    void LinkedList::insertItem( Student stud, int count ){

        Node *insertItem = new Node();
        insertItem->value = stud;

        if ( count == 0 ) {
            insertItem -> next = head;
            head = insertItem;
            return;
        }

        Node *tmpHead = head;
        int index = 1;


        while ( tmpHead && index < count ){
            tmpHead = tmpHead->next;
            index++;
        }

        if ( index == count ) {
            insertItem->next = tmpHead->next;
            tmpHead->next = insertItem;
        }

    }

    int LinkedList::findItem( Student &stud ){

        Node *tmpHead = head;
        int index = 0;

        while ( tmpHead && stud != tmpHead->value ){
            tmpHead = tmpHead->next;
            index++;
        }
        //tmpHead->value.print();
        if ( stud == tmpHead->value ){
            return index;
        } else {
            return -1;
        }
    }