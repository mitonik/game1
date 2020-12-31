#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
	Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f acceleration);

	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f acceleration;

private:
	sf::Texture& texture;
};