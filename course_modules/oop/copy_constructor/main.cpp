#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

void display_player(Player player_object)
{
    std::cout << "in: Name: " << player_object.get_name() << std::endl;
    std::cout << "in Health: " << player_object.get_health() << std::endl;
    std::cout << "in XP: " << player_object.get_xp() << std::endl;
    std::cout << "Public xp:" << player_object.xp << std::endl;
}

void display_player(Player player)
{
    std::cout << "Data from object: " << player.get_name() << " " << player.get_health() << " " << std::endl;
}



int main()
{
    Player empty;

    /* function display_player actually needs copy of 
       the empty object so COPY CONSTRUCTOR WILL BE Called */


    Player frank{"Frank"};
    display_player(frank);
    Player mark{"Mark", 100, 55};

    return 0;
}