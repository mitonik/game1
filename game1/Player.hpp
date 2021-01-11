#pragma once
#include <string>
#include <list>
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"

class Player {
 public:
  Player(sf::Vector2f startPos, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key attack, sf::Keyboard::Key attack2, Player& player2);

  void update(const sf::Time dt);
  void draw(sf::RenderWindow& window);

  sf::Sprite sprite;

  int health = 100;

 private:
  enum lastDirection
  {
    leftDir,
    rightDir
  };

  int lastDir;

  Player& player2;

  sf::Text text;
  sf::Font font;

  sf::Sprite passive;

  sf::Clock clock;
  sf::Time timeSinceLastUpdate;
  sf::Time timeSinceLastUpdateSpecial;

  sf::Texture bulletTexture;

  std::list<Bullet> bullets;

  sf::Keyboard::Key left;
  sf::Keyboard::Key right;
  sf::Keyboard::Key up;
  sf::Keyboard::Key attack;
  sf::Keyboard::Key attack2;

  sf::Texture texture;
  float movementSpeed = 1000.f;
  float jumpSpeed = 2000.f;
  bool isJumping = false;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
};