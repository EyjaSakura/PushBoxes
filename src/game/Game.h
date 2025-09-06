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
	//地图资源管理
	MapList mapList{ cfg::MAP_DIR };
	std::size_t currentMapNum = 0;
	//暂停界面资源
	Map tempMap;
	bool isGamePaused{ false };
	//音频资源
	static sf::Music bgm_music;
	static sf::SoundBuffer warning_buffer;
	static std::unique_ptr<sf::Sound> warning_sound;
	//关卡胜利界面纹理
	static sf::Texture victory_tex;
	static std::unique_ptr<sf::Sprite> victory_sprite;
public:
	Game();
	void run();
	void changeState(GameState nextState);
	sf::RenderWindow& getWindow() { return window; }
	//地图资源管理
	const MapList& getMaps()const { return mapList; }
	void setNextMap() { 
		if (currentMapNum < mapList.count() - 1) { ++currentMapNum; }
		else {
			std::cerr << "已经是最后一关了" << std::endl;
		}
	}
	void setPrevMap() { 
		if (currentMapNum > 0) { --currentMapNum; }
		else {
			std::cerr << "已经是第一关了" << std::endl;
		}
	}
	const std::string& getCurrentMapPath()const { return mapList.at(currentMapNum); }
	size_t getCurrentMapNum()const { return currentMapNum; }
	//处理暂停界面资源
	void saveMap(const Map& map) { tempMap = map; }
	const Map getTempMap()const { return tempMap; }
	void setGamePausedFlag() { isGamePaused = true; }
	void resetGamePausedFlag() { isGamePaused = false; }
	//处理音频资源
	static sf::Music& getBGM() { return bgm_music; }
	static sf::SoundBuffer& getWarningBuffer() { return warning_buffer; }
	static std::unique_ptr<sf::Sound>& getWarningSound() { return warning_sound; }
	//传递关卡胜利界面资源
	static sf::Texture& getVictoryTexture() { return victory_tex; }
	static std::unique_ptr<sf::Sprite>& getVictorySprite() { return victory_sprite; }	//只能移动构造或传引用，不能拷贝构造
};