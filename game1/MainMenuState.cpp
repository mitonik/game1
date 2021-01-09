#include "MainMenuState.hpp"

void MainMenuState::initButtons() {
  font.loadFromFile("fonts/Lucid_Streams.otf");
  buttons["GAME_STATE"] = new Button(100, 50, 150, 30,
    &font,"New Game", 
    sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["GAME_SET"] = new Button(325, 48, 150, 30,
    &font, "Settings", 
    sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["GAME_EXIT"] = new Button(500, 50, 150, 30,
    &font, "Quit", 
    sf::Color::White, sf::Color::Red, sf::Color::Blue);
}

MainMenuState::MainMenuState(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states)
    : State(window, states) {
  initButtons();

  int a = rand() % 4;
  std::string x = std::to_string(a);
  if (!backText.loadFromFile("textures/back" + x + ".png")) {
      std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
  }
  sf::Vector2f back = (sf::Vector2f)backText.getSize();
  background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
  background.setTexture(backText);
}

void MainMenuState::updateMousePosition() {
  mousePosScreen = sf::Mouse::getPosition();
  mousePosWindow = sf::Mouse::getPosition(window);
  mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void MainMenuState::updateButtons() {
  for (auto& it : buttons) {
    it.second->update(mousePosView);
  }
}

void MainMenuState::update(const sf::Time dt) {
  updateMousePosition();
  updateButtons();

  //std::cout << this->mousePosView.x << " " << this->mousePosView.x << "\n";
  if (buttons["GAME_SET"]->isPressed()) {
    states.push(std::shared_ptr<State>(new Settings(window, states)));
  }
  if (buttons["GAME_STATE"]->isPressed()) {
    states.push(std::shared_ptr<State>(new MapChose(window, states)));
  }
  if (buttons["GAME_EXIT"]->isPressed()) {
    window.close();
  }
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
  for (auto& it : buttons) {
    it.second->render(target);
  }
}

void MainMenuState::draw() {
  window.draw(background);
  renderButtons(window);
}

void MainMenuState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    window.close();
  }
}