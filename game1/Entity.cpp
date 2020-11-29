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

void Entity::move(const sf::Time dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt.asSeconds(), dir_y * this->movementSpeed * dt.asSeconds());
}

void Entity::update(const sf::Time dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
