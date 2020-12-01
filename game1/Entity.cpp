#include "Entity.hpp"
#include <SFML/Graphics.hpp>

Player::Player()
{
	this->sprite.setScale(sf::Vector2f(3.f, 3.f));
	if (!texture.loadFromFile("textures/player.png")) {}
	this->sprite.setTexture(texture);
	this->speed = 500.f;
}

//Player::~Player()
//{
//}

void Player::move(const float x, const float y) {
	this->sprite.move(x * this->speed, y * this->speed);
}

void Player::update(const sf::Time deltaTime)
{
	this->accelerationX = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->accelerationX -= this->speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->accelerationX += this->speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isJumping == false)
	{
		this->accelerationY = -this->jump;
	}
	
	if (this->sprite.getPosition().y + this->sprite.getGlobalBounds().height < 800.f) {
		isJumping = true;
		accelerationY += 50.f;
	}
	if (this->sprite.getPosition().y + this->sprite.getGlobalBounds().height > 800.f) {
		isJumping = false;
		this->sprite.setPosition(this->sprite.getPosition().x, 800.f - this->sprite.getGlobalBounds().height);
		this->accelerationY = 0;
	}

	this->velocityX = this->accelerationX * deltaTime.asSeconds();
	this->velocityY = this->accelerationY * deltaTime.asSeconds();

	this->sprite.move(velocityX, velocityY);
}

//void Player::render(sf::RenderTarget* target)
//{
//	target->draw(this->sprite);
//}
