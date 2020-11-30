#pragma once
#include "State.hpp"
#include"GameState.hpp"
#include"Button.hpp"

class MainMenuState :
    public State
{
private:

    sf::RectangleShape background;

    std::map<std::string, Button*> buttons;

    void initKeybinds();
    void initButtons();

    
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    void endState();
    void updateInput(const sf::Time dt);
    void upadateButtons();
    void update(const sf::Time dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};