#pragma once
#include "State.hpp"
#include "MainMenuState.hpp"
class GameState :
    public State
{
private:
    Player player;
    std::stack<State*> states;
    void initKeybinds();

public:
    //std::stack<State*> states;
    GameState(sf::RenderWindow* window, std::stack<State*>* states);

    void endState();
    void updateInput(const sf::Time dt);
    void update(const sf::Time dt);
    void render(sf::RenderTarget* target = nullptr);
};