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

Player::Player() // Call three args constructor
    : Player {"None", 0, 0} // This constructor will call 3 arg constructor in tthe end (delegation of the constructors)
{
    std::cout << "No-args constructor" << std::endl;
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