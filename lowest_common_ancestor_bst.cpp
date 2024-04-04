//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/64963/3-lines-with-o-1-space-1-liners-alternatives/
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; }
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) { return nullptr; }
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    else {
        return root;
    }
}