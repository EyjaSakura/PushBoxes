#include"common/Resources.h"

const sf::Font& Resources::getMainFont() {
    static sf::Font font;
    static bool loaded = false;
    if (!loaded) {
        if (!font.openFromFile(cfg::TEST_FONT_PATH))
            throw std::runtime_error("�������ʧ��");
        loaded = true;
    }
    return font;
}

void Resources::loadAllTexture() {
	//��������
	bool src_flag = false;
	if (!Box::loadTexture(cfg::BOX_PATH, cfg::BOX_ON_TARGET_PATH)) {
		std::cerr << "����������ش���" << std::endl;
		src_flag = true;
	}
	if (!Player::loadTexture(cfg::PLAYER_PATH, cfg::PLAYER_ON_TARGET_PATH)) {
		std::cerr << "���������ش���" << std::endl;
		src_flag = true;
	}
	if (!Map::loadTexture(cfg::TARGET_PATH, cfg::WALL_PATH, cfg::SPACE_PATH)) {
		std::cerr << "��ͼ������ش���" << std::endl;
		src_flag = true;
	}
	if (src_flag) {
		std::cerr << "��Դ����ʧ��" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void Resources::loadAllAudio() {
	//��ʼ��bgm
	if (!Game::getBGM().openFromFile(cfg::BGM_PATH)) { std::cerr << "BGM�ļ�����ʧ��" << std::endl; }

	//��ʼ����Ч
	if (!Game::getWarningBuffer().loadFromFile(cfg::WARNING_PATH)) { std::cerr << "������ʾ������ʧ��" << std::endl; }
	else { Game::getWarningSound() = std::make_unique<sf::Sound>(Game::getWarningBuffer()); }
}