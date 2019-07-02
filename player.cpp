#include "player.h"

//Player::Player()
//{

//}

bool Player::isHitting() const
{
    std::cout << m_Name << ", do you want a hit? (Y/N)";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    std::cout << m_Name << " wins.\n";
}

void Player::lose() const
{
    std::cout << m_Name << " loses.\n";
}

void Player::push() const
{
    std::cout << m_Name << " pushes.\n";
}
