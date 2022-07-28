#include <cstring>
#include <iostream>
#include "Mystring.hpp"

Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
}

Mystring &Mystring::operator=(const Mystring &right_object) // copy constructor in = operator overloading
{
    std::cout << "Copy assignement" << std::endl;

    if (this == &right_object)
        return *this; // we use & so it should return not pointer but value (reference operator wants the value)

    delete[] this->str;
    str = new char[std::strlen(right_object.str) + 1];
    std::strcpy(this->str, right_object.str);
    return *this;
}

Mystring::Mystring(Mystring &&source) // Move assignement
    : str(source.str)
{
    source.str = nullptr;
    std::cout << "Move constructor called" << std::endl;
}

Mystring &Mystring::operator=(Mystring &&right_value)
{
    std::cout << "Using move assigment" << std::endl;

    if (this == &right_value)
        return *this;

    delete[] str;
    str = right_value.str;
    right_value.str = nullptr;

    return *this;
}

Mystring Mystring::operator-() const // make lowercase
{
    char *buffer = new char[std::strlen(str) + 1];
    std::strcpy(buffer, str);

    for (size_t i = 0; i < std::strlen(buffer); i++)
        buffer[i] = std::tolower(buffer[i]);

    Mystring temp{buffer};
    delete[] buffer;

    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const // concatenate
{
    char *buffer = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);

    Mystring temp {buffer};
    delete [] buffer;

    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const // equality
{
    return (std::strcmp(str, rhs.str) == 0);
}

Mystring::~Mystring()
{
    delete[] str;
}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}