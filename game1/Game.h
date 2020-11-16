#pragma once
#include "state.h"

class Game {
public:

	Game();
	virtual ~Game();

	void updateDt();
	void run();
	void updateSFMLEvents();
	void update();
	void render();

private:
	void initWindow();

	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;
};