#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <list>

using namespace std;

void oview(vector<int>& a, list<int>& o) {
    int max = -1;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] > max) {
            max = a[i];
            o.push_front(i);
        }
    }
}