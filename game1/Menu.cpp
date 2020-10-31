#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <vector>

Menu::Menu() : window(sf::VideoMode(1280, 720), "Menu-WTC", sf::Style::Close),textureback(), texture(), player(), back() {
    window.setFramerateLimit(60);

    if (!textureback.loadFromFile("textures/back1.png")) {}
    back.setTexture(textureback);
    back.setPosition(0.f, 0.f);
    back.setScale(1.f, 1.f);

    if (!texture.loadFromFile("textures/enter.png")) {}
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
    window.draw(back);
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
    else if (key == sf::Keyboard::M)
    {
        std::cout << "x -> " << sf::Mouse::getPosition(window).x << "\n y -> " << sf::Mouse::getPosition(window).y << "\n";
    }
    else if (key == sf::Keyboard::Escape)
    {
        //window.close();
    }
}
    