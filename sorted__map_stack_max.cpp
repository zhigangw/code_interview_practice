/*
* push()
* pop()
* peekMax()
* popMax()
* rescriction and assumption
* push / pop /peekMax()/popMax() should be o(log(n))
* implementation:
* we can easilly implement a stack using double linkedlist or a linkedlist with a top/tail pointer.
* to support peekMax(), we need keep the node in an ordered way. BST is a good candidate.
* (heap will not work well for deletion which need to search and find the target)
* to support popMax(), we need a mapping from the sorted node to the iterator of the orginal list,
* so we can perfrom the deletion in o(1)
* with a BST alike data structure to store the order, the push/pop will be o(log(n)), we can use (descending) map
* in c++ to make the deletion from BST in o(1);
*/
#include <list> //double linked list
#include <map> //sorted hash map
using namespace std;
class MaxStack {
public:
    MaxStack() {

    }
    void push(int n) {
        //shall we block the duplication?
        auto i = this->stack.insert(stack.cend(), n);
        this->sorted_map.insert({ n,i });
    }
    void pop() {
        int n = this->stack.back();
        this->sorted_map.erase(n);
        this->stack.pop_back();
    }
    int peekMax() {
        int n = this->sorted_map.begin()->first;
        return n;
    }
    int popMax() {
        int n = this->sorted_map.begin()->first;
        auto i = this->sorted_map[n];
        this->sorted_map.erase(n);
        this->stack.erase(i);
        return n;
    }

private:
    list<int> stack;
    map<int, list<int>::iterator, greater<int>> sorted_map;
};