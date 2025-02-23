/*
* Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/
/*
* SOLUTION:
* The right k value must be between 1 and the amount n of the pile having most bananas. 
* We can do binary search between 1 and n to find the largest value can make koko eat all the bananas in h hours
*/

bool can_eat_all(int ba[], int length, int h, int k) {
	int hours = 0;
	for (int i = 0; i < length; i++) {
		hours += (ba[i] / k) + (ba[i] % k ? 1 : 0);
	}
	return hours <= h;
}
int eat_banana(int ba[], int length, int h) {
	int n = 0;
	for (int i = 0; i < length; i++) {
		if (ba[i] > n) n = ba[i];
	}
	int l = 1;
	int k = 0;
	while (l < h) {
		int m = (l + h) / 2;
		if (can_eat_all(ba, length, h, m)) {
			l = m + 1;
			k = m;
		}
		else
		{
			h = m - 1;
		}
	}
	return k;
}