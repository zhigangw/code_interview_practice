#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

int closest_in_bst(node* root, int target) {
    if (root == nullptr) return -1;

    node* p = root;
    int closest = root->value;
    while (p) {
        if (abs(target - p->value) > abs(target - closest)) {
            closest = p->value;
        }

        if (target < p->value) {
            p = p->left;
        }
        else if (p->value < target) {
            p = p->right;
        }
        else {
            break;
        }
    }
    return closest;
}