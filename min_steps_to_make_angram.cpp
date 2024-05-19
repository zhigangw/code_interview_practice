/*
* You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
* Return the minimum number of steps to make t an anagram of s.
* An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
*/

/*
* solution: 
* use two hash table(128 int array since they are ANSI chars), ah, bh, to remember the occurence of the charartors. 
* scan the two hash tables to find the difference between the occurrence of the same char, ah[i] - bh[i]. Please note there will be positive and negative values
* add up all the difference to get the mini steps.
*/

int min_step(const char* s, const char* t, int length) {
	const int N = 128;
	int ah[N] = { 0 };
	int bh[N] = { 0 };
	for (int i = 0; i < length; i++)
	{
		ah[*s++]++;
		bh[*t++]++;
	}
	int steps = 0;
	for (int i = 0; i < N; i++) {
		steps += (ah[i] - bh[i]);
	}
	return steps;
}