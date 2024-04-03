/*
* find the pivot index
* first, we will assume we are at position 0 and employ two variables,
* one is set as the left sum, the other is set as the sum of the right sum.
* we move the position to right one by one and add the value in i-1 to the left sum
* and remove the value in i from the right sum, and we compare the right and left sum.
* repeat until we find the pivot
*/
#include <vector>
using namespace std;
int find_pivot(vector<int> a) {
    if (a.size() <= 0) return -1;
    int right_sum = 0;
    for (auto i = 0; i < a.size(); i++) {
        right_sum += a[i];
    }
    int left_sum = -a[0];
    for (int i = 0; a.size(); i++) {
        left_sum += a[i];
        right_sum -= a[i];
        if (right_sum == left_sum) return i;
    }
    return -1;
}