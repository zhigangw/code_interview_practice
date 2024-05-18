struct node
{
    void *value;
    node *left;
    node *right;
};

void tree_to_list(node *root, node *&first, node *&last)
{
    // do in-order depth first traverse
    if (!root)
    {
        first = nullptr;
        last = nullptr;
        return;
    }
    // if the left node is not empty, traverse the left node;
    node *l_first = nullptr, *l_last = nullptr;
    if (root && root->left)
        tree_to_list(root->left, l_first, l_last);
    if (root && !root->left)
    {
        l_first = root;
    }
    // handle the node pointers

    // if the right node is not empty, traverse the right node.
    node *r_first = nullptr, *r_last = nullptr;
    if (root && root->right)
        tree_to_list(root->right, r_first, r_last);
    if (root && !root->right)
    {
        r_first = root;
    }

    root->left = l_last;
    root->right = r_first;
    first = l_first;
    last = r_last;
}