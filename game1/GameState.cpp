#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "Bullet.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<State*>& states)
  : State(window, states)
  , player({0, 0})
  , world(window)
{}

void GameState::update(const sf::Time dt) {
  //world.update(dt);
  player.update(dt);
}

void GameState::draw() {
  window.draw(player.sprite);
}

void GameState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
    states.push(new MainMenuState(window, states));
  }
}