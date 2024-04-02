/*
* use a vector/list to contain the elements
* use a hash map to record the mapping from the value to the position of the value in the list
* for insert, simply append the value and remember the mapping
* for remove, simply remove the value from the vector by replace the value by the last element, so the other element's position will not change. and delete the mapping.
* for random get, generate a random number as the position while we can retrieve the value.
*/
#include <vector>
#include <unordered_map>
using namespace std;
class RandomSet {
public:
    RandomSet() {}
    void insert(int val) {
        //check the presence
        if (mapping.contains(val)) return;
        list.push_back(val);
        mapping[val] = (int)list.size() - 1;
    }

    void remove(int val) {
        if (!mapping.contains(val)) return;
        int pos = mapping[val];
        list[pos] = list.back();
        mapping[list[pos]] = pos;
        list.pop_back();
    }

    int get_random() {
        int ran_pos = rand() % list.size();
        return list[ran_pos];
    }

private:
    vector<int> list;
    unordered_map<int, int> mapping;
};