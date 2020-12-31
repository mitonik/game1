#include "Bullet.hpp"

Bullet::Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f acceleration) : texture(texture)
, position(position), acceleration(acceleration) {
  sprite.setTexture(texture);
}