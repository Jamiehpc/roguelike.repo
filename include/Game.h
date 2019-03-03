#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "string"
#include "TileMap.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void Run();

    protected:

    private:
    bool m_gameIsRunning {true};
    sf::RenderWindow window;
};

#endif // GAME_H
