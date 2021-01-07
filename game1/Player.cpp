#include "Player.hpp"
#include <iostream>

Player::Player(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key attack, Player& player2)
    : left(left), right(right), up(up), attack(attack), player2(player2) {
  texture.loadFromFile("textures/player_move_r.png");
  sprite.setTexture(texture);
  sprite.setScale(sf::Vector2f(5.f, 5.f));
  font.loadFromFile("fonts/arial.ttf");
  text.setFont(font);
  text.setCharacterSize(50);
  text.setFillColor(sf::Color::White);
  text.setString(std::to_string(health));
  bulletTexture.loadFromFile("textures/player_move_r.png");
}

void Player::update(const sf::Time dt) {
  acceleration.x = 0;
  if (sf::Keyboard::isKeyPressed(left)) {
    acceleration.x -= movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(right)) {
    acceleration.x += movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(up) && isJumping == false) {
    acceleration.y = -jumpSpeed;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < 830) {
    isJumping = true;
    acceleration.y += 50.f;
  }
  velocity.x = acceleration.x * dt.asSeconds();
  velocity.y = acceleration.y * dt.asSeconds();
  sprite.move(velocity.x, velocity.y);
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > 830) {
    isJumping = false;
    acceleration.y = 0;
    sprite.setPosition(sprite.getPosition().x, 830 - sprite.getGlobalBounds().height);
  }
  if (sprite.getPosition().x + sprite.getGlobalBounds().width > 1600) {
    acceleration.x = 0;
    sprite.setPosition(1600 - sprite.getGlobalBounds().width, sprite.getPosition().y);
  }
  if (sprite.getPosition().x < 0) {
    acceleration.x = 0;
    sprite.setPosition(0, sprite.getPosition().y);
  }
  text.setPosition(sprite.getPosition() + sf::Vector2f(0.f, -100.f));
  text.setString(std::to_string(health));
  std::list<Bullet>::iterator it = bullets.begin();
  while (it != bullets.end())
  {
    it->update(dt);
    if (it->sprite.getGlobalBounds().intersects(player2.sprite.getGlobalBounds())) {
      player2.health -= 20;
      it = bullets.erase(it);
    }
    else if (it->sprite.getPosition().x > 1600) {
      it = bullets.erase(it);
    }
    else {
      it++;
    }
  }
  if (sf::Keyboard::isKeyPressed(attack)) {
    Bullet bullet(bulletTexture, sprite.getPosition(), sf::Vector2f(100.f, 0.f));
    bullets.push_back(bullet);
  }
}

void Player::draw(sf::RenderWindow& window) {
  for (std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++) {
    window.draw(it->sprite);
  }
  //std::cout << bullets.size() << std::endl;
  window.draw(sprite);
  window.draw(text);
}