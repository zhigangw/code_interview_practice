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

int sum_root(node* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    if (root->left) {
        sum += (root->value * 10) + sum_root(root->left);
    }
    if (root->right) {
        sum += (root->value * 10) + sum_root(root->right);
    }
    if (root->right == nullptr && root->left == nullptr) {
        sum = root->value;
    }
    return sum;
}