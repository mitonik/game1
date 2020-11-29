#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State
{
protected:
	sf::RenderWindow* window;
	
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//resources
	std::vector<sf::Texture> textures;

	virtual void initKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;

	virtual void updateInput(const sf::Time dt) = 0;
	virtual void update(const sf::Time dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif