#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

void display_active_players(){
    std::cout << "Active players: " << Player::get_num_players() << std::endl;
}

int main()
{
    Player empty1;
    display_active_players();
    Player empty2;
    display_active_players();
    Player empty3;
    display_active_players();
    Player empty4;
    display_active_players();
    display_active_players();
    display_active_players();
    return 0;
}