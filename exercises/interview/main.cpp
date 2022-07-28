#include<iostream>
#include<string>
#include<cstring>

class Base
{

private:
    char* str;
    int baseVal;
    std::string name;
    void print_name(Base& obj);
    friend Base operator+(const Base &lObj, const Base &rObj);
    Base &operator=(const Base &rhs);
public:

    // default constructor
    Base()
        :str{ nullptr }, baseVal{ 0 }, name{ "" }
    {
        str = new char [ 1 ];
        *str = '\0';
        std::cout<<"Default constructor called"<<std::endl;
    }

    // delegated contructor:
    Base(char* str, int baseVal)
        : Base{ str, baseVal, "" }
    {

    }

    // overloaded constructor
    Base(char* s, int baseVal, std::string name)
        :str{ nullptr }, baseVal{ baseVal }, name{ name }
    {
        str = new char [ std::strlen(s)+1 ];
        std::strcpy(str,s);
        std::cout << "Overloaded constructor called" << std::endl;
    }

# if 0
    // Shallow copy
    Base(const Base& obj)
        : str{ obj.str }, baseVal{ obj.baseVal }, name{ obj.name }
    {

    }
#endif

    // Deep copy constructor
    Base(const Base& obj)
        :str{nullptr}, baseVal{obj.baseVal}, name{obj.name}
    {
        str = new char[std::strlen(obj.str) + 1];
        std::strcpy(str, obj.str);
        std::cout<<"Deep copy constructor called"<<std::endl;
    }

    ~Base()
    {
        delete [] str;
        std::cout << "*** Destructor called *** " << std::endl;
    }

    // getter:
    std::string get_name(void) { return name; }
    void set_name(std::string newName) { name = newName; }

    //getter for str
    const char* get_str(void) {return str;}
    void set_str(const char *data) { std::strcpy(str,data);}

};

// Copy constructor called
void print_name(Base& obj)
{
    std::cout<<"The name is: "<<obj.get_name()<<std::endl;
}

// operator overloading:
Base operator+(const Base &lObj, const Base &rObj)
{   
    std::string out = lObj.name + "and" + rObj.name;
    std::cout << "DEBUG: Overload +" << std::endl;
    Base temp{};
    temp.set_name(out);
    return temp;
}

#if 0
Base &Base::operator=(const Base &rhs)
{
    if(this == &rhs)
        return *this;

    this->baseVal = rhs.baseVal;
    this->name.assign(rhs.str);

    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);

}
#endif

int main()
{
    std::cout << "EX1" << std::endl;
    Base b{ "Living in Munich", 25, "Daniel" };
    b.set_str("No changes");
    std::cout << "String get: " << b.get_str() << std::endl;
    
    std::cout << "EX2" << std::endl;
    Base d {b};
    std::cout << "String get: " << d.get_str() << std::endl;
    print_name(d);

    std::cout << "EX3" << std::endl;
    Base c {};
    b + d;
    //std::cout << "String get: " << c.get_str() << std::endl;

    return 0;
}