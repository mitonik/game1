#include "Player.hpp"
#include <SFML/Graphics.hpp>

Player::Player() {
  sprite.setScale(sf::Vector2f(3.f, 3.f));
  texture.loadFromFile("textures/player.png");
  sprite.setTexture(texture);
}

void Player::move(const float x, const float y) {
  sprite.move(x * movementSpeed, y * movementSpeed);
}

void Player::update(const sf::Time dt) {
  accelerationX = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    accelerationX -= movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    accelerationX += movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isJumping == false) {
    accelerationY = -jumpSpeed;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < 800.f) {
    isJumping = true;
    accelerationY += 50.f;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > 800.f) {
    isJumping = false;
    accelerationY = 0;
    sprite.setPosition(sprite.getPosition().x, 800.f - sprite.getGlobalBounds().height);
  }
  velocityX = accelerationX * dt.asSeconds();
  velocityY = accelerationY * dt.asSeconds();
  sprite.move(velocityX, velocityY);
}
