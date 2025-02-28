#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct node {
    int value;
    node* next;
};

node* remove_nth(node* head, int n) {
    node* pn = head;
    node* pq = head;
    node* pp = head;
    while (n > 0 && pn) {
        pn = pn->next;
    }
    if (n > 0) {
        return nullptr;
    }
    while (pn) {
        pn = pn->next;
        pp = pq;
        pq = pq->next;
    }
    if (pq) {
        pp->next = pq->next;
    }
    return pq;
}