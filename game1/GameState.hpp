#pragma once
#include "State.hpp"

class GameState : public State {
public:
  GameState(sf::RenderWindow* window, std::stack<State*>* states);
  void update(const sf::Time dt);
  void render();

private:
  Player player;

};