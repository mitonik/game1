#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

Menu::Menu() : 
    window(sf::VideoMode(1280, 720), "Menu-WTC", sf::Style::Close),
    textureback(), 
    texture_button2(),
    texture_button(),
    player(), 
    back(),
    button()
{
    window.setFramerateLimit(60);

    if (!textureback.loadFromFile("textures/back1.png")) {}
    back.setTexture(textureback);
    back.setPosition(0.f, 0.f);
    back.setScale(1.f, 1.f);

    if (!texture_button.loadFromFile("textures/enter.png", sf::IntRect(10, 10, 100, 50))){}
    button.setTexture(texture_button);
    button.setPosition(100.f, 200.f);
    //button.setColor(sf::Color(0, 255, 0));

    if (!texture_button2.loadFromFile("textures/enter.png", sf::IntRect(10, 10, 100, 50))) {}
    button2.setTexture(texture_button2);
    button2.setPosition(100.f, 240.f);
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //mause button to start game 
        && sf::Mouse::getPosition(window).x >= 100
        && sf::Mouse::getPosition(window).y >= 200
        && sf::Mouse::getPosition(window).x <= 200
        && sf::Mouse::getPosition(window).y <= 230
        )
    {
        std::cout << "x -> " << sf::Mouse::getPosition(window).x << "\n y -> " << sf::Mouse::getPosition(window).y << "\n";
        Application game;
        window.close();
        game.run();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //mause button to close 
        && sf::Mouse::getPosition(window).x >= 100
        && sf::Mouse::getPosition(window).y >= 240
        && sf::Mouse::getPosition(window).x <= 200
        && sf::Mouse::getPosition(window).y <= 270
        )
    {
        std::cout << "x -> " << sf::Mouse::getPosition(window).x << "\n y -> " << sf::Mouse::getPosition(window).y << "\n";
        window.close();
    }
}

void Menu::render() {
    window.clear();
    window.draw(back);
    window.draw(player);
    window.draw(button);
    window.draw(button2);
    window.display();
}

void Menu::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::M)
    {
        std::cout << "x -> " << sf::Mouse::getPosition(window).x << "\n y -> " << sf::Mouse::getPosition(window).y << "\n";
    }
    else if (key == sf::Keyboard::Escape)
    {
        //window.close();
    }
}