#pragma once
#include <stack>
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "MainMenuState.hpp"
#include "State.hpp"

class Application {
public:
	Application();
	void run();

private:
	void processInput();
	void update(sf::Time TimePerFrame);
	void render();
	//void initWindow();
	//void initState();

	sf::RenderWindow window;
	static const sf::Time TimePerFrame;
	//std::vector<sf::VideoMode> videoModes;
	//bool fullscreen;

	std::stack<State*> states;
};