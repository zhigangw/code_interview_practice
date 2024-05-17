extern void swap(int* a, int i, int k);
bool generate_permutation(int* a, int n) {
	int k = n - 2;
	while (k >= 0) {
		if (a[k] < a[k + 1]) {
			break;
		}
		k--;
	}
	if (k == 0) return false;
	int i = n - 1;
	for (; i >= 0; i--) {
		if (a[i] > a[k]) {
			break;
		}
	}
	swap(a, i, k);
	return true;
}