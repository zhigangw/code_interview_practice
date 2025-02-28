#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
bool valid_point(int** g, int width, int height, int r, int c) {
    return r >= 0 && c >= 0 && r < height && c < width && g[r][c] == 0;
}
int shortest_path_binary_graph(int** g, int start_row, int start_column, int end_row, int end_column, int width, int height) {
    //do BST graph using queue
    queue<pair<int, int>> visiting;
    int level = 0;
    int r = start_row;
    int c = start_column;

    if (valid_point(g, width, height, start_row, start_row)) {
        visiting.push(make_pair(r, c));
    }

    while (!visiting.empty()) {
        auto current = visiting.front();
        r = current.first;
        c = current.second;
        g[r][c] = level + 1;

        if (r == end_row && c == end_column) break;

        //check the points around
        for (int ro = -1; ro <= 1; ro++) {
            for (int co = -1; co <= 1; co++) {
                if (valid_point(g, width, height, r + ro, c + co)) {
                    visiting.push(make_pair(r + ro, c + co));
                }
            }
        }
        level++;
        visiting.pop();
    }
    return level;
}