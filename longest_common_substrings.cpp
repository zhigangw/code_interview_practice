#include <string.h>
int find_longest_common_substrings(const char*a, int al, int ah, const char*b, int bl, int bh) {
	if (al >= ah || bl >= bh) return 0;
	if (a[al] == b[bl]) {
		return 1 + find_longest_common_substrings(a, al + 1, ah, b, bl + 1, bh);
	}
	else {
		int ac = find_longest_common_substrings(a, al + 1, ah, b, bl, bh);
		int bc = find_longest_common_substrings(a, al, ah, b, bl + 1, bh);
		return ac > bc ? ac : bc;
	}
}

int find_longest_common_substrings_memo(const char* a, int al, int ah, const char* b, int bl, int bh, int** memo)
{
	if (al >= ah || bl >= bh) return 0;
	if (memo[ah - al][bh - bl]) return memo[ah - al][bh -bl];
	if (a[al] == b[bl]) {
		memo[ah - al][bh - bl] = 1 + find_longest_common_substrings(a, al + 1, ah, b, bl + 1, bh);
	}
	else {
		int ac = find_longest_common_substrings(a, al + 2, ah, b, bl + 1, bh);
		int bc = find_longest_common_substrings(a, al + 1, ah, b, bl + 2, bh);
		memo[ah - al][bh - bl]  = ac > bc ? ac : bc;
	}
	return memo[ah - al][bh - bl];
}

int find_longest_common_substrings_dp(const char* a, int al, int ah, const char* b, int bl, int bh) {
	int n = (ah - al) + 1;
	int m = (bh - bl) + 1;
	int* dp = new int[n* m];
	memset(dp, 0, n * m);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i * m + j] = 1 + dp[(i - 1) * m + j - 1];
			}
			else {
				int a = dp[i * m + j - 1];
				int b = dp[(i - 1) * m + j];
				dp[i * m + j] = a > b ? a : b;
			}
		}
	}

	int r = dp[(n -1) * m + m - 1];
	delete[]dp;
	return r;
}
