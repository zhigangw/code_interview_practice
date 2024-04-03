//https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/
/* the order is: prev2, prev1, num  */
#include <vector>
using namespace std;
int rob(vector<int> nums) {
    if (nums.size() == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}