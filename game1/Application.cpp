#include "Application.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include <fstream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

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

void Application::processInput() {
  sf::Event event;
  while (window->pollEvent(event)) {
    states.top()->handleEvent(event);
    if (event.type == sf::Event::Closed) {
      window->close();
    }
  }
}

void Application::update(sf::Time dt) {
  /*if (!states.empty()) {
    states.top()->update(TimePerFrame);
    if (states.top()->getQuit()) {
      states.top()->endState();
      delete states.top();
      states.pop();
    }
  }
  else {
    window->close();
  }*/
  states.top()->update(dt);
}

void Application::render() {
  window->clear();
  states.top()->render();
  window->display();
}

void Application::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window->isOpen()) {
    sf::Time dt = clock.restart();
    timeSinceLastUpdate += dt;
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;
      processInput();
      update(TimePerFrame);
    }
    //std::cout << timeSinceLastUpdate.asSeconds() << std::endl;
    render();
  }
}