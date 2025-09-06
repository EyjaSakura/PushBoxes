#include"map/Map.h"

void Map::loadMapFromFile(std::string filePath, int mapNum) {

	map_num = mapNum;

	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "无法打开文件: " << filePath << std::endl;
		return;
	}

	map.clear();
	targets.clear();
	boxes.clear();
	target_sprites.clear();
	wall_sprites.clear();
	space_sprites.clear();

	std::string line;
	getline(file, line);
	std::istringstream mapSize(line);
	mapSize >> map_rows >> map_cols;

	//绘制map，加载动态元素
	int rowNum = 0;
	while (getline(file, line)) {
		int colNum = 0;
		for (char mapContent : line) {
			switch (mapContent) {
			case cfg::PLAYER_CHAR:
				player.setPosition({ rowNum,colNum }, false);
				break;
			case cfg::BOX_CHAR:
				boxes.push_back(Box(rowNum, colNum, false));
				break;
			case cfg::TARGET_CHAR:
				targets.push_back({ rowNum, colNum });
				break;
			case cfg::BOX_ON_TARGET_CHAR:
				boxes.push_back(Box(rowNum, colNum, true));
				targets.push_back({ rowNum, colNum });
				break;
			case cfg::PLAYER_ON_TARGET_CHAR:
				player.setPosition({ rowNum, colNum }, true);
				targets.push_back({ rowNum, colNum });
				break;
			}
			if (mapContent == cfg::WALL_CHAR) {
				map.push_back(cfg::WALL_CHAR);
			}
			else {
				map.push_back(cfg::SPACE_CHAR);
			}
			++colNum;
		}
		++rowNum;
	}

	//绘制静态元素
	/*for (int i = 0; i < map_rows; ++i) {
		for (int j = 0; j < map_cols; ++j) {
			Position pos = { i,j };
			char ele = map[i * map_cols + j];

			if (ele == cfg::WALL_CHAR) {
				sf::Sprite wall_sprite(wall_tex);
				wall_sprite.setPosition({ j * 100.f,i * 100.f });
				wall_sprites.push_back(wall_sprite);
			}
			else if (ele != cfg::UNDEFINE_CHAR) {
				sf::Sprite space_sprite(space_tex);
				space_sprite.setPosition({ j * 100.f,i * 100.f });
				space_sprites.push_back(space_sprite);

				for (const auto& target : targets) {
					if (target == pos) {
						sf::Sprite target_sprite(target_tex);
						target_sprite.setPosition({ j * 100.f,i * 100.f });
						target_sprites.push_back(target_sprite);
						break;
					}
				}
			}

		}
	}*/

}
void Map::draw(sf::RenderWindow& window) {

	for (const auto& sprite : wall_sprites) {
		window.draw(sprite);
	}
	for (const auto& sprite : space_sprites) {
		window.draw(sprite);
	}
	for (const auto& sprite : target_sprites) {
		window.draw(sprite);
	}
	for (const auto& box : boxes) {
		window.draw(box.getSprite());
	}
	window.draw(player.getSprite());

	// 调试信息
	//static int frameCount = 0;
	//if (frameCount % 120 == 0) {
	//	for (const auto& box : boxes) {
	//		cout << "箱子位置：(" << box.getPosition().x << ", " << box.getPosition().y << ")" << endl;
	//	}
	//	cout << "Sprites: " << target_sprites.size() << " targets, "
	//		<< wall_sprites.size() << " walls, "
	//		<< space_sprites.size() << " spaces, "
	//		<< boxes.size() << " boxes" << endl;
	//}
	//frameCount++;

}

bool Map::isSpace(Position pos) {
	if (pos.x < 0 || pos.x >= map_rows || pos.y < 0 || pos.y >= map_cols) {
		return false;
	}
	return map[pos.x * map_cols + pos.y] == cfg::SPACE_CHAR;
}
bool Map::isWall(Position pos) {
	if (pos.x < 0 || pos.x >= map_rows || pos.y < 0 || pos.y >= map_cols) {
		return true;
	}
	return map[pos.x * map_cols + pos.y] == cfg::WALL_CHAR;
}
bool Map::isOnTarget(Position pos) {
	for (auto& target : targets) {
		if (target == pos) {
			return true;
		}
	}
	return false;
}
Box* Map::getBoxAt(Position pos) {
	for (auto& box : boxes) {
		if (box.getPosition() == pos) {
			return &box;
		}
	}
	return nullptr;
}
void Map::movePlayer(Direction dir) {
	Position newPlayerPos = player.getPosition().move(dir);
	if (isWall(newPlayerPos)) { return; };
	Box* box = getBoxAt(newPlayerPos);
	if (box) {
		Position newBoxPos = box->getPosition().move(dir);
		if (isWall(newBoxPos) || getBoxAt(newBoxPos)) { return; };
		box->setPosition(newBoxPos);
		box->setOnTarget(isOnTarget(newBoxPos));
	}
	player.setPosition(newPlayerPos, isOnTarget(newPlayerPos));
}
bool Map::gameOver() {
	if (mapLoadFailedFlag) { return true; }
	for (auto& box : boxes) { if (box.getOnTarget() == false) { return false; } }
	return true;
}
bool Map::mapChecked() {
	if (this->getRows() == 0 || this->getCols() == 0) {
		std::cerr << "地图尺寸非法，地图编号：" << this->getMapNum() << std::endl;
		this->mapLoadFailedFlag = true;
		return false;
	}
	this->mapLoadFailedFlag = false;
	return true;
}
void Map::changeMapEle(Position pos, char changeChar) {
	if (pos.x < 0 || pos.x >= map_rows || pos.y < 0 || pos.y >= map_cols) {
		std::cerr << "不应该出现的错误：深搜位置越界" << std::endl;
		return;
	}
	map[pos.x * map_cols + pos.y] = changeChar;
}


int Map::getRows()const { return map_rows; }
int Map::getCols()const { return map_cols; }
int Map::getMapNum()const { return map_num; }

bool Map::loadTexture(const std::string& target_tex_path, const std::string& wall_tex_path, const std::string& space_tex_path) {
	bool flag1 = target_tex.loadFromFile(target_tex_path);
	bool flag2 = wall_tex.loadFromFile(wall_tex_path);
	bool flag3 = space_tex.loadFromFile(space_tex_path);
	return flag1 && flag2 && flag3;
}

//静态变量
sf::Texture Map::target_tex;
sf::Texture Map::wall_tex;
sf::Texture Map::space_tex;