#include "Game.h"

void Game::initWindow()
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

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent)) 
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render() 
{
  this->window->clear();

  this->window->display();
}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << "\n";
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}