#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

void display_player_name(const Player &p)
{
    std::cout << p.get_name() << std::endl;
}

int main()
{
    Player empty;

    /* function display_player actually needs copy of 
       the empty object so COPY CONSTRUCTOR WILL BE Called */

    const Player frank{"Frank", 1000, 34};

    Player mark{"Mark", 100, 55};

    display_player_name(frank);

    return 0;
}