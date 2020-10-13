#include <SFML/Graphics.hpp>

int main() {

  sf::RenderWindow window(sf::VideoMode(1280, 720), "Game 1", sf::Style::Close);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

	}
	return EXIT_SUCCESS;
}