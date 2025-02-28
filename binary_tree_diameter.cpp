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

using namespace std;

struct node {
	int value;
	node* left;
	node* right;
};

int find_diameter(node* root, int& max_diameter) {
	if (root == nullptr) return 0;
	int l = find_diameter(root->left, max_diameter);
	int r = find_diameter(root->right, max_diameter);
	max_diameter = max(max_diameter, l + r);
	return (l > r ? l : r) + 1;
}

int diameter(node* root) {
	int max_diameter = 0;
	find_diameter(root, max_diameter);
	return max_diameter;
}
