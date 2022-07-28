#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;

public:
    Mystring(/* args */);
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();

    Mystring &operator=(const Mystring &right_object); // Copy assigment

    Mystring(Mystring &&source);                  // Move constructor
    Mystring &operator=(Mystring &&right_object); // Move assignement

    Mystring operator-() const;                    // make lowercase
    Mystring operator+(const Mystring &rhs) const; // concatenate
    bool operator==(const Mystring &rhs) const;    // equality

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif