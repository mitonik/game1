#pragma once
#include <stack>
#include "State.hpp"
#include "SFML/Graphics.hpp"

class PauseState : public State {
public:
  PauseState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states);

  void update(const sf::Time dt);
  void draw();
  void handleEvent(const sf::Event& event);

private:
  sf::Font font;
  sf::Text text;
};