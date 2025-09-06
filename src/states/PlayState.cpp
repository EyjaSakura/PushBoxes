#include "states/PlayState.h"
#include"utils/pathFinding/FindPath.h"

#include<iostream>


PlayState::PlayState(Game& game, bool isGamePaused) {
	//������ʱ��
	ignoreMouseTimer.restart();
	
	map.loadTexture(cfg::TARGET_PATH, cfg::WALL_PATH, cfg::SPACE_PATH);
	if (isGamePaused) {
		map = game.getTempMap();
		Game::getBGM().play();
		std::cerr << "��ͣ�ָ�" << std::endl;
	}
	else { enter(game); }
}

void PlayState::enter(Game& game){
	
	std::cout << "��ͼ��ַ��" << game.getCurrentMapPath() << std::endl;
	std::cout << "��ͼ��ţ�" << static_cast<int>(game.getCurrentMapNum()) << std::endl;

	map.loadMapFromFile(game.getCurrentMapPath(), static_cast<int>(game.getCurrentMapNum()));
	game.getWindow().close();
	if (!map.mapChecked()) {
		Game::getWarningSound()->play();
		//�˴��ɸ���Ϊ������ʾͼ
		game.getWindow().create(sf::VideoMode({ 600u,600u }), cfg::GAME_TITLE);
	}
	else {
		game.getWindow().create(sf::VideoMode({ (unsigned int)map.getCols() * 100,(unsigned int)map.getRows() * 100 }), cfg::GAME_TITLE);
	}
}

void PlayState::handleEvent(Game& game, const std::optional<sf::Event>& event) {
	//����ǰ200ms������¼�
	if (ignoreMouseTimer.getElapsedTime() < sf::milliseconds(200)) { return; }

	//����¼�
	if (auto* mousebtn = event->getIf<sf::Event::MouseButtonPressed>()) {
		if (mousebtn->button == sf::Mouse::Button::Left) {
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(game.getWindow());
			Position goal = { mouse_pos.y / 100,mouse_pos.x / 100 };
			if (goal.x < 0 || goal.y >= map.getRows() || goal.y < 0 || goal.y >= map.getCols()) { return; }
			if (map.isSpace(goal)) {
				std::vector<Position> path;
				Position start = map.getPlayerPos();
				if (!FindPath::find_path_DFS(map, start, goal, path)) { return; }
				map.changeMapEle(start, cfg::SPACE_CHAR);
				for (Position next_pos : path) {
					std::cerr << "׷�ٵ㣺(" << next_pos.x << "," << next_pos.y << ")" << std::endl;
					sf::sleep(sf::seconds(0.2f));
					map.setPlayerPos(next_pos, false);
					map.changeMapEle(next_pos, cfg::SPACE_CHAR);
					map.draw(game.getWindow());
					game.getWindow().display();
				}
				map.showMap();
			}
		}
	}
	//�����¼�
	else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
		const auto code = keyPressed->code;

		if (!map.gameOver()) {
			switch (code) {
			case sf::Keyboard::Key::W:
				map.movePlayer(UP);
				break;
			case sf::Keyboard::Key::A:
				map.movePlayer(LEFT);
				break;
			case sf::Keyboard::Key::S:
				map.movePlayer(DOWN);
				break;
			case sf::Keyboard::Key::D:
				map.movePlayer(RIGHT);
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
				//Ա��ͨ��
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
			case sf::Keyboard::Key::Escape:
				Game::getBGM().pause();
				game.setGamePausedFlag();
				game.saveMap(map);
				game.changeState(GameState::Pause);
				break;
				//Ա��ͨ��
			case sf::Keyboard::Key::K:
				game.setNextMap();
				enter(game);
				break;
			}
		}
	}
}
void PlayState::draw(Game& game) {
	map.draw(game.getWindow());
}