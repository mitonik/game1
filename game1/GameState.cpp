#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states, const int x)
    : State(window, states)
  , player(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::F, window.getView().getSize())
  , player2(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::End, window.getView().getSize()) {
	
	std::string a = std::to_string(x);
	if (!backText.loadFromFile("textures/back" + a + ".png")) {}
	sf::Vector2f back = (sf::Vector2f)backText.getSize();
	background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
	background.setTexture(backText);
}

void GameState::update(const sf::Time dt) {
  player.update(dt);
  player2.update(dt);
  if (player.bullet.getGlobalBounds().intersects(player2.sprite.getGlobalBounds())){
    std::cout << "player2 got hit" << std::endl;
  }
  if (player2.bullet.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
    std::cout << "player1 got hit" << std::endl;
  }
}

void GameState::draw() {
  window.draw(background);
  player.draw(window);
  player2.draw(window);
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