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

node* traverse(node* root, bool left, node*& head_or_tail) {
    if (root == nullptr) return nullptr;
    node* left_head = nullptr;
    if (root->left) {
        node* left_max = traverse(root->left, true, left_head);
        if (left_max) {
            left_max->right = root;
        }
        root->left = left_max;
    }
    else {
        left_head = root;
    }

    node* right_tail = nullptr;
    if (root->right) {
        node* right_min = traverse(root->right, false, right_tail);
        if (right_min) {
            right_min->left = root;
        }
        root->right = right_min;
    }
    else {
        right_tail = root;
    }

    if (left) {
        head_or_tail = left_head;
        return right_tail;
    }
    else {
        head_or_tail = right_tail;
        return left_head;
    }
}

node* bst2linkedlist(node* root) {
    if (root == nullptr) return nullptr;
	node* head = nullptr;
    node* left_max = traverse(root->left, true, head);
    if (left_max) {
        left_max->right = root;
    }
    root->left = left_max;
	node* tail = nullptr;
    node* right_min = traverse(root->right, false, tail);
    if (right_min) {
        right_min->left = root;
    }
    root->right = right_min;
	return head;
}