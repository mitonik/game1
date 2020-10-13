#include "Game.h"

Game::Game() : window(sf::VideoMode(1280, 720), "Game 1", sf::Style::Close), texture(), player() {
  window.setFramerateLimit(60);
  if(!texture.loadFromFile("player.png")) {}
  player.setTexture(texture);
  player.setPosition(100.f, 100.f);
  player.setScale(3.f, 3.f);
}

void Game::run() {
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

void Game::processEvents() {
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

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W) {
    isMovingUp = isPressed;
  }
  else if (key == sf::Keyboard::S) {
    isMovingDown = isPressed;
  }
  else if (key == sf::Keyboard::A) {
    isMovingLeft = isPressed;
  }
  else if (key == sf::Keyboard::D) {
    isMovingRight = isPressed;
  }
}

void Game::update(sf::Time deltaTime) {
  sf::Vector2f movement(0.f, 0.f);
  if (isMovingUp)
    movement.y -= PlayerSpeed;
  if (isMovingDown)
    movement.y += PlayerSpeed;
  if (isMovingLeft)
    movement.x -= PlayerSpeed;
  if (isMovingRight)
    movement.x += PlayerSpeed;
  player.move(movement * deltaTime.asSeconds());
}

void Game::render() {
  window.clear();
  window.draw(player);
  window.display();
}