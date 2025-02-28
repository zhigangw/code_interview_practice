#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

void merge_interval(vector<pair<int, int>>& a, vector<pair<int, int>>& merged) {
    if (a.size() == 0) return;

    sort(a.begin(), a.end());

    pair<int, int> current = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (!(current.second < a[i].first || current.first > a[i].second)) {// there is an overlap, pick it up.
            current.first = min(current.first, a[i].first);
            current.second = max(current.second, a[i].second);
        }
        else {//no overlap, push the current into the merged.
            merged.push_back(current);
            current = a[i];
            i++;
        }
    }

}
