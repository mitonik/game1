#include "SettingsState.hpp"
#include "Application.hpp"

void Settings::initButtons() {
  font.loadFromFile("fonts/Lucid_Streams.otf");
  buttons["FULL_SCREEN"] = new Button(100, 500, 200, 30, &font, "Full Screen", sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["NOT_FULL_SCREEN"] = new Button(100, 600, 200, 30, &font, "Windowed", sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["GAME_MENU"] = new Button(100, 800, 200, 30, &font, "Back to menu", sf::Color::White, sf::Color::Red, sf::Color::Blue);
}

Settings::Settings(sf::RenderWindow& window, std::stack<State*>& states) : State(window, states) {
  initButtons();

  backText = backText;

  background.setScale(sf::Vector2f(window.getSize().x / 1056.f, window.getSize().y / 672.f));
  //this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
  //this->background.setFillColor(sf::Color::Green);
  if (!backText.loadFromFile("textures/back1.png")) {
    std::cout << "ERROR::LOADING BACKGROUND TEXTURES\n";
  }
  background.setTexture(backText);
}

Settings::~Settings() {
  auto it = buttons.begin();
  for (it = buttons.begin(); it != buttons.end(); ++it) {
    delete it->second;
  }
}

void Settings::updateMousePosition() {
  mousePosScreen = sf::Mouse::getPosition();
  mousePosWindow = sf::Mouse::getPosition(window);
  mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void Settings::updateButtons() {
  for (auto& it : buttons) {
    it.second->update(mousePosView);
  }
}

void Settings::update(const sf::Time dt) {
  updateMousePosition();
  updateButtons();
  if (buttons["FULL_SCREEN"]->isPressed()) {
    std::ofstream ifs("config/window.ini");
    std::string title = "game1";
    sf::VideoMode window_bounds(1920, 1080);
    bool fullscreen = false;
    unsigned int framerate_limit = 120;
    bool vertival_sync_enabled = false;
    unsigned antialiasing_level = 0;
    if (ifs.is_open()) {
      //std::getline(ofs, title);
      ifs << "game1\n";
      ifs << window_bounds.width << " " << window_bounds.height << "\n";
      ifs << "1\n";                                      //0 - to jest tryb okienkowy, 1 - fullscreen
      ifs << framerate_limit << "\n";
      ifs << vertival_sync_enabled << "\n";
      ifs << antialiasing_level << "\n";
    }
    ifs.close();
    window.close();
    Application app;
    app.run();
  }
  if (buttons["NOT_FULL_SCREEN"]->isPressed()) {
    std::ofstream ofs("config/window.ini");
    std::string title = "game1";
    sf::VideoMode window_bounds(1920, 1080);
    bool fullscreen = false;
    unsigned int framerate_limit = 120;
    bool vertival_sync_enabled = false;
    unsigned antialiasing_level = 0;
    if (ofs.is_open()) {
      //std::getline(ofs, title);
      ofs << "game1\n";
      ofs << window_bounds.width << " " << window_bounds.height << "\n";
      ofs << "0\n";                                      //0 - to jest tryb okienkowy, 1 - fullscreen
      ofs << framerate_limit << "\n";
      ofs << vertival_sync_enabled << "\n";
      ofs << antialiasing_level << "\n";
    }
    ofs.close();
    window.close();
    Application app;
    app.run();
  }
  if (buttons["GAME_MENU"]->isPressed()) {
    states.pop();
    states.push(new MainMenuState(window, states));
  }
}

void Settings::renderButtons(sf::RenderTarget& target) {
  for (auto& it : buttons) {
    it.second->render(target);
  }
}

void Settings::draw() {
  window.draw(background);
  renderButtons(window);
}

void Settings::handleEvent(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    states.pop();
    states.push(new MainMenuState(window, states));
  }
}