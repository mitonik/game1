#pragma once
#include "Gamestate.h"
#include "MainMenuState.h"

class Game {
public:

	Game();
	virtual ~Game();

	//void endApplication();
	//void updateDt();
	void run();
	//void updateSFMLEvents();
	void processEvents();
	void update(sf::Time timePerFrame);
	void render();

private:
	void initWindow();
	void initState();
	void initKeys();

	sf::RenderWindow* window;
	sf::Event event;

	sf::Clock clock;

	sf::Time deltaTime;
	const sf::Time timePerFrame = sf::seconds(1.f / 120.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;
};