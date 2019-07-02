#include "deck.h"
#include <algorithm>
#include "globals.h"

void Deck::populate()
{
    clear();

    for(int s  = suit::CLUBS; s <= suit::SPADES; ++s)
    {
        for(int r = rank::ACE; r <= rank::KING; ++r)
        {
            add(new Card(static_cast <rank> (r), static_cast<suit> (s)));
        }
    }
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
        deal (aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if(aGenericPlayer.isBoosted())
        {
            aGenericPlayer.bust();
        }
    }
}
