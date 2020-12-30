#include "Player.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

Player::Player() {
  sprite.setScale(sf::Vector2f(3.f, 3.f));
  texture.loadFromFile("textures/player.png");
  sprite.setTexture(texture);
}

void Player::move(sf::Vector2f velocity) {
  sprite.move(velocity.x * movementSpeed, velocity.y * movementSpeed);
}

void Player::update(const sf::Time dt) {
  acceleration.x = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    acceleration.x -= movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    acceleration.x += movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isJumping == false) {
    acceleration.y = -jumpSpeed;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < 800.f) {
    isJumping = true;
    acceleration.y += 50.f;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > 800.f) {
    isJumping = false;
    acceleration.y = 0;
    sprite.setPosition(sprite.getPosition().x, 800.f - sprite.getGlobalBounds().height);
  }
  velocity.x = acceleration.x * dt.asSeconds();
  velocity.y = acceleration.y * dt.asSeconds();
  sprite.move(velocity);
}