#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {}

void GameState::update(const sf::Time dt) {
  player.update(dt);
}

void GameState::draw() {
  window->draw(player.sprite);
}

void GameState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states->pop();
    this->states->push(new MainMenuState(this->window, this->states));
  }
}