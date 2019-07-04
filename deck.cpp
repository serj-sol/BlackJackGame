#include "deck.h"
#include <algorithm>

Deck::Deck ()
{
    clear();
    m_Cards.reserve(52);
    populate();
    shuffle();
}
void Deck::populate()
{
    for(int s  = suit::CLUBS; s <= suit::SPADES; ++s)
    {
        for(int r = rank::ACE; r <= rank::KING; ++r)
        {
            add(new Card(static_cast <rank> (r), static_cast<suit> (s)));
        }
    }
    std::cout << "Теперь в колоде: " << m_Cards.size() << " карт.\n";
}

void Deck::shuffle()
{
    std::random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::deal(Hand& aHand)
{
    if(!m_Cards.empty())
    {
        aHand.add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        std::cout << "out of cards. Unable to deal.";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
    std::cout << std::endl;
    while (!(aGenericPlayer.isBoosted()) && aGenericPlayer.isHitting())
    {
        if(m_Cards.size() < 20)
        {
            std::cout << "Карт в колоде: " << m_Cards.size() << ". Добавляем новую колоду\n";
            this->populate();
            this->shuffle();

        }
        deal (aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if(aGenericPlayer.isBoosted())
        {
            aGenericPlayer.bust();
        }
    }
}
