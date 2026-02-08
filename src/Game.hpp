#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "TileMap.hpp"   // ✅ REQUIRED

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    sf::View camera;

    TileMap world;   // ✅ now compiler knows TileMap
    Player player;
};
