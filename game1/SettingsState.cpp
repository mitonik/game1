#include "SettingsState.hpp"

Settings::Settings(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states) : State(window, states) {
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

Settings::~Settings() {
  auto it = buttons.begin();
  for (it = buttons.begin(); it != buttons.end(); ++it) {
	delete it->second;
  }
}

void Settings::initButtons() {
  font.loadFromFile("fonts/Lucid_Streams.otf");
  std::ifstream ifs("config/window.ini");
  std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
  std::string title = "Game1";
  sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
  bool fullscreen = false;
  if (ifs.is_open()) {
	  std::getline(ifs, title);
	  ifs >> window_bounds.width >> window_bounds.height;
	  ifs >> fullscreen;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
  }
  ifs.close();

  //wyswietlanie odpowiedniego przycisku zaleznie od tego czy gra jest na pelnym ekranie czy w okienku
  if (fullscreen) {
	  buttons["SCREEN"] = new Button(100, 100, 200, 30, &font, "Windowed", sf::Color::White, sf::Color::Red, sf::Color::Blue);
  }
  else {
	  buttons["SCREEN"] = new Button(100, 100, 200, 30, &font, "Full Screen", sf::Color::White, sf::Color::Red, sf::Color::Blue);
  }

  buttons["2560"] = new Button(500, 100, 200, 30, &font, "2560x1080", sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["1920"] = new Button(500, 200, 200, 30, &font, "1920x1080", sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["1600"] = new Button(500, 300, 200, 30, &font, "1600x900", sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["720"] = new Button(500, 400, 200, 30, &font, "1280x720", sf::Color::White, sf::Color::Red, sf::Color::Blue);

  buttons["GAME_MENU"] = new Button(100, window.getSize().y - 50, 200, 30, &font, "Back", sf::Color::White, sf::Color::Red, sf::Color::Blue);
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
  std::ifstream ifs("config/window.ini");
  std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
  std::string title = "Game1";
  sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
  bool fullscreen = false;
  unsigned int framerate_limit = 120;
  bool vertival_sync_enabled = false;
  unsigned antialiasing_level = 0;
  if (ifs.is_open()) {
	  std::getline(ifs, title);
	  ifs >> window_bounds.width >> window_bounds.height;
	  ifs >> fullscreen;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
	  ifs >> framerate_limit;
	  ifs >> vertival_sync_enabled;
	  ifs >> antialiasing_level;
  }
  ifs.close();

  //Wpisywanie do pliku config.ini zmian i resetowanie aplikacji w celu wczytaniu tych zmian z pliku
  if (buttons["SCREEN"]->isPressed()) {
	  if (fullscreen) {
		  std::ofstream ofs("config/window.ini");
		  if (ofs.is_open()) {
			  ofs << title << "\n";
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
	  else {
		  std::ofstream ofs("config/window.ini");
		  if (ofs.is_open()) {
			  ofs << title << "\n";
			  ofs << window_bounds.width << " " << window_bounds.height << "\n";
			  ofs << "1\n";                                      //0 - to jest tryb okienkowy, 1 - fullscreen
			  ofs << framerate_limit << "\n";
			  ofs << vertival_sync_enabled << "\n";
			  ofs << antialiasing_level << "\n";
		  }
		  ofs.close();
		  window.close();
		  Application app;
		  app.run();
	  }
	
  }

  if (buttons["2560"]->isPressed()) {
	  std::ofstream ofs("config/window.ini");
	  if (ofs.is_open()) {
		  ofs << title << "\n";
		  ofs << "2560 1080\n";
		  ofs << fullscreen << "\n";;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
		  ofs << framerate_limit << "\n";
		  ofs << vertival_sync_enabled << "\n";
		  ofs << antialiasing_level << "\n";
	  }
	  ofs.close();
	  window.close();
	  Application app;
	  app.run();
  }

  if (buttons["1920"]->isPressed()) {
	  std::ofstream ofs("config/window.ini");
	  if (ofs.is_open()) {
		  ofs << title << "\n";
		  ofs << "1920 1080\n";
		  ofs << fullscreen << "\n";;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
		  ofs << framerate_limit << "\n";
		  ofs << vertival_sync_enabled << "\n";
		  ofs << antialiasing_level << "\n";
	  }
	  ofs.close();
	  window.close();
	  Application app;
	  app.run();
  }

  if (buttons["1600"]->isPressed()) {
	  std::ofstream ofs("config/window.ini");
	  if (ofs.is_open()) {
		  ofs << title << "\n";
		  ofs << "1600 900\n";
		  ofs << fullscreen << "\n";;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
		  ofs << framerate_limit << "\n";
		  ofs << vertival_sync_enabled << "\n";
		  ofs << antialiasing_level << "\n";
	  }
	  ofs.close();
	  window.close();
	  Application app;
	  app.run();
  }

  if (buttons["720"]->isPressed()) {
	  std::ofstream ofs("config/window.ini");
	  if (ofs.is_open()) {
		  ofs << title << "\n";
		  ofs << "1280 720\n";
		  ofs << fullscreen << "\n";;                                      //0 - to jest tryb okienkowy, 1 - fullscreen
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
  }
}