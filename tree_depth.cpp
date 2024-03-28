#include <map>
struct node {
	void* value;
	node* l;
	node* r;
};

int tree_depth(node* root, node* parent, std::map<void*, int>& depth_map) {
	if (!root) return 0;
	if (!parent) {
		depth_map[root] = 1;
		return 1;
	}
	int depth = 0;
	int l_depth = 0;
	if (root->l) {
		l_depth = tree_depth(root->l, root, depth_map);
	}
	int r_depth = 0;
	if (root->r) {
		r_depth = tree_depth(root->r, root, depth_map);
	}
	depth = std::max(l_depth, r_depth) + 1;
	depth_map[root] = depth;
	return depth;
}