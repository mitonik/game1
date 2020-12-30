#include "GameState.hpp"
#include "PauseState.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states)
    : State(window, states), player(window.getView().getSize()) {}

void GameState::update(const sf::Time dt) {
  player.update(dt);
}

void GameState::draw() {
  window.draw(player.sprite);
}

void GameState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
    //states.push(std::shared_ptr<State>(new PauseState(window, states)));
  }
  if (event.type == sf::Event::Resized) {
    player.bounds = sf::Vector2f(event.size.width, event.size.height);
  }
}