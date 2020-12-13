#pragma once
#include <stack>
#include "SFML/Graphics/RenderWindow.hpp"

class State
{
protected:
	sf::RenderWindow* window;
	std::stack<State*>* states;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);

	virtual void update(const sf::Time dt) = 0;
	virtual void draw() = 0;
	virtual void handleEvent(const sf::Event& event) = 0;
};
