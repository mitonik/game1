#include "MainMenuState.hpp"

void MainMenuState::initButtons() {
  font.loadFromFile("fonts/Lucid_Streams.otf");
  buttons["GAME_STATE"] = new Button(100, 100, 150, 30,
    &font,"New Game", 
    sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["GAME_SET"] = new Button(100, 200, 150, 30, 
    &font, "Settings", 
    sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["GAME_EXIT"] = new Button(100, 300, 150, 30, 
    &font, "Quit", 
    sf::Color::White, sf::Color::Red, sf::Color::Blue);
}

MainMenuState::MainMenuState(sf::RenderWindow& window, std::stack<State*>& states)
    : State(window, states) {
  initButtons();
  if (!backText.loadFromFile("textures/back2.png")) {
      std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
  }
  background.setScale(sf::Vector2f(window.getSize().x/ 928.f, window.getSize().y / 793.f));
  background.setTexture(backText);
}

MainMenuState::~MainMenuState() {
  auto it = buttons.begin();
  for (it = buttons.begin(); it != buttons.end(); ++it) {
    delete it->second;
  }
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
    states.pop();
    states.push(new Settings(window, states));
  }
  if (buttons["GAME_STATE"]->isPressed()) {
    states.pop();
    states.push(new GameState(window, states));
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