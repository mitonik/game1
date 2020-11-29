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

enum button_stetes{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
private:
	short unsigned buttonState;
	bool pressed;
	bool hover;

	sf::Sprite shape;
	sf::Texture textButton;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();


	//Accessors
	const bool isPessed() const;

	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};