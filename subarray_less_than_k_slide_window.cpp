int subarry_slide_window(int* a, int size, int k) {
	// use a left pointer l and a right pointer r to mark a sliding window
	// point l and r to the starting position
	int l = 0, r = 0;
	int product = a[0];
	int count = 0;
	while (l < size - 1 && r < size - 1) {
		// caculate the product of the subarray
		if (product < k) {
			// if the product is less than k, count it, and move r to right
			count++;
			r++;
			product *= a[r];
		}
		else
		{
			// if the product of the emlement is equal to or greater than k, move l to r.
			product /= a[l];
			l++;
			if (l > r) {
				r = l;
				product = a[l];
			}
		}
	}//repeat until the l and r reach the end of the array
	
	return count;
}