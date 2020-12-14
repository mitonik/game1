#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
	Bullet(sf::Vector2f position, float accelerationX, float accelerationY);
	void update(sf::Time dt);

private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f acceleration;
	size_t bullets = 0;
};
