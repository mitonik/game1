#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {}

void GameState::update(const sf::Time dt) {
  player.update(dt);
}

void GameState::render() {
  window->draw(player.sprite);
}
