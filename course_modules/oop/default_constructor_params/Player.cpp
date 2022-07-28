#include <iostream>
#include <string>
#include "Player.hpp"

void Player::set_name(std::string name_val)
{
    name = name_val;
}

std::string Player::get_name()
{
    return name;
}

Player::Player(std::string name_const, int health_const, int xp_cons)
    : name{name_const}, health{health_const}, xp{xp_cons}
{
    std::cout << "Three-args constructor" << std::endl;
}

Player::~Player()
{
    std::cout << "Desctructor called for " << name << std::endl;
}