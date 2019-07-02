//string m_Name Имя игрока

//virtual bool IsHitting() const = 0
//Указывает, нужна ли игроку еще одна карта. Чистая виртуальная функция

//bool IsBoosted() const Указывает, что у игрока перебор

//void Bust() const Объявляет, что у игрока перебор

#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include "hand.h"


class GenericPlayer : public Hand
{
protected:
    std::string m_Name;
public:
    GenericPlayer(const std::string& name = "") : m_Name(name) {}
    ~GenericPlayer() {}
    virtual bool    isHitting() const = 0;
    bool            isBoosted() const;
    void            bust() const;

    friend std::ostream& operator<< (std::ostream& os, GenericPlayer& aGenericPlayer);
};

#endif // GENERICPLAYER_H
