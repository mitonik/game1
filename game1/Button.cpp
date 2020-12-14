#include "Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Font* font, sf::String text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(25);
	this->text.setPosition(
		this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f - this->text.getGlobalBounds().width/2.f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height / 2.f);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
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
		this->text.setFillColor(this->idleColor);
		this->shape.setFillColor(sf::Color::Black);
		break;
	case BTN_HOVER:
		this->text.setFillColor(this->hoverColor);
		break;
	case BTN_PRESSED:
		this->text.setFillColor(this->activeColor);
		break;
	default:
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->text);
}