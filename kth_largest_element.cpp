#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int kth_largest(int a[], int size, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min pq
    for (int i = 0; i < size; i++) {
        if (pq.size() < k) {
            pq.push(a[i]);
        }
        else
            if (pq.top() < a[i]) {
                pq.pop();
                pq.push(a[i]);
            }
    }
    return pq.top();
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(int a[], int low, int high) {
    int pv = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] > pv) {//descending
            i++;
            swap(a, i, j);
        }
    }
    i++;
    swap(a, i, high);
    return i;
}

int kth_largest2(int a[], int size, int k) {
    int low = 0;
    int high = size - 1;
    int pa = partition(a, low, high);
    while (k > 0) {
        if (k < pa) {// discard the high part
            k = pa - k;
            high = pa - 1;
            pa = partition(a, low, high);
        }
        else if (pa < k) { //discard the low part
            k = k - pa;
            low = pa + 1;
            pa = partition(a, low, high);
        }
        else {
            break;
        }
    }
    return pa;
}