#include "Game.hpp"

Game::Game()
{
    // Initialize the window 
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    window.create(
        desktop,
        "Zelda-like-Game",
        sf::Style::None     // Borderless fullscreen
      );

    // Set a frame limit to make the game run at a consistent speed
    window.setFramerateLimit(60);

      // Initialize the camera
    camera = sf::View(
        sf::FloatRect(
        {0.f, 0.f},
        {800.f, 600.f})
    );

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
/*    if(event-> is<sf::Event::Resized>())
    {
        // Update the camera's viewport to maintain the aspect ratio
        sf::Vector2f size{
            static_cast<float>(event->size.width),
            static_cast<float>(event->size.height)
        };
        camera.setSize(size);
    }
*/
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update(float dt)
{
    // Player logic will go here
    player.update(dt, world);

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

