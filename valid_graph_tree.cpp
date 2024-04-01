
/*
* To tell if a graph is a valid tree, we have to meet two conditions
* 1) There is no cycle in the graph.
* 2) All nodes are in one connected component
* To meet the above conditions, first, every time when we get two nodes from a new edge, 
* we will trace back from the two and see if they have same root. If yes, the new edge will create loop.
* After we verify there is no cycle, we will simple test if there are enough edges(number of edges is equal to the number of node minus one) to make all nodes connected.
*/
#include <vector>
#include <map>
using namespace std;
bool valid_tree(int n, vector<pair<int, int>>& edges) {
	map<int, int> prev_to;
	for (auto i = edges.cbegin(); i < edges.cend(); i++) {
		int pf = i->first;
		int ps = i->second;
		while (prev_to.contains(pf)) pf = prev_to[pf];
		while(prev_to.contains(ps)) ps = prev_to[ps];
		if (pf == ps) return false;
		prev_to[i->second] = i->first;
	}
	return (n - 1) == prev_to.size();
}