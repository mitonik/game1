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

    std::stack<State*> states;
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();
    void updateInput(const float& dt);
    void upadateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};