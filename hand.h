//vector<Card*> m_Cards: Коллекция карт. Хранит указатели на объекты типа ​ Сard

//void Add(Card* pCard): Добавляет карту в руку.
//Добавляет указатель на объект типа ​ Сard в вектор ​ m_Сards

//void Clear(): Очищает руку от карт. Удаляет все указатели из вектора ​ m_Сards​,
//устраняя все связанные с ними объекты в куче

//int GetTotal(): Возвращает сумму очков карт руки

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"

class Hand
{
    protected:
    std::vector<Card*> m_Cards;
public:
    Hand()
    {
        m_Cards.reserve(7);
    }
    virtual ~Hand()
    {
        clear();
    }
    void    add(Card* pCard);
    void    clear();
    int     getTotal() const;

};

#endif // HAND_H
