/*
* You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/
/*
* SOLUTION:
* Update the a[i] with farest position the jumper can reach from a[i]
* Jump from a[0] and count the jumps until it reach the end
*/
#include <algorithm> 
#include <cmath>
using namespace std;
int jump_game_mini_steps(int a[], int length) {

	for (int i = 1; i < length; i++) {
		a[i] = max(a[i] + i, a[i - 1]);
	}
	int pos = 0;
	int jump = 0;
	while (pos < length) {
		jump++;
		pos = a[pos];
	}
	return jump;
}