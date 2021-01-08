#pragma once
#include "State.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window/Event.hpp"

class VictoryState : public State {
public:
  VictoryState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states);

  void handleEvent(const sf::Event& event);
  void update(const sf::Time dt);
  void draw();

private:
  sf::Sprite background;
  sf::Texture backgroundTexture;
};