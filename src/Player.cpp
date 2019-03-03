#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::PlayerMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_playerPos.y -=1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_playerPos.y += 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_playerPos.x -= 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_playerPos.x += 1;

}
