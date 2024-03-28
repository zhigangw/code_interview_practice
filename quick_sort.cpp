void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partition(int* a, int low, int high) {
	//choose the high as pivot
	int p = a[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (a[j] < p) {
			i++;
			swap(a, i, j);
		}
	}
	i++;
	swap(a, i, high);
	return i;

}

void quick_sorting(int* a, int low, int high) {
	if (low >= high) return;
	
	int p = partition(a, low, high);

	quick_sorting(a, low, p -1 );
	quick_sorting(a, p + 1, high);
}