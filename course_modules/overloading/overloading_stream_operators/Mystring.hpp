#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;

public:
    Mystring(/* args */);
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();

    Mystring &operator=(const Mystring &right_object); // Copy assigment

    Mystring(Mystring &&source);                  // Move constructor

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif