#include <iostream>
#include <string>
#include "Player.hpp"


Player::Player(std::string name_const, int health_const, int xp_cons)
    : name{name_const}, health{health_const}, xp{xp_cons}
{
    std::cout << "Three-args constructor" << std::endl;
}

Player::Player(const Player &source)
    :name{source.name}, health{source.health}, xp{source.xp}
    {
        std::cout << "Copy constructor - made copy. Params:" << std::endl
        << "name: " << source.name << std::endl
        << "health: " << source.health << std::endl
        << "xp: " << source.xp << std::endl;
    }

Player::~Player()
{
    std::cout << "Desctructor called for " << name << std::endl;
}