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

double pow(double x, int n) {
    if (n == 0)  return 1;
    if (n == 1) return x;
    if (n == -1) return 1 / x;

    if (n < 0) {
        return pow(x, -n);
    }

    if (n % 2 == 0) {
        return pow(x * x, n / 2);
    }

    else {
        return pow(x * x, n / 2) * x;
    }

}