    Student::Student(){
        name = unknown;
        lastName = unknown;
        age = 0;
        dept = 0;
        major = unknown;
    }

    
    Student::Student( const std::string& name, const std::string& lastName, int age, int dept, const std::string& major ){
        setName(name);
        setLastName(lastName);
        setAge(age);
        setDept(dept);
        setMajor(major);
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