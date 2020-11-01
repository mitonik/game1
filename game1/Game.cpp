#include "Game.h"
#include "Menu.h"
#include <string>

Game::Game():
  window(sf::VideoMode(1600, 900), "Game 1", sf::Style::Close),
  texture(),
  player()
  {
  window.setFramerateLimit(60);
  if(!texture.loadFromFile("textures/player.png")) {}
  player.setTexture(texture);
  player.setPosition(100.f, 100.f);
  player.setScale(3.f, 3.f);
  if (!arial.loadFromFile("fonts/arial.ttf")) {}
  frametime.setFont(arial);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time TimePerFrame = sf::seconds(1.f / 120.f);
  while (window.isOpen()) {
    frametime.setString("Frametime: " + std::to_string(clock.getElapsedTime().asMicroseconds()) + " X: " + std::to_string(player.getPosition().x) + " Y: " + std::to_string(player.getPosition().y));
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
    isJumping = isPressed;
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
  else if (key == sf::Keyboard::Escape)
  {
      Menu menu;
      window.close();
      menu.run(); //it will be pause menu
  }
}

void Game::update(sf::Time deltaTime) {
  sf::Vector2f movement(0.f, 0.f);
  if (isJumping)
    velocity -= PlayerJump;
  else if (player.getPosition().y + player.getGlobalBounds().height < groundHeight)
    velocity += GRAVITY;
  else if (player.getPosition().y + player.getGlobalBounds().height > groundHeight)
    velocity = 0;
    player.setPosition(player.getPosition().x, groundHeight - player.getGlobalBounds().height);
  /*if (isMovingDown)
    movement.y += PlayerSpeed;*/
  if (isMovingLeft)
    movement.x -= PlayerSpeed;
  if (isMovingRight)
    movement.x += PlayerSpeed;
  movement.y += velocity;
  player.move(movement * deltaTime.asSeconds());
}

void Game::render() {
  window.clear();
  window.draw(player);
  window.draw(frametime);
  window.display();
}