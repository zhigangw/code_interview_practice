/*
* we will scan the array and do the following
* using a variable, accumuliated, to record the accumulated product by far
* compare the accumulated * the current and and accumulated, remember the maximum as max1.
* we then need to do in the reverse direction to collect the max2,
* and then return the larger value of two.
*/
#include <stdlib.h>
using namespace std;
int max_product(int* a, int size) {
    int max = a[0];
    int prod = 1;
    for (int i = 0; i < size; i++) {
        prod *= a[i];
        max = max > prod ? max : prod;
        if (prod == 0) prod = 1;
    }
    //scan from the reversed direction
    prod = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        prod *= a[i];
        max = max > prod ? max : prod;
        if (prod == 0) prod = 1;
    }
    return max;
}
