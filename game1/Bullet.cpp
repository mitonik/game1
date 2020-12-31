#include "Bullet.hpp"

Bullet::Bullet() {
  texture.loadFromFile("textures/player.png");
  sprite.setTexture(texture);
}