#include "Mystring.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

MyString::MyString()
    :str{nullptr}
{
    str = new char[1];
    *str = '\0';
    std::cout << "No-args constructor called" << std::endl;
}

MyString::MyString(const char *s)
    :str{nullptr}
{
    str = new char[std::strlen(s)+1];
    std::strcpy(str, s);
    std::cout << "Constructor called" << std::endl;
}

MyString::~MyString()
{
    delete [] str;
}

void MyString::display() const
{
    std::cout << "******* STR: ******* : " << str << std::endl;
}

int MyString::get_length() const
{
    auto length = std::strlen(str);
    std::cout << "Length: " << length << std::endl;
    return length;
}

const char* MyString::get_str() const
{
    std::cout << "Address: " << str << std::endl;
    return str;
}

/* Deep copy constructor */
MyString::MyString(const MyString &source)
    :str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor called" << std::endl;
}

/* Copy assigment */
MyString &MyString::operator=(const MyString &rhs)
{
    std::cout << "Copy assigment called" << std::endl;

    if(this == &rhs)
        return *this;

    // this object is object of a class so it might point to some string already
    
    delete [] this->str;
    str = new char[std::strlen(rhs.str)+1];
    std::strcpy(this->str, rhs.str);

    return *this;
}

MyString MyString::operator-() const
{
    //- is unary operator so it is called on the left of the object and cant take any argumetns
    std::cout << "Operator - overload function called" << std::endl;
    char *buffer = new char[std::strlen(str) + 1];
    for (size_t i = 0; i< std::strlen(str); i++)
    {
        buffer[i] = std::tolower(str[i]);
    }

    MyString temp {buffer};
    delete [] buffer;
    
    return temp;
}

MyString MyString::operator+(const MyString &rhs) const
{
    char *buffer = new char[(std::strlen(str) + std::strlen(rhs.str) + 2)];
    std::cout << "DEBUG data: " << "str: " << str << std::endl;
    std::cout << "DEBUG data: " << "rhs: " << rhs.str << std::endl; 
    const char *space = "_";
    std::strcpy(buffer, str);
    std::strcat(buffer, space);
    std::strcat(buffer, rhs.str);

    MyString temp {buffer};
    delete [] buffer;

    return temp;
}

/*
Stram insertion operators - doesnt make sense to implement these as member methods:
    - left operant must be a suer-defined classs
    - not the way we normally use these operands
*/


// stream insertion operator:
std::ostream &operator<<(std::ostream &os, const MyString &obj)
{
    os << obj.str;      // if     friend function
    //os << obj.get_str(); // if not friend function

    return os;
}

// stream extraction operator:
std::istream &operator>>(std::istream &is, MyString &obj)
{
    char *buff = new char [1000];
    is >> buff;
    obj = MyString{buff};

    delete [] buff;
    return is;

}