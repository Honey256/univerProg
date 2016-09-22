#include <iostream>
#include <string.h>
//#include "student.h"
#include "linkedList.h"




int main(){

    LinkedList *l = new LinkedList();

    Student *stud0 = new Student( "Alex", "Krilov", 18, 2, "CS" );
    l->addItem( *stud0 );

    Student *stud1 = new Student( "iliya", "galkin", 19, 2, "CS" );
    l->addItem( *stud1 );
    
    Student *stud2 = new Student( "Kate", "Shatankova", 18, 2, "physical science" );
    l->addItem( *stud2 );
    
    Student *stud3 = new Student();
    l->addItem( *stud3 );
    
    Student *stud4 = new Student( "Anastasia", "Dekanova", 19, 2, "radio physics" );
    l->addItem( *stud4 );

    std::cout << "first printList: " << std::endl;
    l->printList();
    
    std::cout << std::endl << "removing 2:" << std::endl;
    l->removeItem( *stud2 );
    
    l->printList();
    std::cout << std::endl;

    Student *s = l->getItem( 3 );
    if ( s ){
        std::cout << "item 3: ";
        s->print();
    }

    Student *stud6 = new Student( "Vasiliy", "Gladishev", 19, 2, "CS" );
    l->insertItem( *stud6, 3 );

    std::cout << std::endl
              << "after insert ( 3rd position ):"
              << std::endl;

    l->printList();
    std::cout << std::endl << "found element number: "<< l->findItem( *( new Student() ) ) << std::endl;

    return 0;
}