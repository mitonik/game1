#pragma once
#include "State.hpp"
#include "Player.hpp"
#include "SFML/Window/Event.hpp"

class GameState : public State {
 public:
  GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, const int x);

  void handleEvent(const sf::Event& event);
  void update(const sf::Time dt);
  void draw();

 private:
  sf::Sprite background;
  sf::Texture backgroundTexture;

  Player player;
  Player player2;
};