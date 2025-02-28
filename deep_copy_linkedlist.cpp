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

struct node {
    int value;
    node* p_next;
    node* p_random;
    node(int v) {
        value = v;
        p_next = nullptr;
        p_random = nullptr;
    }
};

node* deep_copy_node(node* current, unordered_map<node*, node*>& node_map) {
    if (current == nullptr) return nullptr;
    node* new_node = new node(current->value);
    node_map[current] = new_node;
    return new_node;
}

node* deep_copy_linkedlist(node* head) {
    if (head == nullptr) return nullptr;

    unordered_map<node*, node*> node_map;
    node* current_node = head;
    while (current_node != nullptr) {
        deep_copy_node(current_node, node_map);
        current_node = current_node->p_next;
    }

    current_node = head;
    node* new_node = node_map[head];

    while (current_node != nullptr) {
        new_node->p_next = node_map[current_node->p_next];
        new_node->p_random = node_map[current_node->p_random];
        current_node = current_node->p_next;
        new_node = new_node->p_next;
    }
    return node_map[head];
}