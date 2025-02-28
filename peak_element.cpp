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
int peak(int a[], int size) {

    int low = 0, high = size - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (a[mid] > a[mid + 1]) {// desecnding slope
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}