#include "Settings.hpp"

void Settings::initButtons()
{
	this->buttons["GAME_MENU"] = new Button(100, 100, 1, 1, sf::Color::Green, sf::Color::White, sf::Color::Blue);
}

Settings::Settings(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
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

Settings::~Settings()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void Settings::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

//void Settings::checkForQuit()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//		//this->quit = true;
//		//this->states.push(new MainMenuState(this->window, &this->states));
//		this->window->close();
//	}
//}

//void Settings::endState()
//{
//	this->window->close();
//}

//void Settings::updateInput(const sf::Time dt)
//{
//	this->checkForQuit();
//}

void Settings::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void Settings::update(const sf::Time dt)
{
	this->updateMousePosition();
	//this->updateInput(dt);

	this->updateButtons();

	//std::cout << this->mousePosView.x << " " << this->mousePosView.x << "\n";

	if (this->buttons["GAME_MENU"]->isPressed())
	{
		this->states->push(new MainMenuState(this->window, this->states));

	}
}

void Settings::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Settings::render()
{
	window->draw(this->background);
	this->renderButtons(window);
}

void Settings::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		window->close();
	}
}