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

void custom_sort(char order[], int o_size, char s[], int s_size, vector<char> output) {
    unordered_map<char, int> fre_map;
    for (int i = 0; i < o_size; i++) {
        fre_map[order[i]] = 0;
    }

    for (int j = 0; j < s_size; j++) {
        char c = s[j];
        if (fre_map.contains(c)) {
            fre_map[c] += 1;
        }
        else {
            fre_map[c] = 1;
        }
    }

    for (auto itr = fre_map.cbegin(); itr != fre_map.cend(); itr++) {
        int counter = itr->first;
        while (counter > 0) {
            //produce itr->second;
            output.push_back(itr->second);
        }
    }
    return;
}