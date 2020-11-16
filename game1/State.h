#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State
{
protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;

	virtual void chechForQuit();

	virtual void endState() = 0;

	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif