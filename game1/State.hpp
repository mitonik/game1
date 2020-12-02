#ifndef STATE_H
#define STATE_H

#include "Player.hpp"

#include <SFML/Graphics.hpp>

class State
{
protected:
	sf::RenderWindow* window;

	std::stack<State*>* states;

	//std::map<std::string, int>* supportedKeys;
	//std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	//resources
	std::vector<sf::Texture> textures;

	virtual void initKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::stack<State*>* states);

	bool getQuit();

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateMousePosition();
	virtual void updateInput(const sf::Time dt) = 0;
	virtual void update(const sf::Time dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif