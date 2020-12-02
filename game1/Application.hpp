#pragma once
#include <map>
#include "MainMenuState.hpp"

class Application {
public:
	Application();
	~Application();
	void run();

private:
	void processEvents();
	void update(sf::Time timePerFrame);
	void render();
	void initWindow();
	void initState();
	//void initKeys();

	sf::RenderWindow* window;
	sf::Event event;

	sf::Clock clock;

	sf::Time deltaTime;
	const sf::Time timePerFrame = sf::seconds(1.f / 120.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;
};
