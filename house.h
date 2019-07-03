//virtual const bool IsHitting() Указывает, нужна ли игроку еще одна карта

//void FlipFirstCard() Переворачивает первую карту
#ifndef HOUSE_H
#define HOUSE_H

#include "genericplayer.h"

class House : public GenericPlayer
{
private:
public:
    House(const std::string& name = "House") : GenericPlayer(name) {}
    virtual ~House() {}
    virtual bool    isHitting() const;
    void            flipSecondCard();
};

#endif // HOUSE_H
