#include "State.hpp"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	//this->quit = false;
	this->states = states;
}

void State::render()
{
}

//bool State::getQuit() {
//	return this->quit;
//}
//
//void State::checkForQuit() {
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//		//this->quit = true;
//		//this->states.push(new MainMenuState(this->window, &this->states));
//		this->window->close();
//	}
//}
//
//void State::updateMousePosition()
//{
//	this->mousePosScreen = sf::Mouse::getPosition();
//	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
//	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
//}
