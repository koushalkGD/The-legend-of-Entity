#include "Game.hpp"

Game::Game()
    : window(
        sf::VideoMode(sf::Vector2u{800, 600}),
        "Zelda-like-Game"
      ),
      camera(sf::FloatRect(
        sf::Vector2f{0.f, 0.f},
        sf::Vector2f{800.f, 600.f}
        ))
{
    window.setFramerateLimit(60);

    //center the camera arround the player
    camera.setCenter(player.getPosition());
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

    //camera follow player
     camera.setCenter(player.getPosition());
}

void Game::render()
{
    window.clear(sf::Color::Black); // Dark background
    window.setView(camera); // Set the view to the camera
    world.render(window); // Render the world (tile map)
    player.render(window); // Render the player
    window.display();
}

