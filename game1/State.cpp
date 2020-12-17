#include "State.hpp"

State::State(sf::RenderWindow& window, std::stack<State*>& states)
    : window(window), states(states) {}