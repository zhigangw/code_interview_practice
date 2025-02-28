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

using namespace std;

int pick_random(int a[], int size) {
    vector<int> rlist;
    if (size == 0) return -1;
    if (size == 1) return 1;

    rlist.push_back(0); // starting
    int sum = 0;
    for (int i = 0; i < size - 1; i++) {
        rlist.push_back(a[i] + rlist.back());
        sum += a[i];
    }

    int ran = rand() % sum; // scale up to sum range
    int low = 0;
    int high = (int)rlist.size() - 1;
    int found = -1;
    while (low < high && found == -1) {
        int mid = low + high;
        if (ran < rlist[mid]) {
            high = mid - 1;
        }
        else if (rlist[mid] < ran) {
            if (ran < rlist[mid + 1]) {
                found = mid + 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            found = mid + 1;
        }
    }
    return found;
}