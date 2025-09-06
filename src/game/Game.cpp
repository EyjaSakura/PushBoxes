#include "game/Game.h"
#include "states/StartState.h"
#include "states/PlayState.h"
#include"states/PauseState.h"
#include"states/VictoryState.cpp"
#include"common/Resources.h"

Game::Game() {
	window.create(sf::VideoMode({ 800u,600u }), cfg::GAME_TITLE);

	Resources::loadAllTexture();
	Resources::loadAllAudio();

	Game::getBGM().setVolume(25);
	Game::getBGM().play();

	changeState(GameState::Start);
}

void Game::run() {
	while (window.isOpen()) {
		while (const auto& event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			currentState->handleEvent(*this, event);
		}
		window.clear(sf::Color::Black);
		currentState->draw(*this);
		window.display();
	}
}

void Game::changeState(GameState nextState) {
	//清空事件队列
	while (const auto& event = window.pollEvent()) {}
	//状态切换
	switch (nextState)
	{
	case GameState::Start:
		currentState = std::make_unique<StartState>();
		break;
	case GameState::Play:
		currentState = std::make_unique<PlayState>(*this, isGamePaused);
		break;
	case GameState::Pause:
		currentState = std::make_unique<PauseState>();
		break;
	case GameState::Victory:
		currentState = std::make_unique<VictoryState>();
		break;
	default:
		break;
	}
}

//静态变量
sf::Music Game::bgm_music;
sf::SoundBuffer Game::warning_buffer;
std::unique_ptr<sf::Sound> Game::warning_sound;