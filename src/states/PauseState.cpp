#include"states/PauseState.h"
#include "game/Game.h"
#include"common/Resources.h"

#include<iostream>

PauseState::PauseState() :btnContinue("Continue", { 160,60 }, { 320,300 }) {}

void PauseState::handleEvent(Game& game, const std::optional<sf::Event>& event) {
	if (btnContinue.updateClicked(game.getWindow())) { game.changeState(GameState::Play); }
}
void PauseState::draw(Game& game) {
	btnContinue.draw(game.getWindow());
}