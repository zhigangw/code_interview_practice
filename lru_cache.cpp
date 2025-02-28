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
#include <string>
#include <sstream> // include sstream for stringstream

using namespace std;

class LRUCache {
public:
    LRUCache(int c) {
        _capacity = c;
    }

    int get(int key) {
        return _cache.contains(key) ? _cache[key] : -1;
    }

    void put(int key, int value) {
        if (_cache.contains(key)) {
            _cache[key] = value;
        }
        else { // need to add a new item
            if (_lru_queue.size() == _capacity) {
                _cache.erase(_lru_queue.front().first);
                _lru_queue.pop();
            }
            _cache[key] = value;
            _lru_queue.push(make_pair(key, value));
        }
    }
private:
    int _capacity;
    unordered_map<int, int> _cache;
    queue<pair<int, int>> _lru_queue;
};