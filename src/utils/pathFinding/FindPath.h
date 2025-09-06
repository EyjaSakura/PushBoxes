#include"common/Position.h"
#include"map/Map.h"
#include<vector>

namespace FindPath {
	bool find_path_DFS(Map&, const Position&, const Position&, std::vector<Position>&);
}