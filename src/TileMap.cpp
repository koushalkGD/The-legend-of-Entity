#include "TileMap.hpp"

TileMap::TileMap()
{
    map =
    {
        {TileType::Wall, TileType::Wall,  TileType::Wall,  TileType::Wall,  TileType::Wall},
        {TileType::Wall, TileType::Grass, TileType::Grass, TileType::Grass, TileType::Wall},
        {TileType::Wall, TileType::Grass, TileType::Grass, TileType::Grass, TileType::Wall},
        {TileType::Wall, TileType::Grass, TileType::Grass, TileType::Grass, TileType::Wall},
        {TileType::Wall, TileType::Wall,  TileType::Wall,  TileType::Wall,  TileType::Wall},
    };
}

bool TileMap::isSolidAt(sf::Vector2f worldPos) const
{
    int tileX = static_cast<int>(worldPos.x) / TILE_SIZE;
    int tileY = static_cast<int>(worldPos.y) / TILE_SIZE;

    // Outside map = solid
    if (tileX < 0 || tileY < 0 ||
        tileY >= static_cast<int>(map.size()) ||
        tileX >= static_cast<int>(map[0].size()))
        return true;

    // ✅ FIX HERE
    return map[tileY][tileX] == TileType::Wall;
}


void TileMap::render(sf::RenderWindow& window) const
{
    sf::RectangleShape tile({(float)TILE_SIZE, (float)TILE_SIZE});

    for (size_t y = 0; y < map.size(); ++y)
    {
        for (size_t x = 0; x < map[y].size(); ++x)
        {
            tile.setPosition({x * TILE_SIZE * 1.f, y * TILE_SIZE * 1.f});

            tile.setFillColor(
                map[y][x] == TileType::Wall
                ? sf::Color(120,120,120)
                : sf::Color(80,180,80)
            );

            window.draw(tile);
        }
    }
}
