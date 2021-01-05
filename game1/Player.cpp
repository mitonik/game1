#include "Player.hpp"

Player::Player(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key attack, sf::Vector2f bounds) : bounds(bounds), lastDirection(left)
, left(left), right(right), up(up), attack(attack) {
  texture1.loadFromFile("textures/player_move_l.png");
  texture2.loadFromFile("textures/player_move_r.png");
  texture3.loadFromFile("textures/player_attack_l.png");
  texture4.loadFromFile("textures/player_attack_r.png");
  sprite.setTexture(texture1);
  sprite.setScale(sf::Vector2f(5.f, 5.f));
  bullet.setFillColor(sf::Color::Black);
  bullet.setRadius(50.f);
}

void Player::update(const sf::Time dt) {
  acceleration.x = 0;
  if (sf::Keyboard::isKeyPressed(left)) {
    acceleration.x -= movementSpeed;
    lastDirection = leftDir;
    sprite.setTexture(texture1);
  }
  if (sf::Keyboard::isKeyPressed(right)) {
    acceleration.x += movementSpeed;
    lastDirection = rightDir;
    sprite.setTexture(texture2);
  }
  if (sf::Keyboard::isKeyPressed(up) && isJumping == false) {
    acceleration.y = -jumpSpeed;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < bounds.y) {
    isJumping = true;
    acceleration.y += 50.f;
  }
  velocity.x = acceleration.x * dt.asSeconds();
  velocity.y = acceleration.y * dt.asSeconds();
  sprite.move(velocity.x, velocity.y);
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
  if (sf::Keyboard::isKeyPressed(attack) && clock.getElapsedTime().asSeconds() > 2.f) {
    if (lastDirection == leftDir)
    {
      sprite.setTexture(texture3);
    }
    else if (lastDirection == rightDir)
    {
      sprite.setTexture(texture4);
    }
    std::cout << "fire" << std::endl;
    bullet.setPosition(sprite.getPosition() + sf::Vector2f(0.f, -200.f));
    clock.restart();
  }
  //std::cout << clock.getElapsedTime().asSeconds() << std::endl;
}

void Player::draw(sf::RenderWindow& window) {
  window.draw(sprite);
  window.draw(bullet);
}