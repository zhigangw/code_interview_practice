//https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/
/* the order is: prev2, prev1, num  */
#include <vector>
using namespace std;
int rob_dp(vector<int> nums) {
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

int rob_rs(vector<int>& nums, int i) {
    if (i < 0) {
        return 0;
    }
    return max(rob_rs(nums, i - 2) + nums[i], rob_rs(nums, i - 1));
}

int rob(vector<int>& nums) {
    return rob_rs(nums, (int)nums.size() - 1);
}
