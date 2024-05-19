/*
There is a binary tree rooted at 0 consisting of n nodes. 
The nodes are labeled from 0 to n - 1. 
You are given a 0-indexed integer array parents representing the tree, where parents[i] is the parent of node i. 
Since node 0 is the root, parents[0] == -1.Each node has a score. To find the score of a node, consider if the node and the edges connected to it were removed. 
The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. 
The score of the node is the product of the sizes of all those subtrees.
Return the number of nodes that have the highest score.
*/

/*
* construct a binary tree array bta(using stack) where the ith' left child node is in 2i + 1 and right node is in 2i + 2, and the value is the size of the (sub)tree rooted from the node.  
* caculate the score of each node by the following fomular
* (bta[0] - bta[i]) * bta[2*i + 1] * bta[2*i + 2]
*/
struct Node {
	int size = 0;
	int f_child = -1;
	int s_child = -1;
};
int highest_score(int a[], int length) {
	Node *nodes = new Node[length];
	for (int i = 0; i < length; i++) {
		int j = i;
		int k = j;
		while (j != -1) {
			nodes[j].size++;
			k = j;
			j = a[j];
			if(j!=-1){
				if (nodes[j].f_child == -1) {
					nodes[j].f_child = k;
				}
				else
				{
					nodes[j].s_child = k;
				}
			}
		}		
	}
	int max_score = 0;
	for (int l = 0; l < length; l++) {
		int p_size = a[l] == -1 ? 1 : nodes[a[l]].size - nodes[l].size;
		int fl_size = nodes[l].f_child == -1 ? 1 : nodes[nodes[l].f_child].size;
		int sl_size = nodes[l].s_child == -1 ? 1: nodes[nodes[l].s_child].size;
		int score = p_size * fl_size * sl_size;
		max_score = score > max_score ? score : max_score;
	}
	delete []nodes;
	return max_score;
}