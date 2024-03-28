#include <stack>
#include <string>

using namespace std;
void remove(char *sc)
{
    stack<int> stack;
    int i = 0;
    char *p = sc;
    while (p && *p)
    {
        if (*p == '{')
        {
            stack.push(i);
        }
        else if (*p == '}')
        {
            if (!stack.empty())
                stack.pop();
            else
            {
                *p = ' ';
            }
        }
        i++;
        p++;
    }
    while (!stack.empty())
    {
        int j = stack.top();
        sc[j] = ' ';
        stack.pop();
    }
    char *q = sc, *r = sc;
    while (q && *q && r && *r)
    {
        while (*r == ' ')
            r++;
        while (*r && *r != ' ')
            *q++ = *r++;
    }
    //_ASSERT(q&&*q)
    *q = 0;
}