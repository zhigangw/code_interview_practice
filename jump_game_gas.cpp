/*
* You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/
/*
* SOLUTION:
* Start from the 0 position, use g, which initialized by the a[0] to represent the remaining gas enable you to move forward for g positions. 
* If g > 0, you can move one step, and g--;
* Once after a move, update g with max(g, a[i])
* if g <=0 but you still have not reach the last element, you fail.  
*/
#include <algorithm> 
#include<cmath>
using namespace std;
bool jump_game(int a[], int length) {
	if (a == nullptr || length <= 0) return false;
	int g = a[0];
	int i = 0;
	while (g > 0 && i < length)
	{
		g = max(g, a[i]);
		g--;
		i++;
	}
	return (i == length);
}