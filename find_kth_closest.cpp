inline int abs(int x) {
	return x >= 0 ? x : -x;
}
void find_closest_kth(int* a, int n, int* output, int k, int x) {
	//use binary search to find the closest index to x in a
	int low = 0;
	int high = n - 1;
	int middle = (low + high) / 2;
	while (low <= high) {
		if (a[middle] == x) {
			break;
		}
		else if (x < a[middle]) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
		middle = (low + high) / 2;
	}
	//use two pointer to walk in two directions, compare the element they are pointing to, and select the one closest to x. move the pointer.
	int i = middle;
	int j = middle;
	int c = 0;
	while (c < k)
	{
		if (i < 0 && j >= n) {
			//we hit the boundry
			break;
		}
		else if (j < n - 1)
		{
			output[c++] = a[j++];
		}
		else {
			output[c++] = a[i--];
		}
		if (abs(a[i] - x) < abs(a[j] - x)) {
			output[c++] = a[i--];
		}
		else {
			output[c++] = a[j++];
		}
	}
	return;
}