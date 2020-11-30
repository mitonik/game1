#pragma once
#include<map>
#include "MainMenuState.hpp"

class Application {
public:

	Application();
	virtual ~Application();

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