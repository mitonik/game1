#include "PlayerOneChoseState.hpp"

PlayerOneChoseState::PlayerOneChoseState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, std::string x)
	: State(window, states) {
	font.loadFromFile("fonts/Lucid_Streams.otf");
	initButtons();
	int a = rand() % 2;
	std::string b = std::to_string(a);
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
		/*std::string back = x;
		std::string p_one = "1";
		states.push(std::shared_ptr<State>(new GameState(window, states, back, p_one)));*/
	}

	if (buttons["BACK"]->isPressed())
	{
		states.pop();
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
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		states.pop();
	}
}

void PlayerOneChoseState::initButtons()
{
	buttons["PLAYER_RED"] = new Button(50, 200, 200, 50,
		&font, "RED",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);

	buttons["BACK"] = new Button(100, window.getSize().y - 50, 150, 30,
		&font, "BACK",
		sf::Color::White, sf::Color::Red, sf::Color::Blue);
}
