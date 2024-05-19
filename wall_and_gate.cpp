/*
* You are given an m x n grid rooms initialized with these three possible values.
-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
*/

/*
* SOLUTION:
* scan the grids. once run into a gate, put the grids around it into a queue and mark them as 1 in the grid. 
* for the cells in the queue, collect the cells around it and accessible from the cell, and 
* 1) mark the arounding cells'value as min(cell_value + 1, current_arounding_cell_value); 
* 2) put the around cells into the queue if they have not been visited.(the current_arounding_cell_value is INF)
*/

#include<queue>
using namespace std;
const int inf = 2147483647;
void wall_and_gate(int **a, int width, int height) {
	queue<int> helper_queue;
	for (int w = 0; w < width;w++) {
		for (int h = 0; h < height; h++) {
			if (a[w][h] == 0) {
				if (w - 1 >= 0) {
					if (a[w - 1][h] == inf)//not visited
					{
						a[w - 1][h] = 1;
						helper_queue.push((w - 1) * height + h);
					}
				}
				if (h - 1 >= 0) {
					if (a[w][h - 1] == inf) {
						a[w][h - 1] = 1;
						helper_queue.push(w * height + h - 1);
					}
				}
				if (w + 1 < width) {
					if (a[w + 1][h] == inf) {
						a[w + 1][h] = 1;
						helper_queue.push((w + 1)*height + h);
					}
				}
				if (h + 1 < height) {
					if (a[w][h + 1] == inf) {
						a[w][h + 1] = 1;
						helper_queue.push(w *height + h + 1);
					}
				}
			}
		}
	}
	while (helper_queue.size() > 0) {
		int v = helper_queue.front();
		int w = v / height;
		int h = v % height;
		if (w - 1 >= 0) {
			if (a[w - 1][h] == inf) {
				helper_queue.push((w - 1) * height + h);
				a[w - 1][h] = a[w][h] + 1;
			}
			else {
				a[w - 1][h] = min(a[w - 1][h], a[w][h] + 1);
			}
		}
		if (h - 1 >= 0) {
			if (a[w][h - 1] == inf) {
				helper_queue.push((w) * height + h - 1);
				a[w][h - 1] = a[w][h] + 1;

			}
			else {
				a[w][h - 1] = min(a[w][h - 1], a[w][h] + 1);
			}
		}
		if (w + 1 < width) {
			if (a[w + 1][h] == inf) {
				helper_queue.push((w + 1) * height + h);
				a[w + 1][h] = a[w][h] + 1;

			}
			else {
				a[w + 1][h] = min(a[w + 1][h], a[w][h] + 1);
			}
		}
		if (h + 1 < height) {
			if (a[w][h + 1] == inf) {
				helper_queue.push((w) * height + h + 1);
				a[w][h + 1] = a[w][h] + 1;

			}
			else {
				a[w][h] = min(a[w][h + 1], a[w][h] + 1);
			}
		}
		helper_queue.pop();
	}
}

