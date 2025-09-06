#pragma once
#include<SFML/Graphics.hpp>
#include"common/Position.h"

class Box {
private:
	Position box_pos;
	bool box_onTarget;
	sf::Sprite box_sprite;
	static sf::Texture only_box;
	static sf::Texture box_on_target;

public:
	Box();
	Box(Position pos, bool onTarget);
	Box(int x, int y, bool onTarget);

	Position getPosition()const;
	void setPosition(const Position pos);

	bool getOnTarget()const;
	void setOnTarget(const bool onTarget);

	sf::Sprite getSprite()const { return box_sprite; };

	static bool loadTexture(const std::string& only_box_path, const std::string& box_on_target_path);

};