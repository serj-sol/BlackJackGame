#include <iostream>
#include <vector>
#include <cstring>

#include "player.h"
#include "game.h"
#include "card.h"
#include "deck.h"
#include "genericplayer.h"
#include "globals.h"
#include "hand.h"
#include "house.h"

int main (int argc, char* argv[])
{
    std::cout << "\t\tWelcome to BlackJack!\n\n";

    int numPlayers = 0;

    while (numPlayers < 1 || numPlayers > 7)
    {
        std::cout << "How many players? (1 - 7): ";
        std::cin >> numPlayers;
    }
    std::vector<std::string> names;

    std::string name;

    for(int i = 0; i < numPlayers; ++i)

    {
        std::cout << "Enter player name: ";
        std::cin >> name;
        names.push_back(name);
    }
    std::cout << std::endl;

    // игровой цикл
    Game aGame (names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
    }
    return 0;
}