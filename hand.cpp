#include "hand.h"

void Hand::add(Card* pCard)
{
    if(!(pCard->getValue()))    // <--Добавил условие и переворот карты, если она рубашкой вверх,
        pCard->flip();          //<-- иначе карты остаются перевернутыми.
    m_Cards.push_back(pCard);
}

int Hand::getTotal() const
{
    if(m_Cards.empty())
        return 0;

    if(m_Cards[0]->getValue() == 0)
        return 0;

    int total = 0;
    std::vector<Card*>::const_iterator iter;

    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        total += (*iter)->getValue();

    bool containsAce = false;

    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        if ((*iter)->getValue() == rank::ACE)
            containsAce = true;
    if (containsAce && total <= 11)

        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку

        total += 10;
    return total;
}
void Hand::clear()
{
    for(auto ite = m_Cards.begin(); ite != m_Cards.end(); ++ite)
    {
        delete *ite;
        *ite = 0;
    }
    m_Cards.clear();
}
