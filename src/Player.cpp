#include "Player.hpp"
#include "TileMap.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Player::Player()
{
    // Initialize player properties
    body.setSize({40.f, 40.f});
    // Set the player's color
    body.setFillColor(sf::Color::Red);
    // Set the origin
    body.setOrigin(body.getSize() / 2.f);
    // Spawn position
    body.setPosition(sf::Vector2f
    {
        2.f * TileMap::TILE_SIZE + TileMap::TILE_SIZE / 2.f,
        2.f * TileMap::TILE_SIZE + TileMap::TILE_SIZE / 2.f
    });

    speed = 200.f;
}

sf::Vector2f Player::getPosition() const
{
    return body.getPosition();
}

void Player::update(float dt, const TileMap& world)
{
    sf::Vector2f direction{0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) direction.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) direction.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) direction.x += 1.f;

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f)      direction /= length; // Normalize
    velocity = direction * speed;

    sf::Vector2f pos = body.getPosition();

    // ---- X axis movement ----
    sf::Vector2f nextX = {pos.x + velocity.x * dt, pos.y};
    if (!world.isSolidAt(nextX))
        body.setPosition(nextX);

    // ---- Y axis movement ----
    sf::Vector2f nextY = {body.getPosition().x, pos.y + velocity.y * dt};
    if (!world.isSolidAt(nextY))
        body.setPosition(nextY);
}

void Player::render(sf::RenderWindow& window) const
{
    window.draw(body);
}
