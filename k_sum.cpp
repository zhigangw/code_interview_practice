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

using namespace std;

int ksum(int a[], int size, int k) {
    //define a hash map to record the frequency of a sum
    unordered_map<int, int> sums;

    //if the sum -k happened before, the elements in between sum up as k, we bump the counter
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
        if (sums.contains(sum - k)) {
            counter += sums[sum - k];
        }
        if (sums.contains(sum)) {
            sums[sum] += 1;
        }
        else {
            sums[sum] = 1;
        }
    }
    return counter;
}