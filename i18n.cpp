#include <array>
#include <cmath>
namespace std
{
    bool is_digit(char c)
    {
        return '0' < c && c < '9';
    }

    bool find_pattern(char *pattern, int k, char *source, int n)
    {
        char *f, *s, *p, *q;
        int l = 0;
        // find the first pattern by doing the following
        // set pointer f to the first charactor in the pattern; if the pattern starts from digits, set it as null;
        p = pattern;
        q = source;
        f = p;
        s = p;
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
                    l += (*q - '0') * (int)pow(10, cd);
                    q++;
                    cd++;
                }
                if (q && *q && !is_digit(*q))
                {
                    s = q;
                    q++;
                }
            }
            // scan the source string using pointer p
            // 1) If the *p == *f, or *p is digit and *f==null, match, and move p to next occurence
            // 2) Continue moving p to the next and --i, until i is zero, or p hits the end of the pattern string.
            // 3) Compare the *p and *s, if they are matching, move p to the next charactor, and repeat the above steps.

            if (f && !p && is_digit(*p))
                return false;
            if (*f != *p)
            {
                return false;
            }
            else
            {
                p++;
            }
            while (is_digit(*p) && cd > 0)
            {
                cd--;
                p++;
            }
            if ((is_digit(*p) && cd == 0) || (!is_digit(*p) && cd > 0))
                return false;
            if (s && *s == *p)
            {
                p++;
            }
        }
        if (p && *p == 0 && *q && *q == 0)
            return true;
        else
            return false;
    }
}
