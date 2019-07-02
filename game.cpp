#include "game.h"
#include <cstdlib>
#include "player.h"
#include "house.h"

Game::Game(const std::vector<std::string>& names)
{
    std::vector<std::string>::const_iterator pName;

    for(pName = names.begin(); pName != names.end(); ++pName)
    {
        m_Players.push_back(Player(*pName));
    }

    srand(static_cast<unsigned int> (time(0)));
    m_Deck.populate();
    m_Deck.shuffle();
}


void Game::play()
{
    std::vector<Player>::iterator pPlayer;
    for(int i = 0; i < 2; ++i)
    {
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.deal(*pPlayer);
        }
        m_Deck.deal(m_House);
    }

    // Прячем превую карту дилера.

    m_House.flipFirstCard();

    // Открывем руки всех игроков.

    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        std::cout << *pPlayer << std::endl;
    }

    std::cout << m_House << std::endl;

    // Раздаем игрокам дополнительные карты.

    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.additionalCards(*pPlayer);
    }

    // Показваем первую карты дилера.

    m_House.flipFirstCard();
    std::cout << std::endl << m_House;

    // Раздаем дилеру дополнительные карты.

    m_Deck.additionalCards(m_House);

    if(m_House.isBoosted()) // Если у дилера перебор.
    {
        // Все, кто остался в игре, побеждают.
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if(!(pPlayer->isBoosted()))
            {
                pPlayer->win();
            }
        }
    }
    else
    {
        // Сравниваем суммы очков всех оставшихся игроков с суммой очков дилера.

        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if(!(pPlayer->isBoosted()))
            {
                if(pPlayer->getTotal() > m_House.getTotal())
                {
                    pPlayer->win();
                }

                if(pPlayer->getTotal() < m_House.getTotal())
                {
                    pPlayer->lose();
                }

                else
                {
                    pPlayer->push();
                }
            }
        }
    }
    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    m_House.clear();
}
