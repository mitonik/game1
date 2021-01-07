#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System/Time.hpp"

class Bullet {
 public:
  Bullet(sf::Texture& texture, sf::Vector2f startPos, sf::Vector2f direction);

  void update(const sf::Time dt);

  sf::Sprite sprite;
 private:
  sf::Vector2f direction;
};