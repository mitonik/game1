#include "Player.hpp"
#include <iostream>

Player::Player(sf::Vector2f startPos, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key attack, sf::Keyboard::Key attack2, Player& player2, sf::Vector2u bounds)
    : bounds(bounds), left(left), right(right), up(up), attack(attack), attack2(attack2), player2(player2), lastDir(leftDir) {
  texture.loadFromFile("textures/player_move_r.png");
  sprite.setTexture(texture);
  sprite.setScale(sf::Vector2f(5.f, 5.f));
  font.loadFromFile("fonts/arial.ttf");
  text.setFont(font);
  text.setCharacterSize(50);
  text.setFillColor(sf::Color::White);
  text.setString(std::to_string(health));
  bulletTexture.loadFromFile("textures/player_move_r.png");
  sprite.setPosition(startPos);
  passive.setTexture(texture);
}

void Player::update(const sf::Time dt) {
  acceleration.x = 0;
  if (sf::Keyboard::isKeyPressed(left)) {
    acceleration.x -= movementSpeed;
    lastDir = leftDir;
  }
  if (sf::Keyboard::isKeyPressed(right)) {
    acceleration.x += movementSpeed;
    lastDir = rightDir;
  }
  if (sf::Keyboard::isKeyPressed(up) && isJumping == false) {
    acceleration.y = -jumpSpeed;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < bounds.y - 70) {
    isJumping = true;
    acceleration.y += 50.f;
  }
  velocity.x = acceleration.x * dt.asSeconds();
  velocity.y = acceleration.y * dt.asSeconds();
  sprite.move(velocity.x, velocity.y);
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > bounds.y - 70) {
    isJumping = false;
    acceleration.y = 0;
    sprite.setPosition(sprite.getPosition().x, bounds.y - 70 - sprite.getGlobalBounds().height);
  }
  if (sprite.getPosition().x + sprite.getGlobalBounds().width > bounds.x) {
    acceleration.x = 0;
    sprite.setPosition(bounds.x - sprite.getGlobalBounds().width, sprite.getPosition().y);
  }
  if (sprite.getPosition().x < 0) {
    acceleration.x = 0;
    sprite.setPosition(0, sprite.getPosition().y);
  }
  text.setPosition(sprite.getPosition() + sf::Vector2f(0.f, -100.f));
  text.setString(std::to_string(health));
  std::list<Bullet>::iterator it = bullets.begin();
  while (it != bullets.end()) {
    it->update(dt);
    if (it->sprite.getGlobalBounds().intersects(player2.sprite.getGlobalBounds())) {
      player2.health -= 20;
      it = bullets.erase(it);
    }
    else if (it->sprite.getPosition().x > bounds.x) {
      it = bullets.erase(it);
    }
    else {
      it++;
    }
  }
  timeSinceLastUpdate += dt;
  if (sf::Keyboard::isKeyPressed(attack) && timeSinceLastUpdate.asSeconds() > 1.f) {
    timeSinceLastUpdate = sf::Time::Zero;
    if (lastDir == leftDir) {
      Bullet bullet(bulletTexture, sprite.getPosition(), sf::Vector2f(-750.f, 0.f));
      bullets.push_back(bullet);
    } else if (lastDir == rightDir) {
      Bullet bullet(bulletTexture, sprite.getPosition(), sf::Vector2f(750.f, 0.f));
      bullets.push_back(bullet);
    }
  }
  timeSinceLastUpdateSpecial += dt;
  if (timeSinceLastUpdateSpecial > sf::seconds(1.f)) {
    if (passive.getGlobalBounds().intersects(player2.sprite.getGlobalBounds())) {
      player2.health -= 10;
      timeSinceLastUpdateSpecial = sf::seconds(0.f);
    }
  }
  passive.setPosition(200.f * cos(clock.getElapsedTime().asSeconds()) + sprite.getPosition().x, 200.f * sin(clock.getElapsedTime().asSeconds()) + sprite.getPosition().y);
}

void Player::draw(sf::RenderWindow& window) {
  for (std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++) {
    window.draw(it->sprite);
  }
  //std::cout << bullets.size() << std::endl;
  window.draw(sprite);
  window.draw(passive);
  window.draw(text);
}