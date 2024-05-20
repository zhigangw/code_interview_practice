/*
* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/
/*
* SOLUTION:
* build two graph, in and out, to represent the incoming and outgoing edges
* start scan in graph, queue the node without any incoming(prerequisite) edges;
* for the nodes in the queue, output it, remove it from the incoming edges. 
* If the removal make a node become ready(no incoming edges), put it into the queue
*/
#include <vector>
#include<queue>
#include <set>
using namespace std;
void course_schedule(vector<pair<int,int>>& courses, int num, vector<int>& output) {
	vector<set<int>> in(num);
	vector<set<int>> out(num);
	queue<int> helper_q;

	for (auto& pair : courses) {
		in[pair.second].insert(pair.first);
		out[pair.first].insert(pair.second);
	}

	for (int i = 0; i < num;i++) {
		if (in[i].size() == 0) {
			helper_q.push(i);
		}
	}
	while (helper_q.size() > 0) {
		int i = helper_q.front();
		output.push_back(i);

		for (auto& k : out[i]) {
			in[k].erase(i);
			if (in[k].size() == 0) {
				helper_q.push(k);
			}
		}
		helper_q.pop();
	}
}