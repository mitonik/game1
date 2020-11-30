#include "MainMenuState.hpp"

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

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
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

void MainMenuState::updateInput(const sf::Time dt)
{
	this->checkForQuit();

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

void MainMenuState::update(const sf::Time dt)
{
	this->UpdateMousePosition();
	this->updateInput(dt);

	this->upadateButtons();

	//std::cout << this->mausePosView.x << " " << this->mausePosView.x << "\n";
	//std::cout << this->buttons["GAME_EXIT"]->isPressed()<<"\n";
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));
	}

	if (this->buttons["GAME_EXIT"]->isPressed())
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