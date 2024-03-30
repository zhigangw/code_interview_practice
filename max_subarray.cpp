int max_subarray(int* a, int n) {
	// scan the array, and check if the current value + accumulated value > current value
	// if yes, accumulated value = current value + accumulated value 
	// if no, accumulated value = current value 
	// use a max_sum to remeber the max value of accumulated one
	int accumulated = 0;
	int max_sum = 0;
	for (int i = 0; i < n; i++) {
		if (accumulated + a[i] > accumulated) {
			accumulated = accumulated + a[i];
		}
		else {
			accumulated = a[i];
		}
		if (max_sum < accumulated) max_sum = accumulated;
	}
	return max_sum;
} 