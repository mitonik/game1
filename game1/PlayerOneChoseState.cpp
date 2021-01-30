#include "PlayerOneChoseState.hpp"

PlayerOneChoseState::PlayerOneChoseState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, std::string b)
	: State(window, states) {
	font.loadFromFile("fonts/Lucid_Streams.otf");
	initButtons();
	if (!backText.loadFromFile("textures/back" + b + ".png")) {
		std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
	}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);

	logo.setFont(font);
	logo.setString("Chose Player One");
	logo.setCharacterSize(50);
	logo.setPosition((window.getSize().x / 2) - 300, 20);

	i = b;
}

void PlayerOneChoseState::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void PlayerOneChoseState::updateButtons()
{
	for (auto& it : buttons) {
		it.second->update(mousePosView);
	}
}

void PlayerOneChoseState::update(const sf::Time dt)
{
	updateMousePosition();
	updateButtons();
	if (buttons["PLAYER_RED"]->isPressed())
	{
		std::string p_one = "1";
		states.push(std::shared_ptr<State>(new PlayerTwoChoseState(window, states, i, p_one)));
	}
	if (buttons["PLAYER_BLUE"]->isPressed())
	{
		std::string p_two = "2";
		states.push(std::shared_ptr<State>(new PlayerTwoChoseState(window, states, i, p_two)));
	}
}

void PlayerOneChoseState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : buttons) {
		it.second->render(target);
	}
}

void PlayerOneChoseState::draw()
{
	window.draw(background);
	window.draw(logo);
	renderButtons(window);
}

void PlayerOneChoseState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape || buttons["BACK"]->isPressed())
	{
		states.pop();
	}
}

void PlayerOneChoseState::initButtons()
{
	buttons["PLAYER_RED"] = new Button(50, 200, 200, 50,
		&font, "RED",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["PLAYER_BLUE"] = new Button(window.getSize().x - 250, 200, 200, 50,
		&font, "BLUE",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["BACK"] = new Button(100, window.getSize().y - 50, 150, 30,
		&font, "BACK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);
}