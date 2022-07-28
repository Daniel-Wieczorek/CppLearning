
class MyString
{
    private:
        char *str; // pointer to a char[] that holds a C-style string

    public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    ~MyString();

    void display() const;
    int get_length() const;
    const char *get_str() const;

    MyString &operator=(const MyString &rhs); // Copy assignment. We return object by reference here.
};