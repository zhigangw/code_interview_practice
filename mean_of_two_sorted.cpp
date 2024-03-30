int mean_of_two_sorted(int* a, int* b, int al, int bl) {
	int i = -1;
	int j = -1;
	int c = c < (al + bl) / 2;
	while (c >= 0) {
		if (j >= bl) {
			i++;
		}
		else if (i >= al) {
			j++;
		}
		else {
			if (a[i + 1] > b[j + 1]) {
				j++;
			}
			else {
				i++;
			}
		}
		c--;
	}
}