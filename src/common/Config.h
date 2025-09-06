#pragma once
#include <string>

namespace cfg {
	//��Ϸ����
	inline const std::string GAME_TITLE = "Push Box";

	// ��Դ��Ŀ¼
	inline const std::string RES = "src/media_src";

	// ͼƬ
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

	// ��ͼ
	inline const std::string MAP_DIR = RES + "/maps";

	// ��Ƶ
	inline const std::string BGM_PATH = RES + "/audio/bgm.MP3";
	inline const std::string WARNING_PATH = RES + "/audio/warning.wav";

	// ����
	inline const std::string TEST_FONT_PATH = RES + "/font/SourceHanSansSC-Normal.ttf";

	// ��ͼ�ַ�����
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