#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    void set_name(std::string name_val)
    {
        name = name_val;
    }

    Player()
    {
        std::cout << "No args conctructor called" << std::endl;
    }

    Player(std::string name)
    {
        std::cout << "String arg constructor called with argument " << name << std::endl;
    }

    Player(std::string name, int health, int xp)
    {
        std::cout << "Three args conctructor called with args: " << name << health << xp << std::endl;
    }

    ~Player()
    {
        std::cout << "Desctructor called for " << name << std::endl;
    }
};

int main()
{
    Player slayer;
    slayer.set_name("Slayer");

    Player frank;
    frank.set_name("FRANK");

    Player villain("Villain", 100, 12);
    villain.set_name("Villain2");

    Player *enemy = new Player;
    enemy->set_name("Enemy");
    delete enemy;

    return 0;
}