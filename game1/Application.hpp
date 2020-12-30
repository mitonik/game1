#pragma once
#include <stack>
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "State.hpp"

class Application {
 public:
  Application();

  void run();

 private:
  void processInput();
  void update(sf::Time dt);
  void render();

  static const sf::Time TimePerFrame;
  sf::RenderWindow window;
  std::stack<std::shared_ptr<State>> stateStack;
};