#include "Player.hpp"
#include <cmath>

Player::Player()
{
    body.setSize({40.f, 40.f});
    body.setFillColor(sf::Color::Green);

    // Center pivot
    body.setOrigin(body.getSize() / 2.f);

    // Spawn in center
    body.setPosition({400.f, 300.f});

    // Set player speed
    speed = 250.f;
}

void Player::update(float dt)
{
    // movement
    sf::Vector2f direction{0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        direction.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        direction.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        direction.x += 1.f;

    //Normalization direction
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if(length != 0.f)
    {
        direction /= length;
    }

    body.move(direction * speed * dt);

}

void Player::render(sf::RenderWindow& window)
{
    window.draw(body);
}

// Get the player's current position
sf::Vector2f Player::getPosition() const
{
    return body.getPosition();
}
