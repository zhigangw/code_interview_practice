/*
* You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.
*/
/*
* SOLUTION:
* use unsorted_sets to represent islands to collect '1' in grid 2.
* enumerate the '1's in the islands in grid2 to see if they are '1's in grid 1  
*/

#include <unordered_set>
using namespace std;

int dfs_island(int** a, int** b, int width, int height, int w, int h) {
	if (w < 0 || h < 0 || w >= width || h >= height) return 0;
	
	if (a[w][h] == 0 || b[w][h] == 0) return 0;
	b[w][h] = 0; //marked it as non-island to avoid duplicated counting.

	return
		dfs_island(a, b, width, height, w - 1, h) +
		dfs_island(a, b, width, height, w, h - 1) +
		dfs_island(a, b, width, height, w + 1, h) +
		dfs_island(a, b, width, height, w, h + 1) +
		1;
}
int sub_islands(int** a, int** b, int width, int height) {
	int number_of_island = 0;
	for (int w = 0; w < width; w++) {
		for (int h = 0; h < height; h++) {
			if (b[w][h] == 1) {
				number_of_island += dfs_island(a, b, width, height, w, h);
			}
		}
	}
	return number_of_island;
}