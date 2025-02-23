#include <iostream>
using namespace std;
int find_diameter(int a[], int al, int root, int& max_diameter) {
    if (a == nullptr) return 0; // should not happen
    if (al <= root) { // reach the end of the tree
        return 0;
    }
    int ld = find_diameter(a, al, root * 2 + 1, max_diameter);
    int rd = find_diameter(a, al, root * 2 + 2, max_diameter);
    max_diameter = max(max_diameter, ld + rd);
    return ld > rd ? ld + 1 : rd + 1;
}

int main_func() {
    int root[] = { 1,2,3,4,5 };
    int max_diameter = 0;
    find_diameter(root, 5, 0, max_diameter);
    return max_diameter;
}