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

void right_view(node* root, vector<int>& result) {
    if (root == nullptr) return;

    queue<node*> qu;
    qu.push(root);

    while (!qu.empty()) {
        int num = (int)qu.size();
        while (num > 0) {
            node* p = qu.front();
            if (p->left) {
                qu.push(p->left);
            }
            if (p->right) {
                qu.push(p->right);
            }
            if (num == 1) {// the last one and the right most one
                result.push_back(p->value);
            }
            qu.pop();
            num--;
        }
    }

}