#include "TileMap.hpp"
#include <stdexcept>

TileMap::TileMap()
{
    if (!tileset.loadFromFile("assets/tileset.png"))
        throw std::runtime_error("Failed to load tileset");

    map =
    {
        {0,0,0,0,0},
        {0,5,5,5,0},
        {0,5,1,5,0},
        {0,5,5,5,0},
        {0,0,0,0,0}
    };
}


bool TileMap::isSolidAt(sf::Vector2f worldPos) const
{
    int tileX = static_cast<int>(worldPos.x) / TILE_SIZE;
    int tileY = static_cast<int>(worldPos.y) / TILE_SIZE;

    if (tileX < 0 || tileY < 0 ||
        tileY >= static_cast<int>(map.size()) ||
        tileX >= static_cast<int>(map[0].size()))
        return true;

    return map[tileY][tileX] == 0;  // 0 = wall
}


void TileMap::render(sf::RenderWindow& window)
{
    int tilesPerRow = tileset.getSize().x / TILE_SIZE;

    for (size_t y = 0; y < map.size(); ++y)
    {
        for (size_t x = 0; x < map[y].size(); ++x)
        {
            int tileIndex = map[y][x];

            int tu = tileIndex % tilesPerRow;
            int tv = tileIndex / tilesPerRow;

            tileSprite.setTextureRect(
                sf::IntRect(
                    sf::Vector2i{tu * TILE_SIZE, tv * TILE_SIZE},
                    sf::Vector2i{TILE_SIZE, TILE_SIZE}
                )
            );

            tileSprite.setPosition(
                sf::Vector2f{
                    static_cast<float>(x * TILE_SIZE),
                    static_cast<float>(y * TILE_SIZE)
                }
            );

            window.draw(tileSprite);
        }
    }
}
