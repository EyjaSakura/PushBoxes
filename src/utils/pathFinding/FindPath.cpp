#include"utils/pathFinding/FindPath.h"

bool FindPath::find_path_DFS(Map& map_copy, const Position& cur, const Position& goal, std::vector<Position>& path) {
	if (cur == goal) { 
		return true;
	}
	map_copy.changeMapEle(cur, cfg::DFS_CHAR);
	static const Direction dirs[] = { UP, RIGHT, DOWN, LEFT };
	for (Direction dir : dirs) {
		Position next = cur.move(dir);
		if (!map_copy.isSpace(next) && !map_copy.isOnTarget(next)) { continue; }
		path.push_back(next);
		if (FindPath::find_path_DFS(map_copy, next, goal, path)) { return true; }
		path.pop_back();
	}
	map_copy.changeMapEle(cur, cfg::SPACE_CHAR);
	return false;
}