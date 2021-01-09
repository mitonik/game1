#pragma once
#include "State.hpp"
#include "MapChoseState.hpp"
#include "SettingsState.hpp"
#include "Button.hpp"

class MainMenuState : public State {
 public:
  MainMenuState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states);

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
  sf::Font nickfont;
  sf::Text logo;
  sf::Text text;

  std::map<std::string, Button*> buttons;

  void initButtons();

  sf::Vector2i mousePosScreen;
  sf::Vector2i mousePosWindow;
  sf::Vector2f mousePosView;

  sf::CircleShape mitonik;
  sf::CircleShape woz;

  sf::Texture mitonikText;
  sf::Texture wozText;
};