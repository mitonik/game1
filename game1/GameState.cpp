#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "Bullet.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<State*>& states)
  : State(window, states)
  , spawnPosition(worldView.getSize().x / 2.f, worldView.getSize().y / 2.f)
  , worldBounds(0.f, 0.f, worldView.getSize().x, worldView.getSize().y)
  , player(spawnPosition)
{}

void GameState::update(const sf::Time dt) {
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