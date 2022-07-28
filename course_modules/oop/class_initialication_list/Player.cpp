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


Player::Player()
    : name{ "None" }, health{ 0 }, xp{ 0 }
{

}

Player::Player(std::string name, int health, int xp)
    : name{ name }, health{ health }, xp{ xp }
{

}

#ifdef DELEGATING_CONSTRUCTORS
Player::Player(std::string name, int health, int xp)
    : name{ name }, health{ health }, xp{ xp }
{

}

Player::Player() : Player{"None", 0, 0} // delegation constructor which will call 3 args constructor!
{

}

#ifdef SINGLE_CONSTRUCTOR
// in constructor declaration:
Player(std::string name = "None", int health = 0, int xp = 0);

// in constructor definition
Player::Player(std::string name, int health, int xp)
: name{name}, health{health}, xp{xp}
{
    std::cout << "Constructor called" << std::endl
}
#endif


/*
    std::string name;
    int health;
    int xp;

    Player(); // default constuctor overloaded
    Player(std::string name, int health, int xp);
    ~Player();
    */