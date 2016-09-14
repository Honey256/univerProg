
static const std::string unknown = "unknown";

class Student{

private:
    std::string name;
    std::string lastName;
    int age;
    int dept;
    std::string major;

public:

    bool operator==( const Student &rhs );

    bool operator!=( const Student &rhs );

    Student();

    Student( const std::string& name, const std::string& lastName, int age, int dept, const std::string& major );
    
    ~Student();

    int getAge() const {
        return age;
    }

    void setAge( int age ) {
        this->age = age;
    }

    int getDept() const {
        return dept;
    }

    void setDept( int dept ) {
        this->dept = dept;
    }

    const std::string &getLastName() const {
        return lastName;
    }

    void setLastName( const std::string &lastName ) {
        this->lastName = lastName;
    }

    const std::string &getMajor() const {
        return major;
    }

    void setMajor( const std::string &major ) {
        this->major = major;
    }

    const std::string &getName() const {
        return name;
    }

    void setName( const std::string &name ) {
        this->name = name;
    }

    void print();



};

#include "student.cpp"
