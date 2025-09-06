#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<memory>
#include"states/State.h"
#include"common/MapList.h"
#include"map/Map.h"
#include"common/Config.h"
#include<iostream>

enum class GameState { Start, Play, Pause, Victory };

class Game {
private:
	sf::RenderWindow window;
	std::unique_ptr<State> currentState;
	//��ͼ��Դ����
	MapList mapList{ cfg::MAP_DIR };
	std::size_t currentMapNum = 0;
	//��ͣ������Դ
	Map tempMap;
	bool isGamePaused{ false };
	//��Ƶ��Դ
	static sf::Music bgm_music;
	static sf::SoundBuffer warning_buffer;
	static std::unique_ptr<sf::Sound> warning_sound;
	//�ؿ�ʤ����������
	static sf::Texture victory_tex;
	static std::unique_ptr<sf::Sprite> victory_sprite;
public:
	Game();
	void run();
	void changeState(GameState nextState);
	sf::RenderWindow& getWindow() { return window; }
	//��ͼ��Դ����
	const MapList& getMaps()const { return mapList; }
	void setNextMap() { 
		if (currentMapNum < mapList.count() - 1) { ++currentMapNum; }
		else {
			std::cerr << "�Ѿ������һ����" << std::endl;
		}
	}
	void setPrevMap() { 
		if (currentMapNum > 0) { --currentMapNum; }
		else {
			std::cerr << "�Ѿ��ǵ�һ����" << std::endl;
		}
	}
	const std::string& getCurrentMapPath()const { return mapList.at(currentMapNum); }
	size_t getCurrentMapNum()const { return currentMapNum; }
	//������ͣ������Դ
	void saveMap(const Map& map) { tempMap = map; }
	const Map getTempMap()const { return tempMap; }
	void setGamePausedFlag() { isGamePaused = true; }
	void resetGamePausedFlag() { isGamePaused = false; }
	//������Ƶ��Դ
	static sf::Music& getBGM() { return bgm_music; }
	static sf::SoundBuffer& getWarningBuffer() { return warning_buffer; }
	static std::unique_ptr<sf::Sound>& getWarningSound() { return warning_sound; }
	//���ݹؿ�ʤ��������Դ
	static sf::Texture& getVictoryTexture() { return victory_tex; }
	static std::unique_ptr<sf::Sprite>& getVictorySprite() { return victory_sprite; }	//ֻ���ƶ���������ã����ܿ�������
};