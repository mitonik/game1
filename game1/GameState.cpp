#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, std::string b, std::string p_one, std::string p_two)
    : State(window, states)
  , player(sf::Vector2f(0.f, window.getSize().y), sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::F, sf::Keyboard::G, player2)
  , player2(sf::Vector2f(window.getSize()), sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::End, sf::Keyboard::Down, player) {
  backgroundTexture.loadFromFile("textures/back" + b + ".png");
  sf::Vector2f back = (sf::Vector2f)backgroundTexture.getSize();
  background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
  background.setTexture(backgroundTexture);
  font.loadFromFile("fonts/arial.ttf");
  playerWin.setFont(font);
  playerWin.setCharacterSize(50);
  playerWin.setFillColor(sf::Color::White);
}

void GameState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
  }
}

void GameState::update(const sf::Time dt) {
  if (win == 0) {
    player.update(dt);
    player2.update(dt);
  }
  if (player.health <= 0) {
    win = 2;
  } else if (player2.health <= 0) {
    win = 1;
  }
}

void GameState::draw() {
  if (win == 0) {
    window.draw(background);
    player.draw(window);
    player2.draw(window);
  }
  if (win == 1) {
    playerWin.setString("Player1 Won! Press ESC to exit.");
    window.draw(background);
    window.draw(playerWin);
  }
  if (win == 2) {
    playerWin.setString("Player2 Won! Press ESC to exit.");
    window.draw(background);
    window.draw(playerWin);
  }
}