#include "Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setScale(sf::Vector2f(width, height));
	this->textButton = textButton;
	if (!textButton.loadFromFile("textures/enter.png")) 
	{
		std::cout << "ERROR::LOANDING BUTTONS TEXTURES\n";
	}
	this->shape.setTexture(textButton);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setColor(this->idleColor);
}

Button::~Button()
{
}

bool Button::isPressed()
{
	if (this->buttonState == BTN_PRESSED)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Button::update(const sf::Vector2f mousePos) //update buttons for hover and press
{
	this->buttonState = BTN_IDLE;

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->shape.setColor(this->hoverColor);
		break;
	case BTN_PRESSED:
		this->shape.setColor(this->activeColor);
		break;
	default:
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}