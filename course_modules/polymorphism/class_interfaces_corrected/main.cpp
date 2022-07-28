#include <iostream>
#include <vector>

class Printable
{
private:
    friend std::ostream& operator<<(std::ostream& os, const Printable& obj);
public:
    virtual void print(std::ostream& os) const = 0;

    virtual ~Printable() { }
};

std::ostream& operator<<(std::ostream& os, const Printable& obj)
{
    obj.print(os);
    return os;
}

class Account : public Printable
{
public:
    void withdraw(int money)
    {
        std::cout<<"Withdraw from Account: "<<money<<std::endl;
    }

    virtual void print(std::ostream& os) const override
    {
        os<<"Overloaded operator called from Account class";
    }

    virtual ~Account() { }

};

class Checking : public Printable
{
public:
    virtual void withdraw(int money)
    {
        std::cout<<"Withdraw from Checking: "<<money<<std::endl;
    }
    virtual void print(std::ostream& os) const override
    {
        os<<"Overloaded operator called from Checking class";
    }

    virtual ~Checking() { }

};


int main()
{
    Printable* objAccount = new Account();

    Printable* objChecking = new Checking();

    std::cout<<*objAccount<<std::endl;  // Overloaded operator called from Account class
    std::cout<<*objChecking<<std::endl; // Overloaded operator called from Checking class
    
    /*
    So the behaviour for the second case will not as expected. Both functions
    will call friend function from friend function defined for Account class
    */

    return 0;
}