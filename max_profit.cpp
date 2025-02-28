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

int max_profit(int a[], int size) {
    int minval = a[0];
    int max_profit = 0;
    for (int i = 0; i < size; i++) {
        if (minval > a[i]) {
            minval = a[i];
        }
        if (max_profit < a[i] - minval) {
            max_profit = a[i] - minval;
        }
    }
    return max_profit;
}