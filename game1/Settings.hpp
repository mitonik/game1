#pragma once
#include "MainMenuState.hpp"
#include "State.hpp"
#include "Button.hpp"

class Settings :
    public State
{
private:

    sf::Sprite background;
    sf::Texture backText;

    std::map<std::string, Button*> buttons;

    //void initKeybinds();
    void initButtons();

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;


public:
    Settings(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~Settings();

    void updateMousePosition();
    void checkForQuit();
    void endState();
    void updateInput(const sf::Time dt);
    void updateButtons();
    void update(const sf::Time dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render();
};

