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

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
private:
	short unsigned buttonState;
	bool pressed;
	bool hover;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height, sf::Font* font, sf::String text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();


	//Accessors
	bool isPressed();

	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};