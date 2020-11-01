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
  fps.setFont(arial);
  frametime.setFont(arial);
  frametime.setPosition(0, 25);
  x.setFont(arial);
  x.setPosition(0, 50);
  y.setFont(arial);
  y.setPosition(0, 75);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time TimePerFrame = sf::seconds(1.f / 120.f);
  while (window.isOpen()) {
    fps.setString("FPS: " + std::to_string(1000000.f / clock.getElapsedTime().asMicroseconds()));
    frametime.setString("Frametime: " + std::to_string(clock.getElapsedTime().asMicroseconds()));
    x.setString("X: " + std::to_string(player.getPosition().x));
    y.setString("Y: " + std::to_string(player.getPosition().y));
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
  if (key == sf::Keyboard::W)
    isJumping = isPressed;
  else if (key == sf::Keyboard::A)
    isMovingLeft = isPressed;
  else if (key == sf::Keyboard::D)
    isMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime) {
  playerAccelerationX = 0;
  if (isMovingLeft)
    playerAccelerationX -= playerSpeed;
  if (isMovingRight)
    playerAccelerationX += playerSpeed;
  if (isJumping)
    playerAccelerationY = -playerJump;
  if (player.getPosition().y + player.getGlobalBounds().height < GROUND_HEIGHT)
    playerAccelerationY += GRAVITY;
  if (player.getPosition().y + player.getGlobalBounds().height > GROUND_HEIGHT) {
    player.setPosition(player.getPosition().x, GROUND_HEIGHT - player.getGlobalBounds().height);
    playerAccelerationY = 0;
  }

  playerVelocityX = playerAccelerationX * deltaTime.asSeconds();
  playerVelocityY = playerAccelerationY * deltaTime.asSeconds();

  player.move(playerVelocityX, playerVelocityY);
}

void Game::render() {
  window.clear();
  window.draw(player);
  window.draw(fps);
  window.draw(frametime);
  window.draw(x);
  window.draw(y);
  window.display();
}