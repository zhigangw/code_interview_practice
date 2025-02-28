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

int dot_product(map<int, int>& a, map<int, int>& b) { // map is a sorted hash table
    auto aitr = a.cbegin();
    auto bitr = b.cbegin();
    int result = 0;
    while (aitr != a.cend() && bitr != b.cend()) {
        if (aitr->first < bitr->first) {
            result += aitr->second;
            aitr++;
        }
        else if (bitr->first < aitr->first) {
            result += bitr->second;
            bitr++;
        }
        else {
            result += (aitr->second * bitr->second);
            aitr++;
            bitr++;
        }
    }
    while (aitr != a.cend()) {
        result += aitr->second;
        aitr++;
    }
    while (bitr != b.cend()) {
        result += bitr->second;
        bitr++;
    }
    return result;
}