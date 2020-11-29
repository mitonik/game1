#include "State.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::chechForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		//this->quit = true;
		this->window->close();
	}
}

void State::UpdateMousePosition()
{
	this->mausePosScreen = sf::Mouse::getPosition();
	this->mausePosWindow = sf::Mouse::getPosition(*this->window);
	this->mausePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
