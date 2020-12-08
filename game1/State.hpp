#ifndef STATE_H
#define STATE_H

#include "Player.hpp"

#include <SFML/Graphics.hpp>

class State
{
protected:
	sf::RenderWindow* window;
	std::stack<State*>* states;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);

	virtual void update(const sf::Time dt) = 0;
	virtual void render() = 0;
	virtual void handleEvent(const sf::Event& event) = 0;
};

#endif