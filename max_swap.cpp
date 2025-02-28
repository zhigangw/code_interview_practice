#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;

static inline void swap(string& s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int max_swap(int num) {
    string snum = to_string(num);
    char last_max = -1;
    char last_candidate = -1;
    char cur_max = snum.size() - 1;
    char current_candidate = snum.size() - 1;
    for (int i = snum.size() - 1; i >= 0; i--) {
        if (snum[i] > snum[cur_max]) {
            last_max = cur_max;
            cur_max = i;
            last_candidate = current_candidate;
            current_candidate = cur_max;
        }

        if (snum[i] < snum[current_candidate]) {
            current_candidate = i;
        }
    }

    if (current_candidate < cur_max) {
        swap(snum, current_candidate, cur_max);
    }
    else {
        if (last_candidate != -1 && last_max != -1 && last_candidate < last_max) {
            swap(snum, current_candidate, cur_max);
        }
    }
    return stoi(snum);
}