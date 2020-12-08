#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {}

void GameState::update(const sf::Time dt) {
  player.update(dt);
}

void GameState::render() {
  window->draw(player.sprite);
}

void GameState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    window->close();
  }
}
