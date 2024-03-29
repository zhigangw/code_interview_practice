class PriorityQueue /*build a priority queue with min value on top*/
{
public:
	PriorityQueue(int k) {
		this->data = new int[k];
		this->size = k;
		this->counter = 0;
	}
	~PriorityQueue() {
		if (this->data) {
			delete this->data;
		}
		this->data = nullptr;
		this->size = 0;
		this->counter = 0;
	}
	void update_min_max(int v) {
		this->min_value = (this->counter == 1 || min_value > v) ? v : min_value;
		this->max_value = (this->counter == 1 || max_value < v) ? v : max_value;
	}
	bool insert(int v) {
		bool inserted = false;
		if (this->counter < this->size - 1) {
			this->data[this->counter++] = v;
			bubble_up(this->counter);
			inserted = true;
		}
		else {
			if (this->min_value < v) {
				this->data[0] = v;
				bubble_down(0);
				inserted = true;
			}
		}
		if (inserted) {
			update_min_max(v);
		}
		return inserted;
	}
	int min() {
		return this->min_value;
	}
private:
	int size;
	int* data;
	int counter;
	int min_value = 0;
	int max_value = 0;

	int parent(int c) {
		return (c <= 0) ? -1: c/2;
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
		if (c <= 0) return;
		int par = parent(c);
		if (par < 0) return;
		if (this->data[par] > this->data[c]) {
			swap(c, par);
		}
		bubble_up(par);
	}
	void bubble_down(int c) {
		if (c < 0 || c >= this->size) return;
		int lc = l_child(c);
		int rc = r_child(c);
		int tc = (this->data[lc] > this->data[lc]) ? lc : rc;
		swap(tc, c);
		bubble_down(tc);
	}
};


int findkth(int a[], int n, int k)
{
	PriorityQueue kc(k);
	for (int i = 0; i < n; i++)
	{
		kc.insert(a[i]);
	}
	return kc.min();
}