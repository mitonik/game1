#include "MapChoseState.hpp"

MapChose::MapChose(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states) : State(window, states) {
	initButtons();
	int a = rand() % 4;
	std::string x = std::to_string(a);
	if (!backText.loadFromFile("textures/back" + x + ".png")) {
		std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
	}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);
	if (!machineText.loadFromFile("textures/back0.png")) {}
	if (!spaceText.loadFromFile("textures/back3.png")) {}
	if (!cyberpunkText.loadFromFile("textures/back2.png")) {}
	if (!woodsText.loadFromFile("textures/back1.png")) {}

	woods.setPosition(50,100);
	woods.setSize(sf::Vector2f(200, 200));
	woods.setTexture(&woodsText);

	cyberpunk.setPosition(500, 100);
	cyberpunk.setSize(sf::Vector2f(200, 200));
	cyberpunk.setTexture(&cyberpunkText);

	space.setPosition(50, 400);
	space.setSize(sf::Vector2f(200, 200));
	space.setTexture(&spaceText);

	machine.setPosition(500, 400);
	machine.setSize(sf::Vector2f(200, 200));
	machine.setTexture(&machineText);
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

	if (buttons["WOODS"]->isPressed()) 
	{
		std::string x = "1";
		states.push(std::shared_ptr<State>(new GameState(window, states, x)));
	}
	if (buttons["CYBERPUNK"]->isPressed())
	{
		std::string x = "2";
		states.push(std::shared_ptr<State>(new GameState(window, states, x)));
	}
	if (buttons["SPACE"]->isPressed())
	{
		std::string x = "3";
		states.push(std::shared_ptr<State>(new GameState(window, states, x)));
	}
	if (buttons["MACHINE"]->isPressed())
	{
		std::string x = "0";
		states.push(std::shared_ptr<State>(new GameState(window, states, x)));
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
	window.draw(woods);
	window.draw(cyberpunk);
	window.draw(space);
	window.draw(machine);
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
	buttons["WOODS"] = new Button(50, 150, 200, 50,
		&font, "WOODS",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["CYBERPUNK"] = new Button(500, 150, 200, 50,
		&font, "CYBERPUNK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["SPACE"] = new Button(50, 450, 200, 50,
		&font, "SPACE",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["MACHINE"] = new Button(500, 450, 200, 50,
		&font, "MACHINE",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["BACK"] = new Button(100, window.getSize().y - 50, 150, 30,
		&font, "BACK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);
}