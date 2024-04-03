/*
* Valid Triangle Number
* The condition to make three lines as a valid triangle is that a+b>c
* we can sort the numbers ascendingly first.
* we use three pointers, i, starting from 0, j, starting from k - 1, k, starting from the end of the array.
* if l[i] + l[j] > l[k], the line between i and j with the k as the 3rd line are all valid, count them, and move j to j - 1.
* otherwise, we move i to i + 1;
* we repeat the above until i>=j, we move k to k -1 and repeat.
*/
#include <algorithm>
#include <vector>
using namespace std;
int valid_triangle_number(vector<int>& lines) {
    sort(lines.begin(), lines.end());
    int count = 0;
    for (int k = (int)lines.size() - 1; k >= 2; k++) {
        int i = 0;
        int j = k - 1;
        while (i < j) {
            if (lines[i] + lines[j] > lines[k]) {
                count += (j - i);
                j--;
            }
            else {
                i++;
            }
        }
    }
    return count;
}