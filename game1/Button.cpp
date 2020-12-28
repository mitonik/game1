#include "Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Font* font,
               sf::String buttonText, sf::Color idleColor, sf::Color hoverColor,
               sf::Color activeColor)
    : font(font), idleColor(idleColor), hoverColor(hoverColor)
    , activeColor(activeColor) {
  shape.setPosition(sf::Vector2f(x, y));
  shape.setSize(sf::Vector2f(width, height));

  text.setFont(*this->font);
  text.setString(buttonText);
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(35);
  text.setPosition(
  shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f - this->text.getGlobalBounds().width/2.f,
  shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height / 2.f);

  shape.setFillColor(this->idleColor);
}

bool Button::isPressed() {
  if (buttonState == BTN_PRESSED) {
    return true;
  } else {
    return false;
  }
}

void Button::update(const sf::Vector2f mousePos) {
  buttonState = BTN_IDLE;
  if (shape.getGlobalBounds().contains(mousePos)) {
    buttonState = BTN_HOVER;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      buttonState = BTN_PRESSED;
    }
  }

  switch (buttonState) {
  case BTN_IDLE:
    text.setFillColor(idleColor);
    shape.setFillColor(sf::Color::Black);
    break;
  case BTN_HOVER:
    text.setFillColor(hoverColor);
    break;
  case BTN_PRESSED:
    text.setFillColor(activeColor);
    break;
  default:
    break;
  }
}

void Button::render(sf::RenderTarget& window) {
  window.draw(text);
}