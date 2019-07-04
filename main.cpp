#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <cstdlib>

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
        std::cout << "How many players? (1 - 7):  (Enter -1 for exit) ";
        std::cin >> numPlayers;

        if (numPlayers == -1)
            return 0;

        std::cin.clear();   // Очистка ошибок и потока на случай ввода не цифр.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

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

    // Игровой цикл.

    Game aGame (names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
        system("clear");
    }
    return 0;
}
