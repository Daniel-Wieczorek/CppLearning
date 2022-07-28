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
    std::cout << "Display method called: length " << std::endl;
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
























MyString &MyString::operator=(const MyString &rhs)
{
    if (this == &rhs)
        return *this;

    delete [] this->str;   
    str = new char[std::strlen(rhs.str)+1];
    std::strcpy(this->str, rhs.str);
}