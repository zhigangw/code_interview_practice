int find_in_rotated_array(int* a, int size, int value) {
	int l = 0;
	int r = size - 1;
	bool found = false;
	int m = (l + r) / 2;
	while (l <= r && !found)
	{
		if (a[m] == value) {
			found = true;
			break;
		}
		else if (a[m] < value) {
			if(a[r] > value)
			l = m + 1;
			else if (a[r] < value) {
				r = m - 1;
			}
			else {
				m = r;
				found = true;
				break;
			}
		}
		else if (a[m] > value) {
			r = m - 1;
		}
		m = (l + r) / 2;
	}
	return found ? m : -1; 
}