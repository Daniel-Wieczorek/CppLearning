#include <iostream>
#include <string>
#include "Player.hpp"

/* INITIALIZATION OF THE STATIC VARIABLE*/
int Player::num_players {0};


Player::Player(std::string name_const, int health_const, int xp_cons)
    : name{name_const}, health{health_const}, xp{xp_cons}
{
    ++num_players;
    std::cout << "Three-args constructor" << std::endl;
}

Player::~Player()
{
    --num_players;
    std::cout << "Desctructor called for " << name << std::endl;
}

int Player::get_num_players()
{
    return num_players;
}