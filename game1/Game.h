#pragma once
#include "Gamestate.h"
#include "MainMenuState.h"

class Game {
public:

	Game();
	virtual ~Game();

	void endApplication();
	void updateDt();
	void run();
	void updateSFMLEvents();
	void update();
	void render();

private:
	void initWindow();
	void initState();
	void initKeys();

	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;
};