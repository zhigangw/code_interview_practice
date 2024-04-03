/*
* isIsomorphic string
* use a hash map to record the mapping from string a to b.
* scan the two strings, for the current position,
* if there is no mapping for the char in string a, create one
* map it from a[i] to b[i].
* if there is a mapping, check if the mapping matches the current pair.
* if not, return false;
* assumption, there are only ansi chars(0~127) in the string.
*/
#include<string>
using namespace std;
bool isIsomorphic(string a, string b) {
    char mapping[128] = { -1 }; // set all value to -1 in the initialization.
    for (int i = 0; i < a.length(); i++) {
        if (mapping[a[i]] == -1) {
            mapping[a[i]] = b[i];
        }
        else {
            if (mapping[a[i]] != b[i]) return false;
        }
    }
    return true;
}