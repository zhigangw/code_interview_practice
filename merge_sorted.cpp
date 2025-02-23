#include <iostream>
#include <vector>

using namespace std;
void merge_sorted(vector<int>& a, vector<int>& b, vector<int>& o) {
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            o.push_back(a[i++]);
        }
        else {
            o.push_back(b[j++]);
        }
    }
    if (i < a.size()) {
        o.insert(o.end(), a.begin() + i, a.end());
    }
    if (j < b.size()) {
        o.insert(o.end(), b.begin() + j, b.end());
    }
}