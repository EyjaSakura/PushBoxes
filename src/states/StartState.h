#pragma once
#include"states/State.h"
#include"ui/Button.h"

class StartState :public State {
private:
	Button btnStart;
public:
	StartState();
	void handleEvent(Game& game, const std::optional<sf::Event>& event)override;
	void draw(Game& game)override;
};