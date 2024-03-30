/*
We will have double linked lists,to keep the elements in the order when they are pushed in, so we can easily implement the stack functions like pop()
We will also need a binary search tree, by which we easily maintain the order of the values and find the max and min
-- the key is that once we pop out the top element, we need update the BST so the peekMax and peekMin will still work.
*/
struct TreeNode
{
	int value = 0;
	TreeNode* p_left = nullptr;
	TreeNode* p_right = nullptr;
};

//consider priority queue during interview
class BinarySearchTree {
public:
	void insert(int v) {
		TreeNode* p_new_note = new TreeNode;
		p_new_note->value = v;
		if (p_root == nullptr) {
			p_root = p_new_note;
		}
		else
		{
			TreeNode* p = this->p_root;
			TreeNode* r = this->p_root;
			while (p) {
				r = p;
				if (v < p->value) {
					p = p->p_left;
				}
				else {
					p = p->p_right;
				}
			}
			if (v < r->value) {
				r->p_left = p_new_note;
			}
			else
			{
				r->p_right = p_new_note;
			}
		}
	}
	void remove(int v) {
		//this is going to be too much during interview. consider priority queue instead
	}
	void remove_max() {
		if (this->p_root)
		{
			TreeNode* r = this->p_root;
			TreeNode* p = this->p_root;
			while (p->p_right) {
				p = p->p_right;
			}
			if (r != p) {
				r->p_left = p->p_left;
				r->p_right = nullptr;
				delete p;
			}
			else
			{
				this->p_root = p->p_left;
				delete p;
			}
		}
	}

	int peek_max() {
		if (this->p_root == nullptr)
		{
			return -1;
		}
		else {
			TreeNode* p = this->p_root;
			while (p->p_right) {
				p = p->p_right;
			}
			return p->value;
		}
	}
private:
	TreeNode* p_root = nullptr;
};

struct ListNode
{	
	int value = 0;
	ListNode* p_next = nullptr;
};
class MaxStack {
public:
	MaxStack() {
	}

	virtual ~MaxStack() {
		while (this->size() > 0) {
			this->pop();
		}
	}

	void push(int x) {
		ListNode* p_new_node = new ListNode;
		p_new_node->value = x;

		//handle header pointer
		if (this->p_head) {
			p_new_node->p_next = this->p_head;
		}
		this->p_head = p_new_node;

		ordered_list.insert(x);
	}
	int pop() {
		int v = -1;
		if (this->size() > 0) {
			int v = this->p_head->value;
			this->ordered_list.remove(v);
			ListNode* p = this->p_head;
			this->p_head = p->p_next;
			delete p;
			this->length--;
		}
		return v;
	}
	int top() {
		if (this->size() > 0)
		{
			return this->p_head->value;
		}
		else {
			return -1;
		}
	}
	int peekMax() {
		return 	this->ordered_list.peek_max();;
	}
	int size() {
		return this->length;
	}
private:
	int length = 0;
	ListNode* p_head = nullptr;
	BinarySearchTree ordered_list;
};