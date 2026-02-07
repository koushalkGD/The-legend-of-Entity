#include "TileMap.hpp"

TileMap::TileMap()
{
    map =
    {
        {TileType::Wall, TileType::Wall, TileType::Wall, TileType::Wall, TileType::Wall},
        {TileType::Wall, TileType::Grass, TileType::Grass, TileType::Grass, TileType::Wall},
        {TileType::Wall, TileType::Grass, TileType::Grass, TileType::Grass, TileType::Wall},
        {TileType::Wall, TileType::Grass, TileType::Grass, TileType::Grass, TileType::Wall},
        {TileType::Wall, TileType::Wall, TileType::Wall, TileType::Wall, TileType::Wall},
    };
}

void TileMap::render(sf::RenderWindow& window)
{
    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f{
        static_cast<float>(TileMap::TILE_SIZE),
        static_cast<float>(TileMap::TILE_SIZE)
    });

    for (size_t y = 0; y < map.size(); ++y)
    {
        for (size_t x = 0; x < map[y].size(); ++x)
        {
            tile.setPosition(sf::Vector2f{
                static_cast<float>(x * TileMap::TILE_SIZE),
                static_cast<float>(y * TileMap::TILE_SIZE)
            });

            if (map[y][x] == TileType::Grass)
                tile.setFillColor(sf::Color(80, 180, 80));
            else if (map[y][x] == TileType::Wall)
                tile.setFillColor(sf::Color(120, 120, 120));

            window.draw(tile);
        }
    }
}
