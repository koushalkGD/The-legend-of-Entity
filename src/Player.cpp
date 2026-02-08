#include "Player.hpp"
#include "TileMap.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

static constexpr int FRAME_WIDTH = 32;
static constexpr int FRAME_HEIGHT = 48;

Player::Player()
{
    // player properties
    if(!texture.loadFromFile("assets/player.png"))
    {
        // Handle error
        throw std::runtime_error("Failed to load player texture");
    }

    sprite.setTexture(texture);

    sprite.setTextureRect(
        sf::IntRect(
            sf::Vector2i{0, 0},
            sf::Vector2i{FRAME_WIDTH, FRAME_HEIGHT}
        )
    );

    //size of the player
    sprite.setScale(sf::Vector2f{2.f, 2.f});

    // Set the origin
    auto bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.size / 2.f);

    // Spawn position
    sprite.setPosition(sf::Vector2f
    {
        2.f * TileMap::TILE_SIZE + TileMap::TILE_SIZE / 2.f,
        2.f * TileMap::TILE_SIZE + TileMap::TILE_SIZE / 2.f
    });

    speed = 200.f; // pixels per second
}

bool isColliding(const TileMap& world, const sf::FloatRect& bounds)
{
    sf::Vector2f topLeft     = bounds.position;
    sf::Vector2f topRight    = bounds.position + sf::Vector2f{bounds.size.x, 0.f};
    sf::Vector2f bottomLeft  = bounds.position + sf::Vector2f{0.f, bounds.size.y};
    sf::Vector2f bottomRight = bounds.position + bounds.size;

    return
        world.isSolidAt(topLeft)     ||
        world.isSolidAt(topRight)    ||
        world.isSolidAt(bottomLeft)  ||
        world.isSolidAt(bottomRight);
}


sf::FloatRect Player::getHitbox() const
{
    sf::FloatRect bounds = sprite.getGlobalBounds();

    // shrink hitbox (feet area)
    bounds.position.x += bounds.size.x * 0.25f;
    bounds.position.y += bounds.size.y * 0.50f;
    bounds.size.x     *= 0.50f;
    bounds.size.y     *= 0.40f;

    return bounds;
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}

void Player::update(float dt, const TileMap& world)
{
    sf::Vector2f direction{0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) direction.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) direction.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) direction.x += 1.f;

    // Normalize direction
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f)
        direction /= length;

    velocity = direction * speed;

    //sf::FloatRect bounds = getHitbox();

    // X axis
    sf::FloatRect nextX = getHitbox();
    nextX.position.x += velocity.x * dt;

    if (!isColliding(world, nextX))
        sprite.move({velocity.x * dt, 0.f});

    // Y axis
    sf::FloatRect nextY = getHitbox();
    nextY.position.y += velocity.y * dt;

    if (!isColliding(world, nextY))
        sprite.move({0.f, velocity.y * dt});
}

void Player::render(sf::RenderWindow& window) const
{
    window.draw(sprite);
}
