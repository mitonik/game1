#pragma once
#include <stack>
#include "SFML/Graphics/RenderWindow.hpp"

class State {
 public:
  State(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states);

  virtual void update(const sf::Time dt) = 0;
  virtual void draw() = 0;
  virtual void handleEvent(const sf::Event& event) = 0;

 protected:
  std::stack<std::shared_ptr<State>>& states;
  sf::RenderWindow& window;
};