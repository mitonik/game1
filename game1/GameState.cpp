#include "GameState.hpp"

void GameState::initKeybinds()
{
//	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
//	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
//	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
//	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->initKeybinds();
}

GameState::~GameState()
{

}

void GameState::endState()
{
	this->window->close();
}

void GameState::updateInput(const sf::Time dt)
{
	this->checkForQuit();

	//player input

	player.update(dt);
}

void GameState::update(const sf::Time dt)
{
	this->UpdateMousePosition();
	this->updateInput(dt);
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->player.render(target);
}