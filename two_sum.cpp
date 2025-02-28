#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

void two_sum(vector<int>& nums, int target, int& ni, int& nj) {
    unordered_map<int, int> hashmap;

    for (int i = 0; i < nums.size(); i++) {
        hashmap[nums[i]] = i;
    }

    for (auto& num : hashmap) {
        if (hashmap.contains(target - num.first)) {
            ni = num.second;
            nj = hashmap[target - num.first];
            break;
        }
    }
}