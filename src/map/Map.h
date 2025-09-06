#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
#include"common/Position.h"
#include"things/player/player.h"
#include"things/box/Box.h"
#include"common/Config.h"

class Map {
private:
	int map_rows, map_cols, map_num{ -1 };
	std::vector<char> map;
	std::vector<Position> targets;
	std::vector<Box> boxes;
	Player player;
	std::vector<sf::Sprite> target_sprites;
	std::vector<sf::Sprite> wall_sprites;
	std::vector<sf::Sprite> space_sprites;
	static sf::Texture target_tex;
	static sf::Texture wall_tex;
	static sf::Texture space_tex;
	bool mapLoadFailedFlag{ false };

public:
	void loadMapFromFile(std::string filePath, int mapNum);
	void draw(sf::RenderWindow& window);

	bool isSpace(Position);
	bool isWall(Position pos);
	bool isOnTarget(Position pos);
	Box* getBoxAt(Position pos);
	void movePlayer(Direction dir);
	bool gameOver();
	bool mapChecked();
	void changeMapEle(Position pos, char changeChar);
	void setPlayerPos(Position pos, bool isPlayerOnTarget) { player.setPosition(pos, isPlayerOnTarget); }

	int getRows()const;
	int getCols()const;
	int getMapNum()const;
	Position getPlayerPos()const { return player.getPosition(); }

	//≤‚ ‘”√
	std::vector<char> getMap()const { return map; }
	void showMap() {
		for (int i = 0; i < map_rows; ++i) {
			for (int j = 0; j < map_cols; ++j) {
				std::cout << map[i * map_cols + j] << " ";
			}
			std::cout << std::endl;
		}
	}

	static bool loadTexture(const std::string& target_tex_path, const std::string& wall_tex_path, const std::string& space_tex_path);
};