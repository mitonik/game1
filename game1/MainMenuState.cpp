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
  nickfont.loadFromFile("fonts/arial.ttf");
  int a = rand() % 2;
  std::string x = std::to_string(a);
  if (!backText.loadFromFile("textures/back" + x + ".png")) {
	  std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
  }
  sf::Vector2f back = (sf::Vector2f)backText.getSize();
  background.setScale(sf::Vector2f(window.getSize().x / back.x, window.getSize().y / back.y));
  background.setTexture(backText);

  if (!mitonikText.loadFromFile("textures/mitonik.png")) {}
  if (!wozText.loadFromFile("textures/woz.png")) {}

  mitonik.setPosition(window.getSize().x - 240, window.getSize().y - 150);
  mitonik.setRadius(50);
  mitonik.setTexture(&mitonikText);

  woz.setPosition(window.getSize().x - 150, window.getSize().y - 150);
  woz.setRadius(50);
  woz.setTexture(&wozText);

  logo.setFont(font);
  logo.setString("Game 1");
  logo.setCharacterSize(100);
  logo.setPosition(window.getSize().x - 450, 20);

  
  text.setFont(nickfont);
  text.setString("@mitonik   @ofalwoz");
  text.setCharacterSize(20);
  text.setPosition(window.getSize().x - 250, window.getSize().y - 50);
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
  window.draw(mitonik);
  window.draw(woz);
  window.draw(text);
  window.draw(logo);
  renderButtons(window);
}

void MainMenuState::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
	window.close();
  }
}