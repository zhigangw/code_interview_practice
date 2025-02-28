#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility> // for pair
#include <queue> // for queue and priority_queue
#include <stack>
#include <string>
#include <sstream> // include sstream for stringstream

using namespace std;


void k_closest_points(vector<pair<int, int>>& a, int k, vector<pair<int, int>>& result) {
    auto comp = [&a](int n1, int n2) { return (a[n1].first ^ 2 + a[n1].second ^ 2) < (a[n2].first ^ 2 + a[n2].second ^ 2); };
    priority_queue<int, vector<int>, decltype(comp)> heap(comp);

    for (int i = 0; i < a.size(); i++) {
        heap.push(i);
        while (heap.size() > k) {
            heap.pop();
        }
    }
    while (!heap.empty()) {
       result.push_back(a[heap.top()]);
        heap.pop();
    }
}