
const int N = 100;
struct TreeNode {
    int value;
    TreeNode* child[N];
};

int caculate_tree_diameter(TreeNode* root, int& current_max) {
    // DFS to caculate the diameter of the each child.
    // Keep the largest and second largest on to caculate the diameter of the tree
    // compare with the the max_diameter
    if (root == nullptr)
        return 0;
    int first_diameter = 0;
    int second_diameter = 0;
    for (int i = 0; i < N; i++) {
        int diameter = caculate_tree_diameter(root->child[i], current_max);
        if (diameter > first_diameter) {
            first_diameter = diameter;
        }
        else if (diameter > second_diameter) {
            second_diameter = diameter;
        }
    }
    if (first_diameter + second_diameter > current_max) {
        current_max = first_diameter + second_diameter;
    }
    return current_max;
}