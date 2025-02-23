#include <iostream>
using namespace std;

bool valid_abbr(const char* s, const char* abbr) {
    if (s == nullptr || abbr == nullptr) return false;

    const char* p = s, * q = abbr;
    while (*p && *q) {
        int counter = 0;
        while (*q >= '0' && *q <= '9') { // digit
            counter = counter * 10 + (*q - '0');
            q++;
        }

        while (counter > 0 && *p) { //move p by the counter
            counter--;
            p++;
        }
        while (*p == *q) {
            p++;
            q++;
        }
    }
    return *p == 0 && *q == 0;
}