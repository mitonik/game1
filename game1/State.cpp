#include "State.hpp"

State::State(sf::RenderWindow& window, std::stack<std::shared_ptr<State>>& states) : window(window), states(states) {}