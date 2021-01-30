#include "PlayerTwoChoseState.hpp"

PlayerTwoChoseState::PlayerTwoChoseState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, std::string b, std::string p_one)
: State(window, states) {
	font.loadFromFile("fonts/Lucid_Streams.otf");
	initButtons();
	int a = rand() % 2;
	std::string x = std::to_string(a);
	if (!backText.loadFromFile("textures/back" + x + ".png")) {
		std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
	}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);

	logo.setFont(font);
	logo.setString("Chose Player Two");
	logo.setCharacterSize(50);
	logo.setPosition((window.getSize().x / 2) - 300, 20);

	i = b;
	j = p_one;
	std::cout << i << "\n" << j;
}

void PlayerTwoChoseState::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void PlayerTwoChoseState::updateButtons()
{
	for (auto& it : buttons) {
		it.second->update(mousePosView);
	}
}

void PlayerTwoChoseState::update(const sf::Time dt)
{
	updateMousePosition();
	updateButtons();
	if (buttons["PLAYER_RED"]->isPressed())
	{
		std::cout << i << "\n" << j;
		std::string p_two = "1";
		states.push(std::shared_ptr<State>(new GameState(window, states, i, j, p_two)));
	}
}

void PlayerTwoChoseState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : buttons) {
		it.second->render(target);
	}
}

void PlayerTwoChoseState::draw()
{
	window.draw(background);
	window.draw(logo);
	renderButtons(window);
}

void PlayerTwoChoseState::handleEvent(const sf::Event& event)
{
	if (buttons["BACK"]->isPressed())
	{
		states.pop();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	{
		states.pop();
	}
}

void PlayerTwoChoseState::initButtons()
{
	buttons["PLAYER_RED"] = new Button(50, 300, 200, 50,
		&font, "RED",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["BACK"] = new Button(100, window.getSize().y - 50, 150, 30,
		&font, "BACK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);
}
