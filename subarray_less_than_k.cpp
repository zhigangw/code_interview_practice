int subarrays(int* a, int size, int k) {
	int num = 0;
	for (int i = 0; i < size - 1; i++) {
		int product = a[i];
		for (int j = i; j < size - 1; j++)
		{
			if (j != i) {
				product *= a[j];
			}
			if (product < k) {
				num++;
			}
			else {
				break;
			}
		}
	}
	return num;
}