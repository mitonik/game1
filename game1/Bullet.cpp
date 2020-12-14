#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, float accelerationX, float accelerationY)
{
  texture.loadFromFile("textures/bullet.png");
  sprite.setTexture(texture);
  Bullet* bullets[100];
  for (size_t i = 0; i < 100; i++) {
    bullets[i] = NULL;
  }
}

void Bullet::update(sf::Time dt)
{
	/*for (size_t i = 0; i < 100; i++) {
		if (bullets[i] != NULL) {
		}
	}*/
}
