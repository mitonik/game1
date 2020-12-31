#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Player {
 public:
  Player(sf::Vector2f bounds);
  sf::Sprite sprite;

  void update(const sf::Time dt);
  sf::Vector2f bounds;
  std::vector<Bullet> bullets;

 private:
  sf::Texture texture;

  float movementSpeed = 1000.f;
  float jumpSpeed = 2000.f;
  sf::Vector2f position;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
  bool isJumping = false;
  void move(sf::Vector2f velocity);

};