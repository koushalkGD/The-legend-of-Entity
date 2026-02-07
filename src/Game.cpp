#include "Game.hpp"

Game::Game()
    : window(
        sf::VideoMode(sf::Vector2u{800, 600}),
        "Zelda-like-Game"
      )
{
    window.setFramerateLimit(60);
}

void Game::run()
{
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents()
{
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update(float dt)
{
    // Player logic will go here
    player.update(dt);
}

void Game::render()
{
    window.clear(sf::Color::Black); // Dark background
    player.render(window); // Render the player
    window.display();
}

