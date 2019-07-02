//rank m_Rank     Значение карты (туз, двойка, тройка и так долее). ​ rank — это
//    перечисление, куда входят все 13 значений

//suit m_Suit     Масть карты (трефы, бубны, червы и пики). ​ suit — это перечисление,
//    содержащее четыре возможные масти

//bool m_IsFaceUp     Указывает, как расположена карта — вверх лицом или рубашкой.
//    Влияет на то, отображается она или нет

//int GetValue()  Возвращает значение карты

//void Flip()     Переворачивает карту. Может использоваться для того, чтобы
//   перевернуть карту лицом вверх или вниз

#ifndef CARD_H
#define CARD_H
#include "globals.h"
#include <iostream>

class Card
{
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;

public:
    Card(rank r, suit s, bool isf = 0 ): m_Rank(r), m_Suit(s), m_IsFaceUp(isf) {}
    ~Card() {}
    int     getValue() const;
    void    flip();
    friend std::ostream& operator<< (std::ostream& os, const Card& aCard);
};

#endif // CARD_H
