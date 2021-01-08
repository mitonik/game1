#include "VictoryState.hpp"

VictoryState::VictoryState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states)
  : State(window, states) {
  backgroundTexture.loadFromFile("textures/back3.png");
  sf::Vector2f back = (sf::Vector2f)backgroundTexture.getSize();
  background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
  background.setTexture(backgroundTexture);
}

void VictoryState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
  }
}

void VictoryState::update(const sf::Time dt) {
}

void VictoryState::draw() {
  window.draw(background);
}