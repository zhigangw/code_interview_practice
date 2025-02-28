#include <iostream>
#include <memory>
#include <map>
#include <vector>
using namespace std;


void v_traverse(int a[], int size, int root, int row, int col, map<int, unique_ptr<map<int, int>> >& nodes) {
    if (root >= size) return;
    if (!nodes[col]) nodes[col] = make_unique<map<int, int>>();
    (*nodes[col])[row] = a[root];
    v_traverse(a, size, root * 2 + 1, row++, col--, nodes);
    v_traverse(a, size, root * 2 + 2, row++, col++, nodes);
}

void traverse(int a[], int size) {
    map<int, unique_ptr<map<int, int>> > nodes;
    v_traverse(a, size, 0, 0, 0, nodes);
    for (auto nitr = nodes.cbegin(); nitr != nodes.cend(); nitr++) {
        if (nitr->second) {
            for (auto jitr = nitr->second->cbegin(); jitr != nitr->second->cend(); jitr++) {
                //visit(jitr->second);
            }
        }
    }
}
