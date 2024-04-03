#include <array>
#include <cmath>
using namespace std;

bool is_digit(char c)
{
	return '0' < c && c < '9';
}

bool find_pattern_i18n(const char* pattern, int k, const char* source, int n)
{
	const char* f, * s, * p, * q;
	int l = 0;
	// find the first pattern by doing the following
	// set pointer f to the first charactor in the pattern; if the pattern starts from digits, set it as null;
	p = source;
	q = pattern;
	f = q;
	s = q;
	// set the pointer s to the second charactor in the pattern, if the pattern ends with digits, set it as null;
	// find the digits between f and s, convert them to a number l;
	while (p && *p)
	{
		int cd = 0;
		while (q && *q) // assuming the end of the string is 0;
		{
			if (q && *q && !is_digit(*q))
			{
				f = q;
				q++;
			}
			else
			{
				f = NULL;
			}
			while (q && is_digit(*q))
			{
				l *= (int)pow(10, cd);
				l += (*q - '0');
				q++;
				cd++;
			}
			if (q && *q && !is_digit(*q))
			{
				s = q;
				q++;
			}

			// scan the source string using pointer p
			// 1) f == NULL, meaning we skip the first cd char in the source
			// 1.1) else If the *p == *f, match, and move p to next occurence
			// 2) Continue moving p to the next and --i, until i is zero, or p hits the end of the pattern string.
			// 3) Compare the *p and *s, if they are matching, move p to the next charactor, and repeat the above steps.
			if (f != NULL)
			{
				if (*f != *p) {
					return false;
				}
				else
				{
					p++;
				}
			}
			while (l > 0 && p && *p)
			{
				l--;
				p++;
			}
			if (l > 0) return false; 
			if (s != NULL)
			{
				if (!p || !*p) return false;
				if (*s == *p)
				{
					p++;
				}
				else {
					return false;
				}
			}
		}
	}
	if (q && p && *p == 0 && *q && *q == 0)
		return true;
	else
		return false;
}

