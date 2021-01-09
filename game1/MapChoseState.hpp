#pragma once
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Application.hpp"
#include "Button.hpp"

class MapChose : public State {
public:
	MapChose(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states);
	~MapChose();

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

	sf::Sprite woods;
	sf::Sprite space;
	sf::Sprite cyberpunk;
	sf::Sprite machine;

	sf::Texture woodsText;
	sf::Texture spaceText;
	sf::Texture cyberpunkText;
	sf::Texture machineText;
};