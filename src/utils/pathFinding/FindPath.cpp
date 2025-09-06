#include"utils/pathFinding/FindPath.h"

bool FindPath::find_path_DFS(Map& map, const Position& cur, const Position& goal, std::vector<Direction>& path) {
	if (cur == goal) return true;

    struct DirCost { Direction dir; int cost; };
    DirCost dirs[4] = {
        {UP,    cur.move(UP).manhattan(goal)},
        {RIGHT, cur.move(RIGHT).manhattan(goal)},
        {DOWN,  cur.move(DOWN).manhattan(goal)},
        {LEFT,  cur.move(LEFT).manhattan(goal)}
    };

    std::sort(std::begin(dirs), std::end(dirs),
        [](const DirCost& a, const DirCost& b) { return a.cost < b.cost; });

    map.changeMapEle(cur, cfg::DFS_CHAR);
    for (auto& dirCost : dirs) {
        Position next = cur.move(dirCost.dir);
        if (!map.isSpace(next) && !map.isOnTarget(next)) continue;
        path.push_back(dirCost.dir);
        if (find_path_DFS(map, next, goal, path)) return true;
        path.pop_back();
    }
    map.changeMapEle(cur, cfg::SPACE_CHAR);
    return false;
}