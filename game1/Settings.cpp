#include "Settings.hpp"
#include "Application.hpp"
void Settings::initButtons()
{
	if (!this->font.loadFromFile("fonts/Lucid_Streams.otf"))
	{
	}
	this->buttons["FULL_SCREEN"] = new Button(100, 500, 200, 30, &this->font, "Full Screen", sf::Color::White, sf::Color::Red, sf::Color::Blue);

	this->buttons["GAME_MENU"] = new Button(100, 800, 200, 30, &this->font, "Back to menu", sf::Color::White, sf::Color::Red, sf::Color::Blue);
}

Settings::Settings(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->initButtons();

	this->backText = backText;

	this->background.setScale(sf::Vector2f(window->getSize().x / 1056.f, window->getSize().y / 672.f));
	//this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->background.setFillColor(sf::Color::Green);
	if (!backText.loadFromFile("textures/back.png"))
	{
		std::cout << "ERROR::LOADING BUTTONS TEXTURES\n";
	}
	this->background.setTexture(backText);
}

Settings::~Settings()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void Settings::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Settings::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void Settings::update(const sf::Time dt)
{
	this->updateMousePosition();
	//this->updateInput(dt);

	this->updateButtons();

	if (this->buttons["FULL_SCREEN"]->isPressed())	//work in progress
	{
			std::ofstream ifs("config/window.ini");
			std::string title = "game1";
			sf::VideoMode window_bounds(1920, 1080);
			bool fullscreen = false;
			unsigned int framerate_limit = 120;
			bool vertival_sync_enabled = false;
			unsigned antialiasing_level = 0;
			if (ifs.is_open()) {
				//std::getline(ifs, title);
				ifs << "game1\n";
				ifs << window_bounds.width << " " << window_bounds.height << "\n";
				ifs << "0\n";                                      //0 - to jest tryb okienkowy, 1 - fullscreen
				ifs << framerate_limit << "\n";
				ifs << vertival_sync_enabled << "\n";
				ifs << antialiasing_level << "\n";
			}
			ifs.close();
			window->close();
			Application app;
			app.run();
	}
	if (this->buttons["GAME_MENU"]->isPressed())
	{
		states->pop();
		this->states->push(new MainMenuState(this->window, this->states));
	}
}

void Settings::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Settings::draw()
{
	window->draw(this->background);
	this->renderButtons(window);
}

void Settings::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		states->pop();
		this->states->push(new MainMenuState(this->window, this->states));
	}
}