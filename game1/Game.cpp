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

void Game::initKeys()
{
//    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
//   this->supportedKeys["A"] = sf::Keyboard::Key::A;
//    this->supportedKeys["D"] = sf::Keyboard::Key::D;
//    this->supportedKeys["W"] = sf::Keyboard::Key::W;
//    this->supportedKeys["S"] = sf::Keyboard::Key::S;
}

void Game::initState()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
    //this->states.push(new MainMenuState(this->window, &this->supportedKeys));
}

Game::Game()
{
    this->initWindow();
    this->initKeys();
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

//void Game::updateSFMLEvents()
//{
//    while (this->window->pollEvent(this->event)) 
//    {
//        if (this->event.type == sf::Event::Closed)
//            this->window->close();
//    }
//}

void Game::processEvents() {
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    }
  }
}

void Game::update(sf::Time timePerFrame)
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
        //this->endApplication();
        this->window->close();
    }

    this->window->display();
}

//void Game::endApplication()
//{
//    std::cout << "End\n";
//}

//void Game::updateDt()
//{
//    this->dt = this->dtClock.restart().asSeconds();
//
//    system("cls");
//    std::cout << this->dt << "\n";
//}

void Game::run() {
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