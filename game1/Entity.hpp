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
	sf::Sprite sprite;
	float speed = 500.f;
	float jump = 500.f;
	float velocityX = 0.f;
	float velocityY = 0.f;
	float accelerationX = 0.f;
	float accelerationY = 0.f;

public:
	Player();
	virtual ~Player();

	virtual void move(const float x, const float y);

	virtual void update(const sf::Time dt);
	virtual void render(sf::RenderTarget* target);

};