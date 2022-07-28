#ifndef C793191C_C740_4DB2_BE30_F8B1259ECAA9
#define C793191C_C740_4DB2_BE30_F8B1259ECAA9
#include <string>

class Account
{
    friend std::ostream &operator <<(std::ostream &os, const Account &account);

protected:

    double balance;

public:

    void deposit(double amount);
    void withdraw(double amount);

    // Constructors && Destructors
    Account();
    Account(double balance);
    ~Account();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
