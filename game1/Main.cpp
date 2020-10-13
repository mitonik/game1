#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void run();

private:
  void processEvents();
  void update();
  void render();
  sf::RenderWindow window;
  sf::CircleShape player;
};

Game::Game()
  : window(sf::VideoMode(1280, 720), "Game 1", sf::Style::Close)
  , player() {
  player.setRadius(40.f);
  player.setPosition(100.f, 100.f);
  player.setFillColor(sf::Color::Green);
}

void Game::run() {
  while (window.isOpen()) {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void Game::update() {
}

void Game::render() {
  window.clear();
  window.draw(player);
  window.display();
}

int main() {
  Game game;
  game.run();
  return EXIT_SUCCESS;
}