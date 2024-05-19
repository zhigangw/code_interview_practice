/*
* You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). 
You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). 
A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.
Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. 
If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.
The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2)
*/

/*
* SOLUTION:
* scan the list. 
* for all the valid points, compute the Manhattan distance, if the value is smaller than the current one, remember the index. 
*/
const int MAX_INT = 2 << 31 - 1;
#include <cmath>
using namespace std;
int nearest_point(int x, int y, int a[][2], int length) {
	int smallest = MAX_INT;
	int index = -1;
	for (int i = 0; i < length; i++) {
		if (a[i][0] == x || a[i][1] == y) {
			int md = abs(a[i][0] - x) + abs(a[i][1] - y);
			if (md < smallest) {
				smallest = md;
				index = i;
			}
		}
	}
	return index;
}