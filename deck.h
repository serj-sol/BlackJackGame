//vold Populate() Создает стандартную колоду из 52 карт

//void Shuffle() Тасует карты

//vold Deal (Hand& aHand) Раздает в руку одну карту

//void AddltionalCards (GenericPlayer& aGenerlcPlayer) Раздает игроку дополнительные карты до тех пор,
//пока он может и хочет их получать

#ifndef DECK_H
#define DECK_H
#include "hand.h"
#include "genericplayer.h"


class Deck : public Hand
{
private:
public:
    Deck()
    {
        m_Cards.reserve(52);
        populate();
    }
    ~Deck() {}

    void populate();
    void shuffle();
    void deal (Hand& aHand);
    void additionalCards (GenericPlayer& aGenerlcPlayer);
};

#endif // DECK_H
