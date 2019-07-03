#include "house.h"

bool House::isHitting() const
{
    return (getTotal() <= 16);
}

void House::flipSecondCard()
{
    if(!m_Cards.empty())
    {
        m_Cards[1]->flip();
    }
    else
    {
        std::cout << "No card to flip.\n";
    }
}
