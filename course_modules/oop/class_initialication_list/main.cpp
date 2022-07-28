#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

int main()
{
    Player frank;
    frank.set_name("Frank");
    std::cout << frank.get_name() << std::endl;

    Player hero {"Hero", 120, 13};
    std::cout << hero.get_name() << std::endl;

    Player daniel {"Hi", 100,200};

    return 0;
}