#include "states/PlayState.h"
#include"utils/pathFinding/FindPath.h"

#include<iostream>


PlayState::PlayState(Game& game, bool isGamePaused) {
	//启动计时器
	ignoreMouseTimer.restart();
	
	map.loadTexture(cfg::TARGET_PATH, cfg::WALL_PATH, cfg::SPACE_PATH);
	if (isGamePaused) {
		map = game.getTempMap();
		Game::getBGM().play();
		std::cerr << "暂停恢复" << std::endl;
	}
	else { enter(game); }
}

void PlayState::enter(Game& game){
	
	std::cout << "地图地址：" << game.getCurrentMapPath() << std::endl;
	std::cout << "地图编号：" << static_cast<int>(game.getCurrentMapNum()) << std::endl;

	map.loadMapFromFile(game.getCurrentMapPath(), static_cast<int>(game.getCurrentMapNum()));
	game.getWindow().close();
	if (!map.mapChecked()) {
		Game::getWarningSound()->play();
		//此处可更换为警报提示图
		/*game.getWindow().create(sf::VideoMode({ 600u,600u }), cfg::GAME_TITLE);
		game.getWindow().clear();*/
	}
	else {
		game.getWindow().create(sf::VideoMode({ (unsigned int)map.getCols() * 100,(unsigned int)map.getRows() * 100 }), cfg::GAME_TITLE);
	}
}

void PlayState::handleEvent(Game& game, const std::optional<sf::Event>& event) {
	//忽略前200ms的鼠标事件
	if (ignoreMouseTimer.getElapsedTime() < sf::milliseconds(200)) { return; }

	//鼠标事件
	if (auto* mousebtn = event->getIf<sf::Event::MouseButtonPressed>()) {
		if (mousebtn->button == sf::Mouse::Button::Left) {
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(game.getWindow());
			Position goal = { mouse_pos.y / 100,mouse_pos.x / 100 };
			if (goal.x < 0 || goal.y >= map.getRows() || goal.y < 0 || goal.y >= map.getCols()) { return; }
			if (map.isSpace(goal) || map.isOnTarget(goal)) {
				std::vector<Direction> path;
				Position start = map.getPlayerPos();
				std::vector<char> map_saved = map.getMap();
				if (!FindPath::find_path_DFS(map, start, goal, path)) { return; }
				map.setMap(map_saved);
				for (Direction next_dir : path) {
					sf::sleep(sf::seconds(0.2f));
					map.movePlayer(next_dir);
					map.draw(game.getWindow());
					game.getWindow().display();
				}
				map.showMap();
			}
		}
	}
	//键盘事件
	else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
		const auto code = keyPressed->code;

		if (!map.gameOver()) {
			shouleReloadWindow = true;
			switch (code) {
			case sf::Keyboard::Key::W:
				map.movePlayer(UP);
				map.showMap();
				break;
			case sf::Keyboard::Key::A:
				map.movePlayer(LEFT);
				map.showMap();
				break;
			case sf::Keyboard::Key::S:
				map.movePlayer(DOWN);
				map.showMap();
				break;
			case sf::Keyboard::Key::D:
				map.movePlayer(RIGHT);
				map.showMap();
				break;
			case sf::Keyboard::Key::R:
				enter(game);
				break;
			case sf::Keyboard::Key::L:
				game.setPrevMap();
				enter(game);
				break;
			case sf::Keyboard::Key::Q:
				game.getWindow().close();
				break;
			case sf::Keyboard::Key::Escape:
				Game::getBGM().pause();
				game.setGamePausedFlag();
				game.saveMap(map);
				game.changeState(GameState::Pause);
				break;
				//员工通道
			case sf::Keyboard::Key::K:
				game.setNextMap();
				enter(game);
				break;
			}
		}
		else {
			switch (code) {
			case sf::Keyboard::Key::R:
				enter(game);
				break;
			case sf::Keyboard::Key::N:
				game.setNextMap();
				enter(game);
				break;
			case sf::Keyboard::Key::L:
				game.setPrevMap();
				enter(game);
				break;
			case sf::Keyboard::Key::Q:
				game.getWindow().close();
				break;
				//员工通道
			case sf::Keyboard::Key::K:
				game.setNextMap();
				enter(game);
				break;
			}
		}
	}
}
void PlayState::draw(Game& game) {
	if (!map.gameOver()) {
		map.draw(game.getWindow());
	}
	else {
		if (shouleReloadWindow) {
			game.getWindow().close();
			game.getWindow().create(sf::VideoMode({ 700u,495u }), cfg::GAME_TITLE);
			shouleReloadWindow = false;
		}
		game.getWindow().draw(*Game::getVictorySprite());
	}
}