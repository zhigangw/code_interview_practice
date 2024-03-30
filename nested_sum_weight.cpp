int nested_sum_weith(char* s, int n){
	// init the depth as 0
	// scan the list.
	// once encounter a '[', increase the depth, once encounter the ']' decrease the depth
	// use accumulated to collect the weight for all the digits
	// use the max_weight to remember the max_weight
	// int the end, use the curent formular to caculate: (max_weight + 1) * n - accumulated
	int depth = 0;
	int acumulated = 0;
	int max_weight = 0;
	int num_digit = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '[') {
			depth++;
		}
		else if (s[i] == ']') {
			depth--;
		} 
		else {
			acumulated += depth;
			if (max_weight < acumulated) max_weight = acumulated;
			num_digit++;
		}
	}
	return (max_weight + 1) * num_digit - acumulated;
}