#include"things/player/Player.h"


Player::Player() : player_pos{ 0,0 }, player_onTarget(false), player_sprite(only_player) {
	player_sprite.setPosition({ 0.f, 0.f });
}
Player::Player(Position pos, bool onTarget) :player_pos(pos), player_onTarget(onTarget), player_sprite(onTarget ? player_on_target : only_player) {
	player_sprite.setPosition({ pos.y * 100.f, pos.x * 100.f });
}
Player::Player(int x, int y, bool onTarget) :player_pos{ x,y }, player_onTarget(onTarget), player_sprite(onTarget ? player_on_target : only_player) {
	player_sprite.setPosition({ y * 100.f, x * 100.f });
}

Position Player::getPosition()const { return player_pos; }
void Player::setPosition(const Position pos, bool onTarget) {
	player_pos = pos;
	this->setOnTarget(onTarget);
	player_sprite.setPosition({ pos.y * 100.f,pos.x * 100.f });
};

bool Player::getOnTarget()const { return player_onTarget; };
void Player::setOnTarget(const bool onTarget) {
	player_onTarget = onTarget;
	player_sprite.setTexture(onTarget ? player_on_target : only_player);
};

sf::Sprite Player::getSprite()const { return player_sprite; };

bool Player::loadTexture(const std::string& only_player_path, const std::string& player_on_target_path) {
	bool flag1 = only_player.loadFromFile(only_player_path);
	bool flag2 = player_on_target.loadFromFile(player_on_target_path);
	return flag1 && flag2;
}

//æ≤Ã¨±‰¡ø
sf::Texture Player::only_player;
sf::Texture Player::player_on_target;