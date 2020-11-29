#pragma once
#include "State.h"
class GameState :
    public State
{
private:
    Entity player;

    void initKeybinds();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~GameState();

    void endState();
    void updateInput(const sf::Time dt);
    void update(const sf::Time dt);
    void render(sf::RenderTarget* target = nullptr);
};