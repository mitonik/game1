#pragma once
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Application.hpp"
#include "Button.hpp"

class MapChose : public State {
public:
	MapChose(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states);

	void updateMousePosition();
	void updateButtons();
	void update(const sf::Time dt);
	void renderButtons(sf::RenderTarget& target);
	void draw();
	void handleEvent(const sf::Event& event);

private:
	sf::Sprite background;
	sf::Texture backText;
	sf::Font font;
	std::map<std::string, Button*> buttons;
	//void initKeybinds();
	void initButtons();

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::RectangleShape woods;
	sf::RectangleShape space;
	sf::RectangleShape cyberpunk;
	sf::RectangleShape machine;
	sf::RectangleShape safara;
	sf::RectangleShape hight;

	sf::Texture woodsText;
	sf::Texture spaceText;
	sf::Texture cyberpunkText;
	sf::Texture machineText;
	sf::Texture safaraText;
	sf::Texture hightText;
};