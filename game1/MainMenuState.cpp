#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Button.hpp"

void MainMenuState::initKeybinds()
{
	//	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	//	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	//	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	//	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(100, 100, 1, 1, sf::Color::Green, sf::Color::White, sf::Color::Blue);

	this->buttons["GAME_EXIT"] = new Button(100, 200, 1, 1, sf::Color::Red, sf::Color::White, sf::Color::Blue);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->background.setFillColor(sf::Color::Green);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
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

void MainMenuState::upadateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mausePosView);
	}
}

void MainMenuState::update(const float& dt)
{
	this->UpdateMousePosition();
	this->updateInput(dt);

	this->upadateButtons();

	system("cls");
	std::cout << this->mausePosView.x << " " << this->mausePosView.x << "\n";

	if (this->buttons["GAME_EXIT"]->isPessed())
	{
		this->window->close();
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);
}