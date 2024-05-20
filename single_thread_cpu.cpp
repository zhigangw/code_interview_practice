/*
* You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.
*/

/*
* SOLUTION:
* 1) sort the tasks by starting time.
* 2) put all avaiable tasks into a priority queue sorted by the processing time.
* 3)
*/
#include<vector>
#include<queue>
using namespace std;
void single_cpu(vector<pair<int, int>>& a, vector<int> output) {
	sort(begin(a), end(a));
	int time = a[0].first;
	for (int i = 0; i < a.size(); i++) {
		int j = i;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;//every time create a new pq
		while (a[j].first <= time && j < a.size()) {
			pq.push(make_pair(a[i].second, j));
			j++;
		}
		time += pq.top().first;
		i = pq.top().second + 1;
		output.push_back(pq.top().second);
	}
}