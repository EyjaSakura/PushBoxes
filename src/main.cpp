#include"game/Game.h"
#include<iostream>
using namespace std;

#include"common/Config.h"
#include"common/MapList.h"
#include"utils/pathFinding/FindPath.h"
#include"map/Map.h"

#include<SFML/Graphics.hpp>

int main() {

	/*sf::RenderWindow window;
	window.create(sf::VideoMode({ 800u,600u }), "hello");

	while (window.isOpen()) {
		if (const auto& event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			if (auto* mb = event->getIf<sf::Event::MouseButtonPressed>()) {
				if (mb->button == sf::Mouse::Button::Left) {
					std::cerr << "error" << std::endl;
				}
			}
		}
		window.clear(sf::Color::Blue);
		window.display();
	}*/

	Game game;
	game.run();
	return 0;
}