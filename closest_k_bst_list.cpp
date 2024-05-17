/*
* closest kth elements in binary search tree / sorted array
* we can take use of the property of the BST and sorted array.
* we can maintain a linked list with size k, and continue to push
* the elements in ascending order when the number of the elements
* in the list is less than k.
* after the number of the elements is greater than k, we will compare
* the abs different between the target and the value, and the top and bottom elements.
* If the abs different is less than the one for the front, we pop up the front one,
* and push it to the bottom.
* if the abs differnt is greater than the front one, we find all the k element and stop.
*/

#include <cmath>
#include <list>
#include <stdlib.h>
using namespace std;
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

void find_k_closest(TreeNode* root, int k, double x, list<int>& closest) {
    if (root == nullptr) return;
    find_k_closest(root->left, k, x, closest);
    if (closest.size() < k)
    {
        closest.push_back(root->value);
    }
    else {
        double abs_diff = abs(x - root->value);
        if (abs_diff < abs(x - closest.front())) {
            closest.pop_front();
            closest.push_back(root->value);
        }
    }
    find_k_closest(root->right, k, x, closest);
}