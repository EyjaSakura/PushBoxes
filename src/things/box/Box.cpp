#include"things/box/Box.h"

Box::Box() : box_pos{ 0,0 }, box_onTarget(false), box_sprite(only_box) {
	box_sprite.setPosition({ 0.f, 0.f });
}
Box::Box(Position pos, bool onTarget) :box_pos(pos), box_onTarget(onTarget), box_sprite(onTarget ? box_on_target : only_box) {
	box_sprite.setPosition({ pos.y * 100.f, pos.x * 100.f });
}
Box::Box(int x, int y, bool onTarget) :box_pos{ x,y }, box_onTarget(onTarget), box_sprite(onTarget ? box_on_target : only_box) {
	box_sprite.setPosition({ y * 100.f, x * 100.f });
}

Position Box::getPosition()const { return box_pos; }
void Box::setPosition(const Position pos) {
	box_pos = pos;
	box_sprite.setPosition({ pos.y * 100.f,pos.x * 100.f });
};

bool Box::getOnTarget()const { return box_onTarget; };
void Box::setOnTarget(const bool onTarget) {
	box_onTarget = onTarget;
	box_sprite.setTexture(onTarget ? box_on_target : only_box);
};

bool Box::loadTexture(const std::string& only_box_path, const std::string& box_on_target_path) {
	bool flag1 = only_box.loadFromFile(only_box_path);
	bool flag2 = box_on_target.loadFromFile(box_on_target_path);
	return flag1 && flag2;
}

//æ≤Ã¨±‰¡ø
sf::Texture Box::only_box;
sf::Texture Box::box_on_target;