#include "MainMenuState.hpp"
#include "GameState.hpp"

void MainMenuState::initKeybinds()
{
	//	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	//	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	//	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	//	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Green);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
	this->window->close();
}

void MainMenuState::updateInput(const float& dt)
{
	this->chechForQuit();

	//player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

	}
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);
}