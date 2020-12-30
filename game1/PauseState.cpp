#include "PauseState.hpp"

PauseState::PauseState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states)
  : State(window, states) {
  font.loadFromFile("fonts/Lucid_Streams.otf");
  text.setFont(font);
  text.setCharacterSize(24);
  text.setString("Paused");
  text.setFillColor(sf::Color::White);
  text.setPosition(window.getView().getCenter() - sf::Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2));
}

void PauseState::update(const sf::Time dt) {
}

void PauseState::draw() {
  window.draw(text);
}

void PauseState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
  }
  if (event.type == sf::Event::Resized) {
    text.setPosition(sf::Vector2f(event.size.width/2 - text.getGlobalBounds().width/2, event.size.height/2 - text.getGlobalBounds().height / 2));
  }
}