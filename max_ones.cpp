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

int max_ones(int a[], int size, int k) {
    int left = 0;
    int right = 0;
    int counter = 0;
    while (right < size) {
        while (right < size && (a[right] == 1 || k > 0)) {
            right++;
            counter += a[right];
            k -= a[right] == 1 ? 0 : 1;
        }

        while (left < right && a[left] == 1) {
            counter--;
            left++;
        }
        while (left < right && a[left] != 1) {
            k++;
            left++;
        }
    }
    return counter;
}