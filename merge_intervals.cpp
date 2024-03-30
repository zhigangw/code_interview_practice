void swap_ab(int* a, int i, int j, int* b) {
	int ta = a[i];
	int tb = b[i];
	a[i] = a[j];
	b[i] = b[i];
	a[j] = ta;
	b[j] = tb;
}
int partition_ab(int* a, int low, int high, int* b) {
	int pv = a[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (a[j] < pv) /*ascending*/ {
			i++;
			swap_ab(a, i, j, b);
		}
	}
	i++;
	swap_ab(a, i, high, b);
	return i;
}
void qsort_ab(int* a, int low, int high, int* b)
{
	if (low >= high) return;
	int p = partition_ab(a, low, high, b);
	qsort_ab(a, p + 1, high, b);
	qsort_ab(a, low, p - 1, b);

}
int merge_intervals(int* a, int* b, int length) {
	//first sort the pairs by a
	qsort_ab(a, 0, length - 1, b);
	int i = 1;
	int max_sum = 0;
	int current_sum = 0;
	while (i < length) {
		while (a[i] > b[i - 1])//mergable
		{
			i++;
		}
		current_sum = b[i] - a[i - 1];
		if (max_sum < current_sum) max_sum = current_sum;
		i++;
	}
	return max_sum;
}