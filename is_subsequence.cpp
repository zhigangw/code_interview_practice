#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


bool is_sub(string s, string t) {
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    return i == s.size();
}