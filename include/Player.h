#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"


class Player
{
    public:
        Player();
        virtual ~Player();
        void PlayerMove();

    protected:

    private:
    sf::Vector2u m_playerPos {0,0};
    int m_health {100};
};

#endif // PLAYER_H
