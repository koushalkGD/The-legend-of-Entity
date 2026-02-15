#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

// enum class TileType
// {
//     Grass,
//     Wall
// };

class TileMap
{
public:
    TileMap();

    void render(sf::RenderWindow& window);
    bool isSolidAt(sf::Vector2f worldPos) const;
    static constexpr int TILE_SIZE = 32;

private:
    sf::Texture tileset;
    sf::Sprite tileSprite{tileset};
    std::vector<std::vector<int>> map;
};
