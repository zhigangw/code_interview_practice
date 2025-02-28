#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void collect_intervals(vector<pair<int, int>>& a, vector<pair<int, int>>& b, vector<pair<int, int>>& collected) {
    int start = 0;
    int end = 0;
    auto i = 0;
    auto j = 0;
    while (i < a.size() && j < b.size()) {
        start = max(a[i].first, b[j].first);
        end = min(a[i].second, b[j].second);
        if (start < end) { //there is an interval, let's collect.
            collected.push_back(make_pair(start, end));
        }
        if (a[i].second > b[j].second) {
            i++;
        }
        else {
            j++;
        }
    }
    while (i < a.size()) {
        collected.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        collected.push_back(b[j]);
        j++;
    }
}