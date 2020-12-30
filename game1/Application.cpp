#include "Application.hpp"
#include <fstream>
#include <iostream>
#include "MainMenuState.hpp"
#include "GameState.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 120.f);

Application::Application()
  : window(sf::VideoMode(1280, 720), "Game1", sf::Style::Close) {
  std::ifstream ifs("config/window.ini");
  std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
  std::string title = "Game1";
  sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
  bool fullscreen = false;
  unsigned int framerate_limit = 120;
  bool vertival_sync_enabled = false;
  unsigned antialiasing_level = 0;
  if (ifs.is_open()) {
    std::getline(ifs, title);
    ifs >> window_bounds.width >> window_bounds.height;
    ifs >> fullscreen;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
    ifs >> framerate_limit;
    ifs >> vertival_sync_enabled;
    ifs >> antialiasing_level;
  }
  ifs.close();
  sf::ContextSettings window_settings;
  window_settings.antialiasingLevel = antialiasing_level;

  if (fullscreen) {
    window.close();
    window.create(window_bounds, title, sf::Style::Fullscreen, window_settings);
  } else {
    window.close();
    window.create(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, window_settings);
  }
  window.setFramerateLimit(framerate_limit);
  window.setVerticalSyncEnabled(vertival_sync_enabled);
  window.setKeyRepeatEnabled(false);
  states.push(new MainMenuState(window, states));
}

void Application::processInput() {
  sf::Event event;
  while (window.pollEvent(event)) {
    states.top()->handleEvent(event);
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void Application::update(sf::Time dt) {
  states.top()->update(dt);
}

void Application::render() {
  window.clear();
  states.top()->draw();
  window.display();
}

void Application::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window.isOpen()) {
    sf::Time dt = clock.restart();
    timeSinceLastUpdate += dt;
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;
      processInput();
      update(TimePerFrame);
    }
    render();
  }
}