#include "Bullet.hpp"

Bullet::Bullet(sf::Texture& texture, sf::Vector2f startPos, sf::Vector2f direction)
    : direction(direction) {
  sprite.setTexture(texture);
  sprite.setPosition(startPos);
}

void Bullet::update(const sf::Time dt) {
  sprite.setPosition(sprite.getPosition() + direction * dt.asSeconds());
}