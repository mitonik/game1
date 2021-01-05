#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include <iostream>

class Player {
 public:
  Player(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key attack, sf::Vector2f bounds);

  void update(const sf::Time dt);
  void draw(sf::RenderWindow& window);

  sf::Vector2f bounds;
  sf::CircleShape bullet;
  sf::Sprite sprite;
 private:

  enum lastDirection {
    leftDir,
    rightDir
  };

  sf::Keyboard::Key left;
  sf::Keyboard::Key right;
  sf::Keyboard::Key up;
  sf::Keyboard::Key attack;

  sf::Texture texture1;
  sf::Texture texture2;
  sf::Texture texture3;
  sf::Texture texture4;

  sf::Clock clock;


  float movementSpeed = 1000.f;
  float jumpSpeed = 2000.f;
  bool isJumping = false;

  sf::Vector2f velocity;
  sf::Vector2f acceleration;

  int lastDirection;

};