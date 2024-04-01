struct TreeNode
{
	int value;
	TreeNode* pleft;
	TreeNode* pright;
};
class Stack
{
public:
	Stack() {}
	~Stack() {}
	void push(int n) {
	}
	int pop() {
		return 0;
	}
	int top() {
		return 0;
	}
	int size() {
		return 0;

	}
private:

};

static inline double abs(double x) {
	return x > 0 ? x : -x;
}
void in_order_traverse_bst(TreeNode* root, double x, Stack& stack, bool reverse) {
	if (root == nullptr) return;
	in_order_traverse_bst(reverse ? root->pright : root->pleft, x, stack, reverse);
	if (!reverse) {
		if (root->value < x) { return; }
	}
	else {
		if (root->value > x) { return; }
	}
	stack.push(root->value);
	in_order_traverse_bst(reverse ? root->pleft : root->pright, x, stack, reverse);

}

void find_closet_k_bst(TreeNode* root, double x, int k) {
	Stack sn;
	Stack ss;
	in_order_traverse_bst(root, x, sn, false);
	in_order_traverse_bst(root, x, sn, true);
	while (k > 0 && (sn.size() > 0 || ss.size() > 0)) {
		if (sn.size() <= 0) {
			ss.pop();
		}
		else if (ss.size() <= 0) {
			sn.pop();
		}
		else {
			if (abs(sn.top() - x) < abs(ss.top() - x)) {
				sn.pop();
			}
			else
			{
				ss.pop();
			}
		}
		k--;
	}
}