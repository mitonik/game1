#include "GameState.hpp"
#include "PauseState.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, const int x)
    : State(window, states), player(window.getView().getSize()) {
	
	std::string a = std::to_string(x);
	if (!backText.loadFromFile("textures/back" + a + ".png")) {}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);
}

void GameState::update(const sf::Time dt) {
  player.update(dt);
}

void GameState::draw() {
  window.draw(background);
  window.draw(player.sprite);
  for (int i = 0; i < player.bullets.size(); i++) {
    window.draw(player.bullets[i].sprite);
  }
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