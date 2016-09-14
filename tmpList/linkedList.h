class LinkedList{

 public:
    struct Node{
        Node *next;
        Student value;
    };

 private:
    Node *head;

 public:

    LinkedList();

    ~LinkedList();
    
    void addItem(Student value);
    
    void printList();
    
    void removeItem(Student stud);
    
    Student* getItem(int position);
    
    void insertItem(Student stud, int count);
    
    int findItem(Student &stud);
};

#include "linkedList.cpp"