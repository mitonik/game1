#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void run();

private:
  void processEvents();
  void handlePlayerInput(sf::Keyboard::Key, bool);
  void update(sf::Time);
  void render();
  sf::RenderWindow window;
  sf::CircleShape player;
  bool isMovingUp = false;
  bool isMovingDown = false;
  bool isMovingLeft = false;
  bool isMovingRight = false;
  float PlayerSpeed = 1000.f;
};

Game::Game() : window(sf::VideoMode(1280, 720), "Game 1", sf::Style::Close), player() {
  window.setFramerateLimit(60);
  player.setRadius(40.f);
  player.setPosition(100.f, 100.f);
  player.setFillColor(sf::Color::Green);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
  while (window.isOpen()) {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update(TimePerFrame);
    }
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      handlePlayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePlayerInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      window.close();
      break;
    }
  }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W) {
    isMovingUp = isPressed;
  }
  else if (key == sf::Keyboard::S) {
    isMovingDown = isPressed;
  }
  else if (key == sf::Keyboard::A) {
    isMovingLeft = isPressed;
  }
  else if (key == sf::Keyboard::D) {
    isMovingRight = isPressed;
  }
}

void Game::update(sf::Time deltaTime) {
  sf::Vector2f movement(0.f, 0.f);
  if (isMovingUp)
    movement.y -= PlayerSpeed;
  if (isMovingDown)
    movement.y += PlayerSpeed;
  if (isMovingLeft)
    movement.x -= PlayerSpeed;
  if (isMovingRight)
    movement.x += PlayerSpeed;
  player.move(movement * deltaTime.asSeconds());
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