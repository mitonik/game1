#pragma once
#include "State.hpp"
#include "Player.hpp"
#include "SFML/Window/Event.hpp"

class GameState : public State {
 public:
  GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, std::string b, std::string p_one, std::string p_two);

  void handleEvent(const sf::Event& event);
  void update(const sf::Time dt);
  void draw();


 private:
   int win = 0;
   sf::Font font;
   sf::Text playerWin;

  sf::Sprite background;
  sf::Texture backgroundTexture;

  sf::Vector2u bounds = window.getSize();

  Player player;
  Player player2;
};