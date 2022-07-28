#include <iostream>
#include <string>
#include <vector>

class Account{
private:
    std::string account_name;
    double balance;

public:
    //methods
    // decalred inline
    void set_balance(double bal) {balance = bal;}
    double get_balance() {return balance;}

    // methods declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

void Account::set_name(std::string n)
{
    account_name = n;
}

std::string Account::get_name()
{
    return account_name;
}

bool Account::deposit(double amount)
{
    //if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if(balance-amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    Account frank_account;

    frank_account.set_name("Frank account");
    frank_account.set_balance(1000.0);

    if(frank_account.deposit(200.0))
        std::cout << "Deposit OK" << std::endl;
    else
        std::cout << "Deposit not allowed" << std::endl;

    if(frank_account.withdraw(500.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Not sufficient funds" << std::endl;
    
    if(frank_account.withdraw(1500.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Not sufficient found" << std::endl

    return 0;
}