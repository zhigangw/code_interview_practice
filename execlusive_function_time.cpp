#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;
void extract_from_log(string log, int& fid, bool& start, int& time) {

}
void exclusive_function_time(vector<string>& logs, map<int, int>& exclusive_time) {
	stack<pair<int, int>> log_stack;
	
	//iterate the logs
	//if it is 'start' log, push into stack
	//if it is 'end' log, pop up the top from the stack, record the execution time and put it into hash map
	for (string log : logs) {
		int fid = 0;
		bool start = false;
		int time = 0;
		extract_from_log(log, fid, start, time);
		if (start) {
			log_stack.push(make_pair(fid,time));
			exclusive_time[fid] = 0;
		}
		else {
			//ASSERT the function id is matched
			int added_time = (time - log_stack.top().second + 1);
			exclusive_time[fid] += added_time;
			log_stack.pop();

			//handle recursive
			if (log_stack.size() > 0) {
				exclusive_time[log_stack.top().first] -= added_time;
			}
		}
	}
}
