#include "Account.hpp"
#include "SavingsAccount.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    Account a1 {1000};
    cout << a1 << endl;

    a1.deposit(500);
    cout << a1 << endl;

    a1.withdraw(1000);
    cout << a1 << endl;

    a1.withdraw(5000);
    cout << a1 << endl;

    cout << "================= SAVINGS ACCOUNT =================" << endl;
    Savings_Account s1 (1000, 5.0);

    s1.deposit(500);
    cout << s1 << endl;

    s1.withdraw(1000);
    cout << s1 << endl;

    s1.withdraw(5000);
    cout << s1 << endl;


    return 0;
}