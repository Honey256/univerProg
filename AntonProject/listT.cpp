#include <iostream>
#include <string.h>
#include <fstream>


class Aeroflot{

public:
    std::string destination;
    int flightNumber;
    std::string planeType;


    int getFlightNumber() const {
        return flightNumber;
    }

    void setFlightNumber( int flightNumber ) {
        this->flightNumber = flightNumber;
    }

    const std::string& getDestination() const {
        return destination;
    }

    void setDestination( const std::string& destination ) {
        this->destination = destination;
    }

    const std::string& getPlaneType() const {
        return planeType;
    }

    void setPlaneType( const std::string& planeType ) {
        this->planeType = planeType;
    }

    void print(){
        std::string space = " ";
        std::cout << destination << space
                  << flightNumber << space
                  << planeType
                  << std::endl;
    }

};

class LinkedList{

public:
    struct Node{
        Node *next;
        Aeroflot value;
    };
private:
    Node *head;

public:

    LinkedList(){
        this->head = NULL;
    }

    ~LinkedList(){

        while ( head ){

            removeItem(0);
        }
        head = NULL;
    }

    void addItem( Aeroflot value ){

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

    void printList(){

        Node *tmpNode = head;
        int count = 0;

        while( tmpNode ){
            std::cout << count << ") ";
            tmpNode->value.print();
            tmpNode = tmpNode->next;
            count++;
        }
    }

    void removeItem( int num ){
        Node *tmpHead = this->head;
        if ( num == 0 ){
            head = head->next;
            delete tmpHead;
            return;
        }

        for ( int i = 1; i < num; i++ ){
            tmpHead = tmpHead->next;
        }
        Node *tmpCurr = tmpHead->next;
        tmpHead->next = tmpCurr->next;
        delete tmpCurr;
    }

    void addRecord(){

        Aeroflot *flight = new Aeroflot();

        std::string destination;
        std::cout << "Enter destination: "; 
        std::cin >> destination;
        flight->setDestination(destination);


        int flightNumber = 0;
        std::cout << "Enter flight number: "; 
        std::cin >> flightNumber;
        flight->setFlightNumber(flightNumber);

        std::string planeType;
        std::cout << "Enter plane type: ";
        std::cin >> planeType;
        flight->setPlaneType(planeType);

        addItem( *flight );
    }

    void addRecord( char *destination, char* flightNumber, char *planeType ){

        Aeroflot *flight = new Aeroflot();

        flight->setDestination( destination );

        int index = 0;
        int temp = 0;

        while ( flightNumber[index] ){
            temp = temp*10 + flightNumber[index] - 48;
            index++;
        }

        flight->setFlightNumber( temp );

        flight->setPlaneType( planeType );

        addItem( *flight );
    }

    void deleteRecord(){
        std::cout << "Enter number of the deleted record: ";
        int num;
        std::cin >> num;
        removeItem( num );
    }

    void enter(){
        int num;
        std::cout<<" enter the number of new records: ";
        std::cin>> num;
        for ( int i = 0; i < num; i++ ){
            addRecord();
        }
    }

    void inFile(){
        std::ofstream out;
        out.open("AEROFLOT1.txt", std::ios::out);
        Node *tmpHead = head;
        // запись в файл
        while( tmpHead ){
            out << tmpHead->value.getDestination() << " " 
                << tmpHead->value.getFlightNumber() << " " 
                << tmpHead->value.getPlaneType() << std::endl;
            tmpHead = tmpHead->next;
        }

        out.close(); 
    }

    int getWordsArray( char *st, char *arrayWords[] ){
        int i = 0, j = 0;

        while( st[i] ) {
            int k = 0;

            while( st[i] == ' ' || st[i] == '\n' )
                    i++;

            while( st[i] != ' ' && st[i] != '\n' && st[i] ) {
                    arrayWords[j][k] = st[i];
                    k++;
                    i++;
            }
            arrayWords[j][k] = '\0';
            j++;
        }
        return j;
    }

    void fromFile(){

        while ( head ){
            removeItem(0);
        }
        head = NULL;

        std::ifstream in ( "AEROFLOT2.txt", std::ifstream::in );
        in.seekg ( -1,in.end );
        long size = in.tellg();
        size = size + 2;
        in.seekg ( 0, in.beg );

        char *array = new char[size];
        in.read( array, size );
        char **arrayWords = new char*[size];

        for ( int j = 0; j < size; j++ ){
            arrayWords[j] = new char[30];
        }
        int rows = getWordsArray( array, arrayWords );

        for ( int i = 0; i < rows; i += 3 ){
            addRecord( arrayWords[i], arrayWords[i+1], arrayWords[i+2] );
            
        }
        in.close();
    }

    void findRecords(){

        std::string plane;
        std::cout << "Enter plane type: "; 
        std::cin >> plane;
        Node *tmpHead = head;

        while ( tmpHead && tmpHead->value.planeType != plane ){
            tmpHead = tmpHead->next;
        }
        if ( tmpHead->value.planeType == plane ){
            tmpHead->value.print();
            std::cout << std::endl;
        }
    }

    void swap( Node *first ){

        Node *tmpHead = head;

        if ( first == head ){
            head = tmpHead->next;
            tmpHead->next = head->next;
            head->next = tmpHead;
            return;
        }

        while ( tmpHead->next && tmpHead->next != first ){
            tmpHead = tmpHead->next;
        }

        tmpHead->next = first->next;
        first->next = first->next->next;
        tmpHead->next->next = first;

        return;
    }

    void mySort(){
        std::string sort;
        std::cout << "Enter a sort field:(flightNumber/planeType/destination) ";
        std::cin >> sort;
        Node *tmpHead = head;
        int num = 0;

        while( tmpHead->next ){
            tmpHead = tmpHead->next;
            num++;
        }

        tmpHead = head;
        Node *tmpNode = head;

        if ( sort == "destination" ){

            for( int i = 0; i < num; i++ ){

                while ( tmpHead->next && tmpNode->next ){

                    if ( strcmp( ( tmpHead->value.destination ).c_str(), ( tmpHead->next->value.destination ).c_str() ) > 0 ){
                        swap(tmpHead);
                    }

                    if ( tmpHead->next && tmpHead == tmpNode ){
                        tmpHead = tmpHead->next;

                    } else if( tmpHead->next && tmpNode->next && tmpNode->next == tmpHead ){
                        tmpHead = tmpHead->next;
                        tmpNode = tmpNode->next;

                    } else if ( tmpHead->next && tmpNode->next && tmpNode->next != tmpHead && tmpHead != tmpNode ){
                        tmpNode = tmpNode->next;
                    }
                }
                tmpHead = head;
                tmpNode = head;
            }

        } else if ( sort == "flightNumber" ){

            for( int i = 0; i < num; i++ ){

                while ( tmpHead->next && tmpNode->next ){

                    if ( tmpHead->value.flightNumber > tmpHead->next->value.flightNumber ){
                        swap(tmpHead);
                    }

                    if ( tmpHead->next && tmpHead == tmpNode ){
                        tmpHead = tmpHead->next;

                    } else if( tmpHead->next && tmpNode->next && tmpNode->next == tmpHead ){
                        tmpHead = tmpHead->next;
                        tmpNode = tmpNode->next;

                    } else if ( tmpHead->next && tmpNode->next && tmpNode->next != tmpHead && tmpHead != tmpNode ){
                        tmpNode = tmpNode->next;
                    }
                }
                tmpHead = head;
                tmpNode = head;
            }

        } else if ( sort == "planeType" ){

            for( int i = 0; i < num; i++ ){

                while ( tmpHead->next && tmpNode->next ){

                    if ( strcmp( ( tmpHead->value.planeType ).c_str(), ( tmpHead->next->value.planeType ).c_str() ) > 0 ){
                        swap(tmpHead);
                    }

                    if ( tmpHead->next && tmpHead == tmpNode ){
                        tmpHead = tmpHead->next;

                    } else if( tmpHead->next && tmpNode->next && tmpNode->next == tmpHead ){
                        tmpHead = tmpHead->next;
                        tmpNode = tmpNode->next;

                    } else if ( tmpHead->next && tmpNode->next && tmpNode->next != tmpHead && tmpHead != tmpNode ){
                        tmpNode = tmpNode->next;
                    }
                }
                tmpHead = head;
                tmpNode = head;
            }

        } else{
            std::cout << "invalid value";
        }
    }
};


int menuTitle(){
    int c;
    std::cout << "1. Input of new records"<< std::endl;

    std::cout << "2. viewing of the list"<< std::endl;

    std::cout << "3. Remove record from the list"<< std::endl;

    std::cout << "4. Add record in the list"<< std::endl;

    std::cout << "5. Save in the file"<< std::endl;

    std::cout << "6. load from the file"<< std::endl;

    std::cout << "7. Search record"<< std::endl;
    
    std::cout << "8. Sort"<< std::endl;

    std::cout << "9. Exit"<< std::endl;

  do {
    std::cout << ( "Enter number: ");
    std::cin >> c;
  } while(c < 1 || c > 9);
  return c;
}

void menu(LinkedList *list){

    while( 1 ) {

        int choice = menuTitle();

        switch( choice ) {

        case 1: 
            list->enter();
            break;

        case 2: 
            list->printList();     
            break;

        case 3:
            list->deleteRecord();
            break;

        case 4: 
            list->addRecord(); 
            break;

        case 5: 
            list->inFile();
            break;

        case 6: 
            list->fromFile(); 
            break;

        case 7: 
            list->findRecords();  
            break;

        case 8:
            list->mySort();
            break;

        case 9:
            delete list;
            return;
            break;
        }
    std::cout << std::endl;
  }
  return;
}

int main(){


    LinkedList *list = new LinkedList();
    menu(list);
    return 0;
}