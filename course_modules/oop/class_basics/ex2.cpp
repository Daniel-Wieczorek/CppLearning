#include <iostream>
#include <string>
#include <vector>


class Player{
public:
    // atributes
    std::string name {"No name"};
    int health {100};
    int xp {3};

    //methods
    void talk(std::string text_to_say) 
    {
        std::cout << name << " says: " << text_to_say << std::endl;
    }

    bool is_dead();
};

class Account{
public:
    std::string name {"Account"};
    double balance {0.0};

    //methods
    bool deposit(double bal)
    {
        balance += bal;
        std::cout << "In deposit:" << bal << std::endl;
    }

    bool withdraw(double bal)
    {
        balance -= bal;
        std::cout << "In withdraw:" << bal << std::endl;
    }
};


int main()
{
    Account frank_account;
    frank_account.name = "Frank account";
    frank_account.balance = 5000.0;
    frank_account.deposit(1000.0);
    frank_account.withdraw(500);


    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp - 12;
    frank.talk("Hello Frank");

    Player *hero = new Player;
    hero->name = "Enemy";
    hero->health = 120;
    hero->xp = 15;
    hero->talk("I Will destroy you");


    return 0;
}