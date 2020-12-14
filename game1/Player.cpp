#include "Player.hpp"
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"
#include <iostream>

Player::Player(sf::Vector2f position) {
  sprite.setScale(sf::Vector2f(3.f, 3.f));
  texture.loadFromFile("textures/player.png");
  sprite.setTexture(texture);
  sprite.setPosition(position.x, position.y);
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
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    std::cout << "Left" << std::endl;
    Bullet bullet(sprite.getPosition(), acceleration.x, acceleration.y);
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
    std::cout << "Right" << std::endl;
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
