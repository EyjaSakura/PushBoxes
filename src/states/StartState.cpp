#include"states/StartState.h"
#include "game/Game.h"
#include"common/Resources.h"

#include<iostream>

StartState::StartState() :btnStart("Start", { 160,60 }, { 320,300 }) {}

void StartState::handleEvent(Game& game, const std::optional<sf::Event>& event) {
	if (btnStart.updateClicked(game.getWindow())) { game.changeState(GameState::Play); }
}
void StartState::draw(Game& game) {
	btnStart.draw(game.getWindow());
}