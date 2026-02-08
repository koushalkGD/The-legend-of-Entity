#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum class TileType
{
    Grass,
    Wall
};

class TileMap
{
public:
    TileMap();

    void render(sf::RenderWindow& window) const;
    bool isSolidAt(sf::Vector2f worldPos) const;
    static constexpr int TILE_SIZE = 32;

private:
    std::vector<std::vector<TileType>> map;
};
