#pragma once
#include <string>
#include <list>
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"

class Player {
 public:
  Player(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key attack, Player& player2);

  void update(const sf::Time dt);
  void draw(sf::RenderWindow& window);

  sf::Sprite sprite;

  int health = 100;

 private:
  Player& player2;

  sf::Text text;
  sf::Font font;

  sf::Texture bulletTexture;

  std::list<Bullet> bullets;

  sf::Keyboard::Key left;
  sf::Keyboard::Key right;
  sf::Keyboard::Key up;
  sf::Keyboard::Key attack;

  sf::Texture texture;
  float movementSpeed = 1000.f;
  float jumpSpeed = 2000.f;
  bool isJumping = false;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
};