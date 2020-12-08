#include "Player.hpp"
#include <SFML/Graphics.hpp>

Player::Player()
{
	sprite.setScale(sf::Vector2f(3.f, 3.f));
	if (!texture.loadFromFile("textures/player.png")) {}
	sprite.setTexture(texture);
	movementSpeed = 500.f;
}

void Player::move(const float x, const float y) {
	sprite.move(x * movementSpeed, y * movementSpeed);
}

void Player::update(const sf::Time deltaTime)
{
	accelerationX = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		accelerationX -= movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		accelerationX += movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isJumping == false)
	{
		accelerationY = -jumpSpeed;
	}
	
	if (sprite.getPosition().y + sprite.getGlobalBounds().height < 800.f) {
		isJumping = true;
		accelerationY += 50.f;
	}
	if (sprite.getPosition().y + sprite.getGlobalBounds().height > 800.f) {
		isJumping = false;
		sprite.setPosition(sprite.getPosition().x, 800.f - sprite.getGlobalBounds().height);
		accelerationY = 0;
	}

	velocityX = accelerationX * deltaTime.asSeconds();
	velocityY = accelerationY * deltaTime.asSeconds();

	sprite.move(velocityX, velocityY);
}
