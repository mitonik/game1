#pragma once
#include "State.hpp"
class GameState :
    public State
{
private:
    Player player;

    void initKeybinds();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~GameState();

    void endState();
    void updateInput(const sf::Time dt);
    void update(const sf::Time dt);
    void render(sf::RenderTarget* target = nullptr);
};