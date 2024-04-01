/*
* https://leetcode.com/problems/all-oone-data-structure/solutions/91398/c-solution-with-comments/
*/
#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
using namespace std;
class AllOOne
{
public:
	AllOOne() {
	}
	~AllOOne() {

	}
	void inc(string key) {
		if (!key_bucket_map.contains(key)) {
			key_bucket_map[key] = counter_keys_list.insert(counter_keys_list.begin(), { 0,{key} });
		}
		auto bucket = key_bucket_map[key];
		int counter = bucket->counter++;
		auto next = bucket++;
		// insert the key to the appropriate bucket
		// if the new counter is between bucket and the next, or the next the at the end of the list, insert a new bucket.
		// if the next bucket is the right one, add the key into the next bucket. 
		if (next == counter_keys_list.end() || counter < next->counter) {
			key_bucket_map[key] = counter_keys_list.insert(bucket, { counter,{key} });
		}
		else {
			//the next's counter must be equal to the counter since they are incremented by one.
			key_bucket_map[key] = next;
		}

		//remove the key from the current bucket.
		bucket->keys.erase(key);
		if (bucket->keys.empty()) {
			counter_keys_list.erase(bucket);
		}
	}
	void dec(string key) {
		if (!key_bucket_map.contains(key)) {
			return;
		}
		auto bucket = key_bucket_map[key];
		int counter = bucket->counter--;
		auto prev = bucket--;
		//first remove the key from the current bucket
		bucket->keys.erase(key);
		if (counter <= 0) {
			return;
		}

		//insert the key into the appropriate spot
		if (prev == counter_keys_list.begin() || counter > prev->counter) {
			key_bucket_map[key] = counter_keys_list.insert(prev, { counter,{key} });
		}
		else {
			prev->keys.insert(key);
			key_bucket_map[key] = prev;
		}
	}
	string max_count_key() {
		return counter_keys_list.empty() ? "" : *counter_keys_list.cend()->keys.cbegin();
	}
	string min_count_key() {
		return counter_keys_list.empty() ? "" : *counter_keys_list.cbegin()->keys.cbegin();
	}
private:
	struct Bucket { int counter; unordered_set<string> keys; };
	list<Bucket> counter_keys_list;
	map<string, list<Bucket>::iterator> key_bucket_map;
};
