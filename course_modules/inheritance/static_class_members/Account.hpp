#ifndef C793191C_C740_4DB2_BE30_F8B1259ECAA9
#define C793191C_C740_4DB2_BE30_F8B1259ECAA9
#include <string>

class Account
{
public:
    double balance;
    std::string name;
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    ~Account();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
