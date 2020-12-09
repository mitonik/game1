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

	this->buttons["GAME_SET"] = new Button(100, 200, 1, 1, sf::Color::Blue, sf::Color::White, sf::Color::Blue);

	this->buttons["GAME_EXIT"] = new Button(100, 300, 1, 1, sf::Color::Red, sf::Color::White, sf::Color::Blue);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->initKeybinds();
	this->initButtons();

	this->backText = backText;

	this->background.setScale(sf::Vector2f(5, 5));
	//this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->background.setFillColor(sf::Color::Green);
	if (!backText.loadFromFile("textures/back.png"))
	{
		std::cout << "ERROR::LOADING BUTTONS TEXTURES\n";
	}
	this->background.setTexture(backText);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

//void MainMenuState::endState()
//{
//	this->window->close();
//}

//void MainMenuState::updateInput(const sf::Time dt)
//{
//	this->checkForQuit();
//
//	//player input
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
//	{
//
//	}
//}

void MainMenuState::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

//void MainMenuState::checkForQuit() {
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//		//this->quit = true;
//		//this->states.push(new MainMenuState(this->window, &this->states));
//		this->window->close();
//	}
//}

void MainMenuState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void MainMenuState::update(const sf::Time dt)
{
	this->updateMousePosition();
	//this->updateInput(dt);

	this->updateButtons();

	//std::cout << this->mousePosView.x << " " << this->mousePosView.x << "\n";
	if (this->buttons["GAME_SET"]->isPressed())
	{
		states->pop();
		this->states->push(new Settings(this->window, this->states));
	}
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		states->pop();
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

void MainMenuState::draw()
{
	window->draw(this->background);
	this->renderButtons(window);
}

void MainMenuState::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		window->close();
	}
}