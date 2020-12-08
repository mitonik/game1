#pragma once
#include "State.hpp"
#include "MainMenuState.hpp"

class GameState : public State {
public:
  GameState(sf::RenderWindow* window, std::stack<State*>* states);
  void update(const sf::Time dt);
  void render();
  void handleEvent(const sf::Event& event);

private:
  Player player;

};