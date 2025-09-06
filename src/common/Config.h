#pragma once
#include <string>

namespace cfg {
	//游戏标题
	inline const std::string GAME_TITLE = "Push Box";

	// 资源根目录
	inline const std::string RES = "src/media_src";

	// 图片
	inline const std::string BOX_PATH = RES + "/image/box.jpg";
	inline const std::string BOX_ON_TARGET_PATH = RES + "/image/boxOnTarget.jpg";
	inline const std::string PLAYER_PATH = RES + "/image/player.jpg";
	inline const std::string PLAYER_ON_TARGET_PATH = RES + "/image/playerOnTarget.jpg";
	inline const std::string TARGET_PATH = RES + "/image/target.jpg";
	inline const std::string WALL_PATH = RES + "/image/wall.jpg";
	inline const std::string SPACE_PATH = RES + "/image/space.jpg";
	//inline const std::string UNDEFINE_PATH = RES + "/image/undefine.jpg";
	//inline const std::string DFS_PATH = RES + "/image/dfs.jpg";
	inline const std::string VICTORY_SCREEN = RES + "/image/victory.jpg";

	// 地图
	inline const std::string MAP_DIR = RES + "/maps";

	// 音频
	inline const std::string BGM_PATH = RES + "/audio/bgm.MP3";
	inline const std::string WARNING_PATH = RES + "/audio/warning.wav";

	// 字体
	inline const std::string TEST_FONT_PATH = RES + "/font/SourceHanSansSC-Normal.ttf";

	// 地图字符常量
	constexpr char BOX_CHAR = '$';
	constexpr char BOX_ON_TARGET_CHAR = '*';
	constexpr char PLAYER_CHAR = '@';
	constexpr char PLAYER_ON_TARGET_CHAR = '+';
	constexpr char TARGET_CHAR = '.';
	constexpr char WALL_CHAR = '#';
	constexpr char SPACE_CHAR = ' ';
	constexpr char UNDEFINE_CHAR = '-';
	constexpr char DFS_CHAR = '=';
} // namespace cfg