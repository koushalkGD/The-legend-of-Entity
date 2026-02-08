#pragma once
#include <SFML/Graphics.hpp>

class TileMap;

class Player
{
public:
    Player();

    void update(float dt, const TileMap& world);
    void render(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape body;
    sf::Vector2f velocity;
    float speed;
};
