#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void update(float dt);
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    float speed;
};
