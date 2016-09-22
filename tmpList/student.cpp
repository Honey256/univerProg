
#include "student.h"

    const std::string unknown = "unknown";

    bool Student::operator==( const Student &rhs ){

        return ( *this ).getName() == rhs.getName()
            && ( *this ).getLastName() == rhs.getLastName()
            && ( *this ).getAge() == rhs.getAge()
            && ( *this ).getDept() == rhs.getDept()
            && ( *this ).getMajor() == rhs.getMajor();
    }

    bool Student::operator!=( const Student &rhs ){
        return !(( *this ) == rhs);
    }

    Student::Student(){

        name = unknown;
        lastName = unknown;
        age = 0;
        dept = 0;
        major = unknown;
    }

    Student::Student( const std::string& name, const std::string& lastName, int age, int dept, const std::string &major ){
       
        setName( name );
        setLastName( lastName );
        setAge( age );
        setDept( dept );
        setMajor( major );
    }

    Student::~Student(){}

    void Student::print(){

        std::string space = " ";
        std::cout << name << space
                  << lastName << space
                  << age << space
                  << dept << space
                  << major
                  << std::endl;
    }