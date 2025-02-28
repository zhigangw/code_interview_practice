#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;


void group_shifted(vector<string>& a, vector<vector<string>>& result) {
    unordered_map<string, vector<string>> hashmap;

    for (int j = 0; j < a.size(); j++) {
        // make copy of s from a
        string s = a[j];

        for (int i = 0; i < s.size(); i++) {
            int gap = s[i] - 'a';
            s[i] -= gap;
        }
        hashmap[s].push_back(a[j]);
    }

    for (auto& ss : hashmap) {
        result.push_back(ss.second);
    }

}
