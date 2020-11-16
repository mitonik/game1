#include "Entity.h"

Entity::Entity()
{
	this->shape.setScale(sf::Vector2f(3.f, 3.f));
	if (!texture.loadFromFile("textures/player.png")) {}
	this->shape.setTexture(texture);
	this->movementSpeed = 500.f;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(dt, 0.f, 1.f);
	}
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
