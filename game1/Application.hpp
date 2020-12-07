#pragma once
#include <map>
#include <stack>

#include "State.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Application {
public:
	Application();
	~Application();
	void run();

private:
	void processInput();
	void update(sf::Time TimePerFrame);
	void render();
	void initWindow();
	void initState();
	//void initKeys();

	sf::RenderWindow* window;
	static const sf::Time TimePerFrame;

	std::stack<State*> states;

	//std::map<std::string, int> supportedKeys;
};
