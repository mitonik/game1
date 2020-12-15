#include "Application.hpp"
#include <fstream>
#include <iostream>
#include "MainMenuState.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 120.f);

Application::Application()
  : window(sf::VideoMode(1280, 720), "Game1", sf::Style::Default)
{
  window.setKeyRepeatEnabled(false);
  window.setVerticalSyncEnabled(true);
  states.push(new MainMenuState(window, states));
}

void Application::processInput() {
  sf::Event event;
  while (window.pollEvent(event)) {
    states.top()->handleEvent(event);
    if (event.type == sf::Event::Closed) {
      window.close();
    }
    else if (event.type == sf::Event::Resized) {
      sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
      window.setView(sf::View(visibleArea));
    }
  }
}

void Application::update(sf::Time dt) {
  states.top()->update(dt);
}

void Application::render() {
  window.clear();
  states.top()->draw();
  window.setView(window.getDefaultView());
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