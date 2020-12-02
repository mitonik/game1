#include "Application.hpp"
#include <iostream>
#include <fstream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

void Application::initWindow() {
  std::ifstream ifs("config/window.ini");
  std::string title = "game1";
  sf::VideoMode window_bounds(1600, 900);
  unsigned int framerate_limit = 60;
  bool vertival_sync_enabled = false;
  if (ifs.is_open()) {
    std::getline(ifs, title);
    ifs >> window_bounds.width >> window_bounds.height;
    ifs >> framerate_limit;
    ifs >> vertival_sync_enabled;
  }
  ifs.close();
  window = new sf::RenderWindow(window_bounds, title, sf::Style::Close);
  window->setFramerateLimit(framerate_limit);
  window->setVerticalSyncEnabled(vertival_sync_enabled);
}

//void Application::initKeys() {
//  this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
//  this->supportedKeys["A"] = sf::Keyboard::Key::A;
//  this->supportedKeys["D"] = sf::Keyboard::Key::D;
//  this->supportedKeys["W"] = sf::Keyboard::Key::W;
//  this->supportedKeys["S"] = sf::Keyboard::Key::S;
//}

void Application::initState() {
  //this->states.push(new GameState(this->window, &this->supportedKeys));
  states.push(new MainMenuState(this->window, &this->states));
}

Application::Application() {
  initWindow();
  //initKeys();
  initState();
}

Application::~Application() {
  delete window;
  while (states.empty()) {
    delete states.top();
    states.pop();
  }
}

void Application::processEvents() {
  while (window->pollEvent(event)) {
    /*if (event.type == sf::Event::Closed) {
      window->close();
    }*/
  }
}

void Application::update(sf::Time timePerFrame) {
  if (!states.empty()) {
    states.top()->update(timePerFrame);
    if (states.top()->getQuit()) {
      states.top()->endState();
      delete states.top();
      states.pop();
    }
  }
  else {
    window->close();
  }
}

void Application::render() {
  window->clear();
  states.top()->render();
  window->display();
}

void Application::run() {
  while (window->isOpen()) {
    deltaTime = clock.restart();
    timeSinceLastUpdate += deltaTime;
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      processEvents();
      update(timePerFrame);
    }
    std::cout << timeSinceLastUpdate.asSeconds() << std::endl;
    render();
  }
}