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

void Game::initState()
{
    this->states.push(new GameState(this->window));
}

Game::Game()
{
    this->initWindow();
    this->initState();
}

Game::~Game()
{
    delete this->window;

    while (this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
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

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render() 
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
        this->endApplication();
        this->window->close();
    }

    this->window->display();
}

void Game::endApplication()
{
    std::cout << "End\n";
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