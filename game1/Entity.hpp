#include<vector>
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
	sf::Texture texture;
	float movementSpeed = 500.f;
	float jumpSpeed = 1000.f;
	float velocityX = 0.f;
	float velocityY = 0.f;
	float accelerationX = 0.f;
	float accelerationY = 0.f;
	void move(const float x, const float y);
	bool isJumping = false;

public:
	Player();
	//virtual ~Player();
	sf::Sprite sprite;

	void update(const sf::Time dt);

	//virtual void render(sf::RenderTarget* target);

};