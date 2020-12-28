#pragma once
#include<vector>
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

class Button {
 public:
  Button(float x, float y, float width, float height, sf::Font* font, sf::String text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

  bool isPressed();
  void update(sf::Vector2f mousePos);
  void render(sf::RenderTarget& window);

  enum button_states{
    BTN_IDLE,
    BTN_HOVER,
    BTN_PRESSED
  };

 private:
  short unsigned buttonState = BTN_IDLE;
  bool pressed = false;
  bool hover = false;
  sf::RectangleShape shape;
  sf::Font* font;
  sf::Text text;
  sf::Color idleColor;
  sf::Color hoverColor;
  sf::Color activeColor;
};