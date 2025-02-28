#include <iostream>
#include <memory>
#include <map>
#include <vector>
using namespace std;

void remove(char s[], int size, int o[]) {
    int cp = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == '(') {
            cp++;
        }
        if (s[i] == ')') {
            if (cp > 0) {
                cp--;
            }
            else {
                s[i] = '*'; // marker to remove
            }
        }
    }

    for (int i = size - 1; i >= 0 && cp > 0; i--) {// scan backwords
        if (s[i] == '(') {
            s[i] = '*';
            cp--;
        }
    }

    int j = 0;
    for (int i = 0; i < size - 1; i++) {
        if (s[i] != '*') {
            o[j++] = s[i];
        }
    }
}