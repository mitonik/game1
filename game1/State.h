#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State
{
private:

protected:
	sf::RenderWindow* window;
	
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mausePosScreen;
	sf::Vector2i mausePosWindow;
	sf::Vector2f mausePosView;

	//resources
	std::vector<sf::Texture> textures;

	virtual void initKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getQuit() const;

	virtual void chechForQuit();

	virtual void endState() = 0;
	virtual void UpdateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif