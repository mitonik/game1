#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void Application::initWindow()
{
    std::ifstream ifs("config/window.ini");

    std::string title = "game1";
    sf::VideoMode window_bounds(1600, 900);
    unsigned framerate_limit = 60;
    bool vertival_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertival_sync_enabled;
    }
    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Close);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertival_sync_enabled);
}

void Application::initKeys()
{
//    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
//   this->supportedKeys["A"] = sf::Keyboard::Key::A;
//    this->supportedKeys["D"] = sf::Keyboard::Key::D;
//    this->supportedKeys["W"] = sf::Keyboard::Key::W;
//    this->supportedKeys["S"] = sf::Keyboard::Key::S;
}

void Application::initState()
{
    //this->states.push(new GameState(this->window, &this->supportedKeys));
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
}

Application::Application()
{
    this->initWindow();
    this->initKeys();
    this->initState();
}

Application::~Application()
{
    delete this->window;

    while (this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//void Application::updateSFMLEvents()
//{
//    while (this->window->pollEvent(this->event)) 
//    {
//        if (this->event.type == sf::Event::Closed)
//            this->window->close();
//    }
//}

void Application::processEvents() 
{
  while (this->window->pollEvent(this->event)) 
  {
    if (this->event.type == sf::Event::Closed) 
    {
      this->window->close();
    }
  }
}

void Application::update(sf::Time timePerFrame)
{
    if (!this->states.empty())
    {
        this->states.top()->update(this->timePerFrame);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        //this->endApplication();
        this->window->close();
    }
}

void Application::render() 
{
    this->window->clear();

    if (!this->states.empty())
    {
        this->states.top()->render();
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        //this->endApplication();
        this->window->close();
    }

    this->window->display();
}

//void Application::endApplication()
//{
//    std::cout << "End\n";
//}

//void Application::updateDt()
//{
//    this->dt = this->dtClock.restart().asSeconds();
//
//    system("cls");
//    std::cout << this->dt << "\n";
//}

void Application::run() {
  while (window->isOpen()) {
    deltaTime = clock.restart();
    timeSinceLastUpdate += deltaTime;
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      std::cout << timeSinceLastUpdate.asSeconds() << std::endl;
      processEvents();
      update(timePerFrame);
    }
    render();
  }
}