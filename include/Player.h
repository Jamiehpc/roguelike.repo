#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"


class Player
{
    public:
        Player();
        virtual ~Player();
        void PlayerMove();
        int Attack();
        void TakeDamage();

    protected:

    private:
    sf::Vector2u m_playerPos {0,0};
    int m_health {100};
    bool m_isAlive {true};
    int m_armour {0};
    int m_damage{2};
    int m_initiative{3};

};

#endif // PLAYER_H
