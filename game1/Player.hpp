#include <SFML/Graphics.hpp>

class Player {
private:
	sf::Texture texture;
	float movementSpeed = 1000.f;
	float jumpSpeed = 2000.f;
	float velocityX = 0.f;
	float velocityY = 0.f;
	float accelerationX = 0.f;
	float accelerationY = 0.f;
	void move(const float x, const float y);
	bool isJumping = false;

public:
	Player();
	sf::Sprite sprite;

	void update(const sf::Time dt);

};