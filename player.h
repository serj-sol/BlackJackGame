//virtual const bool IsHitting() Указывает, нужна ли игроку еще одна карта

//void Win() const Объявляет, что игрок выиграл

//void Lose() const Объявляет, что игрок проиграл

//void Push() const Объявляет, что игрок сыграл вничью

#ifndef PLAYER_H
#define PLAYER_H
#include <cstring>
#include "genericplayer.h"


class Player: public GenericPlayer
{
private:

public:
    Player(std::string name = "") : GenericPlayer(name) {}
    ~Player() {}

    virtual bool    isHitting() const;
    void            win() const;
    void            lose() const;
    void            push() const;
};

#endif // PLAYER_H
