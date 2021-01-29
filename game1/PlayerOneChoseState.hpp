#pragma once
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Application.hpp"
#include "Button.hpp"
#include "MapChoseState.hpp"

class PlayerOneChoseState : public State {
public:
	PlayerOneChoseState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, std::string x);

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
	sf::Text logo;
	std::map<std::string, Button*> buttons;
	//void initKeybinds();
	void initButtons();

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
};

