#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility> // for pair
#include <queue> // for queue and priority_queue
#include <stack>

using namespace std;

int cal(char a[], int size) {
    int result = 0;
    int last = 0;
    int current = 0;
    char op = '+';

    for (int i = 0; i < size; i++) {
        while (a[i] >= '0' && a[i] <= '9') {
            current = current * 10 + a[i] - '0';
        }
        if (a[i] == '-' || a[i] == '+' || a[i] == '*' || a[i] == '/' || i == size - 1) {
            if (op == '-' || op == '+') {
                result += last;
                last = op == '-' ? -current : current;
            }
            else if (op == '*') {
                last = last * current;
            }
            else if (op == '/') {
                last = last / current;
            }
            op = a[i];
            current = 0;
        }
    }
    result += last;
    return result;
}

int do_calc(int nl, int nr, char op) {
    switch (op) {
    case '+':
        return nl + nr;
    case '-':
        return nl - nr;
    case '*':
        return nl * nr;
    case '/':
        return nl / nr;
    }
    return 0;
}

int cal_stack2(char a[], int size) {
    stack<int> ns;
    stack<char> os;
    for (int i = 0; i < size; i++) {
        if (a[i] >= '0' && a[i] <= '9')
        {
            int num = 0;
            while (a[i] >= '0' && a[i] <= '9') {
                num = num * 10 + a[i] - '0';
            }
            ns.push(num);
        }

        if (a[i] == '*' || a[i] == '/') {
            os.push(a[i]);
        }
        if (a[i] == '+' || a[i] == '-' || i == size - 1) {
            while (!os.empty()) {
                char op = os.top(); os.pop();
                int nr = ns.top(); ns.pop();
                int nl = ns.top(); ns.pop();
                int result = do_calc(nl, nr, op);
                ns.push(result);
            }
            if (i != size - 1) {
                os.push(a[i]);
            }
        }
    }
    int result = ns.top(); ns.pop();

    return result;
}