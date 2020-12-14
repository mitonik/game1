#pragma once
#include <stack>
#include "State.hpp"
#include "Player.hpp"
#include "World.hpp"

class GameState : public State {
public:
  GameState(sf::RenderWindow* window, std::stack<State*>* states);
  void update(const sf::Time dt);
  void draw();
  void handleEvent(const sf::Event& event);

private:
  //World world;
  Player player;

};