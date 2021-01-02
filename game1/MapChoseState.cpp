#include "MapChoseState.hpp"

MapChose::MapChose(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states) : State(window, states) {
	initButtons();
	int a = rand() % 3;
	std::string x = std::to_string(a);
	if (!backText.loadFromFile("textures/back" + x + ".png")) {
		std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
	}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);
}

MapChose::~MapChose()
{
}

void MapChose::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void MapChose::updateButtons()
{
	for (auto& it : buttons) {
		it.second->update(mousePosView);
	}
}

void MapChose::update(const sf::Time dt)
{
	updateMousePosition();
	updateButtons();

	if (buttons["NEXT"]->isPressed()) 
	{
		states.push(std::shared_ptr<State>(new GameState(window, states)));
	}
	if (buttons["BACK"]->isPressed()) 
	{
		states.pop();
	}
}

void MapChose::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : buttons) {
		it.second->render(target);
	}
}

void MapChose::draw()
{
	window.draw(background);
	renderButtons(window);
}

void MapChose::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		states.pop();
	}
}

void MapChose::initButtons()
{
	font.loadFromFile("fonts/Lucid_Streams.otf");
	buttons["NEXT"] = new Button(window.getSize().x - 250, window.getSize().y - 50, 150, 30,
		&font, "Next",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["BACK"] = new Button(100, window.getSize().y - 50, 150, 30,
		&font, "BACK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);
}
