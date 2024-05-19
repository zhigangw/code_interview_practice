/*
* You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
* Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
*/

/*
* SOLUTION
* scan the two strings, once find a mismatch, do a swap, and check if the swap can make the string equal
*/

bool one_step_to_equal(const char* s, const char* t, int length) {
	int q = -1;
	int p = -1;
	int swap = 0;
	for (int i = 0; i < length; i++)
	{
		if (s[i] != t[i]) {
			if (p == -1) {
				p = i;
			}
			else
			{
				q = i;
			}
			if (p != -1 && q != -1) {
				if (t[q] == s[p] && t[p] == s[q]) {
					swap++;
					if (swap > 1) {
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}