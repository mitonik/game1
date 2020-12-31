#include "Player.hpp"

Player::Player(sf::Vector2f bounds) : bounds(bounds) {
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
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < bounds.y) {
    isJumping = true;
    acceleration.y += 50.f;
  }
  velocity.x = acceleration.x * dt.asSeconds();
  velocity.y = acceleration.y * dt.asSeconds();
  sprite.move(velocity);
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > bounds.y) {
    isJumping = false;
    acceleration.y = 0;
    sprite.setPosition(sprite.getPosition().x, bounds.y - sprite.getGlobalBounds().height);
  }
  if (sprite.getPosition().x + sprite.getGlobalBounds().width > bounds.x) {
    acceleration.x = 0;
    sprite.setPosition(bounds.x - sprite.getGlobalBounds().width, sprite.getPosition().y);
  }
  if (sprite.getPosition().x < 0) {
    acceleration.x = 0;
    sprite.setPosition(0, sprite.getPosition().y);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    Bullet bullet;
    bullet.sprite.setPosition(sprite.getPosition());
    bullets.push_back(bullet);
  }

  for (int i = 0; i < bullets.size(); i++) {
    bullets[i].sprite.setPosition(bullets[i].sprite.getPosition() +  sf::Vector2f(10.f * dt.asSeconds(), 10.f * dt.asSeconds()));
  }
}