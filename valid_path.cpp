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

string valid_path(string path) {
    vector<string> stack;
    stringstream ss(path); // initialize stringstream
    string temp;
    while (getline(ss, temp, '/')) {
        if (temp == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else if (temp == "." || temp.empty()) {
            continue;
        } else {
            stack.push_back(temp);
        }
    }

    string result;
    while (!stack.empty()) {
        result = '/' + stack.back() + result;
        stack.pop_back();
    }
    if (result.empty()) {
        result = '/';
    }
    return result;
}