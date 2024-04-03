/*
* find the celebrity
* first round, scan all participants, and check if there is one who knows noboddy but at least someone knows her/him
* second, for the candidate, check if she/he knows know noboddy, and everyone knows she/he
*/
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
int find_celebrety(vector<int>& guests, function<bool(int, int)> knows) {
    int candidate = 0;
    for (int i = 0; i < guests.size(); i++) {
        // if the candidate knows i, TC is not the celebrity since a celebrity should know noboddy.
        // if TC doesn't know i, i is not the celebretiy since everyone should know the celebrity.
        if (knows(candidate, guests[i])) {
            candidate = i;
        }
    }
    for (int i = 0; i < guests.size(); i++) {
        if (i != candidate && knows(candidate, guests[i])) {
            //candidate knows someone, she/he fails since a celebrity should know no buddy. 
            return -1;
        }
        if (i != candidate && !knows(guests[i], candidate)) {
            //everyone should know the candidate 
            return -1;
        }
    }
    return candidate;
}