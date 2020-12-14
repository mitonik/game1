#include <SFML/Graphics.hpp>

class Player {
private:
	sf::Texture texture;

	float movementSpeed = 1000.f;
	float jumpSpeed = 2000.f;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	bool isJumping = false;
	void move(sf::Vector2f velocity);

public:
	Player(float x, float y);
	sf::Sprite sprite;

	void update(const sf::Time dt);

};