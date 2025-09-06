#pragma once
#include<SFML/Graphics.hpp>
#include"common/Position.h"

class Player {
private:
	Position player_pos;
	bool player_onTarget;
	sf::Sprite player_sprite;
	static sf::Texture only_player;
	static sf::Texture player_on_target;

public:
	Player();
	Player(Position pos, bool onTarget);
	Player(int x, int y, bool onTarget);

	Position getPosition()const;
	void setPosition(const Position pos, bool onTarget);

	bool getOnTarget()const;
	void setOnTarget(const bool onTarget);

	sf::Sprite getSprite()const;

	static bool loadTexture(const std::string& only_player_path, const std::string& player_on_target_path);
};