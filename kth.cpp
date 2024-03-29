class PriorityQueue /*build a priority queue with max value on top*/
{
public:
	PriorityQueue(int k) {
		this->length = k + 1;
		this->data = new int[this->length];//1 for the extra space to push a new element
		this->counter = 0;
	}
	~PriorityQueue() {
		if (this->data) {
			delete this->data;
		}
		this->data = nullptr;
		this->length = 0;
		this->counter = 0;
	}
	void insert(int v) {
		if (this->counter < this->length) {
			this->data[this->counter] = v;
		}
		bubble_up(this->counter);
		// we only increase the counter when it is less than size - 2, otherwise, 
		// it will point to the last slot which is reserved as the extra space for new element.
		if (this->counter < this->length - 1) {
			this->counter++;
		}
	}
	int top() {
		return this->data[0];
	}
	int size() {
		return this->counter;
	}
	void pop() {
		if (this->counter > 0) {
			this->data[0] = this->data[this->counter--];
			bubble_down(0);
		}
	}
private:
	int length;
	int* data;
	int counter;
	int parent(int c) {
		return (c <= 0) ? -1 : c / 2;
	}
	int l_child(int c) {
		return (c<0 || 2 * c + 1 > this->counter) ? -1 : c * 2 + 1; // zero base
	}
	int r_child(int c) {
		return (c<0 || 2 * c + 2 > this->counter) ? -1 : c * 2 + 2; // zero base
	}
	void swap(int i, int j) {
		int temp = this->data[i];
		this->data[i] = this->data[j];
		this->data[j] = temp;
	}
	void bubble_up(int c) {
		if (c <= 0 || c >= this->length) return;
		int par = this->parent(c);
		if (par < 0) return;
		if (this->data[par] < this->data[c]) {
			swap(c, par);
		}
		bubble_up(par);
	}
	void bubble_down(int c) {
		if (c < 0 || c >= this->length) return;
		int lc = this->l_child(c);
		int rc = this->r_child(c);

		int tc = -1;
		if (lc >= 0 && rc >= 0) {
			tc = this->data[lc] > this->data[rc] ? lc : rc;
		}
		else if (lc >= 0) {
			tc = this->data[lc];
		}
		else if (rc >= 0) {
			tc = rc;
		}
		else {
			tc = -1;
		}
		if (tc < 0) return;
		if (this->data[c] < this->data[tc]) {
			swap(c, tc);
		}
		bubble_down(tc);
	}
};


int find_kth_smallest(int* a, int n, int k)
{
	PriorityQueue kc(k);
	for (int i = 0; i < n; i++)
	{
		if (kc.size() < k) {
			kc.insert(a[i]);
		}
		else {
			if (a[i] < kc.top()) {
				kc.pop();
				kc.insert(a[i]);
			}
		}
	}
	return kc.top();
}