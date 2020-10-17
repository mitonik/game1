#include "Menu.h"
#include "Game.h"

Menu::Menu() : window(sf::VideoMode(1280, 720), "Menu-WTC", sf::Style::Close), texture(), player() {
    window.setFramerateLimit(60);
    if (!texture.loadFromFile("ENTER.png")) {}
    player.setTexture(texture);
    player.setPosition(100.f, 100.f);
    player.setScale(2.f, 2.f);
}

void Menu::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    while (window.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Menu::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}


void Menu::update(sf::Time)
{
}

void Menu::render() {
    window.clear();
    window.draw(player);
    window.display();
}

void Menu::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Enter)
    {
        Game game;
        window.close();
        game.run();
    }
    else if (key == sf::Keyboard::Escape)
    {
        window.close();
    }
}
