//https://leetcode.com/problems/max-points-on-a-line/solutions/3016390/c-easy-beats-approx-100-explanation/
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

int max_point(vector<pair<int, int>>& points) {
	//create a hash map, where the key is the slope, the value is the list of the points which connecting to the first point with same slope
	//we store the slope using it value multipled by 100 and save the interger
	int max_points = 0;
	map<int, set<pair<int, int>> > slope_point_map;
	for (auto i = points.begin(); i < points.end(); i++) {
		for (auto j = i + 1; j < points.end(); j++) {
			int slope = (int)((abs(i->second - j->second) == 0 ? INT32_MAX : (i->first - j->first) / (i->second - j->second) * 100));
			if (!slope_point_map.contains(slope))
			{
				slope_point_map[slope] = {};
			}
			slope_point_map[slope].insert(make_pair(i->first, i->second));
			slope_point_map[slope].insert(make_pair(j->first, j->second));
		}
	}

	for (auto x = slope_point_map.begin(); x != slope_point_map.end();x++) {
		if (max_points < x->second.size()) {
			max_points = (int)x->second.size();
		}
	}

	return max_points;
}