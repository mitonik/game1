#pragma once
#include <stack>
#include "State.hpp"
#include "Player.hpp"
#include <iostream>

class GameState : public State {
 public:
  GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states,const int x);

  void update(const sf::Time dt);
  void draw();
  void handleEvent(const sf::Event& event);

 private:
   sf::Sprite background;
   sf::Texture backText;
   Player player;
   Player player2;
};