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

struct node {
    int value;
    node* left;
    node* right;
};

void traverse(node* root, int low, int high, int& sum) {
    if (root == nullptr) return;
    if (root->value > low) {
        traverse(root->left, low, high, sum);
    }

    if (root->value >= low && root->value <= high) {
        sum += root->value;
    }

    if (root->value < high) {
        traverse(root->right, low, high, sum);
    }
}

int range_sum(node* root, int low, int high) {
    int sum = 0;
    traverse(root, low, high, sum);
    return sum;
}