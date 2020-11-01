#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void run();

private:
  void processEvents();
  void update(sf::Time);
  void render();
  void handlePlayerInput(sf::Keyboard::Key, bool);
private:
  sf::RenderWindow window;
  sf::Texture texture;
  sf::Sprite player;
  sf::Font arial;
  sf::Text fps;
  sf::Text frametime;
  sf::Text x;
  sf::Text y;

  float GROUND_HEIGHT = 800.f;
  float GRAVITY = 100.f;

  bool isMovingLeft = false;
  bool isMovingRight = false;
  bool isJumping = false;
  float playerSpeed = 1000.f;
  float playerJump = 1000.f;
  float playerVelocityX = 0.f;
  float playerVelocityY = 0.f;
  float playerAccelerationX = 0.f;
  float playerAccelerationY = 0.f;
};