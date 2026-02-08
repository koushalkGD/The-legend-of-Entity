#pragma once
#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

class Player
{
public:
    Player();

    void update(float dt, const TileMap& world);
    void render(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;

private:
    sf::FloatRect getHitbox() const;

private:
    sf::Texture texture;
    sf::Sprite sprite{texture};

    sf::Vector2f velocity;
    float speed;
};
