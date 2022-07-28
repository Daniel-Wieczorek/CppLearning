#include <iostream>
#include <vector>

class Account
{
private:
    friend std::ostream& operator<<(std::ostream& os, Account& obj);
public:
    void withdraw(int money)
    {
        std::cout<<"Withdraw from Account: "<<money<<std::endl;
    }

    virtual ~Account() { }

};

std::ostream& operator<<(std::ostream& os, Account& obj)
{
    os<<"Account display overloaded operator: ";
    return os;
}

class Checking : public Account
{
private:
    friend std::ostream& operator<<(std::ostream& os, Checking& obj);
public:
    virtual void withdraw(int money)
    {
        std::cout<<"Withdraw from Checking: "<<money<<std::endl;
    }

    virtual ~Checking() { }

};

std::ostream& operator<<(std::ostream& os, Checking& obj)
{
    os<<"Checking display from overloaded operator";
    return os;
}


int main()
{
    Account* objAccount = new Account();

    Account* objChecking = new Checking();

    std::cout<<*objAccount<<std::endl;  // Account display overloaded operator:
    std::cout<<*objChecking<<std::endl; // Account display overloaded operator:

    /*
    So the behaviour for the second case will not as expected. Both functions
    will call friend function from friend function defined for Account class.
    I will keep this example and correct impl. will be done in 
    class_interfaces_corrected
    */

    return 0;
}