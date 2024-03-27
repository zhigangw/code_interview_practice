//return the index of the given value in the array
int binary_search(int* array, int size, int value) {
	int low = 0;
	int high = size - 1;
	int middle = high / 2;
	bool found = false;
	while (low <= high && !found) {
		middle = (low + high) / 2;
		if (array[middle] == value) {
			found = true;
			break;
		}
		else if (array[middle] < value) {
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return found ? middle : -1;
}