#include "Entity.h"

Entity::Entity()
{
	this->shape.setScale(sf::Vector2f(3.f, 3.f));
	if (!texture.loadFromFile("textures/player.png")) {}
	this->shape.setTexture(texture);
	this->playerSpeed = 500.f;
}

Entity::~Entity()
{
}

void Entity::move(const float x, const float y) {
	this->shape.move(x * this->playerSpeed, y * this->playerSpeed);
}

void Entity::update(const sf::Time deltaTime)
{
	this->playerAccelerationX = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->playerAccelerationX -= this->playerSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->playerAccelerationX += this->playerSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->playerAccelerationY = -this->playerJump;
	}
	if (this->shape.getPosition().y + this->shape.getGlobalBounds().height < 800.f)
		playerAccelerationY += 100.f;
	if (this->shape.getPosition().y + this->shape.getGlobalBounds().height > 800.f) {
		this->shape.setPosition(this->shape.getPosition().x, 800.f - this->shape.getGlobalBounds().height);
		this->playerAccelerationY = 0;
	}

	this->playerVelocityX = this->playerAccelerationX * deltaTime.asSeconds();
	this->playerVelocityY = this->playerAccelerationY * deltaTime.asSeconds();

	this->shape.move(playerVelocityX, playerVelocityY);
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
