//Deck m_Deck Колода карт

//House m_House Рука дилера

//vector<Player> m_Players Группа игроков-людей. Вектор, содержащий объекты типа ​ Player

//void Play() Проводит кон игры ​ Blackjack
#ifndef GAME_H
#define GAME_H

#include <vector>

#include "house.h"
#include "player.h"
#include "deck.h"

class Game
{
protected:
    Deck                m_Deck;
    House               m_House;
    std::vector<Player> m_Players;
public:
    Game(const std::vector<std::string>& names);
    ~Game() {}
    void play();
};

#endif // GAME_H
