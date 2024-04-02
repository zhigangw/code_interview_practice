#include <iostream>
#include <vector>
using namespace std;

/*
* for each node, if it is 1, use dfs to travers all the ajacent points(1), change the 1 to 0 to avoid re-visit.
* count the number of connected components
*/
void erase_lands(vector<vector<int>>& map, int i, int j) {
    if (i < 0 || i >= map.size() || j < 0 || j >= map.size()) return;
    if (map[i][j] == 0) return;
    map[i][j] = 0;
    erase_lands(map, i - 1, j); // left
    erase_lands(map, i, j - 1); // up
    erase_lands(map, i + 1, j); // right
    erase_lands(map, i, j + 1); // down
}

int num_of_islands(vector<vector<int>>& map) {
    int num_of_islands = 0;
    for (auto i = 0; i < map.size(); i++) {
        for (auto j = 0; j < map.size(); j++)
        {
            if (map[i][j]) {
                num_of_islands++;
                erase_lands(map, i, j);
            }
        }
    }
    return num_of_islands;
}