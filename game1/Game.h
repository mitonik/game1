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
  sf::Text frametime;
  bool isMovingUp = false;
  bool isMovingDown = false;
  bool isMovingLeft = false;
  bool isMovingRight = false;
  float PlayerSpeed = 1000.f;
};