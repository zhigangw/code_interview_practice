#include <queue>
int find_kth_pq(int* a, int n, int k) {
	std::priority_queue<int> pqueue;
	for (int i = 0; i < n; i++) {
		if (pqueue.size() < k) {
			pqueue.push(a[i]);
		}
		else {
			if (pqueue.top() > a[i]) {
				pqueue.pop();
				pqueue.push(a[i]);
			}
		}
	}
	return pqueue.top();
}