#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, const int x)
    : State(window, states)
    , player(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::F, player2)
    , player2(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::End, player) {
  std::string a = std::to_string(x);
  backgroundTexture.loadFromFile("textures/back" + a + ".png");
  sf::Vector2f back = (sf::Vector2f)backgroundTexture.getSize();
  background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
  background.setTexture(backgroundTexture);
}

void GameState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
  }
}

void GameState::update(const sf::Time dt) {
  player.update(dt);
  player2.update(dt);
}

void GameState::draw() {
  window.draw(background);
  player.draw(window);
  player2.draw(window);
}