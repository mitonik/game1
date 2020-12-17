#pragma once
#include "State.hpp"
#include "GameState.hpp"
#include "Settings.hpp"
#include "Button.hpp"

class MainMenuState : public State {
 public:
  MainMenuState(sf::RenderWindow& window, std::stack<State*>& states);
  ~MainMenuState();

  void updateMousePosition();
  void updateButtons();
  void update(const sf::Time dt);
  void renderButtons(sf::RenderTarget& target);
  void draw();
  void handleEvent(const sf::Event& event);

 private:
  sf::Sprite background;
  sf::Texture backText;
  sf::Font font;

  std::map<std::string, Button*> buttons;

  void initButtons();

  sf::Vector2i mousePosScreen;
  sf::Vector2i mousePosWindow;
  sf::Vector2f mousePosView;
};