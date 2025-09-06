#include"common/Resources.h"

const sf::Font& Resources::getMainFont() {
    static sf::Font font;
    static bool loaded = false;
    if (!loaded) {
        if (!font.openFromFile(cfg::TEST_FONT_PATH))
            throw std::runtime_error("字体加载失败");
        loaded = true;
    }
    return font;
}

void Resources::loadAllTexture() {
	//加载纹理
	bool src_flag = false;
	if (!Box::loadTexture(cfg::BOX_PATH, cfg::BOX_ON_TARGET_PATH)) {
		std::cerr << "箱子纹理加载错误" << std::endl;
		src_flag = true;
	}
	if (!Player::loadTexture(cfg::PLAYER_PATH, cfg::PLAYER_ON_TARGET_PATH)) {
		std::cerr << "玩家纹理加载错误" << std::endl;
		src_flag = true;
	}
	if (!Map::loadTexture(cfg::TARGET_PATH, cfg::WALL_PATH, cfg::SPACE_PATH)) {
		std::cerr << "地图纹理加载错误" << std::endl;
		src_flag = true;
	}
	if (src_flag) {
		std::cerr << "资源加载失败" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void Resources::loadAllAudio() {
	//初始化bgm
	if (!Game::getBGM().openFromFile(cfg::BGM_PATH)) { std::cerr << "BGM文件加载失败" << std::endl; }

	//初始化音效
	if (!Game::getWarningBuffer().loadFromFile(cfg::WARNING_PATH)) { std::cerr << "警告提示音加载失败" << std::endl; }
	else { Game::getWarningSound() = std::make_unique<sf::Sound>(Game::getWarningBuffer()); }
}