#pragma once
#include<vector>
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity
{
protected:
	sf::Texture texture;
	sf::Sprite shape;
	float playerSpeed = 1000.f;
	float playerJump = 1000.f;
	float playerVelocityX = 0.f;
	float playerVelocityY = 0.f;
	float playerAccelerationX = 0.f;
	float playerAccelerationY = 0.f;

public:
	Entity();
	virtual ~Entity();

	virtual void move(const float x, const float y);

	virtual void update(const sf::Time dt);
	virtual void render(sf::RenderTarget* target);

};