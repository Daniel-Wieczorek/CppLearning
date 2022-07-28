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
Player::Player() // default constuctor overloaded
{
    name = "None";
    health = 100;
    xp = 3;
}

Player::Player(std::string name, int health, int xp)
{
    std::cout << "Three args conctructor called with args: " << name << health << xp << std::endl;
}

Player::~Player()
{
    std::cout << "Desctructor called for " << name << std::endl;
}