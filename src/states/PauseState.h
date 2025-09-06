#pragma once
#include"states/State.h"
#include"ui/Button.h"

class PauseState :public State {
private:
	Button btnContinue;
public:
	PauseState();
	void handleEvent(Game& game, const std::optional<sf::Event>& event)override;
	void draw(Game& game)override;
};