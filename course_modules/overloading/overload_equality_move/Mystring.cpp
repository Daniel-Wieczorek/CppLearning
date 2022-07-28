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

Mystring::Mystring(Mystring &&source) // MOve assignement
    :str(source.str)
    {
        source.str = nullptr;
        std::cout << "Move constructor called" << std::endl;
    }

Mystring &Mystring::operator=(Mystring &&right_value)
{
    std::cout << "Using move assigment" << std::endl;

    if(this == &right_value)
        return *this;

    delete [] str;
    str = right_value.str;
    right_value.str = nullptr;

    return *this;

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