#include "MapChoseState.hpp"

MapChose::MapChose(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states) : State(window, states) {
	initButtons();
	if (!backText.loadFromFile("textures/back2.png")) {
		std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
	}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);
	if (!machineText.loadFromFile("textures/back0.png")) {}
	if (!spaceText.loadFromFile("textures/back3.png")) {}
	if (!cyberpunkText.loadFromFile("textures/back2.png")) {}
	if (!woodsText.loadFromFile("textures/back1.png")) {}
	if (!woodsText.loadFromFile("textures/back1.png")) {}
	if (!safaraText.loadFromFile("textures/back4.png")) {}
	if (!hightText.loadFromFile("textures/back5.png")) {}
	
	sf::Vector2f sizeText = sf::Vector2f(320, 180);

	woods.setPosition(50,100);
	woods.setSize(sizeText);
	woods.setTexture(&woodsText);

	cyberpunk.setPosition(sf::Vector2f((window.getSize().x / 2) - 160, 100));
	cyberpunk.setSize(sizeText);
	cyberpunk.setTexture(&cyberpunkText);

	space.setPosition(50, 400);
	space.setSize(sizeText);
	space.setTexture(&spaceText);

	machine.setPosition(sf::Vector2f((window.getSize().x/2) - 160, 400));
	machine.setSize(sizeText);
	machine.setTexture(&machineText);

	hight.setPosition(sf::Vector2f(window.getSize().x - 370, 100));
	hight.setSize(sizeText);
	hight.setTexture(&hightText);

	safara.setPosition(sf::Vector2f(window.getSize().x - 370, 400));
	safara.setSize(sizeText);
	safara.setTexture(&safaraText);

	logo.setFont(font);
	logo.setString("Chose Map");
	logo.setCharacterSize(50);
	logo.setPosition((window.getSize().x/2) - 150, 20);
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
	window.draw(safara);
	window.draw(hight);
	window.draw(logo);
	renderButtons(window);
}

void MapChose::handleEvent(const sf::Event& event)
{
	if (buttons["WOODS"]->isPressed())
	{
		std::string x = "1";
		states.push(std::shared_ptr<State>(new PlayerOneChoseState(window, states, x)));
	}
	if (buttons["CYBERPUNK"]->isPressed())
	{
		std::string x = "2";
		states.push(std::shared_ptr<State>(new PlayerOneChoseState(window, states, x)));
	}
	if (buttons["SPACE"]->isPressed())
	{
		std::string x = "3";
		states.push(std::shared_ptr<State>(new PlayerOneChoseState(window, states, x)));
	}
	if (buttons["MACHINE"]->isPressed())
	{
		std::string x = "0";
		states.push(std::shared_ptr<State>(new PlayerOneChoseState(window, states, x)));
	}
	if (buttons["SAFARA"]->isPressed())
	{
		std::string x = "4";
		states.push(std::shared_ptr<State>(new PlayerOneChoseState(window, states, x)));
	}
	if (buttons["HIGHT"]->isPressed())
	{
		std::string x = "5";
		states.push(std::shared_ptr<State>(new PlayerOneChoseState(window, states, x)));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape || buttons["BACK"]->isPressed())
	{
		states.pop();
	}
}

void MapChose::initButtons()
{
	font.loadFromFile("fonts/Lucid_Streams.otf");
	buttons["WOODS"] = new Button(50, 200, 200, 50,
		&font, "WOODS",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["CYBERPUNK"] = new Button((window.getSize().x / 2) - 140, 200, 200, 50,
		&font, "CYBERPUNK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["SPACE"] = new Button(50, 500, 200, 50,
		&font, "SPACE",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["MACHINE"] = new Button((window.getSize().x / 2) - 140, 500, 200, 50,
		&font, "MACHINE",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["SAFARA"] = new Button(window.getSize().x - 350, 500, 200, 50,
		&font, "SAFARA",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["HIGHT"] = new Button(window.getSize().x - 330, 200, 200, 50,
		&font, "HIGHT GROUND",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["BACK"] = new Button(100, window.getSize().y - 50, 150, 30,
		&font, "BACK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);
}