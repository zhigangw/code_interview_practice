
#include <string>
using namespace std;
int mininum_types(string s) {
    char current = 'a';
    int seconds = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int diff = abs(s[i] - current);
        //clock or anti-clock
        int steps = 26 - diff < diff ? 26 - diff : diff;
        //move the wheel
        seconds += steps;
        //tap the char
        seconds += 1;
        //record the current
        current = s[i];
    }
    return seconds;
}
