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

int top_k_frequent(int a[], int size, int k) {
    unordered_map<int, int> frequency_map;
    for (int i = 0; i < size; i++) {
        if (frequency_map.contains(a[i]))
        {
            frequency_map[a[i]] += 1;
        }
        else
        {
            frequency_map[a[i]] = 1;
        }
    }

    auto comp = [&frequency_map](int n1, int n2) { return frequency_map[n1] > frequency_map[n2]; };

    priority_queue<int, vector<int>, decltype(comp)> heap(comp);
    for (auto itr = frequency_map.cbegin(); itr != frequency_map.cend(); itr++) {
        if (heap.size() < k) {
            heap.push(itr->first);
        }
        else {
            if (heap.top() < itr->first) {
                heap.pop();
                heap.push(itr->first);
            }
        }
    }
    return heap.top();
}