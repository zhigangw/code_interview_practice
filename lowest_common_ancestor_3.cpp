#include <iostream>
#include <memory>
#include <map>
#include <vector>
using namespace std;

struct node {
    int v;
    node* left;
    node* right;
    node* parent;
};

node* lca(node* root, node* n1, node* n2) {
    node* p = n1;
    node* q = n2;
    int ph = 0;
    int qh = 0;

    while (p != root) {
        p = p->parent;
        ph++;
    }

    while (q != root) {
        q = q->parent;
        qh++;
    }

    p = n1;
    q = n2;
    while (ph > qh) {
        p = p->parent;
        ph--;
    }
    while (qh > ph) {
        q = q->parent;
        qh--;
    }
    while (q != p) {
        p = p->parent;
        q = q->parent;
    }
    return q;
}