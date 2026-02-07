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
    void render(sf::RenderWindow& window);

private:
    static constexpr int TILE_SIZE = 32;
    std::vector<std::vector<TileType>> map;
};
