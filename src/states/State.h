#pragma once
#include<SFML/Graphics.hpp>

class Game;

class State {
public:
	virtual ~State() = default;
	virtual void handleEvent(Game& game, const std::optional<sf::Event>& event) {}
	virtual void update(Game& game, float dt) {}
	virtual void draw(Game& game) {}
};