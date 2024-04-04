/*
* make the BST complete binary tree. use '#' to indicate the null pointers
*/
#include <string>
using namespace std;
struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};
void serialize_bst(TreeNode* root, string& os) {
	if (root == nullptr) {
		os.append("#");
	}
	else {
		os.append(to_string(root->value));
		serialize_bst(root->left, os);
		serialize_bst(root->right, os);
	}
}

void deserialize_bst(const char* s, int start, int end, TreeNode*& root) {
	if (start > end) return;
	if (s[start] == '#')
	{
		root = nullptr;
	}
	else {
		root = new TreeNode;
		root->value = (s[start] - '0');
		root->left = nullptr;
		root->right = nullptr;
		deserialize_bst(s, start + 1, end, root->left);
		deserialize_bst(s, start + 2, end, root->right);
	}

}