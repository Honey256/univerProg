#include <iostream>
#include <string.h>

static const std::string unknown = "unknown";

class Student{

private:
    std::string name;
    std::string lastName;
    int age;
    int dept;
    std::string major;

public:
    bool operator==( const Student& rhs ){
        return (*this).getName() == rhs.getName()
            && (*this).getLastName() == rhs.getLastName()
            && (*this).getAge() == rhs.getAge()
            && (*this).getDept() == rhs.getDept()
            && (*this).getMajor() == rhs.getMajor();
    }

    bool operator!=( const Student& rhs ){
        return !((*this) == rhs);
    }

    Student(){
        name = unknown;
        lastName = unknown;
        age = 0;
        dept = 0;
        major = unknown;
    }

    /*
    Student(const Student& student){
        name = student.getName();
        lastName = student.getLastName();
        age = student.getAge();
        dept = student.getDept();
        major = student.getMajor();
    }
    */
    Student( const std::string& name, const std::string& lastName, int age, int dept, const std::string& major ){
        setName(name);
        setLastName(lastName);
        setAge(age);
        setDept(dept);
        setMajor(major);
    }
    ~Student(){}

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getDept() const {
        return dept;
    }

    void setDept(int dept) {
        this->dept = dept;
    }

    const std::string& getLastName() const {
        return lastName;
    }

    void setLastName(const std::string& lastName) {
        this->lastName = lastName;
    }

    const std::string& getMajor() const {
        return major;
    }

    void setMajor(const std::string& major) {
        this->major = major;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }
    void print(){
        std::string space = " ";
        std::cout << name << space
                  << lastName << space
                  << age << space
                  << dept << space
                  << major
                  << std::endl;
    }



};
class LinkedList{
public:

    struct Node{
        Node *next;
        Student value;
    };
private:
    Node *head;

public:

    LinkedList(){
        this->head = NULL;
    }
    ~LinkedList(){
    }
    void addItem(Student value){
        Node *newItem = new Node();
        newItem->value = value;
        if(head == NULL){
            head = newItem;
            newItem->next = NULL;
            return;
        }

        Node *tmpHead = head;
        Node *prev = NULL;

        while(tmpHead){
            prev = tmpHead;
            tmpHead = tmpHead->next;
        }

        prev->next = newItem;
        newItem->next = NULL;
    }
    void printList(){
        Node *tmpNode = head;
        int count = 0;
        while(tmpNode){
            std::cout << count << ") ";
            tmpNode->value.print();
            tmpNode = tmpNode->next;
            count++;
        }
    }
    void removeItem(Student stud){
        Node * prev = head;
        Node * current = head->next;
        if (head->value == stud){
            head = head->next;
            delete prev;
            return;
        }

        while (current != NULL && current->value != stud){
            prev = current;
            current = current->next;

        }

        prev->next = current->next;
        delete current;
    }
    Student* getItem(int position) {
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

    void insertItem(Student stud, int count){
        Node *insertItem = new Node();
        insertItem->value = stud;

        if (count == 0) {
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
    int findItem(Student &stud){
        Node *tmpHead = head;
        int index = 0;
        while ( tmpHead && stud != tmpHead->value){
            tmpHead = tmpHead->next;
            index++;
        }
        //tmpHead->value.print();
        if ( stud == tmpHead->value){
            return index;
        } else {
            return -1;
        }
    }
};

int main(){
    LinkedList *l = new LinkedList();
    Student *stud0 = new Student("Alex", "Krilov", 18, 2, "CS");
    l->addItem(*stud0);
    Student *stud1 = new Student("iliya", "galkin", 19, 2, "CS");
    l->addItem(*stud1);
    Student *stud2 = new Student("Kate", "Shatankova", 18, 2, "physical science");
    l->addItem(*stud2);
    Student *stud3 = new Student();
    l->addItem(*stud3);
    Student *stud4 = new Student("Anastasia", "Dekanova", 19, 2, "radio physics");
    l->addItem(*stud4);

    std::cout << "first printList: " << std::endl;
    l->printList();
    std::cout << std::endl << "removing 2:" << std::endl;
    l->removeItem(*stud2);
    l->printList();
    std::cout << std::endl;
    Student * s = l->getItem(3);
    if ( s ){
        std::cout << "item 3: ";
        s->print();
    }
    Student *stud6 = new Student("Vasiliy", "Gladishev", 19, 2, "CS");
    l->insertItem(*stud6, 3);
    std::cout << std::endl
              << "after insert ( 3rd position):"
              << std::endl;


    l->printList();
    std::cout << std::endl << "found element number: "<< l->findItem(*(new Student()));

    /*l->addItem(15);
    l->addItem(21);
    l->addItem(3);
    l->addItem(17);
    l->addItem(24);
    l->removeItem(21);
    l->findItem(2);
    l->insertItem(5, 3);
    l->printList();*/
    return 0;
}