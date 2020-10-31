#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
	Menu();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);
private:
	sf::RenderWindow window;
	sf::Texture texture_button2;
	sf::Texture textureback;
	sf::Texture texture_button;
	sf::Sprite button;
	sf::Sprite button2;
	sf::Sprite player;
	sf::Sprite back;
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
	float PlayerSpeed = 1000.f;
};