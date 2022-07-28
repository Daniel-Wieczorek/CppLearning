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
    void talk(std::string);
    bool is_dead();
};

class Account{
public:
    std::string name {"Account"};
    double balance {0.0};

    //methods
    bool deposit(double);
    bool withdraw(double);
};


int main()
{
    Player frank;
    Player hero;

    Account frank_account;
    Account jim_account;

    Player players[] {frank, hero};
    std::vector<Player> play_vec {frank};
    play_vec.push_back(hero);

    Player *enemy {nullptr};
    enemy = new Player;
    delete enemy;

    return 0;
}