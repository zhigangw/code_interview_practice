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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int do_find(TreeNode* root, TreeNode* n1, TreeNode* n2, int level, int& max_level, TreeNode*& lca_node) {
    int result = 0;
    bool found_n1 = false;
    bool found_n2 = false;
    int fm = 0;
    if (root == nullptr) return 0; // not found any

    if (root == n1 || root == n2) {
        fm = 1;
    }

    int fl = do_find(root->left, n1, n2, level + 1, max_level, lca_node);
    int fr = do_find(root->right, n1, n2, level + 1, max_level, lca_node);

    result = fl + fr + fm;

    if (result == 2) {
        if (max_level < level) {
            max_level = level;
            lca_node = root;
        }
    }
    return result;
}

TreeNode* find_lca(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    TreeNode* lca_node = nullptr;
    int max_level = -1;
    int result = do_find(root, n1, n2, 0, max_level, lca_node);

    return lca_node;
}